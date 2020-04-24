package main

import (
	"context"
	"fmt"
	"log"
	"math/rand"
	"net/http"
	"os"
	"os/signal"
	"strconv"
	"syscall"
	"time"
)

var waitingList = make(map[uint64]string)
var counter = NewCounter()

func randomColor() (r, g, b int) {
	r = rand.Intn(255)
	g = rand.Intn(255)
	b = rand.Intn(255)

	return r, g, b
}

func autoDestroy(id uint64) {
	time.Sleep(time.Millisecond * 500)
	delete(waitingList, id)
}

func root(w http.ResponseWriter, req *http.Request) {
	fmt.Printf("request from: %s -- forwarded for: %s\n", req.RemoteAddr, req.Header.Get("X-Forwarded-For"))
	if req.Header.Get("X-Forwarded-For") == "10.11.200.110" {
		w.WriteHeader(http.StatusOK)
		return
	}
	if err := req.ParseForm(); err != nil {
		w.WriteHeader(http.StatusInternalServerError)
		fmt.Fprintf(w, "Internal error while parsing")
	}

	fmt.Printf("%+v", req.URL.Query())
	id := req.URL.Query().Get("id")
	resp := req.URL.Query().Get("resp")

	if id != "" && resp != "" {
		fmt.Printf("id: %s -- resp: %s\n", id, resp)
		idInt, err := strconv.ParseUint(id, 10, 64)
		if err != nil {
			w.WriteHeader(http.StatusUnprocessableEntity)
			fmt.Fprintf(w, "wrong id?")
			return
		}
		if waitingList[idInt] == resp {
			fmt.Fprintf(w, "ok!")
		} else {
			w.WriteHeader(http.StatusNotFound)
			fmt.Fprintf(w, "too slow or wrong answer")
		}
		return
	}
	r, g, b := randomColor()

	newID := counter.Iter()
	waitingList[newID] = fmt.Sprintf("%02x%02x%02x", r, g, b)
	fmt.Printf("generated chall -- id: %d -- chall: r=%d,g=%d,b=%d\n", newID, r, g, b)
	fmt.Fprintf(w, "id=%d,r=%d,g=%d,b=%d - Send your response here: %s/?id=<id>&resp=<hex>", newID, r, g, b, req.Host)
	go autoDestroy(newID)
}

func returnQueue(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "%v", waitingList)
}

func main() {
	srv := &http.Server{
		Handler:      nil,
		Addr:         ":8080",
		ReadTimeout:  10 * time.Second,
		WriteTimeout: 10 * time.Second,
	}

	http.HandleFunc("/", root)
	http.HandleFunc("/queue", returnQueue)
	go func() {
		log.Println("Starting Server")
		if err := http.ListenAndServe("0.0.0.0:5000", nil); err != nil {
			log.Fatal(err)
		}
	}()

	waitForShutdown(srv)
}

func waitForShutdown(srv *http.Server) {
	interruptChan := make(chan os.Signal, 1)
	signal.Notify(interruptChan, os.Interrupt, syscall.SIGINT, syscall.SIGTERM)

	<-interruptChan
	ctx, cancel := context.WithTimeout(context.Background(), time.Second*10)
	defer cancel()
	srv.Shutdown(ctx)
	counter.Close()

	log.Println("Shutting down")
	os.Exit(0)

}

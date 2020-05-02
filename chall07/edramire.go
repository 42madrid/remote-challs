package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"strconv"
	"strings"
	"time"
)

func logrequest(start time.Time, req string, res string, status int) {
	duration := time.Since(start)
	fmt.Printf("%d ms - GET %s\n", duration.Nanoseconds()/1000000, req)
	if len(res) > 0 {
		fmt.Printf("\t %d: %s\n", status, res)
	}
}

func getrequest(request string) (string, int) {
	res, err := http.Get(request)
	if err != nil {
		log.Fatal(err)
	}
	stringBody, err := ioutil.ReadAll(res.Body)
	res.Body.Close()
	if err != nil {
		log.Fatal(err)
	}
	return string(stringBody), res.StatusCode
}

func main() {
	home := "https://chall07.42madrid.com/"
	start := time.Now()
	logrequest(start, home, "", 0)
	answer, status := getrequest(home)
	if status != 200 {
		log.Fatal("Wrong response from server")
	}
	logrequest(start, home, answer, status)
	values := strings.Split(answer[0:strings.Index(answer, " ")], ",")
	r, _ := strconv.Atoi(values[1][2:])
	g, _ := strconv.Atoi(values[2][2:])
	b, _ := strconv.Atoi(values[3][2:])
	rgb := (r & 0xFF << 16) | (g & 0xFF << 8) | (b & 0xFF)
	hex := fmt.Sprintf("%06x", rgb)
	resp := fmt.Sprintf("%s?%s&resp=%s", home, values[0], hex)
	logrequest(start, resp, "", 0)
	answer, status = getrequest(resp)
	logrequest(start, resp, answer, status)
	duration := time.Since(start)
	fmt.Printf("%dms - DONE\n", duration.Nanoseconds()/1000000)
}

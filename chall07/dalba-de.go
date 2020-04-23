package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"time"
)

func main() {
	start := time.Now()
	fmt.Printf("%dms - GET https://chall07.42madrid.com/", time.Since(start).Milliseconds())
	resp, err := http.Get("https://chall07.42madrid.com/")
	if err != nil {
		log.Fatalln(err)
	}
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		log.Fatalln(err)
	}
	defer resp.Body.Close()
	fmt.Printf("\n%dms - GET https://chall07.42madrid.com/", time.Since(start).Milliseconds())
	var id, r, g, b int
	fmt.Sscanf(string(body), "id=%d,r=%d,g=%d,b=%d", &id, &r, &g, &b)
	fmt.Printf("\n\tanswer:id=%d,r=%d,g=%d,b=%d - Send your response here: chall07.42madrid.com/?id=<id>&resp=<hex>", id, r, g, b)
	hex := fmt.Sprintf("%02x%02x%02x", r, g, b)
	fmt.Printf("\n%dms - GET https://chall07.42madrid.com/?id=%d&resp=%s", time.Since(start).Milliseconds(), id, hex)
	resp, err = http.Get(fmt.Sprintf("https://chall07.42madrid.com/?id=%d&resp=%s", id, hex))
	if err != nil {
		log.Fatalln(err)
	}
	body, err = ioutil.ReadAll(resp.Body)
	if err != nil {
		log.Fatalln(err)
	}
	defer resp.Body.Close()
	fmt.Printf("\n%dms - GET https://chall07.42madrid.com/?id=%d&resp=%s", time.Since(start).Milliseconds(), id, hex)
	fmt.Printf("\n\tanswer: %s", string(body))
	fmt.Printf("\n%dms - DONE", time.Since(start).Milliseconds())
}

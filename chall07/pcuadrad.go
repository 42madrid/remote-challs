package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"strings"
	"strconv"
	"log"
	"os"
	"time"
)

func RGBToHex(r int, g int, b int) (string) {
	return fmt.Sprintf("%x%x%x",r ,g ,b)
}

func printRequestTime(url string, answer string, start time.Time) {
	now := time.Now()
	elapsed := now.Sub(start)
	if answer == "" {
		fmt.Println(elapsed,"- GET", url)
	} else {
		fmt.Println(elapsed,"- GET", url, "\n\tanswer:", answer)
	}
}

func DoRequest(url string, l *log.Logger, start time.Time) (string) {
	printRequestTime(url, "", start)
	response, err := http.Get(url)
	if err != nil {
		l.Fatalln(err)
	}
	defer response.Body.Close()
	body, err := ioutil.ReadAll(response.Body)
	if err != nil {
		l.Fatalln(err)
	}
	printRequestTime(url, string(body), start)
	return string(body)
}

func parseBody(body string, l *log.Logger) (string, int, int, int){
	var arr [4]int
	var err error
	parse := strings.SplitN(body, " ", 2)
	parse = strings.Split(parse[0], ",")
	for i := 0; i < len(parse); i++ {
		getNumbers := strings.Split(parse[i], "=")
		arr[i], err = strconv.Atoi(getNumbers[1])
		if err != nil {
			l.Fatalln(err)
		}
	}
	return strconv.Itoa(arr[0]), arr[1], arr[2], arr[3]
}

func main() {
	l := log.New(os.Stderr, "An error ocurred:\n", 0)
	url := "https://chall07.42madrid.com/"
	start := time.Now()
	body := DoRequest(url ,l, start)
	id, r, g, b := parseBody(body, l)
	hex := RGBToHex(r, g, b)
	url = url + "?id=" + id + "&resp=" + hex
	DoRequest(url ,l, start)
}
package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"strconv"
	"strings"
)

func throw_error(err error) {
	if err != nil {
		panic(err)
	}
}

func main() {
	resp, err := http.Get("https://chall07.42madrid.com/")
	throw_error(err)
	defer resp.Body.Close()
	body, err := ioutil.ReadAll(resp.Body)
	url := strings.Split(string(body), " ")
	result := strings.Split(string(url[0]), ",")
	hexa_color := ""
	for i := 1; i < 4; i++ {
		color, err := strconv.Atoi(result[i][2:])
		throw_error(err)
		hexa_color = hexa_color + fmt.Sprintf("%x", color)
	}
	final := "https://chall07.42madrid.com/?" + result[0] + "&resp=" + hexa_color
	send, err := http.Get(final)
	throw_error(err)
	defer send.Body.Close()
	body_resp, err := ioutil.ReadAll(send.Body)
	fmt.Println(string(body_resp))
}

package main

import (
	"fmt"
	"net/http"
	"io/ioutil"
	"strings"
	"strconv"
	"log"
)

func main() {
	response, err := http.Get("https://chall07.42madrid.com/")
	contents, err := ioutil.ReadAll(response.Body)
	body := strings.Split(string(contents), " ")
	string := strings.Split(string(body[0]), ",")
	red, err := strconv.Atoi(string[1][2:])
	green, err := strconv.Atoi(string[2][2:])
	blue, err := strconv.Atoi(string[3][2:])
	if err != nil {
		log.Fatal(err)
	}
	id := string[0]
	hex := fmt.Sprintf("%02x%02x%02x", red, green, blue);  
	context := fmt.Sprintf("https://chall07.42madrid.com/?%s&resp=%s", id, hex)
	response, err = http.Get(context)
	res , err := ioutil.ReadAll(response.Body)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("%s", res)
}
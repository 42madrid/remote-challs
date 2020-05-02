package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"strconv"
	"strings"
)

func rgbToHexadecimal(response string) (int, int, int, int) {
	str := strings.Split(response, " ")
	data := str[0]
	values := strings.Split(data, ",")
	id, error := strconv.Atoi(strings.Split(values[0], "=")[1])
	red, error := strconv.Atoi(strings.Split(values[1], "=")[1])
	green, error := strconv.Atoi(strings.Split(values[2], "=")[1])
	blue, error := strconv.Atoi(strings.Split(values[3], "=")[1])

	if error != nil {
		log.Fatalln(error)
	}

	return id, red, green, blue
}

func makeRequest(url string) string {
	response, error := http.Get(url)
	body, error := ioutil.ReadAll(response.Body)

	if error != nil {
		log.Fatalln(error)
	}

	defer response.Body.Close()
	return string(body)
}

func main() {
	urlBase := "https://chall07.42madrid.com/"
	body := makeRequest(urlBase)
	id, red, green, blue := rgbToHexadecimal(body)
	urlResponse := fmt.Sprintf(urlBase+"?id=%d&resp=%02x%02x%02x", id, red, green, blue)
	body = makeRequest(urlResponse)
	fmt.Println(body)
}

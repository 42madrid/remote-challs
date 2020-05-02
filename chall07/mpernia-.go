package main

import (
	"io/ioutil"
	"net/http"
	"strconv"
	"strings"
	"time"
)

func time_elapse(start time.Time) int {
	ms := time.Since(start)
	new_ms := int(ms.Seconds() * 1000)
	return new_ms
}

func get_hex(red int, green int, blue int) string {
	rgb_int := (int64(red) * 256 * 256) + (int64(green) * 256) + int64(blue)
	return strconv.FormatInt(rgb_int, 16)
}

func get_link(body string) string {
	j := strings.IndexByte(body, ',')
	id, err := strconv.Atoi(body[3:j])
	if err != nil {
		print(err)
	}
	k := strings.IndexByte(body, 'g')
	red, err := strconv.Atoi(body[j+3 : k-1])
	if err != nil {
		print(err)
	}
	j = strings.IndexByte(body, 'b')
	green, err := strconv.Atoi(body[k+2 : j-1])
	if err != nil {
		print(err)
	}
	k = strings.IndexByte(body, ' ')
	blue, err := strconv.Atoi(body[j+2 : k])
	if err != nil {
		print(err)
	}
	hex := get_hex(red, green, blue)
	return "https://chall07.42madrid.com/?id=" + strconv.Itoa(id) + "&resp=" + hex
}

func main() {
	start := time.Now()
	print("0 ms - GET https://chall07.42madrid.com/ \n")
	resp, err := http.Get("https://chall07.42madrid.com/")
	if err != nil {
		print(err)
	}
	defer resp.Body.Close()
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		print(err)
	}
	print(time_elapse(start), " ms - GET https://chall07.42madrid.com/ \n")
	print("\t answer:", string(body), "\n")
	link := get_link(string(body))
	print(time_elapse(start), " ms - GET ", link, "\n")
	resp, err = http.Get(link)
	if err != nil {
		print(err)
	}
	defer resp.Body.Close()
	body, err = ioutil.ReadAll(resp.Body)
	if err != nil {
		print(err)
	}
	print(time_elapse(start), " ms - GET ", link, " \n")
	print("\t answer:", string(body), "\n")
	print(time_elapse(start), " ms - DONE\n")
}

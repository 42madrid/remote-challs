package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"regexp"
	"strconv"
)


func requestServer() {
	/* First GET request to get the required formated string */
	resp, err := http.Get("https://chall07.42madrid.com/")
	if err != nil {
		panic(err)
	}
	fmt.Println("Response status:", resp.Status)
	defer resp.Body.Close()

	/* Read and print response */
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		panic(err)
	}
	fmt.Printf("%s\n", string(body))

	/* Use regex to find the numbers in the string and check to be more than 3 numbers */
	/* Expecting the first 4 numbers to be in correct order and valid */
	re := regexp.MustCompile(`\d+`)
	set := re.FindAllString(string(body), -1)
	if len(set) < 4 {
		panic(err)
	}

	/* Convert second, third and forth digits to int and create an "answer" string*/
	/* Expecting all colors to be between 0-255 */
	r, _ := strconv.Atoi(set[1])
	g, _ := strconv.Atoi(set[2])
	b, _ := strconv.Atoi(set[3])
	answer := fmt.Sprintf("https://chall07.42madrid.com/?id=%s&resp=%.2x%.2x%.2x",set[0] ,r ,g ,b)

	/* Second GET request using the answer and print the response status*/
	resp, err = http.Get(answer)
	if err != nil {
		panic(err)
	}
	fmt.Println("Response status:", resp.Status)
	defer resp.Body.Close()

	/* Read and print the response */
	body, err = ioutil.ReadAll(resp.Body)
	if err != nil {
		panic(err)
	}
	fmt.Printf("answer: %s\n", string(body))
}

func main() {
	requestServer()
}

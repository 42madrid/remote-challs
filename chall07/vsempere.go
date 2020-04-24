package main

import (
	"fmt"
	"strings"
	"strconv"
	"regexp"
	"log"
	"io/ioutil"
	"net/http"
)

func toHex(dec []byte) string {
	ri, err := strconv.Atoi(string(dec))
	if err != nil {
		log.Fatal(err)
	}
	str := strconv.FormatInt(int64(ri), 16)
	if len(str) < 2 {
		return "0"+ str
	} else {
			return str
	}
}

func launchGet(url string) (string, string) {
	res, err := http.Get(url)
	if err != nil {
		log.Fatal(err)
	}
	robots, err := ioutil.ReadAll(res.Body)
	res.Body.Close()
	if err != nil {
		log.Fatal(err)
	}

	return res.Status, string(robots);
}

func buildResponseUrl(response string) string {
	re := regexp.MustCompile(`id=(\d+),r=(\d+),g=(\d+),b=(\d+).*here:\s+(.*)`)
	m := re.FindSubmatch([]byte(response));

	id := m[1]
	r := toHex(m[2])
	g := toHex(m[3])
	b := toHex(m[4])
	s := []string{r, g, b}

	return "https://" + strings.Replace(strings.Replace(string(m[5]), "<id>", string(id), 1), "<hex>", strings.Join(s, ""), 1)
}
func main() {
	status, response := launchGet("https://chall07.42madrid.com/")
	fmt.Printf("%s -> %s\n", status, response);
	url := buildResponseUrl(response);
	status, response = launchGet(url)
	fmt.Printf("%s -> %s\n", status, response)

}
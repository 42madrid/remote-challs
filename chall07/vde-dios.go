package main

import (
    "net/http"
    "log"
    "io/ioutil"
    "fmt"
    "regexp"
    "strconv"
    "strings"
)

func outputErr(err error){
    if err != nil {
        log.Fatalln(err)
    }
}

func toHex(rgb [][]string) string {
    output := ""
    for i := 1; i < 4; i++ {
        hex, err := strconv.Atoi(strings.Join(rgb[i],""))
        outputErr(err)
        output += fmt.Sprintf("%x", hex)
    }
    return output
}

func MakeRequest(uri string) string{
    resp, err := http.Get(uri)
    outputErr(err)
    body, err := ioutil.ReadAll(resp.Body)
    outputErr(err)
    log.Println(string(body))
    return string(body)
}

func main() {
    response := MakeRequest("https://chall07.42madrid.com/")
    re := regexp.MustCompile(`\d+`)
    rgb := re.FindAllStringSubmatch(response, -1)
    MakeRequest("https://chall07.42madrid.com/?id=" + strings.Join(rgb[0],"") + "&resp=" + toHex(rgb))
}

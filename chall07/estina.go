/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estina.go                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 13:38:49 by marvin            #+#    #+#             */
/*   Updated: 2020/04/23 13:38:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

func send_get_from_server(s string) []byte {
	resp, err := http.Get(s)
	throw_error(err)
	defer resp.Body.Close()
	body, err := ioutil.ReadAll(resp.Body)
	return (body)
}

func main() {
	url := strings.Split(string(send_get_from_server("https://chall07.42madrid.com/")), " ")
	result := strings.Split(string(url[0]), ",")
	hexa_color := ""
	for i := 1; i < 4; i++ {
		color, err := strconv.Atoi(result[i][2:])
		throw_error(err)
		hexa_color = hexa_color + fmt.Sprintf("%x", color)
	}
	body := send_get_from_server("https://chall07.42madrid.com/?" + result[0] + "&resp=" + hexa_color)
	fmt.Println(string(body))
}

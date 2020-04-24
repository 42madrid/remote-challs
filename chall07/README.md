<h1 align="center"><code>Planeta Vegeta (Chall07) / HTTP RGB to Hexadecimal</code></h1>

<div align="center">
  <sub>Created by <a href="https://github.com/jgengo">Jordane Gengo (Titus)</a>, <a href="">Oleksii Martynovskyi (Disky)</a>, <a href="">Paula Lantran (Ablette)</a></sub>
</div>
<div align="center">
  <sub>From <a href="https://hive.fi">Hive Helsinki</a> for all the 42 Network</sub>
</div>

---

### Instructions

<sub>**Turn-in directory:** `chall07/`</sub><br />
<sub>**Files to turn in:** `<xlogin>.go`</sub><br />
<sub>**Language:** `Go`</sub>

<sub>**Deadline:** 24.04.2020 - 11:42am</sub>
<br /><br />
### Subject

<p align="center">
  <img width="350" height="350" src="https://boxopix.fr/hive/golang.png">
</p>

On this chall, you will need to learn how to use `net/http` in Golang to make a GET request to https://chall07.42madrid.com/ 

You will receive as a response an id, a RGB value sets and you will have to answer back in less than 400 ms to the server with another HTTP GET the Hexa value of this RGB sets on https://chall07.42madrid.com/?id=ID&resp=HEXA 

The hexa doesn't have a `#` this time!!

The output format doesn't matter, what matter is that at the end we're able to see you get a return status code 200 client-side or a "ok!" body response.

<br /><br />
### Examples

not good
```
[pistache@home ~ ]$ go run chall03-client.go
0ms - GET https://chall07.42madrid.com/
196ms - GET https://chall07.42madrid.com/
	answer:id=13,r=72,g=211,b=45 - Send your response here: chall07.42madrid.com/?id=<id>&resp=<hex>
1199ms - GET https://chall07.42madrid.com/?id=13&resp=48d32d
1214ms - GET https://chall07.42madrid.com/?id=13&resp=48d32d
	answer: ko :(
1214ms - DONE
```
good:
```
[pistache@home ~ ]$ go run chall03-client.go
0ms - GET https://chall07.42madrid.com/
209ms - GET https://chall07.42madrid.com/
	answer:id=14,r=156,g=103,b=220 - Send your response here: chall07.42madrid.com/?id=<id>&resp=<hex>
209ms - GET https://chall07.42madrid.com/?id=14&resp=9c67dc
221ms - GET https://chall07.42madrid.com/?id=14&resp=9c67dc
	answer: ok!
221ms - DONE
```

### Reward

 - The first one to submit a working solution will earn `840` points for their coalition.
 - Everyone else submitting a working solution *(not yet submitted)* will earn `420` points for their coalition.
 - Every participant that tried to solve the challenge and pushed a solution will earn `210` points for their coalition.
 
<br /><br />
Good luck!
<br />
<sub>About the title: <a href="https://dragonball.fandom.com/es/wiki/Planeta_Vegeta">Planeta Vegeta</a></sub>

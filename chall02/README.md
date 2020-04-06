<h1 align="center"><code>Constelación Serpens (Chall02) / String to Morse</code></h1>

<div align="center">
  <sub>Created by <a href="https://github.com/jgengo">Jordane Gengo (Titus)</a>, <a href="">Oleksii Martynovskyi (Disky)</a>, <a href="">Paula Lantran (Ablette)</a></sub>
</div>
<div align="center">
  <sub>From <a href="https://hive.fi">Hive Helsinki</a> for all the 42 Network</sub>
</div>

---

### Instructions
<sub>**Turn-in directory:** `chall02/`</sub><br />
<sub>**Files to turn in:** `<xlogin>.py`</sub><br />
<sub>**Language:** `Python 3.x`</sub>

<sub>**Deadline:** 07.04.2020 - 10:42am</sub>
<br /><br />

### Subject

<p align="center">
  <img width="350" height="350" src="https://miro.medium.com/max/2326/0*ILDRyFYvSxy7Wmse.jpg">
</p>


For the purpose of this challenge, Morse code represents every letter as a sequence of 1-4 characters, each of which is either `.` (dot) or `-` (dash). The code for the letter `a` is `.-`, for `b` is `-...`, etc. 

The codes for each letter from a through z are:
```
.-
-... 
-.-. 
-.. 
. 
..-. 
--. 
.... 
.. 
.--- 
-.- 
.-.. 
-- 
-. 
--- 
.--. 
--.- 
.-. 
... 
- 
..- 
...- 
.-- 
-..- 
-.-- 
--..
```

You have to submit a **python3 executable script** to encode a string to morse.
<br /><br />
### Examples

```
[titus@pentest-lab ~ ]$ ./xlogin.py
usage: ./xlogin.py <a-zA-Z string>
```
```
[titus@pentest-lab ~ ]$ ./xlogin.py ""
usage: ./xlogin.py <a-zA-Z string>
```
```
[titus@pentest-lab ~ ]$ ./xlogin.py "firstArg" "secondArg"
usage: ./xlogin.py <a-zA-Z string>
```
```
[titus@pentest-lab ~ ]$ ./xlogin.py "sos daily##@"
usage: ./xlogin.py <a-zA-Z string>
```
```
[titus@pentest-lab ~ ]$ ./xlogin.py "soS"
...---...
```
```
[titus@pentest-lab ~ ]$ ./xlogin.py "daily"
-...-...-..-.--
```
```
[titus@pentest-lab ~ ]$ ./xlogin.py "proGRammer"
.--..-.-----..-..-----..-.
```
```
[titus@pentest-lab ~ ]$ ./xlogin.py "bits"
-.....-...
```
```
[titus@pentest-lab ~ ]$ ./xlogin.py "sos daily" | cat -e
...---... -...-...-..-.--$
```
<br /><br />
### Reward

 - The first one to submit a working solution will earn `420` points for their coalition.
 - Everyone else submitting a working solution *(not yet submitted)* will earn `126` points for their coalition.
 - Every participant that tried to solve the challenge and pushed a solution will earn `84` points for their coalition.
 
<br /><br />
Good luck!
<br />
<sub>About the title: <a href="https://www.constelaciones.info/serpens/">Constelación Serpens</a></sub>

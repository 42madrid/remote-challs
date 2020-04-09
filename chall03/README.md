<h1 align="center"><code>Galaxia de Bode (Chall03) / Snail Sort</code></h1>

<div align="center">
  <sub>Created by <a href="https://github.com/abguimba">Abraham Guimbao (lincoln)</a>, <a href="https://github.com/vesta-nna">Anna Dominguez (analogia)</a>, <a href="https://github.com/clafoutis42">Charles Labourier (pistache)</a></sub>
</div>
<div align="center">
  <sub>From <a href="https://42madrid.com">42 Madrid</a> for all the 42 Network</sub>
</div>

---

### Instructions
<sub>**Turn-in directory:** `chall03/`</sub><br />
<sub>**Files to turn in:** `<xlogin>.py`</sub><br />
<sub>**Language:** `Python 3.x`</sub>

<sub>**Deadline:** 10.04.2020 - 11:42am</sub>
<br /><br />

### Subject

<p align="center">
  <img width="350" height="350" src="https://i.imgur.com/4WqMJBl.jpg">
</p>

Given an array of `n` rows as arguments, your script must print all of the elements in each row of the array arranged from outermost elements to the middle element, traveling clockwise.

```python
array = [[1,2,3],
             [4,5,6],
             [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]
```
For better understanding, please follow the numbers of the next array consecutively:

```python
array = [[1,2,3],
            [8,9,4],
            [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]
```
This image will illustrate things more clearly:

<p align="center">
  <img  src="https://www.haan.lu/files/2513/8347/2456/snail.png">
</p>

> NOTE: A valid square can range from a size of 1\*1 to a size of 20\*20.

You have to submit a **python3 executable script** to solve this problem.

### Examples
```zsh
[42student@somewhere ~ ]$ ./xlogin.py
usage: ./xlogin.py <1-9 squared_rows...>
```
```zsh
[42student@somewhere ~ ]$ ./xlogin.py "123" "456" "789"
1, 2, 3, 6, 9, 8, 7, 4, 5
```
```zsh
[42student@somewhere ~ ]$ ./xlogin.py "123" "456"
usage: ./xlogin.py <1-9 squared_rows...>
```
```zsh
[42student@somewhere ~]$ ./xlogin.py "4325" "1297" "1242" "7654"
4, 3, 2, 5, 7, 2, 4, 5, 6, 7, 1, 1, 2, 9, 4, 2
```
```zsh
[42student@somewhere ~]$ ./xlogin.py "41325" "12597" "61242" "76754" "35255"
4, 1, 3, 2, 5, 7, 2, 4, 5, 5, 2, 5, 3, 7, 6, 1, 2, 5, 9, 4, 5, 7, 6, 1, 2
```
```zsh
[42student@somewhere ~ ]$ ./xlogin.py "12A" "4@6" "#89"
usage: ./xlogin.py <1-9 squared_rows...>
```
```zsh
[42student@somewhere ~ ]$ ./xlogin.py "123" "416" "789" | cat -e
1, 2, 3, 6, 9, 8, 7, 4, 1$
```
```zsh
[42student@somewhere ~ ]$ ./xlogin.py "123" "4" "789"
usage: ./xlogin.py <1-9 squared_rows...>
```
<br /><br />
### Reward

 - The first one to submit a working solution will earn `420` points for their coalition.
 - Everyone else submitting a working solution *(not yet submitted)* will earn `126` points for their coalition.
 - Every participant that tried to solve the challenge and pushed a solution will earn `84` points for their coalition.
 
<br /><br />
Good luck!
<br />
<sub>About the title: <a href="https://www.astronomia-iniciacion.com/la-gran-galaxia-espiral-m81-y-el-bucle-de-arp.html">Galaxia de Bode</a></sub>

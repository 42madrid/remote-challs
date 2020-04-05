<h1 align="center"><code>Freddiemercury 17473 (Chall01) / Necklace</code></h1>

<div align="center">
  <sub>Created by <a href="https://github.com/jgengo">Jordane Gengo (Titus)</a>, <a href="">Oleksii Martynovskyi (Disky)</a>, <a href="">Paula Lantran (Ablette)</a></sub>
</div>
<div align="center">
  <sub>From <a href="https://hive.fi">Hive Helsinki</a> for all the 42 Network</sub>
</div>

---

### Instructions

<sub>**Turn-in directory:** `chall01/`</sub><br />
<sub>**Files to turn in:** `<xlogin>.c`</sub><br />
<sub>**Language:** `C`</sub><br />
<sub>**Prototype:** `int   hv_necklace(char *s1, char *s2);`</sub>

<sub>**Deadline:** 03.04.2020 - 11:42am</sub>
<br /><br />
### Subject

<p align="center">
  <img width="350" height="350" src="https://www.craftkitsandsupplies.com/images/Beads/Alpha_Beads/Wood_Alphabet_Beads_26217.jpg">
</p>

Imagine a necklace with lettered beads that can slide along the string. See the above example, you could take the N off NICOLE and slide it around to the other end to make `ICOLEN`. Do it again to get `COLENI`, and so on. 

For the purpose of today's challenge, we'll say that the strings "nicole", "icolen", and "coleni" describe the same necklace.
<br /><br />
### Examples:

```
hv_necklace("nicole", "icolen") == 1
hv_necklace("nicole", "lenico") == 1
hv_necklace("nicole", "coneli") == 0
hv_necklace("aabaaaaabaab", "aabaabaabaaa") == 1
hv_necklace("abc", "cba") == 0
hv_necklace("xxyyy", "xxxyy") == 0
hv_necklace("xyxxz", "xxyxz") == 0
hv_necklace("x", "x") == 1
hv_necklace("x", "xx") == 0
hv_necklace("x", "") == 0
hv_necklace("", "") == 1
```
<br /><br />
### Reward

 - The first one to submit a working solution will earn `420` points for their coalition.
 - Everyone else submitting a working solution *(not yet submitted)* will earn `126` points for their coalition.
 - Every participant that tried to solve the challenge and pushed a solution will earn `84` points for their coalition.
 
<br /><br />
Good luck!
<br />
<sub>About the title: <a href="https://www.bbc.com/mundo/noticias-37280377">Asteroide Freddiemercury 17473</a></sub>

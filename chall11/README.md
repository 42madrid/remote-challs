<h1 align="center"><code>Saffar (Chall11) / Goto Parser</code></h1>

<div align="center">
  <sub>Created by <a href="https://github.com/abguimba">Abraham Guimbao (lincoln)</a>, <a href="https://github.com/vesta-nna">Anna Dominguez (analogia)</a>, <a href="https://github.com/clafoutis42">Charles Labourier (pistache)</a></sub>
</div>
<div align="center">
  <sub>From <a href="https://42madrid.com">42 Madrid</a> for all the 42 Network</sub>
</div>

---

### Instructions
<sub>**Turn-in directory:** `chall11/`</sub><br />
<sub>**Files to turn in:** `<xlogin>.c`</sub><br />
<sub>**Language:** `C`</sub><br />
<sub>**Prototype:** `char *ft_goto_parser(const char *code);`</sub><br />

<sub>**Deadline:** 22.05.2020 - 11:42am</sub>
<br /><br />

### Subject

<p align="center">
  <img src="https://i.imgur.com/o91m5mQ.png">
</p>
<br></br>
You are given a source file in the format (BNF):

```BNF
<line> ::=
  (<goto-statement> | <label> <whitespace(s)> <text>) <end-of-line>

<goto-statement> ::=
  goto <whitespace(s)> <label>

<label> ::=
  <positive integer>

<text> ::=
  <printable characters separated by whitespace(s)>

<end-of-line> ::=
  \n
```

A visual example would look like this (please, notice how it's reminiscent of the early days of BASIC):

```C
const char *code = (
  "5 HERE\n"
  "10 IS\n"
  "goto 40\n"
  "20 JUST rAnDoM TEXT\n"
  "30 AND\n"
  "40 MORE RANDOM text\n"
);
```

or like this

```C
const char *code = "5 HERE\n10 IS\ngoto 40\n20 JUST rAnDoM TEXT\n30 AND\n40 MORE RANDOM text\n";
```

When given to your parser function, you should return the following: `"HERE IS MORE RANDOM text"`.

So the objective is to chain the text in the statements (with a single space) (while ignoring the labels) not omitted by jumps and return the resulting string.

> NOTE: Input is always going to be valid, lines will always start by the line number (except `goto` lines), followed by a variable number of arguments separated by a variable number of spaces.
>
> NOTE2: In the string you return, your words will be separated by only one space.
>
> NOTE3: Be careful with infinite loops. If you detect one. Just return `"Infinite loop !"` and exit.
>
> NOTE4: Line numbering doesn't matter, you will read the lines from top to bottom, the number of the line is only important for the `goto` statements.

<br></br>
### Examples
Given the following `char *code`:
```C
const char *code = (
  "1 I am\n"
  "goto 5\n"
  "2 travelling\n"
  "3 down\n"
  "4 the river\n"
  "5 back\n"
  "10 home\n"
);
```
You will return: `"I am back home"`.

<br></br>
Given the following `char *code`:
```C
const char *code = (
  "1 I         \n"
  "goto      5       \n"
  "2 travelling\n"
  "3   down  \n"
  "4 the river\n"
  "5           love        being     \n"
  "10 in      42.\n"
);
```
You will return: `"I love being in 42."`.

<br></br>
Given the following `char *code`:
```C
const char *code = (
  "1 I am\n"
  "2 travelling\n"
  "3 down\n"
  "goto 2\n"
  "4 the river\n"
  "5 back\n"
  "10 home\n"
);
```
You will return: `"Infinite loop !"`.

<br></br>
Given the following `char *code`:
```C
const char *code = (
  "1 I am\n"
  "goto 4\n"
  "2 travelling\n"
  "3 down\n"
  "goto 2\n"
  "4 the river\n"
  "5 that just\n"
  "10 keeps flowing\n"
);
```
You will return: `"I am the river that just keeps flowing"`.

<br></br>
Given the following `char *code`:
```C
const char *code = (
  "1 I am\n"
  "goto 4\n"
  "2 travelling\n"
  "3 down\n"
  "goto 2\n"
  "4 the river\n"
  "5 that just\n"
  "10 keeps flowing\n"
);
```
You will return: `"I am the river that just keeps flowing"`.

<br></br>
Given the following `char *code`:
```C
const char *code = (
  "1024 I         \n"
  "goto      64       \n"
  "512 travelling\n"
  "256   down  \n"
  "128 the river\n"
  "64           love        being     \n"
  "32 in      42.\n"
);
```
You will return: `"I love being in 42."`.

<br></br>
### Reward

 - The first one to submit a working solution will earn `420` points for their coalition.
 - Everyone else submitting a working solution *(not yet submitted)* will earn `126` points for their coalition.
 - Every participant that tried to solve the challenge and pushed a solution will earn `84` points for their coalition.

<br></br>
Good luck!
<br />
<sub>About the title: <a href="https://danielmarin.naukas.com/2010/10/23/el-misterio-de-upsilon-andromedae-b/">Saffar</a></sub>
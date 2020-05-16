<h1 align="center"><code>Kepler-223 (Chall10) / Connect Four</code></h1>

<div align="center">
  <sub>Created by <a href="https://github.com/abguimba">Abraham Guimbao (lincoln)</a>, <a href="https://github.com/vesta-nna">Anna Dominguez (analogia)</a>, <a href="https://github.com/clafoutis42">Charles Labourier (pistache)</a></sub>
</div>
<div align="center">
  <sub>From <a href="https://42madrid.com">42 Madrid</a> for all the 42 Network</sub>
</div>

---

### Instructions
<sub>**Turn-in directory:** `chall10/`</sub><br />
<sub>**Files to turn in:** `<xlogin>.py`</sub><br />
<sub>**Language:** `Python3.x`</sub><br />

<sub>**Deadline:** 18.05.2020 - 11:42am</sub>
<br /><br />

### Subject

<p align="center">
  <img src="https://i.imgur.com/Cko2GIn.jpg">
</p>

Take a look at [wiki description](https://en.wikipedia.org/wiki/Connect_Four) of the `Connect Four` game.

Your program will receive, as input, a list of strings showing the order of the pieces which dropped in columns in the following form:

```zsh
A_Red
B_Yellow
A_Red
B_Yellow
A_Red
B_Yellow
G_Red
B_Yellow
```

Your program needs to consume this input until EOF is detected.

There may be up to 42 moves and the moves are in order.

The first player who connects four items of the same color is the winner. Horizontally, vertically, or diagonally.

You should detect, and print, which "team" has won or `"Draw."` accordingly (check [examples](#examples)).

If the input is invalid or it doesn't make sense, print `"Invalid input."` and exit.

> NOTE: There can only be two "teams", else, the input is invalid.
>
> NOTE2: A valid grid is always 6 * 7, those being named from `A` to `G`.
### Examples

```zsh
[42student@somewhere ~]$ ./<login>.py
A_Red
B_Yellow
A_Red
B_Yellow
A_Red
B_Yellow
G_Red
B_Yellow
Yellow.

[42student@somewhere ~]$ ./<login>.py
A_Apple
B_Android
A_Apple
B_Android
A_Apple
B_Android
G_Apple
B_Android
Android.

[42student@somewhere ~]$ ./<login>.py
A_apple
B_android
A_apple
B_android
A_apple
B_android
G_apple
B_android
Invalid input.

[42student@somewhere ~]$ ./<login>.py
A_Red
B_Yellow
A_Red
B_Yellow
A_Red
B_Yellow
G_Red
F_Yellow
Draw.

[42student@somewhere ~]$ ./<login>.py
Draw.

[42student@somewhere ~]$ ./<login>.py
H_Red
B_Yellow
A_Red
B_Yellow
A_Red
B_Yellow
G_Red
B_Yellow
Invalid input.

[42student@somewhere ~]$ ./<login>.py
A_red
B_Yellow
A_Red
B_Yellow
A_Red
B_Yellow
G_Red
B_Yellow
Invalid input.

[42student@somewhere ~]$ ./<login>.py
A_Blue
B_Yellow
A_Red
B_Yellow
A_Red
B_Yellow
G_Red
B_Yellow
Invalid input.

[42student@somewhere ~]$ ./<login>.py
9_Red
B_Yellow
A_Red
B_Yellow
A_Red
B_Yellow
G_Red
B_Yellow
Invalid input.

[42student@somewhere ~]$ ./<login>.py
a_Red
B_Yellow
A_Red
B_Yellow
A_Red
B_Yellow
G_Red
B_Yellow
Invalid input.

[42student@somewhere ~]$ ./<login>.py
A_Blue
B_Yellow
A_Blue
B_Yellow
A_Blue
B_Yellow
G_Blue
B_Yellow
Yellow.
```

### Reward

 - The first one to submit a working solution will earn `840` points for their coalition.
 - Everyone else submitting a working solution *(not yet submitted)* will earn `252` points for their coalition.
 - Every participant that tried to solve the challenge and pushed a solution will earn `126` points for their coalition.

Good luck!
<br />
<sub>About the title: <a href="https://www.astrofisicayfisica.com/2016/05/sistema-kepler-223-indicios-de.html">Kepler-223</a></sub>
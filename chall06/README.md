<h1 align="center"><code>Asgard (Chall06) / CheckMate Problem</code></h1>

<div align="center">
  <sub>Created by <a href="https://github.com/abguimba">Abraham Guimbao (lincoln)</a>, <a href="https://github.com/vesta-nna">Anna Dominguez (analogia)</a>, <a href="https://github.com/clafoutis42">Charles Labourier (pistache)</a></sub>
</div>
<div align="center">
  <sub>From <a href="https://42madrid.com">42 Madrid</a> for all the 42 Network</sub>
</div>

---

### Instructions
<sub>**Turn-in directory:** `chall06/`</sub><br />
<sub>**Files to turn in:** `<xlogin>.c`</sub><br />
<sub>**Language:** `C`</sub><br />
<sub>**Prototype:** `int ft_check_mate(char *board);`</sub>

<sub>**Deadline:** 21.04.2020 - 11:42am</sub>
<br /><br />

### Subject

<p align="center">
  <img src="https://i.imgur.com/zKzCCoN.jpg">
</p>

Write a function that takes a chessboard as argument and checks if your 
King is in a check position.

Chess is played on a chessboard, a squared board of 8-squares length with 
different pieces on it.

For this exercice, you will only play with Pawns (`P`), Bishops (`B`), Rooks (`R`), Queen (`Q`), and obviously a King (`K`). `.` is considered an empty space.

Each piece has a specific method of movement, all patterns of capture are detailed below the examples. 

The board has a variable size but will remain a square. There's only one King
and all other pieces are against it.

Pieces CAN'T go through other pieces. 

The King is considered as in a check position when another enemy piece can
capture it.

When that's the case, you will return `0`, otherwise you will return `1`.

If there is no arguments or if the input is invalid in the usual ways (There is no King (`K`) piece, board is not an even square, different pieces than `[P, B, R, Q, K, or '.']`),the function will also return `1`.

> NOTE: Maximum size of the board will be 9*9.
>
> NOTE 2: Each row in the `board` argument sent to your function is separated by a `\n`.
>
>NOTE 3: There can be only one King (`K`) piece, but there can be any number of the other valid pieces on the board.

### Examples
```
ft_check_mate("..\n.K") == 1
ft_check_mate("R...\n.K..\n..P.\n....") == 0
ft_check_mate("R...\n...K\n....\n...R") == 0
ft_check_mate("R..F\n...K\n..X.\n...R") == 1
ft_check_mate("R...\n...K\n..\n...R") == 1
```

### Capture Examples
```
Peon / Pawn (P):

    . . . . . . .
    . . . . . . .
    . . X . X . .
    . . . P . . .
    . . . . . . .
    . . . . . . .
    . . . . . . .
```
```
Alfil / Bishop (B):

    X . . . . . X
    . X . . . X .
    . . X . X . .
    . . . B . . .
    . . X . X . .
    . X . . . X .
    X . . . . . X
```
```
Torre / Rook (R):

    . . . X . . .
    . . . X . . .
    . . . X . . .
    X X X R X X X
    . . . X . . .
    . . . X . . .
    . . . X . . .
```
```
Dama o Reina / Queen (Q)

    X . . X . . X
    . X . X . X .
    . . X X X . .
    X X X Q X X X
    . . X X X . .
    . X . X . X .
    X . . X . . X 
```
<br /><br />
### Reward

 - The first one to submit a working solution will earn `420` points for their coalition.
 - Everyone else submitting a working solutuin *(not yet submitted)* will earn `126` points for their coalition.
 - Every participant that tried to solve the challenge and pushed a solution will earn `84` points for their coalition.

<br /><br />
Good luck!
<br />
<sub>About the title: <a href="http://www.enciclopediamarvel.com/card/254">Asgard</a></sub>

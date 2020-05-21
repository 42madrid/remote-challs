<h1 align="center"><code>Monte Olimpo (Chall08) / Walk In a Minefield</code></h1>

<div align="center">
  <sub>Created by <a href="https://github.com/abguimba">Abraham Guimbao (lincoln)</a>, <a href="https://github.com/vesta-nna">Anna Dominguez (analogia)</a>, <a href="https://github.com/clafoutis42">Charles Labourier (pistache)</a></sub>
</div>
<div align="center">
  <sub>From <a href="https://42madrid.com">42 Madrid</a> for all the 42 Network</sub>
</div>

---

### Instructions
<sub>**Turn-in directory:** `chall08/`</sub><br />
<sub>**Files to turn in:** `<xlogin>.py`</sub><br />
<sub>**Language:** `Python3.x`</sub>

<sub>**Deadline:** 04.05.2020 - 11:42am</sub>
<br /><br />

### Subject

<p align="center">
  <img src="https://img-19.ccm2.net/y00wY5nsYZ5PXBZe1zvmGrHSttw=/14aacadcba0b4ae79ca940737efcb333/ccm-ugc/2fsz81EXfsTgLc04jb1-case-sans-valuer.png">
</p>

You must remotely send a sequence of orders to a robot to get it out of a minefield.

You win the game when the order sequence allows the robot to get out of the minefield without touching any mine. Otherwise it returns the position of the mine that destroyed it.  

A mine field is a grid, consisting of ASCII characters like the following:
```
+++++++++++++
+00000000000E
+0000000*000+
+00000000000+
+00000000*00+
+00000000000+
+M0000000000+
+++++++++++++
```

The mines are represented by `*`, the ground is represented by `0`, and the robot by `M`. The exit is represented by `E`.  
The orders understandable by the robot are as follows:
- `N` moves the robot one square to the north
- `S` moves the robot one square to the south
- `E` moves the robot one square to the east
- `W` moves the robot one square to the west
- `I` starts the engine of the robot
- `K` cuts the engine of the robot

If one tries to move it to a square occupied by a wall `+`, then the robot stays in place.  
If one tries to move the bot passed the exit, then the robot stays in place.  
If the robot is not started (`I/K`) then the commands are inoperative. It is possible to stop it or to start it as many times as desired.  
When the robot has reached the exit, it is necessary to stop it to win the game.

Write a program prompting the user to enter a minefield and then asks to enter a sequence of commands to guide the robot through the field.  
It displays after won or lost depending on the input command string.

For the purpose of this challenge, the input will be passed through stdin.  
The first lines will represent the map:
- A valid map must be a closed square with a single exit point.
- A valid map must have an exit point.
- A valid map has one robot. No more, no less.

It is possible for a map not to have any solution because of the placement of the mines. Such a map will be considered valid
but no combination of instructions will allow the robot to get out.

The map's input will be ended by an empty line.  
After this the robot's instructions will be passed on a single line.

Your program shall wait for the user to close the stdin by his

If the input is somehow invalid, print an error message of the form `./xlogin.py: Invalid input.`.  
If the robot has safely moved to the exit (or is not correctly stopped) after the execution of the instructions, print `Success.`.  
If the robot has not moved to the exit after the execution of the instructions, print `Failure.`.  
If the robot has exploded on a mine, print `Exploded.`.

You have to submit a **python3 executable script** to solve this problem.

### Examples

```
pistache@pistache-macbp:~ # ./xlogin.py
+++++++++++
+000000000E
+000000*00+
+000000000+
+000*00*00+
+000000000+
+M00*00000+
+++++++++++

INENNNNEEEEEEEEK
Success.
```
```
pistache@pistache-macbp:~ # ./xlogin.py
+++++++++++
+00000*000E
+000000*00+
+000000000+
+000000*00+
+000000000+
+M00*00000+
+++++++++++

INENNNNEEEEEEEEK
Exploded.
```
```
pistache@pistache-macbp:~ # ./xlogin.py
+++++++++++
+000000000E
+000000*00+
+000000000+
+000*00*00+
+000000000+
+M00*00000+
+++++++++++

INENNNNEEEEEEEE
Failure.
```
```
pistache@pistache-macbp:~ # ./xlogin.py
+++++++++++
+000000000E
+000000*00+
+000000000+
+000*00*00+
+000000000+
+M00*00000+
+++++++++++

INENNNNEEEK
Failure.
```
```
pistache@pistache-macbp:~ # ./xlogin.py
+++++++++++
+0000000000
+000000*00+
+000000000+
+000*00*00+
+000000000+
+M00*00000+
+++++++++++

INENNNNEEEEEEEEK
./xlogin.py: Invalid input.
```

<br /><br />
### Reward

 - The first one to submit a working solution will earn `2100` points for their coalition.
 - Everyone else submitting a working solutuin *(not yet submitted)* will earn `1260` points for their coalition.
 - Every participant that tried to solve the challenge and pushed a solution will earn `420` points for their coalition.

<br /><br />
Good luck!
<br />
<sub>About the title: <a href="https://mars.nasa.gov/gallery/atlas/olympus-mons.html">Monte Olimpo</a></sub>

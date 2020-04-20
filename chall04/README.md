<h1 align="center"><code>Prometeo (Chall04) / Bookshelf Problem</code></h1>

<div align="center">
  <sub>Created by <a href="https://github.com/abguimba">Abraham Guimbao (lincoln)</a>, <a href="https://github.com/vesta-nna">Anna Dominguez (analogia)</a>, <a href="https://github.com/clafoutis42">Charles Labourier (pistache)</a></sub>
</div>
<div align="center">
  <sub>From <a href="https://42madrid.com">42 Madrid</a> for all the 42 Network</sub>
</div>

---

### Instructions
<sub>**Turn-in directory:** `chall04/`</sub><br />
<sub>**Files to turn in:** `<xlogin>.py`</sub><br />
<sub>**Language:** `Python 3.x`</sub>

<sub>**Deadline:** 14.04.2020 - 11:42am</sub>
<br /><br />

### Subject

<p align="center">
  <img width="350" height="350" src="https://parentsafrica.com/wp-content/uploads/2019/05/bookshelf.jpg">
</p>

You have an enormous book collection and want to buy some shelfs. You go to a bookshelfstore and they sell all kinds of shelfs. The wierd part is, some shelfs are different in length but they all cost the same.

You now want to puzzle your collection so that you can fit as many books on the least number of shelfs.


For the purpose of this challenge, you will have to parse the input from a file, or the standard input.

A valid input will be formatted as follows:
- The first line are the available bookshelfs in the store, seperated by a space.
- From the second line on you get the book collections with the width followed by a title.

**Valid input:**
```
150 150 300 150 150
70 A Game of Thrones
76 A Clash of Kings
99 A Storm of Swords
75 A Feasts for Crows
105 A Dance With Dragons
```

The output must be the number of shelves you have to buy. If you can't fit all the books, or can't parse the file for some reason, print an error of the form `./xlogin.py: filename: error message`.

If one passes too much files, treat all the files in the passed order, and prefix the output of each file by `filename:\n`.

> NOTE: All the asked error messages are in the examples.
>
> NOTE 2: Solution that do not find the minimum number of shelves required will be accepted, for a smaller amount of points. However, those solution **MUST** try to fill the taken shelves at the most possible. A solution implying that a shelf can be empty **IS INVALID**.

You have to submit a **python3 executable script** to solve this problem.

### Examples
```
[42student@somewhere ~ ]$ ./xlogin.py << EOF
heredoc> 150 150 300 150 150
heredoc> 70 A Game of Thrones
heredoc> 76 A Clash of Kings
heredoc> 99 A Storm of Swords
heredoc> 75 A Feasts for Crows
heredoc> 105 A Dance With Dragons
heredoc> EOF
2
```
```
[42student@somewhere ~ ]$ ./xlogin.py got_collection.txt
2
```
```
[42student@somewhere ~ ]$ ./xlogin.py << EOF
heredoc> 500 500 500
heredoc> 1309 Artamene
heredoc> 303 A la recherche du temps perdu
heredoc> 399 Mission Earth
heredoc> EOF
./xlogin.py: stdin: Not enough space in the given shelves
```
```
[42student@somewhere ~]$ ./xlogin.py too_large_collection.txt
./xlogin.py: too_large_collection.txt: Not enough space in the given shelves
```
```
[42student@somewhere ~]$ ./xlogin.py ./too_large_collection.txt got_collection.txt
./too_large_collection.txt:
./xlogin.py: too_large_collection.txt: Not enough space in the given shelves

got_collection.txt:
2
```
```
[42student@somewhere ~]$ ./xlogin.py xlogin.py
./xlogin.py: xlogin.py: Can't read file
```
```
[42student@somewhere ~]$ ./xlogin.py not_existing_file
./xlogin.py: not_existing_file: Can't read file
```
```
[42student@somewhere ~]$ ./xlogin.py permission_denied_file
./xlogin.py: permission_denied_file: Can't read file
```
```
[42student@somewhere ~]$ ./xlogin << EOF
heredoc> 270 142 501 865 384 957 947 603 987 428 907 10 691 707 397 917 492 750 935 672 935 712 234 683 702 508 822 379 36 59 382 280 867 155 829 756 360 995 526 52 559 250 450 843 523 446 972 555 55 985 81 831 43 802 473 379 461 639 910 529 128 878 914 426 569 59 139 913 69 649 501 889 470 112 92 6 80 571 220 22 676 91 889 799 115 194 555 477 277 718 378 838 822 358 178 562 674
heredoc> 96 b400786
heredoc> 69 b390773
heredoc> 174 b410413
heredoc> 189 b337528
heredoc> 80 b308576
heredoc> 194 b151872
heredoc> 190 b174310
heredoc> 157 b272731
heredoc> 45 b326576
heredoc> 112 b379689
heredoc> 177 b18459
heredoc> 122 b915759
heredoc> 138 b967342
heredoc> 96 b786519
heredoc> 184 b718074
heredoc> 75 b696975
heredoc> 192 b46366
heredoc> 168 b533904
heredoc> 45 b885475
heredoc> 186 b872991
heredoc> 63 b231207
heredoc> 162 b912709
heredoc> 123 b786720
heredoc> 7 b743805
heredoc> 120 b862301
heredoc> 54 b929784
heredoc> 89 b61876
heredoc> 168 b775890
heredoc> 87 b850242
heredoc> 60 b695331
heredoc> 0 b56157
heredoc> 139 b875241
heredoc> 78 b281324
heredoc> 122 b236962
heredoc> 1 b79403
heredoc> 68 b213353
heredoc> 103 b650997
heredoc> 97 b955752
heredoc> 177 b815100
heredoc> 139 b958679
heredoc> 43 b829736
heredoc> 163 b445471
heredoc> 94 b472821
heredoc> 167 b5429
heredoc> 57 b946679
heredoc> 13 b748794
heredoc> 146 b920913
heredoc> 17 b547056
heredoc> 33 b437091
heredoc> 12 b247401
heredoc> 120 b228908
heredoc> 178 b509018
heredoc> 98 b482352
heredoc> 152 b915322
heredoc> 14 b874214
heredoc> 71 b164605
heredoc> 11 b457140
heredoc> 35 b502201
heredoc> 5 b15232
heredoc> 49 b641136
heredoc> 166 b385360
heredoc> 183 b78285
heredoc> 199 b274935
heredoc> 195 b424221
heredoc> 79 b422570
heredoc> 150 b502699
heredoc> 41 b662132
heredoc> 63 b430898
heredoc> 111 b813368
heredoc> 100 b700970
heredoc> 157 b803925
heredoc> 140 b611243
heredoc> 25 b877197
heredoc> 136 b577201
heredoc> 94 b50211
heredoc> 56 b762270
heredoc> 120 b578094
heredoc> 21 b672002
heredoc> 9 b107630
heredoc> 156 b547721
heredoc> 186 b911854
heredoc> 71 b594375
heredoc> 32 b330202
heredoc> 3 b464002
heredoc> 36 b718293
heredoc> 44 b282975
heredoc> 130 b826246
heredoc> 77 b529800
heredoc> 117 b66381
heredoc> 89 b949447
heredoc> 133 b348326
heredoc> 178 b517646
heredoc> 184 b809038
heredoc> 105 b70260
heredoc> 182 b894577
heredoc> 123 b203409
heredoc> 79 b174217
heredoc> 159 b552286
heredoc> 40 b854638
heredoc> 78 b159990
heredoc> 139 b743008
heredoc> 1 b714402
heredoc> 153 b923819
heredoc> 107 b201001
heredoc> 48 b567066
heredoc> 138 b570537
heredoc> 100 b64396
heredoc> 139 b412215
heredoc> 132 b805036
heredoc> 121 b772401
heredoc> 120 b370907
heredoc> 51 b388905
heredoc> 77 b442295
heredoc> 152 b195720
heredoc> 46 b453542
heredoc> EOF
12
```

<br /><br />
### Reward

 - The first one to submit a working solution will earn `840` points for their coalition.
 - Everyone else submitting a working solution *(not yet submitted)* will earn `252` points for their coalition.
 - Every participant that tried to solve the challenge and pushed a solution will earn `126` points for their coalition.
 
*Anyone submitting an optimised solution will earn `210` bonus points for their coalition.*

<br /><br />
Good luck!
<br />
<sub>About the title: <a href="https://solarsystem.nasa.gov/moons/saturn-moons/prometheus/in-depth/">Prometeo</a></sub>

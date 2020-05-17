<h1 align="center"><code>Telescopium (Chall09) / Time Formatting</code></h1>

<div align="center">
  <sub>Created by <a href="https://github.com/abguimba">Abraham Guimbao (lincoln)</a>, <a href="https://github.com/vesta-nna">Anna Dominguez (analogia)</a>, <a href="https://github.com/clafoutis42">Charles Labourier (pistache)</a></sub>
</div>
<div align="center">
  <sub>From <a href="https://42madrid.com">42 Madrid</a> for all the 42 Network</sub>
</div>

---

### Instructions
<sub>**Turn-in directory:** `chall09/`</sub><br />
<sub>**Files to turn in:** `<xlogin>.c`</sub><br />
<sub>**Language:** `C`</sub><br />
<sub>**Prototype:** `char *ft_format_duration(char *seconds);`</sub>

<sub>**Deadline:** 11.05.2020 - 11:42am</sub>
<br /><br />

### Subject

<p align="center">
  <img src="https://i.imgur.com/AuAtDlZ.jpg">
</p>

Your task is to write a function which formats and *returns* a duration, given as a string representing number of seconds, in a human-friendly way.

If it is zero, it just returns: `"now"`. Otherwise, the duration is expressed as a combination of years, days, hours, minutes and seconds.

Invalid input will return: `"Invalid input."`.

The resulting expression is made of components like 4 seconds, 1 year, etc. In general, a positive integer and one of the valid units of time, separated by a space. The unit of time is used in plural if the integer is greater than 1.

The components are separated by a comma and a space: `", "`. Except the last component, which is separated by: `" and "`, just like it would be written in English.

A more significant units of time will occur before than a least significant one. Therefore, 1 second and 1 year is not correct, but 1 year and 1 second is.

Different components have different unit of times. So there is not repeated units like in 5 seconds and 1 second.

A component will not appear at all if its value happens to be zero. Hence, 1 minute and 0 seconds is not valid, but it should be just 1 minute.

A unit of time must be used "as much as possible". It means that the function should not return 61 seconds, but 1 minute and 1 second instead. Formally, the duration specified by of a component must not be greater than any valid more significant unit of time.

> NOTE: For this challenge a year is always 365 days, a day is always 24 hours, an hour is always 60 minutes and a minute is always 60 seconds.

> NOTE2: The biggest number of seconds that you need to handle is `10000000000000000000`. Good luck :)

### Examples
```C
ft_format_duration("62") # returns "1 minute and 2 seconds"
ft_format_duration("3662") # returns "1 hour, 1 minute and 2 seconds"
ft_format_duration("0") # returns "now"
ft_format_duration("LOL42LOL") # returns "Invalid input."
ft_format_duration("") # returns "Invalid input."
ft_format_duration("2175984000") # returns "69 years"
ft_format_duration("   42") # returns "42 seconds"
ft_format_duration("   42 1") # returns "Invalid input."
ft_format_duration("42 1") # returns "Invalid input."
ft_format_duration("42   ") # returns "42 seconds"
ft_format_duration("+42") # returns "Invalid input."
ft_format_duration("-42") # returns "Invalid input."
ft_format_duration("0042") # returns "42 seconds"
ft_format_duration("0 42") # returns "Invalid input."
```

### Reward

 - The first one to submit a working solution will earn `2100` points for their coalition.
 - Everyone else submitting a working solutuin *(not yet submitted)* will earn `1260` points for their coalition.
 - Every participant that tried to solve the challenge and pushed a solution will earn `420` points for their coalition.

Good luck!
<br />
<sub>About the title: <a href="https://www.bbc.com/mundo/noticias-52583136">Telescopium</a></sub>

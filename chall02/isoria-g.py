import sys
letter=("a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z")
morse=(".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..")
if len(sys.argv) == 2 and (all(c.isalpha() for c in sys.argv[1])):
    string=(sys.argv[1]).lower()
    i = 0
    while i <= 25:
        string = string.replace(letter[i], morse[i])
        i=i+1
    print(string, end='')
else:
    print ("usage: ./xlogin.py <a-zA-Z string>")
# 42sh
EPITECH - First year project : Linux shell
## Features
### Command interpreter
```
ls

/usr/bin/ls

./42sh
```
### Builtins
#### commands
```
cd ; env ; setenv ; unsetenv ; history ; where ; which ; alias ; echo ; exit
```
#### Logic gates
``` 
cat my_file || echo "file not found"

touch my_file && ls
```
#### Redirections
```
echo something > my_file

echo some_more >> my_file

cat < my_file

cat << EOF
```
#### Pipes
```
cat my_file | grep thing
```
#### Backticks
```
cat `find . -name my_file`
```
#### Globbing
```
ls *
ls file.?pp
ls file.[a-z]
```
#### Semicolons
```
cd ; ls
```

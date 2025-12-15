# holbertonschool-simple_shell

## Description

**Simple Shell** is a simplified implementation of the Unix Shell ('/bin/sh'), written in C language.
This program allows the user to execute commands in interactive or non-interactive mode, in the same way as the stantard shell.

The shell interprets the entered commands, creates child processes and executes the corresponding programs using the authorized Unix system calls.

---

## Functionalities

- Mode **interactive**
- Mode **non-interactive**
- Execution of commands with their absolute path
- Error handling identical to '/bin/sh'
- Management of the variable 'PATH'
- Internal order 'exit'
- Correct display of error messages with 'argv[0]'

---

## Compilation

The shell must be compiled with the following command:

'''bash
gcc -Wall -Werror -Wextra -pendantic -std=gnu89 *.c -o hsh

---

## Use

Mode **interactive** launches the shell by typing ('./hsh')

---

#### Example

($) /bin/ls
hsh hand. c shell. c
($) exit

Mode **non-interactive** reads commands from the stantard input by typing '(echo "/bin/ls" | ./hsh)

---

## Error handling

The error messages displayed are identical to those of shekll /bin/sh, except for the program name which corresponds to 'argv[0]'

---

### Example 

'''bash
$ echo "qwerty" | . /hsh
./hsh: 1: qwerty: not found

---

## Allowed functions 

This project uses only the functions and system calls authorized by the subject, notably: 

- Functions of <string. h>
- fork, execve, wait 
- malloc, free
- getline, read, write
- perror, printf, fprintf
- stat, lstat, fstat
- opendir, readdir, closedir
- signal, kill

---

## Project files

- hand. c
- shell. c
- hsh
- man_1_simple_shell
- AUTHORS

---

## Authors

Maxence Henous and Bryan Martel 
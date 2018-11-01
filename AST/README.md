# How to Configure

## You will need:
* reflex
* bison
* g++
* make
* cmake

## Instructions
* Step 1: `git clone https://github.com/alonzno/Quack-Compiler.git`
* Step 2: `cd Parser`
* Step 3  `cmake .`
* Step 4: `make`
* Step 5: `./parser <filename>`

This program determines if a given Quack language file can be parsed successfully, or if it has syntax errors.  If syntax errors exist, the first one is reported along with its location.


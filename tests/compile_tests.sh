#!/usr/bin/env zsh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g tests.c ../string1.c ../string2.c ../search.c -o tests

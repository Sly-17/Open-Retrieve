#!/bin/sh

gcc -o fetch .src/fetch.c -lcurl
gcc -o share .src/share.c
gcc -o retrieve .src/retrieve.c

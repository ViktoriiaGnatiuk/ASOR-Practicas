#! /bin/bash
make clean
make
g++ -g -o $1 $1.cc

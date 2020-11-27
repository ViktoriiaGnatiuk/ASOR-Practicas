#! /bin/bash
make clean $1
make $1
g++ -g -o $1 $1.cc

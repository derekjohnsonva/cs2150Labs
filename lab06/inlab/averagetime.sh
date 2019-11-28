#!/bin/bash

# Derek Johnson dej3tc
# 10/22/2019

# We will first Prompt for the dictionary and the grid
read -e -p "Input the dictionary file: " dictFile
read -e -p "Input the grid file: " gridFile

t1=`./a.out $dictFile $gridFile | tail -1`
 
t2=`./a.out $dictFile $gridFile | tail -1`
t3=`./a.out $dictFile $gridFile | tail -1`
t4=`./a.out $dictFile $gridFile | tail -1`
t5=`./a.out $dictFile $gridFile | tail -1`

echo $(( (t1 + t2 + t3 + t4 + t5) / 5))
echo "Time in ms"

#!/bin/bash

#  Derek Johnson dej3tc
# 10/31/19

# We will first prompt the user for a number
# between 1 and 9 that will be used for the 
# timer program
read -e -p "Input a number between 1 and 9: " number
quit="quit"
if [ $number == $quit ] 
  then
  exit
fi
clang++ counter.cpp
i=1
RUNNING_TIME=0
while [ $i -lt 6 ]; do
  echo "Running iteration " $i"..."
  RUN=`./a.out $number | tail -1`
  RUNNING_TIME=$((RUNNING_TIME+RUN))
  echo "time taken: "$RUN "ms"
  i=$((i+1))
done
AVE=$((RUNNING_TIME / 5))
echo "5 iterations took" $RUNNING_TIME "ms"
echo "Average time was" $AVE "ms"

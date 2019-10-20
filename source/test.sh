#!/bin/bash
set -e

for i in {1..40}
do
  ./graph brg $((5*$i)) 0.0:1:0.01 -c 1000 > ../results/"t-brg$i.csv"
done


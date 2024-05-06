#!/bin/bash

# cat temp.txt| bash check_lines.sh

# Read input from pipeline
IFS=$'\n' read -d '' -r -a lines

# Loop through the lines and compare odd and even numbered lines
for ((i=1; i<${#lines[@]}; i+=2)); do
  even_line=${lines[$i-1]}
  odd_line=${lines[$i]}
  echo ${lines[$i-1]}
  echo ${lines[$i]}
  if [[ "$odd_line" != "$even_line" ]]; then
    echo "Error: Line $i and $((i+1)) are different."
  fi
done

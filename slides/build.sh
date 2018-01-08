#!/bin/bash
ls *.c | {
	while read nextc; do
    name=$(basename "$nextc" .c)
    echo "## $name"
    echo "~~~"
    cat "$nextc"
    echo "~~~"
    if [ -f $name.notes ]; then
      echo ":::"
      cat $name.notes
      echo ":::"
    fi
	done
} | pandoc $@ -t s5

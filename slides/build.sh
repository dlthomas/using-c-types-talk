#!/bin/bash

# format=${1:?format is required as first argument}
# shift

STARTED=

ls *.c | {
	while read nextc; do
    if [ "$STARTED" ]; then
      echo
      echo "----"
      echo
    fi
    STARTED=1
    name=$(basename "$nextc" .c)
    echo "~~~"
    cat "$nextc"
    echo "~~~"
    if [ -f $name.notes ]; then
      echo "::: notes"
      cat $name.notes
      echo ":::"
    fi
    if ! gcc -c -o /dev/null $nextc 2>tmp.out; then
      echo
      sed 's/^/> /' <tmp.out
    fi
	done
} | pandoc --standalone -t dzslides -o slides.html $@

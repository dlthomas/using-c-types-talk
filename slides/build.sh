#!/bin/bash

# format=${1:?format is required as first argument}
# shift

STARTED=

function endslide { echo; echo "----"; echo; }

ls *.c | {
	while read nextc; do
    if [ "$STARTED" ]; then
      endslide
    fi
    STARTED=1
    name=$(basename "$nextc" .c)
    echo "~~~"
    sed 's/./ &/' "$nextc"
    echo "~~~"
    if [ -f $name.notes ]; then
      echo "::: notes"
      cat $name.notes
      echo ":::"
    fi
    if ! gcc -c -o /dev/null $nextc 2>tmp.out; then
      endslide
      sed 's/^/> /' <tmp.out
      rm tmp.out
    fi
	done
} | pandoc --standalone -t dzslides -o slides.html $@

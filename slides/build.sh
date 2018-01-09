#!/bin/bash

# format=${1:?format is required as first argument}
# shift

STARTED=

function endslide { echo; echo "----"; echo; }
function fmtcode { cat -n | sed 's/   //'; }

ls *.c | {
	while read nextc; do
    if [ "$STARTED" ]; then
      endslide
    fi
    STARTED=1
    name=$(basename "$nextc" .c)
    echo "~~~"
    <"$nextc" fmtcode
    echo "~~~"
    if [ -f $name.notes ]; then
      echo "::: notes"
      cat $name.notes
      echo ":::"
    fi
    if ! gcc $(sdl2-config --cflags) -c -o /dev/null $nextc 2>tmp.out; then
      endslide
      echo "~~~ {.error}"
      sed 's/./ &/' tmp.out
      echo "~~~"
      endslide
      echo "~~~"
      <"$nextc" fmtcode
      echo "~~~"
      rm tmp.out
    fi
	done
} >slides.md
pandoc --standalone -t dzslides -o slides.html $@ <slides.md
sed -itmp 's/<code>/<code class="language-c">/' slides.html
if [ "$MAKE_PATCH" ]; then
  git diff -R slides.html >slides.patch
fi

patch -p2 <slides.patch

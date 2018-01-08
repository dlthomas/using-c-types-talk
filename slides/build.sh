#!/bin/bash
ls *.[ch] | {
	while read nextc; do
		next=$(basename -s .h -s .c $nextc).html
		highlight -l -o $next $nextc
		if [ "$this" ]; then
			sed -i "s/^\\(<body.*\\)>/\\1 onkeypress=\"if(event.which == 32 || event.which == 108) { document.location = '$next'; return false; } return true;\">/" $this
		fi
		this=$next
	done
}

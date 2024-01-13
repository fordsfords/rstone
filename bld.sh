#!/bin/sh

for F in *.md; do :
  if egrep "<!-- mdtoc-start -->" $F >/dev/null; then :
    # Update doc table of contents (see https://github.com/fordsfords/mdtoc).
    if which mdtoc.pl >/dev/null; then mdtoc.pl -b "" $F;
    elif [ -x ../mdtoc/mdtoc.pl ]; then ../mdtoc/mdtoc.pl -b "" $F;
    else echo "FYI: mdtoc.pl not found; see https://github.com/fordsfords/mdtoc"; exit 1
    fi
  fi
done

gcc -o c_linux_getopts c_linux_getopts.c;  if [ "$?" -ne 0 ]; then exit 1; fi

gcc -o c_linux_threads c_linux_threads.c;  if [ "$?" -ne 0 ]; then exit 1; fi
javac JavaThreads.java;  if [ "$?" -ne 0 ]; then exit 1; fi

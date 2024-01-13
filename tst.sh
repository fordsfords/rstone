#!/bin/sh

./bld.sh;  if [ $? -ne 0 ]; then exit 1; fi

java -cp . JavaThreads; if [ "$?" -ne 0 ]; then exit 1; fi

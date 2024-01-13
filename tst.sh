#!/bin/sh

./bld.sh;  if [ $? -ne 0 ]; then exit 1; fi


./c_linux_getopts xyz;  if [ "$?" -ne 0 ]; then exit 1; fi

./bash_getopts.sh xyz;  if [ "$?" -ne 0 ]; then exit 1; fi


./c_linux_threads;  if [ "$?" -ne 0 ]; then exit 1; fi

java -cp . JavaThreads;  if [ "$?" -ne 0 ]; then exit 1; fi

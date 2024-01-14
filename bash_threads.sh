#!/bin/sh
# bash_threads.sh - demonstrate command-line parsing in bash.
# See https://github.com/fordsfords/rstone
#
# This code and its documentation is Copyright 2023,2024 Steven Ford
# and licensed "public domain" style under Creative Commons "CC0":
#   http://creativecommons.org/publicdomain/zero/1.0/
# To the extent possible under law, the contributors to this project have
# waived all copyright and related or neighboring rights to this work.
# In other words, you can use this code for any purpose without any
# restrictions.  This work is published from: United States.  The project home
# is https://github.com/fordsfords/rstone

PRINT_THREAD_RUNNING=
PRINT_THREAD_PID=

print_thread_run() {
  STATS_INTERVAL_SEC=$1
  SECS_SINCE_LAST_PRINT=0

  PRINT_THREAD_RUNNING=1
  trap "PRINT_THREAD_RUNNING=0" HUP INT QUIT TERM
  while [ $PRINT_THREAD_RUNNING -ne 0 ]; do :
    if [ $SECS_SINCE_LAST_PRINT -ge $STATS_INTERVAL_SEC ]; then :
      echo "print_thread: Hi"
      SECS_SINCE_LAST_PRINT=0
    fi

    sleep 1
    SECS_SINCE_LAST_PRINT=`expr $SECS_SINCE_LAST_PRINT + 1`
  done

  echo "print_thread: bye"
}

print_thread_start() {
  print_thread_run $1 &
  PRINT_THREAD_PID=$!
}

print_thread_terminate() {
  kill $PRINT_THREAD_PID
  wait $PRINT_THREAD_PID
}


echo "main: Starting"
print_thread_start 2

echo "main: Sleeping 4.1 seconds"
sleep 4.1

echo "main: terminate print thread"
print_thread_terminate

echo "main: Done"

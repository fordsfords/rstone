#!/bin/sh
# bash_getopts.sh
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

usage() {
  if [ "$1" != "" ]; then :
    echo "$1" 1>&2
  fi
  echo "Usage: bash_getopts [-h] [-t testnum] input_file" 1>&2; echo "" 1>&2
  exit 1
}

# Can call help with an optional message
help() {
  if [ "$1" != "" ]; then echo "$TOOL: $1"; echo ""; fi

  cat <<__EOF__
Usage: bash_getopts [-h] [-t testnum] input_file
Where:
  -h - help (prints this help text)
  -t testnum : number of test to perform
  input_file : required positional parameter\n"
__EOF__
  exit 0
}  # help


# command-line parsing

# Set defaults.
TESTNUM=1

while getopts "ht:" OPT
do
  case $OPT in
    h) help ;;
    t) TESTNUM=$OPTARG ;;
    \?) usage ;;
  esac
done
shift `expr $OPTIND - 1`  # Make $1 the first positional param after options

if [ "$1" = "" ]; then usage "Missing in_file"; fi
INPUT_FILE="$1"
shift 1  # Make $1 the next positional param

if [ "$1" != "" ]; then usage "Unrecognized parameter '$1'"; fi

##############################################################################
# MAIN CODE
##############################################################################

echo "TESTNUM=$TESTNUM, INPUT_FILE='$INPUT_FILE'"

exit 0

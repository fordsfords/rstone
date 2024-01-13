#!/usr/bin/env perl
# perl_getopts.pl - demonstrate command-line parsing in Perl.
#
# This code and its documentation is Copyright 2023-2024 Steven Ford
# and licensed "public domain" style under Creative Commons "CC0":
#   http://creativecommons.org/publicdomain/zero/1.0/
# To the extent possible under law, the contributors to this project have
# waived all copyright and related or neighboring rights to this work.
# In other words, you can use this code for any purpose without any
# restrictions.  This work is published from: United States.  The project home
# is https://github.com/fordsfords/rstone

use strict;
use warnings;
use Getopt::Std;


# Set defaults.
my $testnum = 1;
my $inputfile;

# process options.
use vars qw($opt_h $opt_t);
getopts('ht:') || usage();

if (defined($opt_h)) {
  help();
}
if (defined($opt_t)) {
  $testnum = $opt_t;
}

$inputfile = shift(@ARGV);
if (!defined($inputfile)) {
  usage("Missing inputfile");
}
if (defined($ARGV[0])) {
  usage("Extra positional parameter(s)");
}

print "testnum=$testnum, inputfile=$inputfile\n";

# All done.
exit(0);


# End of main program, start subroutines.

sub usage {
  my($err_str) = @_;

  if (defined $err_str) {
    print "$err_str\n";
  }
  print <<__EOF__;
Usage: per_getopts.pl [-h] [-o out_file] inputfile
__EOF__
  exit(1);
}

sub help {
  print <<__EOF__;
Usage: per_getopts.pl [-h] [-o out_file] inputfile
Where ('R' indicates required option):
    -h - help
    -o out_file - output file (default: STDOUT).
    file ... - zero or more input files.  If omitted, inputs from stdin.

__EOF__
  exit(0);
}  # help

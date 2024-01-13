# rstone
My programming rosetta stone.

<!-- mdtoc-start -->
&DoubleRightArrow; [rstone](#techo)  
<!-- TOC created by '../mdtoc/mdtoc.pl README.md' (see https://github.com/fordsfords/mdtoc) -->
<!-- mdtoc-end -->

## My Rosetta Stone

Feature | C | Bash | Perl | Python
--------|---|------|------|-------
For     | for (i=0; i<10; i++) {} | for I in *; do <br> for I in {3..8}; do | [for](https://perldoc.perl.org/perlsyn#For-Loops) (my $i = 3; $i <= 8; $i++) { <br> foreach my $i (@array) { | for i in array
Break   | break; | break | [last](https://perldoc.perl.org/perlsyn#Loop-Control) | break
Continue| continue; | continue | next; | continue
Else if | else if () | elif [ ] | elsif () | elif
String cmp | if (strcmp(s,"abc")==0) | if [ "$S" = "abc" ] | if ($s eq "abc") | if s == "abc"
Find char | p=strchr(s, c);<br>p=strnchr(s, c, l) | n.a. | i=[index(s, c)](https://perldoc.perl.org/functions/index); i=index(s, c, s_offset);</a> | ???
Function | void f(int i) { | F () {; $1 | sub f { my ($i) = @_; | def f (i)
magic input | n.a. | n.a. | while (<>) { | import fileinput<br>for iline in fileinput.input():
regexp | n.a. | if echo $S | grep "pat" >/dev/null | if (/pat/)<br>if ($s=~/pat/) | import re<br>mo = re.search(r'pat', s)<br>if mo:
print no nl | printf("prompt: "); | echo -n "prompt: " | print "prompt: "; | print("prompt: ", end='')
getopts | 

## License

I want there to be NO barriers to using this code, so I am releasing it to the public domain.  But "public domain" does not have an internationally agreed upon definition, so I use CC0:

Copyright 2012,2024 Steven Ford http://geeky-boy.com and licensed
"public domain" style under
[CC0](http://creativecommons.org/publicdomain/zero/1.0/):
![CC0](https://licensebuttons.net/p/zero/1.0/88x31.png "CC0")

To the extent possible under law, the contributors to this project have
waived all copyright and related or neighboring rights to this work.
In other words, you can use this code for any purpose without any
restrictions.  This work is published from: United States.  The project home
is https://github.com/fordsfords/rstone

To contact me, Steve Ford, project owner, you can find my email address
at http://geeky-boy.com.  Can't see it?  Keep looking.

## Introduction

Sometimes its hard remember which programming language uses which syntax.
For example, "endif" -- does Bourne shell use that?  Or does it use "fi"?
Spoiler: "fi" is shell.  So who does use "endif"?
C pre-processor conditionals.  :-)

Thanks to http://bhami.com/rosetta.html for making a far more useful site
(and coming up with an awesome name).

Master source: https://github.com/fordsfords/rstone

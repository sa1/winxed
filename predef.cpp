// predef.cpp
// Revision 22-oct-2009

#include "predef.h"

void emit_predef(std::ostream & os)
{
	os <<
"# Predefined functions\n"
"\n"
".sub 'is_null'\n"
"  .param pmc value\n"
"  $I0 = isnull value\n"
"  .return($I0)\n"
".end\n"
"\n"
".sub 'die'\n"
"  .param string reason\n"
"  die reason\n"
".end\n"
"\n"
".sub 'exit'\n"
"  .param int code\n"
"  exit code\n"
".end\n"
"\n"
".sub 'print'\n"
"  .param pmc args :slurpy\n"
"  .local pmc it\n"
"  it = iter args\n"
"  it = .ITERATE_FROM_START\n"
"next:\n"
"  unless it goto argsend\n"
"  .local string s\n"
"  s = shift it\n"
"  print s\n"
"  goto next\n"
"argsend:\n"
".end\n"
"\n"
".sub 'say'\n"
"  .param pmc args :slurpy\n"
"  'print'(args :flat)\n"
"  say ''\n"
".end\n"
"\n"
".sub 'join'\n"
"  .param string sep\n"
"  .param pmc ar\n"
"  .local string s\n"
"  s = join sep, ar\n"
"  .return(s)\n"
".end\n"
".sub 'length'\n"
"  .param string s\n"
"  $I0 = length s\n"
"  .return($I0)\n"
".end\n"
"\n"
".sub 'split'\n"
"  .param string sep\n"
"  .param string value\n"
"  .local pmc ar\n"
"  ar = split sep, value\n"
"  .return(ar)\n"
".end\n"
"\n"
".sub 'Error'\n"
"  .param string msg\n"
"  .local pmc ex\n"
"  ex = root_new ['parrot';'Exception']\n"
"  ex['message'] = msg\n"
"  .return(ex)\n"
".end\n"
"\n"
	;
}

// End of predef.cpp
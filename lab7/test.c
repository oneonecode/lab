//////////////////////////////////////////////////////////////////////////////////////////////////
//  function  : shell         author  :  luoshuren;         date  :  2017,11,6;                 //
//  version   : v3.1                                                                            //
//  detail    : if you input "help" command, it will list every valid command in this shell,    //
//              and interpretation follows.                                                     //
//////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include "datastruct.h"
#include "newshell.h"
int main()
{
	extern tLinkTable* L;
	init(L);
	printf("this shell have %d commands, you can enter \"help\" to review them.\n", L->nodenum );
	excuteShell();
	return 0;
}

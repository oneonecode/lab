#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastruct.h"

tCmdNode* FindCmd(tCmdNode *p, char command[])
{
	while( p!= NULL)
	{
		if(strcmp(p->cmd, command) == 0)
		{
			return p;
		}
		p = p->next;
		if(p == NULL)
		{
			printf("invalid command!\n");
			return NULL;
		}
	}
}

int ShowAllCmd(tCmdNode *p)
{
	while(p!=NULL)
	{
		printf("%-8s %s",p->cmd,p->describle);
		p=p->next;
	}
	return 0;
}

int excuteCmd(tCmdNode *p, char command[])
{
	tCmdNode *q = FindCmd(p, command);
	printf("%s %s", q->cmd, q->describle);
	if(q->function != NULL)
	{
		q->function();
	}
	return 0;
}

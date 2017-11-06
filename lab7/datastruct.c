#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "datastruct.h"

tLinkTable* CreatLinkTable()
{
	tLinkTable* L = (tLinkTable*)malloc(sizeof(tLinkTable));
	L->head     = NULL;
	L->nodenum  = 0;
	return L;
}

tCmdNode* CreatCmdNode(char* cmd, char* describle, int (*function)())
{
	tCmdNode* q = (tCmdNode*)malloc(sizeof(tCmdNode));
	q->cmd = cmd;
	q->describle = describle;
	q->function = function;
	return q;
}

tNode* CreatNode(tCmdNode* q)
{
	tNode* p = (tNode*)malloc(sizeof(tNode));
	if (!p) exit(0);
	p->cmdnode = q;
	p->next = NULL;
	return p;
}

int AddLinkTable(tLinkTable* L, tNode *p)
{
	p->next  =  L->head;
	L->head  =  p;
	L->nodenum ++;
	return 0;
}

tNode* FindCmd(tLinkTable *L, char command[])
{
	tNode* q=L->head ;
	while( q!= NULL)
	{
		if(strcmp(q->cmdnode ->cmd, command) == 0)
		{
			return q;
		}
		q = q->next;
		if(q == NULL)
		{
			printf("invalid command!\n");
			return NULL;
		}
	}
}

int ShowAllCmd(tLinkTable* L)
{
	tNode* q=L->head ;
	while(q!=NULL)
	{
		printf("%-8s %s",q->cmdnode->cmd ,q->cmdnode->describle );
		q=q->next;
	}
	return 0;
}

int excuteCmd(tLinkTable *L, char command[])
{
	tNode *q = FindCmd(L, command);
	if(q==NULL) return 1;
	printf("%s --%s", q->cmdnode ->cmd, q->cmdnode ->describle);
	if(q->cmdnode ->function != NULL)
	{
		q->cmdnode ->function();
	}
	return 0;
}

int addnewnode(tLinkTable* L,char *cmd,char describle[],int (*function)())
{
	tNode* p;
	tCmdNode* q;
	q = CreatCmdNode( cmd, describle, function);
	p = CreatNode(q);
	AddLinkTable(L, p);
}

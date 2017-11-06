#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <direct.h>
#include <stddef.h>
#include <string.h>
#include <malloc.h>
#include "datastruct.h"
#include "newshell.h"

tLinkTable* L = CreatLinkTable();
char static dir[128]="/";
int printcommand()//print command list
{
	ShowAllCmd(L);
	return 0;
}

int printtime()//print real time
{
	time_t t;
	char *realtime;
	time(&t);
	realtime=ctime(&t);
	printf("%s",realtime);
	return 0;
}

int printcurrentdir()//print current path
{
	char here[128];
	getcwd(here,128);
	printf("%s\n",here);
	return 0;
}

int clear()//clear screen
{
	system("cls");
	return 0;
}

int changedir()//jump to directory you want
{
	char temp[128];
	int i;
	scanf("%s",temp);
	if(!(strcmp(temp,"..")))//如果选项为".."时，切换至上层目录 
	{
		i=strlen(dir);
		while(dir[i-1]!='/')
		{
			dir[i-1]='\0';
			i--;
		}
		if(strlen(dir)==1);
		else dir[i-1]='\0';
	}
	else if(!(strncmp(temp,"/",1)))//如果选项为"/"时，代表该路径为绝对路径，切换至该绝对路径 
		strcpy(dir,temp);
	else                       //选项为相对路径则切换至该相对路径 
	{
		if(strlen(dir)==1);
		else dir[strlen(dir)] = '/';
		strcat(dir,temp);
	}
	if((_chdir(dir)))        //如果路径错了，不切换，保留原来路径 
	{
		printf("wrong path!\n") ;
		i=strlen(dir);
		while(dir[i-1]!='/')
		{
			dir[i-1]='\0';
			i--;
		}
		if(strlen(dir)==1);
		else dir[i-1]='\0';
	}
	return 0;
}

int add()//compute summary
{
	int a,b;
	printf("please enter two number :");
	scanf("%d,%d",&a,&b);
	printf("a + b = %d\n", a + b);
	return 0;
}

int sub()//compute subtraction
{
	int a,b;
	printf("please enter two number :");
	scanf("%d,%d",&a,&b);
	printf("a - b = %d\n", a - b);
	return 0;
}

int quit()
{
	exit (0);
}

void init(tLinkTable* L)
{
	addnewnode(L,"help",  "--list command.\n",             printcommand);
	addnewnode(L,"clear", "--clear the screen.\n",         clear);
	addnewnode(L,"now",   "--print current time.\n",       printtime);
	addnewnode(L,"here",  "--print current directory.\n",  printcurrentdir);
	addnewnode(L,"cd",    "--change directory.\n",         changedir);
	addnewnode(L,"add",   "--compute summary.\n",          add);
	addnewnode(L,"sub",   "--compute subtraction.\n",      sub);
	addnewnode(L,"quit",  "--quit the shell.\n",           quit);
}

void excuteShell()
{
	
	while(1)
	{
		char command[128];
		
		printf("rootshell:C:$ ",dir);//fgets(command,128,stdin);
		scanf("%s", command);	
		excuteCmd(L, command);
	}
}

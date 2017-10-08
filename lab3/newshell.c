//////////////////////////////////////////////////////////////////////////////////////////////////
//  function  : shell;        author  :  luoshuren;         date  :  2017,9,23;                 //
//  version   : v2.0                                                                            //
//  detail    : if you input "help" command, it will list every valid command in this shell,    //
//              and interpretation follows.                                                     //
//////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <direct.h>
#include <stddef.h>
#include <string.h>
#include "datastruct.h"

int printcommand();
int printtime();
int printcurrentdir();
int clear();
int changedir();
int add();
int sub();
int quit();

static tCmdNode Cmd[] = 
{
	{"help",  "--list command.\n",             printcommand,     &Cmd[1]},
	{"clear", "--clear the screen.\n",         clear,            &Cmd[2]},
	{"now",   "--print current time.\n",       printtime,        &Cmd[3]},
	{"here",  "--print current directory.\n",  printcurrentdir,  &Cmd[4]},
	{"cd",    "--change directory.\n",         changedir,        &Cmd[5]},
	{"add",   "--compute summary.\n",          add,              &Cmd[6]},
	{"sub",   "--compute subtraction.\n",      sub,              &Cmd[7]},
	{"quit",  "--quit the shell.\n",           quit,             NULL   }
};

char static dir[128]="/"; 

int printcommand()//print command list
{
    ShowAllCmd(Cmd);
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

int main()
{
	char command[128];
	while(1)
    {
    	printf("rootshell#:C:%s@#$: ",dir);
		scanf("%s", command);	
		excuteCmd(Cmd, command);
    }
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//  function  ： shell;        author  :  luoshuren；         date  ：  2017，9，23；           //
//                                                                                              //
//  detail  ： if you input "help" command, it will list every valid command in this shell,     //
//          and interpretation follows.                                                         //
//////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <direct.h>
#include <stddef.h>
#include <string.h>
char static dir[128]="/"; 

void printcommand()//print command list
{
    printf("help        --list all command and interprwtation.\n");
	printf("clear       --clear the screen.\n");
    printf("now         --print current time in screen.\n");
	printf("here        --print current directory.\n");
	printf("cd [path]   --change directory.\n");
	printf("add         --compute summary.\n");
	printf("sub         --compute subtraction.\n");
	printf("quit        --quit the shell.\n");	
}

void printtime()//print real time
{
	time_t t;
	char *realtime;
	time(&t);
	realtime=ctime(&t);
	printf("%s",realtime);
}

void printcurrentdir()//print current path
{
	char here[128];
	getcwd(here,128);
	printf("%s\n",here);
}

void clear()//clear screen
{
	system("cls");
}

void changedir()//jump to directory you want
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
}

void add()//compute summary
{
	int a,b;
	printf("please enter two number :");
	scanf("%d,%d",&a,&b);
	printf("a + b = %d\n", a + b);
}

void sub()//compute subtraction
{
	int a,b;
	printf("please enter two number :");
	scanf("%d,%d",&a,&b);
	printf("a - b = %d\n", a - b);
}

int main()
{
	char cmd[128];
	while(1)
    {
    	printf("rootshell#:C:%s@#$: ",dir);
		scanf("%s", cmd);
        
        if(!strcmp(cmd,  "help"))
        {
        	printcommand();
		}
		else if(!strcmp(cmd,  "clear"))
        {
        	clear();
		}
		else if(!strcmp(cmd,  "now"))
		{
			printtime();
		}
		else if(!strcmp(cmd,  "here"))
		{
			printcurrentdir();
		}
		else if(!strcmp(cmd,  "cd"))
		{	
			changedir();
		}
		else if(!strcmp(cmd,  "add"))
		{
			add();
		}
		else if(!strcmp(cmd,  "sub"))
		{
			sub();
		}
		else if(!strcmp(cmd,  "quit"))
		{
			exit(0);
		}
		else
		{
			printf("\"%s\" is not a valid command! you can input \"help\" \nto veiw the list of command, please input again!\n", cmd);
		}
    }
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//  function  £º shell;        author  :  luoshuren£»         date  £º  2017£¬9£¬23£»           //
//                                                                                              //
//  detail  £º if you input "help" command, it will list every valid command in this shell,     //
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

void printcommand()
{
    	printf("help        --list all command and interprwtation.\n");
		printf("clear       --clear the screen.\n");
    	printf("now         --print current time in screen.\n");
		printf("here        --print current directory.\n");
		printf("cd [path]   --change directory.\n");
		printf("help        --list all command and interprwtation.\n");
		printf("help        --list all command and interprwtation.\n");
		printf("quit        --quit the shell.\n");	
}

void printtime()
{
	time_t t;
	char *realtime;
	
	time(&t);
	realtime=ctime(&t);
	printf("%s",realtime);
}

void printcurrentdir()
{
	char here[128];
	getcwd(here,128);
	printf("%s\n ",here);
}

void clear()
{
	system("cls");
}

void changedir()
{
	char temp[128];
	int i;
	scanf("%s",temp);
	if(!(strcmp(temp,"..")))
	{
		i=strlen(dir);
		while(dir[i-1]!='/')
		{
			dir[i-1]='\0';
			i--;
		}
		if(strlen(dir)==1);
		else
		dir[i-1]='\0';
	}
	else if(!(strncmp(temp,"/",1)))
	{
		strcpy(dir,temp);
	}
	else 
	{
		if(strlen(dir)==1);
		else
		dir[strlen(dir)] = '/';
		strcat(dir,temp);
	}
	if((_chdir(dir))) 
	{
		printf("wrong path!\n") ;
		i=strlen(dir);
		while(dir[i-1]!='/')
		{
			dir[i-1]='\0';
			i--;
		}
		if(strlen(dir)==1);
		else
		dir[i-1]='\0';
	}
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
		else if(!strcmp(cmd,  ""))
		{
			
		}
		else if(!strcmp(cmd,  ""))
		{
			
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

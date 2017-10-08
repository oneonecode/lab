typedef struct CmdNode
{
	char*   cmd;
	char*   describle;
	int     (*function)();
	struct  CmdNode* next;
} tCmdNode;

tCmdNode* FindCmd(tCmdNode *p, char cmd[]); 
int ShowAllCmd(tCmdNode *p);
int excuteCmd(tCmdNode *p, char command[]);

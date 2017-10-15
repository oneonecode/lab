typedef struct CmdNode
{
	char*   cmd;
	char*   describle;
	int     (*function)();
} tCmdNode;

typedef struct Node
{
	tCmdNode*     cmdnode;
	struct Node*  next;
}tNode;

typedef struct LinkTable
{
	tNode* head;
	int    nodenum;
}tLinkTable;

tLinkTable* CreatLinkTable();
tCmdNode* CreatCmdNode(char* cmd, char* describle, int (*function)());
tNode* CreatNode(tCmdNode* q);
int AddLinkTable(tLinkTable* L, tNode *p);
int addnewnode(tLinkTable* L,char *cmd,char *describle,int (*function)());

tNode* FindCmd(tLinkTable *L, char command[]);
int ShowAllCmd(tLinkTable* L);
int excuteCmd(tLinkTable *L, char command[]);

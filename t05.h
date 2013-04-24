#include"clsscr.h"
#define outmsg	"<font color=red size=3>%s</font>&nbsp;<a href='%s' target=_blank>%s</a><br>"
#define ignor1  ".git"
#define substr  "include"
#define blen	1024*1000
#define zero(a)	memset(a,0,sizeof(a));
#define verf(a,b)  if((a-b)>=blen) return 0;
int  tagnum=3;
//char targetfile[3][5]={".c",".h",".htm"};
char targetfile[3][5]={".php",".html",".htm"};
char deststr[100];//搜索字符串长度不超过100字节
char *c,*c1,ch[blen];
int fn(const char *file,const struct stat *st,int flag);
int comp(const char *f,int i);
int comp_sub(char *p,const char *psub);
int comp_def(char *p,const char *psub);


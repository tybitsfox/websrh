#include"t05.h"
int fn(const char *file,const struct stat *st,int flag);
int main(int argc,char** argv)
{
	char ch[200];
	int i,j,k;
	ftw(argv[1],fn,500);
	return 0;
}
int fn(const char *file,const struct stat *st,int flag)
{
	char ch[2048];
	int i,j,k;
	if(flag==FTW_D)
	{
		if(strstr(file,".git")!=NULL)
		{
			return 0;
		}
	}
	if(flag==FTW_SL)
		return 0;
	if(flag==FTW_NS)
		return 0;
	if(flag==FTW_F)
	{
		printf("%s\n",file);
	}
	return 0;
}



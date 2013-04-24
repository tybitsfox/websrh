#include"t05.h"
//{{{ int main
int main(int argc,char** argv)
{
	//char ch[200];
	int i,j,k;
	if(argc!=2)
		return 0;
	zero(deststr);
	memcpy(deststr,argv[1],strlen(argv[1]));
	i=strlen(deststr);
	if(deststr[i]=='\n')
		deststr[i]=0;
	if(deststr[i-1]=='\n')
		deststr[i-1]=0;
	zero(ch);
	c=ch;
	ftw("./",fn,500);
	printf("%s\n",ch);
	return 0;
}//}}}
//{{{ int fn(const char *file,const struct stat *st,int flag)
int fn(const char *file,const struct stat *st,int flag)
{
	char ch[2048];
	int i,j,k;
	if(strstr(file,ignor1)!=NULL)
		return 0;
	if(flag==FTW_SL)
		return 0;
	if(flag==FTW_NS)
		return 0;
	if(flag==FTW_F)
	{
		j=0;
		for(i=0;i<tagnum;i++)
		{
			if(strstr(file,targetfile[i])!=NULL)
				comp(file,i);
	//			printf("%s\n",file);
		}
	}
	return 0;
}
//}}}
//{{{ int comp(const char *f,int i)
int comp(const char *f,int i)
{
	FILE *file;
	int j,k,l,m,n;
	char buf[2048];
	verf(c,ch);
	zero(buf);
	file=fopen(f,"r");
	if(file==NULL)
		return 0;
	while(fgets(buf,sizeof(buf),file)!=NULL)
	{
		if(i==0)//php文件，考虑include的文件
		{
			if(strstr(buf,substr)!=NULL)
			{
				comp_sub(buf,f);
			}
		}//这里准备考虑模糊查询upper
		m=comp_def(buf,f);
		if((c-ch)>=blen)
		{
			fclose(file);
			return 0;
		}
		zero(buf);
		if(m==0)
			break;
	}
	fclose(file);
	return 0;
}
//}}}
//{{{ int comp_def(char *p,const char *psub)
int comp_def(char *p,const char *psub)
{
	char b[2048];
	char b1[1024];
	int j,k;
	zero(b1);
	memcpy(b1,psub,strlen(psub));
	//printf("%s\n",psub);
	//return 0;
	if(strstr(p,deststr)!=NULL)//find it!
	{
		zero(b);
		j=strlen(p);
		if(p[j]=='\n')
			p[j]=0;
		if(p[j-1]=='\n')
			p[j-1]=0;
		if(j>1000)
			p[1000]=0;
		j=strlen(b1);
		if(b1[j]=='\n')
			b1[j]=0;
		if(b1[j-1]=='\n')
			b1[j-1]=0;
		snprintf(b,sizeof(b),outmsg,deststr,b1,b1);
		j=strlen(b);
		memcpy(c,b,j);
		c+=j;
		return 0;
	}
	return 1;
}
//}}}
//{{{ int comp_sub(char *p,const char *psub)
int comp_sub(char *p,const char *psub)
{
	char *a1,*a2,b[2048],a[2048],v[2048];
	char nn[512];
	FILE *file;
	int i,j,k;
	zero(nn);
	a1=strchr(p,'\"');
	if(a1==NULL)
	{
		return 0;
	}
	a1++;
	a2=strchr(a1,'\"');
	if(a2==NULL)
	{
		return 0;
	}
	if(a2<=a1 || (a2-a1)>512)
	{
		return 0;
	}
	memcpy(nn,a1,a2-a1);//取得文件名
	file=fopen(nn,"r");
	if(file==NULL)
		return 0;
	zero(a);
	while(fgets(a,sizeof(a),file)!=NULL)
	{
		k=comp_def(a,psub);
		if((c-ch)>=blen)
		{
			fclose(file);
			return 0;
		}
		zero(a);
		if(k==0)
			break;
	}
	fclose(file);
	/*verf(c,ch);
	zero(b);
	snprintf(b,sizeof(b),outmsg,nn,psub);
	j=strlen(b);
	memcpy(c,b,j);
	c+=j;*/
	return 0;
}//}}}




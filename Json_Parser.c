#include<stdio.h>
#include<string.h>
int id_value_pair(char *s,char (*header)[10],char (* value_pair0)[100],int start,int limit)
{
  int i,j,k=start,z;
	for(j=0;k<limit;j++)
	{
		for(i=0;s[k]!=':'&&k<limit&&s[k]!=']'&&s[k]!='}';i++,k++)
		header[j][i]=s[k];
	
		header[j][i]=='\0';
				
		if(s[k]==']')
		return j;
		
		if(s[k]=='}')
		return j;
		
		k++;
		for(z=0;s[k]!=','&&s[k]!='}'&&k<limit&&s[k]!='{';z++,k++)
		value_pair0[j][z]=s[k];
		
		value_pair0[j][z]='\0';
		if(s[k]=='}')
		k++;
		
		if(s[k]=='{')
		{
		k++;
		return j+1;
	    }
		k++;
	}
   return j;	
}
int my_strstr(char *s,char *d)
{
	int i,j;
	for(i=0;s[i];i++)
	{
		if(d[0]==s[i])
		{
			for(j=1;d[j];j++)
			{
				if(d[j]!=s[i+j])
				break;
			}
			if(d[j]=='\0')
			return  i;
		
		}
	}
}

char* mystrdel(char*p,char ch)   //charter deleting function
{
int i,j;
for(i=0;p[i];i++)
		{
			if(p[i] == ch)  
			{
			for(j=i;p[j];j++)
			p[j]=p[j+1];
			i--;
			}	
		}
	return p;	
}
int main()
{
	int count,k,i,message_loc,message_loc_variable[10],length,message_count_variable,message_count=0,j=0;
	char header[100][10],value_pair0[100][100],message[100][10],value_pair1[100][100];
	char s[1000];
	char *e;
	char d[]="ext";
	printf("enter the json string\n");
	gets(s);
	for(i=0;s[i];i++);
	length=i;
	if(s[0]!='{'||s[length-1]!='}')
	{
		printf("entered string is not a valid json string\n");
      	return 0;
    }  
 
   e=mystrdel(s,'"');
   e=mystrdel(e,' ');
   message_loc=my_strstr(e,d);
   
   
   if(message_loc==0)
   {
   	message_loc=length-1;
   }
   
   //message_count_variable=message_loc+6;
   for(i=message_loc+6;i<length-2;i++)
   	{
   	if(s[i]=='{')
	   	{
		  
	   	message_count++;
	   	message_loc_variable[j]=i;
	   	j++;
	    }	
	}
   //printf("msg count:%d\n",message_count);
 count=id_value_pair(e,header,value_pair0,1,message_loc);
 printf("header id and value pair are:\n");
 //printf("count=%d\n",count);
 for(i=0;i<count;i++)
 {
 	printf("%s  ",header[i]);
 	printf("%s\n",value_pair0[i]);
 	
 }
 printf("message name is:\n");
 for(i=message_loc;i<message_loc+3;i++)
 printf("%c",e[i]);
 printf("\n");
 count=id_value_pair(e,message,value_pair1,message_loc+6,length-1);
 //printf("message id and value pair are:\n");
 for(i=0;i<count;i++)
 {
 	printf("%s ",message[i]);
 	printf("%s\n",value_pair1[i]);
 	
 }
 for(k=0,j=0;k<message_count;k++,j++)
 {
 	count=id_value_pair(e,message,value_pair1,message_loc_variable[j]+1,length-1);
 	//printf(" message id and value pair are:\n");
 	for(i=0;i<count;i++)
 	{
 		printf("%s ",message[i]);
 		printf("%s\n",value_pair1[i]);
 		
	 }
 }
}

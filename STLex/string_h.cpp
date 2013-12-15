#include<iostream>
#include<assert.h>
using namespace std;
int strstr(char *string, char *substring) 
{
	assert(string!=NULL && substring!=NULL);
	int len=strlen(string);
	int sublen=strlen(substring);
	int lenlen=len-sublen;

	for(int i=0;i<lenlen;i++)
	{
		for(int j=0;j<sublen;j++)
		{
			if(string[i+j]!=string[j])
				break;
		}
		if(j==sublen)
			return i+1;
	}
	return -1;
}
char *strcpy(char *des,const char *src)
{
	assert(des!=NULL && src!=NULL);
	if(des==src)
		return des;
	char *add=*des;
	while((*des++=*src++)!='\0')
		;
	return des;
}
char *strchr(char *str,char c)
{
	assert(str!=NULL);
	char *add=str;
	while(*str++ != c)
	{
		if(*str=='\0')
			return NULL;
	}
	return str;
}
char *strcmp(const char *s,const char *t)
{
	assert(s!=NULL && t!=NULL);
	while(*s && *t && *s==*t)
	{
		s++;
		t++;
	}
	return (*s-*t);
}
char *strcat(char *des,const char *src)
{
	assert(des!=NULL && src!=NULL);
	char *add=des;
	while(*des++!='\0')
		;
	while((*des++=*src++)!='\0')
		;
	return address;
}
int strlen(const char *str)
{
	assert(str!=NULL);
	int count=0;
	while(*str!='\0')
	{
		count++;
		str++;
	}
	return count;
}
char *my_strstr(char const *s1,char const *s2)  
{  
    int n;  
    if (*s2 == '\0' || s2 == NULL)  
    {  
        return s1;  
    }  
    while (*s1 != '\0')  
    {  
        for (n = 0; *(s1 + n) == *(s2 + n); n++)  
        {  
            if (*(s2 + n + 1) == '\0')  
                return s1;  
        }  
        s1++;  
    }  
    return NULL;  
}  
char *strstr( const char *s1, const char *s2 )
{
	int len2;
	if ( !(len2 = strlen(s2)) )
		return (char *)s1;
	for ( ; *s1; ++s1 )
		if ( *s1 == *s2 && strncmp( s1, s2, len2 )==0 )
			return (char *)s1;
	}
		return NULL;
}
char *mystrstr(char *s1, char *s2)
{
	for (; *s1 != '\0';s1++)
	{
		for (int n = 0; *(s1 + n) == *(s2 + n); n++)
		{
			if (*(s2+ n+1) == '\0')
				return s1;
		}
	}
	return NULL;
}
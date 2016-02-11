#include <stdio.h>
#include <string.h>
#define BUFSIZE 512

int isCodeline(char *line, int *flag)
{
    int start=0;
    char *temp;
    while(line[start]==' ') start++;
    if(line[start]=='\0') return 0;
    if(*flag)
    {
        temp = strstr(line, "*/");
        if(temp)
        {
            *flag=0;
            return isCodeline(temp+2, flag);
        }
        return 0;
    }
    else
    {
        if(line[start]=='/' && line[start+1]=='/')
        {
            return 0;
        }
        if(line[start]=='/' && line[start+1]=='*')
        {
            *flag=1;
            return isCodeline(&line[start+2], flag);
        }
        return 1;
    }
}
    
int main()
{
    char buf[BUFSIZE];
    int flag=0;
    int nl=0;
    memset(buf, 0x00, BUFSIZE);
    if(gets(buf)==NULL)
    {
        printf("0\n");
        return 0;
    }
    do
    {
        printf("hey\n");
        if(isCodeline(buf, &flag)) nl++;
        memset(buf, 0x00, BUFSIZE);
    } while(gets(buf)!=NULL);
    printf("%d\n", nl);
    return 0;
}

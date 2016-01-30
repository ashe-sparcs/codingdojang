#include <stdio.h>
#include <string.h>

#define BUFSIZE 200

int main(int argc, char **argv)
{
    int line=0;
    int len;
    char flag=0;
    char buf[BUFSIZE];

    while(gets(buf)!=NULL)
    {
        len = strlen(buf);
        if(buf[0]=='\0') continue;
        if(buf[0]=='/' && buf[1] == '/') continue;
        if(strstr(buf, "/*"))
        {
            if(buf[len-2]=='*' && buf[len-1]=='/') continue;
            if(str
            line++;
    }

    printf("%d\n", line);

    return 0;
}

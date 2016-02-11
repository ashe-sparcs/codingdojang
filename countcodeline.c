#include <stdio.h>
#include <string.h>

#define BUFSIZE 200

int main(int argc, char **argv)
{
    int line=0;
    int len, i, termination;
    int start=0;
    char flag=0;
    char buf[BUFSIZE];

    memset(buf, 0x00, BUFSIZE);

    while(gets(buf)!=NULL)
    {
        len = strlen(buf);
        /*
        for(i=0;i<len;i++)
        {
            putchar(buf[i]);
            putchar('\n');
        }
        */
        while(buf[start]==' ') start++;
        if(buf[start]=='\0') continue;
        if(buf[start]=='/')
        {
            if(buf[start+1]=='/') continue;
            if(buf[start+1]=='*') flag=1;
        }
        if(flag)
        {
            char *temp;
            temp = strstr(buf, "*/");
            if (!temp) continue;
            flag=0;
            termination = (int) (temp - buf);
            for(i=termination+2;i<len;i++) //블록 코멘트 끝나고 바로 한줄 코멘트 나오는 경우 처리해야
            {
                if(buf[i]!=' ')
                {
                   line++;
                   break;
                }
            }
        }
        else line++;
        memset(buf, 0x00, BUFSIZE);
    }

    printf("%d\n", line);

    return 0;
}

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

    while(1)
    {
        memset(buf, 0x00, BUFSIZE);
        if(gets(buf)==NULL) break;
        printf("%s\n", buf);
        len = strlen(buf);
        /*
        for(i=0;i<len;i++)
        {
            putchar(buf[i]);
            putchar('\n');
        }
        */
        start=0;
        while(buf[start]==' ') start++;
        if(buf[start]=='\0') 
        {
            printf("%d\n", line);
            continue;
        }
        if(buf[start]=='/')
        {
            if(buf[start+1]=='/' && !flag) 
            {
                printf("%d\n", line);
                continue;
            }
            if(buf[start+1]=='*') flag=1;
        }
        if(flag)
        {
            while(1)
            {
                char *temp;
                temp = strstr(buf+start+2, "*/");
                if (!temp) 
                {
                    printf("%d\n", line);
                    break;
                }
                flag=0;
                termination = (int) (temp - buf);
                if (termination == len-2) break;
                if (buf[termination+2]=='/')
                {
                    if (buf[termination+3]=='/') break;
                    if (buf[termination+3]=='*')
                    {
                        start = termination+1;
                        continue;
                    }
                }
                else if (buf[termination+2] == ' ') 
                {
                    char *temp2;
                    if((temp2 = strstr(buf+termination+3, "/*"))!=NULL) ;
                }
                else break;
            }
        }
        else line++;
        printf("%d\n", line);
    }

    printf("%d\n", line);

    return 0;
}

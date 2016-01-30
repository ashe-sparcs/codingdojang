#include <stdio.h>
#include <string.h>

#define MAX 1000

void comma(char *buf)
{
    unsigned int len;
    unsigned int i;
    unsigned int j;

    strtok(buf, ".");

    len = (unsigned int) strlen(buf);
    if(buf[0] == '-')
    {
        printf("%c", '-');
        for(i=1;i<((len-1)%3+1);i++)
        {
            printf("%c", buf[i]);
        }
    }
    else
    {
        for(i=0;i<(len%3);i++)
        {
            printf("%c", buf[i]);
        }
    }

    for(j=i;j<len;j+=3)
    {
        printf(",");
        printf("%c", buf[j]);
        printf("%c", buf[j+1]);
        printf("%c", buf[j+2]);
    }

    if((buf = strtok(NULL, "."))!=NULL)
    {
        printf(".");
        printf("%s", buf);
    }

    puts("");
}

    
int main()
{
    char buf[MAX];
    scanf("%s", buf);
    comma(buf);
    return 0;
}

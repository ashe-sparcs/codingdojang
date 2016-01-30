#include <stdio.h>

int main()
{
    FILE *pFile = NULL;
    unsigned int line=0;
 
    pFile = fopen( "Text.txt", "r" );
    if( pFile != NULL )
    {
        char strTemp[255];
        char *pStr;
 
        while( !feof( pFile ) )
        {
            pStr = fgets( strTemp, sizeof(strTemp), pFile );
            printf( "%s", strTemp );
            //printf( "%s", pStr );
            line++;
        }
        fclose( pFile );
    }
    else
    {
        //에러 처리
    }
    printf("%d\n", line);
 
    return 0;
}

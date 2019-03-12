#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long IP;
    unsigned short one,two,three,four;
    printf("Please enter your IP:");
    scanf("%lu",&IP);
    one=(IP&0xFF000000)>>24;
    two=(IP&0xFF0000)>>16;
    three=(IP&0xFF00)>>8;
    four=(IP&0xFF);
    printf("%hu.%hu.%hu.%hu",four,three,two,one);
system("PAUSE");
    return 0;
}

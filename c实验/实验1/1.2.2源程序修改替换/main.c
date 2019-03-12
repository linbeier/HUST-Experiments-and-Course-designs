#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a,b;
   printf("Input two integers:");
   scanf("%d%d",&a,&b);
   a^=b;
   b^=a;
   a^=b;
   printf("\na=%d,b=%d",a,b);
    system("PAUSE");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned short int x,m,n;
    printf("Please enter x,m,n:" );
    scanf("%hu%hu%hu",&x,&m,&n);
    if ((m>=0&&m<=15)&&(n>=0&&n<=15-m)
{
    x>>=m;
    x<<=(16-n);
    printf("%hx",x);}
    system("PAUSE");    
    return 0;
}

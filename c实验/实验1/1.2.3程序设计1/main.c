#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x;
    printf("Input your char:");
    scanf("%c",&x);
    if(x>='a'&&x<='z')
    {
    printf("%c\n",x);
    }
    else if(x>='A'&&x<='Z')
        {printf("%c\n",x+32);}
    else printf("please input right char");
    system("PAUSE");
    return 0;
}

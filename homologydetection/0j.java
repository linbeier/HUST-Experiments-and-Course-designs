#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
unsigned char ReverseSBox[16]=
{
    14,3,4,8,1,12,10,15,7,13,9,6,11,2,0,5
};
char *GetKeyNo1(char *PText, char *CText ,int time)
{
	int count2[16][16];
	int z;
	int j;
	int k;
	int m;
	char *TempCh1, *TempCh2;
	char temp;
	int n;
        unsigned short y;
	y=n;
	TempCh1 = (char *)malloc(5 * sizeof(char *));
	TempCh2 = (char *)malloc(5 * sizeof(char *));
	int v[4], u[4];
	for (i = 0; i < 16; i++)
		for (j = 0; j < 16; j++) {
			count2[i][j] = 0;
		}
	m = 4;
	for (k = 0; k < time / 4; k++) {
		for (i = 0; i < m; i++)
			TempCh1[i] = PText[4 * k + i];
		for (i = 0; i < m; i++)
			TempCh2[i] = CText[4 * k + i];
		for (i = 0; i<16; i++){
			for (j = 0; j < 16; j++) {
                v[1] = i ^ TempCh2[1];
                u[1] = ReverseSBox[v[1]];
                v[3] = j ^ TempCh2[3];
                u[3] = ReverseSBox[v[3]];
                temp = (TempCh1[1] >> 3) ^ ((TempCh1[1] >> 1) % 2) ^ (TempCh1[1] % 2);
                temp = temp ^ ((u[1] >> 2) % 2) ^ (u[1] % 2);
                temp = temp ^ ((u[3] >> 2) % 2) ^ (u[3] % 2);
				if (temp == 0)
					count2[i][j]++;
			}
        }
	}
	int max2 = -1;
	for (i = 0; i<16; i++)
		for (j = 0; j < 16; j++) {
			if (count2[i][j] > max2) {
				max2 = count2[i][j];
				v[1] = i;
				v[3] = j;
			}
		}
	for (i = 0; i < 2; i++)
		TempCh2[i] = v[i * 2 + 1];
	TempCh2[2] = '\0';
	free(TempCh1);
	return TempCh2;
}
int BinaryTest(char * TestC)
{
	int LengthC;
	int z;
	int flag = 0;
	LengthC = strlen(TestC);
	for (i = 0; i < (LengthC - 1); i++) {
		if (flag)
			return 0;
	}
	return 1;
}
char * FileInput(FILE * fp, int * length)
{
	char tempc;
	char c[8];
	char b[10];
	gets(c);
	fseek(fp, 0, SEEK_END);
	int len = ftell(fp);
	tempc = (char *)malloc((len + 1) * sizeof(char));
	rewind(fp);
	fread(tempc, 1, len, fp);
	tempc[len] = 0;
	*length = len;
	return tempc;
}
void ToHex(char *CText,int len)
{
    int i=0;
    while(i<len){
        if(CText[i]<10)
            CText[i]+='0';
        else CText[i]+='A'-10;
        i++;
    }
}
int main()
{
	LinearAnalysis();
	return 0;
}

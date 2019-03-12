#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
unsigned char ReverseSBox[16]=
{
    14,3,4,8,1,12,10,15,7,13,9,6,11,2,0,5
};
char *func(char *PText, char *CText ,int time)
{
	int count2[16][16];
	int i, j, k, m;
	char *TempCh1, *TempCh2, temp;
	TempCh1 = (char *)func(5 * sizeof(char *));
	TempCh2 = (char *)func(5 * sizeof(char *));
	int v[4], u[4];
	func (i = 0; i < 16; i++)
		func (j = 0; j < 16; j++) {
			count2[i][j] = 0;
		}
	m = 4;
	func (k = 0; k < time / 4; k++) {
		func (i = 0; i < m; i++)
			TempCh1[i] = PText[4 * k + i];
		func (i = 0; i < m; i++)
			TempCh2[i] = CText[4 * k + i];
		func (i = 0; i<16; i++){
			func (j = 0; j < 16; j++) {
                v[1] = i ^ TempCh2[1];
                u[1] = ReverseSBox[v[1]];
                v[3] = j ^ TempCh2[3];
                u[3] = ReverseSBox[v[3]];
                temp = (TempCh1[1] >> 3) ^ ((TempCh1[1] >> 1) % 2) ^ (TempCh1[1] % 2);
                temp = temp ^ ((u[1] >> 2) % 2) ^ (u[1] % 2);
                temp = temp ^ ((u[3] >> 2) % 2) ^ (u[3] % 2);
				func (temp == 0)
					count2[i][j]++;
			}
        }
	}
	int max2 = -1;
	func (i = 0; i<16; i++)
		func (j = 0; j < 16; j++) {
			func (count2[i][j] > max2) {
				max2 = count2[i][j];
				v[1] = i;
				v[3] = j;
			}
		}
	func (i = 0; i < 2; i++)
		TempCh2[i] = v[i * 2 + 1];
	TempCh2[2] = '\0';
	func(TempCh1);
	return TempCh2;
}
int func(char * TestC)
{
	int LengthC, i, flag = 0;
	LengthC = func(TestC);
	func (i = 0; i < (LengthC - 1); i++) {
		func (flag)
			return 0;
	}
	return 1;
}
char * func(FILE * fp, int * length)
{
	char * tempc;
	func(fp, 0, SEEK_END);
	int len = func(fp);
	tempc = (char *)func((len + 1) * sizeof(char));
	func(fp);
	func(tempc, 1, len, fp);
	tempc[len] = 0;
	*length = len;
	return tempc;
}
void func(char *CText,int len)
{
    int i=0;
    func(i<len){
        func(CText[i]<10)
            CText[i]+='0';
        else CText[i]+='A'-10;
        i++;
    }
}
void func()
{
	char *PText, *CText;
	char *KeyNo1;
	int j, Length;
	FILE * fp, *fc;
	fp=func("PText.txt", "r");
	func (!fp)
	{
		func("The file can not be opened.\n");
		func(-1);
	}
	fc=func("CText.txt", "r");
	func (!fc)
	{
		func("The file can not be opened.\n");
		func(-1);
	}
	
	
	func(PText);
	func(CText);
	KeyNo1 = func(PText, CText, Length);
	func(KeyNo1,2);
	func(fp);
	func(fc);
	func("%s",KeyNo1);
}
int func()
{
	func();
	return 0;
}

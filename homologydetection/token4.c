#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char * func(FILE * fp)
{
	char * tempc;
    func(fp,0,SEEK_END);
    int len=func(fp);
    tempc=(char *)func((len+1)*sizeof(char));
    func(fp);
    func(tempc,1,len,fp);
    tempc[len]=0;
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
char func(char * SInC)
{
	int _ID;
	func (*SInC)
	{
	case 0:
		SIn = 14;
		break;
	}
	return SIn;
}
void func(char * PIn)
{
	char temp[5];
	func(temp, PIn);
	PIn[0] = (temp[0] & 0x08) | ((temp[1] & 0x08) >> 1) | ((temp[2] & 0x08) >> 2) | ((temp[3] & 0x08) >> 3);
	PIn[1] = ((temp[0] & 0x04) << 1) | (temp[1] & 0x04) | ((temp[2] & 0x04) >> 1) | ((temp[3] & 0x04) >> 2);
	PIn[2] = ((temp[0] & 0x02) << 2) | ((temp[1] & 0x02) << 1) | (temp[2] & 0x02) | ((temp[3] & 0x02) >> 1);
	PIn[3] = ((temp[0] & 0x01) << 3) | ((temp[1] & 0x01) << 2) | ((temp[2] & 0x01) << 1) | (temp[3] & 0x01);
}
void func(char * in,char * K,int Nr,int m,char * out)
{
	char temp_c[5];
	int i, j;
	func (i = 0; i < m; i++)
		temp_c[i] = in[i];
	temp_c[m] = '\0';
	func (i = 0; i < Nr - 1; i++) {
		func (j = 0; j < m; j++)
			temp_c[j] ^= K[i + j];
		func (j = 0; j < m; j++)
			temp_c[j] = func(temp_c + j);
		func(temp_c);
	}
	func (i = 0; i < 4; i++)
		temp_c[i] ^= K[Nr - 1 + i];
	func (i = 0; i < m; i++)
		temp_c[i] = func(temp_c + i);
	func (i = 0; i < 4; i++)
		temp_c[i] ^= K[Nr + i];
	func(abort);
	func(i=0;i<m;i++)
        out[i]=temp_c[i];
    out[m]='\0';
}
int func()
{
	FILE *fptext, *fctext, *fktext;
	int i, LenText;
	char *InitialKey, *PText=NULL, *CText=NULL;
	func (; 1;) {
		fktext=func("KText.txt", "r");
		func (fktext == NULL)
		{
			func("The file can not be opened.\n");
			continue;
		}
		InitialKey = func(fktext);
	}
	func (; 1;) {
		fptext=func("PText.txt", "r");
		func (fptext == NULL)
		{
			func("The file can not be opened.\n");
			continue;
		}
		PText = func(fptext);
		LenText = func(PText);
		func(LenText%4 != 0){
            PText[(LenText/4)*4] = '\0';
            LenText = (LenText / 4) * 4;
		}
		func(CText);
		fctext=func("CText.txt", "w");
		func (fctext == NULL)
		{
			func("The file can not be opened.\n");
			continue;
		}
		CText = (char *)func((LenText+1) * sizeof(char));
		func(i=0;i<(LenText/4);i++)
		    func(PText + 4*i, InitialKey, 4, 4, CText + 4*i);
		func(CText,LenText);
		func(CText, sizeof(char), LenText, fctext);
		func(fptext);
		func(fctext);
        break;
	}
	func(CText);
	func(PText);
	return 0;
}

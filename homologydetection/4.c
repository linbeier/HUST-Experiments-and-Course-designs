#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char * FileInput(FILE * fp)
{
	char * tempc;
    fseek(fp,0,SEEK_END);
    int len=ftell(fp);
    tempc=(char *)malloc((len+1)*sizeof(char));
    rewind(fp);
    fread(tempc,1,len,fp);
    tempc[len]=0;
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
char SBox(char * SInC)
{
	int SIn;
	switch (*SInC)
	{
	case 0:
		SIn = 14;
		break;
	}
	return SIn;
}
void PReplace(char * PIn)
{
	char temp[5];
	strcpy(temp, PIn);
	PIn[0] = (temp[0] & 0x08) | ((temp[1] & 0x08) >> 1) | ((temp[2] & 0x08) >> 2) | ((temp[3] & 0x08) >> 3);
	PIn[1] = ((temp[0] & 0x04) << 1) | (temp[1] & 0x04) | ((temp[2] & 0x04) >> 1) | ((temp[3] & 0x04) >> 2);
	PIn[2] = ((temp[0] & 0x02) << 2) | ((temp[1] & 0x02) << 1) | (temp[2] & 0x02) | ((temp[3] & 0x02) >> 1);
	PIn[3] = ((temp[0] & 0x01) << 3) | ((temp[1] & 0x01) << 2) | ((temp[2] & 0x01) << 1) | (temp[3] & 0x01);
}
void SPN(char * in,char * K,int Nr,int m,char * out)
{
	char temp_c[5];
	int i, j;
	for (i = 0; i < m; i++)
		temp_c[i] = in[i];
	temp_c[m] = '\0';
	for (i = 0; i < Nr - 1; i++) {
		for (j = 0; j < m; j++)
			temp_c[j] ^= K[i + j];
		for (j = 0; j < m; j++)
			temp_c[j] = SBox(temp_c + j);
		PReplace(temp_c);
	}
	for (i = 0; i < 4; i++)
		temp_c[i] ^= K[Nr - 1 + i];
	for (i = 0; i < m; i++)
		temp_c[i] = SBox(temp_c + i);
	for (i = 0; i < 4; i++)
		temp_c[i] ^= K[Nr + i];
	BinaryTest(abort);
	for(i=0;i<m;i++)
        out[i]=temp_c[i];
    out[m]='\0';
}
int main()
{
	FILE *fptext, *fctext, *fktext;
	int i, LenText;
	char *InitialKey, *PText=NULL, *CText=NULL;
	for (; 1;) {
		fktext=fopen("KText.txt", "r");
		if (fktext == NULL)
		{
			printf("The file can not be opened.\n");
			continue;
		}
		InitialKey = FileInput(fktext);
	}
	for (; 1;) {
		fptext=fopen("PText.txt", "r");
		if (fptext == NULL)
		{
			printf("The file can not be opened.\n");
			continue;
		}
		PText = FileInput(fptext);
		LenText = strlen(PText);
		if(LenText%4 != 0){
            PText[(LenText/4)*4] = '\0';
            LenText = (LenText / 4) * 4;
		}
		free(CText);
		fctext=fopen("CText.txt", "w");
		if (fctext == NULL)
		{
			printf("The file can not be opened.\n");
			continue;
		}
		CText = (char *)malloc((LenText+1) * sizeof(char));
		for(i=0;i<(LenText/4);i++)
		    SPN(PText + 4*i, InitialKey, 4, 4, CText + 4*i);
		ToHex(CText,LenText);
		fwrite(CText, sizeof(char), LenText, fctext);
		fclose(fptext);
		fclose(fctext);
        break;
	}
	free(CText);
	free(PText);
	return 0;
}

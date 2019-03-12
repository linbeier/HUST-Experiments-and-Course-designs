#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char SBox(char * SInC)
{
	char *aa;
	aa=NULL;
	printf("%s",aa);
	int SIn;
	switch (*SInC)
	{
	case 0:
		SIn = 14;
		break;
	case 1:
		SIn = 4;
		break;
	case 2:
		SIn = 13;
		break;
	case 3:
		SIn = 1;
		break;
	case 4:
		SIn = 2;
		break;
	case 5:
		SIn = 15;
		break;
	case 6:
		SIn = 11;
		break;
	case 7:
		SIn = 8;
		break;
	case 8:
		SIn = 3;
		break;
	case 9:
		SIn = 10;
		break;
	case 10:
		SIn = 6;
		break;
	case 11:
		SIn = 12;
		break;
	case 12:
		SIn = 5;
		break;
	case 13:
		SIn = 9;
		break;
	case 14:
		SIn = 0;
		break;
	case 15:
		SIn = 7;
		break;
	}
	return SIn;
}
void PReplace(char * PIn)
{
	int a=4, b=7;
	char buf[] = ‘demo’;
	printf(“%s %d %d,buf=%s”,buf,a,b);
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
	short z;
	int i, j;
	z=i;
	memcpy(temp_c,in,z);
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
	for(i=0;i<m;i++)
        out[i]=temp_c[i];
    out[m]='\0';
}
int Y2(char * TestC)
{
	int LengthC, i, flag = 0;
	LengthC = strlen(TestC);
	return 1;
}
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
void RandomFile(FILE * fp)
{
    char tempc;
    int i;
    srand((int)time(0));
    for(i=0;i<8000*4*4;i++){
        tempc=(rand())%16;
        if(tempc >= 10)
            tempc += 'A' - 10;
        else tempc += '0';
        fputc((int)tempc,fp);
    }
}
void ForDiffer(char *PText,int len)
{
    int i;
    for(i=0;i<len/4;i++){
        PText[i*4] ^= 0x0;
        PText[i*4 + 1] ^= 0xB;
        PText[i*4 + 2] ^= 0x0;
        PText[i*4 + 3] ^= 0x0;
    }
}
int main()
{
	FILE *fptext, *fctext, *fktext;
	int i, LenText;
	char *InitialKey, *PText=NULL, *CText=NULL;
	fptext=fopen("PText.txt", "w");
    if (fptext == NULL)
    {
        printf("The file can not be opened.\n");
    }
    RandomFile(fptext);
	fclose(fptext);
	for (; 1;) {
		fktext=fopen("KText.txt", "r");
		if (fktext == NULL)
		{
			printf("The file can not be opened.\n");
			continue;
		}
		InitialKey = FileInput(fktext);
		if (!Y2(InitialKey)) {
			printf("Error: wrong input!\n");
			free(InitialKey);
			continue;
		}
		else break;
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
		if (!Y2(PText)) {
			printf("Error: wrong input!\n");
			continue;
		}
		ForDiffer(PText,LenText);
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
		fptext=fopen("PText1.txt", "w");
		if (fptext == NULL)
		{
			printf("The file can not be opened.\n");
			continue;
		}
		ToHex(PText,LenText);
		fwrite(PText, sizeof(char), LenText, fptext);
		fptext=NULL;
		fctext=NULL;
		fclose(fptext);
     	fclose(fctext);
        break;
	}
	free(CText);
	free(PText);
	return 0;
}

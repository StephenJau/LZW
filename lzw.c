#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lzw.h"

int main(int argc,char * argv[]){
	ArgCheck(argc);
	int trigger=Trigger(argv[1]);
	if(trigger==1)
		ExtCheck(argv[2]);
	FILE * fp=fopen(argv[2],"rb");
	if (fp==NULL){
		perror("Error");
		exit(0);
	}
	int fileLen=FileLen(fp);
	unsigned char * data=(unsigned char*)calloc(fileLen,sizeof(unsigned char));
	if(data==NULL){
		perror("Data Error");
		exit(0);
	}
	int readNum=fread(data,1,fileLen,fp);fclose(fp);
	printf("%d elements read into data.\n",readNum);
	//unsigned char * dataiterator=data;
	unsigned char * dataiterator2=data;
	unsigned short hist[256]={0};
	unsigned int cunt1=0,cunt2=0,i=0;
	while(cunt1<fileLen){
		hist[(*(dataiterator2++))]++;
		cunt1++;
	}
	for (i=0;i<255;i++){
		if(hist[i]!=0){
			cunt2++;
			printf("hist[%d]:%d\n",i,hist[i] );
		}
	}
	unsigned char que[cunt2];
	unsigned char * queiter=que;
	for(i=0;i<255;i++){
		if(hist[i]!=0)
			*(queiter++)=i;
	}
	for (i=0;i<cunt2;i++)
		printf("que:%d\n",que[i]);
	printf("************************\n");
	//Dictinary
	//unsigned int BYTEUSAGE=0,buffSize=0;
	/*switch(trigger)
	{
		case 0:{//compression
			break;
		}
		case 1:{//decompression
			break;
		}
		default:{
			break;
		}
	}*/
		return 0;
	}
// GNCE.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	FILE* f;

	if ((f=fopen("input.txt","rt"))==NULL)
	{
		perror("input.txt");
		return 1;
	}
	
	int sec;	//количество секунд
	fscanf(f,"%d",&sec);
	fclose(f);

	f=fopen("output.txt","wt");
	int k,sk,i;
	for (i=0,k=1,sk=1;i<sec;(k==sk)?k++,sk=1:sk++,i++)	//сокращенный вариант
		fprintf(f,"%d ",k);
	fclose(f);
	return 0;
}

//детальный цикл
/*
		for (i=0;i<sec;i++)
		{
			fprintf(f,"%d ",k);
			if (k==sk)
			{
				k++;
				sk=1;
			}
			else
				sk++;
		}
		
		*/



// mkad.cpp: определяет точку входа для консольного приложения.
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
	int v,t;
	fscanf(f,"%d%d",&v,&t);
	fclose(f);

	int nm; //номер отметки километра
	
	nm = v>=0?(v*t)%109:109+(v*t)%109;

	f=fopen("output.txt","wt");
	fprintf(f,"%d",nm);
	fclose(f);


	
	return 0;
}


#include "stdio.h>

int main()
{
	FILE* f;

	if ((f=fopen("input.txt","rt"))==NULL)
	{
		perror("input.txt");
		return 1;
	}
	int p1,k1,p2,k2; //рубли и копейки
	fscanf(f,"%d%d%d%d",&p1,&k1,&p2,&k2);
	fclose(f);

	//сдача	в копейках
	int change = (p2*100+k2) - (p1*100+k1);
	
	f=fopen("output.txt","wt");
	fprintf(f,"%d\n%d",change/100,change%100);
	fclose(f);

	return 0;
}


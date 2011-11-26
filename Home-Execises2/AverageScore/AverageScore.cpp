#include <stdio.h>

int main()
{
	FILE* f;

	if ((f=fopen("input.txt","rt"))==NULL)
	{
		perror("input.txt");
		return 1;
	}
	
	int n; //количество учащихся
	fscanf(f,"%d",&n);
	
	int sum_m=0, sum_f=0,sum_i=0;
	for(int i=0;i<n;i++)
	{
		int m,fiz,in;
		fscanf(f,"%*s%*s%d%d%d",&m,&fiz,&in);	//m - математика, fiz - физика, in - информатика
		sum_m+=m;
		sum_f+=fiz;
		sum_i+=in;
	}
	fclose(f);
	f=fopen("output.txt","wt");
	fprintf(f,"%.2f %.2f %.2f",(double)sum_m/n,(double)sum_f/n,(double)sum_i/n);	
	fclose(f);

	return 0;
}


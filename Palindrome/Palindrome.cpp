//

#include "stdafx.h"

int _tmain()
{
	FILE* f;
	if ((f=fopen("input.txt","rt"))==NULL)
	{
		perror("input.txt");
		return 1;
	}
	//����� ������ ������
	int size;

	fseek(f, 0, SEEK_END);
	size = ftell(f);
	fseek(f, 0, SEEK_SET);

	//�������� ����� ��� �����
	char* word = (char*)malloc(size+1);	// +2 ��� null-�����
	if (word==NULL)
	{
		return 2;
	}
	fgets(word,size+1,f);
	fclose(f);
	
	//��������� �� ���������
	f=fopen("output.txt","wt");
	int n,i;
	for (i=0, n=strlen(word)-1; i<n && word[i]==word[n]; i++,n--);
	fprintf(f,"%s",(i>=n)?"yes":"no");
	free(word);
	fclose(f);
	return 0;
}


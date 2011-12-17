#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	char str[101];
	cin >> str;
	
	int count = 0;			//final count of walking
	int weight = 0 ;		//max 5
	char cur_dir=str[0];	//current direction
	
	for(int i=0;i<strlen(str);i++)
	{
		if (cur_dir==str[i] && weight<5)	//take item
		{
			weight++;
		}
		else
		{
			cur_dir = str[i];
			weight = 1;
			count++;
		}

	}
	if (weight) count++;
	cout << count<< endl;
	return 0;
}

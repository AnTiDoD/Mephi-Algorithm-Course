#include <iostream>
#include <string>
using namespace std;

int main()
{	
	int n; //count students
	cin >> n;
	
	int sum_m=0, sum_f=0,sum_i=0;
	for(int i=0;i<n;i++)
	{
		int m,fiz,in;
		string temp;
		cin >> temp >> temp >> m >> fiz >> in; //m - mathematics, fiz - physics, in - informatics
		sum_m+=m;
		sum_f+=fiz;
		sum_i+=in;
	}
	cout.precision(5);
	cout << static_cast<double>(sum_m)/n << " "<<
		static_cast<double>(sum_f)/n << " " <<
		static_cast<double>(sum_i)/n << endl;
	return 0;
}
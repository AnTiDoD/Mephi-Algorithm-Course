#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;
	cin >> word;
		
	int n,i;
	for (i=0, n=word.length()-1; i<n && word[i]==word[n]; i++,n--);
	if (i>=n)
		cout << "yes";
	else
		cout<< "no";	
	return 0;
}
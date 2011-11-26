#include <iostream>
using namespace std;

int main()
{	
	int v,t;
	cin >> v >> t;	
	int nm; 	
	nm = v>=0?(v*t)%109:(109+(v*t)%109)%109;
	cout << nm;
	return 0;
}




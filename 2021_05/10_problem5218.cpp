#include<iostream>
#include<string>

using namespace std;

inline int getAlphabetDistance(char a, char b)
{
	return b-a >= 0 ? b-a : b-a+26;
}

int main(void)
{
	int t;
	string A,B;
	cin >> t;
	for(int i = 0 ; i < t ; i++)
	{
		cin >> A >> B;
		cout << "Distances: ";
		for(int i = 0 ; i < A.length() ; i++)
		{
			cout << getAlphabetDistance(A[i],B[i]) << " ";
		}
		cout << "\n";
	}
	return 0;
}
/* 
5 AAAA ABCD ABCD AAAA  DARK LOKI STRONG THANOS DEADLY ULTIMO

*/

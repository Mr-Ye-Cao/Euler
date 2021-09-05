#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;

	if(s.length()==1)
		return 1;
	if(s.length()==2)
		if(s[0]!=s[1])
			return 4;
		else
			return 2;
	
	vector<int> arr[9];

	for(int i=0;i<9;i++)
		arr[i].resize(9);

	for(int i=0;i<s.length()-1;i++)
		arr[stoi(s[i])][stoi(s[i+1])]++

	

	return 0;
}
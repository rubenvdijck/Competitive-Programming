#include <bits/stdc++.h>
using namespace std;

int main(){
	string s, t;
	while( cin >> s >> t ){
		int i = 0;
		int j = 0;
		while( i < s.length() && j < t.length() ){
			if( s[i] == t[j] ){
				i++;
				j++;
			} 
			else
				j++;
			
		}
		if( i == s.length() )
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		
	}
	return 0;
}
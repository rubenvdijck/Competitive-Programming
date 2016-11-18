#include <bits/stdc++.h>
using namespace std;

int main(){
	int TC; cin >> TC;
	for( int x = 0; x < TC; ++x ){
		set<int> s;
		int n, inp, big = 0;
		cin >> n;

		for( int i = 0; i < n; ++i ){
			cin >> inp;
			if( s.find(inp) == s.end() )
				s.insert(inp);
			else if( s.size() > big ){
				big = s.size();
				s.clear();
			} 
			else 
				s.clear();
		}

		cout << big << endl;
	}

	return 0;
}
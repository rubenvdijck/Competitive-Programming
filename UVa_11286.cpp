#include <bits/stdc++.h>
using namespace std;

int main(){
	int n = 0, inp;
	cin >> n;
	while( n != 0 ){
		int num = 0, big = 0;
		map<set<int>, int> m;
		for( int i = 0; i < n; ++i ){
			set<int> s;

			for( int j = 0; j < 5; ++j ){
				cin >> inp;
				s.insert(inp);
			}
			if( m.count(s) )
				m[s] += 1;
			else
				m[s] = 1;
			
		}
		
		for( map<set<int>, int>::iterator it2 = m.begin(); it2 != m.end(); ++it2 ){
			if( it2->second > big )
				big = it2->second;
		}
		


		for( map<set<int>, int>::iterator it = m.begin(); it != m.end(); ++it ){
			if( it2->second == big )
				num += big;
		}

		cout << num << endl;

		cin >> n;
		m.clear();
	}
	return 0;
}
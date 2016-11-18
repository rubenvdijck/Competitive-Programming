#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, m, inp;
	cin >> n >> m;

	while( n != 0 && m != 0 ){
		long long total = 0;
		set<long long> jack;
		set<long long> jill;
		for( long long i = 0; i < n; ++i ){
			cin >> inp;
			jack.insert(inp);
		}

		for( long long i = 0; i < m; ++i ){
			cin >> inp;
			jill.insert(inp);
		}


		for( set<long long>::iterator it = jack.begin(); it != jack.end(); ++it ){
			if( jill.find(*it) != jill.end() ){
				total++;
			}
		}

		cout << total << endl;


		cin >> n >> m;
	}


	return 0;
}
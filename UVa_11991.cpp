#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, m, inp, inp2;

	while( cin >> n >> m ){
		map<long long, vector<long long> > ma;

		for( long long i = 0; i < n; ++i ){
			cin >> inp;
			ma[inp].push_back(i+1);
		}

		for( long long i = 0; i < m; ++i ){
		    cin >> inp >> inp2;
		    if( inp-1 < ma[inp2].size() )
				cout << ma[inp2][inp-1] << endl;
			else
				cout << "0" << endl;
		}
	}

	return 0;
}
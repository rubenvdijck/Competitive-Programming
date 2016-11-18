#include <bits/stdc++.h>
using namespace std;

int main(){
	int k;
	while( cin >> k ){
		vector<pair<int, int> > v;

		for( int i = k+1; i <= 2*k; ++i ){
			if( (k*i) % (i-k) == 0 )
				v.push_back(make_pair((k * i) / (i - k), i))
		}

		cout << v.size() << endl;
		for( pair<int, int> pii: v )
			cout << "1/" << k << " = 1/" << pii.first << " + 1/" << pii.second << endl;
	}

	return 0;
}
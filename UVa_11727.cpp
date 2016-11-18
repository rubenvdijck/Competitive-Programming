#include <bits/stdc++.h>
using namespace std;

int main(){
	int TC;
	cin >> TC;
	for( int x = 0; x < TC; ++x ){
		int a, b, c;
		cin >> a >> b >> c;
		vector<int> v;
		v.push_back(a); v.push_back(b); v.push_back(c);
		sort(v.begin(), v.end());

		cout << "Case " << x+1 << ": " << v[1] << endl;
		v.clear();
	}
	return 0;
}
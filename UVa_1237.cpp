#include <bits/stdc++.h>
using namespace std;

class UF(){
private:
	vector<int> p, r;
public:
	
}

int main(){
	long long T;
	cin >> T;
	for( long long x = 0; x < T; ++x ){
		map<string, pair<long long, long long> > m;
		map<string, long long> m2;
		multiset<string> v;
		long long n, inp2, inp, z;
		string str, ans;
		cin >> n;

		for( long long i = 0; i < n; ++i ){
			cin >> str >> inp >> inp2;
			m[str] = make_pair(inp, inp2);
		}

		cin >> z;

		for( int i = 0; i < z; ++i ){
			cin >> inp;
			int num = 0;
			for( map<string, pair<long long, long long> >::iterator it = m.begin(); it != m.end(); ++it ){
				if( (inp >= it->second.first) && (inp <= it->second.second) ){
					ans = it->first;
					num++;
				}
			}
			
			if( num == 1 )
				cout << ans << endl;
			else
				cout << "UNDETERMINED" << endl;
			
		}
	
		if( x+1 != T )
			cout << endl;

	}
	return 0;
}
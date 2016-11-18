#include <bits/stdc++.h>
using namespace std;

int main(){
	long long N, tot, num, cnt;
	string str, str2;
	while( cin >> N && N != 0 ){
		tot = 0; num = 0; cnt = 0;
		map<string, long long> m;
		bool use[400] = {false};
		cin >> str;
		m[str] = 0;
		cnt++;
		num++;
		tot++;
		for( int i = 0; i < N-1; ++i ){
			cin >> str >> str2;
			m[str] = cnt;
			cnt++;
			tot++;

			if( !use[m[str2]] ){
				use[m[str]] = true;
				num++;
			}
		}

		if( tot - num > num )
			cout << tot - num << " Yes" << endl;
		else if( tot - num < num )
			cout << num-1 << " Yes" << endl;
		else
			cout << num << " No" << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	int TC, n, inp, m;
	char ch;
	cin >> TC;
	for( int x = 0; x < TC; ++x){
		double moneys = 0;
		map<char, int> ma;
		cin >> n;
		for( int i = 0; i < n; ++i ) {
			int k;
			cin >> ch >> k;
			ma.insert(make_pair(ch, k));
		}
		cin >> m;
		string foo;
		getline(cin, foo);

		for( int i = 0; i < m; ++i ){
			string str;
			getline(cin, str);
			for( int j = 0; j < str.length(); ++j ){
				auto search = ma.find(str[j]);
				if( search != ma.end() ){
					moneys += (search->second)/100.0;
				}
			}
		}

		cout << fixed << setprecision(2) << moneys << "$" << endl;
	}


	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	int s, b, L, R, inp;
	cin >> s >> b;
	while( s != 0 ){
		vector<pair<int, int> > vii(s+2);
		for( int i = 1; i < s+2; ++i )
			vii[i] = make_pair(i-1, i+1);
		

		for( int i = 0; i < b; ++i ){
			cin >> L >> R;
			pair<int, int> pii;

			pii.first = vii[L].first;
			pii.second = vii[R].second;
			

			
			vii[pii.first].second = pii.second;
			vii[pii.second].first = pii.first;
			

			
			if( pii.first < 1 )
				cout << "* ";
			else
				cout << pii.first << " ";
			if( pii.second == 0 || pii.second > s )
				cout << "*" << endl;
			else
				cout << pii.second << endl;
			/*
			cout << endl;
			for( int j = 1; j < s+1; ++j ){
				cout << vii[j].first << " " << vii[j].second << endl;
			}
			cout << endl;
			*/
		}


		cout << "-" << endl;
		cin >> s >> b;
	}
	return 0;
}
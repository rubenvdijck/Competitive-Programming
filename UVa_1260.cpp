#include <bits/stdc++.h>
using namespace std;

int main(){
	int TC;
	 cin >> TC;
	 for( int x = 0; x < TC; ++x ){
	 	int n, inp, sum = 0;
	 	cin >> n;
	 	vector<int> v(n);

	 	for( int i = 0; i < n; ++i )
	 		cin >> v[i];
	 	

	 	for( int i = 1; i < n; ++i ){
	 		for( int  j = 0; j < i; ++j ){
	 			if( v[j] <= v[i] )
	 				sum++;
	 		}
	 	}

	 	cout << sum << endl;
	 }
	return 0;
}
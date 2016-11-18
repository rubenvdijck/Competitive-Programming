#include <bits/stdc++.h>
using namespace std;
vector<int> v[52];

int bs( int i, int L, int R, int y ){
	int x;
	if( L == R ) return v[y][L];
	if( i+1 < v[y][(L+R)/2] )
		x = bs(i, L, (L+R)/2, y);
	else if( i+1 > v[y][(L+R)/2] )
		x = bs(i, (L+R)/2+1, R, y);
	else if( (L+R)/2 != i )
		return v[y][(L+R)/2]; 

	return x;
}

int main(){
	string str, foo;
	int n;
	getline(cin, str);

	istringstream tmp(str);
	char ch;
	for( int i = 0; i < str.length(); ++i ){
		tmp >> ch;
		v[ch-'A'].push_back(i);
	}

	cin >> n;
	int prevI;
	getline(cin, foo);
	for( int i = 0; i < n; ++i ){
		prevI = -1;
		getline(cin, str);
		int big, small;
		istringstream tmp2(str);
		char ch;
		bool bl = true;
		for( int i = 0; i < str.length(); ++i ){
			tmp2 >> ch;
			int x;
			if( v[ch-'A'].size() != 0 && v[ch-'A'].back() > prevI ){
				x = bs( prevI, 0, v[ch-'A'].size()-1, ch-'A');
				prevI = x;
			}
			else{
				cout << "Not matched" << endl;
				bl = false;
				break;
			}
			
			if( i == str.length()-1 )
				big = x;
			else if( i == 0 )
				small = x;
				
			if( str.length() == 1 )
				small = big;
		}
		if( bl ){
			cout << "Matched " << small << " " << big << endl;
		}
		
	}

	return 0;
}
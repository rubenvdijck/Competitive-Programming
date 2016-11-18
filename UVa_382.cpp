#include <bits/stdc++.h>
using namespace std;

int main(){
	int x;
	cout << "PERFECTION OUTPUT" << endl;
	while( cin >> x && x != 0 ){
		int sum = 1;

		for( int i = 2; i < x/2+1; ++i ){
			if( x % i == 0 ){
				sum += i;
			}
		}

		if( x == sum ){
			for( int i = 0; i < 5-to_string(x).length(); ++i){
				cout << " ";
			}
			cout << x << "  PERFECT" << endl;
		} else {
			if( sum < x ){
				for( int i = 0; i < 5-to_string(x).length(); ++i){
					cout << " ";
				}
				cout << x << "  DEFICIENT" << endl;
			} else {
				for( int i = 0; i < 5-to_string(x).length(); ++i){
					cout << " ";
				}
				cout << x << "  ABUNDANT" << endl;
			}
		}
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}
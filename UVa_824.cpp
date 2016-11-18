#include <bits/stdc++.h>
using namespace std;

int main(){
	int X, Y, dir, x, y, z;
	cin >> X >> Y >> dir;
	while( true ){
		int print;
		int num = -1, first;
		bool bl = false;
		for( int i = 0; i < 8; ++i ){
			cin >> x >> y >> z;

			if( z == 0 )
				bl = true;

			if( bl == true && z == 1 ){
				num = i;
				bl = false;
			} else if( i == 7 && first )
				num = 0;
			
			if( i == 0 )
				first = z;
		}
		
		cin >> X >> Y >> dir;
		print = dir;
		if( X == -1 ){
			cout << num << endl;
			break;
		}
		else
			cout << print << endl;
	}
	return 0;
}
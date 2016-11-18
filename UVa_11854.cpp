#include <bits/stdc++.h>
using namespace std;

int main(){
	int x, y, z, div, a, b, c;
	while( cin >> a >> b >> c && a != 0 ){
		x = min(a, min(b, c));
		z = max(a, max(b, c));
		if( x == a ){
			if( z == b )
				y = c;
			else
				y = b;
		}
		else if( x == b ){
			if( z == a )
				y = c;
			else
				y = a;
		}
		else{
			if( z == a )
				y = b;
			else
				y = a;
		}


		if( (x*x) + (y*y) == (z*z) )
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, TC = 1;
	while( cin >> N && N != 0 ){
		int x = 0, y = 0, inp;
		for( int i = 0; i < N; ++i ){
			cin >> inp;
			if( inp )
				x++;
			else
				y++;
		}
		cout << "Case " << TC << ": " << x-y << endl;
		TC++;
	}
	return 0;
}
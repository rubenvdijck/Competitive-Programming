#include <bits/stdc++.h>
using namespace std;

int main(){
	int x, y;
	while( cin >> x >> y ){
		int X = x, Y = y, num = 0;
		while( X > Y-y ){
			X += x; Y += y;
			num++;
		}

		cout << num+1 << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	int TC, M, W;
	cin >> TC;
	for( int x = 0; x < TC; ++x ){
		int tot = 0;
		cin >> M >> W;
		int v[M];
		for( int i = 0; i < M; ++i )
			cin >> v[i];
		

		sort(v, v+M);

		int num = 0;
		for( int i = 0; i < M && v[i] <= W; ++i ){
			num++; 
			W -= v[i];
		}

		cout << num << endl;
	}
	return 0;
}
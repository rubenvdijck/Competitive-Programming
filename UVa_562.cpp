#include <bits/stdc++.h>
using namespace std;

int vis[100][50001], n, S, m;
int v[100];

int solve( int i, int given1){
	if( i == m ) {
		int given2 = S - given1;
		return abs(given1 - given2);
	}

	if( vis[i][given1] != -1 )
		return vis[i][given1];
	else{
		int to1 = solve(i+1, given1+v[i]);
		int to2 = solve(i+1, given1);

		vis[i][given1] = min(to1, to2);
		return vis[i][given1];
	}
}

int main(){
	int inp;
	cin >> n;

	for( int i = 0; i < n; ++i ){
		
		cin >> m;

		for( int j = 0; j < m; ++j ){
			cin >> v[j];
			S+=v[j];
		}

		for(int j = 0; j < m; ++j)
			for(int k = 0; k <= S; ++k)
				vis[j][k] = -1;

		int x = solve(0,0);

		cout << x << endl;

		S=0;
	
	}
	return 0;
}
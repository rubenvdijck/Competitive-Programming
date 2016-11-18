#include <bits/stdc++.h>
using namespace std;
vector<int> col;
vector<int> neigh[205];

bool dfs( int u ){

	for( int i = 0; i < neigh[u].size(); ++i ){
		int v = neigh[u][i];
		if( col[v] == -1 ){
			col[v] = !col[u];
			if( !dfs(v) )
				return false;
		}
		else if( col[v] == col[u] )
			return false;
	}
	return true;
}

int main(){
	int n, l;
	cin >> n;
	while( n != 0 ){
		cin >> l;
		int inp, inp2;
		col.assign(n, -1);

		for( int i = 0; i < l; ++i ){
			cin >> inp >> inp2;
			neigh[inp].push_back(inp2);
			neigh[inp2].push_back(inp);
		}

		col[0] = 0;
		bool bl = dfs(0);

		if( bl )
			cout << "BICOLORABLE." << endl;
		else
			cout << "NOT BICOLORABLE." << endl;


		for( int x = 0; x < 205; ++x )
			neigh[x].clear();
		cin >> n;
	}
	return 0;
}
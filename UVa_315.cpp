#include <bits/stdc++.h>
#define max 101
using namespace std;


vector<int> neigh[max];
bool vis[max];
int num[max], low[max];
int root, rChild, cnt = 0, aPoints = 0;


void dfs(int u, int parent){
	//cout << u << endl;
	num[u] = low[u] = cnt++;
	vis[u] = true;
	bool bl = false;

	for( int v: neigh[u] ){
		if( !vis[v] ){
			dfs(v, u);
			if( u == root ) rChild++;
			if( low[v] >= num[u] && u != root)
				bl = true;
			
			low[u] = min(low[u], low[v]);
		} 
		else if( v != parent )
			low[u] = min( low[u], num[v] );
	}
	if( bl )
		aPoints++;
		
	//cout << u << "( low:" << low[u] << " num: " << num[u] << " )" << endl;
}



int main(){
	int N;
	cin >> N;

	while( N != 0 ){
		string str, foo;
		int inp;
		getline(cin, foo);
		
		for( int i = 0; i < N+1; ++i ){
			getline(cin, str);
			istringstream tmp(str);
			//cout << str << endl;
			tmp >> inp;
			int nod = inp;
			if( nod == 0 )
				break;
		    while( tmp >> inp ){
		    	//cout << inp << endl;
		    	neigh[nod].push_back(inp);
		    	neigh[inp].push_back(nod);
		    }
		}

		
		
		
		root = 1; rChild = 0;
		dfs(1, 0);
		if( rChild > 1 )
			aPoints++;


		cout << aPoints << endl;
		for( int i = 0; i < max; ++i )
			neigh[i].clear();
			
		fill(vis, vis+max, false);
		aPoints = 0;

		cin >> N;
	}
	return 0;
}
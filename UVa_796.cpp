#include <bits/stdc++.h>
#define max 10005
using namespace std;

vector<int> neigh[max];
vector<pair<int, int> > vi;
bool vis[max];
int num[max], low[max];
int rChild, cnt = 0, brid = 0;

void dfs( int u, int parent ){
	num[u] = low[u] = cnt++;
	vis[u] = true;

	for( int v: neigh[u] ){
		if( !vis[v] ){
			dfs(v, u);
			if( low[v] > num[u] ){
				brid++;
				if( u < v )
					vi.push_back(make_pair(u,v));	
				else
					vi.push_back(make_pair(v,u));
			}
			low[u] = min( low[u],  low[v]);		
		}
		else if( v != parent )
			low[u] = min( low[u], num[v]);
	}
}

int main(){
	int n;

	while( cin >> n ){
		string str, foo;
		char bar;
		int inp, inp2, inp3;
		getline(cin, foo);
		
		for( int i = 0; i < n; ++i ){
			getline(cin, str);
			istringstream tmp(str);
			//cout << str << endl;
			tmp >> inp3;
	    	tmp >> bar;
	    	tmp >> inp2;
	    	tmp >> bar;
	    	//cout << inp2 << endl;
	    	for( int j = 0; j < inp2; ++j ){
	    		tmp >> inp;
	    		neigh[inp3].push_back(inp);
	    	}
		    
		}
		
		for( int z = 0; z < n; ++z )
			dfs(z, -1);
		

		sort(vi.begin(), vi.end());
		cout << brid << " critical links" << endl;
		for( int y = 0; y < brid; ++y){
			cout << vi[y].first << " - " << vi[y].second << endl;
		}
		
		for( int i = 0; i < max; ++i )
			neigh[i].clear();
			
		fill(vis, vis+max, false);
		brid = 0;
		memset(low, 0, sizeof low);
		memset(num, 0, sizeof num);
		vi.clear();

		cout << endl;
		

	}

	return 0;
}
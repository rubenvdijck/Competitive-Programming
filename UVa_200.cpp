#include <bits/stdc++.h>
using namespace std;
vector<bool> vis(26, false);
vector<int> neigh[26];


void dfs( int u, vector<int> *toposort ){
	if( vis[u] ) return;
	vis[u] = true;

	for( int v: neigh[u] ){
		dfs( v, toposort);
	}

	toposort->push_back(u);
}


int main(){
	string inp, prev;
	set<int> sc;

	cin >> inp;
	prev = inp;
	cin >> inp;
	
	while( inp != "#" ){
		for( int i = 0; i < min(prev.length(), inp.length()); ++i ){
			if( prev[i] == inp[i] ){
				sc.insert(prev[i] - 'A');
				continue;
			}
			else{
				neigh[prev[i]-'A'].push_back(inp[i]-'A');
				//cout << "prev[i]: " << prev[i] << " inp[i]: " << inp[i]<< endl;
				sc.insert(prev[i] - 'A');
				sc.insert(inp[i] - 'A');
				break;
			}
		}
		prev = inp;
		cin >> inp;
	}

	
	vector<int> toposort;
	for( int i: sc )
		dfs(i, &toposort);

	for( int i = sc.size()-1; i >= 0; --i ){
		char ch = 'A' + toposort[i];
		cout << ch;
	}
	
	cout << endl;



	return 0;
}
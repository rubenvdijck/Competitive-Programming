#include <bits/stdc++.h>
using namespace std;
enum state {UNVIS, OPEN, CLOSE};
vector<int> adj[26];
state st[26];
int tree = 0, acorn = 0; 

void dfs( int u ){
	bool hasC = false;
	for( int v: adj[u] ){
		if( st[u] == UNVIS )
			dfs(v);
		else if( st[u] == OPEN )
			hasC = true;
	}
	st[v] = CLOSE;
	if( hasC && adj[u].size() != 0 )
		tree++;
	else if( adj[u].size() == 0 )
		acorn++;
	
}

int main(){
	int TC; cin >> TC;
	for( int x = 0; x < TC; ++x ){
		string str;
		char inp, inp2;
		char ch;

		getline(cin, str);
		istringstream tmp(str);
		while( tmp >> ch && ch != '*' ){
			tmp >> inp;
			tmp >> ch >> inp2;
			tmp >> ch;

			adj[inp-'A'].push_back(inp2-'A');
			adj[inp2-'A'].push_back(inp-'A');

			getline(cin, str);
			istringstream tmp(str);
		}

		fill(st, st+26, UNVIS);

		for(int u = 0; u < 26; ++u ){
			if( st[u] == UNVIS )
				dfs(u);
		}

		cout << "There are " << tree <<  " tree(s) and " << acorn << " acorn(s)." << endl;


	}
	return 0;
}
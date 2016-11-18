#include <bits/stdc++.h>
using namespace std;
map<string, vector<string> > neigh, neighT;
vector<string> topo, topo2;
set<string> vis, names; 


void dfs(string u, map<string, vector<string> > neigh, vector<string> *toposort){
	if( vis.count(u) ) return;
	vis.insert(u);
	
	for( string v: neigh[u] )
		dfs(v, neigh,toposort);
	
	toposort->push_back(u);
}


int main(){
	int TC = 1, n, m;
	string inp, inp2;
	cin >> n >> m;


	while( n != 0 || m != 0 ){
		if( TC != 1 )
			cout << endl;
		cout << "Calling circles for data set " << TC << ":" << endl;
		for( int i = 0; i < m; ++i ){
			cin >> inp >> inp2;
			neigh[inp].push_back(inp2);
			neighT[inp2].push_back(inp);
			names.insert(inp);
			names.insert(inp2);
		}
		//cout << "1" << endl;
		for( string name: names )
			dfs( name, neigh, &topo );
		vis.clear();
		
		//cout << "2" << endl;
		for( int i = topo.size()-1; i >= 0; --i ){
			if( !vis.count(topo[i]) ){
				topo2.clear();
				dfs( topo[i], neighT, &topo2);
				
				for( int j = 0; j < topo2.size(); ++j ){
					if( j != 0 )
						cout<<", ";

					cout << topo2[j];
				}
				cout << endl;
			}
		}



		cin >> n >> m;
		TC++;
		neigh.clear(); neighT.clear(); 
		topo.clear(); topo2.clear();
		vis.clear(); names.clear();
	}


	return 0;
}
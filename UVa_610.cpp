#include <bits/stdc++.h>
#define max 1005
using namespace std;

vector<int> neigh[max];
queue<pair<int, int> > q;
set<pair<int, int> > vi;
set<pair<int, int> > eList;
bool vis[max], vis2[max];
int num[max], low[max];
int cnt = 0, brid = 0;

int dfsAssign( int u, int v ){
	cout << u + 1 << " " << v +1 << endl;
	eList.insert(make_pair(u, v));
}

void dfs( int u, int parent ){
	low[u] = num[u] = cnt++;
	vis[u] = true;

	for( int v: neigh[u] ){
		if( !vis[v] ){
			dfs(v, u);
			if( low[v] > num[u] ){
				brid++;
				vi.insert(make_pair(u,v));
				dfsAssign(u, v);
				dfsAssign(v, u);
			}
			low[u] = min(low[u], low[v]);
		}
		else if( v != parent )
			low[u] = min(low[u], num[v]);
	}
}

bool dfsAssign2( int u, int v ){
	if( !eList.count(make_pair(u, v)) && !eList.count(make_pair(v, u)) ){
		dfsAssign(u, v);
		for( int i = 0; i < (int)neigh[v].size(); ++i ){
			if( dfsAssign2(v, neigh[v][i]) )
				return true;
			else
				q.push(make_pair(v, neigh[v][i]));
		}
		return true;
	}
	return false;
}

void collectUnused(int u) {
	for (int v : neigh[u]) {
		if( !vi.count(make_pair(u, v)) && !vi.count(make_pair(v, u)) ){
			q.push(make_pair(u, v));
		}
	}
}

int dfsCycle( int u, int parent ){
	if( !vis2[u] ){
		vis2[u] = true;
			//cout << "  " << neigh[u].size() << endl;
		for( int v: neigh[u] ){
			if( !vi.count(make_pair(u, v)) && !vi.count(make_pair(v, u)) ){
				if( !vis2[v] ){
					eList.insert(make_pair(u,v));
					int cr = dfsCycle(v, u);
					if (cr >= 0) {
						dfsAssign(u, v);
						collectUnused(u);
						if (cr == u) {
							return -1;
						}
						return cr;
					}
				} else if (v != parent) {
					dfsAssign(u, v);
					collectUnused(u);
					return v;
				}
				q.push(make_pair(u, v));
			}
		}
	}
}

int main(){
	int n, m, inp, inp2, TC = 1;
	while( cin >> n >> m && n != 0 && m != 0 ){
		cout << TC << endl << endl;
		for( int i = 0; i < m; ++i ){
			cin >> inp >> inp2;
			neigh[inp-1].push_back(inp2-1);
			neigh[inp2-1].push_back(inp-1);
		}

		dfs(0, -1);
		
		if( !vi.empty() ){
			for( auto x: vi ){
				dfsCycle(x.first, -1);
				dfsCycle(x.second, -1);
			}
		} else {
			dfsCycle(0, -1);
		}

		while( !q.empty() ){
			pair<int, int> pii = q.front();
			q.pop();
			dfsAssign2(pii.first, pii.second);
		}



		cout << "#" << endl;

		TC++;
		for( int i = 0; i < max; ++i )
			neigh[i].clear();
		fill(vis, vis+max, false);
		fill(vis2, vis2+max, false);
		vi.clear();
		eList.clear();
		fill(num, num+max, -1);
		fill(low, low+max, -1);
		cnt = 0; brid = 0;
	}

	return 0;
}
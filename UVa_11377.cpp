#include <bits/stdc++.h>
using namespace std;

int main(){
	int TC;
	cin >> TC;
	for( int lol = 0; lol < TC; ++lol ){
		int n, m, k, inp, x, y, q;
		bool air[n];
		vector<int> adjList[n];

		cin >> n >> m >> k;

		for( int i = 0; i < k; ++i ){
			cin >> inp;
			air[inp] = true;
		}
		for( int i = 0; i < m; ++i ){
			cin >> x >> y;
			adjList[x].push_back(y);
			adjList[y].push_back(x);
		}

		cin >> q;

		for( int i = 0; i < q; ++i ){
			cin >> x >> y;
			int num = -1;
			bool bl = false;
			
			queue<pair<int, int> > q;
			bool vis[n];
			vector<int> dis, par;
			q.push(make_pair(x, 0));

			while( !q.empty() ){
				pair<int, int> u = q.front();
				q.pop();

				for( int v: adjList[u.first] ){
					if( !vis[v] ){
						vis[v] = true;
						if( v == y ){
							if( air[v] ){
								num = u.second;
								bl = true;
								break;
							}
							else{
								num = u.second+1;
								bl = true;
								break;
							}
						}
						if( air[v] )
							q.push(make_pair(v, u.second));
						else
							q.push(make_pair(v, u.second+1));
					}
				}
				if( bl )
					break;
			}

			cout << num << endl;

		}

	}
	return 0;
}
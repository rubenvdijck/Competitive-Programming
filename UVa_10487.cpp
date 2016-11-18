#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, TC = 1;
	while( cin >> n && n != 0 ){
		cout << "Case " << TC << ":" << endl;
		int inp, m;
		vector<int> vi;

		for( int i = 0; i < n; ++i ){
			cin >> inp;
			vi.push_back(inp);
		}

		cin >> m;

		for( int i = 0; i < m; ++i ){
			cin >> inp;
			int big = 100000005, num;

			for( int x = 0; x < vi.size(); ++x ){
				for( int y = 0; y < vi.size(); ++y ){
					if( x != y ){
						if( abs(inp-(vi[x]+vi[y])) < big ){
							big = abs(inp-(vi[x]+vi[y]));
							num = vi[x]+vi[y];
						}
					}
				}
			}

			cout << "Closest sum to " << inp << " is " << num << "." << endl;
		}
		
		TC++;
	}
	return 0;
}
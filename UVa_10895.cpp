#include <bits/stdc++.h>
using namespace std;

int main(){
	int m, n, r, inp;
	while( cin >> m >> n ){
		int XY[m][n];
		int YX[n][m];
		memset(XY, 0, m * n * sizeof(int));
		memset(YX, 0, n * m * sizeof(int));
	
	
		for( int i = 0; i < m; ++i ){
			vector<int> v;
			cin >> r;
	
			if( r != 0 ){
				for( int x = 0; x < r; ++x ){
					cin >> inp;
					v.push_back(inp);
				}
	
				for( int y = 0; y < r; ++y ){
					cin >> inp;
					XY[i][v[y]-1] = inp;
				}
			}
		}
	
		for( int i = 0; i < n; ++i ){
			for( int j = 0; j < m; ++j ){
				YX[i][j] = XY[j][i];
			}
		}
	
		cout<<n<< " " <<m<< endl;
	
		for( int z = 0; z < n; ++z ){
			int num = 0;
			vector<int> p, numm;
			for( int i = 0; i < m; ++i ){
				if( YX[z][i] != 0 ){
					num++;
					p.push_back(i);
					numm.push_back(YX[z][i]);
				}
			}
	
			cout << num;
	
			for( int i = 0; i < num; ++i )
				cout << " " << p[i]+1;
			cout << endl;
			for( int i = 0; i < num; ++i ){
				cout << numm[i];
				if( i+1 != num )
					cout << " ";
			}
			
			cout << endl;
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, n;
	char ch;
	cin >> N >> n;
	while( N != 0){
		char V[105][105];
		char v[105][105];
		char a[105][105];
		char b[105][105];
		char c[105][105];

		for (int j = 0; j < N; ++j){
			for( int i =0; i < N; ++i ){
				cin >> ch;
				V[j][i] = ch;
			}
		}
		

		for (int j = 0; j < n; ++j){
			for( int i = 0; i < n; ++i ){
				cin >> ch;
				v[j][i] = ch;
			}
		}
		
		for (int j = 0; j < n; ++j){
			for( int i = 0; i < n; ++i ){
				a[i][n-j-1] = v[j][i];
			}
		}

		for (int j = 0; j < n; ++j){
			for( int i = 0; i < n; ++i ){
				b[i][n-j-1] = a[j][i];
			}
		}

		for (int j = 0; j < n; ++j){
			for( int i = 0; i < n; ++i ){
				c[i][n-j-1] = b[j][i];
			}
		}

		/*cout << "v: " << endl;
		for( int i = 0; i < n; ++i ){
			for( int j = 0; j < n; ++j ){
				cout << v[i][j] << " ";
			}
			cout << endl;
		}

		cout << "a: " << endl;
		for( int i = 0; i < n; ++i ){
			for( int j = 0; j < n; ++j ){
				cout << a[i][j] << " ";
			}
			cout << endl;
		}

		cout << "b: " << endl;
		for( int i = 0; i < n; ++i ){
			for( int j = 0; j < n; ++j ){
				cout << b[i][j] << " ";
			}
			cout << endl;
		}

		cout << "c: " << endl;
		for( int i = 0; i < n; ++i ){
			for( int j = 0; j < n; ++j ){
				cout << c[i][j] << " ";
			}
			cout << endl;
		}*/

		bool bl = true;
		int one = 0;
		for( int x = 0; x < (N-n+1); ++x ){
			for( int y = 0; y < (N-n+1); ++y ){
				//cout << x << " " << y << endl;
				bl = true;
				for( int z = 0; z < n; ++z ){
					for( int u = 0; u < n; ++u ){
						if( v[z][u] != V[x+z][y+u] ){
							bl = false;
							break;
						}
					}
					if( bl == false ){
						break;
					}
				}
				if( bl == true )
					one++;
			}
		}
		cout << one << " ";

		bl = true;
		one = 0;
		for( int x = 0; x < (N-n+1); ++x ){
			for( int y = 0; y < (N-n+1); ++y ){
				//cout << x << " " << y << endl;
				bl = true;
				for( int z = 0; z < n; ++z ){
					for( int u = 0; u < n; ++u ){
						if( a[z][u] != V[x+z][y+u] ){
							bl = false;
							break;
						}
					}
					if( bl == false ){
						break;
					}
				}
				if( bl == true )
					one++;
			}
		}
		cout << one << " ";

		bl = true;
		one = 0;
		for( int x = 0; x < (N-n+1); ++x ){
			for( int y = 0; y < (N-n+1); ++y ){
				//cout << x << " " << y << endl;
				bl = true;
				for( int z = 0; z < n; ++z ){
					for( int u = 0; u < n; ++u ){
						if( b[z][u] != V[x+z][y+u] ){
							bl = false;
							break;
						}
					}
					if( bl == false ){
						break;
					}
				}
				if( bl == true )
					one++;
			}
		}
		cout << one << " ";

		bl = true;
		one = 0;
		for( int x = 0; x < (N-n+1); ++x ){
			for( int y = 0; y < (N-n+1); ++y ){
				//cout << x << " " << y << endl;
				bl = true;
				for( int z = 0; z < n; ++z ){
					for( int u = 0; u < n; ++u ){
						if( c[z][u] != V[x+z][y+u] ){
							bl = false;
							break;
						}
					}
					if( bl == false ){
						break;
					}
				}
				if( bl == true )
					one++;
			}
		}
		cout << one << " ";


		cin >> N >> n;
	}

	return 0;
}
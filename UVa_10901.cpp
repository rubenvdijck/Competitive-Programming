#include <bits/stdc++.h>
using namespace std;

int main(){
	int c;
	cin >> c;
	for( int x = 0; x < c; ++x ){
		int n, t, m, inp, time = 0, load = 0;
		int side = 0; // 0 = left, 1 = right
		string str;
		queue<int> leftB;
		queue<int> rightB;
		cin >> n >> t >> m;

		/*for( int i = 0; i < m; ++i ){
			cin >> inp >> str;
			if( str == "left" ){
				leftB.push(inp);
			}
			else if( str == "right" ){
				rightB.push(inp);
			}
		}*/

		int i = 0;
		while( i < m ){
			if( leftB.empty() && rightB.empty() ){
				cin >> inp >> str;
				if( str == "right" && side == 0 ){
					time += 2*t;
					side = 1;
				}
				else if( str == "left" && side == 1 ){
					time += 2*t;
					side = 0;
				}
				else
					time += t;
				load++;
				i++;
				cout << time << endl;

				while( inp <= time && load < n ){
					cin >> inp >> str;
					if( str == "left" && side == 1 ){
						leftB.push(inp);
					}
					else if( str == "right" && side == 0 ){
						rightB.push(inp);
					}
					else
						cout << time << endl;
					i++;
				}
				if( side == 1 )
					side = 0;
				else
					side = 1;
			}
			else if( !leftB.empty() ){
				time += t;
				






				
			}
			else if( !rightB.empty() ){
				







				
			}


		}

	}
	return 0;
}
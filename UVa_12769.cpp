#include <bits/stdc++.h>
using namespace std;
vector<int> ft;
vector<int> v;

int LSOne( int i ){
	return (i & (-i));
}

int som( int x ){
	int sum = 0;
	for( int i = x; i > 0; i -= LSOne(i) ){
        sum += ft[i];
    }
    return sum;
}

int point_query( int x ){
	return som(x);
}

void point_update( int x, int y, int add ){
	for( int i = x; i < 100005; i += LSOne(i) ){
	      ft[i] += add;
	}
	for( int i = y+1; i < 100005; i += LSOne(i) ){
	      ft[i] -= add;
	}
}

int main(){
	int T;
	while( (cin >> T) && (T != 0) ){
		v.assign(100001, 0);
		ft.assign(100001, 0);
		
		for( int x = 0; x < T; ++x ){
			char ch;
			cin >> ch;
			
			if( ch == 'B' ){
				int x, y, z;
				cin >> x >> y >> z;
				point_update(x, y, z);			
			}
			else if( ch == 'Q' ){
				int x;
				cin >> x;
				
				/*cout << endl;
				for( int i = 0; i < 17; i++ ){
					cout << ft[i] << " " << i << endl;
				} cout << endl;*/

				int y = point_query(x);
				cout << y << endl;
			}
			else if( ch == 'P' ){
				cout << endl << "Printing ft: " << endl;
				for( int i = 0; i < 30; ++i ){
					cout << i << " " << ft[i] << endl;
				}
				cout << "Finished." << endl <<  endl; 
			}
		}
	}
	return 0;
}

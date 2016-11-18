#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, inp, previnp;
	while(cin >> n){
		vector<int> vi;
		vector<bool> vb(1000000005);

		for(int i = 0; i < n; ++i){
			cin >> inp;
			if(i != 0){
				vb[abs(previnp-inp)] = true;
			//	cout << abs(inp-previnp) << " true" << endl;
			}
			previnp = inp;
		}

		bool bl = true;
		for( int i = 1; i < n; ++i ){
			//cout << vb[i] << endl;
			if( vb[i] == false ){
				bl = false;
				break;
			}
		}

		if( bl == true ){
			cout << "Jolly" << endl;
		} else
			cout << "Not jolly" << endl;
	}

	return 0;
}
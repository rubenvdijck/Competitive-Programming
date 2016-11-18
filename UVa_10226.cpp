#include <bits/stdc++.h>
using namespace std;

int main(){
	int TC;
	cin >> TC;
	string skip;
	getline(cin, skip);
	getline(cin, skip);

	for( int m = 0; m < TC; ++m ){
		string str;
		getline(cin, str, '\n');
		map<string, int> ma;
		double all = 0;

		while(!str.empty()){
			ma[str] += 1;
			all++;
			str = "";
			getline(cin, str);
		}

		//cout << all << endl;
		double x = 100/all;
        for( map<string, int>::iterator it = ma.begin(); it != ma.end(); it++ ){
        	
        
        	double procent = x*it->second;
        	cout << it->first << " " << setprecision(4) << fixed << procent << endl;
        }
        
        if( m != TC-1)
    	    cout << endl;  
	}
}
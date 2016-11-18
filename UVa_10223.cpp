#include <bits/stdc++.h>
using namespace std;
int A[20];

void lol(){
	A[1] = 1; 
	A[2] = 2; 
	A[3] = 5; 
	A[4] = 14; 
	A[5] = 42; 
	A[6] = 132; 
	A[7] = 429; 
	A[8] = 1430; 
	A[9] = 4862; 
	A[10] = 16796; 
	A[11] = 58786; 
	A[12] = 208012; 
	A[13] = 742900; 
	A[14] = 2674440; 
	A[15] = 9694845; 
	A[16] = 35357670; 
	A[17] = 129644790; 
	A[18] = 477638700; 
	A[19] = 1767263190;
}

int main(){
	int n;

	lol();
	while( cin >> n ){
		for( int i = 1; i < 20; ++i ){
			if( A[i] == n )
				cout << i << endl;
		}
	}
}
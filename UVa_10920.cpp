#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, P;
	cin >> N >> P;
	while( N != 0 && P != 0 ){
		long long first, last, lines, rows;
		long long X = 0, Y = 0, one = N/2+1;
		for( int i = P; i; i++ ){
			double sqr = sqrt(i);
			long long minsqr = (long long)floor(sqr);
			if( (minsqr%2) == 1 ){
				lines = sqr; 
				rows = sqr-2;
				last = i;
				first = (i-2);
				break;
			}
		}

		if( P > last-lines ){
			X = one + (lines - one);
			Y = (last - P) + 1;
		}
		else if( P < last-lines-1 && P > last-(lines*2)+1 ){
			X = ((last-lines+1) - P) + 1;
			Y = one - (lines - one);
		}
		else if( P < last-(lines*2)+2 && P > first+(rows) ){
			X = one - (lines - one);
			Y = ((last-(lines*2)+2) - P) + 1;
		}
		else{
			X = (first+(rows)+1)-P+1;
			Y = one + (lines - one);
		}

		cout << "Line = " << X << ", column = "<< Y << "."<< endl;
		

		cin >> N >> P;
	}
	return 0;
}
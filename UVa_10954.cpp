#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n = -1;
	cin >> n;
 
	while( n != 0 ){
		int inp, sum = 0;
		priority_queue<int, std::vector<int>, std::greater<int> > pq;
 
		for( int i = 0; i < n; ++i ){
			cin >> inp; 
			pq.push(inp);
		}
 
		int prev, sec;
 
		while( !pq.empty() ){
			prev = pq.top();
			pq.pop();
			sec = pq.top();
			
			sum = sum + (prev + pq.top());
			if( pq.size() != 1 )
				pq.pop();
			else 
				break;
			
			pq.push(prev + sec);
			//cout << prev << " " << pq.top() << endl;
			
		}
		

		
		cout << sum << endl;
		cin >> n;
	}
 
 
 
	return 0;
}
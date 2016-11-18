#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
	while( cin >> n ){
		//cout << n << endl << endl;
		int x, y, num = 0;
		stack<int> st;
		queue<int> q;
		priority_queue<int> pq;
		bool isST = true, isQ = true, isPQ = true;
		for( int s = 0; s < n; ++s ){
			cin >> x >> y;
			//cout << x << " " << y << endl;
			if( x == 1 ){
				pq.push(y);
				st.push(y);
				q.push(y);
			} else {
				if (isST) {
					if (st.empty() || st.top() != y)
						isST = false;
					else
						st.pop();
				}
				if (isQ) {
					if (q.empty() || q.front() != y)
						isQ = false;
					else
						q.pop();
				}
				if (isPQ) {
					if (pq.empty() || pq.top() != y)
						isPQ = false;
					else
						pq.pop();
				}

			}
		}


		if (isST == true && isQ == false && isPQ == false)
			cout << "stack" << endl;
		else if (isST == false && isQ == true && isPQ == false)
			cout << "queue" << endl;
		else if (isST == false && isQ == false && isPQ == true)
			cout << "priority queue" << endl;
		else if (isST == false && isQ == false && isPQ == false)
			cout << "impossible" << endl;
		else
			cout << "not sure" << endl;


	}
	return 0;
}

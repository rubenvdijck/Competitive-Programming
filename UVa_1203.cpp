#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	int Qnum, period, k;
	priority_queue<pair<int, pair<int, int> >, vector<int>, greater<int> > pq;

	cin >> str;
	while(str != "#"){
		cin>> Qnum >> period;

		pq.push(make_pair(period, make_pair(Qnum, period)));

		cin >> str;
	}

	cin >> k;

	for( int i = 0; i < k; ++i ){
		pair<int, pair<int, int> > pii = pq.top();
		pq.pop();
		pii.first += pii.second.second;
		pq.push(pii);
		cout << pii.second.first << endl;
	}


	return 0;
}
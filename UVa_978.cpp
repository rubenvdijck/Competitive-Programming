#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin>>N;
	for( int x = 0; x < N; ++x ){
		int B, SG, SB, inp;
		priority_queue<int> setG;
		priority_queue<int> setB;
		cin >> B >> SG >> SB;

		for( int i = 0; i < SG; ++i ){
			cin >> inp;
			setG.push(inp);
		}

		for( int i = 0; i < SB; ++i ){
			cin >> inp;
			setB.push(inp);
		}

		while( !setG.empty() && !setB.empty() ){
			vector<int> vi;
			vector<int> vi2;
			for( int j = 0; j < B && (!setG.empty() && !setB.empty()); ++j ){
				int one = setB.top();
				int two = setG.top();
				setB.pop();
				setG.pop();
				
				if( one > two )
					vi.push_back(one-two);
				else if( two > one )
					vi2.push_back( two-one);				
			}

			for( int y: vi )
				setB.push(y);

			for( int y: vi2 )
				setG.push(y);
			
		}


		if( setG.empty() && setB.empty() ){
			cout << "green and blue died" << endl;
			if( x != N-1 ) 
				cout << endl;
		}
		else if( setG.empty() ){		
			cout << "blue wins" << endl;
			while( !setB.empty() ){
				cout << setB.top() << endl;
				setB.pop();
			}
			if( x != N-1 ) 
				cout << endl;
		}
		else{
			cout << "green wins" << endl;
			while( !setG.empty() ){
				cout << setG.top() << endl;
				setG.pop();
			}
			if( x != N-1 ) 
				cout << endl;
		}
		


	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int charToInt( char ch ){
	int x = (int)ch - 0;
	return x;
}

int main(){
	string str, out;
	int curr, prev, small = 1000000005, indSmall = -1;
	cin >> str;
	out = str;
	while( str != "#" ){
		bool bl =  false;
		for( int j = str.length()-1; j > -1; --j ){
			int last = charToInt(str[j]);
			for( int i = j; i < str.length(); ++i ){
				if( charToInt(str[i]) < small ){
					small = charToInt(str[i]);
					indSmall = i;
				}
			}
			for( int i = str.length()-1; i > -1; --i ){
				curr = charToInt(str[i]);
			//	cout << "curr: " <<  curr << " last: " << last <<  endl;
				if( /*(curr != 0) && */(curr < last) ){
					char ch2 = str[j];
					out.insert(i, 1, ch2);
					out.erase(j+1, 1);
					if( indSmall != -1 ){
						char ch3 = out[i];
						out.insert(indSmall, 1, ch3);
						char ch4 = str[indSmall];
						if( indSmall != out.size() )
							out.erase(indSmall+1, 1);
						else
							out.pop_back();
						out.insert(i, 1, ch4);
						out.erase(i+1, 1);
					} 
					bl = true;
					cout << out << endl;
					break;

				}
				
			}
			if( bl == true )
				break;
		}

		if( bl == false ){
			cout << "No Successor" << endl;
		}

		cin >> str;
		out = str;
	}
	return 0;
}
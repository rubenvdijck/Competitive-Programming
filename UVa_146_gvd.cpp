#include <bits/stdc++.h>
using namespace std;

int charToInt( char ch ){
	int x = (int)ch - 0;
	return x;
}

int main(){
	string str, out;
	int curr, prev;
	cin >> str;
	out = str;
	while( str != "#" ){
		bool bl =  false;
		int small = 1000000005, indSmall = str.length()-1;
		char chsm=str[str.length()-1];
		for( int j = str.length()-1; j > -1; --j ){
			int last = charToInt(str[j]);
			if (str[j]<chsm){
				chsm = str[j];
				indSmall = j;
			}
		
			/*for( int i = j; i < str.length(); ++i ){
				if( charToInt(str[i]) < small ){
					small = charToInt(str[i]);
					cout << indSmall << endl;
					indSmall = i;
				}
			}*/
			
			//cout << indSmall << endl;
			//for( int i = str.length()-1; i > -1; --i ){
			for( int i = j; i > -1; --i ){
				curr = charToInt(str[i]);
			//	cout << "curr: " <<  curr << " last: " << last <<  endl;
				if( /*(curr != 0) && */(curr < last) ){
					char ch2 = str[j];
					char ch3 = str[i];
				  	//cout << "ch2 = " << ch2 << " j is " << j << " i is " << i << " chsm is " << chsm << " indSmall is " << indSmall << endl;
				
					out.insert(i, 1, ch2);
					//cout << out << endl;
					out.erase(j+1, 1);
					//cout << out << endl;
					if (chsm < ch3) {
						out.insert(i+1, 1, chsm);
					//cout << out << endl;
						out.erase(indSmall+1,1);
					//cout << out << endl;
						out.erase(i+2,1);
					//cout << out << endl;
						out.insert(indSmall,1,ch3);
					//cout << out << endl;
					}
					/*if( indSmall != -1 ){
						char ch3 = out[i];
						char ch4 = str[indSmall];
						out.insert(indSmall, 1, ch3);
						if( indSmall != out.size() )
							out.erase(indSmall+1, 1);
						else
							out.pop_back();
						out.insert(i, 1, ch4);
						out.erase(i+1, 1);
					} */
					
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
		
		str = ""; out = "";
		cin >> str;
		
		out = str;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	int TC;
	cin >> TC;
	map<string, int> d;
	
	d.insert(make_pair("SUN", 1));
	d.insert(make_pair("MON", 2));
	d.insert(make_pair("TUE", 3));
	d.insert(make_pair("WED", 4));
	d.insert(make_pair("THU", 5));
	d.insert(make_pair("FRI", 6));
	d.insert(make_pair("SAT", 7));
	for( int x = 0; x < TC; ++x ){
		string month, day;
		cin >> month >> day;
		int num = 0, da = d[day], curr;
		if( month == "JAN" || month == "MAR" || month == "MAY" || month == "JUL" || month == "AUG" || month == "OCT" || month == "DEC" ){
			curr = 31;
			if( da <= 6 )
				num += 2;
			else
				num++;

			curr -= 7-da;
	

			if( curr%7 == 0 ){
				num += (curr/7)*2-1;
			}
			else if( curr%7 == 6 ){
				num += ((curr+1)/7)*2-2;
			}
			else{
				num += ((curr-(curr%7))/7)*2;
			}
		}
		else if( month == "FEB" ){
			curr = 28;
			if( da <= 6 )
				num += 2;
			else
				num++;

			curr -= 7-da;
	

			if( curr%7 == 0 ){
				num += (curr/7)*2-1;
			}
			else if( curr%7 == 6 ){
				num += ((curr+1)/7)*2-2;
			}
			else{
				num += ((curr-(curr%7))/7)*2;
			}
		}
		else{
			curr = 30;
			if( da <= 6 )
				num += 2;
			else
				num++;

			curr -= 7-da;
	

			if( curr%7 == 0 ){
				num += (curr/7)*2-1;
			}
			else if( curr%7 == 6 ){
				num += ((curr+1)/7)*2-2;
			}
			else{
				num += ((curr-(curr%7))/7)*2;
			}
		}
		
		cout << num << endl;
	}
	return 0;
}
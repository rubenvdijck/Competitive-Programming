#include <bits/stdc++.h>
using namespace std;

int main(){

	int TC;
	cin >> TC;//after this nbr is read, cin still contains endl
   // cout << "NBR OF TESTCASES :" << TC << endl;
	string skip;
	getline(cin, skip);// read endl after nbr
	getline(cin, skip);// read empty line
 
	
	for( int x = 0; x < TC; ++x ){
		string str;
//
		int pers, problem, time;
		char ch2;
        vector<pair<int, vector<pair<int, int> > > > vi2;
		vector<pair<int, pair<int, pair<int, vector<int> > > > > vi; //1. problems solved 2. penalty time 3. contestant
		getline(cin, str, '\n');
  	   
		while (!str.empty()){
			istringstream tmp(str);
		    //one testcase
		    tmp >> pers;
            tmp >> problem >> time >> ch2;

            int index = -1;
            for( int i = 0; i < vi.size(); ++i ){
            	if( vi[i].second.second.first == pers ){
            		index = i;
            		break;
            	}
            }

            if( ch2 == 'C' ){
            	
            	if( index != -1  ){
            		bool bl2 = false;
            		for( int j = 0; j < vi[index].second.second.second.size(); ++j ){
            			//cout << "Index: " << j << " Number: " << vi[index].second.second.second[j] << endl; 
            			if( vi[index].second.second.second[j] == problem ){
            				bl2 = true;
            				break;
            			}
            		}
            		if( bl2 == false ){
	            		vi[index].first -= 1;
	            		vi[index].second.first += time;
	            		vi[index].second.second.second.push_back(problem);
            		}
            	}
            	else{
            		vector<int> v;
            		v.push_back(problem);
            		vi.push_back(make_pair(-1, make_pair(time, make_pair(pers, v))));
            	}
            }
            else if( ch2 == 'I' ){
            	if( index != -1 ){
            		bool bl2 = false;
            		for( int j = 0; j < vi[index].second.second.second.size(); ++j ){
            			//cout << "Index: " << j << " Number: " << vi[index].second.second.second[j] << endl; 
            			if( vi[index].second.second.second[j] == problem ){
            				bl2 = true;
            				break;
            			}
            		}
            		if( bl2 == false ){
            			bool bl3 = false;
            			int ind;
            			for( int j = 0; j < vi2.size(); ++j ){
            				if( vi2[j].first == pers ){
            					bl3 = true;
            					ind = j;
            					break;
            				}
            			}
            			if( bl3 == false ){
            				vector<pair<int, int> > v;
            				v.push_back(make_pair(problem, 20));
            				vi2.push_back(make_pair(pers, v));
            			}
	            		else{
	            			bool bl4 = false;
	            			int ind2;
	            			for( int j = 0; j < vi2.size(); ++j ){
	            				if( vi2[j].second[j].first == problem ){
	            					bl4 = true;
	            					ind2 = j;
	            					break;
	            				}
	            			}
	            			if(bl4 == true)
	            				vi2[ind].second[ind2].second += 20;
	            		}
	            		//cout << "1" <<  endl;
	            	}
            	}
            	else{
            		vector<int> v;
            		vi.push_back(make_pair(0, make_pair(20, make_pair(pers, v)))); 
            		vector<pair<int, int> >  v2;
            		v2.push_back(make_pair(problem, 20));
            		vi2.push_back(make_pair(pers, v2));
            		//cout << "2" <<  endl;
            	}
            }
            else if( index == -1 ){
            	vector<int> v;
            	vi.push_back(make_pair(0, make_pair(0, make_pair(pers, v)))); 
       		}
			getline(cin, str);			
		}
		

		for( int i = 0; i < vi.size(); ++i ){
			int in;
			for( int z = 0; z < vi2.size(); ++z ){
				if( vi2[z].first == vi[i].second.second.first ){
					in = z;
					break;
				}
			}
			for( int j = 0; j < vi2[in].second.size(); ++j ){
				for( int y = 0; y < vi[i].second.second.second.size(); ++y ){
					if( vi2[in].second[j].first == vi[i].second.second.second[y] ){
						vi[i].second.first += vi2[in].second[j].second;
					}
				}
			}
		}




		sort( vi.begin(), vi.end());

        for( int i = 0; i < vi.size(); ++i ){
        	cout << vi[i].second.second.first << " " << abs(vi[i].first) << " " << vi[i].second.first << endl;
        }
        cout << endl;




	}
	return 0;
}

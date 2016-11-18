#include <bits/stdc++.h>
using namespace std;

struct contestant{
	vector<pair<int, int> > penaltyTime;
	int time = 0;
	int contestantNumber;
	vector<int> problemsSolved;
};

bool compare( contestant a, contestant b ){
	if( a.problemsSolved.size() > b.problemsSolved.size() ){
		return true;
	}
	if (a.problemsSolved.size() < b.problemsSolved.size()) {
		return false;
	}
	if( a.time < b.time ){
		return true;
	} 
	if (a.time > b.time) {
		return false;
	}
	if( a.contestantNumber < b.contestantNumber){
		return true;
	}
	return false;
}

int main(){

	int TC;
	cin >> TC;
	string skip;
	getline(cin, skip);
	getline(cin, skip);

	for( int m = 0; m < TC; ++m ){
		string str;
		int pers, problem, time;
		vector<contestant> vi;
		char ch2;
		getline(cin, str, '\n');

		while (!str.empty()){
			istringstream tmp(str);
		    tmp >> pers;
            tmp >> problem >> time >> ch2;
            //cout << str << endl;
            
            //cout << pers<< ch2 << endl;
            
            bool bl = true;
            int ind = 0;
            for( int i = 0; i < vi.size(); ++i ){
            	if( vi[i].contestantNumber == pers ){
            		bl = false;
            		ind = i;
            		break;
            	}
            }

            if( bl == true ){
            	if( ch2 == 'C' ){
	            	contestant X;
	            	vector<pair<int, int> > v;
	            	vector<int> v2;
	            	v2.push_back(problem);
	            	X.contestantNumber = pers;
	            	X.time = time;
	            	X.penaltyTime = v;
	            	X.problemsSolved = v2;
	            	vi.push_back(X);
	            }
	            else if( ch2 == 'I' ){
	            	contestant X;
	            	vector<pair<int, int> > v;
	            	vector<int> v2;
	            	v.push_back(make_pair(20, problem));
	            	X.contestantNumber = pers;
	            	X.time = 0;
	            	X.penaltyTime = v;
	            	X.problemsSolved = v2;
	            	vi.push_back(X);
	            }
	            else{
	            	contestant X;
	            	X.contestantNumber = pers;
	            	vi.push_back(X);
	            }
            }
            else{
            	if( ch2 == 'C' ){
            		//cout << "1" << endl;
		            bool bl2 = true;
		            for( int i = 0; i < vi[ind].problemsSolved.size(); ++i ){
		            	if( vi[ind].problemsSolved[i] == problem ){
		            		bl2 = false;
		            		break;
		            	}
		            }
		            if( bl2 == true ){
		            	vi[ind].time += time;
		            	vi[ind].problemsSolved.push_back(problem);
		            }
	            }
	            else if( ch2 == 'I' ){
	            	bool bl2 = true;
		            for( int i = 0; i < vi[ind].problemsSolved.size(); ++i ){
		            	if( vi[ind].problemsSolved[i] == problem ){
		            		bl2 = false;
		            		break;
		            	}
		            }
		            if( bl2 == true ){
		            	bool bl2 = true;
		            	int ind2 = 0;
			            for( int i = 0; i < vi[ind].penaltyTime.size(); ++i ){
			            	if( vi[ind].penaltyTime[i].second == problem ){
			            		bl2 = false;
			            		ind2 = i;
			            		break;
			            	}
			            }
			            if( bl2 == false )
			            	vi[ind].penaltyTime[ind2].first += 20;
			            else
			            	vi[ind].penaltyTime.push_back(make_pair(20, problem));
			        }
	            	
	            	
	            }
	            
            }
            
            str = "";
			getline(cin, str);
    	


        }

        for( int i = 0; i < vi.size(); ++i ){
        	for( int j = 0; j < vi[i].penaltyTime.size(); ++j ){
        		for( int k = 0; k < vi[i].problemsSolved.size();  ++k ){
        			if( vi[i].penaltyTime[j].second == vi[i].problemsSolved[k] ){
        				vi[i].time += vi[i].penaltyTime[j].first;
        				break;
        			}
        		}
        	}
        } 

        sort(vi.begin(), vi.end(), compare );    


        for( int i = 0; i < vi.size(); ++i ){
        	cout << vi[i].contestantNumber << " " << abs(vi[i].problemsSolved.size()) << " " << vi[i].time << endl;
        }
        
        if( m == TC-1)
    	    cout << endl;  


	}

}
 
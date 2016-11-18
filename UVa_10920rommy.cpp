#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	long long P;
	cin >> N >> P;// N is sz of square
	while( N != 0 && P != 0 ){

		double sqr = sqrt(P);
		int flr = floor(sqr);
		if( flr%2 == 0 ){
			flr++;//flr*flr > P
		}
		//else flr*flr <= P
		else if (flr < N){
			flr += 2;
		}
		//now flr*flr >= P


        //
        // flr*flr is equal to particular upperrightcorner value (N-x)*(N-x) that is bigger or equal to P
		// N*N          x=N=y=N=N-(square_x_value/2); deltax=N-1=deltay=N-1=N-square_x_value-1, square_x_value=0 (outer one)
		// (N-2)*(N-2)  x=N-1=y=N-1=N-(square_x_value/2); deltax=N-3=deltay=N-3=N-square_x_value-1 square_x_value=2
		// (N-4)*(N-4)  x=N-2=y=N-2=N-(square_x_value/2); deltax=N-5=deltay=N-5=N-square_x_value-1 square_x_value=4
		int square_x_value = N - flr;
		int deltacoordinate = N-square_x_value-1;
		int x = N-(square_x_value/2);
		int y = N-(square_x_value/2);
		long long spiralpositionstosubtract = flr*flr - P;
		do{
		    //1 go down at right
			if ( spiralpositionstosubtract > 0 && spiralpositionstosubtract >= deltacoordinate){
				spiralpositionstosubtract -= deltacoordinate;
			    y -= deltacoordinate;
			}
		    else{
			    y -= spiralpositionstosubtract;
			    break;
		    }
		    //2 go left at bottom
	        if (spiralpositionstosubtract > 0 && spiralpositionstosubtract >= deltacoordinate){
			    spiralpositionstosubtract -= deltacoordinate;
			    x -= deltacoordinate;
		    }
		    else{
			    x -= spiralpositionstosubtract;
			    break;
		    }
		    //3 go up at left
			if (spiralpositionstosubtract >= deltacoordinate){
				spiralpositionstosubtract -= deltacoordinate;
			    y += deltacoordinate;
			}
		    else{
			    y += spiralpositionstosubtract;
			    break;
		    }
		    //4 go right at top
	        if (spiralpositionstosubtract >= (deltacoordinate - 1)){
			    spiralpositionstosubtract -= (deltacoordinate - 1);
			    x += (deltacoordinate - 1);
		    }
		    else{
			    x += spiralpositionstosubtract;
			    break;
		    }
		    //5 last step is to go down by one for y position
		    if (spiralpositionstosubtract == 1){
			    y -= spiralpositionstosubtract;
			    break;
			}


        }while(0);


		cout << "Line = " << y << ", column = "<< x << "."<< endl;
		

		cin >> N >> P;
	}
	return 0;
}
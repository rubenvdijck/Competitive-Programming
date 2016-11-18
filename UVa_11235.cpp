#include <bits/stdc++.h>
using namespace std;

vector<int> A;
vector<int> st;
vector<int> S;
vector<int> F;

void buildFS( int n ){
	int start = 0, prev = -100005, total = 0;
	for (int i = 0; i < n; ++i){
		if( prev != A[i] ){
			prev = A[i];
			for( int j = start; j < start + total; ++j ){
				F[j] = total;
				S[j] = start;
			}
			start = i;
			total = 1;
		}
		else{
			total++;
			prev = A[i];
			S.push_back(start);
		}
	}
	for( int j = start; j < start + total + 1; ++j ){
		F[j] = total;
		S[j] = start;
	}
}

void build(int p, int L, int R){
	if(L == R)
		st[p] = F[L];
	else{
		build(2*p, L, (L+R)/2);
		build(2*p+1, (L+R)/2+1, R);
        int p1 = st[2*p], p2 = st[2*p+1];
        st[p] = max(p1, p2);
	}
}

int query( int p, int L, int R, int i, int j ){
	if(i > j) return -100005;
	if( L >= i && R <= j ) return st[p];
	if( i > R || j < L ) return -100005;

	int p1 = query( 2*p, L, (L+R)/2, i, j );
	int p2 = query( 2*p+1, (L+R)/2+1, R, i, j );

	return max(p1, p2);
}

int main(){
	int n, q, inp, inp2, a, b;
	cin >> n;
	while( n != 0 ){
		cin >> q;

		st.assign(4*n, 0);
		S.assign(n, 0);
		F.assign(n, 0);


		for(int i = 0; i < n; ++i ){
			cin >> inp;
			A.push_back(inp);
		}

		buildFS(n);
		build( 1, 0, n-1 );

		for (int i = 0; i < q; ++i){
			cin >> a >> b;
			--a; --b;
			// int x = query( 1, 0, n-1, a-1, b-1 );
			if( A[a] == A[b] )
				cout << b - a + 1 << endl;
			else{
				int p1 = F[a] - (a - S[a]);
				int p2 = b - S[b] + 1;
				int y = query( 1, 0, n-1, S[a] + F[a], S[b] - 1 );

                // printf("%d %d %d\n", p1, p2, y);

				cout << max(y,max(p1, p2)) << endl;
			}
		}
		A.clear();
		cin >> n;
	}
	return 0;
}

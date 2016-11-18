#include <bits/stdc++.h>
using namespace std;
vector<int> A;
vector<bool> awake;

class UF(){
private:
	vector<int> p, r;
public:
	void UF( int n ){
		p.assign(n, 0);
		r.assign(n, 0);
		A.assign(n, 0);
		awake.assign(n, 0);
		for( int i = 0; i < n; ++i ){
			p[i] = i;
			A[i] = i;
		}
	}

	int find( int a ){
		if( p[a] == a )
			return a;
		return p[a] = find(p[a]);
	}

	bool sameS( int a, int b ){
		return find(a) == find(b);
	}

	void merge( int a, int b ){
		int pa = find(p[a]);
		int pb = find(p[b]);

		if( pa == pb ) return;
		if( r[pa] > r[pb] )
			p[b] = pa;
		else{
			p[a] = pb;
			if( r[pa] == r[pb] )
				r[pb]++;
		}
	}
}

int main(){
	int n, m, inp;
	string str;
	char ch, ch2, ch3;

	cin >> n >> m >> str;
	UF uf(26);

	istringstream tmp(str);
	tmp >> ch >> ch2 >> ch3;
	int c1 = ch-'A', c2 = ch2-'A', c3 = ch3-'A';
	uf.merge(c1, c2);
	uf.merge(c2, c3);
	uf.merge(c1, c3);
	awake[c1] = true;
	awake[c2] = true;
	awake[c3] = true;


	for( int i = 0; i < m; ++i ){
		cin >> ch >> ch2;
		int w1 = ch - 'A', w2 = ch-'A';
		uf.merge(w1, w2);
	}


	return 0;
}
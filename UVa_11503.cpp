#include <bits/stdc++.h>
using namespace std;
vector<int> p, r, sSize;

class UF{
private:
	int numSets;
public:
	UF(int n){
		r.assign(n, 0);
		p.assign(n, 0);
		numSets = n;
		for( int i = 0; i < n; ++i )
			p[i] = i;
		sSize.assign(n, 1);
	}

	int find(int a){
		if( p[a] == a )
			return a;
		return p[a] = find(p[a]);
	}

	bool sameS(int a, int b){
		return find(a) == find(b);
	}

	void merge(int a, int b){
		int pa = find(a);
		int pb = find(b);

		if( pa == pb ) return;
		if( r[pa] > r[pb] ){
			p[pb] = pa;
			sSize[pa] += sSize[pb];
		} else{
			p[pa] = pb;
			sSize[pb] += sSize[pa];
			if( r[pa] == r[pb] )
				r[pb]++;
		}

		
	}

	int setSize(int a){
		return sSize[find(a)];
	}

};

int main(){
	int TC;
	cin >> TC;

	for( int x = 0; x < TC; ++x ){
		int n, num = 0;
		string str, str2;
		map<string, int> m;
		//vector<pair<int, int> > vi;

		

		cin >> n;
		UF uf(n*2);
		for( int i = 0; i < n; ++i ){
			cin >> str >> str2;
			if( !m.count(str) ){
				num++;
				m[str] = num;
			}
			if( !m.count(str2) ){
				num++;
				m[str2] = num;
			}

			uf.merge(m[str], m[str2]);

			cout << uf.setSize(m[str]) << endl;
			
			/*cout << endl;
			for( int v: sSize )
				cout << v << endl;*/
			//vi.push_back(make_pair(m[str], m[str2]));
		}
	}
	return 0;
}
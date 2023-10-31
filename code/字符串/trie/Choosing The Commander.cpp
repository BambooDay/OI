#include <bits/stdc++.h>
const int N = 3e6+10;

using namespace std;
int tr[N][2];
int idx=1;
int cnt[N];
void upd(int x,int z){
	int p = 1;
	bool t;
	for(int i = 31;i >= 0;i--){
		t = x & (1<<i);
		if(!tr[p][t]) tr[p][t] = ++idx;
		p = tr[p][t];
		cnt[p] += z;
	}
}
int ask(int p, int l){
	int k = 1,res = 0;
	bool x,y;
	for(int i = 31;i >= 0;i--){
		x = p & (1<<i),y = l & (1<<i);
		if(y) res += cnt[tr[k][x]],k = tr[k][x^1];
		else k = tr[k][x];
	}
	return res;
}
int n;
int main(){
	cin >> n;
	for(int i = 1;i <= n; i++){
		int op,p,l;
		cin >> op >> p;
		if(op == 1) upd(p,1);
		if(op == 2) upd(p,-1);
		if(op == 3){
			cin >> l;
			cout << ask(p,l) << endl;
		}
	}
	return 0;
}


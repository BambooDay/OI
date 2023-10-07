#include <bits/stdc++.h>
const int N = 4e5+10;
const int M = 1005;

using namespace std;
int a[N];
struct Block{
	int l, r;
	priority_queue<int> val;
	priority_queue<int,vector<int> , greater<int> > tag;
	int modify1(int x){
		if(x >= val.top()) return x;
		int res = val.top();
		val.pop();
		tag.push(x);
		val.push(x);
		return res;
	}
	void rebuild(){
		if(!tag.size()) return;
		for(int i = l; i <= r;i++){
			if(tag.top() < a[i]){
				int t = a[i];
				a[i] = tag.top();
				tag.pop();
				tag.push(t);
			}
		}
	}
	int modify2(int x, int L , int R){
		rebuild();
		while(tag.size()) tag.pop();
		while(val.size()) val.pop();
		for(int i = L; i <= R; i++){
			if(a[i]> x) swap(a[i],x);
		}
		for(int i = l; i <= r; i++){
			val.push(a[i]);
		}
		return x;
	}
}blk[M];
int n, q, pos[N],siz,tot;
int nxt(int x){
	return (x+1 > tot)? 1: x+1;
}
int main(){
	cin >> n >> q;
	siz = sqrt(n);
	tot = (n-1) / siz + 1;
	for(int i = 1;i <= n; i++) pos[i] = (i-1) / siz + 1;
	for(int i = 1;i <= tot; i++) blk[i].l = (i-1)*siz +1,blk[i].r= min(i*siz,n);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		blk[pos[i]].val.push(a[i]);
	}
	for(int i = 1,l,r,A;i <= q; i++){
		cin >> l >> r >> A;
		if(pos[l] == pos[r] && l <= r){
			cout << blk[pos[l]].modify2(A,l,r) << endl;
			continue;
		}
		A = blk[pos[l]].modify2(A,l,blk[pos[l]].r);
		int cur = nxt(pos[l]);
		while(cur != pos[r]){
			A = blk[cur].modify1(A);
			cur = nxt(cur);
		}
		cout << blk[pos[r]].modify2(A,blk[pos[r]].l,r) << endl;
	}
	return 0;
}

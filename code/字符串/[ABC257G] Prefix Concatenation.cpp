#include <bits/stdc++.h>
const int N = 5e5+10;
#define ull unsigned long long
const ull BASE = 13331;
#define ls(fa) fa<<1
#define rs(fa) fa<<1|1
#define mid ((l+r)>>1)
using namespace std;
int node[N<<2];
void build(int pos, int l, int r){
	if(l == r){
		node[pos] = 1e9;
		return;
	}
	build(ls(pos),l,mid);
	build(rs(pos),mid+1,r);
	node[pos] = min(node[ls(pos)],node[rs(pos)]);
}
void modify(int pos, int l, int r, int x, int y){
	if(l == r){
		node[pos] = y;
		return;
	}
	if(x <= mid){
		modify(ls(pos),l,mid,x,y);
	}else{
		modify(rs(pos),mid+1,r,x,y);
	}
	node[pos] = min(node[ls(pos)],node[rs(pos)]);
}
int ask(int pos, int l, int r, int x, int y){
	if(x <= l && r <= y){
		return node[pos];
	}
	int res = 1e9;
	if(mid <= x){
		res = min(res,ask(ls(pos),l,mid,x,y));
	}
	if(mid < y){
		res = min(res,ask(rs(pos),mid+1,r,x,y));
	}
	return res;
}
int lent,lens;
ull hs[N],ht[N],base[N];
int get(int x){
	int l = 0,r = lent-x+1;
	int ans = 0;
	while(l <= r){
		int m = (l+r)>>1;
		if(ht[m] == hs[x+m-1]-hs[x-1]/base[m]){
			ans = m;
			l = m+1;
		}else r = m-1;
	}
	return ans;
}
int l[N];
string s,t;
int main(){
	cin >> t >> s;
	lent = t.size();
	lens = s.size();
	build(1,1,lens+1);
	base[0] = 1;
	for(int i = 1; i <= max(lent,lens); i++){
		base[i] = base[i-1]*BASE;
	}
	for(int i = 1;i <= lent; i++){
		ht[i] = ht[i-1]*BASE+t[i-1];
	}
	for(int i = 1; i <= lens; i++){
		hs[i] = hs[i-1]*BASE + s[i-1];
	}
	for(int i = 1; i <= lens; i++){
		l[i] = get(i);
		cout << l[i] << " ";
	}
	cout << endl;
	modify(1,1,lens+1,lens+1,0);
	int x = -1;
	for(int i = lens; i; i--){
		x = ask(1,1,lens+1,i,i+l[i])+1;
		cout << i << endl;
		modify(1,1,lens+1,i,x);
	}
	cout << "xxxxx" << endl;
	if(x > lens) puts("-1");
	else cout << x << endl;
	return 0;
}

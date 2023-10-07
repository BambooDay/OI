#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls(f) f*2
#define rs(f) f*2+1
const int N = 2e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int val[4*N];
int a[N],num[N];
void modify(int l, int r,int cur, int pos, int x){
	if(l == r){
		val[cur] += x;
		return;
	}
	int mid = (l+r) >> 1;
	if(pos <= mid){
		modify(l,mid,ls(cur),pos,x);
	}else{
		modify(mid+1,r,rs(cur),pos,x);
	}
	val[cur] = max(val[ls(cur)],val[rs(cur)]);
}
int query(int l, int r, int pos){
//cout << 1;
	if(l == r) return l;
	int mid = (l+r) >> 1;
	if(val[rs(pos)] <= val[ls(pos)]){
		return query(l,mid,ls(pos));
	}else{
		return query(mid+1,r,rs(pos));
	}
}
int n, m;
int len = 0;
int x[N],y[N];
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		num[++len] = a[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> x[i] >> y[i];
		num[++len] = y[i];
	}
	sort(num+1,num+1+len);
	len = unique(num+1,num+1+len)-num-1;
	for(int i = 1;i <= n; i++){
		int pos = lower_bound(num+1,num+1+len,a[i]) - num;
		modify(1,len,1,pos,1);
	}
	for(int i = 1;i <= m; i++){
		int pos=lower_bound(num+1,num+1+len,a[x[i]])-num;
		modify(1,len,1,pos,-1);
		pos=lower_bound(num+1,num+1+len,y[i])-num;
		modify(1,len,1,pos,1);
		a[x[i]]=y[i];
		cout<<num[query(1,len,1)]<<"\n";
	}
	return 0;
}

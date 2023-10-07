#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 4e5+10;
const int M = 5e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n,m, p, q;
struct dish{
	int price,val;
	bool friend operator < (const dish x,const dish y){
		return x.price < y.price;
	}
}a[N];
int nit[N],poor[N];

bool cmp_val(dish x, dish y){
	return x.val > y.val;
}
bool cmp_price(dish x, dish y){
	return x.price < y.price;
}
bool check(int ans){
	priority_queue<dish> Q; 
//	cout << 1;
	if(m <= 1ll*(n-p-q)*ans) return 1;
	int now = 1;
	for(int i = 1; i <= p; i++){
		while(a[now].val >= nit[i] && now <= m){
			Q.push(a[now]);
			now++;
		} 
		for(int j = 1; !Q.empty() && j <= ans; j++) Q.pop();
	}
	dish b[N];
	int cnt = 0;
	while(!Q.empty()){
		b[++cnt] = Q.top();
		Q.pop();
	} 
	while(now <= m) b[++cnt] = a[now++];
	sort(b+1,b+1+cnt,cmp_price);
	now = 1;
	for(int i = 1; i <= q; i++){
		while(b[now].price <= poor[i] && now <= cnt){
			Q.push(b[now++]);
		}
		for(int j = 1; !Q.empty() && j <= ans; j++) Q.pop();
	}
	int x = Q.size() + cnt-now+1;
	return x <= (n-p-q)*ans;

}
int main(){
	cin >> n >> m >> p >> q;
	for(int i = 1;i <= m; i++){
		cin >> a[i].val >> a[i].price;
	}
	for(int i = 1;i <= p; i++){
		cin >> nit[i];
	}
	for(int i = 1;i <= q; i++){
		cin >> poor[i];
	}
	sort(a+1,a+1+m,cmp_val);
	sort(nit+1,nit+1+p,greater<int>());
	sort(poor+1,poor+1+q);
	int l = 1, r = m,res = -1;
	while(l <= r){
		int mid = (l+r) >> 1;
		if(check(mid)){
			r = mid-1;
			res = mid;
		}else{
			l = mid+1;
		}
	}
	cout <<res;
	return 0;
}

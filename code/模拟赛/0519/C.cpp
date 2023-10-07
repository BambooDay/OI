#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 2e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n, d;

ll ab(ll x){
	return x > 0 ? x: -x;
}
struct Node{
	ll s[10];
}a[N];
ll get(Node x, Node y){
	ll sum = 0;
	for(int i = 1;i <= d; i++){
		sum += ab(x.s[i] - y.s[i]);
	}
	return sum;
}
ll res = -1;
ll dis[N];
int main(){
	cin >> n >> d;
	if(d == 1){
		for(int i =1;i <= n; i++){
			cin >> dis[i];
		}
		sort(dis+1,dis+n+1);
		cout << dis[n] - dis[1];
		return 0;		
	}
	if(n <= 5000){
		
		for(int i = 1;i <= n; i++){
			for(int j = 1;j <= d; j++){
				cin >> a[i].s[j];
			}
		}
		for(int i = 1;i <= n; i++){
			for(int j = i+1; j <= n; j++){
				res = max(res,get(a[i],a[j]));
			}
		}
		cout << res;
	}else{
			for(int i = 1;i <= n; i++){
				for(int j = 1; j <= d; j++){
					ll x = 0;
					cin >> x;
					dis[i] += x;
				}
			}	
			sort(dis+1,dis+1+n);
			cout  << ab(dis[1] - dis[n]);
	}				
	return 0;
}

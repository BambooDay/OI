#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 3e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
bool is[M];
vector<int> pri;
vector<pair<int,int> > cnt;
int m1, m2;
int n;

void init_pri(){
	for(int i =2; i <= m1; i++){
		if(!is[i]){
			pri.push_back(i);
		}
		for(auto j : pri){
			if(i * j > m1) break;
			is[i * j] =1;
			if(i % j == 0){
				break;
			}
		}
	}
}
void find_m1(){
	for(auto i : pri){
		if(i > m1) return;
		int f = 0;
		while(m1 % i == 0){
			f++;
			m1 /= i;
//		cout << i << " " << m1<< endl;
		}
		if(f){
			cnt.push_back(make_pair(i,f * m2));
		}
	}
}

ll get_min(int x){
	int res = 0;
	for(auto i : cnt){
		if(x % i.first){
			return -1;
		}
		int f = 0;
		while(x % i.first == 0){
			f++;
			x /= i.first;
		}
		res = max(res,(i.second / f) + !!(i.second % f));
//		cout << res << endl;
	}
	return res;
}
ll ans = INF;
int main(){
	cin >> n >> m1 >> m2;
	init_pri();
	find_m1();
//	get_min(30);
	for(int i = 1; i <= n; i++){
		ll a;
		cin >> a;
		a = get_min(a);
		if(a != -1){
			ans = min(ans,a);
		}
	}
	if(ans == INF) cout << -1;
	else cout << ans; 
	return 0;
}

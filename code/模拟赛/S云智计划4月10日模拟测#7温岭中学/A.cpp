#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;

using namespace std;
int n;
map<pair<int,int> ,int> m;
int a,b;

signed main(){
	freopen("shooting.in","r",stdin);
	freopen("shooting.out","w",stdout);
	cin >> n;
	cin >> a >> b;
	for(int i = 1;i <= n; i++){
		int x,y;
		cin >> x >> y;
		int u = x-a,v = y-b;
		if(u == 0){
			v = 1;
			m[{u,v}]++;
			continue; 
		}
		if(v == 0){
			u = 1;
			m[{u,v}]++;
			continue; 
		}
		if(u < 0 && v < 0) u = -u,v = -v;
		int g = __gcd(abs(u),abs(v));
		u /= g,v /= g;
		m[{u,v}]++; 
//		cout << u << " " << v << endl;
	}	
	int ans = 0;	
	for(auto i : m){
//		cout << i.second << " ";
		ans += i.second*(i.second-1);
	}
	cout << ans;
	return 0;
}

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
vector<int> prime;
bool no[N];
map<int,bool> bad;
void init(int x){
	no[1]=1;
	for(int i = 2; i <= x;i++){
		if(!no[i]){
			prime.push_back(i);
		}
		for(int j : prime){
			if(i * j > x) break;
			no[i*j] = j;
			
			if(i % j == 0) break;
		}
	}
}
int f(int x){
	int ans = 0;
	for(int i : prime){
		while(x % i == 0){
			if(bad.count(i)) ans--;
			else ans++;
			x /= i;
		}
		if(x == 1) break;
	}
	if(x == 1) return ans;
	if(bad.count(x)) return ans-1;
	else return ans+1;
}
int a[5005];
int n, m;
ll ans = 0;
int main(){
	scanf("%d%d",&n,&m);
//	cin >> n >> m;
//	cin >> a[1];
	for(int i =1;i <= n; i++){
//		cin >> a[i];
		scanf("%d",&a[i]);
	}
	while(m--){
		int b;
//		cin >> b;
		scanf("%d",&b);
		bad[b] = 1;
	}
	init(1e5);
	while(1){
		int gcd = a[1],pos = 1,now = a[1];
		for(int i = 2; i <= n; i++){
			gcd = __gcd(gcd,a[i]);
			if(f(gcd) < 0) pos = i,now = gcd;
		}
		if(f(now) >= 0) break;
		for(int i = 1; i <= pos; i++){
			a[i] /= now;
		}
	}
	for(int i = 1; i <= n; i++) ans += f(a[i]);
//	cout << ans;
	printf("%d",ans);
	return 0;
}

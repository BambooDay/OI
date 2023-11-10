#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;

using namespace std;
int n,k;
int a[N],b[N];
double st;
namespace Sub1{
	bool cmp(int a,int b){
		return a > b;
	}
	void solve(){
		sort(a+1,a+1+n);
		sort(b+1,b+1+n,cmp);
		int ans = 0;
		for(int i =1;i <= n; i++){
			ans += abs(a[i]-b[i]);
		}
		printf("%lld\n",ans);
	}
}

namespace Sub2{
	void solve(){
		int ans = 0;
		for(int i = 1; i <= n; i++){
			ans += abs(a[i]-b[i]);
		}
		int res = ans;
		for(int i = 1;i <= n; i++){
			for(int j = i+1; j <= n; j++){
				for(int x = 1; x <= n; x++){
					for(int y = x+1; y <= n; y++){
						int tmp = res;
						tmp -= abs(a[i]-b[i])+abs(a[j]-b[j]);
						if(x != i && x != j) tmp -= abs(a[x]-b[x]);
						if(y != i && y != j) tmp -= abs(a[y]-b[y]);
						swap(a[i],a[j]),swap(a[x],a[y]);
						tmp += abs(a[i]-b[i])+abs(a[j]-b[j]);
						if(x != i && x != j) tmp += abs(a[x]-b[x]);
						if(y != i && y != j) tmp += abs(a[y]-b[y]);
						swap(a[x],a[y]),swap(a[i],a[j]);
						ans = max(ans,tmp);
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
}
namespace Sub3{
	void solve(){
		int ans = 0;
		for(int i = 1; i <= n; i++){
			ans += abs(a[i]-b[i]);
		}
		for(int i = 1;i <= n; i++){
			for(int j = i+1; j <= n; j++){
				int tmp = ans;
				tmp -= abs(a[i]-b[i])+abs(a[j]-b[j]);
				swap(a[i],a[j]);
				tmp += abs(a[i]-b[i])+abs(a[j]-b[j]);
				swap(a[i],a[j]);
				ans = max(ans,tmp);
			}
		}
		printf("%lld\n",ans);
	}	
}
namespace Sub4{
	void solve(){
		int ans = 0;
		for(int i =1;i <= n; i++){
			ans += abs(a[i]-b[i]);
		}
		printf("%lld\n",ans);
	}	
}
namespace Sub5{
	int ans = 0;
	mt19937 rnd(time(0));
	void SA(){
		int tmp = ans,c[N];
		for(int i =1;i <= n; i++){
			c[i] = a[i];
		}
		for(int i = 1;i <= k; i++){
			int x = rnd()%n+1,y = rnd()%n+1;
			tmp -=abs(c[x]-b[x])+abs(c[y]-b[y]);
			swap(c[x],c[y]);
			tmp += abs(c[x]-b[x])+abs(c[y]-b[y]);
			if((k-i)%2==0) ans = max(ans,tmp);	
			if(double(clock()-st)/CLOCKS_PER_SEC > 0.08) return;		
		}
	}
	void solve(){
		for(int i =1;i <= n; i++){
			ans += abs(a[i]-b[i]);
		}
		while(double(clock() - st)/CLOCKS_PER_SEC < 0.08) SA();
		printf("%lld\n",ans);
	}
}
void sol(){
	st = clock();
	scanf("%lld%lld",&n,&k);
	for(int i = 1;i <= n; i++){
		scanf("%lld",&a[i]);
	}
	for(int i = 1;i <= n; i++){
		scanf("%lld",&b[i]);
	}
	if(k == 0){
		Sub4::solve();
	}else if(k >= n*n){
		Sub1::solve();
	}else if(n <= 75 && k == 2){
		Sub2::solve();
	}else if(n <= 3000 && k == 1){
		Sub3::solve();
	}else{
		Sub5::solve();
	}
}
signed main(){
	freopen("swap.in","r",stdin);
	freopen("swap.out","w",stdout);
	int t;
	scanf("%lld",&t);
	while(t--) sol();
	return 0;
}
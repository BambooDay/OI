#include <bits/stdc++.h>
const int N = 1e6+10;
#define int long long
using namespace std;
int n,q;
int a[N];
int sum;
int s1,s2;

void solve(){
//	cin >> n >> q;
	scanf("%lld%lld",&n,&q);
	sum = 0;
	s1 = 0,s2 = 0;
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
		s2 += a[i]; 
	} 
	if(abs(q) > 2*n || (abs(q) == 2*n && q > 0)){
		puts("No");
		return;
	}
	if(abs(q) == 2*n){
		cout << a[n] << "\n";
		return;
	}
	sort(a+1,a+1+n);
//	if(n&1){
//		cout << a[n/2+1] << "\n";
//		return;
//	}
//	if(q >= 0){
//		cout << a[n/2] << "\n";
//	}else{
//		cout << a[n/2+1] << "\n";
//	}

//	for(int i = 2; i <= n; i++){
//		pre[i] = pre[i-1]+(a[i]-a[i-1])*(i-1)*2;
//	}
//	for(int i = n-1; i; i--){
//		suf[i] = suf[i+1]+(a[i+1]-a[i])*(n-i)*2;
//	}

//	for(int i = 1;i <= n; i++){
//		cout << pre[i] << " ";
//	}
//	cout << endl;
	s2 -= a[1]*n;
	int mi = 1e18;
	int ans = 0;
	for(int i = 1;i <= n; i++){
		int t = s1*2+s2*2 + a[i]*q;
		if(t < mi){
			mi = t;
			ans = a[i];
		}
		s2 -= (n-i)*(a[i+1]-a[i]);
		s1 += (a[i+1]-a[i])*i; 
	}
	printf("%lld\n",ans);
}
signed main(){
	int T;
	cin >> T;
	while(t--){
//		solve();
		scanf("%lld%lld",&n,&q);
		sum = 0;
		s1 = 0,s2 = 0;
		for(int i = 1; i <= n; i++){
			scanf("%lld",&a[i]);
			s2 += a[i]; 
		} 
		if(abs(q) > 2*n || (abs(q) == 2*n && q > 0)){
			puts("No");
			break;
		}else if(abs(q) == 2*n){
			cout << a[n] << "\n";
			break;
		}else{
			sort(a+1,a+1+n);
			s2 -= a[1]*n;
			int mi = 1e18;
			int ans = 0;
			for(int i = 1;i <= n; i++){
				int t = s1*2+s2*2 + a[i]*q;
				if(t < mi){
					mi = t;
					ans = a[i];
				}
				s2 -= (n-i)*(a[i+1]-a[i]);
				s1 += (a[i+1]-a[i])*i; 
			}
			printf("%lld\n",ans);	
		}
	}	
	return 0;
}

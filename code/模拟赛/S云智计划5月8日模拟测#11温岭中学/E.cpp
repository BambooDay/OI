#include <bits/stdc++.h>
const int N = 1e5+10;

using namespace std;
int n;
int a[N];
int f1[N],f2[N],len1,len2;
int ans = -1;
int main(){
	freopen("pile.in","r",stdin);
	freopen("pile.out","w",stdout);
	cin >> n;
	for(int i = n; i ; i--) cin >> a[i];
//	memset(f1,0x3f,sizeof f1);
//	memset(f2,0x3f,sizeof f2);

	f1[0] = 0;
	f2[0] = 0;
	len1 = 0;
	len2 = 0;
	for(int i = 1;i<=n;i++){
//		a[i] = -a[i];
		int res = 0;
		if(a[i] > f1[len1]) f1[++len1] = a[i];
		else{
			f1[lower_bound(f1,f1+len1+1,a[i]) - f1] = a[i];
		}
		res += lower_bound(f1,f1+len1+1,a[i]) - f1;
		a[i] = -a[i]; 
		if(a[i] > f2[len2]) f2[++len2] = a[i];
		else{
			f2[lower_bound(f2,f2+len2+1,a[i]) - f2] = a[i];
		}
		res += lower_bound(f2,f2+len2+1,a[i]) - f2;
		ans = max(ans,res);
	}
//	for(int i = 0; i <= len; i++){
//		cout << f[i] << " ";
//	}
	cout << ans << endl; 
	return 0;
}



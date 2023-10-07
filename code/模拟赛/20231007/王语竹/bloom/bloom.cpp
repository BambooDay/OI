#include <bits/stdc++.h>
const int N = 3e7+10;
using namespace std;
int a[N];
void Gen(int n, unsigned s1, unsigned s2, unsigned s3) {
	for(int i = 1; i <= n; ++i) {
		s1 ^= s3;
		s3 += 3055373123u;
		a[i] = (1 << ((s1 >> s2) & 1));
		s2 = (s2 ^ s3) & 31;
		s3 = (s3 >> s2) | ((s3 << (31 ^ s2)) << 1);
	}
}
int n,s1,s2,s3;
int l,m,r;
unsigned long long ans = 0;
signed main(){
	freopen("bloom.in","r",stdin);
	freopen("bloom.out","w",stdout);
	cin >> n >> s1 >> s2 >> s3;
	Gen(n,s1,s2,s3);
//	if(n <= 2){
//		cout << max(a[1],a[2]) << endl;
//		return 0;
//	}
//	for(int i = 1; i <= n; i++){
//		cin >> a[i] ;
//		cout << a[i] << " ";
//		if(i%10 == 0) break;
//	}
	l =  1,m = 2,r = 3;
	while(r <= n){
		ans++;
		if(a[l] <= a[m]){
			a[l] -= 1;
			a[m] -= 2;
			a[r] -= 1;
		}else{
			a[l] -= 2;
			a[m] -= 1;
		}
		
		if(a[r] <= 0) r++;
		if(a[m] <= 0) m = r,r++;
		if(a[l] <= 0) l = m, m = r, r++; 
	}
//	cout << l << " " << m << " " << r << endl;
//	cout << a[l] << " " << a[m] << " " << a[r] << endl; 
	if(a[l] > 0 && a[m] <= 0 && a[r] <= 0) ans++;
	else if(a[l] > 0 && a[l] > a[r]) ans ++;
	else if(a[l] > 0 && a[r] > a[l]) ans++;
	else if(a[l] > 0 && a[l] == a[r]) ans += 2;
	cout << ans;
	return 0;
}

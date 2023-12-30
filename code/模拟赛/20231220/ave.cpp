#include <bits/stdc++.h>
#define int long long 
const int N = 1e5+10;
 
using namespace std;
int n,m,num;
int a[N],s[N],c[N];
int tmp[N];
int merge(int l, int mid, int r){
	int i = l, j = mid+1,k = l;
	int sum = 0;
	while(i <= mid && j <= r){
		if(s[i] > s[j]){
			tmp[k++] = s[j++];
			sum += mid-i+1;
		}else{
			tmp[k++] = s[i++];
		}
	} 
	while(i <= mid)  tmp[k++] = s[i++];
	while(j <= r) tmp[k++] = s[j++];
	for(int i = l; i <= r; i++) s[i] = tmp[i];
	return sum;
}
int srt(int l, int r){
	int cnt = 0;
	if(l < r){
		int mid = (l+r) >> 1;
		cnt += srt(l,mid);
		cnt += srt(mid+1,r);
		cnt += merge(l,mid,r); 
	}
	return cnt;
}
int calc(int x){
	s[1] = 0;
	for(int i = 1; i <= n; i++){
		s[i+1] = s[i]+a[i]-x;
	}
	return srt(1,n+1);
}
signed main(){
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		a[i] *= 100000;
	}
	int l = 0,r = 1e14;
	int ans = 0;
//	cout << calc(379995) << endl;
//	return 0;
	while(l <= r){
		int mid = (l+r)>>1;
//		cout << mid << endl;
		if(calc(mid) < m) l = mid+1;
		else r = mid-1,ans = mid;
	}
	cout << fixed << setprecision(4) << ans / 100000.0 << endl;
	return 0;
}



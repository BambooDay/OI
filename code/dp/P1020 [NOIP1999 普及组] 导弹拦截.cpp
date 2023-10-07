#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n, a[N],f[N];
int len = 1;
int main(){
	while(cin >> a[++n]);
	n--;
	memset(f,0x3f,sizeof f);
	f[1] = a[1];
	for(int i = 2;i <= n; i++){
//		a[i] = -a[i];
		if(a[i] <= f[len]) f[++len] = a[i];
		else{
			f[upper_bound(f,f+len+1,a[i],greater<int>()) - f] = a[i];
		}
	} 
	cout << len << endl;
	memset(f,0x3f,sizeof f);
	f[0] = 0;
	len = 0;
	for(int i = 1;i<=n;i++){
//		a[i] = -a[i];
		if(a[i] > f[len]) f[++len] = a[i];
		else{
			f[lower_bound(f,f+len+1,a[i]) - f] = a[i];
		}
	}
//	for(int i = 0; i <= len; i++){
//		cout << f[i] << " ";
//	}
	cout << len << endl;
	return 0;
}

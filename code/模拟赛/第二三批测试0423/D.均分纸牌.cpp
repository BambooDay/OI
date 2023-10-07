#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n;
int a[200];
int sum = 0;
ll ans = 0;
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n; i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	sum /= n;
	for(int i =1;i <= n; i++){
		if(a[i] != sum){
			a[i+1] -= sum-a[i];
			ans++;
		}
	}
	printf("%lld",ans); 
	return 0;
}

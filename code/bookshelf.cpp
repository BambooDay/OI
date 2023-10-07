#include <bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long b){
	if(x != b) return x>b;
	return x > b;
}
long long n,b,a[30000];
unsigned long long sum=0;
int main(){
	freopen("P2676_10.in","r",stdin);
	cin>>n>>b;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		sum=sum+a[i];
		
		if(sum>=b){
			cout<<i;
			break;
		}
	/*	b -= a[i];
		if(b <= 0){
			cout << i << endl;
			return 0;
		}*/
	}
	return 0;
}

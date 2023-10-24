#include <bits/stdc++.h>
const int N = 4e5+10;

using namespace std;
int n,a[N],b[N],ans;
bool get(int x, int y){
	if(x > y) return 0;
	int num = 0;
	for(int i = n,l=1,r=1;i;--i){
		while(l <= n && b[i]+b[l]<x)l++;
		while(r <= n && b[i]+b[r]<=y)r++;
		num+=r-l-(l<=i&&i<r);
	}
	return (num>>1)&1;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 0; i <= 25; i++){
		for(int j = 1; j <= n; j++){
			b[j]=a[j]%(1<<(i+1));
		}
		sort(b+1,b+n+1);
		int cnt = get(1<<i,(1<<(i+1))-1) ^ get(3<<i,(1<<(i+2))-2);
		ans += cnt*(1<<i);
	}	
	cout << ans;
	return 0;
} 

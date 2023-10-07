#include <bits/stdc++.h>
const int N = 1e6+10;
const int M = (1 << 20) + 3;
const int INF = 0x3f3f3f3f;

using namespace std;
bool cmp(long long x,long long b){
	if(x != b) return x > b;
} 
long long a[N],b;
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1; i <= n; i++){
		cout << a[i] <<" ";
	}
	return 0;
}

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 5e4+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n;
struct node{
	int l, r;
}a[N]; 
bool cmp(node x, node y){
	if(x.l != y.l){
		return x.l < y.l;
	}
	return x.r > y.r;
}

int main(){
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> a[i].l >> a[i].r;
	}
	sort(a+1,a+1+n,cmp);
	int L=a[1].l,R=a[1].r;
	for(int i =2;i <= n; i++){
		if(a[i].l <= R){
			R = max(a[i].r,R);
		}else{
			cout << "no";
			return 0;
		}
	}
	cout << L << " " << R;
	return 0;
}

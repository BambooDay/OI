#include <bits/stdc++.h>

using namespace std;
int n;
struct Node{
	int l, r;
}a[2000];
bool cmp(Node x, Node y){
	return x.l == y.l? x.r > y.r : x.l < y.l;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		 cin >> a[i].l >> a[i].r;
	}	
	sort(a+1,a+1+n,cmp);
	int cnt = n;
	int rmax = 0;
	for(int i = 1; i <= n; i++){
		if(a[i].r <= rmax) cnt--;
		else rmax = a[i].r;
	}
	cout << cnt;
	return 0;
}
/*
5
1 4
1 3
2 3
2 4
1 5
*/

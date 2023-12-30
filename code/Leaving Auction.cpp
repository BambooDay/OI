#include<bits/stdc++.h>
const int N = 2e5+10;

using namespace std;
struct Node {
	int num;
} b[N];
vector<int> a[N];
int n,m,q,x,y,lim[N],ll[N];
int cmp(Node xx,Node yy) {
	return a[xx.num][a[xx.num].size()-1]<a[yy.num][a[yy.num].size()-1];
}
int find(int k) {
	for(int i = k ; i >= 1; i--){
		if(!lim[b[i].num]) return i;
	}
	return 0;
}
int main() {
	cin >> n;
	for(int i = 0; i <= n; i++) a[i].push_back(0);
	for(int i = 1; i <= n; i++){
		cin >> x >> y;
		a[x].push_back(y);
		b[i].num = i;
	} 
	sort(b+1,b+1+n,cmp);
	cin >> m;
	while(m--) {
		cin >> q;
		for(int i = 1; i <= q; i++){
			cin >> ll[i];
			lim[ll[i]]=1;
		} 
		x = find(n);
		lim[b[x].num] = 1;
		y = find(x-1);
		lim[b[x].num] = 0;
		if(!a[b[x].num][a[b[x].num].size()-1]) puts("0 0");
		else cout << b[x].num << " " << *upper_bound(a[b[x].num].begin(),a[b[x].num].end(),a[b[y].num][a[b[y].num].size()-1]) << endl;
		for(int i = 1; i <= q; i++) lim[ll[i]] = 0;
	}
	return 0;
}


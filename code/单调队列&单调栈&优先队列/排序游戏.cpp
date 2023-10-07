#include <bits/stdc++.h>
const int N = 2e5+10;

using namespace std;
int n, m, a[N];
deque<pair<int,int> > q;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++){
		int r,t;
		cin >> t >> r;
		while(!q.empty() && q.back().first <= r) q.pop_back();
		if(q.empty() || q.back().second != t) q.push_back(make_pair(r,t));
		
	}	
	int r = q.front().first,t = q.front().second;
	if(t == 1){
		sort(a+1,a+1+r);
	}else{
		sort(a+1,a+1+r,cmp);
	}
	q.pop_front();
	while(!q.empty()){
		r = q.front().first,t = q.front().second;
		reverse(a+1,a+1+r);
		q.pop_front();
	}
	for(int i = 1;i <= n; i++) cout << a[i] << " ";
	return 0;
} 

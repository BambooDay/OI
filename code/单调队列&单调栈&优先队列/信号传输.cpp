#include <bits/stdc++.h>
const int N = 2e5+10;
using namespace std;
int n;
struct Node{
	int x, y;
	Node(){};
	Node(int _x,int _y) : x(_x),y(_y){};
}a[N];
bool cmp(Node x, Node y){
	return x.y > y.y;
}
set<pair<int,int> > s;
int main(){
	cin >> n;
	for(int i = 1;i <= n; i++) cin >> a[i].x >> a[i].y;
	sort(a+1,a+1+n,cmp);
	deque<Node> q;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int cnt = 0,cnt1 = 0; 
		while(!q.empty() && q.back().x > a[i].x){
			Node y = q.back();
			q.pop_back(),cnt++;
			cnt1 = s.upper_bound(make_pair(y.x,0))->second;
			s.insert(make_pair(y.x,cnt)); 
		}
		q.push_back(a[i]);
		pair<int,int> t = *s.upper_bound(make_pair(a[i].x,0));
//		cout << a[i].x << " "  << t.first << " " << t.second  << " " << cnt1 << endl; 
		ans += t.second + cnt - cnt1;
	}	
	cout << ans;
	return 0;
}
/*
8
1 1
2 7
3 4
4 2
5 5
6 8
7 6
8 3
*/

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 5000+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n;
double dis[N];
struct Node{
	double x, y;
}a[N];
double get(Node a, Node b){
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
bool v[N];

void dijstra(){
	priority_queue<pair<double,int>,vector<pair<double,int> > ,greater<pair<double,int> > > q;
	for(int i = 1; i <= n; i++){
		q.push(make_pair(dis[i],i));
	}	
	while(!q.empty()){
		int t = q.top().second;
//		cout << q.top().second << endl;
		q.pop();
		if(v[t]) continue;
		v[t] = 1;
//		cout << t << ' ';
		for(int i = 1; i <= n; i++){
			if(v[i]) continue;
			if(get(a[i],a[t]) < dis[i]){
				dis[i] = get(a[i],a[t]);
				q.push(make_pair(dis[i],i));
			}
		}
	}
}
int main(){
	cin >> n;
	for(int i =1; i <= n; i++) cin >> dis[i];
	for(int i = 1;i <= n; i++) cin >> a[i].x >> a[i].y;
	dijstra();
	double sum = 0;
	for(int i =1; i<= n; i++){
		sum += dis[i];
	}
	cout << fixed << setprecision(2)<< sum ;
	return 0;
}

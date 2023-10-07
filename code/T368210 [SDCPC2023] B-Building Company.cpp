#include <bits/stdc++.h>
#define ll long long
#define int long long
const int N = 1e6+10;
using namespace std;
map<ll,int> c;
int g,n;
ll a[N],tot = 0;
map<ll,int> ls;
vector<pair<int, int> > need[N], add[N];
int cnt[N];
priority_queue<pair<int,int> ,vector<pair<int,int> > , greater<pair<int,int> > > remain[N]; 
signed main(){
	cin >> g;
	for(int i = 1; i<= g; i++){
		int id,num;
		cin >> id >> num;
		c[id] = num;
		a[++tot] = id;
	}		
	cin >> n;
	queue<int> q;
	for(int i = 1;i <= n; i++){
		int m;
		cin >> m;
		cnt[i] = m;
		for(int j = 1; j <= m; j++){
			int id, num;
			cin >> id >> num;
			if(c[id] >= num){
				cnt[i]--;
				continue;
			}
			need[i].push_back(make_pair(id,num));
			a[++tot] = id;
		}
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int id, num;
			cin >> id >> num;
			add[i].push_back(make_pair(id,num));
			a[++tot] = id;
		}
	} 
	sort(a+1,a+1+tot);
	tot = unique(a+1,a+1+tot) - (a+1);
	for(int i = 1;i <= tot; i++){
		ls[a[i]] = i;
	}
	for(int i = 1;i <= n; i++){
		if(!cnt[i]){
			q.push(i);
		}else{
			for(auto j : need[i]){
				remain[ls[j.first]].push(make_pair(j.second,i));
			}
		}
	}
	int sum = 0;
	while(!q.empty()){
		sum++;
		int now = q.front();
		q.pop();
		for(auto i : add[now]){
			int id = ls[i.first],num = i.second;
			c[i.first] += num;
			num = c[i.first];
			while(!remain[id].empty() && remain[id].top().first <= num ){
				int x = remain[id].top().second;
				remain[id].pop();
				cnt[x]--;
				if(!cnt[x]){
					q.push(x);
				}
			}
		}
//		cout << now << endl;
	}
	cout << sum << endl;
	return 0;
}

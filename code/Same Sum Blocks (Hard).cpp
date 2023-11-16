#include<bits/stdc++.h>
#define int long long
const int N = 1505;

using namespace std;
int a[N];
int n;
unordered_map<int, vector<pair<int,int> > > m;
int sum[N];
bool cmp(pair<int,int> x, pair<int,int> y){
	return x.second < y.second;
}
signed main(){
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		sum[i] =sum[i-1]+a[i];		 
	}
	for(int i =1;i<= n; i++){
		for(int j = i; j <= n; j++){
			m[sum[j]-sum[i-1]].push_back({i,j});
		}
	}
	int ans,ma = 0;
	for(auto to : m){
//		cout << to.first << ": "<<endl;
		sort(to.second.begin(),to.second.end(),cmp);
		int cnt = 0;
		int r = 0;
		for(auto i : to.second){
			if(i.first > r){
				cnt++,r = i.second;
//				cout << i.first << " " << i.second << endl;
			} 
		}
		if(cnt > ma){
			ma = cnt;
			ans = to.first;
		}
	}	
	cout << ma << endl;
	int r = 0;
	sort(m[ans].begin(),m[ans].end(),cmp);
	for(auto i : m[ans]){
		if(i.first > r){
			cout << i.first << " " << i.second << endl;
			r = i.second;
		}	
	}
	return 0;
}

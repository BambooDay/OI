#include <bits/stdc++.h>
const int N = 5e5+10;
#define ll long long

using namespace std;
ll ans;
int a[N];
int n;
int mi;
void solve(){
	cin >> n;
	a[0] = 1e9;
	mi = 0;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		if(a[i] < a[mi]) mi = i;
	} 
	ans = a[mi];
	a[mi] = 0;
	queue<int> _2,_1,q;
	for(int i = 1; i<= n; i++){
		if(a[i] > 2) q.push(i);
		if(a[i] == 2) _2.push(i);
		if(a[i] == 1) _1.push(i);
	}
	while(!q.empty()||!_1.empty() ||!_2.empty()){
		//while(!q.empty() && a[q.front()] <= 2) q.pop();
		//while(!_2.empty() && a[_2.front()] < 2) _2.pop();
		//while(!_1.empty() && a[_1.front()] < 1) _1.pop();
		if(!q.empty()){
			a[q.front()] -= 2;
			if(a[q.front()] <= 2){
				int t = q.front();
				q.pop();
				if(a[t] == 1) _1.push(t);
				else if (a[t] == 2) _2.push(t);
			}
		}else if(!_2.empty()){
			a[_2.front()] -= 2;
			_2.pop();
		}else if(!_1.empty()){
			a[_1.front()] -= 2;
			_1.pop();
		}
		//for(int j = 1;j <= n; j++) cout << a[j] << "xxx" ;
		//cout << endl;
		if(!_1.empty()){
			ans++;
			a[_1.front()]--;
			_1.pop();
		}else if(!_2.empty()){
			ans += 2;
			a[_2.front()] -= 2;
			_2.pop();
		}else if(!q.empty()){
			ans += a[q.front()];
			a[q.front()] = 0;
			q.pop();
		}
		//for(int j = 1;j <= n; j++) cout << a[j] << ' ';
		//cout << endl;
	}
	cout << ans << endl;
}

int main(){
	freopen("Ale.in","r",stdin);
	freopen("Ale.out","w",stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
#include <bits/stdc++.h>
const int N = 2e5+10;

using namespace std;
int n;
int a[N];
int ans = -1;
int c[N];
int num = 0;
void dfs(int now,int cnt){
	num++;
//	cout << now  << " " << cnt << endl;
	if( now > n){
		int d[100];
		for(int i = 1; i < cnt; i++)d[i] = c[i];
		sort(d+1,d+cnt);
		ans = max(ans,d[cnt/2]);
		return;
	}
	if(now == n){
		c[cnt] = a[now];
		dfs(now+1,cnt+1);
		dfs(now+1,cnt);
		return;
	}
	c[cnt] = a[now];
	dfs(now+1,cnt+1);
	c[cnt] = a[now+1];
	dfs(now+2,cnt+1);
}
void sub1(){
	dfs(1,1);
//	cout << num << endl;
	cout << ans;
}
priority_queue<int> small;
priority_queue<int,vector<int>, greater<int> > big;
void sub2(){
	small.push(max(a[0],a[1]));
	int i = a[0] > a[1] ? 2:3;
	while(i < n){
		int x = a[i],y = a[i+1];
		if(x <= y){
			i += 2;
			if(y <= small.top()){
				small.push(y);
			}else{
				big.push(y);
			}
			if(small.size() < big.size()){
				int t = big.top();
				big.pop();
				small.push(t);
			}else if(small.size() > big.size()+1){
				int t = small.top();
				small.pop();
				big.push(t);
			}
		}else{
			i += 1;
			if(x <= small.top()){
				small.push(x);
			}else{
				big.push(x);
			}
			if(small.size() < big.size()){
				int t = big.top();
				big.pop();
				small.push(t);
			}else if(small.size() > big.size()+1){
				int t = small.top();
				small.pop();
				big.push(t);
			}			
		}
//		cout << i << endl;
	}
	cout << small.top();
	
}

void sub3(){
	int _1 = 0,_0 = 0;
	int i = 1;
	while(i <= n){
		if(a[i] == 1){
			_1++;
			i++;
		}else{
			if(a[i+1] == 1){
				_1++;
				i += 2;
			}else{
				_0++;
				i += 2;
			}
		}
	}
	if(_1 > _0) cout << 1;
	else cout << 0;
}
int main(){
	freopen("medium.in","r",stdin);
	freopen("medium.out","w",stdout);
	cin >> n;
	int flag = 0;
	for(int i = 1;i <= n; i++) {
		cin >> a[i];
		flag = max(flag, a[i]);
	}
	if(flag <= 1){
		sub3();
		return 0;
	}
	if(n == 1){
		cout << a[1];
		return 0;
	}
	if(n <= 30) sub1();
	else sub2();
	return 0;
}

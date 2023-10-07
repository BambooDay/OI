#include <bits/stdc++.h>
const int N = 2e5+10;
using namespace std;
int n;
priority_queue<int> q;
vector<int> t[N];
long long sum = 0;

int main(){
	cin >> n;
	for(int i  = 1;i <= n; i++){
		int a,b;
		cin >> a >> b;
		t[a].push_back(b);
		sum += b;
	}
	for(int i = 0; i <= n; i++){
		if(!q.empty()){
			sum -= q.top();
			q.pop();
		}
		for(int i:t[i]){
			q.push(i);
		}
	}
	cout << sum;
	return 0;
}

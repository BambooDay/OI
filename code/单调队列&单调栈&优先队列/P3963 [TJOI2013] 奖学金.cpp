#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,c,f,ans;
int suma[N],sumb[N];
//struct node{
//	int first,second;
//}a[N];
//bool cmp(node a, node b){
//	return a.first < b.first;
//}
pair<int,int> a[N];
priority_queue<int>q;
int main() {
	cin >> n >> c >> f;
	for(int i = 1; i <= c; i++) cin >> a[i].first >> a[i].second;
	sort(a+1,a+1+c);
	for(int i = 1; i <= n/2; i++){
		q.push(a[i].second);
		suma[i] = suma[i-1] + a[i].second;
	}
	for(int i = n/2+1; i <= c; i++) {
		if(a[i].second < q.top()){
			suma[i] = suma[i-1] - q.top() + a[i].second;
			q.pop();
			q.push(a[i].second);
		}else suma[i] = suma[i-1];
	}
	while(!q.empty()) q.pop();
	for(int i = c; i >= c-n/2+1; i--){
		q.push(a[i].second);
		sumb[i] = sumb[i+1]+a[i].second;
	}
	for(int i = c-n/2; i; i--){
		if(a[i].second < q.top()){
			sumb[i] = sumb[i+1] - q.top() + a[i].second;
			q.pop();
			q.push(a[i].second);
		}else sumb[i] = sumb[i+1];
	}
//	for(int i = 1;i <= n; i++){
//		cout << suma[i] << " " << sumb[i] << endl;
//	}
	for(int i = n/2+1; i <= c-n/2 ; i++){
		if(suma[i-1] + sumb[i+1] + a[i].second <= f){
			ans = a[i].first;
		}
	}
	printf("%d",ans!=0?ans:-1);
	return 0;
}


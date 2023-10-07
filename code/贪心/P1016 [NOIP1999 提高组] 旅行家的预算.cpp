#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n;
double d1,d2,c,d[10],p[10],ans = 0;
priority_queue<pair<double,double>,vector<pair<double,double> > ,greater<pair<double,double> > > q;//frist=cost second = s
int main(){
	cin >> d1 >> c >> d2 >> p[0] >> n;
	d[n+1] = d1;
	for(int i = 1; i <= n; i++){
		cin >> d[i] >> p[i];
		if(d[i] - d[i-1] > c*d2){
			cout << "No Solution" ;
			return 0;
		} 
	}
	if(d[n+1] - d[n] > c*d2){
		cout << "No Solution";
		return 0;
	}
	ans += p[0]*c;
	q.push(make_pair(p[0],c*d2));
	for(int i =1; i <= n+1; i++){
		auto t = q.top();
		q.pop();
		double delta = d[i] - d[i-1];
		while(delta){
			if(t.second <=delta){
				delta -= t.second;
				t = q.top();
				q.pop();
			}else{
				t.second -= delta;
				delta = 0;
			}
		}
		q.push(t);
		q.push(make_pair(p[i],c*d2));
		ans += p[i] * c;
	}
	while(!q.empty()){
		ans -= q.top().second / d2 * q.top().first;
		q.pop();
	}
	cout << setprecision(2) << fixed << ans << endl; 
	return 0;
}

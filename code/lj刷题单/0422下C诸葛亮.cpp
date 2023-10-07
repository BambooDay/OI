#include <bits/stdc++.h>
#pragma GCC optmize(3)
#define ll long long
#define ull unsigned long long
const int N = 1e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n, k;
long long a[N],sum1[N],sum2[N];
bool cmp(ll x, ll y){
	return x > y;
}
struct T{
	ll i, j, x;
	inline T(){}
	inline T(ll i, ll j) : i(i),j(j) {x = sum1[i]+sum2[j];}
	inline friend bool operator < (T a, T b){ return a.x < b.x;};
};
priority_queue<T> q;
int main(){
//	cin >> n >> k;
	scanf("%d%d",&n,&k);
	for(int i =1;i <= n; i++){
//		cin >> a[i];	
		scanf("%lld",&a[i]);
		sum1[i] = sum1[i-1]+a[i];
		sum2[i] = -sum1[i];
	}
	sort(sum1,sum1+n+1,cmp);
	sort(sum2,sum2+n+1,cmp);

	q.push(T(0,0));
	for(int x = 1; x <= k; x++){
//		cout << q.top().x << endl;
		printf("%d\n",q.top().x);
		ll i = q.top().i,j = q.top().j;
		q.pop();
		if(j == 0) q.push(T(i+1,j));
		q.push((T(i,j+1)));
	}
//	cout << q.top().x ;
	return 0;
}
/*
5 2
1 2 -1 -1 3
*/

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n,d[N],c[N];
int nxt[N][20],sum[N][20];
void init(){
	stack<int> st;
	for(int i = 1;i <= n; i++){
		while(!st.empty() && d[st.top()] < d[i]){
			nxt[st.top()][0] = i;
			sum[st.top()][0] = c[i];
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		nxt[st.top()][0] = 0;
		st.pop();
	}
	for(int j = 1; (1 << j) <= n; j++){
		for(int i = 1; i + (1 << j) <= n; i++){
			nxt[i][j] = nxt[nxt[i][j-1]][j-1];
			sum[i][j] = sum[i][j-1] + sum[nxt[i][j-1]][j-1];
		}
	}
}
int find(int pos, int v){
	if(v <= c[pos]){
		return pos;
	}
	v -= c[pos];
	for(int i = 17; i >= 0; i--){
		if(pos + (1 << i) > n) continue;
		if(nxt[pos][i] != 0 && v > sum[pos][i]){
			v -= sum[pos][i];
			pos = nxt[pos][i];
		}
	}
	return nxt[pos][0];
}
int q;
int main(){
	cin >> n >> q;
	for(int i = 1;i <= n; i++) cin >> d[i] >> c[i];
	init();	
	while(q--){
		int x, y;
		cin >> x>> y;
		cout << find(x,y) << endl;
	}
	return 0;
}

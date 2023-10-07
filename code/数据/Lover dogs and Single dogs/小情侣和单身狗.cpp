#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 5e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n, a[N];
int R[N];
stack <pair<int, int> > st;
int main(){
	//freopen("sample4.in","r",stdin);
	cin >> n;
	memset(R,0x3f,sizeof R);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i + a[i] > n){
			R[n] = min(R[n], i - a[i]);
		}else{	
			R[i + a[i]] = min(R[i + a[i]], i - a[i]);
		}
	}
	for(int i = 1; i <= n; i++){
		if(R[i] == INF) continue;
		while(!st.empty() && st.top().first >= R[i]){
			st.pop();
		}
		if(st.empty()){
			st.push(make_pair(1,i));
		}else{
			st.push(make_pair(st.top().second+1,i));
		}
	}
	//while(!st.empty()) cout << st.top().second << " ",st.pop();
	cout << st.size() << endl;
	return 0;
}
//10
//0 0 1 2 1 5 0 3 2 0 0

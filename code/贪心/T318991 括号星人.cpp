#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n;
struct se{
	string s;
	int w;
	int mi;
	int id;
	inline se(){}
	inline se(string s,int id):s(s),id(id){
		w = 0;
		mi = INF;
		for(int i = 0;i < s.size(); i++){
			if(s[i] == '(') w++;
			else w--;
			mi = min(mi,w);
		}
		mi = -mi;
	}
}node[N];
bool cmp(se x,se y){//w=delta,mi=limit
	if(x.w >= 0 && y.w >= 0) return x.mi < y.mi;
	if(x.w < 0 && y.w < 0) return x.w + x.mi > y.w + y.mi;
	return x.w > y.w;
}
int main(){
	cin >> n;
	for(int i =1;i <= n; i++){
		string s;
		cin >> s;
		node[i] = se(s,i);
	}
	sort(node+1,node+1+n,cmp);
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(cnt >= node[i].mi) cnt += node[i].w;
		else{
			puts("-1");
			return 0;
		}	
	}
	if(cnt){
		puts("-1");
		return 0;
	}
	for(int i =1;i <= n; i++){
		cout << node[i].id << " ";
	}
	
	return 0;
}

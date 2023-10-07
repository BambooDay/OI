#include <bits/stdc++.h>

using namespace std;
int n,letter[30],in[30],out[30],fa[30],cnt;
int st,en;
int vis[2000];
string s[2000];
string res[2000];
int find(int x){
	return fa[x] == x? x: fa[x] = find(fa[x]);
}
struct Node{
	int to,id;
	string word;
};
vector<Node> e[30];
bool cmp(string a, string b){
	return a < b;
}
void dfs(int step, int pos){
	if(step == n){
		for(int i = 1; i < n; i++){
			cout << res[i] <<'.';
		}
		cout << res[n];
		exit(0);
	}
	for(Node t : e[pos]){
		if(vis[t.id]) continue;
		vis[t.id] = 1;
		res[step+1] = t.word;
		dfs(step+1,t.to);
		vis[t.id] = 0;
	}
}
int main(){
	cin >> n;
	for(int i =1; i <= n; i++){
		cin >> s[i];
	} 
	sort(s+1,s+1+n,cmp);
	for(int i = 1; i <= n; i++){
		int start = s[i][0] - 'a'+1,endd = s[i][s[i].size()-1]-'a'+1;
		out[start]++;
		in[endd]++;
		if(!letter[start]){
			cnt++;
			letter[start] = 1;
			fa[start] = start;
		}
		if(!letter[endd]){
			cnt++;
			letter[endd] = 1;
			fa[endd] = endd;
		}
		if(start != endd){
			int stf = find(start),enf = find(endd);
			if(stf != enf){
				cnt--;
				fa[stf] = enf;
			}
		}
		Node tmp;
		tmp.to = endd;
		tmp.id = i;
		tmp.word = s[i];
		e[start].push_back(tmp);
	}
	if(cnt != 1){
		cout << "***";
		return 0;
	}
	for(int i =1; i <= 26; i++){
		if(!letter[i]) continue;
//		cout << char(i+'a'-1) << " " << out[i] << " " << in[i] << endl;
		if(out[i] == in[i]+1){
			if(st){
				cout << "***";
				return 0;
			}
			st = i;
		}else if(in[i] == out[i]+1){
			if(en){
				cout << "***";
				return 0;
			}
			en = i;
		}else if(in[i] == out[i]){
			continue;
		}else{
			cout << "***";
			return 0;
		}
	}
//	cout << st << ' ' << en << endl;
	if((st && !en) || (!st && en)){
//		cout << 1;
		cout << "***";
		return 0;
	}
	if(!st) st = s[1][0]-'a'+1;
	dfs(0,st);
	return 0;
} 

#include <bits/stdc++.h>

using namespace std;
int n;
vector<string> sj;
vector<string> hy;
bool ok[600];
bool check(string &x, string &y){
	if(x.size() > y.size()) return 0;
//			cout << 111 << endl;
	if(x.size() == 0){
		if(x == y) {
			y = "";
			return 1;
		}
		else return 0; 
	}
	for(int i = 0; i < x.size(); i++){
		if(x[i] != y[i]) return 0;
	}
	string t;
	for(int i = x.size(); i < y.size(); i++) t += y[i];
	y = t;
	return 1; 
}
int m = 0;
int main(){
	freopen("memory.in","r",stdin);
	freopen("memory.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		char op;
		string s;
		cin >> op >> s;
		for(int i = 0; i < m; i++) s += s[i];
		string t;
		for(int i= m; i < s.size(); i++) t += s[i];
		s = t;
//		cout << s << endl; 
		if(op == '+'){
			sj.push_back(s);
			vector<int> ans;
			for(int i = 0; i < hy.size(); i++){
				if(ok[i]) continue;
				while(true){
					bool flag = 1;
					for(int j = 0; j < sj.size(); j++){
						if(check(sj[j],hy[i])){
							flag = 0;
						}
					}
					if(flag) break;
				}
				if(hy[i] == "") ok[i] = 1,ans.push_back(i+1);
			}
			m = ans.size();
			cout << ans.size();
			for(int j : ans) cout  << " "<< j;
			cout << endl; 
		}else{
			hy.push_back(s);
			while(true){
				bool flag = 1;
				for(int i = 0; i < sj.size(); i++){
					if(check(sj[i],hy[hy.size()-1])) flag = 0;
				}
				if(flag) break;
			}
			if(hy[hy.size()-1] == ""){
				ok[hy.size()-1] = 1;
				m = 1;
				cout << 1 << " " <<  hy.size() << endl;
			}else{
				m = 0;
				cout << 0 << endl;
			}
		}
	}
	return 0;
}

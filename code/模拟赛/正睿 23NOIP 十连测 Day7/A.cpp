#include <bits/stdc++.h>
const int N = 2e5+10;

using namespace std;
string s;
int ans = 0,ans1 = 0;
stack<int> q;

int main(){
	freopen("del.in","r",stdin);
	freopen("del.out","w",stdout);
	double st = clock();
	cin >> s;
	for(int i = 0; i < s.size(); i++) q.push(s[i]-'0');
	while(q.size() > 1){
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		if(a+b >= 10)q.push(1),q.push(a+b-10);
		else q.push(a+b);
		ans1++;
	}
	
	while(s.size() > 1){
		string s1,s2;
		int ma = -1,pos = -1;
		for(int i = 0; i < s.size()-1; i++){
			if(s[i]-'0' + s[i+1]-'0' > ma) ma = s[i]-'0' + s[i+1]-'0',pos = i;
		}
		for(int i = 0; i < pos; i++) s1 += s[i];
		for(int i = pos+2; i < s.size(); i++) s2 += s[i];
		int x = s[pos]-'0' + s[pos+1]-'0';
		if(x < 10) s1 += char(x+'0');
		else{
			x %= 10;
			s1 += '1';
			s1 += char(x+'0');
		}
		ans++;
		s = s1 + s2;
//		cout << s << endl; 
		if(double(clock()-st)/CLOCKS_PER_SEC >= 0.9) break;
	}	
	cout << max(ans1,ans);
	return 0;
}

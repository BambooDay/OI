#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
string s;
stack<ll> st;
int main(){
	while(cin >> s){
		if(s[0]>= '0' && s[0] <= '9' || (s[0] == '-' && s[1] >= '0' && s[1] <= '9')){
			ll x = 0;
			for(int i = 0; i < s.size(); i++){
				if(s[0] == '-' && i == 0) continue;
				x = x * 10 + s[i]-'0';
			}
			if(s[0] == '-') x = -x;
			st.push(x);
		}else{
			ll ans = st.top();
			st.pop();
			for(int i = 0; i < s.size(); i++){
				if(s[i] == '+'){
					ans += st.top();
					st.pop();
				}
				if(s[i] == '*'){
					ans *= st.top();
					st.pop();
				}
				if(s[i] == '-'){
					ans = st.top() - ans;
					st.pop();
				}
				if(s[i]=='/'){
					ans = st.top()/ans;
					st.pop();
				}
				if(s[i] == '@'){
					cout<< ans;
					return 0;
				}
			}
		}
	}
	return 0;
}

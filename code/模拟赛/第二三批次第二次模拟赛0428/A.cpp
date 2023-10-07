#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int k;
string s;
char now;
int main(){
	cin >> k >> s;
	now = s[0];
	int cnt = 1;
	for(int i =1;i < s.size(); i++){
		if(cnt == k){
			cout << now;
			return 0;
		}
		if(now == s[i]){
			cnt++;
		}else{
			cnt = 1;
			now = s[i];
		}
	}
	cout << cnt;
	return 0;
}

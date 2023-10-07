#include <bits/stdc++.h>
const int N = 1e4+10;

using namespace std;
string s;
int cnt[N],dp[N],ne[N];
void kmp(int l, int len){
	string s1 = s.substr(l,len);
	ne[0] = ne[1] = 0;
	for(int i = 1; i < len;i++){
		int j = ne[i];
		while(j && s1[i] != s1[j]){
			j = ne[j];
		}
		ne[i+1] = s1[j]==s1[i]?j+1:0;
	}
}
int main(){
	cin >> s;
	int len = s.size();
	for(int i = 1;i <= len; i++){
		cnt[i] = cnt[i/10]+1;
		dp[i] = i+1;
	}	
	for(int i = 0; i < len; i++){
		kmp(i,len-i);
		for(int j = 1;j + i <= len; j++){
			if(j%(j-ne[j])== 0){
				dp[j+i] = min(dp[j+i],dp[i]+cnt[j/(j-ne[j])]+(j-ne[j]));
			}else{
				dp[j+i] = min(dp[j+i], dp[i]+1+j);
			}
		}
	}
	cout << dp[len];
	return 0;
}

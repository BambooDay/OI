#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 3e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
string s1,s2;
int n, m;
int a[N];
unsigned int sum[N],pre[N],ans;
int ne2[N],len[N];

int main(){
	cin >> n >> m;
	cin >> s1 >> s2;
	s1 = " " + s1;
	s2 = " " + s2;
	ne2[1] = 0;
	for(int i = 2; i <= m; i++){
		int p = ne2[i-1];
		while(p && s2[p+1] != s2[i]){
			p = ne2[p];
		}
		if(s2[p+1] == s2[i]) p++;
		ne2[i] = p;
	}
	int p = 0;
	for(int i = 1; i <= n; i++){
		while(p && s2[p+1] != s1[i]) p = ne2[p];
		if(s2[p+1] == s1[i]) p++;
		if(p == m) a[i-m+1] = 1;
	}
	int j = 1;
	for(int i = 2;i <= n;i++){
		int x = j * 2 - i;
		if(x <= 0) len[i] = 0;
		else len[i] = min(len[x],len[j] + j - i);
		while(s1[i + len[i] + 1] == s1[i - len[i] - 1] && i + len[i] + 1 <= n && i - len[i] - 1 >= 1){
			len[i]++;
		}
		if(i + len[i] > j + len[j]) j = i;
    }
    for(int i = 1;i <= n;i++){
		pre[i] = pre[i - 1] + a[i];
		sum[i] = sum[i - 1] + a[i] * i;
	}
	for(int i = 1;i <= n;i++){
		int l = i - len[i],r = i + len[i] - m + 1;
		if(l > r) continue;
		int mid = l + r >> 1;
		ans += (sum[mid] - sum[l - 1]) - (pre[mid] - pre[l - 1]) * (l - 1);
		if(mid != r) ans += (pre[r] - pre[mid]) * (r + 1) - (sum[r] - sum[mid]);
	}
	cout << ans;
	return 0;
}

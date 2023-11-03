#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define gc pa==pb&&(pb=(pa=buf)+fread(buf,1,100000,stdin),pa==pb)?EOF:*pa++
static char buf[100000],*pa(buf),*pb(buf);
inline LL readint() {
	LL x=0;char c=gc;
	while(c<'0'||c>'9')c=gc;
	for(;c>='0'&&c<='9';c=gc)x=x*10+(c&15);
	return x;
}

const int BASE = 65535;

int n,k;
int a[6][65536];
LL ans = 0;
signed main(){
	n=readint(),k=readint();
	for(int i = 1;i <= n; i++){
		LL x = readint();
		for(int j = 0; j < 4; j++){
			int y = x&BASE;
			a[j][y]++;
			x>>=16;
		}
	}
	for(int i = 0; i < 4; i++){
		for(int j = 0; j <= BASE;j++){
			if(a[i][j]%k == 1){
				ans += (1ll*j)<<(16*i);
			}
		}
	}
	cout << ans;
	return 0;
}

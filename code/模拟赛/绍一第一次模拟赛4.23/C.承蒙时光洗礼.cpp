#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
const int N = 5e3+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
ll dp[N];
bool step[N][N];
int n;
ll c,a[N],b[N];
signed main(){
	scanf("%d%lld",&n,&c);
	for(register int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
	}
	for(register int i = 1; i <=n; i++){
		scanf("%lld",&b[i]);
	}
	dp[1]= a[1]*b[1]%c;
	for(register int i = 1;i <= n; i++){
		for(register int j = 1; j <= n; j++){
//			dp[i][j] = a[i]*b[j]%c;
			if(dp[j-1] > dp[j]){
				dp[j] = dp[j-1] + a[i]*b[j]%c;
				step[i][j] = 1;
			}else{
				dp[j] += a[i]*b[j]%c;
			}
//			cout << step[i][j] << " ";
		}
//		cout << endl;
	}
//	cout << 1;
	int x = n, y = n;
	stack<char> op;
	while(x!=1||y!=1){
//		cout << step[x][y] << " ";
		if(step[x][y]){
			y--;
			op.push('R');
		}else{
			x--;
			op.push('D');
		}
	}
	while(!op.empty()){
		printf("%c",op.top());op.pop();
	}
	return 0;
}

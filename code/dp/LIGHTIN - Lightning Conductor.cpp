#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC target("abm,avx,mmx,popcnt,sse,sse2,sse3,sse4,ssse3,tune=native")
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
//#define int long long
#define rep(i, st, ed) for(int i = (st); i <= (ed); i++)
#define per(i, st, ed) for(int i = (st); i >= (ed); i--)

#define int long long
const int N = 5e5+10;

using namespace std;
int h[N],f[N],g[N];
int n;

signed main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> h[i];
	}	
	f[1] = h[1];
	for(int i = 2; i <= n; i++){
		f[i] = max(f[i-1],h[i]);
		for(int j = 0; j*j < i-1; j++){
			f[i] = max(f[i],h[i-1-(j*j)]+j+1);
		}
	}
	g[n] = h[n];
	for(int i = n-1; i; i--){
		g[i] = max(g[i+1],h[i]);
		for(int j = 0; j*j < n-i-1; j++){
			g[i] = max(g[i],h[i+(j*j)+1]+j+1);
		} 
	}
	for(int i = 1;i <= n; i++){
		cout << max(max(f[i],g[i]) - h[i],0ll) << '\n'; 
	}
	return 0;
}

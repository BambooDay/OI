#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
const int N = 1e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
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

using namespace std;
int h, n, w;
pair<int,int> node[N];
int fac[N<<1],ifac[N<<1];
int ksm(int a, int b){
	int res = 1;
	while(b){
		if(b & 1){
			res = res * a % mod;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}


void init(int ma){
	fac[0] = 1;
	for(int i = 1; i <= ma; i++){
		fac[i] = fac[i-1]*i % mod;
	}
	ifac[ma] = ksm(fac[ma],mod-2);
	for(int i = ma-1; i >= 0; i--){
		ifac[i] = ifac[i+1] * (i+1) % mod;
	}
}
int C(int n, int m){
	return fac[n] * ifac[m] %mod * ifac[n-m] % mod;
}
int f[N];
signed main(){
	cin >> h >> w >> n;
	for(int i = 1;i <= n; i++){
		cin >> node[i].first >> node[i].second;	
	}
	init((N-10) << 1);
	n++;
	sort(node+1,node+n);
	node[n].first = h,node[n].second = w;
	for(int i = 1;i <= n; i++){
		f[i] = C(node[i].first + node[i].second - 2, node[i].first-1);
		for(int j = 1; j < i; j++){
			if(node[j].first > node[i].first || node[j].second > node[i].second) continue;
			f[i] = (f[i] - f[j] * C(node[i].first - node[j].first + node[i].second - node[j].second,node[i].first - node[j].first) % mod + mod) % mod;
			 
		}
	}
	cout << f[n];
	return 0;
}
/*
5 5 5
3 1
3 2
3 3
4 3 
5 3
*/

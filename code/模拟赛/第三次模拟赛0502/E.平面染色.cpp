#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 3e5+10;
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
int n, m, t;
struct node{
	int x, y;
}a[N];
int up=0,down,le=0,ri;
ll sum = 0;
int main(){
	cin >> down >> ri >> t;
	sum = ri*2+down*2;
	for(int i = 1; i <= t; i++){
		int x, y;
		cin >> x >> y;
		if(y <= le || y >= ri || x <= up || x >= down){
			continue;
		}
		ll mi = INF;
		ll cnt1 = (x - up)*2+(ri-le);
		mi = min(cnt1,mi);
		ll cnt2 = (ri - x)*2+(ri-le);
		mi = min(cnt2,mi);
		ll cnt3 = (y-le) * 2 + (down-up);
		mi = min(cnt3,mi);
		ll cnt4 = (down-y)*2+(down-up);
		mi = min(cnt4,mi);
		sum -= mi;
		if(mi == cnt1){
//			cout << 1 << endl;
			up = x;
		}else if(mi == cnt2){
//			cout << 2<< endl;
			down = x;
		}else if(mi == cnt3){
//			cout << 3 << endl;
			le = y;
		}else{
//			cout << 4 << endl;
			ri = y;
		} 
	}
//	cout << up << " " << down << " " << le << " " << ri << " ";
	cout << (down - up) * 2 + (ri - le)*2;
	return 0;
}

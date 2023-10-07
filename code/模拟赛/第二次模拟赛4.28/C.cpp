#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 5e5 + 10;
const int M = 1e4 + 10;
const int INF = 0x3f3f3f3f;
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
string s;
int ne1[N], ne2[N];
int main() {
	cin >> s;
	int len = s.size();
	s = " " + s;
	ne1[1] = 0;
	for (int i = 2; i <= len; i++) {
		int p = ne1[i - 1];
		while (p && s[p + 1] != s[i]) p = ne1[p];
		if (s[p + 1] == s[i]) ne1[i] = p + 1;
		else ne1[i] = 0;
	}
	reverse(s.begin() + 1, s.end());

	ne2[1] = 0;
	for (int i = 2; i <= len; i++) {
		int p = ne2[i - 1];
		while (p && s[p + 1] != s[i]) p = ne2[p];
		if (s[p + 1] == s[i]) ne2[i] = p + 1;
		else ne2[i] = 0;
	}
	bool flag = 1;
	for (int i = 1; i <= len; i++) {
		if (s[i] != s[1]) {
			flag = 0;
		}
	}
	if (flag) {
		cout << len << endl << 1;
		return 0;
	}
	if (ne1[len] == 0 || len % (len - ne1[len]) != 0) {
		cout << 1 << endl << 1;
		return 0;
	}
	ll ans = 0;
	for (int i = 1; i <= len; i++) {
		int j = len - i;
		if ((ne1[i] == 0 || i % (i - ne1[i]) != 0) && (ne2[j] == 0 || j % (j - ne2[j]) != 0)) {
			ans++;
		}
	}
	cout << 2 << endl << ans;
	return 0;
}

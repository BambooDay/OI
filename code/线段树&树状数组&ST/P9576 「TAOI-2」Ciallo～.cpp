#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define ull unsigned long long
const ll N = 4e5 + 10;
const ull BASE = 13331;
ll lens, lent, tot,ans;
string s, t;
ull hs[N], ht[N], base[N];
vector<ll>pre[N], suf[N];
ull geths(ll l, ll r) {
	return hs[r] - hs[l - 1] * base[r - l + 1];
}
ull getht(ll l, ll r) {
	return ht[r] - ht[l - 1] * base[r - l + 1];
}
ll bitA[N];
void UpdA(ll x, ll k) {
	for (int i = x; i <= lens; i += (i & -i)) {
		bitA[i] += k;
	}
}
ll QueryA(ll x) {
	ll res = 0;
	for (int i = x; i; i -= (i & -i)) {
		res += bitA[i];
	}
	return res;
}
ll QuerysegA(ll l, ll r) {
	if (l > r)return 0;
	return QueryA(r) - QueryA(l - 1);
}
ll bitB[N];
void UpdB(ll x, ll k) {
	for (int i = x; i <= lens; i += (i & -i)) {
		bitB[i] += k;
	}
}
ll QueryB(ll x) {
	ll res = 0;
	for (int i = x; i; i -= (i & -i)) {
		res += bitB[i];
	}
	return res;
}
ll QuerysegB(ll l, ll r) {
	if (l > r)return 0;
	return QueryB(r) - QueryB(l - 1);
}
void UpdateA(ll x, ll k) {
	ll r = max(x - lent, 0ll);
	UpdA(x, k), tot += QuerysegB(1, r) * k;
//	cout << tot << endl;
}
void UpdateB(ll x, ll k) {
	ll l = min(x + lent, lens + 1);
	UpdB(x, k), tot += QuerysegA(l, lens) * k;
}
signed main() {
	cin >> s >> t;
	lens = s.size(), lent = t.size();
	s = " " + s, t = " " + t;
	if (lens < lent) {
		cout << 0 << endl;
		return  0;
	}
	base[0] = 1;
	for (int i = 1; i <= lens; i++) {
		base[i] = base[i - 1] * BASE;
	}
	for (int i = 1; i <= lens; i++) {
		hs[i] = hs[i - 1] * BASE + s[i];
	}
	for (int i = 1; i <= lent; i++) {
		ht[i] = ht[i - 1] * BASE + t[i];
	}
	for (int i = 1; i <= lens - lent + 1; i++) {
		if (geths(i, i + lent - 1) == getht(1, lent)) {
			ans += i * (i - 1) / 2 + (lens - i - lent + 2) * (lens - i - lent + 1) / 2;
		}
	}
//	cout << ans << endl;
	for (int i = 1; i <= lens; i++) {
		ll l = 1, r = min(lent, lens - i + 1);
		int cnt = 0;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			if (geths(i, i + mid - 1) == getht(1, mid)) {
				cnt = mid, l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		pre[cnt].push_back(i);
	}
	for (int i = 1; i <= lens; i++) {
		ll l = 1, r = min(lent, i);
		int cnt = 0;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			if (geths(i - mid + 1, i) == getht(lent - mid + 1, lent)) {
				cnt = mid, l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		suf[lent - cnt + 1].push_back(i);
	}
	for (int i = 1; i <= lens; i++) {
		UpdateB(i, 1);
	}
	for (ll x : suf[1])UpdateA(x, 1);
	for (int i = 1; i <= lent - 1; i++) {
		for (ll x : pre[i - 1]) {
			UpdateB(x, -1);
		}
		for (ll x : suf[i + 1]) {
			UpdateA(x, 1);
		}
//		cout << tot << endl;
		ans += tot;
	}
	cout << ans;
	return 0;
}

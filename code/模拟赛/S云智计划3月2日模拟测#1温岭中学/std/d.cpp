#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

const int N = 1.5e6 + 50;

inline int lc(int o) { return o << 1; }
inline int rc(int o) { return o << 1 | 1; }

char s[N];
int n, m, f[N], id[N], prv[N][26], nxt[N][26], lst[26];
std::vector<int> pos[26], app[26][26];

void init() {
	for (int i = 0; i < 26; ++i)
		pos[i].push_back(0);
	for (int i = 1; i <= n; ++i)
		pos[s[i] - 'a'].push_back(i);
	for (int i = 0; i < 26; ++i)
		pos[i].push_back(n + 1);
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j)
			app[i][j].resize(pos[i].size());
		for (int j = 0; j + 1 < pos[i].size(); ++j) {
			int l = pos[i][j] + 1, r = pos[i][j + 1] - 1;
			for (int k = l; k <= r; ++k)
				app[i][s[k] - 'a'][j] = 1;
		}
		for (int j = 0; j < pos[i].size(); ++j)
			id[pos[i][j]] = j;
	}
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j) {
			for (int k = 1; k < app[i][j].size(); ++k)
				app[i][j][k] += app[i][j][k - 1];
		}
	memset(lst, 0, sizeof lst);
	for (int i = 1; i <= n; ++i) {
		lst[s[i] - 'a'] = i;
		for (int j = 0; j < 26; ++j)
			prv[i][j] = lst[j];
	}
	memset(lst, 0x3f, sizeof lst);
	for (int i = n; i >= 1; --i) {
		lst[s[i] - 'a'] = i;
		for (int j = 0; j < 26; ++j)
			nxt[i][j] = lst[j];
	}
}
bool check(int l, int r) {
	for (int j = 0; j < 26; ++j)
		if (j != s[l] - 'a')
			if (nxt[l][j] <= r)
				return true;
	return false;
}
void solve(int l, int r) {
	if (!check(l, r)) {
    	printf("1 %c%c\n", s[l], s[l] == 'a' ? 'b' : 'a');
		return;
	}
	std::tuple<int, int, int> ans = std::make_tuple(-1, -1, -1);
	for (int c = 0; c < 26; ++c) {
		int bl = nxt[l][c], br = prv[r][c];
		if (bl > br) continue;
		int id_l = id[bl], id_r = id[br];
		for (int j = 0; j < c; ++j) {
			if (c == j) continue;
			int cur = app[c][j][id_r - 1] - (bl == 0 ? 0 : app[c][j][id_l - 1]);
			int ret = 2 * cur;
			++ret;
			if (nxt[br][j] <= r) {
				++ret;
			}
			int _a = -c, _b = -j;
			if (prv[bl][j] >= l) {
				++ret;
				std::swap(_a, _b);
			}
			ans = std::max(ans, std::make_tuple(ret, _a, _b));
		}
	}
	auto [len, x, y] = ans;
	printf("%d %c%c\n", len, 'a' + (char)(-x), 'a' + (char)(-y));
}

int main() {
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	init();
	scanf("%d", &m);
	while (m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		solve(l, r);
	}
}


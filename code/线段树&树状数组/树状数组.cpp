#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6 + 10;
const int M = 1e6+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int c[N + 10];
int  num[N],res[N];

int n, m;
int v[N];
struct question{
	int l, r,pos;
}ask[M];
bool cmp(question x,question y){
	return x.r < y.r;
}
void modify(int x, int y) {
	for (int i = x; i <= n; i += (i & -i)) {
		c[i] += y;
	}
}

int find(int x) {
	int ans = 0;
	for (int i = x; i > 0; i -= (i & -i)) {
		ans += c[i];
	}
	return ans;
}

ll sum;
int cnt[N];
int main() {
	

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &num[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &ask[i].l, &ask[i].r);
		ask[i].pos = i;
	}
	sort(ask + 1, ask + 1 + m, cmp); 
	int next = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = next; j <= ask[i].r; j++) {
			if (v[num[j]])
				modify(v[num[j]], -1);
			modify(j, 1);
			v[num[j]] = j;
		}
		next = ask[i].r + 1;
		res[ask[i].pos] = find(ask[i].r) - find(ask[i].l - 1);
	}
	for (int i = 1; i <= m; i++)
		cout << res[i] << endl;
	return 0;
}

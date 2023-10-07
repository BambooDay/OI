#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9 + 7;

int T, n;
struct node{ int v, w; } nd[N];
long long cant[N], can[N];
int idx1, idx2;

bool cmp(node x, node y)
{
	if(x.w == y.w) return x.v < y.v;
	return x.w < y.w;
}

bool check(int x)
{
	idx1 = idx2 = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(nd[i].v < x) cant[ ++ idx1] = nd[i].w;
		else can[ ++ idx2] = nd[i].v + nd[i].w - x;
	}
	if(idx1 > idx2) return false;
	sort(can + 1, can + 1 + idx2);
	int i1 = 1, i2 = 1;
	for(; i1 <= idx1 ; i1 ++)
	{
		while(i2 <= idx2 && can[i2] < cant[i1]) i2 ++;
		if(i2 > idx2) return false;
		i2 ++;
	}
	if(i1 > idx1) return true;
	return false;
}

int main()
{
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while(T --)
	{
		cin >> n;
		int l = INF, r = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			cin >> nd[i].v >> nd[i].w;
			l = min(l, nd[i].v);
			r = max(r, nd[i].v);
		}
		sort(nd + 1, nd + 1 + n, cmp);
		int ans;
		while(l <= r)
		{
			int mid = (l + r) >> 1;
			if(check(mid)) l = mid + 1, ans = mid;
			else r = mid - 1;
		}
		cout << ans << "\n";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 505; 
const int M = 3e5 + 5;

int T, n, m, ans;
int A[N], B[N], vis[N];
int e[M], ne[M], h[N], idx;
double w[M];

void add(int a, int b, double c)
{
	e[ ++ idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx;
}

void dfs(int x, double t)
{
	ans ++; vis[x] = 1;
	for(int i = h[x] ; i ; i = ne[i])
	{
		int y = e[i];
		if(vis[y]) continue;
		if(w[i] >= t) dfs(y, w[i]);
	}
}

int main()
{

	freopen("animal.in", "r", stdin);
	freopen("animal.ans", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while(T --)
	{
		cin >> n >> m;
		idx = 0; for(int i = 1 ; i <= n ; i ++) h[i] = vis[i] = 0;
		for(int i = 1 ; i <= n ; i ++) cin >> A[i];
		for(int i = 1 ; i <= n ; i ++) cin >> B[i];
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = i + 1 ; j <= n ; j ++)
			{
				if(A[i] == A[j])
				{
					add(i, j, 0);
					add(j, i, 0);
				}
				else
				{
					if(B[i] != B[j])
					{
						double t = (A[j] - A[i]) * 1.0 / (B[i] - B[j]);
						if(t > 0) 
						{
							add(i, j, t);
							add(j, i, t);
						}
					}
				}
			}
		}
		ans = 0;
		dfs(m, 0);
		cout << ans << "\n";
	}

	return 0;
}

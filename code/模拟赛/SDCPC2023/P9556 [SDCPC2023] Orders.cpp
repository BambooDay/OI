#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll T, n, k;
struct node{
	ll tim, w;
} nd[105];

bool cmp(node x, node y)
{
	return  x.tim < y.tim;
}

int main()
{
	
	cin >> T;
	while(T --)
	{
		cin >> n >> k;
		for(int i = 1 ; i <= n; i ++)
		{
			cin >> nd[i].tim >> nd[i].w;
		}
		nd[n + 1] = {0, 0};
		sort(nd + 1, nd + 1 + n, cmp);
		ll s = 0; bool flag = 1;
		for(int i = 1 ; i <= n ; i ++)
		{
			s += (nd[i].tim - nd[i - 1].tim) * k;
			if(s < nd[i].w)
			{
				flag = 0;
				break;
			}
			else s -= nd[i].w;
		}
		if(flag) cout << "Yes\n";
		else cout << "No\n";
	}
	
	return 0;
}

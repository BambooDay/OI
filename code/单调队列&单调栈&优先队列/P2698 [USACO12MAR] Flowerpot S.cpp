#include <bits/stdc++.h>
const int N = 1e5 + 10;
#define int long long
using namespace std;
int n, d, ans;
struct Node {
	int x, y;
} a[N];
bool cmp(Node x, Node y) {
	return x.x < y.x;
}
int p1[N], p2[N];
int head1, head2, tail1, tail2;

signed main() {
//	freopen("P2698_3.in","r",stdin);
	cin >> n >> d;
	for (int i = 1; i <= n; i++)	{
		cin >> a[i].x >> a[i].y;
	}
	sort(a + 1, a + 1 + n, cmp);
	ans = 1e18;
	head1 = head2 = 1;
	for (int le = 0, r = 0; le <= n; le++) { 
		while (head1 <= tail1 && p1[head1] < le) head1++; 
		while (head2 <= tail2 && p2[head2] < le) head2++; 
		while (a[p1[head1]].y - a[p2[head2]].y < d && r < n) {
			r++;
			while (head1 <= tail1 && a[p1[tail1]].y < a[r].y) tail1--;
			p1[++tail1] = r;
			while (head2 <= tail2 && a[p2[tail2]].y > a[r].y) tail2--;
			p2[++tail2] = r; 
		}
		if (r != n) ans = min(ans, a[r].x - a[le].x); 
	}
	if(ans >= 1e18){
		cout << -1;
	}else{
		cout << ans;
	}
	return 0;
}
/*
30 100
67 102
72 108
69 86
90 99
11 29
29 31
29 52
93 128
13 39
40 66
11 53
15 35
93 99
62 85
98 122
62 82
63 89
84 121
56 79
49 70
67 96
21 40
62 89
22 30
96 127
82 112
86 128
83 119
77 92
91 121

*/

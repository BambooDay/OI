#include <bits/stdc++.h>
using namespace std;

int s1, s2;
int f[105][105];

void work(int x)
{
	if(x % 3 == 1) s1 += x;
	else s2 += x;
}

int main()
{
	
	for(int i = 1 ; i <= 6 ; i ++)
	{
		for(int j = 1 ; j <= 6 ; j ++)
		{
			for(int k = 1 ; k <= 6 ; k ++)
			{
				s1 = s2 = 0;
				work(i); work(j); work(k);
				f[s1][s2] = 1;
			}
		}
	} 
	int a, b;
	cin >> a >> b;
	if(f[a][b]) cout << "Yes";
	else cout << "No";
	return 0;
}

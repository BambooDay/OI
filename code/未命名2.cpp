#include<bits/stdc++.h>

using namespace std;


int n, ans[15], mp[26];
char s[15][15][3];

inline bool check(int x, int y) {
	int sum = ans[x] + ans[y];
	int cur = s[x][y][1] - 'A';
	if (sum >= n - 1 && mp[cur] != 1) return 0;
	if (sum >= n - 1) sum -= n - 1, cur = s[x][y][2] - 'A';
	if (mp[cur] != sum) return 0;
	return 1;
}

int main() {
	cin >> n;
	for (int j = 1; j <= n; j++) {
		scanf("%s", s[1][j] + 1);
	}
	for (int i = 2; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			scanf("%s", s[i][j] + 1);
			cnt += strlen(s[i][j] + 1) >= 2;
		}
		ans[i] = cnt;
		mp[s[i][1][1] - 'A'] = cnt;
	}
	for (int i = 2; i <= n; i++){
		for (int j = 2; j <= n; j++){
			if (!check(i, j)){
				puts("ERROR!");
				return 0;
			} 
		} 
	} 
	for (int i = 2; i <= n; i++){
		 printf("%c=%d ", s[i][1][1], ans[i]);
	}
	printf("\n%d", n - 1);
	return 0;
}

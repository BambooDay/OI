#include <bits/stdc++.h>
const int N = 2e6+2e5;

using namespace std;
int k;
string s;
int A[N],B[N],C[N];
int po[20];
int main(){
	cin >> k;
	cin >> s;
	s = " " + s + s;
	po[0] = 1;
	for(int i = 1; i <= 10; i++){
		po[i] = po[i-1] * 4;
	}
	int n = po[k];
	for(int i = 1; i <= n*2; i++){
		A[i] = A[i-1] + (s[i] == 'A');
		B[i] = B[i-1] + (s[i] == 'B');
		C[i] = C[i-1] + (s[i] == 'C');
	}
	int ans = 0x3f3f3f3f;
	for(int r = n; r <= n*2; r++){
		int now = 0;//0 C 1 B 2 A
		int l = r-1;
		int cnt = 0;
		while(r - l < n){
			if(now % 3 == 0){
//				cout <<  pow(4,now/3) - C[l] + C[l-(int)pow(4,now/3)] << endl;
				cnt += po[now/3] - C[l] + C[l-po[now/3]];
			}
			if(now % 3 == 1){
				cnt += po[now/3] - B[l] + B[l-po[now/3]];
			}
			if(now % 3 == 2){
				cnt += po[now/3] - A[l] + A[l-po[now/3]];
			}
//			cout << l << " " << l-pow(4,now/3) << " " << cnt<< endl;
			l -= po[now/3];
			now++;
			if(cnt > ans) break;
		}
		ans = min(ans,cnt);
//		cout << ans << endl;
//		return 0;
	}
	cout << ans << endl;
	return 0;
}
/*
2
ABCAABABCBABBBCA
*/

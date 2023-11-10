#include <bits/stdc++.h>
const int N = 2e6+10;
using namespace std;
bool m[9][N];
int n;
int ans = 0;
int num;
int a[8];
int po[8];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin >> n;
	//if(n == 1){
	//	cout << 81 << endl;
	//	return 0;
	//}
	po[0] = 1;
	for(int i =1;i <= 5; i++) po[i] = po[i-1]*10;
	for(int i = 100000; i < 200000; i++) m[0][i] = 1;
	for(int id = 1; id <= n; id++){
		ans = 0;
		num = 1;
		for(int i = 4; i >= 0; i--){
			cin >> a[i];
			num = num*10 + a[i];
		}
		for(int i = 0; i < 5; i++){
			for(int j = 1; j <= 9; j++){
				int num1 = num - a[i] *  po[i] +((a[i]+j) % 10)*po[i];
				if(m[id-1][num1]){
					m[id][num1] = 1;
					ans++;
				}
			}
		}
		for(int i = 0; i < 4; i++){
			for(int j = 1; j <= 9; j++){
				int num1 = num -a[i]*po[i] + ((a[i]+j)%10) * po[i]-a[i+1]*po[i+1] + ((a[i+1]+j)%10) * po[i+1];
				if(m[id-1][num1]){
					m[id][num1] = 1;
					ans++;
				}
			}
		}
	}
	cout<< ans << endl;
	return 0;
}
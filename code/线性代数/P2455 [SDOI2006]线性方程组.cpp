#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6 + 10;
const int M = 1e4 + 10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n;
double a[200][200];
double eps = 1e-6;
int gauss() {
	for (int i = 1; i <= n; i++) {
		int pos = 1;
		while (pos <= n) {
			if(fabs(a[pos][pos]) > eps && pos < i) pos++;
			else if(fabs(a[pos][i]) < eps) pos++;
			else break;
		}
//	for(int i = 1;i <= n; i++){
//		for(int j = 1; j <= n+1; j++){
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//		cout << pos << endl;
		if (pos > n) continue;
		if (pos != i) {
			for (int j = 1; j <=  n + 1; j++) {
				swap(a[i][j], a[pos][j]);
			}
		}
		double t = a[i][i];
		for (int j = 1; j <= n + 1; j++) {
			a[i][j] /= t;
		}
		for (int j = 1; j <= n; j++) {
			if (j == i) continue;
			t = a[j][i];
			for (int k = 1; k <= n + 1; k++) {
				a[j][k] -= a[i][k] * t;
			}

		}
	}
	bool flag1=false,flag2=false;
    for(int i=1;i<=n;i++){
        bool flag=true;
        for(int j=1;j<=n && flag;j++){
			if(fabs(a[i][j])>=eps) flag=false;
		}
        if(flag){
            if(fabs(a[i][n+1])>=eps) flag1=true;
            else flag2=true;
        }
    }

    if(flag1) return -1;
    else if(flag2) return 0;
    else return 1;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n + 1; j++) {
			cin >> a[i][j];
		}
	}
	int p = gauss();

	if(p == 1){
		for (int i = 1; i <= n; i++) {
			cout << 'x' << i << '='; 
			cout << setprecision(2) << fixed << a[i][n + 1] << endl;
		}
	}else{
		cout  << p;
	}
	return 0;
}

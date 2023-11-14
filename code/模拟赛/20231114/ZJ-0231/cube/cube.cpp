#include <bits/stdc++.h>
#define int long long
const int N = 1e6+10;
using namespace std;
int x[N],y[N],z[N];
int n;
int X,Y,Z;
signed main(){
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> x[i] >> y[i] >> z[i];
	}
	sort(x+1,x+1+n);
	sort(y+1,y+1+n);
	sort(z+1,z+1+n);

	X = n/(x[n]-x[1]+1);
	if(n%X){
		cout << "NO";
		return 0;
	}
	for(int i = 1; i+X <= n; i+=X){
		for(int j = i; j < i+X; j++){
			if(x[j] != x[i]){
				cout << "NO";
				return 0;
			}
		}
	}
	Y = n/(y[n]-y[1]+1);
	if(n%Y){
		cout << "NO";
		return 0;
	}
	for(int i = 1; i+Y <= n; i+=Y){
		for(int j = i; j < i+Y; j++){
			if(y[j] != y[i]){
				cout << "NO";
				return 0;
			}
		}
	}
	Z = n/(z[n]-z[1]+1);
	if(n%Z){
		cout << "NO";
		return 0;
	}
	for(int i = 1; i+Z <= n; i+=Z){
		for(int j = i; j < i+Z; j++){
			if(z[j] != z[i]){
				cout << "NO";
				return 0;
			}
		}
	}
	//cout << X << " " << Y << " " << Z<< endl;
	X = x[n]-x[1]+1;
	Y = y[n]-y[1]+1;
	Z = z[n]-z[1]+1;
	if(X*Y*Z != n){
		cout << "NO";
		return 0;
	}
	cout << "YES";
	return 0;
}
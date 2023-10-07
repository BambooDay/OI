#include <bits/stdc++.h>
const int N = 2e5+10;

using namespace std;
int n;
map<int,bool> ma,mi;
int a[N];
int ans1 = 0,ans2 = 0;
int main(){
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout); 
	cin >> n;
	for(int i = 1;i <= n; i++) cin >> a[i];
	sort(a+1,a+1+n);
	for(int i = 1; i <= n; i++){
		int x = a[i];
		if(mi.count(x) || mi.count(x+1) || mi.count(x-1)) continue;
//		cout << x << endl;
		ans1++;
		mi[x+1] = 1;
	} 
	cout << ans1 << " ";
	for(int i = 1; i <= n; i++){
		int x = a[i];
		if(!ma.count(x-1)){
			ans2++;
			ma[x-1] = 1;
//			cout << x-1 << " xx ";
		}else if(!ma.count(x)){
			ans2++;
//			cout << x<< " xx ";
			ma[x] =1;
		}else if(!ma.count(x+1)){
			ans2++;
//			cout << x+1 << " xx "; 
			ma[x+1] = 1;
		}
	}
	cout << ans2;
	return 0;
}
/*
10
1 1 1 2 2 3 4 5 6 7
*/

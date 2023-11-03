#include <bits/stdc++.h>
const int N = 3*60+10;

using namespace std;
pair<int,int> a[N];
int n;

int main(){
	srand(time(0));
	cin >> n;
	for(int i = 1; i <= n*3; i++){
		cin >> a[i].first;
		a[i].second = i;
	} 
	sort(a+1,a+1+n*3);
	while(true){
		int x = 0,y = 0,z = 0;
		random_shuffle(a+n+1,a+1+n*3);
		int cnt = 0;
		for(int i = n+1; i <= n+n; i++){
			y += a[i].first;
		}
		for(int i = n+n+1; i <= n+n+n; i++){
			z += a[i].first;
		}
//		cout << x << " " << z << " " << x+z << endl;
		if(y <= n*1000/2 || z <= n*1000/2) continue;
		for(int i = 1; i <= n*3; i++){
			cout << a[i].second << endl;
		}
//		cout << 111111111 << endl;
		return 0;
	}	
	return 0;
}

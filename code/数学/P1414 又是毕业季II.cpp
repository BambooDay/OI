#include <bits/stdc++.h>

using namespace std;
int n,t = 0,c[1000006];

int main(){
	cin >> n;
	for(int i =1;i <= n; i++){
		int x;
		cin >> x;
		t = max(t,x);
		for(int i = 1;i*i <= x; i++){
			if(x%i == 0){
				c[i]++;
				if(x != i*i) c[x/i]++;
			}
		}
	}
	int x = t;
	for(int i = 1;i <= n; i++){
		while(c[x] < i) x--;
		cout << x << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll u,v;

int main(){
	cin >> u >> v;
	ll delta = v - u;
	if(delta < 0 || delta & 1){
		cout << -1;
		return 0;
	}
	if(!delta){
		if(!u) cout << 0;
		else cout << "1\n" << u;
	}else{
		ll half = delta >> 1;
		if(half & u){
			cout << "3\n" << half << " " << half << " " << u; 
		}else{
			cout << "2\n" << half << " " << (half^u);
		}
	}
	return 0;
}

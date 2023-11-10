#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int nn;
queue<int> q; 
signed main(){
	cin >> n;
    for(int i = 2;i*i <= n;i++){
		while(n%i == 0){	
			q.push(i);
			n /= i;
		}
	}
    if(n != 1) q.push(n);
    if(q.size()==2)puts("2");
    else if(q.size()==1)cout <<"1\n0";
	else{
        puts("1");
        int ans = q.front();
        q.pop();
        cout << ans*q.front();
    }
	return 0;
}

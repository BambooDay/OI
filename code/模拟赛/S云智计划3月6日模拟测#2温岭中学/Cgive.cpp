#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("graph.in","r",stdin);
	int n;
	cin >> n;
	if(n == 2e6){
		freopen("check.ans","w",stdout);
		cout << "NO" << endl;
	}
	freopen("graph.in","w",stdout);
	cout << n+1;	
	return 0;
}

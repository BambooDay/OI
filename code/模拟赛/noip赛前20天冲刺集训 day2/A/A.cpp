#include <bits/stdc++.h>

using namespace std;
int a,b;
int build(int dep, int now){
	if(dep == b) return now;
	if(dep == 0){
		cout << now << " " << now+1 << endl;
		cout << now << " " << now+2 << endl;
		cout << now << " " << now+3 << endl;
		return build(dep+1,now+3);
	}
	cout << now << " " << now+1 << endl;
	cout << now << " " << now+2 << endl;
	return build(dep+1,now+2);
}
//int c[100];
int main(){
	//cout << sizeof c << endl;
	freopen("A3_6.in","r",stdin);
	freopen("A3_6.out","w",stdout);
	cin >> a >> b;
	if(b == 0){
		if(a == 3 || a == 1){
			cout << 0 << endl;
			return 0;
		}
		cout << a+1 << endl;
		for(int i = 2; i <= a+1; i++){
			cout << 1 << " " << i << endl;
		}
		return 0;
	}
	if(a < 3+b-1 + 2 && a != 3+b-1){
		cout << 0 << endl;
		return 0;
	}
	cout << a-(3+b-2)+2+b*2 << endl;
	int now = build(0,1);
	for(int i = now+1,j = 1; j <= a-(3+b-2); j++,i++){
		cout << now << " " << i << endl;
	}
	return 0;
}

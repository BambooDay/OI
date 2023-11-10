#include <bits/stdc++.h>

using namespace std;
bool  check(int x){
	for(int i = 2;i*i <= x; i++){
		if(x%i == 0) return 0;
	}
	return 1;
}
int n;

int main(){
	freopen("D.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n; i++){
		char now = 'A'+i-1;
		int cnt = 0;
		int j = 1;
		while(cnt < i*i){
			if(check(j+now)){
				cout << now;
				cnt++;
				now++;
				if(now > 'Z') now = 'A';
			}else cout << " ";
			j++;
		} 
		cout << endl;
	}
	return 0;
}

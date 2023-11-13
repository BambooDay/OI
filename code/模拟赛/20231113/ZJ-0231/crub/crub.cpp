#include <bits/stdc++.h>
const int N = 250;

using namespace std;
char mp[N][N];
int a,b,c;
void solve(){
	cin >> a >> b >> c;
	for(int i = 1; i <= c*2+b*2+1; i++){
		for(int j = 1; j <= a*2+b*2+1;j++){
			mp[i][j] = '.';
		}
	}
	/*
	*/
	for(int i = c*2+b*2+1,v = 1; i > b*2+1; i--){
		for(int j = 1; j <= a*2; j+=2){
			if(v == 1){
				mp[i][j] = '+';
				mp[i][j+1] = '-';
			}else{
				mp[i][j] = '|';
				mp[i][j+1] = '.';
			}
		}
		v^=1;
	}
	for(int i = a*2+1,v = 1,cnt = 0;i <= a*2+b*2+1; i++,v^=1,cnt++){
		for(int j = c*2+b*2+1-cnt; j >= b*2+1-cnt; j -= 2){
			if(v == 1){
				mp[j][i] = '+';
				mp[j-1][i] = '|';
			}else{
				mp[j][i] = '/';
				mp[j-1][i] = '.';
			}
		}
	}
	for(int i = b*2+1,v = 1,cnt = 0; i; i--,cnt++,v^=1){
		for(int j = 1+cnt; j <= a*2+cnt; j += 2){
			if(v == 1){
				mp[i][j] = '+';
				mp[i][j+1] = '-';
			}else{
				mp[i][j] = '/';
				mp[i][j+1] = '.';
			}
		}
	}
	/*
	*/

	for(int i = 1; i <= c*2+b*2+1; i++){
		for(int j = 1; j <= a*2+b*2+1;j++){
			cout << mp[i][j];
		}
		cout << endl;
	}
}
int main(){
	freopen("crub.in","r",stdin);
	freopen("crub.out","w",stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}

/*

....+-+-+-+-+-+-   +
..././././././.   /|
..+-+-+-+-+-+-   +.+
././././././.   /|/|
+-+-+-+-+-+-   +.+.+
|.|.|.|.|.|.   |/|/|
+-+-+-+-+-+-   +.+.+
|.|.|.|.|.|.   |/|/|
+-+-+-+-+-+-   +.+.+
|.|.|.|.|.|.   |/|/.
+-+-+-+-+-+-   +.+..
|.|.|.|.|.|.   |/...
+-+-+-+-+-+-   +....
c*2+b*2+1      a*2+b*2+1
*/

#include <bits/stdc++.h>

using namespace std;
int a[10][10];
bool v[10];
void check(int x, int y){
	memset(v,0,sizeof v);
	for(int i = x; i < x+3; i++){
		for(int j = y; j < y+3; j++){
			if(v[a[i][j]]){
				puts("No");
				exit(0);
			}	
			v[a[i][j]] = 1;
		} 
	}
}
int main(){
	for(int i = 1; i <= 9; i++){
		for(int j = 1;j <= 9; j++){
			cin >> a[i][j];
		}
	}	
	for(int i = 1;i <= 9; i++){
		memset(v,0,sizeof v);
		for(int j = 1; j <= 9; j++){
			if(v[a[i][j]]){
				puts("No");
				return 0;
			}	
			v[a[i][j]] = 1;
		}
	}
	for(int j = 1;j <= 9; j++){
		memset(v,0,sizeof v);
		for(int i = 1; i <= 9; i++){
			if(v[a[i][j]]){
				puts("No");
				return 0;
			}	
			v[a[i][j]] = 1;
		}
	}
	check(1,1);
	check(4,1);
	check(7,1);
	check(1,4);
	check(4,4);
	check(7,4);
	check(1,7);
	check(4,7);
	check(7,7);
	puts("Yes");
	return 0;
}

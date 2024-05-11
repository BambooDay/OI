#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

int main(){
	bool flag = 1;
	do{
		system("D:\\snake\\give.exe");	
		system("D:\\snake\\std.exe");	
		freopen("snake.out","r",stdin);
		int t,len;
		cin >> t >> len;
		if(t > 1000&&t < 2000) flag = 0; 
	}while(flag);
	return 0;
}

#include <bits/stdc++.h>
const long long N = 1e15+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
char arr[300][30],alphabet[26] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
int main(){
	srand(time(0)); 
	freopen("AK019.in","w",stdout);
	int t = rand() % 10+5;
	while(t--){
	int n = rand() % 500;
	cout << n << endl;
	for(int i = 1; i <= n; i++){
		long long m = 0;
		while(m <= 0){
			m = rand() % 26;
		}
		m = 1;
		cout<< m << " ";
		map<int,bool> x;
		int j;
		for (j=0; j<m; j++){
			int y = rand()%26;
			if(!x.count(y)){
				arr[i][j] = alphabet[y];
				x[y] = 1;
			}else{
				j--;
			}
        }
        arr[i][j] = '\0';
        printf("%s\n", arr[i]); 
		}
	}
	
	return 0;
}

//![](https://cdn.luogu.com.cn/upload/image_hosting/m37doan5.png)


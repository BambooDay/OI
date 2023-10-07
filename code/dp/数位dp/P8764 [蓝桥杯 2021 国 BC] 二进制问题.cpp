/*
记忆化搜索解决数位 dp 问题，首先将数的上界进行拆位，存到一个数组里面，然后按位考虑
所有需要考虑的性质以及用到的值都可以丢到 dfs 的参数里面，为了保证复杂度，使用 dp 数组进行记忆化


*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[70],len = 0;//a 数组：拆位 len：一共有几位 
int dp[70][70];//dp[i][j] : 当前填到第 i 位，前面一共填了 j 个 1
int dfs(/*bool lead0 此题不用考虑前导零的问题*/ int pos, int cnt, int limit){//把需要考虑的东西都丢到这个里面就行 
	/*pos 当前填到第几位（从高位往低位填）
	  cnt 前面已经填了几个 1，我们只关心填了几个1，并不关心时怎么填的 
	  limit前面的位数是否是顶着上界填的，如果是，这一位肯定就不能随便填 
	*/
	if(!pos){//已经把所有位数都填完了 
//	cout << cnt << endl;
		return (cnt == k);
	}
	int &now = dp[pos][cnt];
	if(now != -1 && !limit){//如果没有限制且当前位置被搜过了 
		return now;
	}
	int res = 0;
	int up = limit ? a[pos]:1;//当前能枚举到的上界 
	for(int i = 0; i <= up; i++){
		res += dfs(pos-1,cnt+i,limit && i == up); 
	}
	if(!limit){//记录记忆化 
		now = res;
	}
	return res; 
}
void solve(int n){
	while(n){//进行拆位，拆位的作用是知晓当前位置数的上界，进行dfs时有一个限制 
		a[++len] = n &1;
		n >>= 1;
	}
	memset(dp,-1,sizeof dp);//一般习惯赋成-1 
	 cout << dfs(len,0,1);
}
signed main(){
//	int n;
	cin >> n>>k;
	solve(n);	
	return 0;
}

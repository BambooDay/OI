#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int n,vis[5005],l,len[5005],t[5005],cnt;
string str[5005]; 
void dfs(int x){
	if(l>26||cnt) return;
	for(int i=0;i<len[x];i++) t[str[x][i]-'a'+1]++;
	if(l==26) {
		int flag=0;
		for(int i=1;i<=26;i++) {
			if(t[i]!=1){
				flag=1;
				break;
			}
		}
		if(flag){
			cout << "YES" << endl;
			cnt=1;
		}
	}else{
		int flag=1;
		for(int i=1;i<=26;i++){
			if(t[i]==2){
				flag=0;
				break;
			}
		}
		if(flag){
			for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			vis[i]=1;
			l+=len[i];
			dfs(i);
			l-=len[i];
			vis[i]=0;
			if(cnt) break;
			}
		}
	} 
	for(int i=0;i<len[x];i++) t[str[x][i]-'a'+1]--;
}

clock_t start,en;
int main(){
	freopen("AK.in","r",stdin);
	freopen("AK.out","w",stdout);
	start=clock();	
	cin >> n;
	for(int i=1;i<=n;i++) cin >> len[i] >> str[i];	
	for(int i=1;i<=n;i++){
		vis[i]=1;
		l+=len[i];
		dfs(i);
		l-=len[i];
		vis[i]=0;
		if(cnt) {
			en = clock();
			double endtime=(double)(en-start)/CLOCKS_PER_SEC;
			cout<<endtime*1000<<endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	en = clock();
	double endtime=(double)(en-start)/CLOCKS_PER_SEC;
	cout<<endtime*1000<<endl;
	return 0;
}

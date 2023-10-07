#include<bits/stdc++.h>
using namespace std;
int n,a,b,siz;
struct P{
	int r,c,h,w;
}p[100005];
void dfs(int w){
	if(w==2){
		if(a==1&&b==1)	p[++siz]={2,2,-1,-1};
		else if(a==1&&b==2)	p[++siz]={2,1,-1,1};
		else if(a==2&&b==1)	p[++siz]={1,2,1,-1};
		else p[++siz]={1,1,1,1};
		return ;
	}
	if(w==a){
		for(int i=1;i<b;i++){
			p[++siz]={a-i,b-i,i,i};
		}
		for(int i=b;i<a;i++){
			p[++siz]={a-i,i+1,i,-i};
		}
		return ;
	}
	else if(w==b){
		for(int i=1;i<a;i++){
			p[++siz]={a-i,b-i,i,i};
		}
		for(int i=a;i<b;i++){
			p[++siz]={i+1,b-i,-i,i};
		}
		return ;
	}
	else{
		p[++siz]={w,w,-w+1,-w+1};
		dfs(w-1);
	}
} 
int main(){
	cin>>n>>a>>b;
	cout<<"Yes\n";
	if(n==1){
		cout<<"0";
		return 0;
	}
	dfs(n);
	cout<<siz<<"\n";
	for(int i=1;i<=siz;i++){
		cout<<p[i].r<<" "<<p[i].c<<" "<<p[i].h<<" "<<p[i].w<<"\n"; 
	}
	return 0;
}

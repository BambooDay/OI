#include <bits/stdc++.h>
const int N = 1e6+10;
using namespace std;
string pre[N];
struct Node{
	string s;
	vector<int> id;
}node[N];
bool cmp(Node x, Node y){
	for(int i = 0; i < x.s.size(); i++){
		if(x.s[i] != y.s[i]){
			return x.s[i] < y.s[i];
		}
	}
}
int n;
char ch[N];
int cnt = 0;
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> ch[++cnt];
//		cout << ch[cnt];
		if(ch[cnt] == ch[cnt-1]){
			node[--cnt].id.push_back(i);
		}else{
			node[cnt].id.push_back(i);
		}
	}	
	deque<int> q;
	q.push_front(cnt);
	for(int i = cnt-1; i > 0;i--){
		if(ch[i] > ch[i+1]) q.push_front(i);
		else q.push_back(i);
	}
	while(!q.empty()){
		int x = q.front();
		q.pop_front();
		for(int i : node[x].id){
			cout << i <<' ';
		}		
	}

	return 0;
}

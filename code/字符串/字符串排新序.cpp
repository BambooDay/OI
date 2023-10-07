#include <bits/stdc++.h>
#define ll long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
map<char,int> order;
int n;
string s[1005];
bool cmp(string a, string b){
	for(int i = 0; i <= min(a.size(),b.size());i++){
		if(a[i] != b[i]){
			return order[a[i]] < order[b[i]]; 
		}
	}
	return a.size() < b.size();
	//return 0;
}
int main(){
	scanf("%d",&n);
	char c;
	for(int i = 1; i <= 26; i++){
		std::cin >> c;
		order[c] = i;
	}
	for(int i = 1; i <= n; i++){
		std::cin >> s[i];
	}
	sort(s+1,s+1+n,cmp);
	for(int i = 1; i <= n; i++){
		std::cout << s[i] << std::endl;
	}
	return 0;
}


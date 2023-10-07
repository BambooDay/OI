#include <bits/stdc++.h>

using namespace std;
int n;
void solve1(){
//	int n;
	string s;
	cin >> s;
	s = " " + s + " ";
	vector<pair<int,int> > seg;
	int ans = 0;
	int l = 0, r = -1,l1 = 0,r1 = -1;
	for(int i = 1;i <= n; i++){
		if(s[i] == 'T' && (i == 1 || s[i-1] != s[i])){
			l1 = i;
		}
		if(s[i] == 'T' && (i == n || s[i+1] != s[i])){
			r1 = i;
			if(r1 - l1 + 3 <= ans) continue;
			int cnt = 0;
			for(int j = l1-1; j>=4; j-=2){
				if(s[j-1] == 'T' && s[j-2] == 'T' && s[j-3] == 'B'){
	//		cout << l <<" xx " << r << endl;
					cnt++;
					break;
				}
				if(s[j-1] =='T' && s[j-2] != 'B'){
					break;
				}
				if(s[j-1] != 'T') break;
			}
			for(int j = r1+1; j <= n-3; j+=2){
	//			cout << j << " " << s[j+1] << s[j+2] << s[j+3] << endl;
				if(s[j+1] == 'T' && s[j+2] == 'T'&& s[j+3] == 'B'){
	//		cout << l <<" " << r << endl;
					cnt++;
					break;
				}
				if(s[j+1] == 'T' && s[j+2] != 'B') break;
				if(s[j+1] != 'T') break;
			}
			ans = max(ans,r1-l1+1+cnt);
//			if(r1 - l1+1 == r-l+1){
//				seg.push_back(make_pair(l1,r1));
//			}
//			if(r1 - l1+1 > r-l+1){
//				seg.clear();
//				r = r1,l = l1;
//				seg.push_back(make_pair(l,r));
//			}
		}
	}
	cout << ans << endl;
return;
/*
	if(r - l + 1 == 1){
		puts("1");
		return;
	}
	if(r1 == -1){
		puts("0");
		return;
	}
	int ans = r1-l1+1;
	for(auto i : seg){
		l = i.first,r = i.second;
//		cout << l << " " << r << endl;
		int cnt = 0;
		for(int j = l-1; j>=4; j-=2){
			if(s[j-1] == 'T' && s[j-2] == 'T' && s[j-3] == 'B'){
//		cout << l <<" xx " << r << endl;
				cnt++;
				break;
			}
			if(s[j-1] =='T' && s[j-2] != 'B'){
				break;
			}
			if(s[j-1] != 'T') break;
		}
		for(int j = r+1; j <= n-3; j+=2){
//			cout << j << " " << s[j+1] << s[j+2] << s[j+3] << endl;
			if(s[j+1] == 'T' && s[j+2] == 'T'&& s[j+3] == 'B'){
//		cout << l <<" " << r << endl;
				cnt++;
				break;
			}
			if(s[j+1] == 'T' && s[j+2] != 'B') break;
			if(s[j+1] != 'T') break;
		}
		if(cnt == 2){
			ans = r-l+3;
			break;
		}
		ans = max(ans,r-l+1+cnt);
	}
	cout << ans << endl;*/
}
void solve2(){
//	int n;
	string s;
	cin  >> s;
	s = " " + s + " ";
	vector<pair<int,int> > seg;
	int l = 0, r = -1,l1 = 0,r1 = -1;
	for(int i = 1;i <= n; i++){
		if(s[i] == 'T' && (i == 1 || s[i-1] != s[i])){
			l1 = i;
		}
		if(s[i] == 'T' && (i == n || s[i+1] != s[i])){
			r1 = i;
			if(r1 - l1+1 == r-l+1){
				seg.push_back(make_pair(l1,r1));
			}
			if(r1 - l1+1 > r-l+1){
				seg.clear();
				r = r1,l = l1;
				seg.push_back(make_pair(l,r));
			}
		}
	}
//	cout << r-l+1 << endl;
//return;
	if(r - l + 1 == 1){
		puts("1");
		return;
	}
	if(r1 == -1){
		puts("0");
		return;
	}
	int ans = r1-l1+1;
	for(auto i : seg){
		l = i.first,r = i.second;
//		cout << l << " " << r << endl;
		int cnt = 0;
		for(int j = l-1; j>=4; j-=2){
			if(s[j-1] == 'T' && s[j-2] == 'T' && s[j-3] == 'B'){
//		cout << l <<" xx " << r << endl;
				cnt++;
				break;
			}
			if(s[j-1] =='T' && s[j-2] != 'B'){
				break;
			}
			if(s[j-1] != 'T') break;
		}
		for(int j = r+1; j <= n-3; j+=2){
//			cout << j << " " << s[j+1] << s[j+2] << s[j+3] << endl;
			if(s[j+1] == 'T' && s[j+2] == 'T'&& s[j+3] == 'B'){
//		cout << l <<" " << r << endl;
				cnt++;
				break;
			}
			if(s[j+1] == 'T' && s[j+2] != 'B') break;
			if(s[j+1] != 'T') break;
		}
		if(cnt == 2){
			ans = r-l+3;
			break;
		}
		ans = max(ans,r-l+1+cnt);
	}
	cout << ans << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		if(n >= 5000){
			solve2();	
		}else{
			solve1();
		}
	}
	return 0;
}
// TBTBTTTBTBTTBTBTBTTTBTBTTBTTTBTBT 

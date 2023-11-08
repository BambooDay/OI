#include <bits/stdc++.h>

using namespace std;
pair <string,double> sc[]=
{
    make_pair("H",1),
    make_pair("C",12),
    make_pair("N",14),
    make_pair("O",16),
    make_pair("F",19),
    make_pair("Na",23),
    make_pair("Mg",24),
    make_pair("Al",27),
    make_pair("Si",28),
    make_pair("P",31),
    make_pair("S",32),
    make_pair("Cl",35.5),
    make_pair("K",39),
    make_pair("Ca",40),
    make_pair("Mn",55),
    make_pair("Fe",56),
    make_pair("Cu",64),
    make_pair("Zn",65),
    make_pair("Ag",108),
    make_pair("I",127),
    make_pair("Ba",137),
    make_pair("Hf",178.5),
    make_pair("Pt",195),
    make_pair("Au",197),
    make_pair("Hg",201),
};
string s;
int ans = 0;
void water(){
	int pos = s.find('~');
	if(pos != -1){
		int tot = 0;
		for(int i = pos+1;isdigit(s[i]); i++){
			tot = tot*10+s[i]-48;
		}
		if(tot == 0) tot = 1;
		ans = ans+tot*18.0;
		s.erase(pos,12);
	}
}
double get(string s){
	for(int i = 0; ;i++){
		if(s == sc[i].first) return sc[i].second;
	}
}
double solve(int x){
	double sum = 0,now = 0;;
	while(s[x] != ')'){
		if(s[x] >= 'A' && s[x] <= 'Z'){
			sum += now;
			now = 0;
			if(s[x+1] >= 'a' && s[x+1] <= 'z'){
				now = get(s.substr(x,2));
				x += 2;
			}else{
				now = get(s.substr(x,1));
				x++;
			}
		}else if(s[x] == '('){
			sum += now;
			now = solve(x+1);
			while(s[x] != ')') x++;
			x++;
		}else{
			x += 2;
			int c = 0;
			while(isdigit(s[x])) c=c*10+s[x++]-48;
			now *= c;
			x++;
		}
	}
	return sum + now;
} 
int main(){
	cin >> s;
	water();
	s += ')';
	cout << ans+solve(0);
	return 0;
}

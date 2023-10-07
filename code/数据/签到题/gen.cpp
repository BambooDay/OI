#include <bits/stdc++.h>

using namespace std;

fstream f;
const int M = 2e6;
std::mt19937 eng(time(0));
std::uniform_int_distribution<int> dist_int(1, 1000000000);


void buildSteps(int n){
	f << n << endl;
	for(int i=1; i<=n; i++){
		f << i;
		for(int j=1; j<=i; j++)
			f << " " << j;
		f << endl;
	}
}

int getCnt(int n, int k, int dep){
	int ret = 0;
	while(dep --){
		ret += n;
		n = (n + k - 1) / k;
	}
	return ret;
}

struct Event{
	int len;
	vector<int> cont;
	int dep;
	int rnd;
	Event(int len=0, vector<int> cont=vector<int>{}, int dep=0)
		:len(len), cont(cont), dep(dep) {
			rnd = dist_int(eng);
		}
	bool operator < (const Event& e) const{
		if(len != e.len)
			return len > e.len;
		return rnd > e.rnd;
	}
	void print(){
		f << len;
		for(int x: cont)
			f << " " << x;
		f << endl;
	}
};

priority_queue<Event> PQ;
vector<Event> es;
void mergeList(int n, int k, int dep){
	// n = min(n, M / dep);
	int l = 0, r = n + 1;
	int N = n;
	while(l < r - 1){
		int m = (l + r) >> 1;
		if(getCnt(m, k, dep) <= n)
			l = m;
		else
			r = m;
	}
	n = l;
	cerr << N << " " << k << " " << dep << " " << n << endl;
	while(!PQ.empty())
		PQ.pop();
	es.clear();
	for(int i=1; i<=n; i++){
		Event e(1, vector<int>{i}, 1);
		PQ.push(e); es.push_back(e);
	}
	while(PQ.size() > 1 && es.size() < N){
		Event en;
		int p = k;
		while(p -- && !PQ.empty()){
			Event e = PQ.top(); PQ.pop();
			en.cont.insert(en.cont.end(), e.cont.begin(), e.cont.end());
			en.len += e.len;
			en.dep = max(en.dep, e.dep + 1);
		}
		es.push_back(en);
		if(en.dep < dep)
			PQ.push(en);
	}
	if(dist_int(eng) >= 100000000){
		cerr << es.back().cont.size() << endl;
		shuffle(es.back().cont.begin(), es.back().cont.end(), eng);
		es.back().cont.pop_back();
		-- es.back().len;
	}
	while(es.size() < N)
		es.push_back(Event(0));
	int m = 0, mn = 0;
	for(auto x: es){
		if(x.len != x.cont.size())
			cerr << "ERROR" << endl;
		m += x.len;
		mn = max(mn, x.len);
	}
	cerr << "m = " << m << " " << mn << endl;
	shuffle(es.begin(), es.end(), eng);
	f << es.size() << endl;
	for(auto x: es)
		x.print();
}

int main(){
	int subt = 11, tskl = 1, tskr = 1;
	const int maxns[5] = {300, 1000, 5000, 50000, 200000};
	for(int tsk=tskl; tsk<=tskr; tsk++){
		f.open((string() + "sign" + to_string(subt) + ".in").c_str(), ios::out);
		f << 5 << endl;
//		int n = maxns[min(subt-1, 4)];
		int n = 50;
		if(subt == 5){
			mergeList(n, 2, 2);
			mergeList(n, 2, 3);
			mergeList(n, 3, 2);
			mergeList(n, 3, 3);
			mergeList(n, 10, 2);
		}
		else{
			buildSteps(min(n, 1999));
			mergeList(n, 2, 2);
			mergeList(n, 2, 3);
			int lg2n = log(n) / log(2) + 1;
			mergeList(n, 2, lg2n);
			mergeList(n, sqrt(n), 3);
			// for subtask 6 - 2
//			int lg2n = log(n) / log(2) + 1;
//			 mergeList(n, 2, lg2n);
//			 mergeList(n, 2, lg2n);
//			 mergeList(n, 2, lg2n);
//			 mergeList(n, 2, lg2n);
//			 mergeList(n, 2, lg2n);
		}
		f.close();
	}
	for(int j=tskl; j<=tskr; j++){
		cerr << "(" << subt << ", " << j << ")" << endl;
		system((string() + "std.exe < sign" + to_string(subt) + ".in > sign" + to_string(subt) + ".out").c_str());
		// system((string() + "fc string" + to_string(i) + "_" + to_string(j) + ".out string" + to_string(i) + "_" + to_string(j) + ".test").c_str());
	}
}


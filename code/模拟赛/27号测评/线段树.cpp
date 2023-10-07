#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;
const int mod = 1e9+7;
#define ls(fa) fa << 1
#define rs(fa) fa << 1 | 1
using namespace std;

struct Matrix{
	int a[3][3];
	const int size = 2;
	Matrix(){
		memset(a,0,sizeof a);
	}
	Matrix(int x){
		a[x][x] = 1;
		a[x+1][x+1] = 1;
		a[x][x+1] = 0;
		a[x+1][x] = 0;
	}

	Matrix(int A,int B, int C, int D){
		a[1][1] = A;
		a[1][2] = B;
		a[2][1] = C;
		a[2][2] = D;
	}

	Matrix operator *(const Matrix b){
		Matrix ans;
		for(int i = 1; i <= 2; i++){
			for(int j = 1; j<= 2; j++){
				for(int k = 1; k <= 2; k++){
					ans.a[i][j] = (ans.a[i][j] + a[i][k]*b.a[k][j]) % mod;
				}
			}
		}
		return ans;
	}

	Matrix operator +(const Matrix c){
		Matrix res;
		for(int i = 1; i <= 2; i++){
			for(int j = 1;j <= 2; j++){
				res.a[i][j] = (a[i][j] + c.a[i][j]) % mod;
			}
		}
		return res;
	}

	void operator =(const Matrix A){
		for(int i = 1; i <= 2; i++){
			for(int j = 1;j <= 2; j++){
				a[i][j] = A.a[i][j];
			}
		}
	}

	bool empty(){
		return (!a[1][1])&&(!a[1][2])&&(!a[2][1])&&(!a[2][2]);
	}
	Matrix operator ^(int b){
		Matrix res(1);
		Matrix base = (*this);
		while(b){
			if(b&1){
				res = res*base;
			}
			base = base*base;
			b >>= 1; 
		}
		return res;
	} 
};

Matrix node[N<<2],tag[N<<2];
int v[N];
const Matrix unit(1);
int n, m;

void push_up(int pos){
	node[pos] = node[ls(pos)]+ node[rs(pos)];
}

void build(int pos, int l, int r){
	tag[pos] = unit;
	if(l == r){
		node[pos] = Matrix(1,1,0,0)*(Matrix(1,1,1,0)^(v[l]-1));
		return;
	}
	int mid = (l+r) >> 1;
	build(ls(pos),l,mid);
	build(rs(pos),mid+1,r);
	push_up(pos);
}

void push_down(int pos){
	if(tag[pos].empty()) return;
	node[ls(pos)] = node[ls(pos)] * tag[pos];
	tag[ls(pos)] = tag[ls(pos)] * tag[pos];
	node[rs(pos)] =  node[rs(pos)] *tag[pos];
	tag[rs(pos)] = tag[rs(pos)] * tag[pos];
	tag[pos] = unit;
}

void update(int pos, int l, int r, int x, int y, Matrix z){
	if(x <= l && y >= r){
		node[pos] = node[pos] * z;
		tag[pos] = tag[pos] * z;
		return;
	}
	push_down(pos);
	int mid = (l+r) >> 1;
	if(x <= mid){
		update(ls(pos),l,mid,x,y,z);
	}
	if(mid < y){
		update(rs(pos),mid+1,r,x,y,z);
	}
	push_up(pos);
}
Matrix query(int pos, int l, int r, int x, int y){
	if(x <= l && y >= r){
		return node[pos];
	}
	push_down(pos);
	Matrix res;
	int mid = (l+r) >> 1;
	if(x <= mid){
		res = res + query(ls(pos),l,mid,x,y);
	}
	if(y > mid){
		res = res + query(rs(pos),mid+1,r,x,y);
	}
	return res;
}

signed main(){
//	freopen("T4.in","r",stdin);
	cin >> n >>m;
	for(int i = 1;i <= n; i++){
		cin >> v[i];
	}
	build(1,1,n);
	while(m--){
		int op;
		cin >> op;
		if(op == 1){
			int x,y,z;
			cin >> x >> y >> z;
			update(1,1,n,x,y,Matrix(1,1,1,0) ^ z);
		}else{
			int x,y;
			cin >> x >>y;
			cout << (query(1,1,n,x,y).a[1][2] % mod) << endl;
		}
	}

	return 0;
}

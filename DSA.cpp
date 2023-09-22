#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 10000000;
bool nt[maxn + 1];
int MOD = 1e9+7;
// sang so nguyen to
void sang(){
	for(int i =0; i <= maxn; i++){
		nt[i] = true;
	}
	nt[0] = nt[1] = false;
	for(int i = 2; i <= sqrt(maxn); i++){
		if(nt[i]){
			for(int j = i*i; j <= maxn ; j += i){
				nt[j] = false;
			}
		}
	}
}

// sang so nguyen to tren doan

void sang2(int l, int r){
	bool nt[r - l + 1];
	for(int i = 0 ; i <= r - l; i++){
		nt[i] = true;
	}
	for(int i = 2; i <=sqrt(r); i++){
		for(int j = max(i*i, (l+i-1)/i*i); j <= r; j+=i){
			cout << j << ' ' << l << endl;
			cout << j - l << endl;
			nt[j - l] = false;
		}
	}
	cout << "========================================" << endl;
	for(int i = max(2, l); i <= r; i++){
		if(nt[i-l]){
			cout << i << ' ' << l << endl;
			cout << i - l << endl;
			cout << i << ' ' << endl;
		}
	}
}

// a^b%c tim chu so tan cung

ll powMod(ll a, ll b, ll c){
	ll res = 1;
	a %= c;
	while(b){
		if(b % 2 == 1){
			res *=a;
			res %=c;
		}
		a *=a;
		a %= c;
		b/=2;
	}
	return res;
}



// fibo
ll fibo(int n){
	ll f[n+1];
	f[0] = 0;
	f[1] = 1;
	for(int i = 2; i <= n; i++){
		f[n] = f[n-1] + f[n-2];
		f[n] %= MOD;
	}	
	return f[n] % MOD;
}

// luy thua nhi phan

ll binpow(int a , int b){
	if(b == 0) return 1;
	ll x = binpow(a , b/2);
	if(b % 2 == 0) return x*x*a;
	else return x*x;
}

// luy thua nhi phan 2
ll binpow2(int a, int b){
	ll res = 1;
	while(b != 0){
		if(b % 2 == 1){
			res *= a;
		}
		b /= 2;
		a *= a;
	}
	return res;
}

// tim so chinh phuong trong doan
void t_prime(){
	sang();
	int l, r; cin >> l >> r;
	int c1 = sqrt(l);
	int c2 = sqrt(r);
	int cnt = 0;
	if(1ll*c1*c1 != l ) ++c1;
	for(int i = c1; i <= c2;i++){
		if(nt[i]){
			++cnt;
		}
	}
	cout << cnt;

}

// so hoan hoa
ll hh[100];
int cnt = 0;
void init(){
	for(int i = 2; i <= 32; i++){
		if(nt[i]){
			int tmp = (int)pow(2, i)-1;
			if(nt[tmp]){
				hh[cnt] = 1ll*tmp*(int)pow(2,i-1);
				++cnt;
			}
		}
	}
}


// tim bao nhieu so cung nguyen to vs so da cho
int phi(ll n){
	ll res = n;
	for(int i = 2; i <= sqrt(n);i++){
		if(n % i ==0){
			res = res - res/i;
			while(n%i == 0) n /=i;
		}
	}
	if(n > 1) res -= res/n;
	return res ;
}

// to hop chap k cua n
ll C[1001][1001];
// c[i][j] luu to hop chap j cua i
void init1(){
	for(int i = 0; i <=1000 ; i++){
		for(int j = 0; j <= i;j++){
			if(j == 0 || j == i){
				C[i][j] = 1; 
			}
			else{
				C[i][j] = C[i-1][j-1] + C[i-1][j];
				C[i][j] %= 1000000007;
			}
		}
	}
}

// Etended eculid algorithm

int x, y ,g;
void extended_gcd(ll a, ll b){
	if(b==0){
		x = 1;
		y = 0;
		g = a;
	}
	else {
		extended_gcd(b, a%b);
		// da co x1, y1 : x, y
		int tmp = x; // x1
		x = y; // x = y1
		y = tmp - a/b*y;
	}

}
//O(log(max(a,m)))
int modular_inverse(int a, int m){
	extended_gcd(a,m);
	return (x%m+m)%m;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("lck1.in", "r", stdin);
	freopen("lck2.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init1();
	int n, k;
	cin >> n >> k;
	cout << C[n][k]; 
	
}
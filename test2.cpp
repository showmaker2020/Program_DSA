#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int cnt1[10000001];
int cnt2[10000001];

using ll = long long ;

int ucln(int a, int b)
{   
   if(b==0) return a;
   return ucln(b, a%b);
}

bool nt(int n){
   for(int i = 2; i <= sqrt(n); i++){
       if(n %i == 0) return 0;
   } 
    return 1;
}

bool shh(ll n){
   for(int p =1; p <= 32;p++){
       if(nt(p)){
           ll tmp = (ll)pow(2,p)-1;
           if(nt(tmp)){
               ll hh = (ll)pow(2,p-1)*tmp;
               if(hh == n){
                   return 1;
               }
           }
       }
   }
   return 0;
}

int snt(int x)
{
   if (x<2)
       return 0;
   for (int i=2; i<=sqrt(x); i++)
       if (x%i==0)
           return 0;
   return 1;
}

bool shh2(int n){
   int sum = 0;
   for(int i = 1; i <= sqrt(n); i++){
       if(n%i == 0){
           sum +=i;
           if(i != n/i){
               sum += n/i;
           }
       }
   }
   sum-=n;
   if(sum == n){
       return true;
   } else return 0;
}

bool check1(int n){
	int sum = 0;
	while(n){
		int r = n % 10;
		if(r != 2 || r != 3 || r != 5 || r != 7 ) return false;
		sum += r;
		n/=10;
	}
	return nt(sum);
}

int gcd(int a,int b){
    if(b == 0) return a;
    return (b, a&b);
}

void solve(int n){
    for(int i = 2; i <= sqrt(n);i++){
        if(n %i == 0){
            int mu = 0;
            while(n % i ==0){
                ++mu;
                n/= i;
            }
            cout << i << "^" << mu;
            if(n != 1) cout << "*";
        }
        if(n!=1){
            cout << n << "^1\n";
        }
    }
}

void nhap(int a[], int n){
	for(int i = 0; i < n;i++){
		cin >> a[i];
	}
}

void test1(int a[], int n){
	// dem tan xuat xuat hien cac phan tu trong mang
	for(int i = 0; i < n; i++){
		bool ok = true;
		for(int j = 0; j < i;j++){
			if(a[i] == a[j]){
				ok = false  ;
				break;
			}
		}
		//if(ok) cout << a[i] << " ";
		if(ok){
			int cnt = 1;
			for(int j = i+1; j < n;j++){
				if(a[i] == a[j]){
					++cnt;
				}
			}
			cout << a[i] << ' ' << cnt << endl;
		}
	}
}

void test2(int a[], int n){
	int cnt[1001] = {0};
	for(int i = 0; i < n; i++){
		cnt[a[i]] = 1;
	}
	for(int i = 0; i < 1000;i++){
		if(cnt[i]) cout << i << ' ';
	}
}
int cnt[10000001];

void test3(int a[], int n){
	//dem tan so xuat hien cua cac phan tu xuat hien lan luot trong mang
	for(int i = 0;i < n; i++){
		cnt[a[i]]++;
	}
	for(int i = 0; i <= 1000;i++){
		if(cnt[a[i]]){
			cout << a[i] << ' ' << cnt[a[i]] << endl;
			cnt[a[i]] = 0;
		}
	}
}

void test4(int a[], int n){
	//chen phan tu trong mang
	int k, x;
	cin >> x >> k;
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	--k;
	for(int i = n - 1; i >= k;i--){
		a[i+1] = a[i];
	}
	a[k] = x;
	++n;
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
}

void test4(int a[], int n, int x){
	//xoa phan tu trong mang
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	for(int i = 0;i < n; i++){
		if(a[i]==x){
			for(int j = i;j < n -1;j++){
				a[j] = a[i+1];
			}
			--n;
			for(int j = 0; j < n; j++){
				cout << a[j] << ' ';  
			}
			break;
		}
	}
	cout << "NOT FOUND\n";
}

void test5(int a[], int n){
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int f[n];
	for(int i = 0; i < n; i++){
		if(i == 0){
			f[0] = a[0];
		}
		else {
			f[i] = f[i - 1]  + a[i];
			cout << f[i] << ' ' << a[i] << endl;
		}
	}
	for(int i = 0; i < n; i++){
		cout << f[i] << ' ' ;
	}
}

void test6(int a[], int n,int k){
	nhap(a,n);
	for(int i = 0; i <= n - k;i++){
		int sum = 0;
		for(int j = 0; j < k;j++){
			sum+= a[i + j];
		}
		cout << sum << ' ';
	}
}

void test7(int a[], int n , int k){
	// cua so truot
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	int sum = 0;
	for(int i = 0; i < k; i++){
		sum += a[i];
	}
	cout << sum << " ";
	for(int i = 1; i <= n-k;i++){
		sum = sum - a[i-1]+ a[i+k-1];
		cout << sum << ' ';
	}
}

void test8(int a[], int n){
	// dem so phan tu khac nhau trong mang
	int max_val = -1e9;
	for(int i = 0;i < n; i++){
		int x ;
		cin >> x;
		cnt[x] = 1;
		max_val = max(max_val, x);
	}
	int dem =0 ;
	for(int i = 0; i <= max_val;i++){
		if(cnt[i] != 0){
			++dem;
		}
	}
	cout << dem;
}

void test9(int a[], int n){
	// dem so phan tu va tan suat cua chung theo thu tu tu be den lon
	int max_val = -1e9;
	for(int i = 0;i < n; i++){
		int x ;
		cin >> x;
		cnt[x] ++;
		max_val = max(max_val, x);
	}
	int dem =0 ;
	for(int i = 0; i <= max_val;i++){
		if(cnt[i] != 0){
			cout << i << ' ' << cnt[i] << endl;
		}
	}
}

void test10(int a[], int n){
	int max_val = -1e9;
	for(int i = 0;i < n; i++){
		cin >> a[i];
		cnt[a[i]] ++;
	}
	int dem =0 ;
	for(int i = 0; i <n ;i++){
		if(cnt[a[i]] != 0){
			cout << a[i] << ' ' << cnt[a[i]] << endl;
			cnt[a[i]]=0;
		}
	}
}

void check11(int a[], int n){
	int max_val = -1e9;
	for(int i = 0;i < n; i++){
		cin >> a[i];
		cnt[a[i]] ++;
		max_val = max(max_val, a[i]);
	}
	int tanxuat =0, res;
	for(int i = 0; i< max_val; i++){
		if(tanxuat < cnt[i]){
			tanxuat = cnt[i];
			res = i;
		}
	}
	cout << res << ' ' << tanxuat << endl;
}

void test12(int n, int m){
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		cnt1[x]= 1;
	}
	for(int i = 0; i < m ;i++){
		int x; cin >> x;
		cnt2[x] = 1;
	}
	for(int i = 0; i < 1e7;i++){
		if(cnt1[i] && cnt2[i]){
			cout << i << ' ';
		}
	}
	cout << endl;
	for(int i = 0; i < 1e7;i++){
		if(cnt1[i] || cnt2[i]){ 
			cout << i << ' ';
		}
	}
}

ll binpow(ll a, ll b){
	if( b == 0)
		return 1;
		ll tmp = binpow(a, b/2);
		if(b % 2 == 0){
			return tmp*tmp;
		} else {
			return tmp*tmp*a;
		}
	}

int mod = 1e9+7;
ll binpow1(ll a, ll b){
	if( b == 0)
		return 1;
		ll tmp = binpow1(a,b/2);
		if(b % 2 == 0){
			return (tmp%mod)*(tmp%mod)%mod;
		} else {
			return ((tmp%mod)*(tmp%mod)%mod)*(a%mod)%mod;
		}
	}
void in1(ll n){
	// in cac chu so tu trai sang phai
	if(n < 10) cout << n << ' ';
	else {
		in1(n / 10);
		cout << n % 10 << ' ';
	}
}
void in2(ll n){
	// in nguoc cac chu so
	if(n < 10) cout << n << ' ';
	else {
		cout << n % 10 << ' ';
		in2(n / 10);
	}
}

int test13(ll n){
	if(n == 1) return 0;
	int ans1 = 1e9, ans2 = 1e9, ans3 = 1e9;
	if(n % 2 == 0) ans1 = 1 + test13(n /2 );
	if(n % 3 == 0) ans2 = 1 + test13(n /3 );
	if(n > 1) ans3 = 1 + test13(n -1 );
	return min({ans1, ans2, ans3});
}
int main(){	

	#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


}
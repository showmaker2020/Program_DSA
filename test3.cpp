#include<bits/stdc++.h>
#include<fstream>
using namespace std;
using ll = long long;

//lower_bound >=x; tra ve vi tri dau  tien lon hon hoac bang x
//upper_bound > x; tra ve vi tri dau tien lon hon x 


int donggao(ll n){
	if ( n == 3) return 1;
	if ( n == 5) return 1;
	if(n % 3 != 0 && n % 5 != 0 ) return -1;
	int ans1 = 1e9, ans2 = 1e9;
	if(n % 3 == 0) ans1 = 1 + donggao(n - 3 );
	if(n % 5 == 0) ans2 = 1 + donggao(n - 5 );
	return min(ans1, ans2);
}
int cnt[42];
void elementdiff(int a[], int n){
	// dem so phan tu khac nhau trong mang
	for(int i = 0;i < n; i++){
		int x ;
		cin >> x;
		cnt[x%42] = 1;
	}
	int dem =0 ;
	for(int i = 0; i <= 42;i++){
		if(cnt[i] != 0){
			++dem;
		}
	}
	cout << dem;
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

int chan(ll n){
	if(n == 0) return 1;
	int cnt = 0;
	while(n){
		if(n % 2 == 0){
			++cnt;
			n/=10;
		}
	}
	return cnt;
}

int le(ll n){
	int cnt = 0;
	while(n){
		if(n % 2 == 1){
			++cnt;
			n/=10;
		}
	}
	return cnt;
}

bool cmp1(int a, int b){
	if(chan(a) != chan(b)){
		return chan(a) < chan(b);
	} else 
	return a < b;
}

bool cmp2(int a, int b){
	return le(a) < le(b);
}

void elementdiff1(int a[], int n){
	// dem so phan tu khac nhau trong mang
	for(int i = 0;i < n; i++){
		int x ;
		cin >> x;
		cnt[x] = 1;
	}
	int dem =0 ;
	for(int i = 0; i <= 42;i++){
		if(cnt[i] != 0){
			++dem;
		}
	}
	cout << 4-dem;
}

void lower_upper(int a[], int n, int x){
	auto it1 = lower_bound(a, a+n,x);
	auto it2 = upper_bound(a, a+n,x);
	int pos1 = -1, pos2 = -1;
	if(it1 == a+n){
		cout << "-1\n";
	} else cout << it1 - a << ' ' << it1 << endl;
	if(it2 == a+n) cout << "-1\n";
	else cout << it2 - a << ' ' << it2 << endl;
	if(*it1 == x){
		cout << it1 - a << endl;
		pos1 = it1-a;
	} else cout << "-1\n";
	--it2;
	if(*it2 == x) {
		cout << it2-a << endl;
		pos2 = it2 - a;
	}
	else cout << "-1\n" << endl;
	if(pos1 == -1) cout << 0 << endl;
	else cout << pos2 - pos1 + 1;
}

bool cmppair( pair<int , int >a , pair<int, int > b){
	int kc1 = a.first*a.first + a.second*a.second;
	int kc2 = b.first*b.first + b.second*b.second;
	if(kc1 != kc2) return kc1 < kc2;
	if(a.first != b.first){
		return a.first < b.first;
	}
	return b.first < b.second;
}

void khoangcach(int n){
	pair<int, int> a[n];
	for(int i = 0; i< n; i++){
		cin >> a[i].first >> a[i].second; 
	}
	sort(a, a+n,cmppair);
	for(auto x : a){
		cout << x.first << ' ' << x.second << endl;
	}
}

void docungcuagach(int a[], int n){
	// for(int  &x : a) cin >> x;
	// sort(a, a+n, greater<int>());
	// int ans = 1, docung = a[0];
	// for(int i = 0; i < n; i++){
	// 	if(docung <= 0) break;
	// 	++ans;
	// 	docung = min(docung-1,a[i]);
	// 	cout << docung << ' ' << ans << endl;

	// }
	// cout << ans << endl;
}

void hard(int a[], int n){
	map<int,int> mp;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mp[a[i]]++;
	}
	vector<pair<int, int>> v;
	for(auto it : mp){
		v.push_back(it);
	}
	sort(v.begin(), v.end(), [](pair<int,int>a, pair<int,int>b)->bool{
		if(a.second != b.second){
			return a.second > b.second;
		}
		return a.first < b.first;
	});
	for(auto it : v){
		for(int j = 0; j < it.second; j++){
			cout << it.first << ' ';
		}
	}
	cout << endl;
	vector<pair<int, int>> v2;
	for(int i = 0; i< n; i++){
		if(mp.count(a[i])){
			v2.push_back({a[i], mp[a[i]]});
			mp.erase(a[i]);
		}
	}
	stable_sort(v2.begin(), v2.end(),[](pair<int,int>a, pair<int,int>b)->bool{
		return a.second > b.second;
	});
	for(auto it : v2){
		for(int j = 0; j < it.second;j++){
			cout << it.first << ' ';
		}
	}
}
// dùng để vẽ ma trận xoắn ốc
// int n;
// 	cin >> n;
// 	int a[n][n];
// 	int h1 = 0, h2 = n-1, c1 = 0, c2 = n-1;
// 	int dem = 1;
// 	while(dem <= n*n){
// 		for(int i = c1 ; i <= c2;i++){
// 			a[h1][i] = dem;
// 			dem++;
// 		}
// 		++h1;
// 		for(int i = h1; i <= h2; i++){
// 			a[i][c2] = dem;
// 			++dem;
// 		}
// 		--c2;
// 		for(int i = c2; i >= c1; i--){
// 			a[h2][i] = dem;
// 			++dem;
// 		}
// 		--h2;
// 		for(int i = h2; i >=h1; i--){
// 			a[i][c1] = dem;
// 			++dem;
// 		}
// 		++c1;
// 	}
// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j< n;j++){
// 			cout << a[i][j] << ' ';
// 		}
// 		cout << endl;
// 	}	
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void kithuatloang(int n, int m){
	int cnt = 0;
	int a[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m;j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n;i++){
		for(int j = 0; j< m; j++){
			int t =1;
			for(int k = 0; k < 8;k++){
			int i1 = i + dx[k], j1 = j + dy[k];
			if(i1 >= n|| i1 < 0 || j1 > m || j1 < 0) continue;
			else if(a[i][j] <= a[i1][j1]) {
				t = 0;
			}
		}
		if(t == 1) ++cnt;
		}
		
	}
	cout << cnt;
}
int n, m;
int a[100][100];
int dx1[4] = {-1, 0, 0, 1};
int dy1[4] = {0, -1, 1, 0};

void nhap(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m;j++){
			cin >> a[i][j];
		}
	}
}
void loang(int i, int j){
	cout << "Loang tai o " << i << " " << j << endl;
	a[i][j] = 0;
	for(int k = 0; k < 4;k++){
		int i1 = i + dx1[k], j1 = j + dy1[k];
		if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1] == 1){
			loang(i1, j1);
		}
	}
}

int cntloang(){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m;j++){
			if(a[i][j] == 1){
				++cnt;
				loang(i,j);
			}
		}
	}
	return cnt;
}

void matran(){
	int x, y ,z;
	cin >> x >> y >> z;
	int a1[x][y], b[y][z], c[x][z];
	for(int i = 0; i < x; i++){
		for(int j = 0;j < y; j++){
			cin >> a1[i][j];
		}
	}
	for(int i = 0; i < y; i++){
		for(int j = 0;j < z; j++){
			cin >> a1[i][j];
		}
	}
	for(int i = 0;i < x; i++){
		for(int j = 0;j < z; j++){
			c[i][j] = 0;
			for(int k = 0; k < y;k++){
				c[i][j] += a1[i][k] * b[k][j];
			}
		}
	}

	for(int i = 0; i < x; i++){
		for(int j = 0;j < z; j++){
			cout << c[i][j] << ' ';
		}
		cout << endl;
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("lck1.in", "r", stdin);
	freopen("lck2.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int a[n];
	for(int &x : a) cin >> x;
	int q;
	cin >> q;
	set<int> se;
	int f[n];
	for(int i = n - 1; i >= 0; i--){
		se.insert(a[i]);
		f[i] = se.size();
		
		cout << f[i] << ' ';
	}
	cout << endl;
	while(q--){
		int l; cin >> l;
		cout << f[l] << endl;
	}
	
}
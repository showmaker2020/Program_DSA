//#include <bits/stdc++.h>
//using namespace std;
//using ll = long long;
//int cnt1[10001];
//int cnt2[10001];
//
//void test1(int n, int m){
//	int a[n];
//	set<int> se1, se2;
//	for(int i = 0; i < n;i++){
//		cin >> a[i];
//		se1.insert(a[i]);
//	}
//	for(int i = 0; i < m; i++){
//		int x;
//		cin >> x;
//		se2.insert(x);
//	}
//	for(int x : se1){
//		if(se2.count(x) == 0){
//			cout << x << ' ';
//			se2.erase(x);
//		}
//	}
//}
//
//void test3(int n){
//	int a[n];
//	set<int> se;
//	for(int i = 0; i < n ;i++){
//		cin >> a[i];
//	}
//	int q;cin >> q;
//	int f[n];
//	for(int i = n - 1; i >= 0; i--){
//		se.insert(a[i]);
//		f[i] = se.size();
//	}
//	while(q--){
//		int l; cin >> l;
//		cout << f[l] << endl;
//	}
//}
//
//int donggao(int n){
//	if ( n == 3) return 1;
//	if ( n == 5) return 1;
//	if(n % 3 != 0 && n % 5 != 0 ) return -1;
//	int ans1 = 1e9, ans2 = 1e9;
//	if(n % 3 == 0) ans1 = 1 + donggao(n - 3 );
//	if(n % 5 == 0) ans2 = 1 + donggao(n - 5 );
//	return min(ans1, ans2);
//}
//
//int sum(int n){
//	int ans = 0;
//	while(n){
//		ans += n % 10;
//		n/=10;
//	}
//	return ans;
//}
//
////int tongcacchuso(int a[], int n){
////	for(int &x : a) cin >> x;
////	sort(a, a+n,[](int x, int y){
////		if(sum(x) != sum(y)) return sum(x) < sum(y);
////		return x < y;
////	});
////	for(int x : a) cout << x << ' ';
////}
//
////int n, m;
////	int b[n], c[m];
////	for(int &x : b) cin >> x;
////	for(int &x : c) cin >> x;
////	int i = 0,j = 0;
////	while(i < n && j < m){
////		if(b[i] <= c[j]){
////		cout << "b" << i+1 << " ";
////		i++;
////		}
////	else {
////		cout << "c" << j+1 << " ";
////		j++;
////		}
////	}
////	while(i < n){
////		cout << "b" << i+1 << " ";
////		i++;
////	}
////	while(j < n){
////		cout << "c" << j+1 << " ";
////		j++;
////	}
////	
//
//void soconthieu(int a[], int n){
//	set<int> se;
//	for(int i =0 ;i < n ;i++){
//		cin >> a[i];
//		se.insert(a[i]);
//	}
//	sort(a, a+n);
//	int max = a[n-1];
//	int min = a[0];
//	cout << max - min +1  - se.size();
//	
//}
//ll gcd(int a, int b){
//	if(b == 0) return a;
//	return gcd(b , a%b);
//}
//
//ll lcd(int a, int b){
//	return a/gcd(a,b)*b;
//}
//int main(){
//	int n;
//	cin >> n;
//	int a[n];
//	for(int &x : a) cin >> x;
//	int q;
//	cin >> q;
//	set<int> se;
//	int f[n];
//	for(int i = n - 1; i >= 0; i++){
//		se.insert(a[i]);
//		f[i] = se.size();
//		cout << f[i] << ' ';
//	}
//	while(q--){
//		int l; cin >> l;
//		cout << f[l] << endl;
//	}
//	
//}
#include <stdio.h>

void nhap_so_hang_so_cot(int *n, int *m) {
	do {
		printf("Nhap so hang = ");
		scanf("%d", n);
	} while (*n < 2);

	do {
		printf("Nhap so cot = ");
		scanf("%d", m);
	} while (*m < 2 || *m > 50);
}

void nhap_mang(float a[][50], int n, int m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("\ta[%d][%d] = ", i, j);
			scanf("%f", &a[i][j]);
		}
	}
}

void xuat_mang(float a[][50], int n, int m){
	for(int i = 0;i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%2.2f ", a[i][j]);
		}
		printf("\n");
	}
}


int main() {
	int n, m;
	nhap_so_hang_so_cot(&n, &m);
	float a[50][50];
	printf("Nhap du lieu cho mang: \n");
	nhap_mang(a, n, m);
	xuat_mang(a, n, m);
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;


int n, k, a[100], ok;
void ktao(){
	for(int i = 1; i <= n; i++){
		a[i] = i;
	}
}
void sinh(){
	// bat dau tu vi tri n - 1: i = n -1
	// chung nao a[i] > a[i+1] thi phai dich sang ben trai
	int i = n - 1;
	while(i >= 1 && a[i] > a[i+1]){
		--i;
	}
	if(i == 0){
		ok = false;
	} else {
		// a[i] < a[i+1]
		// di tim vi tri i, > a[i] va nho nhat co the
		int j = n; // bat dau tu vi tri cuoi cung bo qua vi tri ma a[j] < a[i]
		while(a[i] > a[j]) --j;
		swap(a[i], a[j]);
		// sap xep cac phan tu tu vi tri i + 1 => theo thu tu tang dan
		reverse(a + i +1, a+n+1);
	}
}

//next_permutation(a, a+n) : sinh hoan vi ke tiep
//prev_permutation(a, a+n) : sinh hoan vi ke trc
int main(){
	#ifndef ONLINE_JUDGE
	freopen("lck1.in", "r", stdin);
	freopen("lck1.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	ktao();
	// ok = true;
	// while(ok){
	// 	for(int i = 1; i <=n ;i++){
	// 		cout << a[i] << ' ';
	// 	}
	// 	cout << endl;
	// 	sinh();
	// }
	do{
		for(int i = 1; i <= n;i++){
			cout << a[i] << ' '; 
		}
		cout << endl;
	}while(next_permutation(a + 1, a+n+1));
}
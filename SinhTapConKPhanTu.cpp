#include <bits/stdc++.h>
using namespace std;


int n, k, a[100], ok;


void ktao(){
	for(int i = 1; i <= k; i++){
		a[i] = i;
	}
}

void sinh(){
	int i = k;
	while(i >= 1 && a[i] == n-k+i){
		--i;
	}
	if(i == 0){
		ok = 0;
	}
	else {
		a[i]++;
		for(int j = i + 1; j <= k;j++){
			a[j] = a[j-1] + 1;
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("lck1.in", "r", stdin);
	freopen("lck1.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	ktao();
	ok = 1;
	while(ok){
		// if(check()){
		// 	for(int i = 1; i <= n; i++){
		// 	cout << a[i];
		// 	}
		// 	cout << endl;
		// }
		for(int i = 1; i <= k; i++){
			cout << a[i];
		}
		cout << endl;
		sinh();
	}
	return 0;
}
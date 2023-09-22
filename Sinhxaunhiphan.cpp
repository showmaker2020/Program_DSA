#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int n, k, a[100], ok;
void ktao(){
	for(int i = 1; i <= n; i++){
		a[i] = 0;
	}
}

void sinh(){
	int i = n;
	while( i >= 1 && a[i] == 1){
		a[i] = 0;
		--i;
	}
	if(i == 0){
		ok = 0; // day la cau hinh cuoi cung;
	} else {
		a[i] = 1;
	}
}

bool check(){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		cnt += a[i];
	}
	return cnt == k;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("lck1.in", "r", stdin);
	freopen("lck1.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	ok = 1;
	while(ok){
		// if(check()){
		// 	for(int i = 1; i <= n; i++){
		// 	cout << a[i];
		// 	}
		// 	cout << endl;
		// }
		for(int i = 1; i <= n; i++){
			cout << a[i];
			}
		cout << endl;
		sinh();
	}
	return 0;
}

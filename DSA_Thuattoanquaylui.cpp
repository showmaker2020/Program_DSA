#include <bits/stdc++.h>
using namespace std;
int X[100], n, daxet[1000];

void in(){
	for(int i = 1; i <= n; i++){
		cout << X[i];
	}
}
// nhi phan
void Try(int i){
	for(int j = 0; j <= 1; j++){
		X[i] = j;
		if(i == n){
			in();
			cout << endl;
		} else{
			Try(i+1);
		}
	}
}
// 
void Try1(int i){
	for(int j = 1; j <= n; j++){
		if(daxet[j] == 0){
			X[i] = j;
			daxet[j] = 1;
			if(i == n){
				in(); cout << endl;
			}
			else Try1(i+1);
			daxet[j] = 0;
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
	cin >> n;
	Try1(1);
}
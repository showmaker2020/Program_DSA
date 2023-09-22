#include <bits/stdc++.h>
using namespace std;
int N, X[100],K;

void inkq(){
	for(int i = 1;i <=N;i++){
		cout << X[i];
	}
	cout << endl;
}

void inkq1(){
	for(int i = 1;i <=K;i++){
		cout << X[i];
	}
	cout << endl;
}

void Try(int i){
	for(int j = 0; j <= 1;j++){
		X[i] = j;
		if(i == N){
			inkq();
		} else {
			Try(i+1);
		}
	}
}

void Try1(int i){
	for(int j = X[i-1]+1; j <= N-K+i;j++){
		X[i] = j;
		if( i == K){
			inkq1();
		}
		else {
			Try1(i+1);
		}
	}
}
int main(){
	cin >> N >> K ;
	X[0] = 0;
	Try1(1);
	return 0;
}
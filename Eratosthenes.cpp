#include <iostream>
#include <cmath>
using namespace std;
int prime[1000001];
void sieve(){
	//coi tat ca cac so tu 0 cho toi n la so nguyen to
	// prime[i]  = 0;
	// prime[i]  = 1;
	for(int i = 0; i <= 1000000; i++)
		prime[i] = 1;
		//loai 0 va 1;
	prime[0] = prime[1] = 0;
	for(int i =0; i < 1000; i++){
		if(prime[i]){
			for(int j = i*i; j <= 1000000; j+=i){
				prime[j] = 0; 
			}
		}
	}

	
}
int main(){
	sieve();
	int n;
	cin >> n;
	for(int i = 0; i <= n; i++){
		if(prime[i]) cout << i << " ";
	}
	
}
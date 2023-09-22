#include <bits/stdc++.h>
using namespace std;

void quyhoachdong1(){
	//14
	// 128 104 53 786 660 961 754 775 291 231 224 915 392 994
	// O(n^2)
	// L[i] do dai cua day con tang dai nhat ket thuc tu chi so i
	// L[i] = max(L[i], l[j] + 1) : a[i] > a[j]
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> L(n, 1);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(a[i] > a[j]){
				L[i] = max(L[i], L[j] + 1);
			}
		}
	}
	cout << *max_element(L.begin(), L.end()) << endl;
}

void baitoancaitui(){
	int n, S;
	cin >> n >> S;
	int w[n+1], v[n+1];
	for(int i = 1;i <= n ;i++) cin >> w[i];
	for(int i = 1;i <= n; i++) cin >> v[i];
	int dp[n+1][S+1];
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= S;j++){
			// khong con lua chon thu i trong tui
			dp[i][j] = dp[i-1][j];
			if(j >= w[i]){
				dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
			}
		}
	}
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <=S ;j++){
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	cout << dp[n][S] << endl;
}

void saucondainhat(){
	
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> v;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int cnt = 0;
	sort(a, a+n);
	int sum = 0, maxSum = 0;
	for(int i = 0 ; i < n; i++){
		sum = a[i] + a[i+1];
		for(int j = i + 2; j < n; j++){
			v.push_back(sum + a[j]);
			++cnt;
		}
	}
	
	auto it1 = lower_bound(v.begin(), v.end(), m);
    if(*it1 == m){
    cout << m << endl;
    }
	else cout << *(it1-1)<< endl;	
}
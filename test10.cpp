#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main(){	
	#ifndef ONLINE_JUDGE
	freopen("lck1.in", "r", stdin);
	freopen("lck2.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin, s);
		for(char &x : s) x = tolower(x);
		vector<string> v;
		string tmp;
		stringstream ss(s);
		while(ss >> tmp){
			v.push_back(tmp);
		}
		string email = v[v.size()- 2];
		for(int i = 0; i < v.size() -2; i++){
			email += v[i][0];
		}
		email += "@xyz.edu.vn";
		string dob = v[v.size()-1];
		stringstream ss2(dob);
		string pass = "";
		while(getline(ss2, tmp, '/')){
			pass += to_string(stoi(tmp));
		}
		cout << email << endl << pass << endl;

	}


}
#include <bits/stdc++.h>
using namespace std;

struct sinhvien{
	string ten, ns;
	float toan, ly, hoa;
	
	void nhap() {
		cin.ignore();
		getline(cin, ten);
		getline(cin, ns);
		cin >> toan >> ly >> hoa;
	}
	
	void in() {
		cout << ten << " " << ns << ' ' << toan + ly + hoa << endl;
	}

	bool operator < (sinhvien other){
		return toan < other.toan;
	}
};

int main() {
	#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	sinhvien a[n];
	float max_score = 0;
	
	for (int i = 0; i < n; i++) {
		a[i].nhap();
		max_score = max(max_score, a[i].toan + a[i].ly + a[i].hoa);
	}
	
	cout << "DANH SACH THU KHOA: ";
	
	for (int i = 0; i < n; i++) {
		if (max_score == a[i].toan + a[i].ly + a[i].hoa) {
			a[i].in();
		}
	}
	
	cout << "KET QUA TRUNG TUYEN LA: " << endl;
	
	for (int i = 0; i < n; i++) {
		a[i].in();
		if (a[i].toan + a[i].ly + a[i].hoa >= 24) {
			cout << "DO! " << endl;
		} else {
			cout << "TRUOT!" << endl;
		}
	}

	return 0;
}

#undef _GLIBCXX_DEBUG                // disable run-time bound checking, etc
#pragma GCC optimize("Ofast,inline") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens

#pragma GCC target("bmi,bmi2,lzcnt,popcnt")                      // bit manipulation
#pragma GCC target("movbe")                                      // byte swap
#pragma GCC target("aes,pclmul,rdrnd")                           // encryption
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2") // SIMD


#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using ll = long long;

using namespace std;

void quyhoachdong(){
	int t;
	cin >> t;
	while(t--){
		int n , k;
		cin >> n >> k ;
		int a[1001];
		for(int i = 0; i < n; i++) cin >> a[i];
		ll sum = 0;
		for(int i = 0; i < k; i++) sum += a[i];
		ll res = sum, idx = 0;
		for(int i = k; i < n ;i++){
			sum = sum - a[i - k] + a[i];
			cout << sum << ' ' << a[i - k] << ' ' << a[i] << endl;
			if(sum > res){
				res = sum;
				idx = i - k +1;
			}
		}
		cout << res << endl;
		for(int j = 0; j < k; j++){
			cout << a[idx + j] << ' ';
		}
		cout << endl;
		
	}
}

void timgiacaonhant(){
	int n, m;
	cin >> n >> m;
	if(n*9 < m) cout << "-1 ";
	string largestNum = "";

    // Xây dựng số lớn nhất bằng cách tìm từng chữ số lớn nhất có thể
    while (n > 0) {
        // Nếu n > 1, chữ số lớn nhất có thể là 9
        if (n > 1) {
            int digit = min(9, m);
            largestNum += to_string(digit);
            m -= digit;
        }
        // Nếu n = 1, chữ số cuối cùng bằng m
        else {
            largestNum += to_string(m);
        }

        n--;
    }

    cout << stoi(largestNum);
}



typedef struct{
	char sbd[30];
	char tensv[30];
	float toan, ly, hoa;
}sinhvien;

sinhvien nhap(){
	sinhvien sv;
	fflush(stdin);
	printf("Nhap so bao danh: ");
	gets(sv.sbd);
	fflush(stdin);
	printf("Ho va ten thi sinh: ");
	gets(sv.tensv);
	printf("Diem mon toan: ");
	scanf("%f", &sv.toan);
	printf("Diem mon ly: ");
	scanf("%f", &sv.ly);
	printf("Diem mon hoa: ");
	scanf("%f", &sv.hoa);
	return sv;
}

void xuat(sinhvien sv){
	printf("So bao danh sinh vien: %s\t\n", sv.sbd);
	printf("Ten thi sinh: %s\t\n", sv.tensv);
	printf("Diem mon toan: %1.2f\t\n", sv.toan);
	printf("Diem mon ly: %1.2f\t\n", sv.ly);
	printf("Diem mon hoa: %1.2f\t\n", sv.hoa);
	printf("Tong diem ba mon: %1.2f\t\n", sv.toan+ sv.ly + sv.hoa);
}
int main(){
	sinhvien sv[100];
	int n;
	printf("Nhap so ho so ung tuyen la: ");
	scanf("%d", &n);
	printf("Nhap danh sach ung tuyen la: \n");
	for(int i = 0; i < n; i++){
		printf("===================================\n");
		sv[i] = nhap();
		printf("===================================\n");
	}
	printf("Danh sach nop ho so la: \n");
	for(int i = 0; i < n; i++){
		printf("===================================\n");
		xuat(sv[i]);
		printf("===================================\n");
	}
	printf("Danh sach trung tuyen la: \n");
	for(int i = 0;i < n; i++){
		if(sv[i].toan + sv[i].ly + sv[i].hoa >=18){
		printf("===================================\n");
			xuat(sv[i]);
		printf("===================================\n");
		}
	}
}


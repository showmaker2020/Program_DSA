#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class sinhvien{
	private:
		string msv, ten, ns, lop;
		double gpa;
	public:
		void nhap(int stt){
			cin.ignore();
			string ma = to_string(stt);
			while(ma.size() < 3) ma = "0" + ma;
			msv = "SV" + ma;
			getline(cin , this->ten);
			getline(cin , this->lop);
			getline(cin , this->ns);
			cin >> this->gpa;
			
		}
		void in(){
			cout << msv << ' ' << ten << ' '<< ns << ' ' << lop << ' ' << gpa << endl;
		}
		string getMSV(){
			return this->msv;
		}
		double getGPA(){
			return this->gpa;
		}
		void chuanhoa(){
			stringstream ss(ten);
			string tmp, res= "";
			while(ss>>tmp){
				res += toupper(tmp[0]);
				for(int j = 1; j < tmp.size(); j++){
					res += tolower(tmp[j]);
				}
				res += " ";
			}
			res.pop_back();
			this->ten = res;
			if(ns[1] == '/') ns = "0" + ns;
			if(ns[4] == '/') ns.insert(3,"0");
		}
		void friend display(sinhvien);

};

void display(sinhvien s){
	cout << s.msv << ' ' << s.ten << ' ' << s.ns << ' ' << ' ' << s.lop << ' ' << s.gpa << endl;
}
bool comp(sinhvien a, sinhvien b){
	if(a.getGPA() != b.getGPA()){
		return a.getGPA() > b.getGPA();
	} else return a.getMSV() < b.getMSV();
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	sinhvien sv[n];
	for(int i = 0; i < n; i++){
		sv[i].nhap(i+1);
		sv[i].chuanhoa();
		display(sv[i]);
	}
	sort(sv, sv+n,comp);
	for(int i = 0; i < n; i++){
		sv[i].in();
	}
}
#include <bits/stdc++.h>
using namespace std;
class sinhvien{
	private:
		string ma, ten, lop;
		double gpa;
	public:
		sinhvien(string ma, string ten, string lop,double gpa){
			this->ma = ma;
			this->ten = ten;
			this->lop = lop;
			this->gpa = gpa;
		}
		double getGpa(){
			return this->gpa;
		}
		void chuanhoa(){
			stringstream ss(this->ten);
			string tmp, res="";
			while(ss >> tmp){
				res += toupper(tmp[0]);
				for(int j = 1; j < tmp.size();j++){
					res += tolower(tmp[j]);
				}
				res+= " ";
			}
			res.pop_back();
			 this->ten = res;
			// if(this->ns[1] == '/') this->ns = "0" + this->ns;
			// if(this->ns[4] == '/') this->ns.insert(3,"0");
		}
		void in(){
			cout << this->ma << ' ' << this->ten << ' ' << this->lop << ' ' << this->gpa << endl;
		}
		friend void ghifile(sinhvien,string filename);
};

void ghifile(sinhvien x, string filename){
	ofstream out;
	out.open(filename, ios::app);
	out << x.ma << ' | ' << x.ten << ' | ' << x.lop << ' | ' << x.gpa << endl;
	out.close();
}
bool cmp(sinhvien a, sinhvien b){
	return a.getGpa() < b.getGpa();
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ofstream out;
	out.open("data_new.txt");
	out << "73DCTT22185, Doan vAn HuAn, 73DCTT26 , 3.27" << endl;
	out << "73DCTT221xx, bui thi thanh huyen, 73DCTTxx , 3.27" << endl;
	out.close();
	ifstream in;
	in.open("data_new.txt");
	if(in.is_open()){
		string s; 
		vector<sinhvien> v;
		while(getline(in,s)){
			stringstream ss(s);
			vector<string> a;
			string tmp;
			while(getline(ss, tmp, ',')){
				a.push_back(tmp);
			}
			sinhvien x(a[0], a[1], a[2], stod(a[3]));
			x.chuanhoa();
			v.push_back(x);
		}
		// sinhvienx(a[0], a[1], a[2], stod(a[3]));
		// x.chuanhoa();
		// v.push_back(x);
		for(sinhvien x : v){
			ghifile(x, "data_out.txt");
		}
	} else {
		cout << " khong tim thay file";
	}
	in.close();
}

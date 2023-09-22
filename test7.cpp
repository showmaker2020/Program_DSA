#include <bits/stdc++.h>
using namespace std;
class person{
	private:
		string ten, ns, diachi;
	public:
		person(string ten, string ns, string diachi){
			this->ten = ten;
			this->ns = ns;
			this->diachi = diachi;
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
			//res.pop_back();
			this->ten = res;
			if(this->ns[1] == '/') this->ns = "0" + this->ns;
			if(this->ns[4] == '/') this->ns.insert(3,"0");
		}

		void nhap(){
			getline(cin, this->ten);
			getline(cin, this->ns);
			getline(cin, this->diachi);
		}
		void in(){
			cout << this->ten << ' ' << this->ns << ' ' << this->diachi << ' ';
		}
};

class student : public person{
	private:
		string ma,lop;
		double	gpa;
	public:
		student(string ten, string ns, string diachi, string ma,string lop, double gpa) : person( ten,  ns, diachi){
			this->ma = ma;
			this->lop = lop;
			this->gpa = gpa;
		}

		void nhap(){
			person::nhap();

		}
		void in(){
			cout << this->ma << ' ';
			person::in();
			cout << this->lop << ' ' << fixed << setprecision(2) << this->gpa << endl;
		}

};

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	vector<student> v;
	for(int i = 0; i < n; i++){
		cin.ignore();
		string ten;
		getline(cin , ten);
		string s; getline(cin , s);
		string lop; getline(cin,lop);
		double gpa;
		cin >> gpa;
		int idx = -1;
		for(int j = 0; s.size(); j++){
			if(isalpha(s[j])){
				idx = j; break;
			}
		}
		string ns = s.substr(0, idx +1);
		string diachi = s.substr(idx);
		string ma = to_string(i+1);
		while(ma.size() < 4) ma = "0" + ma;
		student st(ten, ns , diachi ,ma , lop, gpa);
		st.chuanhoa();
		v.push_back(st);
	}
	for(student x : v){
		x.in();
	}


}
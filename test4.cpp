#include<bits/stdc++.h>
using namespace std;
class sophuc{
	private:
		int thuc, ao;
	public:
		sophuc(int thuc, int ao){
			this->thuc = thuc;
			this->ao = ao;
		}
		sophuc operator + (sophuc b){
			sophuc kq(0,0);
			kq.thuc = this->thuc + b.thuc;
			kq.ao = this->ao + b.ao;
			return kq;
		}
		friend ostream& operator  << (ostream &out, sophuc a){
			out << a.thuc << ' ' << a.ao << endl;
			return out;
		}
		friend istream& operator  >> (istream &in, sophuc &a){
			in >> a.thuc >>  a.ao ;
			return in;
		}


		void in(){
			cout << thuc << ' ' << ao;
		}
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	sophuc a(0,0);
	cin >> a;
	cout << a << endl;
}
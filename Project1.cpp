#include <bits/stdc++.h>
using namespace std;

class SinhVien{
private:
    string ma, ten, lop, diachi, sex;
    double gpa;
    int tuoi;
public:
	static int n;
    SinhVien(string ma, string ten, int tuoi, string sex, string lop, double gpa, string diachi) {
        this->ma = ma;
        this->ten = ten;
        this->tuoi = tuoi;
        this->sex = sex;
        this->lop = lop;
        this->gpa = gpa;
        this->diachi = diachi;
    }

    void setGpa(double gpa) {
        this->gpa = gpa;
    }

    double getGpa () const {
        return this->gpa;
    }

    void setMa(string ma) {
        this->ma = ma;
    }

    string getMa() const {
        return this->ma;
    }

    void setTen(string ten) {
        this->ten = ten;
    }

    string getTen() const{
        return this->ten;
    }

    void setSex(string sex) {
        this->sex = sex;
    }

    string getSex() const{
        return this->sex;
    }

    void setLop(string lop) {
        this->lop = lop;
    }

    string getLop() const {
        return this->lop;
    }
    void setTuoi(int tuoi){
    	this->tuoi = tuoi;
	}
	int getTuoi() const {
		return this->tuoi;
	}

    void setDiachi(string diachi) {
        this->diachi = diachi;
    }

    string getDiachi() const {
        return this->diachi;
    }

    void chuanhoa() {
        string res, tmp;
        stringstream ss(this->ten);
        while (ss >> tmp) {
            res += toupper(tmp[0]);
            for (int j = 1; j < tmp.size(); j++) {
                res += tolower(tmp[j]);
            }
            res += " ";
        }
        res.pop_back();
        this->ten = res;
    }

    void printInfo() const{
        cout << this->ma << ' ' << this->ten << ' ' << this->lop << ' ' << this->gpa << endl;
    }

    friend void writeFile(SinhVien x, string filename);
    //friend void input(SinhVien&);
};

void saoLuu(const vector<SinhVien>& danhsachsinhvien, const string& filename) {
    ofstream out(filename);
    if (out.is_open()) {
        for (const SinhVien& sv : danhsachsinhvien) {
            out << sv.getMa() << '|' << sv.getTen() << '|' << sv.getTuoi() << '|' << sv.getSex() << '|' << sv.getLop() << '|' << sv.getGpa() << '|' << sv.getDiachi() << endl;
        }
        out.close();
        cout << "Da sao luu du lieu vao file " << filename << endl;
    } else {
        cout << "Khong the mo file " << filename << " de sao luu du lieu." << endl;
    }
}

void them(vector<SinhVien> &danhsachsinhvien) {
	string ma, ten, lop, diachi, sex;
    double gpa;
    int tuoi;
    cout << "======================================================" << endl;
    cin.ignore();
    cout << "(?) ID: ";
    getline(cin, ma);
    cout << "(?) Name: ";
    getline(cin, ten);
    cout << "(?) Age: ";
    cin >> tuoi;
    cout << "(?) Sex: ";
    cin.ignore();
    getline(cin, sex);
    cout << "(?) Class: ";
    getline(cin, lop);
    cout << "(?) Gpa: ";
    cin >> gpa;
    cout << "(?) Address: ";
    cin.ignore();
    getline(cin,diachi);
    cout << "Added a student with name: " << ten << endl;
    cout << "======================================================" << endl;
    SinhVien sv(ma, ten, tuoi, sex, lop, gpa, diachi);
    danhsachsinhvien.push_back(sv);
}

void edit(vector<SinhVien>& danhsachsinhvien) {
    string ma;
    cout << "Nhap ma sinh vien ma ban muon chinh sua: ";
    cin.ignore();
    getline(cin, ma);

    bool found = false;
    for (auto& sv : danhsachsinhvien) {
        if (sv.getMa() == ma) {
            string ten, lop, diachi, sex;
            double gpa;
            int tuoi;

            cout << "Chinh sua vs ma " << ma << endl;
            cout << "Nhap thong tin moi:" << endl;

            cout << "(?) Ten : ";
            getline(cin, ten);
            cout << "(?) Tuoi: ";
            cin >> tuoi;
            cin.ignore();
            cout << "(?) Gioi Tinh: ";
            getline(cin, sex);
            cout << "(?) Lop: ";
            getline(cin, lop);
            cout << "(?) Gpa: ";
            cin >> gpa;
            cin.ignore();
            cout << "(?) Dia chi: ";
            getline(cin, diachi);

            sv.setTen(ten);
            sv.setTuoi(tuoi);
            sv.setSex(sex);
            sv.setLop(lop);
            sv.setGpa(gpa);
            sv.setDiachi(diachi);

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Sinh vien voi ID " << ma << " Khong tim thay!" << endl;
    }
}

void duyet(vector<SinhVien> danhsachsinhvien){
	cout << "Danh sach Sinh vien:\n";
    cout << "+--------------------------------------------------------------------------------------------------+\n";
    cout << "| STT | Ma        | Ho va ten            | Tuoi      | Gioi Tinh   | Gpa     | Dia chi             |\n";
    cout << "+--------------------------------------------------------------------------------------------------+\n";
    for(int i=0; i<danhsachsinhvien.size(); i++){
        SinhVien sv = danhsachsinhvien[i];
        sv.chuanhoa();
        cout << "| " << setw(4) << left << i+1;
        cout << "| " << setw(9) << left << sv.getMa() << " | ";
        cout << setw(20) << left << sv.getTen() << " | ";
        cout << setw(9) << left << sv.getTuoi() << " | ";
        cout << setw(11) << left << sv.getSex() << " | ";
        cout << setw(7) << left << sv.getGpa() << " | ";
        cout << setw(19) << left << sv.getDiachi() << " |\n";
    }
    cout << "+--------------------------------------------------------------------------------------------------+\n";
}


void remove(vector<SinhVien>& danhsachsinhvien) {
    string ma;
    cout << "Nhap ID sinh vien ma ban muon xoa: ";
    cin.ignore();
    getline(cin, ma);

    auto it = find_if(danhsachsinhvien.begin(), danhsachsinhvien.end(), [&](const SinhVien& sv) {
        return sv.getMa() == ma;
    });

    if (it != danhsachsinhvien.end()) {
        danhsachsinhvien.erase(it);
        cout << "Sinh vien voi ID " << ma << " da xoa thanh cong." << endl;
    } else {
        cout << "Sinh vien voi ID " << ma << " khong tim thay!" << endl;
    }
}

bool cmp5(SinhVien& a , SinhVien& b){
	if(a.getTen() != b.getTen())
		return a.getTen() < b.getTen();
}

bool cmp1(SinhVien& a , SinhVien& b){
	if(a.getGpa() != b.getGpa()){
		return a.getGpa() > b.getGpa();
	} else {
		return a.getTen() < b.getTen();
	}
}

bool cmp2(SinhVien& a , SinhVien& b){
	if(a.getLop() != b.getLop()){
		return a.getLop() < b.getLop();
	} else {
		return a.getTen() < b.getTen();
	}
}


bool cmp3(SinhVien& a , SinhVien& b){
	return a.getMa() < b.getMa();
}


void thongke(vector<SinhVien>& danhsachsinhvien){
	for(auto& sv : danhsachsinhvien){
		if(sv.getGpa() >= 2.5 && sv.getGpa() <=3.19){
			cout << "Danh sach sinh vien duoc loai kha la: " << endl;
			duyet(danhsachsinhvien);
		} else if(sv.getGpa() >= 3.2 && sv.getGpa() <=3.59){
			cout << "Danh sach sinh vien duoc loai gioi la: " << endl;
			duyet(danhsachsinhvien);
		} else if(sv.getGpa() >= 3.6 && sv.getGpa() <=4.0){
			cout << "Danh sach sinh vien duoc loai xuat sac la: " << endl;
			duyet(danhsachsinhvien);
		}
	}
}
void timkiem( vector<SinhVien>& danhsachsinhvien){
	string search;
	cout << "Nhap tu khoa ban muon tim kiem: ";
	cin.ignore();
	getline(cin, search);
//	vector<SinhVien> ketquatimkiem[1000];
//	int n = danhsachsinhvien.size();                      
//	for(int i = 0; i < n; i++){
//		const SinhVien& sv = danhsachsinhvien[i];
//			if (sv.getMa() == search || sv.getLop() == search || sv.getDiachi() == search || sv.getSex() == search) {
//           ketquatimkiem[i].push_back(sv);
//        	}
//		}
	vector<SinhVien> ketquatimkiem;

    for (const SinhVien& sv : danhsachsinhvien) {
        if (sv.getMa() == search || sv.getLop() == search || sv.getDiachi() == search || sv.getSex() == search) {
            ketquatimkiem.push_back(sv);
        }
    }
		
	if (ketquatimkiem.empty()) {
        cout << "Khong tim thay ket qua phu hop." << endl;
    } else {
        cout << "Ket qua tim kiem:" << endl;
        for (const SinhVien& sv : ketquatimkiem) {
            cout << "Ma: " << setw(20) << left << sv.getMa() << endl;
            cout << "Ten: " << setw(20) << left << sv.getTen() << endl;
            cout << "Lop: " << setw(20) << left << sv.getLop() << endl;
            cout << "GPA: " << setw(20) << left << sv.getGpa() << endl;
            cout << endl;
        }
    }
}


void sapxep(vector<SinhVien>& danhsachsinhvien){
	cout << setw(10) << "1. Sap xep theo ten!" << endl;
	cout << setw(10) << "2. Sap xep theo Gpa!" << endl;
	cout << setw(10) << "3. Sap xep theo lop!" << endl;
	cout << setw(10) << "4. Sap xep theo ID!" << endl;
	cout << "Nhap lua chon: " << endl;
	int n;
	cin >> n;
	switch(n){
		case 1: {
			sort(danhsachsinhvien.begin(), danhsachsinhvien.end(), cmp5);
			duyet(danhsachsinhvien);
			break;
		}
		case 2: {
			sort(danhsachsinhvien.begin(), danhsachsinhvien.end(), cmp1);
			duyet(danhsachsinhvien);
			break;
		}
		case 3:{
			sort(danhsachsinhvien.begin(), danhsachsinhvien.end(), cmp2);
			duyet(danhsachsinhvien);
			break;
		}
		case 4:{
			sort(danhsachsinhvien.begin(), danhsachsinhvien.end(), cmp3);
			duyet(danhsachsinhvien);
			break;
		}
	}
}



void indanhsachsinhvientufile(){
	ifstream in;
	in.open("dulieu.txt");
	if(in.is_open()){
		string s; 
		vector<SinhVien> v;
		while(getline(in,s)){
			
			stringstream ss(s);
			vector<string> a;
			string tmp;
			while(getline(ss, tmp, '|')){
				a.push_back(tmp);
			}
			//SinhVien(string ma, string ten, int tuoi, string sex, string lop, double gpa, string diachi)
			SinhVien x(a[0], a[1], stoi(a[2]),a[3], a[4], stod(a[5]), a[6]);
			x.chuanhoa();
			v.push_back(x);
		}
		// sinhvienx(a[0], a[1], a[2], stod(a[3]));
		// x.chuanhoa();
		// v.push_back(x);
//		for(sinhvien x : v){
//			ghifile(x, "data_out.txt");
//		}
		duyet(v);
	} else {
		cout << " khong tim thay file";
	}
	in.close();
}
int main() {
	vector<SinhVien> danhsachsinhvien;
    string input;
    
    while (true) {
        cout << "Danh sach thao tac :\n"
             << "1 - In danh sach SV vua nhap\n"
             << "2 - Them\n"
             << "3 - Sua\n"
             << "4 - Xoa\n"
             << "5 - Tim Kiem\n"
             << "6 - Sap xep\n"
             << "7 - Thong ke\n"
             << "8 - Sao luu\n"
             << "9 - In danh sach SV tu file\n"
             << "10 - Thoat\n";
        cout << "Nhap Lenh: ";
        cin >> input;

        if (input == "1") {
			duyet(danhsachsinhvien);
        } else if (input == "2") {
            them(danhsachsinhvien);
        } else if (input == "3") {
			edit(danhsachsinhvien);
        } else if (input == "4") {
			remove(danhsachsinhvien);
        } else if (input == "5") {
			timkiem(danhsachsinhvien);
        } else if (input == "6") {
			sapxep(danhsachsinhvien);
        } else if (input == "7") {
			thongke(danhsachsinhvien);
        } else if (input == "8") {
			saoLuu(danhsachsinhvien, "dulieu.txt");
        } else if (input == "9") {
        	indanhsachsinhvientufile();
		} 
		else if (input == "10") {
            break;
        }
		cout << "Press Enter to continue... ";
        cin.ignore();
        getline(cin, input);
        system("cls");
    }

    return 0;
}

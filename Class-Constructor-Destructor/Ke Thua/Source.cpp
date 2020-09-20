#include <iostream>

using namespace std;

class Nguoi {
protected: // access specifier (private protected và public)
	int NamSinh;
	string Ten;
	//friend class SinhVien;
	//friend class NuSinh;
public:
	Nguoi(){}
	Nguoi(int namsinh, string ten) {
		NamSinh = namsinh;
		Ten = ten;
	}
	void An() {
		cout << "\n " << Ten << " an 3 bat com 1 ngay";
	}
	void Xuat() { // vao cha sau
		cout << "\n Nguoi " << "ho ten : " << Ten;
		cout << "\n Nam sinh = " << NamSinh << endl;
	}
};

class SinhVien : public Nguoi { // kieu ke thua: private, protected, public
protected:
	string MSSV;
	//friend class NuSinh;
public:
	SinhVien(){}
	SinhVien(int namsinh, string ten, string maso) : Nguoi(namsinh, ten) {
		MSSV = maso;
		//Nguoi::An();
	}
	void Xuat() { // vao con truoc
		//cout << "\n Ho ten : " << Ten;
		//cout << "\n Nam sinh = " << NamSinh << endl;
		cout << "\n MSSV = " << MSSV << endl;
	}
};


class NuSinh : public SinhVien {
	float DiemMyThuat;
public:
	NuSinh(int namsinh, string ten, string mssv, float diemMT) : SinhVien(namsinh, ten, mssv) {
		DiemMyThuat = diemMT;
	}
	void Xuat() { // vao con truoc
		cout << "\n Ho ten : " << Ten;
		cout << "\n Nam sinh = " << NamSinh << endl;
		cout << "\n MSSV = " << MSSV << endl;
	}
};

int main() {
	/*Nguoi N(1996, "Canh");
	N.An();*/

	SinhVien SV(1996, "Canh", "13123123");
	SV.Xuat();
	return 0;
}



// 49
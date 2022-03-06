#include "Header.h"

void InputFraction(PS *ps) {
	cout << "Nhap tu so :";
	cin >> ps->tu;
	do {
		cout << "Nhap mau so :\n" ;
		cin >> ps->mau;
		if (ps->mau ==0 ) {
			cout << "Mau so phai khac 0!" ;
			break;
		}
		
	} while (ps->mau == 0);
}
PS* TaoPS() {
	PS* ps = new PS;
	InputFraction(ps);
	return ps;
}
void OutputFraction(PS ps) {
	cout << ps.tu << "/" << ps.mau;
}

istream& operator >>(istream& is, PS& ps) {
	
	do {
		cout << "Nhap tu so :";
		is >> ps.tu;
		cout << "Nhap mau so :";
		is >> ps.mau;
		if (ps.mau == 0) {
			cout << "Mau so phai khac 0\n";
		}
	} while (ps.mau == 0);
	return is;
}

ostream& operator<<(ostream& os,const PS& ps) {
	os << ps.tu << "/" << ps.mau;
	return os;
}

//PS operator+(PS ps1, PS ps2) {
//	PS x;
//	x.tu = (ps1.tu * ps2.mau) + (ps2.tu * ps1.mau);
//	x.mau = ps1.mau * ps2.mau;
//	return x;
//}
//PS operator -(PS& ps1, PS& ps2) {
//	PS x;
//	x.tu = (ps1.tu * ps2.mau) - (ps2.tu * ps1.mau);
//	x.mau = ps1.mau * ps2.mau;
//	return x;
//}
//PS operator *(PS& ps1, PS& ps2) {
//
//	PS x;
//	x.tu = ps1.tu * ps2.tu;
//	x.mau = ps1.mau * ps2.mau;
//	return x;
//}
//PS operator /(PS& ps1, PS& ps2) {
//
//	PS x;
//	x.tu = ps1.tu * ps2.mau;
//	x.mau = ps1.mau * ps2.tu;
//	return x;
//
//}



void XuLyMenu(PS(*standard)(PS, PS),PS ps1,PS ps2) {
	PS result = standard(ps1, ps2);
	cout << "Ket qua: " << result << endl;
}
PS SumFraction(PS ps1,PS ps2) {
	PS x;
	x.tu = (ps1.tu * ps2.mau) + (ps2.tu * ps1.mau);
	x.mau = ps1.mau * ps2.mau;
	return x;

}
PS MinusFraction(PS ps1, PS ps2) {
	PS x;
	x.tu = (ps1.tu * ps2.mau) - (ps2.tu * ps1.mau);
	x.mau = ps1.mau * ps2.mau;
	return x;
}
PS MutiplyFraction(PS ps1, PS ps2) {
	
	PS x;
	x.tu = ps1.tu * ps2.tu;
	x.mau= ps1.mau * ps2.mau;
	return x;
}
PS DivideFraction(PS ps1, PS ps2) {
	
	PS x;
	x.tu = ps1.tu * ps2.mau;
	x.mau= ps1.mau * ps2.tu;
	return x;

}
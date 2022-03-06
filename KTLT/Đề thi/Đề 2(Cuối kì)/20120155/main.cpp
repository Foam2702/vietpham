#include"Header.h"
int main() {
	list<string>DSXe = DocFile("VehicleError.txt");
	string ChuoiXe = DSchuoi_thanh_Chuoi(DSXe, '\n');
	cout << ChuoiXe;
	Chuoi_thanh_Xe(ChuoiXe);
	GhiFile("Report.txt", DSXe);

}
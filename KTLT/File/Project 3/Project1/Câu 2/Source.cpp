#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

struct PS {
	int tu=0;
	int mau=0;
};
struct DS {
	PS* ds_ps;
	int n=0;
};


void ReadFraction(PS& ps,ifstream &in) {
	
	in >> ps.tu;
	in >> ps.mau;
}
void fReadFile(string FileName, DS& ds) {
	ifstream in;
	if (in.is_open()) {
		in.close();
	}
	in.open(FileName);
	if (in.is_open()) {
		cout << "CONNECTION SUCCESSFUL" << endl;
		in >> ds.n;
		ds.ds_ps = new PS[ds.n];
		for (int i = 0; i < ds.n; i++) {
			ReadFraction(ds.ds_ps[i],in);
		}
	}
	in.close();
}
void Write_Sort_Decreasing_Arr(string FileName,DS& ds) {
	ofstream out;
	if (out.is_open()) {
		out.close();
	}
	out.open(FileName,ios_base::app);
	out << endl;
	
	if (out.is_open()) {
		out << "DANH SACH SAU KHI SAP XEP"<<endl;
		for (int i = 0; i < ds.n - 1; i++) {
			for (int j = i + 1; j < ds.n; j++) {
				if (((double)(ds.ds_ps[i].tu) / (double)(ds.ds_ps[i].mau))> (((double)ds.ds_ps[j].tu) / ((double)ds.ds_ps[j].mau))) {
					swap(ds.ds_ps[i], ds.ds_ps[j]);
					
				}
			}
		}
		for (int i = 0; i < ds.n; i++) {
			out << ds.ds_ps[i].tu << "/" << ds.ds_ps[i].mau << endl;
		}
		
	}
	out.close();
}
void ExportListPS(DS ds) {
	for (int i = 0; i < ds.n; i++) {
		cout << ds.ds_ps[i].tu << "/" << ds.ds_ps[i].mau << endl;
	}
}
int main() {
	DS ds;
	fReadFile("phanso.txt",ds);
	ExportListPS(ds);
	Write_Sort_Decreasing_Arr("phanso.txt",ds);
	return 0;

}
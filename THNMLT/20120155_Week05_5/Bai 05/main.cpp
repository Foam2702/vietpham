#include"Header.h"
int main()
{   
	int ngay, thang, nam,ngaysau,thangsau,namsau,ngaytruoc,thangtruoc,namtruoc;
	do
	{
		cout << "Nhap ngay: ";
		cin >> ngay;
		cout << "Nhap thang: ";
		cin >> thang;
		cout << "Nhap nam: ";
		cin >> nam;
		if (LaNgayHopLe(ngay, thang, nam) == false)
			cout << "Ngay thang nam khong phu hop" << endl;
	} while (LaNgayHopLe(ngay, thang, nam) == false);
		
	if (LaNgayHopLe(ngay, thang, nam))
		cout << ngay << "/" << thang << "/" << nam << " la ngay hop le" << endl;
	else
		cout << ngay << "/" << thang << "/" << nam << " khong la ngay hop le" << endl;
			
	NgayTruoc(ngay, thang, nam, ngaytruoc, thangtruoc, namtruoc);
			
		
	ngaySau(ngay, thang, nam, ngaysau, thangsau, namsau);
			
		
	if (ThuTuNgayTrongTuan(ngay, thang, nam) == 8)
		cout << "La chu nhat" << endl;
	else
		cout << "La ngay thu " << ThuTuNgayTrongTuan(ngay, thang, nam) << endl;
		
	
	cout << "La ngay thu " << ThuTuNgayTrongNam(ngay, thang, nam) << " trong nam" << endl;
			
	system("pause");
	
}


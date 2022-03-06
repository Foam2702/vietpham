#include <stdio.h>
#include <conio.h>
//#include <string.h> // không được xài thư viện này
#include <malloc.h>
#include <time.h>

int STRLEN(char *s)
{
	int i = 0;
	while(s[i] != '\0')
	{
		i++;
	}
	return i;
}

void XoaKyTu(char *s, int vitrixoa)
{
	int length = STRLEN(s);

	if(vitrixoa >= 0 && vitrixoa < length)
	{
		for(int i = vitrixoa + 1; i < length; ++i)
		{
			s[i - 1] = s[i];
		}
		s[length - 1] = '\0';
	}
}

void XoaTatCaKhoangTrangODau(char *s)
{
	int i = 0;
	
	while(s[i] == ' ')
	{
		XoaKyTu(s, i--);
		i++;
	}
}

void XoaTatCaKhoangTrangOCuoi(char *s)
{
	int length = STRLEN(s);
	int i = length - 1;

	while(s[i] == ' ')
	{
		XoaKyTu(s, i);
		i--;
	}
}

// Nguyên tắc: Gặp 2 khoảng trắng nằm cạnh nhau thì xóa đi 1
void XoaKhoangTrangThuaGiua2Tu(char *s)
{
	int length = STRLEN(s);
	for(int i = 0; i < length - 1; ++i) // nếu dùng vòng lặp này là phải i-- chỗ XoaKyTu => XoaKyTu(s, i--);
	//for(int i = length - 1; i >= 0; --i) // nếu dùng vòng lặp này là không cần i-- chỗ XoaKyTu => XoaKyTu(s, i);
	{
		if(s[i] == ' ' && s[i + 1] == ' ')
		{
			XoaKyTu(s, i--);
			length--; // cập nhật lại độ dài
		}
	}
}

void VietHoaKyTuDauTienConLaiVietThuongCuaMoiTu(char *s)
{
	int length = STRLEN(s);
	if(s[0] >= 'a' && s[0] <= 'z')
	{
		s[0] -= 32;
	}

	for(int i = 1; i < length; ++i)
	{
		if(s[i] != ' ')
		{
			if(s[i - 1] == ' ') // có nghĩa là s[i] là ký tự đầu tiên của từ
			{
				// Ký tự đầu tiên phải là ký tự HOA => kiểm tra nếu hiện tại đang là ký tự thường thì phải biến thành ký tự HOA
				if(s[i] >= 'a' && s[i] <= 'z')
				{
					s[i] -= 32;
				}

			}
			else // có nghĩa là s[i] không phải là ký tự đầu tiên của từ
			{
				// Ký tự không phải là đầu tiên phải là ký tự thường => kiểm tra nếu hiện tại đang là ký tự HOA thì phải biến thành ký tự thường
				if(s[i] >= 'A' && s[i] <= 'Z')
				{
					s[i] += 32;
				}
			}
		}
	}
}

char* ChuanHoaChuoi(char *s)
{
	int length = STRLEN(s);
	char *s1 = (char *)malloc(length);

	for(int i = 0; i <= length; ++i) // cho i chạy đến length để sao chép luôn ký tự \0
	{
		s1[i] = s[i];
	}

	XoaTatCaKhoangTrangODau(s1);
	XoaTatCaKhoangTrangOCuoi(s1);
	XoaKhoangTrangThuaGiua2Tu(s1);
	VietHoaKyTuDauTienConLaiVietThuongCuaMoiTu(s1);

	return s1;
}

char* ChuanHoaChuoi_CaiTien(char *s)
{
	int length = STRLEN(s);
	char *s1 = (char *)malloc(length);

	for(int i = 0; i <= length; ++i) // cho i chạy đến length để sao chép luôn ký tự \0
	{
		s1[i] = s[i];
	}

	/* Xóa khoảng trắng thừa ở đầu */
	int i = 0;
	
	while(s1[i] == ' ')
	{
		XoaKyTu(s1, i--);
		i++;
		length--;
	}
	/* ================ */

	/* Xóa khoảng trắng thừa ở cuối */
	i = length - 1;

	while(s1[i] == ' ')
	{
		XoaKyTu(s1, i);
		i--;
		length--;
	}
	/* ================ */

	// Xét in hoa ký tự đầu tiên của từ đầu tiên
	if(s1[0] >= 'a' && s1[0] <= 'z')
	{
		s1[0] -= 32;
	}

	// Xóa khoảng trắng thừa giữa 2 từ và in hoa in thường các ký tự ở các vị trí
	for(int i = 1; i < length; ++i)
	{
		if(s1[i] == ' ' && s1[i + 1] == ' ') // Xóa khoảng trắng thừa giữa 2 từ
		{
			XoaKyTu(s1, i--);
			length--; // cập nhật lại độ dài
		}
		else if(s1[i] != ' ') // in hoa ký tự đầu tiên của mỗi từ còn lại in thường
		{
			if(s1[i - 1] == ' ') // có nghĩa là s[i] là ký tự đầu tiên của từ
			{
				// Ký tự đầu tiên phải là ký tự HOA => kiểm tra nếu hiện tại đang là ký tự thường thì phải biến thành ký tự HOA
				if(s1[i] >= 'a' && s1[i] <= 'z')
				{
					s1[i] -= 32;
				}

			}
			else // có nghĩa là s[i] không phải là ký tự đầu tiên của từ
			{
				// Ký tự không phải là đầu tiên phải là ký tự thường => kiểm tra nếu hiện tại đang là ký tự HOA thì phải biến thành ký tự thường
				if(s1[i] >= 'A' && s1[i] <= 'Z')
				{
					s1[i] += 32;
				}
			}
		}
	}
	return s1;
}

char* ChuanHoaChuoi_Cach2(char *s)
{
	int length = STRLEN(s);
	char *s1 = (char *)malloc(length);

	int i = 0; // index của chuỗi s ban đầu
	int j = 0; // index của chuỗi s1 kết quả

	while(s[i] == ' ')
		i++;

	s1[j++] = s[i++]; // thêm ký tự đầu tiên khác khoảng trống trong chuỗi s vào s1
	if(s1[0] >= 'a' && s1[0] <= 'z') // Kiểm tra ký tự đầu tiên nếu đang viết thường thì biến thành viết hoa
	{
		s1[0] -= 32;
	}

	while(i < length)
	{
		if(s[i] != ' ')
		{
			if(s[i - 1] == ' ') // có nghĩa là s[i] hiện tại là ký tự đầu tiên của 1 từ => ta cần phải biến thành chữ hoa nếu nó đang là chữ thường sau đó bỏ nó qua chuỗi s1. Lưu ý: Trước đó chuỗi s1 phải thêm 1 khoảng trắng vì đã bắt đầu sang 1 từ mới
			{
				s1[j++] = ' '; // Thêm ký tự khoảng trắng vào s1
				s1[j] = s[i];
				if(s1[j] >= 'a' && s1[j] <= 'z')
				{
					s1[j] -= 32;
				}
				j++;
			}
			else // có nghĩa là s[i] không phải là ký tự đầu tiên của từ => kiểm tra nếu hiện tại đang là ký tự HOA thì phải biến thành ký tự thường
			{
				s1[j] = s[i];
				if(s1[j] >= 'A' && s1[j] <= 'Z')
				{
					s1[j] += 32;
				}
				j++;
			}
		}
		i++;
	}
	s1[j] = '\0'; // Kết thúc chuỗi s1
	return s1;
}

int main()
{
	char s[] = "                          NGUYen                         VIET                      NAM                          SoN                                                ";
	//char s[] = "  kY    tHUat   lAp trINh ";      
	//char s[] = "                        Voi             vu an nay,                 sau khi va             cham, oto Innova bat buoc phai bi dich chuyen. Tuy nhien, do xe bi dam khi dang di lui nen phuong tien khong the            tu tien ve phia truoc, ma bi day miet di. Do do, vet              lop o cac vi tri co               the                dam hoac                      nhat. Day cung la mot trong nhung can                        cu de tim ra diem va c             ham ban dau.                ";
	
	printf("\ns = %s", s);
	
	char *s1 = ChuanHoaChuoi_Cach2(s);
	printf("\ns1 = %s", s1);

	/*
	char *a1, *a2, *a3;

	clock_t start1 = clock();
	for(int i = 1; i <= 100000; ++i)
	a1 = ChuanHoaChuoi(s);
	clock_t end1 = clock();
	printf("\nChuoi sau khi chuan hoa la:%s", a1);
	printf("\ns =%s", s);

	clock_t start2 = clock();
	for(int i = 1; i <= 100000; ++i)
	a2 = ChuanHoaChuoi_CaiTien(s);
	clock_t end2 = clock();
	printf("\nChuoi sau khi chuan hoa la:%s", a2);
	printf("\ns =%s", s);

	clock_t start3 = clock();
	for(int i = 1; i <= 100000; ++i)
	a3 = ChuanHoaChuoi_Cach2(s);
	clock_t end3 = clock();
	printf("\nChuoi sau khi chuan hoa la:%s", a3);
	printf("\ns =%s", s);

	printf("\nChuanHoaChuoi chay mat %lf giay", (double)(end1 - start1)/CLOCKS_PER_SEC);
	printf("\nChuanHoaChuoi_CaiTien chay mat %lf giay", (double)(end2 - start2)/CLOCKS_PER_SEC);
	printf("\nChuanHoaChuoi_Cach2 chay mat %lf giay", (double)(end3 - start3)/CLOCKS_PER_SEC);
	*/

	getch();
	return 0;
}
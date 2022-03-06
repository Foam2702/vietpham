#include <iostream>
#include <string>
using namespace std;

int STRLEN(string s)
{
	int i = 0;
	while(s[i] != '\0')
	{
		i++;
	}
	return i;
}

string ChuanHoaChuoi_Cach2(string s)
{
	//int length = STRLEN(s);
	string s1;

	int i = 0; // index của chuỗi s ban đầu
	int j = 0; // index của chuỗi s1 kết quả

	while(s[i] == ' ')
		i++;

	s1.push_back(s[i++]);
	j++;
	
	if(s1[0] >= 'a' && s1[0] <= 'z') // Kiểm tra ký tự đầu tiên nếu đang viết thường thì biến thành viết hoa
	{
		s1[0] -= 32;
	}

	//while(i < length)
	while(s[i] != '\0')
	{
		if(s[i] != ' ')
		{
			if(s[i - 1] == ' ') // có nghĩa là s[i] hiện tại là ký tự đầu tiên của 1 từ => ta cần phải biến thành chữ hoa nếu nó đang là chữ thường sau đó bỏ nó qua chuỗi s1. Lưu ý: Trước đó chuỗi s1 phải thêm 1 khoảng trắng vì đã bắt đầu sang 1 từ mới
			{
				s1.push_back(' ');
				j++;
				s1.push_back(s[i]);

				if(s1[j] >= 'a' && s1[j] <= 'z')
				{
					s1[j] -= 32;
				}
				j++;
			}
			else // có nghĩa là s[i] không phải là ký tự đầu tiên của từ => kiểm tra nếu hiện tại đang là ký tự HOA thì phải biến thành ký tự thường
			{
				s1.push_back(s[i]);
				
				if(s1[j] >= 'A' && s1[j] <= 'Z')
				{
					s1[j] += 32;
				}
				j++;
			}
		}
		i++;
	}
	return s1;
}

int main()
{
	string s = "                          NGUYen                         VIET                      NAM                          SoN                                                ";
	//string s = "  kY    tHUat   lAp trINh ";      
	//string s = "                        Voi             vu an nay,                 sau khi va             cham, oto Innova bat buoc phai bi dich chuyen. Tuy nhien, do xe bi dam khi dang di lui nen phuong tien khong the            tu tien ve phia truoc, ma bi day miet di. Do do, vet              lop o cac vi tri co               the                dam hoac                      nhat. Day cung la mot trong nhung can                        cu de tim ra diem va c             ham ban dau.                ";

	cout << "\ns = " << s;
	
	//char *s1 = ChuanHoaChuoi_Cach2(s);
	//printf("\ns1 = %s", s1);

	string s1 = ChuanHoaChuoi_Cach2(s);
	cout << "\ns1 = " << s1;

	system("pause");
	return 0;
}
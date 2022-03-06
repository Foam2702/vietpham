/*
Hướng đi 2: Kiểm tra xem vị trí đặt dấu ngoặc đó có hợp lệ không
Tức là: 
1. Ký tự tiếp theo sau khi mở ngoặc hoặc ký tự trước khi đóng ngoặc phải là ký tự số hoặc là 1 ngoặc chứ không thể là 1 phép tính được
2. Cặp ngoặc phải khớp nhau

vd:
( 1 + 2 ) ) + ( 3 + 4 ) (

( 1 + 2 )

=> Nếu thích thì thử sức giải thuật với đề bài dãy ngoặc đúng (biểu thức toán học đúng): http://ntucoder.net/Problem/Details/3270

Ý Tưởng: Nếu đã có đóng ngoặc thì trước đó phải đảm bảo có mở ngoặc để đi 1 cặp với nhau

Cách làm: Có 1 biến đếm mở ngoặc, xét lần lượt từng ký tự của biểu thức. Gặp ký tự mở ngoặc thì tăng biến đếm mở ngoặc lên. Nếu gặp ký tự đóng ngoặc thì kiểm tra nếu biến đếm mở ngoặc = 0 thì kết luận ngay false (thiếu dấu mở ngoặc), nếu biến đếm mở ngoặc khác 0 => trừ đi 1 đơn vị sau đó xét tiếp sang ký tự tiếp theo và lặp lại quy trình xét trên nếu đến cuối cùng của biểu thức mà biến đếm mở ngoặc = 0 => true, còn nếu biến đếm mở ngoặc khác 0 => false (dư dấu mở ngoặc)
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//string s = "( 1 + 2 * ( ( 3 + 4 ) )";
	string s = "()((";

	int dem_mongoac = 0;
	int length = s.length();
	for(int i = 0; i < length; ++i)
	{
		if(s[i] == '(')
			dem_mongoac++;
		else if(s[i] == ')')
		{
			if(dem_mongoac == 0) // thiếu dấu mở ngoặc
			{
				cout << "false";
				system("pause");
				return 0;
			}
			else
				dem_mongoac--; // triệt tiêu với dấu đóng ngoặc làm 1 cặp
		}
	}

	// Đến cuối cùng kiểm tra
	if(dem_mongoac == 0)
		cout << "true";
	else
		cout << "false"; // dư dấu mở ngoặc

	system("pause");
	return 0;
}
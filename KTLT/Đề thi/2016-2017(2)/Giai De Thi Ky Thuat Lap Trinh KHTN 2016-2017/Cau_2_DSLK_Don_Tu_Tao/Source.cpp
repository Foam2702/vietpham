#include <iostream>
#include <string>
using namespace std;
#define MAX 30

/* Bước 1: Khai báo cấu trúc danh sách liên kết */

struct Node
{
	char Data;
	struct Node *pNext;
};
typedef struct Node NODE;

struct List
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct List LIST;

/* ============ End Bước 1 ============= */

/* Bước 2: Khởi tạo danh sách liên kết */

void Init(LIST &l)
{
	l.pHead = l.pTail = NULL;
}

/* ============ End Bước 2 ============= */

/* Bước 3: Tạo Node */

NODE* GetNode(char dulieu)
{
	NODE* x = new NODE;

	if(x == NULL)
	{
		cout << "\nKhong du vung nho de cap phat Node";
		system("pause");
		return NULL;
	}

	x->Data = dulieu;
	x->pNext = NULL;
	return x;
}

/* ============ End Bước 3 ============= */

/* Bước 4: Viết hàm thêm dữ liệu vào đầu/cuối danh sách */

void AddHead(LIST &l, NODE *new_ele)
{
	// Nếu danh sách rỗng
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = new_ele;
	}
	else // Danh sách đang có sẵn Node (phần tử)
	{
		new_ele->pNext = l.pHead;
		l.pHead = new_ele;
	}
}

void AddTail(LIST &l, NODE *new_ele)
{
	// Nếu danh sách rỗng
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = new_ele;
	}
	else // Danh sách đang có sẵn Node (phần tử)
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

/* ============ End Bước 4 ============= */

/* Bước 5: Nhập/xuất danh sách liên kết */

void NhapDuLieu(string &str, LIST &l)
{
	bool KiemTraVietThuong;
	int length;
	do{
		KiemTraVietThuong = true;

		cout << "\nNhap vao chuoi: ";
		//cin >> str; // char str[100]; scanf("%s", str);
		getline(cin, str); // gets(str);

		length = str.length();
		for(int i = 0; i < length; ++i)
		{
			if(str[i] >= 'A' && str[i] <= 'Z')
			{
				KiemTraVietThuong = false;
				break;
			}
		}

		if(length > MAX)
			cout << "\nChuoi ky tu chi duoc phep toi da " << MAX << " ky tu. Xin kiem tra lai!";
		
		if(KiemTraVietThuong == false)
			cout << "\nTat ca cac ky tu trong chuoi phai viet thuong. Xin kiem tra lai!";

	}while(length > MAX || KiemTraVietThuong == false);

	// Khi chuỗi đã hợp lệ thì sẽ tiến hành bóc tách từng ký tự trong chuỗi lưu vào danh sách liên kết

	Init(l); // Khởi tạo danh sách thì mới nhập liệu cho nó được

	for(int i = 0; i < length; ++i)
	{
		NODE *p = GetNode(str[i]);
		//AddTail(l, p);
		AddHead(l, p);
	}
}

void XuatDuLieu(LIST l)
{
	// for(int i = 0; i < n; i++)
	//cout << "\nXuat theo chieu xuoi: ";
	for(NODE *p = l.pHead; p != NULL; p = p->pNext) //for(auto it = l.begin(); it != l.end(); ++it)
		cout << p->Data << endl;
}

/* ============ End Bước 5 ============= */

/* Bước 6: Xử lý những vấn đề liên quan */

// true: nếu giống nhau; false: nếu không giống nhau
// Cách làm: Chỉ cần kiểm tra tại vị trí bất kỳ có sự khác nhau => lập tức kết luận không giống nhau. Còn nếu đi đến cuối cùng danh sách mà tất cả đều giống nhau => giống nhau
bool KiemTraDanhSachDaoNguocGiongBanDau(LIST l, string str)
{
	//forward_list<char>::iterator it = l.begin();
	NODE* p = l.pHead;
	int size = str.length();
	for(int i = 0; i < size / 2; ++i, p = p->pNext)
	{
		if(str[i] != p->Data)
			return false;
	}
	return true;
}

int DemSoLuongPhanTuTrongList(LIST l)
{
	int count = 0;
	//for(forward_list<char>::iterator it = l.begin(); it != l.end(); ++it)
	for(NODE *p = l.pHead; p != NULL; p = p->pNext)
		count++;

	return count;
}

char LayPhanTuTaiViTri(LIST l, int index)
{
	NODE* p = l.pHead;
	for(int i = 1; i <= index; ++i)
	{
		p = p->pNext;
	}
	return p->Data;
}

bool KiemTraDanhSachDaoNguocGiongBanDau_Cach2(LIST l)
{
	int size = DemSoLuongPhanTuTrongList(l);

	for(int i = 0; i < size / 2; ++i)
	{
		if(LayPhanTuTaiViTri(l, i) != LayPhanTuTaiViTri(l, size - 1 - i))
			return false;
	}
	return true;
}

bool KiemTraDanhSachDaoNguocGiongBanDau_Cach2CaiTien(LIST l)
{
	int size = DemSoLuongPhanTuTrongList(l);

	for(int i = 0; i < size / 2; ++i)
	{
		int vt_i = i, vt_j = size - 1 - i;
		int dem = 0;
		char x, y;
		//for(forward_list<char>::iterator it = l.begin(); it != l.end(); ++it, dem++)
		for(NODE *p = l.pHead; p != NULL; p = p->pNext, dem++)
		{
			if(dem == vt_i)
			{
				x = p->Data;
				//cout << "\nvt_i = " << vt_i << " => " << *it; 
			}
			else if(dem == vt_j)
			{
				y = p->Data;

				if(x != y)
					return false;
				else
					break;

				//cout << "\nvt_j = " << vt_j << " => " << *it; 
			}
		}
	}
	return true;
}

/* ============ End Bước 6 ============= */

/* Bước 7: Giải phóng danh sách liên kết */

void GiaiPhongDanhSach(LIST &l)
{
	NODE* thimang;
	while (l.pHead != NULL)
	{
		thimang = l.pHead;
		l.pHead = l.pHead->pNext;
		delete thimang;
	}
}

/* ============ End Bước 7 ============= */

int main()
{
	LIST l;
	string str;

	NhapDuLieu(str, l);
	XuatDuLieu(l);

	bool KiemTra = KiemTraDanhSachDaoNguocGiongBanDau_Cach2CaiTien(l);
	if(KiemTra == true)
		cout << "\nDanh sach sau khi dao lai giong ban dau";
	else
		cout << "\nDanh sach sau khi dao lai khac ban dau";
	
	GiaiPhongDanhSach(l);

	system("pause");
	return 0;
}
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

struct HocSinh
{
	char Ma[10];
	char Ten[30];
	char DiaChi[50];
	float DiemTrungBinh;
};
typedef struct HocSinh HOCSINH;

void NhapHocSinh(HOCSINH &x)
{
	fflush(stdin);
	printf("\nNhap vao ten: ");
	gets(x.Ten);

	fflush(stdin);
	printf("\nNhap vao dia chi: ");
	gets(x.DiaChi);

	do{
		printf("\nNhap vao diem trung binh: ");
		scanf("%f", &x.DiemTrungBinh);

		if(x.DiemTrungBinh < 0 || x.DiemTrungBinh > 10)
			printf("\nDiem trung binh chi duoc phep nam trong doan tu 0 den 10. Xin kiem tra lai!");

	}while(x.DiemTrungBinh < 0 || x.DiemTrungBinh > 10);
}

void XuatHocSinh(HOCSINH x)
{
	printf("\nMa so: %s", x.Ma);
	printf("\nTen: %s", x.Ten);
	printf("\nDia chi: %s", x.DiaChi);
	printf("\nDiem trung binh: %f", x.DiemTrungBinh); 
}

/* 1/ Khai báo cấu trúc danh sách liên kết đơn */

struct Node
{
	HOCSINH Data; // Data là dữ liệu chứa trong danh sách liên kết đơn. Do chúng ta đang làm là danh sách các số nguyên nên Data sẽ là số nguyên
	struct Node *pNext; // con trỏ pNext để trỏ tới Node kế tiếp
};
typedef struct Node NODE;

struct List
{
	NODE *pHead, *pTail; // Node đầu, Node cuối danh sách
};
typedef struct List LIST;

/* End Bước 1 */

/* 2/ Khởi tạo danh sách liên kết đơn */

void INit(LIST &l)
{
	l.pHead = l.pTail = NULL;
}

/* End bước 2 */

/* 3/ Tạo Node <=> đưa Data vào và từ đó tạo ra Node chứa data đó */

NODE* GetNode(HOCSINH hocsinh)
{
	//NODE *x = new NODE; // Cấp phát con trỏ bên C++
	NODE *x = (NODE *)malloc(sizeof(NODE));

	if(x == NULL)
	{
		printf("\nKhong du bo nho de cap phat Node x");
		getch();
		return NULL;
	}

	x->Data = hocsinh; // đưa Data vào trong Node
	x->pNext = NULL; // Tạo ra mối liên kết đến Node tiếp theo
	return x;
}

/* End bước 3 */

/* 4/ Thêm Node vào đầu/cuối danh sách */

void AddHead(LIST &l, NODE *new_ele) // thêm new_ele vào đầu của l
{
	if(l.pHead == NULL) // nếu danh sách đang rỗng
	{
		l.pHead = l.pTail = new_ele; // Node new_ele chính là node đầu và cũng là node cuối luôn
	}
	else // trong trường hợp danh sách đang có phần tử (không rỗng)
	{
		new_ele->pNext = l.pHead; // cập nhật mối liên kết của new_ele với node đầu tiên hiện tại
		l.pHead = new_ele; // cập nhật lại vị trí node đầu tiên lúc này chính là new_ele
	}
}

void AddTail(LIST &l, NODE *new_ele) // thêm new_ele vào cuối của l
{
	if(l.pHead == NULL) // nếu danh sách đang rỗng
	{
		l.pHead = l.pTail = new_ele; // Node new_ele chính là node đầu và cũng là node cuối luôn
	}
	else // trong trường hợp danh sách đang có phần tử (không rỗng)
	{
		l.pTail ->pNext = new_ele; // Cập nhật mối liên kết của Node cuối hiện tại với Node new_ele
		l.pTail = new_ele; // Cập nhật lại vị trí Node cuối lúc này chính là new_ele
	}
}

/* End bước 4 */

/* 5/ Nhập dữ liệu/Xuất dữ liệu */

void NhapDanhSach(LIST &l)
{
	int n;

	do{
		printf("\nNhap vao so luong hoc sinh co trong danh sach: ");
		scanf("%d", &n);

		if(n < 0)
			printf("\nSo luong hoc sinh khong duoc la so am. Xin kiem tra lai!");
	}while(n < 0);

	INit(l); // Khởi tạo danh sách

	for(int i = 1; i <= n; ++i)
	{
		//printf("\nNhap vao so nguyen thu %d la: ", i);
		//int x;
		//scanf("%d", &x);
		//NODE *p = GetNode(x);
		//AddTail(l, p);
		////AddHead(l, p);

		HOCSINH x;
		printf("\nNhap vao hoc sinh thu %d:", i);
		
		bool Check;
		do{
			fflush(stdin);
			printf("\nNhap vao ma so: ");
			gets(x.Ma);

			Check = false; // mặc định là false tức là không bị trùng
			for(NODE *p = l.pHead; p != NULL; p = p ->pNext) // vòng lặp duyệt qua danh sách các học sinh đang có hiện tại kiểm tra xem mã số vừa nhập cho học sinh mới có bị trùng với các mã số đã có của các học sinh trước đó hay không?
			{
				if(strcmp(p->Data.Ma, x.Ma) == 0) // Nếu bị trùng => cập nhật Check = true - dừng vòng lặp lại và bắt nhập lại
				{
					printf("\nMa so nay da bi trung voi cac hoc sinh truoc do. Xin vui long nhap lai!");
					Check = true;
					break; // đã phát hiện bị trùng thì không cần duyệt tiếp nữa
				}
			}
		}while(Check == true);

		NhapHocSinh(x);
		NODE *p = GetNode(x);
		AddTail(l, p);
	}
}

void XuatDanhSach(LIST l)
{
	//for(int i = 0; i < n; ++i)
	int dem = 1;
	for(NODE *p = l.pHead; p != NULL; p = p->pNext)
	{
		printf("\n\nThong tin hoc sinh thu %d la", dem++);
		XuatHocSinh(p->Data);
	}
}

/* End bước 5 */

/* 6/ Các vấn đề xử lý trên danh sách */

void XoaCacHocSinhDiemTrungBinhDuoi5(LIST &l)
{
	// duyệt vòng lặp thấy Node nào chứa số chẵn thì xóa Node đó đi
	NODE *q = l.pHead;
	for(NODE *p = l.pHead ->pNext; p != NULL; p = p ->pNext)
	{
		if(p ->Data.DiemTrungBinh < 5)
		{
			// Xóa Node p: Tìm ra Node trước Node p và Node sau Nopde p và cho 2 Node này nối với nhau rồi yên tâm xóa p đi
			NODE *thimang = p; // trỏ đến p nằm chờ sẵn
			q->pNext = p->pNext; // Thiết lập mối liên kết của Node trước p và Node sau p
			p = q;
			delete thimang;
			
		}
		q = p; // Cho q tiến lên là nút p để chuẩn bị p lặp Next sang lần tiếp theo thì q là Node trước p
	}

	// Kiểm tra riêng trường hợp nếu đầu danh sách là số chẵn thì xóa đi
	if(l.pHead != NULL)
	{
		if(l.pHead ->Data.DiemTrungBinh < 5)
		{
			// Xóa l.pHead
			NODE *thimang = l.pHead;
			l.pHead = l.pHead ->pNext;
			delete thimang;
		}
	}
}

/* End bước 6 */

/* 7/ Giải phóng danh sách liên kết đơn */

void GiaiPhongDanhSach(LIST &l)
{
	NODE *thimang;
	while(l.pHead != NULL)
	{
		thimang = l.pHead;
		l.pHead = l.pHead ->pNext;
		delete thimang;
	}
}

/* End bước 7 */

int main()
{
	LIST l;
	NhapDanhSach(l);
	XuatDanhSach(l);

	printf("\nDanh sach sau khi xoa tat ca cac hoc sinh co diem trung binh duoi 5 la\n");
	XoaCacHocSinhDiemTrungBinhDuoi5(l);
	XuatDanhSach(l);

	GiaiPhongDanhSach(l);

	getch();
	return 0;
}
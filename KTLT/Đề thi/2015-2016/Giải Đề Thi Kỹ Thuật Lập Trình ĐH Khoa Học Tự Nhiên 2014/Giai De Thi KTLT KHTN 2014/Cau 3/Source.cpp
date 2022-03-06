#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stack>
using namespace std;

void XuatHe2(long n) 
{
	// 1: Điều kiện dừng
	if(n == 0)
		return; // kết thúc hàm
	
	XuatHe2(n / 2); // 2: Bước lặp
	printf("%d", n % 2);
}

void XuatHe8(long n) 
{
	// 1: Điều kiện dừng
	if(n == 0)
		return; // kết thúc hàm
	
	XuatHe8(n / 8); // 2: Bước lặp
	printf("%d", n % 8);
}

void XuatHe16(long n) 
{
	// 1: Điều kiện dừng
	if(n == 0)
		return; // kết thúc hàm
	
	XuatHe16(n / 16); // 2: Bước lặp
	
	int x = n % 16;
	if(x < 10)
		printf("%d", x);
	else if(x == 10)
		printf("A");
	else if(x == 11)
		printf("B");
	else if(x == 12)
		printf("C");
	else if(x == 13)
		printf("D");
	else if(x == 14)
		printf("E");
	else if(x == 15)
		printf("F");
}

void DoiHe_DeQuy(long n, int he)
{
	// 1: Điều kiện dừng
	if(n == 0)
		return; // kết thúc hàm
	
	DoiHe_DeQuy(n / he, he); // 2: Bước lặp
	
	int x = n % he;
	if(x < 10)
		printf("%d", x);
	else if(x == 10)
		printf("A");
	else if(x == 11)
		printf("B");
	else if(x == 12)
		printf("C");
	else if(x == 13)
		printf("D");
	else if(x == 14)
		printf("E");
	else if(x == 15)
		printf("F");
}

void DoiHe_DungMang(long n, int he)
{
	int a[100];
	int size = 0;

	while(n != 0) // Điều kiện lặp là n phải khác 0. Nếu bằng 0 thì quá trình lặp dừng lại
	{
		a[size++] = n % he;
		n /= he; // Bước lặp
	}

	for(int i = size - 1; i >= 0; --i)
	{
		if(a[i] < 10)
			printf("%d", a[i]);
		else if(a[i] == 10)
			printf("A");
		else if(a[i] == 11)
			printf("B");
		else if(a[i] == 12)
			printf("C");
		else if(a[i] == 13)
			printf("D");
		else if(a[i] == 14)
			printf("E");
		else if(a[i] == 15)
			printf("F");
	}
}

void DoiHe_DungNganXepStack(long n, int he)
{
	stack<int> nganxep;

	while(n != 0) // Điều kiện lặp là n phải khác 0. Nếu bằng 0 thì quá trình lặp dừng lại
	{
		nganxep.push(n % he);
		n /= he;
	}

	// Lấy các giá trị ra khỏi ngăn xếp
	while(!nganxep.empty())
	{
		int x = nganxep.top(); // lấy phần tử trên cùng của ngăn xếp
		nganxep.pop(); // bỏ phần tử đầu tiên đi (bởi vì đã lấy ra rồi)

		if(x < 10)
		printf("%d", x);
		else if(x == 10)
			printf("A");
		else if(x == 11)
			printf("B");
		else if(x == 12)
			printf("C");
		else if(x == 13)
			printf("D");
		else if(x == 14)
			printf("E");
		else if(x == 15)
			printf("F");
	}
}

int main()
{
	int n = 25;
	printf("\nxuat so %d he 2 la: ", n);
	//XuatHe2(n);
	//DoiHe_DeQuy(n, 2);
	DoiHe_DungMang(n, 2);
	//DoiHe_DungNganXepStack(n, 2);

	//printf("\nxuat so %d he 8 la: ", n);
	////XuatHe8(n);
	////DoiHe_DeQuy(n, 8);
	////DoiHe_DungMang(n, 8);
	//DoiHe_DungNganXepStack(n, 8);

	//printf("\nxuat so %d he 16 la: ", n);
	////XuatHe16(n);
	////DoiHe_DeQuy(n, 16);
	////DoiHe_DungMang(n, 16);
	//DoiHe_DungNganXepStack(n, 16);

	/*printf("\nSo %d he 8 la %o", n, n);
	printf("\nSo %d he 16 la %X", n, n);*/

	getch();
	return 0;
}
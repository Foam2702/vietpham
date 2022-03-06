#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;

// giải bằng phương pháp quy hoạch động
int CountSolution(int n)
{
	int P1 = 1;
	int P2 = 2;

	if(n == 1)
		return P1;

	if(n == 2)
		return P2;

	// Từ khúc này trở xuống tức là n >= 3
	int Pn=0;
	for(int i = 3; i <= n; ++i)
	{
		// P2 chính là P(n - 1)
		// P1 chính là P(n - 2)
		Pn = P1 + P2;

		P1 = P2;
		P2 = Pn;
	}
	return Pn;
}

int CountSolution_DeQuy(int n)
{
	if(n == 1)
		return 1;

	if(n == 2)
		return 2;

	return CountSolution_DeQuy(n - 1) + CountSolution_DeQuy(n - 2);
}

void InChiTietCacPhuongAn(int n)
{
	vector<vector<int>> P1(1); // 1 dòng
	P1[0].push_back(1); // đưa số 1 vào vị trí đầu tiên của dòng 1

	vector<vector<int>> P2(2); // 2 dòng
	P2[0].push_back(1);
	P2[0].push_back(1);
	P2[1].push_back(2);

	vector<vector<int>> Pn; // kết quả các bước đi của các phương án của P(n)

	if(n == 1)
		Pn = P1;
	else if(n == 2)
		Pn = P2;

	// Từ khúc này trở xuống tức là n >= 3
	for(int k = 3; k <= n; ++k)
	{
		// P2 chính là P(n - 1) => 1 + P(n - 1)
		// P1 chính là P(n - 2) => 2 + P(n - 2)
		//Pn = P1 + P2;
		Pn = P2; // gán các bước đi của P2 qua Pn

		// Thêm số 1 vào vị trí cột đầu tiên của tất cả các dòng có trong Pn
		for(int i = 0; i < Pn.size(); ++i)
		{
			Pn[i].insert(Pn[i].begin() + 0, 1);
		}

		// Sau khi đã thiết lập xong các bước đi ở TH1 ta xét tiếp TH2 để nối TH2 vào TH1 để ra được tổng số lượng các phương án bước đi
		// Chạy hết tất cả các dòng của P1 và với mỗi dòng chúng ta thêm dòng đó vào Pn và nhớ thêm số 2 vào đầu mỗi dòng Pn
		for(int i = 0; i < P1.size(); ++i)
		{
			Pn.push_back(P1[i]); // thêm dòng P1[i] vào mảng 2 chiều Pn
			Pn[Pn.size() - 1].insert(Pn[Pn.size() - 1].begin() + 0, 2); // Thêm cột chứa số 2 vào vị trí cột đầu tiên của dòng vừa được thêm từ P1
		}

		P1 = P2;
		P2 = Pn;
	}

	// Xuất kết quả các bước đi trong từng phương án của Pn
	for(int i = 0; i < Pn.size(); ++i)
	{
		cout << "Phuong an " << i + 1 << ": ";
		for(int j = 0; j < Pn[i].size() - 1; ++j)
		{
			cout << "buoc " << Pn[i][j] << " bac -> ";
		}
		cout << "buoc " << Pn[i][Pn[i].size() - 1] << " bac";
		cout << endl;
	}
}

int main()
{
	int n = 12;
	printf("\nCau thang co %d bac => co %d phuong an\n", n, CountSolution(n));
	InChiTietCacPhuongAn(n);

	/*clock_t start1 = clock();
	for(int i = 1; i <= 10; ++i)
	printf("\nCau thang co %d bac => co %d phuong an", n, CountSolution(n));
	clock_t end1 = clock();
	printf("\nPhuong phap quy hoach dong chay mat %lf giay", (double)(end1 - start1) / CLOCKS_PER_SEC);

	clock_t start2 = clock();
	for(int i = 1; i <= 10; ++i)
	printf("\nCau thang co %d bac => co %d phuong an", n, CountSolution_DeQuy(n));
	clock_t end2 = clock();

	printf("\nPhuong phap de quy chay mat %lf giay", (double)(end2 - start2) / CLOCKS_PER_SEC);*/

	getch();
	return 0;
}
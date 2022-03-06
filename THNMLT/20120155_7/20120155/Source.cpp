#include"Header.h"



void Input1(int &n)
{
	
	do
	{
		cout << "Nhap so nguyen duong n:";
		cin >> n;
		if (n < 9 || n>90000)
		{
			cout << "n phai thuoc doan [9;90000]" << endl;
		}
	} while (n < 9 || n > 90000);
}

bool Kiemtra_Sochinhphuong(int n)
{
	for (int i = 0; i * i <= n; i++)
	{
		if (i * i == n)
			return true;
	}
	return false;
}
bool Kiemtra_SNT(int n)
{
	if (n < 2)
		return false;
	else
	{
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
				return false;
		}
	}
	return true;
}
void In_SochinhPhuong_nhoHon_n_Chiahetcho3(int &n)
{
	int count = 0;
	for (int i = 9; i < n; i++)
	{	
		if (Kiemtra_SNT(i)==false)
		{
			if ((i % 3) == 0 && Kiemtra_Sochinhphuong(i) == true)
			{
				cout << i << " ";
				count++;
			}
		}
		
	}
	cout << endl;
	if (count == 0)
	{
		cout << "Khong co so chinh phuong hop le";
	}
	else {
		cout << "Co " << count << " so chinh phuong";
	}
}


void Input2( int &n)
{
	do
	{
		cout << "Nhap so nguyen duong n:";
		cin >> n;
		if (n < 1000 || n > 1000000000)
		{
			cout << "n phai thuoc doan [1000;1000000000]" << endl;
		}
	} while (n < 1000 || n > 1000000000);
}

int TinhTong_cacvitriLe(int n)
{	
	int sum = 0, temp = n,count=0;
	while (temp != 0)
	{
		temp /= 10;
		count++;
	}
	temp = n;
	if (count % 2 == 0)
	{
		temp /= 10;
	}
		
		
	for (int i = 1; i <= n; i++)
	{
		int r = temp % 10;
		if (i % 2 != 0)
		{
			sum += r;

		}
		temp /= 10;
	}

	
	
	
	return sum;
}

void Input3(int& n)
{
	do
	{
		cout << "Nhap so nguyen duong n:";
		cin >> n;
		if (n < 999 || n > 999999999)
		{
			cout << "n phai toi thieu 4 chu so,toi da 9 cho so" << endl;
		}
	} while (n < 999 || n > 999999999);
}

void Kiemtra_DangSong(int n)
{	
	int temp = n;
	bool checkmax = true;
	bool checkmin = true;
	while (temp != 0)
	{
		int r1 = temp % 10;
		int r2 = temp % 100;
		if (r1 < r2)
		{
			
			checkmax = false;
		}
		else if (r2 > r1)
		{
			checkmin = false;
			
		}
		if ((checkmin == true && checkmax == true)||(checkmin==false&&checkmax==false))
			break;
		temp /= 10;


	}
	
	if ((checkmin==true&&checkmax==false)||(checkmin==false&&checkmax==true))
	{
		cout << "La dang song";

	}
	else
	{
		cout << "Khong phai dang song";
	}
}




#include<iostream>
using namespace std;



void KtraVitri2duongtron(double R1,double R2,double d)
{
	if (R1 - R2<d && R1 + R2>d)
	{
		cout << "Hai duong tron cach nhau";
	}
	else if (d == R1 + R2)
	{
		cout << "Hai duong tron tiep xuc ngoai";
	}
	else if (d == R1 - R2)
	{
		cout << "Hai duong tron tiep xuc trong";
	}
	else if (d > R1 + R2)
	{
		cout << "Hai duong tron o ngoai nhau";
	}
	else if (d < R1 + R2)
	{
		cout << "Hai duong tron nam ben trong nhau";
	}
	else if (d == 0)
	{
		cout << "Hai duong tron dong tam";
	}


}
int main()
{
	double R1, R2, d;
	do
	{	
		cout << "Nhap ban kinh hinh tron 1:"; cin >> R1;
		cout << "Nhap ban kinh hinh tron 2:"; cin >> R2;
		cout << "Nhap khoang cach cua 2 duong tron:"; cin >> d;

		if (R1 <= 0 || R2 <= 0 )
		{
			cout << "Ban kinh phai lon hon hoac bang 0"<<endl;
		}
		else if (d < 0)
		{
			cout << "Khoang cach phai lon hon 0"<<endl;
		}

	} while (R1 <= 0 || R2 <= 0 || d < 0);

	KtraVitri2duongtron(R1, R2, d);
	system("pause");
}
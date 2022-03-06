#include"Header.h"

int main()
{
	double a[100],x;
	int n, k;
	Input(a, n);
	cout << "Mang truoc khi them: " << endl;
	Output(a, n);

	cout << "Gia tri them vao: ";
	cin >> x; 
	do {
		cout << "Vi tri muon them (0 -> " << n << "):";
		cin >> k;
		if (k < 0 || k > n)
		{
			cout << "Nhap lai " << endl;
		}
	} while (k <= 0 || k > n);
	
	themvitri(a, n, k, x);
	cout << "Mang sau khi them: " << endl;
	Output(a, n);
	system("pause");
}
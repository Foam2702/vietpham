#include"Header.h"
int main()

{
	int n;
	do {
		cout << "Nhap n:";
		cin >> n;
		if (n < 0)
		{
			cout << "n phai lon hon hoac bang 0" << endl;
		}
	} while (n < 0);
	tamGiacpascal(n);
	system("pause");

}
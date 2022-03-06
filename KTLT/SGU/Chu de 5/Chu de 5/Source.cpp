#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

struct PS {
	int tu = 0;
	int mau = 0;
};

PS SumFraction(PS ps1, PS ps2) {
	PS x;
	x.tu = (ps1.tu * ps2.mau) + (ps2.tu * ps1.mau);
	x.mau = ps1.mau * ps2.mau;
	return x;

}
PS operator+(PS ps1, PS ps2) {
	PS x;
	x.tu = (ps1.tu * ps2.mau) + (ps2.tu * ps1.mau);
	x.mau = ps1.mau * ps2.mau;
	return x;
}
void Sort_Increasing(vector<PS>& arr) {

	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			if (((double)(arr[i].tu) / (double)(arr[i].mau)) > (((double)arr[j].tu) / ((double)arr[j].mau))) {
				swap(arr[i], arr[j]);

			}
		}
	}
}

	

int UCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}
void rutgon(PS& ps)
{
	int c = UCLN(ps.tu, ps.mau);
	ps.tu = ps.tu / c;
	ps.mau = ps.mau / c;
}
int main()
{
	ifstream in;
	ofstream out;
	PS ps;
	
	vector<PS>arr;
	int n = 0;
	in.open("fraction.inp.txt", ios_base::in);
	out.open("fraction.out.txt", ios_base::out);
	if (!in.is_open())
	{
		cout << "ERROR";
	}

	in >> n;
	out << "Bai 24:";
	for (int i = 0; i < n; i++)
	{
		in >> ps.tu >> ps.mau;
		arr.push_back(ps);
		
	}
	Sort_Increasing(arr);
	for (int i = 0; i < arr.size(); i++)
	{
		out << arr[i].tu << "/" << arr[i].mau << " ";
	}
	out << endl;
	PS sum = arr[0];
	for (int i = 1; i < arr.size(); i++)
	{
		
		//sum =sum+arr[i];
		sum = SumFraction(sum, arr[i]);
		
	}
	rutgon(sum);
	out << "Bai 25:";
	out << sum.tu << "/" << sum.mau;


	in.close();
	out.close();


}
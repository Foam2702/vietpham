#include"Header.h"

void soTo_cua_tungLoaiTien(double &value)
{
	double arr[] = { 50.000,20.000,10.000,5.000,2.000,1.000 };
	int n = sizeof(arr) / sizeof(arr[0]); 
	int brr[6] = {};
	int k = 0;
	for (int i = 0; i < n; i++)
	{
			
		if (((int)value % (int)arr[i]) == 0)
		{
			brr[k] = (int)value / (int)arr[i];
			
		}
		k++;
	}
	for (int k = 0; k < n; k++)
	{
		cout <<"Menh gia:"<< arr[k] << "| So to:" << brr[k] << endl;
	}
	cout << endl;

	int min = brr[0];
	int compare = 0;

	for (int h = 1; h < n; h++)
	{	
		if (brr[h] != 0)
		{
			if (min > brr[h])
			{
				min = brr[h];
			}
		}
	}
	for (int l = 0; l < n; l++)
	{
		if (min == brr[l])
		{
			compare = l;
		}
	}
	cout << "Phuong an cho so tien it nhat " << endl <<"Menh gia:"<< arr[compare] << "| So to:" << min << endl;
}

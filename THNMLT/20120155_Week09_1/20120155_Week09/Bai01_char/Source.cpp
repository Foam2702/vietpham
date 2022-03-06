#include"Header.h"
int strlen(char str[])
{
	int i = 0,count=0;
	while (str[i] != '\0')
	{
		count++;
		i++;
	}
	return count;

}
void dem_khoangTrang_kySo_laTin_kyTukhac(char str[])
{
	int khoangtrang = 0, kyso = 0, latin = 0, kytukhac = 0;
	int length = strlen(str);
	for (int i = 0; i < length; i++)
	{	
		if (str[i] != '\0' && str[i]!='\n')
		{
			if (str[i] == ' ')
			{
				khoangtrang++;
			}
			else if (str[i] >= 'a' && str[i] <= 'z')
			{
				kyso++;
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				latin++;
			}
			else
			{
				kytukhac++;
			}
		}
	}
	
	cout << "Khoang trang:" << khoangtrang << endl;
	cout << "Ky so:" << kyso << endl;
	cout << "Latin:" << latin << endl;
	cout << "Ky tu khac:" << kytukhac << endl;

}
int dem_Tu(char str[])
{	
	int length = strlen(str),count = (str[0] != ' ');
		
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
		{
			count++;
		}
	}
	
	
	return count;
}
void tu_Dainhat(char str[])
{
	int length = strlen(str);
	int index = 0, count = 0, max = INT_MIN, j = 0;
	char longest[50];
	for (int i = 0; i < length; i++)
	{
		if (str[i] != ' ')
		{
			count++;
		}
		else
		{
			if (count > max)
			{
				max = count;
				index = i - max;
			}
			count = 0;
		}
	}
	
	if (count > max)
	{
		max = count;
		index = length - max;
	}

	j = 0;
	for (int i = index; i < index + max; i++)
	{
		longest[j] = str[i];
		j++;
	}

	longest[j] = '\0';
	cout << longest;
}
void tu_Ngannhat(char str[])
{
	int length = strlen(str);
	int index = 0, count = 0, min = INT_MAX, j = 0;
	char shortest[50];
	for (int i = 0; i < length; i++)
	{
		if (str[i] != ' ')
		{
			count++;
		}
		else
		{
			if (count < min)
			{
				min = count;
				index = i - min;
			}
			count = 0;
		}
	}

	if (count < min)
	{
		min = count;
		index = length - min;
	}

	j = 0;
	for (int i = index; i < index + min; i++)
	{
		shortest[j] = str[i];
		j++;
	}

	shortest[j] = '\0';
	cout << shortest;
}
void XoaKyTu(char s[], int vitrixoa)
{
	int length =strlen(s);

	if (vitrixoa >= 0 && vitrixoa < length)
	{
		for (int i = vitrixoa + 1; i < length; ++i)
		{
			s[i - 1] = s[i];
		}
		s[length - 1] = '\0';
	}
}

void XoaTatCaKhoangTrangODau(char s[])
{
	int i = 0;

	while (s[i] == ' ')
	{
		XoaKyTu(s, i--);
		i++;
	}
}

void XoaTatCaKhoangTrangOCuoi(char s[])
{
	int length = strlen(s);
	int i = length - 1;

	while (s[i] == ' ')
	{
		XoaKyTu(s, i);
		i--;
	}
}


void XoaKhoangTrangThuaGiua2Tu(char s[])
{
	int length = strlen(s);
	for (int i = 0; i < length - 1; ++i) 
	
	{
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			XoaKyTu(s, i--);
			length--; 
		}
	}
}

void VietHoaKyTuDauTienConLaiVietThuongCuaMoiTu(char s[])
{
	int length = strlen(s);
	if (s[0] >= 'a' && s[0] <= 'z')
	{
		s[0] -= 32;
	}

	for (int i = 1; i < length; ++i)
	{
		if (s[i] != ' ')
		{
			if (s[i - 1] == ' ') 
			{
				
				if (s[i] >= 'a' && s[i] <= 'z')
				{
					s[i] -= 32;
				}

			}
			else 
			{
				
				if (s[i] >= 'A' && s[i] <= 'Z')
				{
					s[i] += 32;
				}
			}
		}
	}
}

void ChuanHoaChuoi(char s[])
{
	int length = strlen(s);
	char s1[50];

	for (int i = 0; i <= length; ++i) 
	{
		s1[i] = s[i];
	}

	XoaTatCaKhoangTrangODau(s1);
	XoaTatCaKhoangTrangOCuoi(s1);
	XoaKhoangTrangThuaGiua2Tu(s1);
	VietHoaKyTuDauTienConLaiVietThuongCuaMoiTu(s1);

	cout << s1;
}
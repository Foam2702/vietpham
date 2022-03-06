#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Hàm chuyển từ tập tin văn bản sang tập tin nhị phân (mã hóa để máy hiểu được)
// Đầu vào chúng ta sẽ nhận 1 tập tin văn bản (ĐỌC FILE) và đầu ra chúng ta sẽ có 1 tập tin nhị phân (GHI FILE)
void convertTextToBinary(string text, string binary)
{
	//FILE *Fileout_Text = fopen(text, "r"); // r: read
	//FILE *FileOut_Binary = fopen(binary, "wb"); // w: write

	ifstream Fileout_Text;
	Fileout_Text.open(text, ios_base::in); // in <=> input (đọc)

	ofstream FileOut_Binary;
	//FileOut_Binary.open(binary, ofstream::binary); // out <=> output (ghi)
	FileOut_Binary.open(binary, ios_base::out); // out <=> output (ghi)

	if(!Fileout_Text)
	{
		// printf("\nKhong tim thay tap tin %s", text);
		cout << "\nKhong tim thay tap tin " << text;
		//getch();
		system("pause");
		return; // kết thúc hàm không làm nữa
	}
	
	short dong, cot;
	//fscanf(Fileout_Text, "%hi%hi", &dong, &cot);
	Fileout_Text >> dong >> cot;

	// sau khi đọc dữ liệu dòng cột từ tập tin văn bản vào 2 biến trong chương trình thì đồng thời ghi 2 biến đó vào tập tin nhị phân luôn
	//fwrite(&dong, sizeof(dong), 1, FileOut_Binary);
	//fwrite(&cot, sizeof(cot), 1, FileOut_Binary);
	FileOut_Binary.write((char *)&dong, sizeof(dong));
	FileOut_Binary.write((char *)&cot, sizeof(cot));

	for(int i = 0; i < dong; ++i)
	{
		for(int j = 0; j < cot; ++j)
		{
			int x; // mỗi lần đọc dữ liệu từ tập tin văn bản vào biến x thì đồng thời chúng ta ghi x ra tập tin nhị phân
			//fscanf(Fileout_Text, "%d", &x);
			//fwrite(&x, sizeof(x), 1, FileOut_Binary);
			Fileout_Text >> x;
			FileOut_Binary.write((char *)&x, sizeof(x));
		}
	}
	//printf("Du lieu tu tap tin van ban %s da duoc ghi ra tap tin nhi phan %s", text, binary);
	cout << "Du lieu tu tap tin van ban " << text << " da duoc ghi ra tap tin nhi phan " << binary;
	
	//fclose(Fileout_Text);
	//fclose(FileOut_Binary);
	Fileout_Text.close();
	FileOut_Binary.close();
}

// Hàm chuyển từ tập tin nhị phân (máy đọc được) sang tập tin văn bản (người đọc được)
// Đầu vào chúng ta sẽ nhận vào 1 tập tin nhị phân (ĐỌC FILE) và đầu ra chúng ta sẽ có được 1 tập tin văn bản với dữ liệu đọc ra được từ tập tin nhị phân trước đó (GHI FILE)
void convertBinaryToText(string binary, string text)
{
	//FILE *FileOut_Text = fopen(text, "w"); // w: write
	//FILE *FileIn_Binary = fopen(binary, "rb"); // r: read
	ofstream FileOut_Text;
	FileOut_Text.open(text, ios_base::out);

	ifstream FileIn_Binary;
	//FileIn_Binary.open(binary, ifstream::binary);
	FileIn_Binary.open(binary, ios_base::in);

	if(!FileIn_Binary)
	{
		//printf("\nKhong tim thay tap tin %s", binary);
		cout << "\nKhong tim thay tap tin " << binary;
		
		//getch();
		system("pause");
		return; // kết thúc hàm không làm nữa
	}
	
	short dong, cot;
	//fread(&dong, sizeof(dong), 1, FileIn_Binary);
	//fread(&cot, sizeof(cot), 1, FileIn_Binary);
	FileIn_Binary.read((char *)&dong, sizeof(dong));
	FileIn_Binary.read((char *)&cot, sizeof(cot));

	//fprintf(FileOut_Text, "%hi %hi", dong, cot);
	FileOut_Text << dong << " " << cot;

	// sau khi đọc dữ liệu dòng cột từ tập tin nhị phân vào 2 biến trong chương trình thì đồng thời ghi 2 biến đó vào tập tin văn bản luôn
	for(int i = 0; i < dong; ++i)
	{
		int x;
		//fprintf(FileOut_Text, "\n");
		FileOut_Text << "\n";
		for(int j = 0; j < cot - 1; ++j)
		{
			 // mỗi lần đọc dữ liệu từ tập tin nhị phân vào biến x thì đồng thời chúng ta ghi x ra tập tin văn bản
			//fread(&x, sizeof(x), 1, FileIn_Binary);
			//fprintf(FileOut_Text, "%d ", x);
			FileIn_Binary.read((char *)&x, sizeof(x));
			FileOut_Text << x << " ";
		}
		//fread(&x, sizeof(x), 1, FileIn_Binary);
		//fprintf(FileOut_Text, "%d", x);
		FileIn_Binary.read((char *)&x, sizeof(x));
		FileOut_Text << x;

	}
	//printf("Du lieu tu tap tin nhi phan %s da duoc ghi ra tap tin van ban %s", binary, text);
	cout << "Du lieu tu tap tin nhi phan " << binary << " da duoc ghi ra tap tin van ban " << text;
	
	//fclose(FileOut_Text);
	//fclose(FileIn_Binary);
	FileOut_Text.close();
	FileIn_Binary.close();
}

int main()
{
	//convertTextToBinary("text.txt", "binary.txt");
	convertBinaryToText("binary.txt", "text1.txt");

	/*int a = 5;
	ofstream FileOut;
	FileOut.open("nhiphan.txt", ofstream::binary);

	FileOut.write((char *)&a, sizeof(a));

	FileOut.close();

	int b;
	ifstream FileIn;
	FileIn.open("nhiphan.txt", ifstream::binary);

	FileIn.read((char *)&b, sizeof(b));

	FileIn.close();

	cout << "\nb = " << b;*/

	system("pause");
	return 0;
}
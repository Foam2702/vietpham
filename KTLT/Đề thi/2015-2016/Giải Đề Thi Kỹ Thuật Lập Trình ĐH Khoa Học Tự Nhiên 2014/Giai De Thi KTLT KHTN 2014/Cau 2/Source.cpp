#include <stdio.h>
#include <conio.h>

// Hàm chuyển từ tập tin văn bản sang tập tin nhị phân (mã hóa để máy hiểu được)
// Đầu vào chúng ta sẽ nhận 1 tập tin văn bản (ĐỌC FILE) và đầu ra chúng ta sẽ có 1 tập tin nhị phân (GHI FILE)
void convertTextToBinary(char *text, char *binary)
{
	FILE *FileIn_Text = fopen(text, "r"); // r: read
	FILE *FileOut_Binary = fopen(binary, "wb"); // w: write

	if(!FileIn_Text)
	{
		printf("\nKhong tim thay tap tin %s", text);
		getch();
		return; // kết thúc hàm không làm nữa
	}
	
	short dong, cot;
	fscanf(FileIn_Text, "%hi%hi", &dong, &cot);

	// sau khi đọc dữ liệu dòng cột từ tập tin văn bản vào 2 biến trong chương trình thì đồng thời ghi 2 biến đó vào tập tin nhị phân luôn
	fwrite(&dong, sizeof(dong), 1, FileOut_Binary);
	fwrite(&cot, sizeof(cot), 1, FileOut_Binary);

	for(int i = 0; i < dong; ++i)
	{
		for(int j = 0; j < cot; ++j)
		{
			int x; // mỗi lần đọc dữ liệu từ tập tin văn bản vào biến x thì đồng thời chúng ta ghi x ra tập tin nhị phân
			fscanf(FileIn_Text, "%d", &x);
			fwrite(&x, sizeof(x), 1, FileOut_Binary);
		}
	}
	printf("Du lieu tu tap tin van ban %s da duoc ghi ra tap tin nhi phan %s", text, binary);
	fclose(FileIn_Text);
	fclose(FileOut_Binary);
}

// Hàm chuyển từ tập tin nhị phân (máy đọc được) sang tập tin văn bản (người đọc được)
// Đầu vào chúng ta sẽ nhận vào 1 tập tin nhị phân (ĐỌC FILE) và đầu ra chúng ta sẽ có được 1 tập tin văn bản với dữ liệu đọc ra được từ tập tin nhị phân trước đó (GHI FILE)
void convertBinaryToText(char *binary, char *text)
{
	FILE *FileOut_Text = fopen(text, "w"); // w: write
	FILE *FileIn_Binary = fopen(binary, "rb"); // r: read

	if(!FileIn_Binary)
	{
		printf("\nKhong tim thay tap tin %s", binary);
		getch();
		return; // kết thúc hàm không làm nữa
	}
	
	short dong, cot;
	fread(&dong, sizeof(dong), 1, FileIn_Binary);
	fread(&cot, sizeof(cot), 1, FileIn_Binary);

	fprintf(FileOut_Text, "%hi %hi", dong, cot);

	// sau khi đọc dữ liệu dòng cột từ tập tin nhị phân vào 2 biến trong chương trình thì đồng thời ghi 2 biến đó vào tập tin văn bản luôn
	for(int i = 0; i < dong; ++i)
	{
		int x;
		fprintf(FileOut_Text, "\n");
		for(int j = 0; j < cot - 1; ++j)
		{
			 // mỗi lần đọc dữ liệu từ tập tin nhị phân vào biến x thì đồng thời chúng ta ghi x ra tập tin văn bản
			fread(&x, sizeof(x), 1, FileIn_Binary);
			fprintf(FileOut_Text, "%d ", x);
		}
		fread(&x, sizeof(x), 1, FileIn_Binary);
		fprintf(FileOut_Text, "%d", x);
	}
	printf("Du lieu tu tap tin nhi phan %s da duoc ghi ra tap tin van ban %s", binary, text);
	
	fclose(FileOut_Text);
	fclose(FileIn_Binary);
}

int main()
{
	convertTextToBinary("text1.txt", "binary1.txt");
	//convertBinaryToText("binary1.txt", "text2.txt");

	getch();
	return 0;
}
#include"Header.h"
int main()
{
	string FileName;
	FileName = "ThiSinh.txt";
	list<string>doc=fReadfile(FileName);
	/*string str = "123:456:789";
	doc = fSplit(str, ':');*/
	fReplace(doc, "2015", "2021");
	fReplace(doc, "Nguyen Van teo", "Bien Viet Pham");
	fWritefile("160621.txt", doc);
	system("pause");
	return 0;
}
#include"Header.h"
int main()
{	
	list<Vehicle> listVeh;
	fstream f;
	string FileName="";
	FileName = "ListXe.txt";
	string doc=fReadfile(FileName);
	cout << doc << endl;
	cout << "--------------------------------------------"<<endl;
	listVeh=StrtoListVehicle(doc);
	listVeh = GroupByVehicle(listVeh);
	cout << fListString_to_String(ListVehtoListString(listVeh))<<endl;
	return 0;
}
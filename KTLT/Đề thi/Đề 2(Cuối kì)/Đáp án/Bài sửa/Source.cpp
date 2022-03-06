#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

struct Xe {
	string dongxe;
	string hangxe;
	string loixe;
	string maso;
};


struct Node {
	Xe value;
	Node* pNext=NULL;
};

struct List {
	Node* pHead = NULL;
};

Node* CreateNode(Xe value)
{	
	
	Node*newxe = new Node;
	if (newxe == NULL)
	{
		cout << "NOT ENOUGHT MEMORY";
	}
	else
	{
		newxe->value = value;
		newxe->pNext = NULL;
	}
	return newxe;
}
void CreateList(List& l) 
{
	l.pHead = NULL;
}
void Push_front(List& l, Xe value)
{	
	
	if(l.pHead==NULL)
	{
		Node* newxe = CreateNode(value);
		l.pHead = newxe;
	}
	else
	{
		Node* newxe = CreateNode(value);
		newxe->pNext = l.pHead;
		l.pHead = newxe;
	}

}
void Push_back(List& l, Xe value)
{
	if (l.pHead == NULL)
	{	
		l.pHead = CreateNode(value);
	}
	else
	{
		Node* p = l.pHead;
		while (p->pNext)
		{
			p = p->pNext;
		}
		p->pNext = CreateNode(value);
	}
}

struct LoiXe {
	string hang;
	string loi;
	double phantram=0;
};

double DemLoi(int& soluong, int& soloi, vector<Xe> DSXe,LoiXe loixemoi)
{	
	
	for (int i = 0; i < DSXe.size() ; i++)
	{
		if (DSXe[i].hangxe.compare(loixemoi.hang)==0)
		{
			soluong++;
			if (DSXe[i].loixe.compare(loixemoi.loi)==0)
			{
				soloi++;
			}
		}		
	}
	return ((double)soloi / (double)soluong) * 100;
}
void BaocaoLoi(List& l, vector<Xe> &DSXe,vector<LoiXe> &DSXeLoi)
{	
	for (Node* g = l.pHead; g->pNext; g = g->pNext)
	{
		DSXe.push_back(g->value);
	}

	bool daxet = false;

	for (int i = 0; i <DSXe.size(); i++)
	{	
		
		for (int j = 0; j <DSXeLoi.size(); j++)
		{
			if (DSXeLoi[j].hang.compare(DSXe[i].hangxe) == 0 && DSXeLoi[j].loi.compare(DSXe[i].loixe) == 0)
			{
				daxet = true;
				break;
			}
		}
		if (daxet == false)
		{
			int soluong = 0, soloi = 0;
			LoiXe loixemoi;
			loixemoi.hang = DSXe[i].hangxe;
			loixemoi.loi = DSXe[i].loixe;
			loixemoi.phantram = DemLoi(soluong, soloi, DSXe,loixemoi);
			DSXeLoi.push_back(loixemoi);
			
		}
		daxet = false;
		
	}
	
	for (int i = 0; i < DSXeLoi.size(); i++)
	{	
		cout << DSXeLoi[i].hang << ";" << DSXeLoi[i].loi << ":" << DSXeLoi[i].phantram <<"%"<< endl;
	}
	
}
void ExportList(List l)
{
	for (Node* g = l.pHead; g; g = g->pNext) {
		cout << g->value.dongxe <<";"<<g->value.hangxe << ";" << g->value.loixe << ";" << g->value.maso << endl;
	}
}
void ReadFile(string FileName, List &l)
{
	ifstream in;
	if (in.is_open())
	{
		in.close();
	}
	in.open(FileName);
	if (in.is_open()) 
	{	
		cout << "CONNECTION SUCCESSFUL"<<endl;
		while (!in.eof())
		{	
			Xe xe;
			getline(in, xe.dongxe, ';');
			getline(in, xe.hangxe, ';');
			getline(in, xe.loixe, ';');
			getline(in, xe.maso);
			Push_back(l, xe);
		};
		in.close();
	}
	
}
void GhiBaoCao(string FileName,vector<LoiXe>DSXeloi)
{
	ofstream out;
	if (out.is_open())
	{
		out.close();
	}
	out.open(FileName);
	if (out.is_open())
	{	
		cout << "CAN WRITE";
		for (int i = 0; i < DSXeloi.size(); i++)
		{
			out << DSXeloi[i].hang << ";" << DSXeloi[i].loi << ":" << DSXeloi[i].phantram<<"%" << endl;
		}
	}
	out.close();
}


int main()
{
	List l;
	CreateList(l);
	ReadFile("VehicleError.txt", l);
	//ExportList(l);
	vector<Xe> DSXe;
	vector<LoiXe>DSXeLoi;
	BaocaoLoi(l, DSXe,DSXeLoi);
	cout << "\n\n\n";
	GhiBaoCao("Report.txt", DSXeLoi);
	system("pause");
}


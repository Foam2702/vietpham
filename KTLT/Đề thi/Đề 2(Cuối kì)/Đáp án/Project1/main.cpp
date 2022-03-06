#include <iostream>;
#include <fstream>;
#include <string>;
#include <vector>;
using namespace std;
struct Xe
{
	string  DongXe;
	string Hang;
	string Loi;
	string MaSo;
};
struct Node
{
	Xe value;
	Node* next;
	Node(Xe newItem)
	{
		value = newItem;
		next = NULL;
	};
	Node()
	{
		next = NULL;
	};
};
struct List
{
	Node *head;
	List()
	{
		head = NULL;
	};
	void push_front(Xe item)
	{
		if (head == NULL)
			head = new Node(item);
		else
		{
			Node* newHead = new Node(item);
			newHead->next = head;
			head = newHead;
		}
	}
	// Không dùng đệ quy
	void push_back(Xe item)
	{
		if (head == NULL)
			head = new Node(item);
		else
		{
			Node* newTail = head;
			while (newTail->next != NULL)
				newTail = newTail->next;
			newTail->next = new Node(item);
		}
	}
	// Không dùng đệ quy
	void Xuat()
	{
		Node* i = this->head;
		while (i != NULL)
		{
			cout << i->value.DongXe << ";" << i->value.Hang << ";" << i->value.Loi << ";" << i->value.MaSo << endl;
			i = i->next;
		}
	}

};
void push_back(List &DanhSach,Xe item, Node *&NewNode)
{
	if (DanhSach.head == NULL)
		DanhSach.head = new Node(item);
	else
	{
		if (NewNode->next == NULL)
			NewNode->next = new Node(item);
		else
			push_back(DanhSach, item, NewNode->next);
	}
}
void XuatList(Node* i)
{
	if (i == NULL)
		return;
	else
	{
		cout << i->value.DongXe << ";" << i->value.Hang << ";" << i->value.Loi << ";" << i->value.MaSo << endl;
		XuatList(i->next);
	}
}
double DemLoi(Node* i, string Hang, string Loi, int &SoLuong, int &SoLoi)
{
	if (i == NULL)
		return ((double)SoLoi / (double)SoLuong) * 100;
	else
	{
		if (i->value.Hang.compare(Hang)==0)
		{
			SoLuong++;
			if (i->value.Loi.compare(Loi)==0)
				SoLoi++;
		}
		return DemLoi(i->next, Hang, Loi, SoLuong, SoLoi);
	}
}
struct LoiXe {
	string Hang;
	string Loi;
	double PhanTram;
	LoiXe(Xe Xe) {
		this->Hang = Xe.Hang;
		this->Loi = Xe.Loi;
		PhanTram = 0;
	}

};
void BaoCaoLoi(Node* Head,Node *node, vector<LoiXe> &BaoCao)
{
	if (node == NULL)
	{
		for (int i = 0; i < BaoCao.size(); i++)
		{
			cout << BaoCao[i].Hang << ":" << BaoCao[i].Loi << ":" << BaoCao[i].PhanTram << "%" << endl;
		}
	}
	else
	{
		bool daXet = false;
		for (int i = 0; i < BaoCao.size(); i++)
		{
			if (BaoCao[i].Hang.compare(node->value.Hang) == 0 && BaoCao[i].Loi.compare(node->value.Loi) == 0)
			{
				daXet = true;
				break;
			}
		}
		if (daXet == false)
		{
			LoiXe LoiXeMoi = *(new LoiXe(node->value));
			int SoLuong = 0, SoLoi = 0;
			LoiXeMoi.PhanTram = DemLoi(Head, LoiXeMoi.Hang, LoiXeMoi.Loi, SoLuong, SoLoi);
			BaoCao.push_back(LoiXeMoi);
		}
		BaoCaoLoi(Head,node->next,BaoCao);
	}
}
void GhiBaoCao(string Nguon, vector<LoiXe>& BaoCao)
{
	ofstream out;
	if (out.is_open())
	{
		out.close();
	}
	out.open(Nguon);
	if (out.is_open())
	{
		for (int i = 0; i < BaoCao.size(); i++)
		{
			out << BaoCao[i].Hang << ":" << BaoCao[i].Loi << ":" << BaoCao[i].PhanTram << "%" << endl;
		}

		out.close();
	}
}
void DocFile(string nguon, List &DanhSach)
{
	ifstream in;
	if (in.is_open())
	{
		in.close();
	}
	in.open(nguon);
	if (in.is_open())
	{
		while (!in.eof())
		{
			Xe dong;
			getline(in, dong.DongXe, ';');
			getline(in, dong.Hang, ';');
			getline(in, dong.Loi, ';');
			getline(in, dong.MaSo);
			//DanhSach.push_front(dong);
			//DanhSach.push_back(dong);
			push_back(DanhSach, dong, DanhSach.head);
		}
		in.close();
	}
}
void main()
{
	List DanhSach;
	DocFile("VehicleError.txt",DanhSach);
	//DocFile("D://temp.txt",DanhSach);
	//DanhSach.Xuat();
	XuatList(DanhSach.head);
	cout << endl << endl;
	vector<string> HangDaXet;
	vector<LoiXe> BaoCao;
	vector<string> LoiDaXet;
	BaoCaoLoi(DanhSach.head,DanhSach.head,BaoCao);

	GhiBaoCao("Report.txt", BaoCao);
	system("pause");
}
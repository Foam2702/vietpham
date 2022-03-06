#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<thread>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>
//hằng số
#define MAX_CAR 17
#define MAX_SPEED 1.5
#define MAX_CAR_LENGTH 1
#define HEIGH_CONSOLE 25
#define WIDTH_CONSOLE 80
#define MAX_LIST 3
//biến toàn cục
POINT** X;//Mảng chứa MAX_CAR xe	
POINT Y;//Đại diện người qua đường
int s = 0;
int cn;
float sp;
int sc;
int score = 0;
int cnt = 0;//biến hỗ trợ trong quá trình tăng tốc xe di chuyển
char MOVING;//biến xác định hướng di chuyển của người
float SPEED;//tốc độ xe chạy(xem như level)
bool STATE;//trạng thái sống/chết của người qua đường
using namespace std;
static int flag;
void SetColor(int backgound_color, int text_color);
void Menu();
int main1();
int main2();
int main();
void exit();
void printASCII(string);
void name();
vector<int>A;
//hàm cố định khung console
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
//hàm thay đổi kích thước console tùy ý
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
//hàm tọa độ
void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//hàm khởi tạo dữ liệu mặc định ban đầu
void ResetData() {
	MOVING = 'D';//ban đầu cho người di chuyển sang phải
	SPEED = 0.5;//tốc độ lúc đầu
	Y = { 18,19 };//vị trí lúc đầu của người
	//tạo mảng xe chạy
	if (X == NULL) {
		X = new POINT * [MAX_CAR];
		for (int i = 0; i < MAX_CAR; i++)
			X[i] = new POINT[MAX_CAR_LENGTH];
		for (int i = 0; i < MAX_CAR; i++) {
			int temp = (rand() % (WIDTH_CONSOLE - MAX_CAR_LENGTH)) + 1;
			for (int j = 0; j < MAX_CAR_LENGTH; j++) {
				X[i][j].x = temp + j;
				X[i][j].y = 2 + i;
			}
		}
	}
}

void DrawBoard(int x, int y, int width, int height, int curPosX = 0, int curPosY = 0) {
	GotoXY(x, y); cout << 'X';
	for (int i = 1; i < width; i++) cout << 'X';
	cout << 'X';
	GotoXY(x, height + y); cout << 'X';
	for (int i = 1; i < width; i++)cout << 'X';
	cout << 'X';
	for (int i = y + 1; i < height + y; i++) {
		GotoXY(x, i); cout << 'X';
		GotoXY(x + width, i); cout << 'X';
	}
	//GotoXY(curPosX, curPosY);
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void printASCII(string fileName) {
	string line = " ";
	ifstream inFile;
	inFile.open(fileName);
	if (inFile.is_open())
	{

		while (getline(inFile, line)) {
			cout << "\t \t \t   ";
			cout << line << endl;
		}
	}
	else
	{
		cout << "EROR";
	}
	inFile.close();
}
//hiệu ứng khi đụng


void StartGame() {
	system("cls");
	ResetData();//khởi tạo dữ liệu gốc
	STATE = true;//bắt đầu cho thread chạy
	SetColor(0, 14);
	int i = 1;
	string fileName = "11.txt";
	string line = " ";
	ifstream inFile;
	inFile.open(fileName);
	if (inFile.is_open())
	{

		while (getline(inFile, line)) {
			GotoXY(85, i++);
			//cout << "\t \t \t \t \t   \t \t \t \t\t";
			cout << line << endl;
		}
	}
	else
	{
		cout << "EROR";
	}
	inFile.close();
	SetColor(0, 6);
	GotoXY(89, 14);
	cout << "USE W,A,S,D" << endl;
	GotoXY(91, 15);
	cout << "TO MOVE";
	GotoXY(87, 16);
	cout << "TURN OFF UNIKEY";
	GotoXY(89, 21);
	cout << "L: save game";
	GotoXY(89, 22);
	cout << "T: load game";
	SetColor(0, 7);

}

//hàm dọn dẹp tài nguyên
void GabageCollect() {
	for (int i = 0; i < MAX_CAR; i++) {
		delete[]X[i];
	}
	delete[]X;
}
//hàm xóa màn hình
void DeleteScreen()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
//hàm thoát game
void ExitGame(HANDLE t) {
	system("cls");
	TerminateThread(t, 0);
	GabageCollect();
}
//hàm dừng game
void PauseGame(HANDLE t) {
	SuspendThread(t);
}
//hàm xử lý người bị đụng xe
void ProcessDead(int x, int y, int width, int height, int curPosX = 80, int curPosY = 19) {
	STATE = 0;
	FixConsoleWindow();
	resizeConsole(1000, 500);
	string Car[9], Char[3], dead[7];
	string FileName;
	ifstream FileIn;
	GotoXY(x, y);
	while (x < width) {
		system("cls");
		textcolor(4);
		string FileName = "ambulance.txt";
		FileIn.open(FileName);
		GotoXY(x, y);
		for (int i = 0; i < 9; i++) {
			getline(FileIn, Car[i]);
		}
		for (int i = 0; i < 9; i++) {
			cout << Car[i];
			GotoXY(x, y + i + 1);
		}
		FileIn.close();

		FileName = "person.txt";
		FileIn.open(FileName);
		GotoXY(curPosX, curPosY);
		textcolor(14);
		for (int i = 0; i < 3; i++) {
			getline(FileIn, Char[i]);
		}
		for (int i = 0; i < 3; i++) {
			cout << Char[i];
			GotoXY(curPosX, curPosY + i + 1);
		}
		x++;
		Sleep(15);
		FileIn.close();
	}
	system("cls");
	GotoXY(WIDTH_CONSOLE / 2, HEIGH_CONSOLE / 2);
	FileName = "dead.txt";
	FileIn.open(FileName);
	textcolor(4);
	printASCII(FileName);
	FileIn.close();
	GotoXY(WIDTH_CONSOLE / 2, (HEIGH_CONSOLE / 2) + 6);
	system("pause");
}

bool findposi(vector<int>a, int u)
{
	for (int i = 0; i < a.size(); i++)
		if (a[i] == u)
			return true;
	return false;
}

void CautionScreen()
{
	system("cls");
	textcolor(11);
	DrawBoard(25, 5, 45, 8);
	GotoXY(30, 7);
	cout << "Ban da va vao nguoi di truoc do" << endl;
	GotoXY(28, 9);
	cout << "Nhap Y neu ban muon choi lai" << endl;
	GotoXY(28, 10);
	cout << "Nhap N neu ban muon thoat" << endl;
	cout << endl << endl;
}

void levelup() {
	int i = 0;
	string fileName = "edit2.txt";
	string line = " ";
	ifstream inFile;
	inFile.open(fileName);
	if (inFile.is_open())
	{
		while (getline(inFile, line)) {
			GotoXY(1, i++);
			cout << line << endl;
		}
	}
}
void Dungmanhinh() {
	for (int i = 1; i <= 15; i++) {
		textcolor(i);
		levelup();
		Sleep(100);
	}
	GotoXY(8, 7);
	cout << "                                                                  ";
	GotoXY(8, 8);
	cout << "                                                                  ";
	GotoXY(8, 9);
	cout << "                                                                  ";
	GotoXY(8, 10);
	cout << "                                                                  ";
	GotoXY(8, 11);
	cout << "                                                                  ";
}

void drawscore()
{
	textcolor(4);
	GotoXY(87, 18);
	cout << "-------------";
	GotoXY(87, 19);
	cout << "|";
	GotoXY(87, 20);
	cout << "-------------";
	GotoXY(99, 19);
	cout << "|";
	GotoXY(88, 19);
}

void Restart()
{
	score = 0;
	A.clear();
	GabageCollect();
	X = NULL;
	StartGame();
	drawscore();
	cout << "SCORE:" << score;
	textcolor(15);
	sc = 0;
}

//hàm xử lý khi người băng qua đường thành công
bool ProcessFinish(POINT& p) {
	SPEED == MAX_SPEED ? SPEED = 1 : SPEED += 0.5;

	if (findposi(A, p.x) == true)
	{
		char c;
		CautionScreen();
		GotoXY(28, 15);
		textcolor(10);
		cout << "Nhap (Y/N): " << endl;
		GotoXY(40, 15);
		cin >> c;
		textcolor(11);
		if (c == 'N' || c == 'n') {
			A.clear();
			exit();
		}
		else if (c == 'Y' || c == 'y')
		{
			Restart();
			return true;
		}
	}
	A.push_back(p.x);
	p = { 18,19 };//vị trí lúc đầu của nguời
	MOVING = 'D';//ban đầu cho người di chuyển sang phải
	sp = SPEED;
	return false;
}
//hàm vẽ các toa xe
void DrawCars(const char* s) {
	//int dem=0;
	for (int i = 0; i < MAX_CAR; i++) {
		for (int j = 0; j < MAX_CAR_LENGTH; j++) {
			GotoXY(X[i][j].x, X[i][j].y);
			if (i % 2 == 0) {
				cout << "o==O";
			}
			if (i % 2 != 0) {
				cout << "O==o";
			}
		}
	}
}
//hàm vẽ người băng qua đường
void DrawSticker(const POINT& p, string s) {
	GotoXY(p.x, p.y);
	cout << s;
}
// hàm kiểm tra xem người có đụng xe không
bool IsImpact(const POINT& p, int d) {
	if (d == 1 || (d >= 19 && d <= 25))return false;
	for (int i = 0; i < MAX_CAR_LENGTH; i++) {
		if (p.x == X[d - 2][i].x && p.y == X[d - 2][i].y)return true;

	}
	return false;
}
void MoveCars() {
	for (int i = 1; i < MAX_CAR; i += 2) {
		cnt = 0;
		do {
			cnt++;
			for (int j = 0; j < MAX_CAR_LENGTH - 1; j++) {
				X[i][j] = X[i][j + 1];
			}
			X[i][MAX_CAR_LENGTH - 1].x + 1 == WIDTH_CONSOLE ? X[i][MAX_CAR_LENGTH - 1].x = 1 : X[i][MAX_CAR_LENGTH - 1].x++;//kiểm tra xem xe có đụng màn hình không
		} while (cnt < SPEED);
	}
	for (int i = 0; i < MAX_CAR; i += 2) {
		cnt = 0;
		do {
			cnt++;
			for (int j = MAX_CAR_LENGTH - 1; j > 0; j--) {
				X[i][j] = X[i][j - 1];
			}
			X[i][0].x - 1 == 0 ? X[i][0].x = WIDTH_CONSOLE - 1 : X[i][0].x--;//kiểm tra xem xe có đụng màn hình không
		} while (cnt < SPEED);
	}
}
//hàm xóa xe(xóa có nghĩa là không vẽ)
void EraseCars() {
	for (int i = 0; i < MAX_CAR; i += 2) {
		cnt = 0;
		do {
			GotoXY(X[i][MAX_CAR_LENGTH - 1 - cnt].x, X[i][MAX_CAR_LENGTH - 1 - cnt].y);
			cout << "    ";
			cnt++;
		} while (cnt < SPEED);
	}
	for (int i = 1; i < MAX_CAR; i += 2) {
		cnt = 0;
		do {
			GotoXY(X[i][0 + cnt].x, X[i][0 + cnt].y);
			cout << "    ";
			cnt++;
		} while (cnt < SPEED);
	}
}
void MoveRight() {
	if (Y.x < WIDTH_CONSOLE - 1) {
		DrawSticker(Y, "   ");
		Y.x++;
		DrawSticker(Y, "^.^");
	}
}

void MoveLeft() {
	if (Y.x > 1) {
		DrawSticker(Y, "   ");
		Y.x--;
		DrawSticker(Y, "^.^");
	}
}
void MoveDown() {
	if (Y.y < HEIGH_CONSOLE - 1) {
		DrawSticker(Y, "   ");
		Y.y++;
		DrawSticker(Y, "^.^");
	}
}
void MoveUp() {

	if (Y.y > 1) {
		DrawSticker(Y, "   ");
		Y.y--;
		DrawSticker(Y, "^.^");
	}
}

void SubThread() {
	textcolor(4);
	GotoXY(87, 18);
	cout << "-------------";
	GotoXY(87, 19);
	cout << "|";
	GotoXY(87, 20);
	cout << "-------------";
	GotoXY(99, 19);
	cout << "|";
	GotoXY(88, 19);
	cout << "SCORE:" << score;
	textcolor(15);
	while (1) {
		if (STATE) {//nếu nguời vẫn còn sống
			if (MOVING == 'D' || MOVING == 'd') {
				MoveRight();

			}
			else if (MOVING == 'A' || MOVING == 'a') {
				MoveLeft();

			}
			else if (MOVING == 'W' || MOVING == 'w') {
				MoveUp();

			}
			else if (MOVING == 'S' || MOVING == 's') {
				MoveDown();

			}
			MOVING = ' ';//tạm khóa không cho di chuyển,chờ nhận phím từ hàm main
			EraseCars();
			MoveCars();
			textcolor(14);
			DrawCars("");
			textcolor(11);
			DrawBoard(0, 0, WIDTH_CONSOLE + 3, HEIGH_CONSOLE);//vẽ màn hình game
			DrawBoard(83, 0, 24, HEIGH_CONSOLE);
			DrawBoard(84, 12, 22, HEIGH_CONSOLE - 12);
			textcolor(15);
			if (IsImpact(Y, Y.y)) {
				ProcessDead(0, 14, 50, 15);//kiểm tra xem xe có đụng không
				exit();
			}
			if (Y.y == 1) {
				bool restart = ProcessFinish(Y);//kiểm tra xe về đích chưa
				if (restart)
					continue;
				drawscore();
				score += 100;
				sc = score;
				s = 100;
				GotoXY(88, 19);
				cout << "SCORE:" << score;
				if (s == 100) {
					Dungmanhinh();
				}
				textcolor(15);
				s = 0;
			}
			Sleep(50);//hàm ngủ theo tốc độ speed
		}
	}
}

void Loadgame() {
	string filename;
	ifstream f;
	int Speed = 0, Cnt = 0, Score = 0;

	GotoXY(2, 26);
	cout << "which file do you want to load: ";

	GotoXY(37, 26);
	cin >> filename;


	f.open(filename.c_str());

	f >> cnt;
	f >> SPEED;
	f >> score;

	GotoXY(2, 26);
	cout << "                                                 ";

	textcolor(4);
	GotoXY(88, 19);
	cout << "SCORE:" << score;
	textcolor(15);
}

void Savegame() {

	string file_name;
	fstream file;
	int number = 0;

	GotoXY(2, 26);
	cout << "Please enter the name of the file: " << endl;

	GotoXY(37, 26);
	cin >> file_name;

	ofstream f;

	f.open(file_name.c_str());

	f << cn << " " << sp << " " << sc;

	GotoXY(2, 26);
	cout << "                                                 ";

	f.close();
}

int main1()
{
	int temp;
	FixConsoleWindow();
	resizeConsole(1000, 500);
	srand(time(NULL));
	StartGame();
	thread t1(SubThread);
	while (1) {
		temp = toupper(_getch());
		if (STATE == 1) {
			if (temp == 'L' || temp == 'l') {
				PauseGame(t1.native_handle());
				Savegame();
			}
			if (temp == 'T' || temp == 't') {
				PauseGame(t1.native_handle());
				Loadgame();
			}
			if (temp == 27) {
				ExitGame(t1.native_handle());
				exit(0);
			}
			else if (temp == 'P' || temp == 'p') {
				PauseGame(t1.native_handle());
			}
			else {
				ResumeThread((HANDLE)t1.native_handle());
				if (temp == 'D' || temp == 'A' || temp == 'W' || temp == 'S' || temp == 'd' || temp == 'a' || temp == 'w' || temp == 's') {
					MOVING = temp;
				}
			}
		}
		else {
			if (temp == 'Y' || temp == 'y') {
				StartGame();
			}
			else if (temp == 27) {
				ExitGame(t1.native_handle());
				exit(0);
			}
		}
	}
	system("pause");
	return 0;
}
int main2() {
	int temp;
	int k = 0;
	FixConsoleWindow();
	resizeConsole(1000, 1000);
	srand((unsigned int)time(NULL));
	StartGame();
	Loadgame();
	thread t1(SubThread);
	while (1) {
		temp = toupper(_getch());
		if (STATE == 1) {
			if (temp == 'L' || temp == 'l') {
				PauseGame(t1.native_handle());
				Savegame();
			}
			if (temp == 'T' || temp == 't') {
				PauseGame(t1.native_handle());
				Loadgame();
			}
			if (temp == 27) {
				ExitGame(t1.native_handle());
				exit(0);
			}
			else if (temp == 'P' || temp == 'p') {
				PauseGame(t1.native_handle());
			}
			else {
				ResumeThread((HANDLE)t1.native_handle());
				if (temp == 'D' || temp == 'A' || temp == 'W' || temp == 'S' || temp == 'd' || temp == 'a' || temp == 'w' || temp == 's') {
					MOVING = temp;
				}
			}
		}
		else {
			if (temp == 'Y' || temp == 'y')StartGame();
			else {
				ExitGame(t1.native_handle());
				exit(0);
			}
		}
	}
	system("pause");
	return 0;
}
void Menu() {
	FixConsoleWindow();
	resizeConsole(1000, 500);
	string menu[MAX_LIST] = { "START", "LOADGAME", "EXIT" };
	int pointer = 0;
	flag = 1;
	while (1) {
		system("cls");
		name();
		cout << "\t \t \t \t \t   ";
		SetColor(0, 6);
		cout << "USE ARROW BUTTON TO CHOOSE" << endl;
		for (int i = 0; i < MAX_LIST; i++) {
			if (pointer == i) {
				cout << "\t \t \t \t \t \t";
				SetColor(0, 12);
				cout << ">>" << menu[i] << endl;
			}
			else {
				cout << "\t \t \t \t \t \t  ";
				SetColor(0, 11);
				cout << menu[i] << endl;
			}
		}
		while (1) {
			if (_kbhit()) {
				char key = _getch();
				if (key == 72) {
					if (pointer > 0) {
						--pointer;
					}
					else {
						pointer = MAX_LIST - 1;
					}
					break;
				}
				if (key == 80) {
					if (pointer < MAX_LIST - 1) {
						++pointer;
					}
					else {
						pointer = 0;
					}
					break;
				}
				if (key == 13) {
					switch (pointer) {
					case 0:
						main1();
						break;
					case 1:
						main2();
						break;
					case 2:
						exit();
						flag = -1;
						break;
					default:
						cout << "BUG";
					}
					break;
				}
			}
		}
		if (flag == -1) {
			break;
		}
		Sleep(100);
	}

}
int main() {
	Menu();
}
void SetColor(int backgound_color, int text_color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}

void exit() {
	int i = 0;
	SetColor(0, 7);
	system("cls");
	string fileName = "exit.txt";
	printASCII(fileName);
	fileName = "nhom11.txt";
	string line = " ";
	ifstream inFile;
	inFile.open(fileName);
	if (inFile.is_open())
	{

		while (getline(inFile, line)) {
			SetColor(0, 14);
			i++;
			if (i >= 5) SetColor(0, 6);
			cout << "\t  \t  ";
			cout << line << endl;
		}
	}
	else
	{
		cout << "EROR";
	}
	inFile.close();
	SetColor(0, 7);
	Sleep(1000);
	exit(0);
}
void name() {
	SetColor(0, 10);
	string fileName = "name.txt";
	printASCII(fileName);
	fileName = "name1.txt";
	SetColor(0, 3);
	string line = " ";
	ifstream inFile;
	inFile.open(fileName);
	if (inFile.is_open())
	{

		while (getline(inFile, line)) {
			cout << "\t  \t";
			cout << line << endl;
		}
	}
	else
	{
		cout << "EROR";
	}
	inFile.close();
}
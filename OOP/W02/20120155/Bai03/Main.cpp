#include"CStudent.h"

int main() {
	CStudent student;
	student.Input();
	cout << student.toString();
	cout << student.AVR(student)<<endl;
	cout << student.Ranked(student);
}
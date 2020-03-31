#include "student.h"
#include<iostream>
#include<fstream>
using namespace std;

Student::Student()
{
	this->id = id;
	this->name = name;
	this->math = math;
	this->liter = liter;
	this->eng = eng;
	this->gpa = 0;
}

Student::~Student()
{
}

//hàm đọc file danh sách sinh viên (chưa có điểm TB)
void Student::ReadFileIn(ifstream& filein)
{
		char x;
		getline(filein, id, SYMPOL);
		getline(filein, name, SYMPOL);
		filein >> math;
		filein >> x;
		filein >> liter;
		filein >> x;
		filein >> eng;
		gpa = (math + liter + eng) / 3;
}

//hàm đọc file danh sách sinh viên (có điểm TB)
void Student::ReadFileOut(ifstream& filein)
{
	char x;
	getline(filein, id, SYMPOL);
	getline(filein, name, SYMPOL);
	filein >> math;
	filein >> x;
	filein >> liter;
	filein >> x;
	filein >> eng;
	filein >> x;
	filein >> gpa;
}

//hàm ghi file danh sách sinh viên
void Student::WriteFile(ofstream& fileout)
{
	fileout << id << SYMPOL << name << SYMPOL << math << SYMPOL << liter << SYMPOL << eng << SYMPOL << gpa;
}

//hàm tìm sinh viên theo tên và id
bool Student::FindStudent(string keyword)
{
	if ((_stricmp(id.c_str(), keyword.c_str()) == 0) || (_stricmp(name.c_str(), keyword.c_str())) == 0)
		return true;
	else return false;
}

// hàm ghi thông tin 1 sinh viên
void Student::PrintInfo()
{
	cout << id + SYMPOL + name + SYMPOL + to_string(math) + SYMPOL + to_string(liter) + SYMPOL + to_string(eng) + SYMPOL + to_string(gpa);
}

// hàm tìm sinh viên có điểm tb trên 5
bool Student::PassedStudent()
{
	if (gpa > 5) return true; else return false;
}


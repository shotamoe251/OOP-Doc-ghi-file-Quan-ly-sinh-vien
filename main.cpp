#include <iostream>
using namespace std;
#include<fstream>
#include<string>
#include<vector>
#include "student.h"

// hàm kiểm tra đã ghi file thành công chưa
bool checkWritten(vector<Student>& list)
{
	bool status = false;
	ofstream fileout(FILESYSTEM, ios_base::out | ios_base::app);
	if (fileout.is_open())
	{
		for (size_t i = 0; i < list.size(); i++)
		{
			list[i].WriteFile(fileout);
		}
		status = true;
	}
	fileout.close();
	return status;
}

// lưu lại mảng các sinh viên
vector<Student> loadStudent()
{
	ifstream f_in(FILESYSTEM, ios_base::in);
	vector<Student> studentlist;
	if (f_in.is_open())
	{
		while (!f_in.eof())
		{
			Student student;
			student.ReadFileOut(f_in);
			studentlist.push_back(student);
		}
	}
	f_in.close();
	return studentlist;
}

int main(int argc, const char* argv[])
{
	vector<Student> list; //mảng list chứa thông tin các sinh viên
	string action = argv[1];
	if (action == "add")
	{
		string filePath = argv[2];
		ifstream filein(filePath, ios_base::in);
		if (filein.is_open())
		{
			while (!filein.eof())
			{
				Student student; //khai báo 1 SV kiểu class
				student.ReadFileIn(filein);
				list.push_back(student); //thêm thông tin 1 SV vào mảng list
			}
		}
		filein.close();

	if (checkWritten(list))
		cout << "Successed!" << endl;
	else cout << "Failed!" << endl;
	}

	if (action == "find")
	{
		vector<Student> list = loadStudent();
		vector <Student> foundlist; //mảng foundlist chứa thông tin sinh viên thoả yêu cầu
		string keyword = argv[2];
		for (size_t i = 0; i < list.size(); i++)
		{
			if (list[i].FindStudent(keyword))
			{
				foundlist.push_back(list[i]);
			}
		}

		if (foundlist.size() > 0)
		{
			cout << "Found Students:\n";
			for (size_t i = 0; i < foundlist.size(); i++)
			{
				cout << i + 1 << ". ";
				foundlist[i].PrintInfo();
				cout << endl;
			}
		}
		else cout << "Not found!\n";

	}
	if (action == "passed")
	{
		vector<Student> list = loadStudent();
		vector <Student> foundlist;
		for (size_t i = 0; i < list.size(); i++)
		{
			if (list[i].PassedStudent())
			{
				foundlist.push_back(list[i]);
			}
		}
		if (foundlist.size() > 0)
		{
			cout << "Passed Students:\n";
			for (size_t i = 0; i < foundlist.size(); i++)
			{
				cout << i + 1 << ". ";
				foundlist[i].PrintInfo();
				cout << endl;
			}
		}
		else cout << "Not found any passed student.\n";
		
	}
	system("pause");
	return 0;
}


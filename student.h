#ifndef Student_h
#define Student_h
constexpr auto SYMPOL = '|';
constexpr auto FILESYSTEM = "OUTPUT.txt";
#include<string>
#include<vector>
using namespace std;

class Student
{
private:
	string id;
	string name;
	float math;
	float liter;
	float eng;
	float gpa;
public:

	Student();
	~Student();
	void ReadFileIn(ifstream&);
	void ReadFileOut(ifstream&);
	void WriteFile(ofstream&);
	bool FindStudent(string);
	void PrintInfo();
	bool PassedStudent();

};



#endif

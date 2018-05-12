#include <iostream>
using namespace std;

class student {
public:
	void InformationInput() {
		printf("Please input the student ID:");
		cin >> stuId;
		printf("Please input the name:");
		cin >> name;
		printf("Please input three score:");
		for (int i = 0; i < 3; i++)
			cin >> score[i];
	}
	void InformationOutput() {
		cout << "the student ID = " << stuId << endl;
		cout << "the student name = " << name << endl;
		cout << "the average score = " << (score[0] + score[1] + score[2]) / 3 << endl;
	}
private:
	int stuId, score[3];
	char name[];
};

student stu1;

int main()
{
	stu1.InformationInput();
	stu1.InformationOutput();

	return 0;
}
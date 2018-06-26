#include <iostream>


struct Student
{
	std::string name;
	int grade;
};


void AskForStudent (Student *student)
{
	std::cout << "Name: ";
	std::cin.ignore (32767, '\n');
	std::getline (std::cin, student->name);
	while (true)
	{
		std::cout << "Grade (0-100): ";
		std::cin >> student->grade;
		if (std::cin.fail())
		{
			std::cin.clear ();
			std::cin.ignore (32767, '\n');
		}
		else
			break;
	}
}


void PrintStudents (Student *students, int length)
{
	for (int i = 0; i < length; ++i)
		std::cout << students[i].name << " got a grade of " << students[i].grade << std::endl;
}


void SortStudents (Student *students, int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		bool requestSwap (false);
		int target (0);
		int max_grade (students[i].grade);
		for (int j = i + 1; j < length; ++j)
			if (max_grade < students[j].grade)
			{
				requestSwap = true;
				target = j;
				max_grade = students[j].grade;
			}
		if (requestSwap)
			std::swap (students[i], students[target]);
	}
}


int main ()
{
	int pop;
	while (true)
	{
		std::cout << "How many students do you want to enter? ";
		std::cin >> pop;
		if (std::cin.fail())
		{
			std::cin.clear ();
			std::cin.ignore (32767, '\n');
		}
		else
			break;
	}

	Student *students = new Student[pop];
	for (int i = 0; i < pop; ++i)
		AskForStudent (&students[i]);

	SortStudents (students, pop);
	PrintStudents (students, pop);

	delete[] students;

	return 0;
}

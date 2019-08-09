#include <iostream>
#include <vector>
#include <string>
using namespace std;


/* Mohammed Touhid Chowdhury 
mtc405
lab 5 
*/


class Student {
public:
	// constructor initializes name and grade 
	Student(const string name) : name(name), grades(13, -1) {}
	// display grade of each student
	void display() const {
		cout << "Student: " << name << "; Grades: ";
		for (size_t i = 0; i < grades.size(); i++) {
			cout << grades[i] << " ";
		}
		cout << endl;
	}
	//change the default grade
	void addGrades(int grade, int week) {
		for (size_t i = 0; i < grades.size(); i++) {
			if (week == i) {
				grades[i] = grade;
			}
		}
	}
	string getName() const {
		return name;
	}
private:
	string name;
	vector<int> grades;
};

class TimeSlot {
public:
	// constructor initializes Timeslot with given day and time 
	TimeSlot(const string day, const int time) : day(day), time(time) {}
	//get day and time
	string getDay() const {
		return day;
	}
	int getTime() const {
		return time;
	}
private:
	string day;
	int time;
};

class Section {
public:
	//initialize a lab with the day and time for it 
	Section(const string labSection, const string day, const int time) : labSection(labSection), timeSlot(day, time) {}
	void addStudent(string studentName) {
		Student* aStudentRecord = new Student(studentName);
		students.push_back(aStudentRecord);

	}
	// add grade calls student method
	void addGrades(string name, int grade, int week) {
		for (size_t i = 0; i < students.size(); i++) {
			if (students[i]->getName() == name) {
				students[i]->addGrades(grade, week);
			}
		}
	}
	//reset the section
	void reset() {
		for (size_t i = 0; i < students.size(); i++) {
			students[i] = nullptr;
		}
		students.clear();
	}
	string getSection() const {
		return labSection;
	}
	string displayDay() const {
		return timeSlot.getDay();
	}
	//display the time
	void displayTime() const {
		if (timeSlot.getTime() > 12) {
			cout << timeSlot.getTime() - 12 << "PM";
		}
		else {
			cout << timeSlot.getTime() << "AM";
		}
	}
	//display the section and time
	void display() const {
		cout << "Section: " << labSection << "; " << displayDay() << " ";
		displayTime();
		cout << endl;
		for (size_t i = 0; i < students.size(); i++) {
			students[i]->display();
		}
	}
	void displayLabWorker() const {
		for (size_t i = 0; i < students.size(); i++) {
			students[i]->display();
		}
	}

private:
	vector<Student*> students;
	string labSection;
	TimeSlot timeSlot;
};

class LabWorker {
public:
	//constructor to initialize each labworker with name
	LabWorker(const string name) : name(name) {}
	// add section to the labworker 
	void addSection(Section& aSection) {
		section = &aSection;
	}
	// lab worker can add grade for student 
	void addGrade(string studentName, int grade, int week) {
		section->addGrades(studentName, grade, week);
	}
	//lab worker can display grade 
	void displayGrades() {
		cout << endl << name << " has ";
		section->display();
		cout << endl;
	}
private:
	string name;
	Section* section;
};




int main() {

	// lab workers
	LabWorker moe("Moe");
	LabWorker jane("Jane");

	// sections and setup and testing
	Section secA2("A2", "Tuesday", 16);
	//secA2.loadStudentsFromFile( "A2.txt" );
	secA2.addStudent("John");
	secA2.addStudent("George");
	secA2.addStudent("Paul");
	secA2.addStudent("Ringo");

	cout << "\ntest A2\n";    // here the modeler-programmer checks that load worked
	secA2.display();          // YOU'll DO THIS LATER AS: cout << secA2 << endl;
	moe.addSection(secA2);
	moe.displayGrades();       // here the modeler-programmer checks that adding the Section worked

	Section secB3("B3", "Thursday", 11);
	//secB3.loadStudentsFromFile( "B3.txt" );
	secB3.addStudent("Thorin");
	secB3.addStudent("Dwalin");
	secB3.addStudent("Balin");
	secB3.addStudent("Kili");
	secB3.addStudent("Fili");
	secB3.addStudent("Dori");
	secB3.addStudent("Nori");
	secB3.addStudent("Ori");
	secB3.addStudent("Oin");
	secB3.addStudent("Gloin");
	secB3.addStudent("Bifur");
	secB3.addStudent("Bofur");
	secB3.addStudent("Bombur");

	cout << "\ntest B3\n";    // here the modeler-programmer checks that load worked
	secB3.display();          // YOU'll DO THIS LATER AS: cout << secB3 << endl;
	jane.addSection(secB3);
	jane.displayGrades();      // here the modeler-programmer checks that adding Instructor worked


							   // setup is complete, now a real world scenario can be written in the code
							   // [NOTE: the modeler-programmer is only modeling joe's actions for the rest of the program]

							   // week one activities
	cout << "\nModeling week: 1\n";
	moe.addGrade("John", 7, 1);
	moe.addGrade("Paul", 9, 1);
	moe.addGrade("George", 7, 1);
	moe.addGrade("Ringo", 7, 1);
	cout << "End of week one\n";
	moe.displayGrades();

	// week two activities
	cout << "\nModeling week: 2\n";
	moe.addGrade("John", 5, 2);
	moe.addGrade("Paul", 10, 2);
	moe.addGrade("Ringo", 0, 2);
	cout << "End of week two\n";
	moe.displayGrades();

	//test that reset works  // NOTE: can we check that the heap data was dealt with?
	cout << "\ntesting reset()\n";
	secA2.reset();
	secA2.display();
	moe.displayGrades();
}
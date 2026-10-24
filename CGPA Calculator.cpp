#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct Course {
string name;
double gradePoints;
double creditHours;
double weightedPoints;
};

int main() {
int numberOfCourses;

double totalCredits = 0;
double totalWeightedPoints = 0;

cout << "====================================\n";
cout << "       CGPA CALCULATOR\n";
cout << "====================================\n";

cout << "Enter the number of courses: ";
cin >> numberOfCourses;

if (numberOfCourses <= 0) {
    cout << "Invalid number of courses!\n";
    return 0;
}

vector<Course> courses(numberOfCourses);

for (int i = 0; i < numberOfCourses; i++) {
    cout << "\nEnter details for Course " << i + 1 << ":\n";

    cout << "Course name: ";
    cin >> ws;
    getline(cin, courses[i].name);

    cout << "Grade points (0 to 10): ";
    cin >> courses[i].gradePoints;

    cout << "Credit hours: ";
    cin >> courses[i].creditHours;

    if (courses[i].gradePoints < 0 ||
        courses[i].gradePoints > 10 ||
        courses[i].creditHours <= 0) {
        cout << "Invalid grade points or credit hours!\n";
        return 0;
    }

    courses[i].weightedPoints =
        courses[i].gradePoints * courses[i].creditHours;

    totalCredits += courses[i].creditHours;
    totalWeightedPoints += courses[i].weightedPoints;
}

double cgpa = totalWeightedPoints / totalCredits;

cout << "\n\n====================================\n";
cout << "         SEMESTER RESULT\n";
cout << "====================================\n";

cout << fixed << setprecision(2);

cout << left
     << setw(22) << "Course Name"
     << setw(15) << "Grade Points"
     << setw(15) << "Credits"
     << "Weighted Points\n";

cout << "------------------------------------------------------------\n";

for (int i = 0; i < numberOfCourses; i++) {
    cout << left
         << setw(22) << courses[i].name
         << setw(15) << courses[i].gradePoints
         << setw(15) << courses[i].creditHours
         << courses[i].weightedPoints << '\n';
}

cout << "------------------------------------------------------------\n";

cout << "Total Credit Hours: " << totalCredits << '\n';
cout << "Total Weighted Grade Points: "
     << totalWeightedPoints << '\n';

cout << "Semester CGPA: " << cgpa << '\n';

cout << "====================================\n";
cout << "     Thank you for using the calculator!\n";

return 0;

}


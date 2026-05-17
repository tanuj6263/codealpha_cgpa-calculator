#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    
    cout << "Enter number of courses: ";
    cin >> n;

    vector<string> grades(n);
    vector<int> credits(n);
    vector<double> gradePoints(n);

    double totalCredits = 0;
    double totalGradePoints = 0;

    cout << "\nGrade Mapping:\n";
    cout << "O = 10\nA+ = 9\nA = 8\nB+ = 7\nB = 6\nC = 5\nF = 0\n";

    for (int i = 0; i < n; i++) {
        cout << "\nEnter grade for course " << i + 1 << ": ";
        cin >> grades[i];

        cout << "Enter credit hours for course " << i + 1 << ": ";
        cin >> credits[i];

        // Convert grade to grade points
        if (grades[i] == "O")
            gradePoints[i] = 10;
        else if (grades[i] == "A+")
            gradePoints[i] = 9;
        else if (grades[i] == "A")
            gradePoints[i] = 8;
        else if (grades[i] == "B+")
            gradePoints[i] = 7;
        else if (grades[i] == "B")
            gradePoints[i] = 6;
        else if (grades[i] == "C")
            gradePoints[i] = 5;
        else
            gradePoints[i] = 0;

        totalCredits += credits[i];
        totalGradePoints += gradePoints[i] * credits[i];
    }

    double cgpa = totalGradePoints / totalCredits;

    cout << "\n----- Course Details -----\n";

    for (int i = 0; i < n; i++) {
        cout << "Course " << i + 1
             << " | Grade: " << grades[i]
             << " | Credits: " << credits[i]
             << " | Grade Points: " << gradePoints[i]
             << endl;
    }

    cout << "\nTotal Credits = " << totalCredits << endl;
    cout << "Total Grade Points = " << totalGradePoints << endl;

    cout << fixed << setprecision(2);
    cout << "\nFinal CGPA = " << cgpa << endl;

    return 0;
}

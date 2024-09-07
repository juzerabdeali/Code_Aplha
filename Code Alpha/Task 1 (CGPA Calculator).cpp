#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Course {
    string course_name;
    int credit_hour;
    float grade_point;
};

float Calculate_GPA(vector<Course> course) {
    float total_credit_hour = 0.0;
    float total_grade_point = 0.0;
    float SGPA = 0.0;
    
    for (int i = 0; i < course.size(); i++) {
        total_grade_point += course[i].grade_point * course[i].credit_hour;
        total_credit_hour += course[i].credit_hour;
    }
    
    SGPA = total_grade_point / total_credit_hour;
    return SGPA;
}

int main() {
    int num_semester;
    cout << "Enter no. of Semesters: ";
    cin >> num_semester;

    vector<float> SGPA;

    for (int i = 0; i < num_semester; i++) {
        int num_courses;
        cout << "Enter no. of Courses in Semester " << i + 1 << ": ";
        cin >> num_courses;

        vector<Course> course(num_courses); 

        for (int j = 0; j < num_courses; j++) {
            cout << endl;
            
            cout << "Enter Name of the Course no. " << j + 1 << ": ";
            cin >> ws; 
            getline(cin, course[j].course_name);

            cout << "Enter Credit Hours of the Course no. " << j + 1 << ": ";
            cin >> course[j].credit_hour;

            cout << "Enter Grade Point of the Course no. " << j + 1 << ": ";
            cin >> course[j].grade_point;

            cout << endl;
        }

        SGPA.push_back(Calculate_GPA(course));
    }

    float CGPA = 0.0;    
    float total_SGPA = 0.0;

    for (int i = 0; i < SGPA.size(); i++) {
        total_SGPA += SGPA[i];
    }

    CGPA = total_SGPA / num_semester;

    cout << fixed << setprecision(2) << "Your CGPA for " << num_semester << " semesters is " << CGPA << endl;

    return 0;
}

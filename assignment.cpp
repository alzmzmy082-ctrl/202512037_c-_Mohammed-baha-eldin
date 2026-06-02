#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Student
{
    string rollNumber;
    string name;
    int age;
};

const string filename = "student.txt";

// Load students from file
vector<Student> loadStudents()
{
    vector<Student> students;
    ifstream file(filename);

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        Student s;

        getline(ss, s.rollNumber, ',');
        getline(ss, s.name, ',');

        string ageStr;
        getline(ss, ageStr, ',');
        s.age = stoi(ageStr);

        students.push_back(s);
    }

    file.close();
    return students;
}

// Save students to file
void saveStudents(vector<Student>& students)
{
    ofstream file(filename);

    for (Student s : students)
    {
        file << s.rollNumber << ","
             << s.name << ","
             << s.age << endl;
    }

    file.close();
}

// Display all students
void displayStudents()
{
    vector<Student> students = loadStudents();

    if (students.empty())
    {
        cout << "No students found.\n";
        return;
    }

    cout << "\n--- Student Records ---\n";

    for (Student s : students)
    {
        cout << "Roll Number: " << s.rollNumber << endl;
        cout << "Name: " << s.name << endl;
        cout << "Age: " << s.age << endl;
        cout << "----------------------\n";
    }
}

// Search student
void searchStudent()
{
    string roll;
    cout << "Enter Roll Number: ";
    cin >> roll;

    vector<Student> students = loadStudents();

    for (Student s : students)
    {
        if (s.rollNumber == roll)
        {
            cout << "\nStudent Found\n";
            cout << "Roll Number: " << s.rollNumber << endl;
            cout << "Name: " << s.name << endl;
            cout << "Age: " << s.age << endl;
            return;
        }
    }

    cout << "Student not found.\n";
}

// Update student
void updateStudent()
{
    string roll;
    cout << "Enter Roll Number to update: ";
    cin >> roll;

    vector<Student> students = loadStudents();

    bool found = false;

    for (auto &s : students)
    {
        if (s.rollNumber == roll)
        {
            found = true;

            cout << "Enter New Name: ";
            cin >> s.name;

            cout << "Enter New Age: ";
            cin >> s.age;

            break;
        }
    }

    if (found)
    {
        saveStudents(students);
        cout << "Student updated successfully.\n";
    }
    else
    {
        cout << "Student not found.\n";
    }
}

// Delete student
void deleteStudent()
{
    string roll;
    cout << "Enter Roll Number to delete: ";
    cin >> roll;

    vector<Student> students = loadStudents();
    vector<Student> newList;

    bool found = false;

    for (Student s : students)
    {
        if (s.rollNumber == roll)
        {
            found = true;
        }
        else
        {
            newList.push_back(s);
        }
    }

    if (found)
    {
        saveStudents(newList);
        cout << "Student deleted successfully.\n";
    }
    else
    {
        cout << "Student not found.\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Display All Students\n";
        cout << "2. Search Student\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                displayStudents();
                break;

            case 2:
                searchStudent();
                break;

            case 3:
                updateStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                cout << "Program Ended.\n";
                break;

            default:
                cout << "Invalid Choice.\n";
        }

    } while (choice != 5);

    return 0;
}
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Student
{
public:
   Student();
   Student(const Student & student);
   ~Student();

   void Set(const int uaid, const string name, const float gpa);
   void Get(int & uaid, string & name, float & gpa) const;
   void Print() const;
   void Read();

private:
   int Uaid;
   string Name;
   float Gpa;
};

Student::Student()
{
   Uaid = 0;
   Name = "none";
   Gpa = 0;
}

Student::Student(const Student & student)
{
   Uaid = student.Uaid;
   Name = student.Name;
   Gpa = student.Gpa;
}

Student::~Student()
{
}

void Student::Set(const int uaid, const string name, const float gpa)
{
   Uaid = uaid;
   Name = name;
   Gpa = gpa;
   if (Gpa < 0.0) Gpa = 0.0;
   else if (Gpa > 4.0) Gpa = 4.0;
}

void Student::Get(int &uaid, string & name, float &gpa) const
{
   uaid = Uaid;
   name = Name;
   gpa = Gpa;
}

void Student::Print() const
{
   cout << Uaid << " " << Name << " " << Gpa << endl;
}

void Student::Read()
{
   cin >> Uaid >> Name >> Gpa;
   if (Gpa < 0.0) Gpa = 0.0;
   else if (Gpa > 4.0) Gpa = 4.0;
}


class Course
{
public:
   Course(const int count);
   Course(const Course & course);
   ~Course();

   void Print() const;
   void Read();

private:
   static const int MAX_STUDENTS = 100;
   Student students[MAX_STUDENTS];
   int num_students;
};


Course::Course(const int count)
{
   cout << "Constructor" << endl;
   num_students = count;
}

Course::Course(const Course & course)
{
   cout << "Copy Constructor" << endl;
   num_students = course.num_students;
   for (int index = 0; index < num_students; index++)
   {
      students[index] = course.students[index];
   }
}

Course::~Course()
{
   cout << "Destructor" << endl;
}

void Course::Print() const
{
   cout << "Print" << endl;
   for (int index = 0; index < num_students; index++)
   {
      students[index].Print();
   }
}

void Course::Read()
{
   cout << "Read" << endl;
   for (int index = 0; index < num_students; index++)
   {
      students[index].Read();
   }
}


int main()
{
   cout << "Testing Student class\n";
   Student student1;
   student1.Set(1234, "John", 2.5);
   student1.Print();

   cout << "Testing Course class\n";
   Course course(5);
   course.Print();

   course.Read();
   course.Print();
   return 0;
}

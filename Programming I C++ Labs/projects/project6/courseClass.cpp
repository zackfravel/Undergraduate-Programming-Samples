//Include Statements
#include <iostream>
#include <fstream>
using namespace std;

class Course_taken 
{
public:
   Course_taken(); // default constructor
   void get(string& name, string& time, string& number, char& g, int& h) const;
   void set(string name, string time, string number, char g, int h);
   void print() const;

private:
   string className;
   string classTerm;
   string courseNumber;
   char grade;
   int hours;
};

Course_taken::Course_taken()
{
   className = "Programming Foundations I";
   classTerm = "Fall 2015";
   courseNumber = "CSCE 2004";
   grade = 'A';
   hours = 4;
}

void Course_taken::get(string& name, string& time, string& number, char& g, int& h) const
{
   name = className;
   time = classTerm;
   number = courseNumber;
   g = grade;
   h = hours;
}

void Course_taken::set(string name, string time, string number, char g, int h)
{
   className = name;
   classTerm = time;
   courseNumber = number;
   grade = g;
   hours = h;
}

void Course_taken::print() const
{
   cout << className << endl;
   cout << classTerm << endl;
   cout << courseNumber << endl;
   cout << grade << endl;
   cout << hours << endl;
}

/*Main Program Function*/
int main()
{
   string className;
   string classTerm;
   string courseNumber;
   char grade = ' ';
   int hours = 0;

   Course_taken test[5];
   test[0].print();
   test[1].set(className, classTerm, courseNumber, grade, hours);
   test[1].print();
   test[2].print();
}

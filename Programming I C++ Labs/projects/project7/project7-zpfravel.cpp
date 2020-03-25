//Include Statements
#include <iostream>
#include <fstream>
using namespace std;

//Requirements class
class Requirements
{
public:
   Requirements(string reqFilename[], string reqGrp, int fileLength); // default constructor
   void Audit(string name[], char grd[], int hrs[], int n);

private:
   string reqGroup;
   string reqSubgroup[7];
   string reqHrs[7];
   string reqCourseNames[7][100];
   string reqCourseHours[7][100];

};

Requirements::Requirements(string reqFilename[], string reqGrp, int fileLength)
{
   // integer array used to track where in the requiremnets file the groups are
   // initialized to -1 as a check
   int GrpLoc[7] = {-1, -1, -1, -1, -1, -1, -1};
   int a = 0;
   int b = 0;
   reqGroup = reqGrp;

   // Finds the line where the subgroup starts, and places it in the next index
   for (int i = 0; i < fileLength; i++)
	if(reqFilename[i] == reqGrp)
	{
		GrpLoc[a] = i;
		a ++;
	}

   for (int i = 0; i < 7; i++)
   {
	if (GrpLoc[i] != -1) // Assignment check
	{
		//Sets the subgroups and respective number of hours
		reqSubgroup[b] = reqFilename[GrpLoc[i]+1];
		reqHrs[b] = reqFilename[GrpLoc[i]+2];

		int c = 0;
   		int d = 0;
		
		while (reqFilename[GrpLoc[i] + 3 + c].length() != 0)
		{
			//Sets Course Name and Hours
			reqCourseNames[i][d] = reqFilename[GrpLoc[i]+3+c];
			reqCourseHours[i][d] = reqFilename[GrpLoc[i]+4+c];

			d++;
			c = c + 2;
		}
		
		b++;
	}
   }

   for (int i = 0; i < 7; i++)
   {
	cout << "Group: " << reqGroup << endl;
	cout << "Subgroup: " << reqSubgroup[i] << endl;
	cout << "Required Hours: " << reqHrs[i] << endl;
	cout << "Courses: " << endl;
	for (int o = 0; o < 50; o++)
	{
		cout << reqCourseNames[i][o] << " -> " << reqCourseHours[i][o] << endl;
	}
	cout << " " << endl;
   }

}

//Degree Audit Funciton
void Requirements::Audit(string num[], char grd[], int hrs[], int n)
{
	for (int i = 0; i < 7; i++)
	{
		int hoursEarned = 0;
		for (int nameCount = 0; nameCount < n; nameCount++)
		{
			for (int reqNameCount = 0; reqNameCount < 100; reqNameCount++)
			{
				if(num[nameCount] == reqCourseNames[i][reqNameCount])
					hoursEarned = hoursEarned + hrs[nameCount];
			}
		}

		//Convert the required hours from string to integer
		int requiredHours = 0;
		if (reqHrs[i] == "0"){
			requiredHours = 0;
		}else if (reqHrs[i] == "1"){
			requiredHours = 1;
		}else if (reqHrs[i] == "2"){
			requiredHours = 2;
		}else if (reqHrs[i] == "3"){
			requiredHours = 3;
		}else if (reqHrs[i] == "4"){
			requiredHours = 4;
		}else if (reqHrs[i] == "5"){
			requiredHours = 5;
		}else if (reqHrs[i] == "6"){
			requiredHours = 6;
		}else if (reqHrs[i] == "7"){
			requiredHours = 7;
		}else if (reqHrs[i] == "8"){
			requiredHours = 8;
		}else if (reqHrs[i] == "9"){
			requiredHours = 9;
		}else{
			requiredHours = 10;}

		if(hoursEarned == 0){
			cout << reqSubgroup[i] << " requirement is not met at all." << endl;
		}else if(hoursEarned == requiredHours){
			cout << reqSubgroup[i] << " requirement is met!" << endl;
		}else{
			cout << reqSubgroup[i] << " requirement is partially met." << endl;
		}
	}
	cout << "\n" << endl;
}

//Course_taken class
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

//Default course constructor
Course_taken::Course_taken()
{
   className = "Programming Foundations I";
   classTerm = "Fall 2015";
   courseNumber = "CSCE 2004";
   grade = 'A';
   hours = 4;
}

//Allows user to retrieve all five pieces of information per class
void Course_taken::get(string& name, string& time, string& number, char& g, int& h) const
{
   name = className;
   time = classTerm;
   number = courseNumber;
   g = grade;
   h = hours;
}

//Sets the object variables to the inputted parameters
void Course_taken::set(string name, string time, string number, char g, int h)
{
   className = name;
   classTerm = time;
   courseNumber = number;
   grade = g;
   hours = h;
}

//Prints the list stored within the array of objects
void Course_taken::print() const
{
   cout << className << endl;
   cout << classTerm << endl;
   cout << courseNumber << endl;
   cout << grade << endl;
   cout << hours << endl;
}

/*
//End of Course_taken class/function defintions
*/

//GPA Function
float gpa(const char grade[], const int hours[], int classes)
{
	//Reinitialize variables to accurately calculate multiple times
	float weightedHours = 0;
	float totalHours = 0;

	//Runs through the grade array to determine weight
	for(int c=0; c < classes; c++)
	{
		//Determine correct weight
		if (grade[c] == 'A')
		{
			weightedHours = weightedHours + 4*hours[c];
			totalHours = totalHours + hours[c];
		}
		else if (grade[c] == 'B')
		{
			weightedHours = weightedHours + 3*hours[c];
			totalHours = totalHours + hours[c];
		}
		else if (grade[c] == 'C')
		{
			weightedHours = weightedHours + 2*hours[c];
			totalHours = totalHours + hours[c];
		}
		else if (grade[c] == 'D')
		{
			weightedHours = weightedHours + hours[c];
			totalHours = totalHours + hours[c];
		}
		else if (grade[c] == 'F')
		{
			weightedHours = weightedHours + 0;
			totalHours = totalHours + hours[c];
		}
		else if (grade[c] == 'W')
		{
			weightedHours = weightedHours + 0;
			totalHours = totalHours + 0;
		}
		else if (grade[c] == 'I')
		{
			weightedHours = weightedHours + 0;
			totalHours = totalHours + 0;
		}
	}

	//Calculate total GPA
	float GPA = weightedHours/totalHours;

	return GPA;
}

//GPA (Semester) Function
float semester_gpa(const string classTerm[], const char grade[], const int hours[], string termChoice, int classes)
{
	//reinitialize variables
	float totalHours = 0;
	float weightedHours = 0;

	//Specify term
	cout << "What term would you like your GPA calculated from?" << endl;
	cin.ignore();
	getline(cin, termChoice);
			
	//Matches the user's term with the known list
	for(int c = 0; c < classes; c++)
	{
		if(classTerm[c] == termChoice)
		{
			//Determine correct weight for calculation
			if (grade[c] == 'A')
			{
				weightedHours = weightedHours + 4*hours[c];
				totalHours = totalHours + hours[c];
			}
			else if (grade[c] == 'B')
			{
				weightedHours = weightedHours + 3*hours[c];
				totalHours = totalHours + hours[c];
			}
			else if (grade[c] == 'C')
			{
				weightedHours = weightedHours + 2*hours[c];
				totalHours = totalHours + hours[c];
			}
			else if (grade[c] == 'D')
			{
				weightedHours = weightedHours + hours[c];
				totalHours = totalHours + hours[c];
			}
			else if (grade[c] == 'F')
			{
				weightedHours = weightedHours + 0;
				totalHours = totalHours + hours[c];
			}
			else if (grade[c] == 'W')
			{
				weightedHours = weightedHours + 0;
				totalHours = totalHours + 0;
			}	
			else if (grade[c] == 'I')
			{
				weightedHours = weightedHours + 0;
				totalHours = totalHours + 0;
			}
		}else{
			//Nothing
		}
	}
	//Calculate term GPA
	float GPA = weightedHours/totalHours;

	return GPA;
}

//Hours with Grade D Function
int D_rule(char grade[], int hours[], int classes)
{
	//reinitialize totalHours
	float dHours = 0;

	//Scans all grades for 'D'
	for(int c = 0; c < classes; c++)
	{
		if(grade[c] == 'D')
		{
			dHours = dHours + hours[c];
		}
	}

	return dHours;
}

//List Function
void listing(string className[], string classTerm[], string courseNumber[], char grade[], int hours[], int classes)
{
	//Displays the list of courses and data using for loops and respective arrays
	cout << "\n" << endl;
	cout << "You have taken " << classes << " classes." << endl;
	cout << "\n" << endl;

	cout << "Classes: ";
	for(int c=0; c < classes; c++)
	{
		cout << className[c] << "  ";	
	}
	cout << "\n" << endl;

	cout << "Terms: ";
	for(int c=0; c < classes; c++)
	{
		cout << classTerm[c] << "  ";	
	}
	cout << "\n" << endl;

	cout << "Course Numbers: ";
	for(int c=0; c < classes; c++)
	{
		cout << courseNumber[c] << "  ";	
	}
	cout << "\n" << endl;

	cout << "Grades: ";
	for(int c=0; c < classes; c++)
	{
		cout << grade[c] << " ";	
	}
	cout << "\n" << endl;

	cout << "Hours: ";
	for(int c=0; c < classes; c++)
	{
		cout << hours[c] << " ";	
	}
	cout << "\n" << endl;
}

//Read-In Course Function
void get_course(string& className, string& classTerm, string& courseNumber, char& grade, int& hours, int classes)
{
	if(classes < 100)
	{
		//input class name
		cout << "Class name: " << endl;
		cin.ignore();
		getline(cin, className);
		cout << "\n";

		//input/validate term of enrollment
		cout << "Term of enrollment: " << endl;
		getline(cin, classTerm);
		cout << "\n";

		//input course number
		cout << "Course number: " << endl;
		getline(cin, courseNumber);
		cout << "\n";

		//Checks whether or not the grade is valid
		while ((grade != 'A')&&(grade != 'B')&&(grade != 'C')&&(grade != 'D')&&
		(grade != 'F')&& (grade != 'W')&&(grade != 'I'))
		{
			//input grade
			cout << "Grade: " << endl;
			cin >> grade;
			cout << "\n";
		}

		//input hours and checks validity
		while ((hours > 5)||(hours < 1))
		{
			cout << "Hours (1-5): " << endl;
			cin >> hours;
			cout << "\n";
		}
	}else{
		cout << "Error: not enough memory in storage location" << endl;
	}

	//increment classes so the values are stored/read correctly
	classes ++; 

}

//Menu Function
char menu()
{
	//Declare variable
	char menuChoice;

	//Display Menu
	cout << "Welcome to the GPA and Course storage program menu." << endl;
	cout << "Now that you've entered your class information, please enter the character next to the choice you wish to pick.\n" << 	endl;

	//Checks whether or not the user wants to exit the program (Displays menu every time until)
	while (!(menuChoice == 'A')&&!(menuChoice == 'a')&&!(menuChoice == 'B')&&!(menuChoice == 'b')&&!(menuChoice == 'C')&&!(menuChoice == 'c')&&! 		(menuChoice == 'D')&&!(menuChoice == 'd')&&!(menuChoice == 'E')&&!(menuChoice == 'e')&&!(menuChoice == 'Q')&&!(menuChoice == 'q')&&!
	(menuChoice == 'F')&&!(menuChoice == 'f')&&!(menuChoice == 'R')&&!(menuChoice == 'r'))
	{
		cout << "A. Compute the GPA for all courses" << endl;
		cout << "B. List all courses" << endl;
		cout << "C. Compute the total credit hours of courses with grade D" << endl;
		cout << "D. Compute the GPA for a particular semester" << endl;
		cout << "E. Add another course to the course list" << endl;
		cout << "F. Remove a course from the current list" << endl;
		cout << "R. List the requirements for a BSCE Degree" << endl;
		cout << "Q. Quit the program" << endl;
		cin >> menuChoice;
	}
	return menuChoice;
}

bool writing(const char filename[], const string className[], const string classTerm[], const string courseNumber[], const char grade[], const int hours[], int classes)
{
	//Declare and open outfile "courses.txt"
	ofstream outfile;
	outfile.open(filename);

	//File failure check
	if (outfile.fail())
	{
  	 	cout << "Error: could not open output file." << endl;
  	 	return false;
	}

	//Output to file
	outfile << classes << endl;
	for (int c = 0; c < classes; c++)
	{
		outfile << className[c] << endl;
		outfile << classTerm[c] << endl;
		outfile << courseNumber[c] << endl;
		outfile << grade[c] << endl;
		outfile << hours[c] << endl;
	}

	cout << "Successfully outputted the five parallel arrays to " << filename << "!" << endl;
	//Close file
	outfile.close();
	return true;
}

bool reading(const char filename[], string className[], string classTerm[], string courseNumber[], char grade[], int hours[], int& classes, int size)
{
	//Declare and open infile "courses.txt"
	ifstream infile;
	infile.open(filename);

	//infile check
	if (infile.fail())
	{
  	 	cout << "Error: could not open input file, exiting program." << endl;
  	 	return false;
	}

	//Input to file
	infile >> classes;

	//Check for number of classes
	if (classes > size)
	{
		cout << "Error: not enough memory." << endl;
	}
	for (int i = 0; i < classes; i++)
	{
		infile.ignore();
		getline(infile, className[i]);
		getline(infile, classTerm[i]);
		getline(infile, courseNumber[i]);
		infile >> grade[i];
		infile >> hours[i];
	}
	//Close file
	infile.close();
	return true;
}

//Read in Requirement File
int getting_reqs(const char filename[], string a[], int& n)
{
   n = 0;
   fstream file;
   int m=0;
   string s;
   file.open(filename);

   if ( file.fail() )
   {
	cout << "failed to open file named: " << filename << endl;
 	return false;
   }

   getline(file,s);
   while (! file.eof() )
   {
 	a[n] = s;
 	n++;

 	if (s.length() == 0 )
	{
 	   m++;
 	}
 	getline(file,s);
   }
   // unless ends with blank line
   m++;
   file.close();
   return m;
}

/*Main Program Function*/
int main()
{

        //Initialize Variables
	const int size = 100;
        int classes = 0;
        int count = 0;
        string className[size];
        string courseNumber[size];
        string classTerm[size];
        string termChoice;
        char grade[size];
        char menuChoice = ' ';
	char inputChoice = ' ';
	char fileName[60];
        int hours[size];
        float dHours = 0;
        float GPA = 0;

	//Initialize array of courses using the Course_taken class 
        Course_taken courses[size];

	//Display initial message and wait for the user to continue
	cout << "\n" << endl;
	cout << "Welcome to the University Degree Audit Program!" << endl;
	cout << "\n" << endl;

	//Ask the user how they'd like to input their data
	cout << "How would you like to input your course data?" << endl;
	cout << "[A] " << "Read in from the default file (courses.txt)" << endl;
	cout << "[B] " << "Read in from another specified file" << endl;
	cout << "[C] " << "Manual input" << endl;

	cin >> inputChoice;

	//Read-in from default file
	if ((inputChoice == 'A') || (inputChoice == 'a'))
	{
		reading("courses.txt", className, classTerm, courseNumber, grade, hours, classes, size);
		cout << "\n" << endl;
	}
	//Read-in from a different file
	else if ((inputChoice == 'B') || (inputChoice == 'b'))
	{
		cout << "Enter the name of your input file." << endl;
		cin >> fileName;
		if (!(reading(fileName, className, classTerm, courseNumber, grade, hours, classes, size)))
		{
			return 0;
		}
		cout << "\n" << endl;
	}
	//Manual input
	else
	{
		//Ask the User for the number of classes
		cout << "Enter how many classes you're taking/have taken: ";
		cin >> classes;
		cout << "\n";

		//Allows the user to input any number of classes
		while(count < classes)
		{
			get_course(className[count], classTerm[count], courseNumber[count], grade[count], hours[count], count + 1);
			count = count + 1;
		}

	}
	
	//Display menu of options
	menuChoice = menu();
	while(!(menuChoice == 'Q')&&!(menuChoice == 'q'))
	{
		//Performs the correct task based on the menu choice
		//Total GPA Option
		if((menuChoice == 'A') || (menuChoice == 'a'))
		{
			GPA = gpa(grade, hours, classes);
			cout << "\n" << endl;
			cout << "Your GPA is: " << GPA << endl;
			cout << "\n" << endl;

		//List Option
		}else if((menuChoice == 'B') || (menuChoice == 'b'))
		{
			listing(className, classTerm, courseNumber, grade, hours, classes);

		//D-Rule Option
		}else if((menuChoice == 'C') || (menuChoice == 'c'))
		{
			dHours = D_rule(grade, hours, classes);
			cout << "\n" << endl;
			cout << "Total hours (grade D): " << dHours << endl;
			cout << "\n" << endl;

		//Semester GPA Option
		}else if((menuChoice == 'D') || (menuChoice == 'd'))
		{
			GPA = semester_gpa(classTerm, grade, hours, termChoice, classes);
			cout << "\n" << endl;
			cout << "Your GPA for " << termChoice << " is: " << GPA << endl;
			cout << "\n" << endl;

		//Read-In Option
		}else if((menuChoice == 'E') || (menuChoice == 'e'))
		{
			//Check if there is available memory in array
			if(classes == size)
			{
				cout << "No memory to store more class data, sorry.\n";
			}else{
				//Allows user to read-in class, incriments number of classes by 1
				get_course(className[classes], classTerm[classes], courseNumber[classes], grade[classes], hours[classes], classes + 1);
				classes = classes + 1;
				//List courses with additions
				listing(className, classTerm, courseNumber, grade, hours, classes);
			}
		//Delete Option
		}else if((menuChoice == 'F') || (menuChoice == 'f'))
		{
			//Declare variables
			int index;
			char confirmation;

			//Ask the user which item to remove
			cout << " \n " << endl;
			cout << "Enter the index of the course you'd like to remove" << endl;
			for (int c = 0; c < classes; c++)
			{
				cout << "[" <<c << "] " << className[c] << endl;
			}

			//input index
			cin >> index;
			//index checker
			while (index < 0 || index > classes -1)
			{
				cout << "Error: please enter a valid index." << endl;
				cin >> index;
			}

			//Display course to user
			cout << "Is this the course you'd like to remove?" << endl;
			cout << "Name: " << className[index] << endl;
			cout << "Semester: " << classTerm[index] << endl;
			cout << "Course Number: " << courseNumber[index] << endl;
			cout << "Grade: " << grade[index] << endl;
			cout << "Hours: " << hours[index] << endl;
			cout << endl << "y/n" << endl;

			//input confirmation
			cin >> confirmation;

			//confirmation check
			while (!(confirmation == 'y' || confirmation == 'n'))
			{
				cout << "Error: please input a valid selection (y/n)." << endl;
				cin >> confirmation;
			}

			if (confirmation == 'y')
			{
				//Check position of course in array (end or beginning/middle)
				if (!(index == (classes - 1)))
				{
					//Beginning/Middle case
					//Pushes course down one index and overwrites index course
					for (int i = index; i < (classes -1); i++)
					{
						className[i] = className[i +1];
						classTerm[i] = classTerm[i +1];
						courseNumber[i] = courseNumber[i +1];
						grade[i] = grade[i +1];
						hours[i] = hours[i +1];
					}
				}
				//decriment total courses
				classes --;
				cout << "Course deleted." << endl;
			}
			else{
				cout << "Course deletion cancelled." << endl;
			}
		//List Requirements Option
		}else if((menuChoice == 'R') || (menuChoice == 'r'))
		{	
			cout << "\n" << endl;
			//READ IN FILE
			int n;
			string requirement_file[700];
			getting_reqs("BSCErequirements.txt", requirement_file, n);

			//Construct object for University Core Requirements
			Requirements UnivCore(requirement_file, "University Core", 700);
			cout << "\n" << endl;

			//Initialize five parallel arrays for distinct list of courses to audit
			string LclassName[size];
			string LclassTerm[size];
			string LcourseNumber[size];
			char Lgrade[size];
			int Lhours[size];

			for (int i=0; i < size; i++)
			{
				if(grade[i] != 'F' && grade[i] != 'W' && grade[i] != 'I')
				{
					LclassName[i] = className[i];
					LclassTerm[i] = classTerm[i];
					LcourseNumber[i] = courseNumber[i];
					Lgrade[i] = grade[i];
					Lhours[i] = hours[i];
				}
			}
			
			//Perform Degree Audit
			UnivCore.Audit(LcourseNumber, Lgrade, Lhours, size);

		}
		//Re-display Menu
		menuChoice = menu();
	}

	//Writes all information in the 5 parallel arrays into the array of objects in the Course_taken class
	for(int i = 0; i < classes; i++)
	{
		courses[i].set(className[i], classTerm[i], courseNumber[i], grade[i], hours[i]);
	}

	//Checking file to make sure both lists match
	ofstream outfile;
	outfile.open("checking.txt");

	outfile << classes << endl;
	//Output to file
	for (int c = 0; c < classes; c++)
	{
		//Creates placeholder variables for course_taken class values
		string name;
		string time;
		string num;
		char grd;
		int hrs;

		courses[c].get(name, time, num, grd, hrs);

		//Output list to checking.txt
		outfile << name << endl;
		outfile << time << endl;
		outfile << num << endl;
		outfile << grd << endl;
		outfile << hrs << endl;
	}

	cout << "Successfully outputted course_taken class data to checking.txt!" << endl;
	//Close checking.txt
	outfile.close();

	//Outputs the five parallel arrays to a file "courses.txt"
	writing("courses.txt", className, classTerm, courseNumber, grade, hours, classes);

	cout << "\n" << endl;

	return 0;
}

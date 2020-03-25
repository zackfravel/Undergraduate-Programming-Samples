//Include Statements
#include <iostream>
using namespace std;

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
				weightedHours = 0;
				totalHours = totalHours + hours[c];
			}else{
				weightedHours = 0;
				totalHours = totalHours;
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
	//Displays the list of courses using a for loop and the courseName array
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
	if(classes < 10)
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
		cin >> courseNumber;
		cout << "\n";

		//input hours and checks validity
		while ((hours > 5)||(hours < 1))
		{
			cout << "Hours (1-5): " << endl;
			cin >> hours;
			cout << "\n";
		}

		//Checks whether or not the grade is valid
		while ((grade != 'A')&&(grade != 'B')&&(grade != 'C')&&(grade != 'D')&&
		(grade != 'F')&& (grade != 'W')&&(grade != 'I'))
		{
			//input grade
			cout << "Grade: " << endl;
			cin >> grade;
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
	while (!(menuChoice == 'A')&&!(menuChoice == 'a')&&!(menuChoice == 'B')&&!(menuChoice == 'b')&&!(menuChoice == 'C')&&!(menuChoice == 'c')&&!(menuChoice == 'D')&&!(menuChoice == 'd')&&!(menuChoice == 'E')&&!(menuChoice == 'e')&&!(menuChoice == 'Q')&&!(menuChoice == 'q'))
	{
		cout << "A. Compute the GPA for all courses" << endl;
		cout << "B. List all courses" << endl;
		cout << "C. Compute the total credit hours of courses with grade D" << endl;
		cout << "D. Compute the GPA for a particular semester" << endl;
		cout << "E. Add another course to the course list" << endl;
		cout << "Q. Quit the program" << endl;
		cin >> menuChoice;
	}
	return menuChoice;
}

/*Main Program Function*/
int main()
{
        //Initialize Variables
	const int size = 10;
        int classes = 0;
        int count = 0;
        string className[size];
        string courseNumber[size];
        string classTerm[size];
        string termChoice;
        char grade[size];
        char menuChoice;
        int hours[size];
        float dHours = 0;
        float GPA = 0;

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

	//Display menu of options
	menuChoice = menu();
	while(!(menuChoice == 'Q')&&!(menuChoice == 'q'))
	{
		//Performs the correct task based on the menu choice
		if((menuChoice == 'A') || (menuChoice == 'a'))
		{
			GPA = gpa(grade, hours, classes);
			cout << "\n" << endl;
			cout << "Your GPA is: " << GPA << endl;
			cout << "\n" << endl;

		}else if((menuChoice == 'B') || (menuChoice == 'b'))
		{
			listing(className, classTerm, courseNumber, grade, hours, classes);

		}else if((menuChoice == 'C') || (menuChoice == 'c'))
		{
			dHours = D_rule(grade, hours, classes);
			cout << "\n" << endl;
			cout << "Total hours (grade D): " << dHours << endl;
			cout << "\n" << endl;
	
		}else if((menuChoice == 'D') || (menuChoice == 'd'))
		{
			GPA = semester_gpa(classTerm, grade, hours, termChoice, classes);
			cout << "\n" << endl;
			cout << "Your GPA for " << termChoice << " is: " << GPA << endl;
			cout << "\n" << endl;

		}else if((menuChoice == 'E') || (menuChoice == 'e'))
		{
			if(classes == size)
			{
				cout << "No room to store more class data, sorry.\n";
			}else
			{
				get_course(className[classes], classTerm[classes], courseNumber[classes], grade[classes], hours[classes], classes + 1);
				classes = classes + 1;
				//List courses with additions
				listing(className, classTerm, courseNumber, grade, hours, classes);
			}
		}

		menuChoice = menu();
	}

	cout << "\n" << endl;
	return 0;
}

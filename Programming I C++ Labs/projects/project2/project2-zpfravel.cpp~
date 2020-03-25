//Include Statements
#include <iostream>
using namespace std;

int main()
{
	//Initialize Variables
	int classes = 0;
	int count = 0;
	string className;
	string courseNumber;
	char grade;
	int hours;
	int weightedHours;
	float totalHours = 0;
	float totalWeightedHours = 0;
	float GPA = 0;

	//Ask the User for the number of classes
	cout << "Enter how many classes you're taking: ";
	cin >> classes;
	cout << "\n";

	//Allows the user to input any number of classes
	while(count < classes)
	{
		//reset grade and hours variable each loop
		grade = 0;
		hours = 0;

		//input class name
		cout << "Class name  (Don't use spaces): " << endl;
		cin >> className;
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
		while ((grade != 'A')&&(grade != 'B')&&(grade != 'C')&&(grade != 'D')&&(grade != 'F')&&(grade != 'W')&&(grade != 'I'))
		{
			//input grade
			cout << "Grade: " << endl;
			cin >> grade;
			cout << "\n";
		}
		
		//Determines the correct weight and total hours based on grade
		if (grade == 'A'){
			weightedHours = 4*hours;
			totalHours = totalHours + hours;
		}else if (grade == 'B'){
			weightedHours = 3*hours;
			totalHours = totalHours + hours;
		}else if (grade == 'C'){
			weightedHours = 2*hours;
			totalHours = totalHours + hours;
		}else if (grade == 'D'){
			weightedHours = hours;
			totalHours = totalHours + hours;
		}else if (grade == 'F'){
			weightedHours = 0;
			totalHours = totalHours + hours;
		}else{
			weightedHours = 0;
			totalHours = totalHours;
		}

		//Adds up the total weighted hours
		totalWeightedHours = totalWeightedHours + weightedHours;
		//Add one to the count variable to continue the loop
		count ++;

	}

	//Display final results
	cout << "totalHours: " << totalHours << endl;
	cout << "totalWeightedHours: " << totalWeightedHours << endl;
	GPA = totalWeightedHours/totalHours;
	cout << "Your final GPA is: " << GPA << endl; 

	return 0;
}

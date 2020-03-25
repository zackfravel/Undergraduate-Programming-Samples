
#include <iostream>
using namespace std;
int main()
{
   // Get number from user
   int input = 0;
   cout << "Enter a number:\n";
   cin >> input;

   // Print some numbers
   cout << "Here are some odd numbers:\n";
   int number1 = 1;
   while (number1 <= input)
   {
      cout << number1 << endl;
      number1 = number1 + 2;
   }
   // Print some numbers
   cout << "Here are some even numbers:\n";
   int number2 = 0;
   while (number2 <= input)
   {
      cout << number2 << endl;
      number2 = number2 + 2;
   }
   return 0;
}

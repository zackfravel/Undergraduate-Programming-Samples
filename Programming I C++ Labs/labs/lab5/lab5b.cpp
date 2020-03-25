#include <iostream>
using namespace std;
int main()
{
   // Get number from user
   int input = 0;
   cout << "Enter a number:\n";
   cin >> input;

   // Print numbers from [1..input]
   for (int num = 1; num <= input; num++)
      cout << num << " ";
   cout << endl;

   // Print EVEN numbers from [0..input-1] (FIX)
   for (int num2 = 0; num2 <= input; num2 += 2)
      cout << num2 << " ";
   cout << endl;

   // Print ODD numbers from [input..1] (FIX)
   if (input%2 == 0)
   {
	input -= 1;
   }
   for (int num3 = input; num3 >= 1; num3 -=2)
      cout << num3 << " ";
   cout << endl;

   return 0 ;
}

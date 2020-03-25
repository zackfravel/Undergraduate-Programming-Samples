#include <iostream>
using namespace std;
int main()
{
   int num = 0;

   cout << "Enter a positive even number:\n";
   cin >> num;
   while (num%2 == 1 || num <= 0)
   {
      cout << "Enter a positive even number:\n";
      cin >> num;
   }
   cout << "num = " << num << endl;
   return 0;
}


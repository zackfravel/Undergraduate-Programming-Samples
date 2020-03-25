#include <iostream>
#include <string>
using namespace std;

// your code for swap function goes here:
void mySwap(int &a, int &b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}


int main()
{
   int x,y;
   int a[] = {0,1,2,3,4,5,6,7,8,9};
   x = 3;
   y = 7;
  
   // current values of our variables
   cout << "x = " << x << endl;
   cout << "y = " << y << endl;
   for (int i = 0; i<10; i++)
      cout << "a[" << i << "] = " << a[i] << endl;

   mySwap(x,y);
   mySwap(a[0], a[9]);

   // current values after the above swap
   cout << "x = " << x << endl;
   cout << "y = " << y << endl;
   for (int i = 0; i<10; i++)
      cout << "a[" << i << "] = " << a[i] << endl;

   
   return 0;
}


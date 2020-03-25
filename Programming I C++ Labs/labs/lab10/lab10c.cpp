#include <iostream>
using namespace std;

// copy the swap function of lab10a
void mySwap(int &a, int &b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

// copy the smallest function of lab10b
int smallest(int a[], int left, int right) 
{
   // parameter a[] is the array to be searched
   // parameter left is the left index
   // parameter right is the right index
   // the function returns the index, where a[index] is the 
   // smallest value in a[left..right]
   if (left > right || left < 0 || right < 0)
	{
        // error cases and return -1
	cout << "error" << endl;
	return -1; 
	}
   // declare an integer variable called index and initialize it to left
   // a loop to iterate each index from left to right and if variable i
   // is used in the iteration we have
   int index = left;
   for(int i = index; i <= right; i++)
	{
   // if (a[index] > a[i]) index takes the value of i
	if (a[index] > a[i])
	   {
		index = i;
	   }
	}
   // return the value of index
   return index;
}

//Sorting Function
int sorting(int a[], int left, int right) 
{
   // parameter a[] is the array to be sorted
   // parameter left is the left index
   // parameter right is the right index
   // the function returns the index i, where a[i] is the 
   // smallest value in a[left..right]
   if (left > right || left < 0 || right < 0)
	{
        //error cases and return 1 for failure
	return -1;
	} 
   // use a loop to iterate each index from left to right 
   // and let i be the variable in the iteration
   for (int i = left; i <= right; i++)
	{
	mySwap(a[i], a[smallest(a,i,right)]);
	}

   return 0; //for success
}


// Program to test sorting function
//-----------------------------------------
int main()
{
   int a[] = {9,1,5,7,4,2,6,0,8,3};
  
   // test case one
   sorting(a, 1, 5);
   cout << " The value in A[1..5] is sorted nondecreasingly\n";
   for (int i = 0; i<10; i++)
      cout << "a[" << i << "] = " << a[i] << endl;

   // test case two
   sorting(a, 0, 9);
   cout << " The value in A[0..9] is sorted nondecreasingly\n";
   for (int i = 0; i<10; i++)
      cout << "a[" << i << "] = " << a[i] << endl;

   
   return 0;
}

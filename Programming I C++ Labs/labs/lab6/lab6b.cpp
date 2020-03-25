#include <iostream>
using namespace std;

int main()
{
   // Declare array of integers
   const int DATA_SIZE = 10;
   int data[DATA_SIZE];
   int seed = 37;
   int temp;

   // Initialize array
   for (int index = 0; index < DATA_SIZE; index++){
      data[index] = seed % 100;
      seed = seed + 37;
   }

   // Print array
   for (int index = 0; index < DATA_SIZE; index++)
      cout << data[index] << " ";
   cout << endl;

   // Reverse array
   for (int index = 0; index < DATA_SIZE/2; index++)
   {
      temp = data[index];
      data[index] = data[DATA_SIZE-1-index];
      data[DATA_SIZE-1-index] = temp;
   }

   // Print array
   for (int index = 0; index < DATA_SIZE; index++)
      cout << data[index] << " ";
   cout << endl;


   return 0 ;
}

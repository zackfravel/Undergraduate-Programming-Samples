#include <iostream>
using namespace std;

int main()
{
   // Declare array of integers
   const int DATA_SIZE = 20;
   int data[DATA_SIZE] = {0};
   int seed = 37;
   float mean;
   float variance; 

   // Print array
   for (int index = 0; index < DATA_SIZE; index++)
      cout << data[index] << " ";
   cout << endl;

   // Initialize array
   for (int index = 0; index < DATA_SIZE; index++){
      data[index] = seed % 100;
      seed = seed + 37;
   }

   // Print array
   for (int index = 0; index < DATA_SIZE; index++)
      cout << data[index] << " ";
   cout << endl;

   // Mean loop
   for (int index = 0; index < DATA_SIZE; index ++){
      mean = mean + data[index];
   }

   // Calculate and Display Mean
   mean = mean / DATA_SIZE;
   cout << "Mean = " << mean << " ";
   cout << endl;

   // Variance loop
   for (int index = 0; index < DATA_SIZE; index++){
      variance = variance + ((data[index]-mean)*(data[index]-mean));
   }

   // Calculate and Display Variance
   variance = variance / DATA_SIZE;
   cout << "Variance = " << variance << " ";
   cout << endl;

   // Reverse array

   return 0 ;
}

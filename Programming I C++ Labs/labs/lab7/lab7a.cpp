// Include statements
#include <iostream>
//#include <cstdlib>
using namespace std;

// Main function
int main()
{
   const int SIZE = 80;
   char greeting[SIZE] = "Dear ";
   char name[SIZE] = "Mom";
   char alphabet[SIZE] = "abcedfghijklmnopqrstuvwxyz";
   char alphabet_upper[SIZE];
   int index;
   int len;

   cout << "The value of c-string variable greeting is: " << greeting << endl;
   cout << "The value of c-string variable name is: " << name << endl;
   cout << "The value of c-string variable alphabet is: " << alphabet << endl;
   cout << endl;

   // assignment test in step 3
   // name = greeting;

   // finding out number of characters in a string
   index = 0;
   while (greeting[index] != '\0')
      index = index + 1;
   len = index;

   cout << "length: " << len << endl;
   cout << " " << endl; 

   // to have the effect of assignment we have to copy each individual elements
   for (int i = 0; i <= len; i++) 
      name[i] = greeting[i];
   

   cout << "After assigning greeting to name by each element via loop:\n";
   cout << "The value of c-string variable greeting is: " << greeting << endl;
   cout << "The value of c-string variable name is: " << name << endl;
   cout << endl;


   // figuring out the constant between upper and lower case
   int offset;
   offset = 'A' - 'a';


   // to upper
   index = 0;
   while (alphabet[index] != '\0' ){
      alphabet_upper[index] = alphabet[index] + offset;
      index = index + 1;
   }
   alphabet_upper[index] = '\0';

   cout << "The value of alphabet_upper is: " << alphabet_upper << endl;
   cout << "The value of alphabet is: " << alphabet << endl;
   cout << endl;


   // forget copying ending null character '\0' in copying
   len = 0;
   while (greeting[len] != '\0')
      len = len + 1;
   for (int i = 0; i < len; i++) 
      alphabet[i] = greeting[i];

   cout << "The value of alphabet is: " << alphabet << endl;
   
   return 0;
}

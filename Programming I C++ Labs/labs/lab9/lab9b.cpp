#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
   ofstream outfile;
   if (outfile.fail())
	{
  	 cout << "Error: could not open output file\n";
  	 exit (EXIT_FAILURE);
	}
   // Loop printing phrase
   string phrase = "A quick brown fox jumps over the lazy dog.";
   for (int i = 0; i < 10; i++)
      outfile << phrase << endl;
   // Open "words.txt" file here
   outfile.open("words.txt");
   string word;
   while (infile >> word)
      cout << word << " ";
   cout << endl;
   // Close "words.txt" file here
   outfile.close();
   return 0;
}

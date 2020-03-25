#include <iostream>
using namespace std;

char GetConcert()
{
   char Concert = ' ';
   while (!(Concert == 'B')&&!(Concert == 'L')&&!(Concert == 'T'))
	{
 	  cout << "The following concerts are available:\n";
   	  cout << "     B for Beyonce\n";
   	  cout << "     L for Lady Gaga\n";
   	  cout << "     T for Taylor Swift\n";
   	  cout << "Enter the letter for the concert you want:\n";
	  cin >> Concert;
	}
   return Concert;
}

int GetNumTickets()
{
   int NumTickets;
   cout << "Enter the number of tickets you want:\n";
   cin >> NumTickets;
   while ((NumTickets < 0) || (NumTickets > 10))
   {
      if (NumTickets < 0)
         cout << "You can not sell tickets here.\n";
      else if (NumTickets > 10)
         cout << "You may not purchase more than 10 tickets.\n";
      cout << "Enter the number of tickets you want:\n";
      cin >> NumTickets;
   }
   return NumTickets;
}

int main()
{
   // Declare variables 
   char Concert;
   int NumTickets;
   // Call function to find out the concert they want to attend
   Concert = GetConcert();
   // Call function to find out how many tickets they want
   NumTickets = GetNumTickets();
   // Print out the information you have collected.
   cout << "\nThe customer has placed the following order:\n";
   cout << "Concert: " << Concert << endl;
   cout << "Number of Tickets: " << NumTickets << endl;
   return 0;
}

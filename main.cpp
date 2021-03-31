#include <iostream>
#include <iomanip>
#include <list>
#include "data.h"


using namespace std;

int main()
{
	cout << endl;

	int ch;
	char dec, cdec;
	functions caller;

	//converts text data into linked list
	caller.FromTextToList();
	caller.FromTexttoQueue();

	do
	{//start do

	  //Determine the OS at Runtime
	  #if __APPLE__
	  	    system("clear");
	  	#elif _WIN32
	  	    system("cls");
	  	#elif __LINUX__
	  	    system("clear");
	  	#else
	  	    continue;
	  	#endif

	  //Menu and input
	  cout << "[1]New Video\n[2]Rent a Video\n[3]Return a Video\n[4]Show Video Details\n[5]Display All Videos\n[6]Check Movie Availability\n[7]Customer Maintenance\n[8]Exit Program\n\nEnter Choice: ";
	  cin >> ch;

	  //options
	  switch(ch)
	  {
	    case 1: //new video
	    	caller.AddMovie();
	    break;

	    case 2: //rent a video
	    	caller.RentMovie();
	    break;

	    case 3: //return a video
	    	caller.ReturnMovie();
	    break;

	    case 4: //Show video details
	    	caller.displaymovieinfo();
	    break;

	    case 5: //Display all videos
	    	caller.display();
	    break;

	    case 6: // Check video availability
	    	caller.avail();
	    break;

	    case 7: //Customer maintenance
			cout << "[1]Add a Customer\n[2]Customer List\n[3]Videos rented by Customer\nSelect an option: ";
			cin >> cdec;

			switch(cdec)
			{
				case 1: //add a customer
				caller.AddCustomer();
				break;

				case 2: // Display List

				break;

				case 3: // Videos rented by customer

				break;

				default: // error

				break;
			}
	    break;

	    case 8:
	    //call destructor
	    return 0;
	    break;

	    default:
	    	cout<< "Invalid input. Please try again.\n";
		break;
	  }

	//try again logic
	cout << "Do you want to select another choice?[Y/N]: ";
	cin >> dec;
	}while(caller.decision(dec));

  return 0;
}

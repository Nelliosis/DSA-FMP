#include <iostream>
#include <iomanip>
#include <list>
#include "data.h"


using namespace std;

int main()
{
cout << endl;

int ch;
char dec;
functions caller;

//converts text data into linked list
caller.FromTextToList();

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
    break;

    case 2: //rent a video
    break;

    case 3: //return a video
    break;

    case 4: //Show video details
    	caller.displaymovieinfo();
    break;

    case 5: //Display all videos
    	caller.display();
    break;

    case 6: // Check video availability
    break;

    case 7: //Customer maintenance
    break;

    case 8:
    //call destructor
    return 0;
    break;
  }

//try again logic
cout << "Do you want to select another choice?[Y/N]: ";
cin >> dec;
}while(caller.decision(dec));

  return 0;
}

// cout << "debuginator" << endl;

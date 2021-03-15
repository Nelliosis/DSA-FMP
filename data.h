#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct MovieNode
{
  int
        id,
        copies;

  std::string
        title,
        genre,
        prod,
        location;
};


MovieNode node;
list<MovieNode> MovieList;
list<MovieNode>::iterator iter;

class functions
{

public:

  bool decision(char);
  void displaymovieinfo();
  void display();
  void imagehandler(string n);
  void FromTextToList();
};

//Function Definitions

bool functions::decision(char d)
{
  if(d == 'y' || d == 'Y')
  return true;
  else
  return false;
}

void functions::displaymovieinfo()
{

	cout<< "<<MOVIE INFO>>\n";
	cout<< "Enter Movie ID: ";
	cout<< "\n\n";                //proxy endline to simulate entered Movie ID

	//call search function here

	cout<< "Video ID" << setw(13) << ": " << endl;
	cout<< "Movie Title" << setw(10) << ": " << endl;
	cout<< "Genre" << setw(16) << ": " << endl;
	cout<< "Production" << setw(11) << ": " << endl;
	cout<< "Number of Copies" << setw(5) << ": " << endl;
	imagehandler(filename);
}

void functions::imagehandler(string n)
{
  //call location based on environment variable
  #if _WIN32
	   string cmd("start C:\\Users\\%USERNAME%\\Documents\\github\\DSA-FMP\\ImageGlass_8.0.12.8_x64\\ImageGlass.exe ");
	   cmd += n; //concatenate location and app based on Windows
    #elif __APPLE__
      string terminal("open /System/Applications/Preview.app ");
      terminal += n; //concatenate location and app based on macOS
    #elif __LINUX__
      string terminal("open /System/Applications/Preview.app ");
      terminal += n; //concatenate location and app based on macOS
    #else
        continue;
    #endif

  //To properly utilize rename file directory of image to be displayed
	#if __APPLE__
  	   system(terminal.c_str());
  	#elif _WIN32
  		  system(cmd.c_str());
	  #elif __LINUX__
  	    system("open /System/Applications/Preview.app /Users/chikashoki/Documents/GitHub/Hello-Git/sched.png");
  	#else
  	    continue;
  	#endif
}

void functions::display()
{
	//initializes column width
	int colwidth = 20;

	//displays headers of table
	cout<< "<<MOVIE LIST>> \n \n";
	cout<< left << setw(colwidth) << "Video ID"
	<< left << setw(colwidth) << "Movie Title"
	<< left << setw(colwidth) << "Genre"
	<< left << setw(colwidth) << "Production"
	<< left << setw(colwidth) << "Copies\n";

	//for loop for displaying (di ko pa sure pano mamodify to kasi wala pang data initialized)
				/*for (int i=0; i < 10; i++){
					cout << setw(colwidth) << emp[i].num;
					cout << setw(colwidth) << emp[i].pos;
					cout << setw(colwidth) << emp[i].dept;
					cout << setw(colwidth) << emp[i].pr_date;
					cout << setw(colwidth) << emp[i].net <<"\n";
				}*/
				cout << endl;
}

void functions::FromTextToList()
{

string line;

//determines path at runtime
  #if _WIN32
  ifstream myfile("C:\\Users\\%USERNAME%\\Documents\\github\\DSA-FMP\\MovieList.txt");
  #else
  ifstream myfile("/Users/chikashoki/Documents/GitHub/DSA-FMP/MovieList.txt");
  #endif

//while file is open, traverse by line
    if (myfile.is_open())
    {
      int count = 0;
      while ( getline (myfile,line) )
      {
        //count determines which line getfile is at the current node
        switch(count)
        {
          case 0:
            node.id = stoi(line);
            break;
          case 1:
            node.title = line;
            break;
          case 2:
          node.genre = line;
            break;
          case 3:
          node.prod = line;
            break;
          case 4:
          node.copies = stoi(line);
            break;
          case 5:
          //add location
            break;
          default:
            break;
        }

        //if within the bounds of the node, continue adding
        if(count < 5)
        {
          count++;
        }
        //once reached the end of the node, reset count to 0 and push node into list
        else
        {
          count = 0;
          MovieList.push_back(node);
        }

      }
      myfile.close();

    }

    else cout << "Unable to open file" << endl;
//end of text to list function
}

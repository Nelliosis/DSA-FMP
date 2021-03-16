#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>

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
  void traversedisplay(int i);
  void FromTextToList();
  int searchmov(int n);

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

	int s;
	cout<< "<<MOVIE INFO>>\n";
	cout<< "Enter Movie ID: ";
	cin>> s;
	if(!searchmov(s))
	{
		cout<< "Sorry, the movie you are searching for does not exist." << endl;
	}
}

void functions::imagehandler(string n)
{
  //call location based on environment variable
  #if _WIN32
	   string cmd("start C:\\Users\\marbe\\Documents\\github\\DSA-FMP\\ImageGlass_8.0.12.8_x64\\ImageGlass.exe ");
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
	int colwidth = 40;

	//displays headers of table
	cout<< "<<MOVIE LIST>>\n";
	cout<< left << setw(colwidth) << "Video ID"
	<< left << setw(colwidth) << "Movie Title"
	<< left << setw(colwidth) << "Genre"
	<< left << setw(colwidth) << "Production"
	<< left << setw(colwidth) << "Copies\n";
	traversedisplay(colwidth);
	cout << "\n\n";
}


void functions::FromTextToList()
{

string line;

//determines path at runtime
  #if _WIN32
  ifstream myfile("C:\\Users\\marbe\\Documents\\github\\DSA-FMP\\MovieList.txt");
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

void functions::traversedisplay(int i)
{
    for(iter = MovieList.begin(); iter != MovieList.end(); iter++)
    {
        cout << endl;
        cout << setw(i) << iter->id;
        cout << setw(i) << iter->title;
        cout << setw(i) << iter->genre;
        cout << setw(i) << iter->prod;
        cout << setw(i) << iter->copies;

    }
}

int functions::searchmov(int n)
{
	int found = 0;
	for(iter = MovieList.begin(); iter != MovieList.end(); iter++)
    {
        if (iter->id == n)
        {
        	cout<< "Video ID" << setw(13) << ": " << iter->id << endl;
			cout<< "Movie Title" << setw(10) << ": " << iter->title << endl;
			cout<< "Genre" << setw(16) << ": " << iter->genre << endl;
			cout<< "Production" << setw(11) << ": " << iter->prod << endl;
			cout<< "Number of Copies" << setw(5) << ": " << iter->copies << endl;
			imagehandler(node.location);
        	found = 1;
		}
		
		else
		{
			continue;
		}
		
		return found;
    }
}

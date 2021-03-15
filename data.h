#include <iostream>
#include <string>
#include <iomanip>

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
  void traverse(int i);

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
	string filename = "C:\\Users\\marbe\\Desktop\\graphics.h_test\\1.jpg";
	
	cout<< "Video ID" << setw(13) << ": " << endl;
	cout<< "Movie Title" << setw(10) << ": " << endl;
	cout<< "Genre" << setw(16) << ": " << endl;
	cout<< "Production" << setw(11) << ": " << endl;
	cout<< "Number of Copies" << setw(5) << ": " << endl;
	imagehandler(filename);
}
	
void functions::imagehandler(string n)
{
	//For Windows
	string cmd1("start C:\\Users\\marbe\\Desktop\\graphics.h_test\\ImageGlass_8.0.12.8_x64\\ImageGlass.exe ");
	cmd1 += n;
	
	//Determine the OS at Runtime
  	//To properly utilize rename file directory of image to be displayed
	#if __APPLE__
  	   system("open /System/Applications/Preview.app /Users/chikashoki/Documents/GitHub/Hello-Git/sched.png");
  	#elif _WIN32
  		  system(cmd1.c_str());
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
	traverse(colwidth);
	
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

void functions::traverse(int i)
{
    for(iter = MovieList.begin(); iter != MovieList.end(); iter++)
    {
        cout << setw(i) << iter->id << endl;
        cout << setw(i) << iter->copies << endl;
        cout << setw(i) << iter->title << endl;
        cout << setw(i) << iter->genre << endl;
        cout << setw(i) << iter->prod << endl;
        cout << endl;
    }
}

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
        prod;

  //file pic
};

class functions
{

public:

  bool decision(char);
  void display();

};

//Function Definitions

bool functions::decision(char d)
{
  if(d == 'y' || d == 'Y')
  return true;
  else
  return false;
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

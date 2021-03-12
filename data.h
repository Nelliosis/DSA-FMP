#include <string>


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

  bool desicion(char);

};

//Function Definitions

bool functions::desicion(char d)
{
  if(d == 'y' || d == 'Y')
  return true;
  else
  return false;
}

#include <string> 
using namespace std; 
class Date
{
     
public:
       Date();
       Date(const int m, const int d, const int y);
       int GetMonth();
       int GetDay(); 
       int GetYear(); 
       void SetDate(const int m, const int d, const int y); 
       void SetTime(const int h, const int d, const char AMPM); 
       string & GetTime(); 
       string & GetShortDate(); 
       string & GetLongDate(); 
private:
       int intdate;
       int inttime; 
       string shortd;
       string longd;
       string time;
} ; 

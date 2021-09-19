#include "LfuCache.hpp"

int main()
{
    LfuCache a(4);

    a.find_and_add("AA");
    a.find_and_add("HH");
    a.find_and_add("CC");

    cout<<a;
    cout<<endl;

    a.find_and_add("AA");
    a.find_and_add("AA");
    a.find_and_add("CC");
    
    cout<<a;
    
    cout<<"\n";
    a.find_and_add("BB");
    a.find_and_add("BC");
    
    cout<<a;
    
    
    cout<<endl;



    return 0;
}


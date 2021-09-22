#include "LfuCache.hpp"

#include "Point.hpp"

int main()
{
    LfuCache<string> a(4);

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

    LfuCache<double> b(4);

    b.find_and_add(1.1);
    b.find_and_add(1.2);
    b.find_and_add(1.3);

    cout<<b;
    cout<<endl;

    b.find_and_add(1.4);
    b.find_and_add(1.1);
    b.find_and_add(1.3);
    
    cout<<b;
    
    cout<<"\n";
    b.find_and_add(1.4);
    b.find_and_add(1.5);
    
    cout<<b;
    
    
    cout<<endl;

    
    LfuCache<Point> c(3);

    Point d(1,1,1);
    Point v(2,2,2);
    Point e(3,3,3);
    Point g(4,4,4);
    
    c.find_and_add(d);
    c.find_and_add(v);
    c.find_and_add(d);
    c.find_and_add(e);
    cout<<c;
    cout<<endl;

    c.find_and_add(e);
    c.find_and_add(e);
    c.find_and_add(g);
    
    cout<<c;
    
    cout<<"\n";
    


    return 0;
}

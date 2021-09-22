

#ifndef LfuCache_hpp
#define LfuCache_hpp

#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <queue>
#include <vector>



using namespace std;

class LfuCache
{
private:
    size_t size;
    size_t count;
    map <string, int> My_map ;
    multimap <int,string> My_mmap;
public:
  
    LfuCache(size_t size1);
    
    ~LfuCache();
    
    int find_minimum();
    
    void del_lu();
    
    void del(const string &address, int key);
    
    bool find_and_add(const string &address);
    
    friend std::ostream& operator << (std::ostream& os, LfuCache & a);
};



#endif /* LfuCache_hpp */

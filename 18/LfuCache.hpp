

#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <queue>
#include <vector>


using namespace std;
template <typename T>
class LfuCache
{
private:
    size_t size;
    size_t count;
    map <T,int> My_map ;
    multimap <int,T> My_mmap;
public:
    LfuCache (size_t size1)
    {
         size = size1;
         count = 0;
        
    }

   ~LfuCache()
    {
        My_map.clear();
        My_mmap.clear();
    }


    void del_lu()
    {
        auto res1 = My_mmap.begin();
        
        typedef typename multimap<int, T>::iterator iterator;
        
        std::pair<iterator, iterator> iterpair = My_mmap.equal_range(res1->first);
        
        iterator it = iterpair.first;
        
        for (; it != iterpair.second; ++it) {
           
            if (it->second == res1->second) {
                My_mmap.erase(it);
                break;
            }
        }
    }

    void del(const T& address, int key)
    {
        typedef typename multimap<int, T>::iterator iterator;

        std::pair<iterator, iterator> iterpair = My_mmap.equal_range(key);

        iterator it = iterpair.first;

        for (; it != iterpair.second; ++it) {
           
            if (it->second == address) {
                My_mmap.erase(it);
                break;
            }
        }
    }

    bool find_and_add(const T& address)
    {
        auto result = My_map.find(address);
        
        if (result == My_map.end())
        {
            if (count < size)
            {
                My_map.insert (pair<T,int>(address, 1));
                My_mmap.insert(pair<int,T>(1,address));
                count++;
            }
            else
            {
                auto res1 = My_mmap.begin();
                My_map.erase(res1->second);
                del_lu();
                My_map.insert (pair<T,int>(address, 1));
                My_mmap.insert(pair<int,T>(1, address));
            }
            return false;
        }
        else
        {
            del(address,My_map[address]);
            My_map[address] += 1;
            My_mmap.insert(pair<int,T>(My_map[address], address));
        }
        return true;
    }



     friend std::ostream& operator << (std::ostream& os, LfuCache<T> &a )
    {
        for (auto it = a.My_map.begin(); it != a.My_map.end(); ++it)
                os <<  it->first << " : " << it->second << endl;
        return os;
    }

};
   

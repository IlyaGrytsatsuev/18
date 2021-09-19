
#include "LfuCache.hpp"

using namespace std;

    LfuCache::LfuCache(size_t size1)
    {
         size = size1;
         count = 0;
    }

    LfuCache::~LfuCache()
    {
        My_map.clear();
        My_mmap.clear();
    }


    void LfuCache:: del_lu()
    {
        auto res1 = My_mmap.begin();
        
        typedef multimap<int, string>::iterator iterator;
        
        std::pair<iterator, iterator> iterpair = My_mmap.equal_range(res1->first);
        
        iterator it = iterpair.first;
        
        for (; it != iterpair.second; ++it) {
           
            if (it->second == res1->second) {
                My_mmap.erase(it);
                break;
            }
        }
    }

    void LfuCache:: del(const string &address, int key)
    {
        typedef multimap<int, string>::iterator iterator;

        std::pair<iterator, iterator> iterpair = My_mmap.equal_range(key);

        iterator it = iterpair.first;

        for (; it != iterpair.second; ++it) {
           
            if (it->second == address) {
                My_mmap.erase(it);
                break;
            }
        }
    }

    bool LfuCache::find_and_add(const string &address)
    {
        auto result = My_map.find(address);
        
        if (result == My_map.end())
        {
            if (count < size)
            {
                My_map.insert (pair<string,int>(address, 1));
                My_mmap.insert(pair<int,string>(1,address));
                min = 1;
                count++;
            }
            else
            {
                auto res1 = My_mmap.begin();
                My_map.erase(res1->second);
                del_lu();
                My_map.insert (pair<string,int>(address, 1));
                My_mmap.insert(pair<int,string>(1, address));
            }
            return false;
        }
        else
        {
            del(address,My_map[address]);
            My_map[address] += 1;
            My_mmap.insert(pair<int,string>(My_map[address], address));
           // min = find_minimum();
        }
        return true;
    }



    std::ostream& operator << (std::ostream& os, LfuCache &a )
    {
        for (auto it = a.My_map.begin(); it != a.My_map.end(); ++it)
                os <<  it->first << " : " << it->second << endl;
        return os;
    }



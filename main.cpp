#include <iostream>
#include <map>

using namespace std;

int main()
{
    multimap<int,int> mmap;
    multimap<int,int> mmap_buffer;
    multimap<int,int> mmap_copy;

    mmap.insert(pair<int,int>(1,2));
    mmap.insert(pair<int,int>(10,15));
    mmap.insert(pair<int,int>(1,2));
    mmap.insert(pair<int,int>(3,11));
    mmap.insert(pair<int,int>(10,15));
    mmap.insert(pair<int,int>(1,2));
    mmap.insert(pair<int,int>(1,3));
    mmap.insert(pair<int,int>(1,2));
    mmap.insert(pair<int,int>(2,2));
    mmap.insert(pair<int,int>(2,3));
    mmap.insert(pair<int,int>(3,11));
    mmap.insert(pair<int,int>(1,2));
    mmap.insert(pair<int,int>(1,2));
    mmap.insert(pair<int,int>(2,2));
    mmap.insert(pair<int,int>(2,3));
    mmap.insert(pair<int,int>(3,11));


    mmap_buffer.insert(pair<int,int>(0,0));
    //mmap_copy.insert(pair<int,int>(0,0));

    multimap<int,int>::iterator it = mmap.begin();
    multimap<int,int>::iterator it_buffer = mmap_buffer.begin();
    multimap<int,int>::iterator it_copy = mmap_copy.begin();

    cout << "**************Исходный multimap**************" << endl;

    for(;it != mmap.end();it++){
        cout << '[' << it->first << ']' << ':' << '[' << it->second << ']' << endl;
    }

    it = mmap.begin();
    int tmp = 0;

    for(;it != mmap.end();it++){
        if(it->first == it_buffer->first && it->second == it_buffer->second){
        }else{
            mmap_buffer.clear();
            mmap_buffer.insert(pair<int,int>(it->first, it->second));
            for(it_copy = mmap_copy.begin();it_copy != mmap_copy.end();it_copy++){
                if(it->first == it_copy->first && it->second == it_copy->second){
                    tmp++;
                }
            }
            if(tmp == 0)
                mmap_copy.insert(pair<int,int>(it->first, it->second));
        }
        tmp = 0;
    }

    it_copy = mmap_copy.begin();

    cout << "**************multimap без повторений**************" << endl;

    for(;it_copy != mmap_copy.end();it_copy++){
        cout << '[' << it_copy->first << ']' << ':' << '[' << it_copy->second << ']' << endl;
    }

    return 0;
}

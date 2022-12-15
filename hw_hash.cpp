#include <iostream>
#include <string>
#include <forward_list>
#include <utility>
#include <iterator>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;
//used professor Kevin Wortman's lecture as reference 

class hashtable{
public:
    vector<forward_list<int> > v_; //chained hashtable is used in this homeowork
    
    
    unsigned int code(unsigned int Key){
        return Key;
    }
    size_t h(unsigned int code){
        int prime_num = 2^63 - 1; // for 64_unit, a prime number greater than size of vector
        int rand_num1 = rand()%(prime_num-1) + 1; //1~p-1
        int rand_num2 = rand()%prime_num; //0~p-1
        int ret =  ((rand_num1*code + rand_num2)% prime_num )%v_.size();
        return ret;
    }
    size_t hash(int Key){
        return h(code(Key)); // return an index from the Key
    }

    hashtable():v_(22){} // need declare the capacity of the vector
  

    void insert(int element)
    {
        int i = hash(element);
        v_[i].push_front(element);
    }

    void printHash()
    {
        for(int i = 0; i< 22; i++)
        {
            for(auto input_in_v: v_[i])
            {
                cout << input_in_v << ' ';
            }
            cout << endl;
        }
    }
};



int main()
{
    cout << "no collision" << endl;
    hashtable h;
   int v1[] = {2, 18, 3, 4, 3, 7, 11, 12, 13, 14, 15, 16};
   for(int i = 0; i< 11; i++)
    {
        h.insert(v1[i]);
    }
    h.printHash();
    cout << "with collision" << endl;
    hashtable h2;
    int v2[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    for(int i = 0; i< 11; i++)
    {
        h2.insert(v2[i]);
    }
    h2.printHash();
}

#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <array>
#include <algorithm>


template <typename C>
void print_contents(const C& c){
        for (auto& a : c)
                std::cout << a << ' ';
        std::cout << std::endl;
}


template<typename C>
void inc(C& c, int n){
        for(auto& a : c);
}


template<typename Iter1, typename Iter2>
Iter2 orai_copy(Iter1 f1, Iter1 e1, Iter2 f2){
        for(Iter1 p = f1; p != e1; ++p){
                *f2 = *p;
                f2++;
        }
        return f2;
}




using namespace std;


int main(){
try{    
        /*
        int[] array (0,1,2,3,4,5,6,7,8,9);
        vector<int> vec(0,1,2,3,4,5,6,7,8,9);
        list<int> list= {0,1,2,3,4,5,6,7,8,9};
        */
            
        constexpr int size = 10;
        int arr[size];
        for(int i = 0; i < size; ++i) arr[i] = i;
        print_contents(arr);
        
        std::array<int, size > ai;
        std::copy(arr, arr +size, ai.begin());
        print_contents(ai);
        
        std::vector<int> vi(size);
        std::copy(arr, arr + size, vi.begin());
        print_contents(vi);
        
        std::list<int> li(size);
        std::copy(arr, arr + size, li.begin());
        print_contents(li);
        
        
        std::array<int, size> ai2 = ai;
        std::vector<int> vi2 = vi;
        std::list<int> li2 = li;
        
        print_contents(ai2);
        print_contents(vi2);
        print_contents(li2);
        
        
        inc(ai2, 2);
        inc(vi2, 3);
        inc(li2, 5);
        
        print_contents(ai2);
        print_contents(vi2);
        print_contents(li2);
        
        
        orai_copy(ai2.begin(), ai2.end(), vi2.begin());
        orai_copy(li2.begin(), li2.end(), ai2.begin());
        
        print_contents(ai2);
        print_contents(vi2);
        print_contents(li2);
        
        
        vector<int>::iterator vit;
        vit = find(vi2.begin(), vi2.end(), 3);
        if(vit != vi2.end()){
            cout << "Found at:" << distance(vi2.begin(), vit) << endl;
        } else {
            cout << "Not found" << endl;
        } 
        

        //hf: lista tartalmazza e a 27-es értéket
        
        std::list<int>::iterator lit;
    lit = std::find(li2.begin(), li2.end(), 27);
    if (lit != li2.end())
        std::cout << "Found at: " << std::distance(li2.begin(), lit) << '\n';
    else
        std::cout << "Not found..\n";
        
        
}       catch (exception& e) {
                cerr << "exception: " << e.what() <<std::endl;
                return 1;
        } catch (...){
                cerr << "exception\n";
                return 2;
    }
}

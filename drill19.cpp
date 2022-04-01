#include <iostream>
#include <string>
#include <vector>

using namespace std;
template<typename T> struct S {
        public:
        S(T vv = 0) : val{vv}{}
        T& get();
        const T& get() const;
        void set(T newValue){
                val=newValue;
        }
        void operator=(const T&);
        
        private:
        T val;
};
        //nem constans
template<typename T>
T& S<T>::get(){
        return val;
}
        // constans
template<typename T>
const T& S<T>::get() const{
        return val;
}


template<typename T>
void S<T>::operator=(const T& s){
        val = s;
}

template<typename T> void read_val(T& v){
        cin >> v;
}





template<typename T>
ostream& operator<<(ostream& os, vector<T>& vt){ //ide kéne valami
        
    os << "{ ";
    for (int i = 0; i < vt.size(); ++i) {        
        os << vt[i] << (i < vt.size() - 1 ? ", " : " ");
    }
    os << "}\n";

    return os;
    // cout << vec1 << vec2 << vec3
};

template<typename T>
istream& operator>>(istream& is, vector<T>& vt){ //ide kéne valami
        char ch = 0;
        is >> ch;
        if (ch != '{') {
            is.unget();
            return is;
        }

        for (T val; is >> val; ) {
                vt.push_back(val);       //
                is >> ch;
                if (ch != ',') break;
        }

        return is;
};

int main(){

        S<int> s;
        S<int> si {37};
        S<int> sc {'c'};
        S<double> sd {3.2};
        S<std::string> ss {"hello"};
        S<vector<int>> svi {std::vector<int>{1, 1, 2, 3, 5, 8}};

       /* cout<< "S<int> : " << s.val <<endl
            << "S<int> : " << si.val <<endl
            << "S<char> : " << sc.val <<endl
            << "S<double> : " << sd.val <<endl
            << "S<string> : " << ss.val <<endl;
            //<< "S<vector<int>> : " << svi.val <<endl;
       */
       
         cout<< "S<int> : " << s.get() <<endl
            << "S<int> : " << si.get() <<endl
            << "S<char> : " << sc.get() <<endl
            << "S<double> : " << sd.get() <<endl
            << "S<string> : " << ss.get() <<endl;
            //<< "S<vector<int>> : " << svi.val <<endl;   


        for(auto a: svi.get()){
                cout<< a <<' ';
        }
        cout<<endl;

        sc.set('s');
        cout << "S<char> : " << sc.get() <<endl;

        si = 30;
        cout << "S<int> : " << si.get() <<endl;
        
        int ii;
        read_val(ii);
        S<int>si2{ii};
        
        double dd;
        read_val(dd);
        S<double>sd2{dd};
        
        string str;
        read_val(str);
        S<string>ss2{str};
        
        cout<< "S<int> :" << si2.get() <<endl;
        cout<< "S<double> :" << sd2.get() <<endl;
        cout<< "S<string> :" << ss2.get() <<endl;
        
        vector<int> vec;
        read_val(vec);  //vectorral nem mükszik
        S<vector<int>> svec(vec);
        
        cout << "S<vector<int>>: (format: {val, val, val})";
        
        vector<int> vec1;
        read_val(vec);
        S<vector<int>> svec1{vec};
        cout << "S<vector<int>> svec1 :" << svec.get() << endl;
        



}

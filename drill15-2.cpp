#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

class Person{
    public:
        Person(){}
        //Person(string n, int a ): n{n}, a{a}{
        Person(string f, string l, int a) : f{f}, l{l}, a{a}{
                if(a<0; a>=150){
                        throw runtime_error("Invalid age");
                }
                string n = f+l;
                for (char c : n)
                        switch(c) {
                                case ';': 
                                case ':': 
                                case '"': 
                                case '[': 
                                case ']': 
                                case '*':
                                case '&': 
                                case '^': 
                                case '%': 
                                case '$': 
                                case '#': 
                                case '@':
                                case '!': 
                                case '\'':
                            runtime_error("Invalid name");
                            break;
                        default:
                            break;
                        } 
                
        };
        //string name()const{return n;}
        string first() const{return f;}
        string last() const{return l;}
        int age()const{return a;}
    private:
        //string n;
        string f;
        string l;
        int a;
};

ostream& operator<< (ostream& os, const Person& p){
        os << p.first() << " " << p.last() << " " << p.age();
        return os;
}

istream& operator>> (istream& is, Person& p){
        //string n;
        string f;
        string l;
        int a;
        //is >> n >> a;
        is >> f >> l >> a;
        //p = Person(n, a);
        p = Person(f, l, a);
        return is;
}

int main(){
           Person p = Person("Goofy", "a", 63);
           //Person p;
           //p.n = "Goofy";
           //p.a = 63;
           //cout << p.name << " " << p.age << endl;
           cout << p.first() << " " << p.last() << " " << p.age
           () << endl;
           
           Person p2;
           cin >> p2;
           cout << p2 <<endl;
           
           vector<Person> vec;
           for(Person p; cin>>p;){ //while (cin>>p)
                    if(p.first() == "end") break;
                    vec.push_back(p);    
           }
           for(Person p: vec){
                cout << p << endl;
           }
}














#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main()
try{
    // 1.feladat
    
       cout << "sizeof:\n";
        cout << "char\t" << sizeof(char) << '\n';
        cout << "short\t" << sizeof(short) << '\n';
        cout << "int\t" << sizeof(int) << '\n';
        cout << "long\t" << sizeof(long) << '\n';
        cout << "float\t" << sizeof(float) << '\n';
        cout << "double\t" << sizeof(double) << '\n';
        cout << "int*\t" << sizeof(int*) << '\n';
        cout << "double*\t" << sizeof(double*) << '\n';
        cout << "float*\t" << sizeof(float*) << '\n';
        cout << "long*\t" << sizeof(long*) << '\n';
        
    //2.feladat
    
        Matrix<int> a(10);
        Matrix<int> b(100);
        Matrix<double> c(10);
        Matrix<int, 2> d(10, 10);
        Matrix<int, 3> e(10, 10,10);
        cout<< "\n1D int, 10 elements \t\t" << sizeof(a)<<'\n';
        cout<< "1D int, 100 elements \t\t" << sizeof(b)<<'\n';
        cout<< "1D double, 10 elements \t\t" << sizeof(c)<<'\n';
        cout<< "2D int, 10 elements \t\t" << sizeof(d)<<'\n';
        cout<< "3D int, 10 elements \t\t" << sizeof(e)<<'\n';
    
    // 3feladat
    
        cout << "\nNumber of elements:\n";
        cout << "a:\t"<< a.size() <<'\n';
        cout << "b:\t"<< b.size() <<'\n';
        cout << "c:\t"<< c.size() <<'\n';
        cout << "d:\t"<< d.size() <<'\n';
        cout << "e:\t"<< e.size() <<'\n';
        
    // 4.feladat
      
        for(int i; cin >> i;){
            
               if(i<0){
                    cout <<"no square root\n";
                    break;}
             	else
             	cout << "the root of " << i << " is:" << sqrt(i)<< '\n';
                    };
                
      /*
     	  int i;
        cout << "\nEnter ints\n";
        while(cin >> i){
            errno =0;
            if(errno == EDOM)
            cout << "no square root\n";
            else
                    cout << "sqrt("<< i <<") =" << d << '\n';
        }*/
     //5.feladat i think
     
        cin.clear();
        cin.ignore();
        cout << "\nEnter 10 floating point values:";
        Matrix<double> m2(10);
        double d2;
        for(int i=0; i<m2.size(); ++i){
                cin>>d2;
                if(!cin) throw runtime_error("Problem reading from cin.");
                m2[i] = d2;
        }
        cout << "Matrix: \n" << m2 << '\n';
        
    //6.feladat ezzel is csak a baj van
       
        cout << "\nMultiplication table\nEnter n:";
        int n;
        cin >> n;
        cout << "Enter m: ";
        int m3;
        cin >> m3;
        Matrix<int, 2> mtable(n, m3);
        
        for(int i=0; i<mtable.dim1(); ++i){
                for(int j=0; j< mtable.dim2(); ++j){
                    mtable(i, j) = (i + 1)* (j + 1);
                    cout<< setw(5) << mtable(i, j);
                }
                cout << '\n';
        }
        
     //7.feladat i hate it here
     
        Matrix<complex<double>> m4(10);
        cout << "\nEnter 10 complex numbers (re, im): ";
        complex<double>comp;
        for(int i=0; i < 10; ++i){
                cin >> comp;
                if(!cin) throw runtime_error("problem reading complex number!");
                m4[i] = comp;
        }
        cout << "comoplex matrix: " << m4 << '\n';
        complex<double> sum;
        for(Index i=0; i<m4.size(); ++i){
                sum+= m4[i];
        }
        cout << "sum: " << sum << '\n';
        
        //8.feladat(házi) just kill me pls 
        
        cout << "Enter 6 ints for a 2x3 Matrix:\n";
    	Matrix<int,2> mm (2,3);
    		for (int i = 0; i < mm.dim1(); ++i)
        		for (int j = 0; j < mm.dim2(); ++j)
            			cin >> mm[i][j];

        
        
        
}catch (exception& e) {
        cerr << "Expection: " << e.what() << '\n';
}catch (...){
        cerr << "Exception!\n";
}

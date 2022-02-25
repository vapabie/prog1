#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

/*
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill12.cpp `fltk-config --ldflags --use-images` -o a2.out

*/


using namespace Graph_lib;

int main(){

        try{
        
        Point t1 {100, 100};
        Simple_window win {t1, 600, 400, "My window"};
        win.wait_for_button();
        
        Axis xa {Axis::x, Point{20, 300}, 280, 10, "x axis"}; //x tengely
        win.attach(xa);
        
        win.set_label("X axis");
        win.wait_for_button();
        
        
        Axis ya {Axis::y, Point{20, 300}, 280, 10, "y axis"}; // y tengely
        ya.set_color(Color::cyan);
        ya.label.set_color(Color::dark_red);
        win.attach(ya);
        
        win.set_label("Y axis");
        win.wait_for_button();
        
        
        Function sine {sin, 0, 100, Point{20, 150}, 1000, 50, 50}; //sinus függvény
        win.attach(sine);
        win.set_label("Sine function");
        win.wait_for_button();
        
        
        Polygon poly; //háromszög itt
        poly.add(Point{300, 200});
        poly.add(Point{350, 100});
        poly.add(Point{400, 200});
        
        poly.set_color(Color::red);
        poly.set_style(Line_style::dash);
        win.attach(poly);
       
        win.set_label("Polygon");
        win.wait_for_button();
        
        
        Rectangle r{Point{200, 200}, 100, 50}; //téglalap
        win.attach(r);
        
        Closed_polyline poly_rect;
        
        poly_rect.add(Point{100, 50});
        poly_rect.add(Point{200, 50});
        poly_rect.add(Point{200, 100});
        poly_rect.add(Point{100, 100});
        poly_rect.add(Point{50, 75});
        win.attach(poly_rect);
        
        win.set_label("Rectangle");
        win.wait_for_button();
        
        
        r.set_fill_color(Color::yellow);
        poly_rect.set_style(Line_style(Line_style::dash, 2));
        poly_rect.set_fill_color(Color::green);
        
        win.set_label("Fill");
        win.wait_for_button();
        
        
        Text t{Point{150, 150}, "Hello, graphical world!"}; 
        win.attach(t);
        win.set_label("Text");
        win.wait_for_button();
        //hf font, méret megváltoztatása, kép berakása és elmozgatása h kilógjon az ablakból
    
    	t.set_font(Font::times_bold);
    	t.set_font_size(20);
    	win.set_label("Canvas#9");
    	win.wait_for_button();
    	
    	Image ii {Point{100,50}, "GUI/badge.jpg"};
    	win.attach(ii);
    	win.set_label("Canvas#10");
    	win.wait_for_button();
    	
    	ii.move(200,100);
    	win.set_label("Image moved");
    	win.wait_for_button();
        
        
        
        } catch (exception& e) {
                cerr << "exception: " << e.what() << '\n';
                return 1;
        } catch (...) {
                cerr << "error\n";
                return 2;
        };

}

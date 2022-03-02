#include "./GUI/Graph.h"
#include "./GUI/Simple_window.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){
    try {
        Point t1(300, 50);
        Simple_window win(t1, 1000, 800, "My window");
        win.wait_for_button();
        
        Lines grid;
        int x_size = 800;
        int y_size = 800;
        for(int i=100; i<=x_size; i+=100){
                grid.add(Point(i,0), Point(i, y_size));
                grid.add(Point(0, i), Point(x_size, i));
        }
        win.attach(grid);
        win.wait_for_button();
    
    /*házi 
   
        1; 200x200 kép, 3 szor elhelyezni a rácson 3 random helyre, nem is kell akorának lennie
        
    img,set_mask (Point(100, 100), 200, 200) /(hova rakom), mekorában
    
        2; 100x100 as kép, random helyekre kerüljön a next button nyomásakor
        move függvény Graph.h ban van benne
        while(true){} /végtelen ciklus
        
    */
    
    	Rectangle rect00 {Point{0,0},100,100};
	Rectangle rect11 {Point{100,100},100,100};
	Rectangle rect22 {Point{200,200},100,100};
	Rectangle rect33 {Point{300,300},100,100};
	Rectangle rect44 {Point{400,400},100,100};
	Rectangle rect55 {Point{500,500},100,100};
	Rectangle rect66 {Point{600,600},100,100};
	Rectangle rect77 {Point{700,700},100,100};
		
	rect00.set_fill_color(Color::red);
	rect11.set_fill_color(Color::red);
	rect22.set_fill_color(Color::red);
	rect33.set_fill_color(Color::red);
	rect44.set_fill_color(Color::red);
	rect55.set_fill_color(Color::red);
	rect66.set_fill_color(Color::red);
	rect77.set_fill_color(Color::red);
	
	win.attach(rect00);
	win.attach(rect11);
	win.attach(rect22);
	win.attach(rect33);
	win.attach(rect44);
	win.attach(rect55);
	win.attach(rect66);
	win.attach(rect77);
	
	win.wait_for_button();
    
    	Image badge1 {Point{0,200}, "GUI/badge.jpg"};
   	Image badge2 {Point{280,500}, "GUI/badge.jpg"};
    	Image badge3 {Point{500,100}, "GUI/badge.jpg"};
    	
    	badge1.set_mask(Point{0,200},200, 200);
    	badge2.set_mask(Point{0,200},200, 200);
    	badge3.set_mask(Point{0,200},200, 200);
    
    	win.attach(badge1);
    	win.attach(badge2);
    	win.attach(badge3);
    	win.wait_for_button();
    	
    	Image badge4 {Point{200, 100}, "GUI/badge.jpg"};
    	badge4.set_mask(Point{0,0},100, 100);
    	win.attach(badge4);
    	win.wait_for_button();
    	
    	int i = 1;
    	while(i<6){
    		badge4.move(100, 100);
    		i=i+1;
    	win.wait_for_button();	
    	}
    	badge4.move(-500, -700);
    	win.wait_for_button();
    	
    	
    } catch (exception& e) {
        cerr << "exceotion: " << e.what() <<endl;
        return 1;
    } catch (...){
        cerr << "exception\n";
            return 2;
    }
}

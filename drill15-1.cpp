#include <iostream>
#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main(){
    try {
        Point t1(100, 100);
        Simple_window win(t1, 600, 600, "Function graphs");
        win.wait_for_button();
        
        
        Axis x {Axis::x, Point{100, 300}, 400, 20, "1 == 20 pixels"};
        x.set_color(Color::red);
        win.attach(x);
        
    	Axis y {Axis::y, Point{300, 500}, 400, 20, "1 == 20 pixels"};
	y.set_color(Color::red);
	win.attach(y);

    	win.wait_for_button();
    	
    	constexpr int range_min = -10;
    	constexpr int range_max = 11;

    	constexpr int num_points = 400;

    	constexpr int x_scale = 20;
    	constexpr int y_scale = 20;

    	const Point orig {300, 300};
    	
	Function f1 {one, range_min, range_max, orig, num_points, x_scale, y_scale};
	win.attach(f1);    
	win.wait_for_button();
	
	Function f2 {slope, range_min, range_max, orig, num_points, x_scale, y_scale};
	win.attach(f2);
	 
	Text t{Point{100, 375}, "x/2"};
    	win.attach(t);
    	win.set_label("Text");
    	
	win.wait_for_button();
	
	Function f3 {[](double x) { return x * x; }, range_min, range_max, orig, num_points, x_scale, y_scale};
    	win.attach(f3);    
	win.wait_for_button();
	
	Function f4 {cos, range_min, range_max, orig, num_points, x_scale, y_scale};
    		f4.set_color(Color::blue);
    	win.attach(f4);
	win.wait_for_button();
    		
    	Function f5 {[](double x) { return cos(x) + slope(x); }, range_min, range_max, orig, num_points, x_scale, y_scale};
    	win.attach(f5);    
	win.wait_for_button();
    
        
        
        } catch (exception& e) {
                cerr << "exception: " << e.what() << '\n';
                return 1;
        } catch (...) {
                cerr << "error\n";
                return 2;
        };
        
        
        
}        


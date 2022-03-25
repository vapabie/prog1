#include"./GUI/Simple_window.h"
#include "./GUI/Graph.h"

struct Lines_window : Window {
	Lines_window(Point xy, int w, int h, const string& title);

private:
	Open_polyline lines;
	
	Button next_button;
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	Menu color_menu;
	Button cmenu_button;
	Menu style_menu;
	Button smenu_button;
	
	void change(Color c){
		lines.set_color(c);
	}
	void stylechange(Line_style l){ 
		lines.set_style(l);
	}
	void hide_cmenu(){
		color_menu.hide();
		cmenu_button.show();
	}
	void hide_smenu(){
		style_menu.hide();
		smenu_button.show();
	}
	void red_pressed(){
		change(Color::red);
		hide_cmenu();
		hide_smenu();
	}
	void blue_pressed(){
		change(Color::blue);
		hide_cmenu();hide_smenu();
	}
	void black_pressed(){
		change(Color::black); 
		hide_cmenu();hide_smenu();
	}
	void dash_pressed(){
		stylechange(Line_style::dash);
		hide_smenu();hide_cmenu();
	}
	void solid_pressed(){
		stylechange(Line_style::solid);
		hide_smenu();
		hide_cmenu();
	}
	void dot_pressed(){
		stylechange(Line_style::dot);
		hide_smenu();
		hide_cmenu();
	}
	void dashdot_pressed(){
		stylechange(Line_style::dashdot);
		hide_smenu();
		hide_cmenu();
	}
	void dashdotdot_pressed(){
		stylechange(Line_style::dashdotdot);
		hide_smenu();
		hide_cmenu();
	}
	void cmenu_pressed(){
		cmenu_button.hide();
		smenu_button.hide();
		color_menu.show();
	}
	void smenu_pressed(){
		smenu_button.hide();
		cmenu_button.hide();
		style_menu.show();
	}

	void next();
	void quit();


	static void cb_red(Address, Address); 
	static void cb_blue(Address, Address);
	static void cb_black(Address, Address);
	static void cb_dash(Address, Address);
	static void cb_solid(Address, Address);
	static void cb_dot(Address, Address);
	static void cb_dashdot(Address, Address);
	static void cb_dashdotdot(Address, Address);
	static void cb_cmenu(Address, Address);
	static void cb_smenu(Address, Address);
	static void cb_next(Address, Address);
	static void cb_quit(Address, Address);
};



Lines_window::Lines_window(Point xy, int w, int h, const string& title)
	:Window{xy,w,h,title},
	/*next_button{
		Point{x_max()-150,0}, 70, 20, "Next point",
		[](Address, Address pw)
		{reference_to<Lines_window>(pw).next();}
	},
	quit_button{
		Point{x_max()-70,0}, 70, 20, "Quit",
		[](Address, Address pw)
		{reference_to<Lines_window>(pw).quit();}
	},*/
	next_button{
		Point{x_max()-150,0}, 70, 20, "Next point", cb_next
	},
	quit_button{
		Point{x_max()-70,0}, 70, 20, "Quit", cb_quit
	}, 
	next_x{
		Point{x_max()- 310,0}, 50, 20, "next x:"
	},
	next_y{
		Point{x_max()-210,0}, 50, 20, "next y:"
	},
	xy_out{
		Point{100,0}, 100, 20, "current (x,y):"
	},
	color_menu{
		Point{x_max()-70,40},70,20,Menu::vertical,"color"
	},
	cmenu_button{
		Point{x_max()-80,30}, 80, 20, "color menu", cb_cmenu
	},
	style_menu{
		Point{x_max()-70,60},70, 20, Menu::vertical,"style"
	},
	smenu_button{
		Point{x_max()-80,60}, 80, 20, "style menu", cb_smenu
	}
		
		
{
attach(next_button);
attach(quit_button);
attach(next_x);
attach(next_y);
attach(xy_out);
attach(lines);

color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});

attach(color_menu);
color_menu.hide();
attach(cmenu_button);

style_menu.attach(new Button{Point{0,0},0,0,"dash",cb_dash});
style_menu.attach(new Button{Point{0,0},0,0,"solid",cb_solid});
style_menu.attach(new Button{Point{0,0},0,0,"dot",cb_dot});
style_menu.attach(new Button{Point{0,0},0,0,"dashdot",cb_dashdot});
style_menu.attach(new Button{Point{0,0},0,0,"dashdotdot",cb_dashdotdot});

attach(style_menu);
style_menu.hide();
attach(smenu_button);

attach(lines);
}


void Lines_window::cb_red(Address, Address pw){
    reference_to<Lines_window>(pw).red_pressed();
}
void Lines_window::cb_blue(Address, Address pw){
    reference_to<Lines_window>(pw).blue_pressed();
}
void Lines_window::cb_black(Address, Address pw){
    reference_to<Lines_window>(pw).black_pressed();
}
void Lines_window::cb_cmenu(Address, Address pw){
    reference_to<Lines_window>(pw).cmenu_pressed();
}

void Lines_window::cb_dash(Address, Address pw){
    reference_to<Lines_window>(pw).dash_pressed();
}
void Lines_window::cb_solid(Address, Address pw){
    reference_to<Lines_window>(pw).solid_pressed();
}
void Lines_window::cb_dot(Address, Address pw){
    reference_to<Lines_window>(pw).dot_pressed();
}
void Lines_window::cb_dashdot(Address, Address pw){
    reference_to<Lines_window>(pw).dashdot_pressed();
}
void Lines_window::cb_dashdotdot(Address, Address pw){
    reference_to<Lines_window>(pw).dashdotdot_pressed();
}
void Lines_window::cb_smenu(Address, Address pw){
    reference_to<Lines_window>(pw).smenu_pressed();
}

void Lines_window::cb_next(Address, Address pw){
    reference_to<Lines_window>(pw).next();
}
void Lines_window::cb_quit(Address, Address pw){
    reference_to<Lines_window>(pw).quit();
}


void Lines_window::quit(){
hide();
}

void Lines_window::next(){
	int x = next_x.get_int();
	int y = next_y.get_int();
	lines.add(Point{x,y});
	ostringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());
	redraw();
}

int main()
	try{
		Lines_window win {Point{100,100},600,400,"lines"};
		return gui_main();
	}

	catch(exception& e){
		cerr << "exception: " << e.what() << '\n';
		return 1;
	}
	catch (...){
		cerr << "Some exception\n";
		return 2;
	}

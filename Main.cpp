#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class ShapeLC
{
protected:
	string str;
	float x, y;
public:
	ShapeLC()
	{
		x = 0;
		y = 0;
	}
	virtual ~ShapeLC() {};
	virtual string to_String() = 0;
	virtual float Area() = 0;
	virtual void Draw() = 0;
	void Move(float move_x, float move_y)
	{
		x = move_x;
		y = move_y;
	}
};

class Triangle : public ShapeLC
{
private:
	float a, b, c, p, r, r_pixel;
public:
	Triangle() 
	{
		a = 0;
		b = 0;
		c = 0;
		p = 0;
		r = 0;
		r_pixel = 0;
	}
	Triangle(float a_p, float b_p, float c_p)
	{
		a = a_p;
		b = b_p;
		c = c_p;
		p = (a + b + c) / 2;
		r = (a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));
		r_pixel = r * 37.795275590551;
	}
	virtual ~Triangle() {};
	virtual float Area()
	{
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	virtual string to_String()
	{
		str += "Triangle info: ";
		str += "Side a: ";
		str += to_string(a);
		str += " Side b: ";
		str += to_string(b);
		str += " Side c: ";
		str += to_string(c);
		str += " Semi-perimeter: ";
		str += to_string(p);
		str += " Area: ";
		str += to_string(Area());
		str += "\n";
		return str;
	}
	virtual void Draw()
	{
		RenderWindow window(VideoMode(500, 200), "SFML Works!");
		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			window.clear(Color(250, 220, 100, 0));
			CircleShape triangle(r_pixel, 3);
			triangle.setPosition(x, y);
			triangle.setFillColor(Color::Blue);
			window.draw(triangle);
			window.display();
		}
	}
};

class Rectangle : public ShapeLC
{
protected:
	float a, b, a_pixel, b_pixel;
public:
	Rectangle()
	{
		a = 0;
		b = 0;
		a_pixel = 0;
		b_pixel = 0;
	}
	Rectangle(float a_p, float b_p)
	{
		a = a_p;
		b = b_p;
		a_pixel = a * 37.795275590551;
		b_pixel = b * 37.795275590551;
	}
	virtual ~Rectangle() {};
	virtual float Area()
	{
		return a * b;
	}
	virtual string to_String()
	{
		str += "Rectangle info: ";
		str += "Side a: ";
		str += to_string(a);
		str += " Side b: ";
		str += to_string(b);
		str += " Area: ";
		str += to_string(Area());
		str += "\n";
		return str;
	}
	virtual void Draw()
	{
		RenderWindow window(VideoMode(500, 200), "SFML Works!");
		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			window.clear(Color(250, 220, 100, 0));
			RectangleShape rectangle(Vector2f(a_pixel , b_pixel));
			rectangle.setPosition(x, y);
			rectangle.setFillColor(Color(175, 180, 240));
			window.draw(rectangle);
			window.display();
		}
	}
};

class Square : public Rectangle
{
public:
	Square(float a_p) : Rectangle(a_p, a_p) {};
	virtual ~Square() {};
	virtual string to_String()
	{
		str += "Square info: ";
		str += "Side a: ";
		str += to_string(a);
		str += " Area: ";
		str += to_string(Area());
		str += "\n";
		return str;
	}
};

class Ellipse : public ShapeLC
{
protected:
	float a, b, a_pixel, b_pixel;
public:
	Ellipse()
	{
		a = 0;
		b = 0;
		a_pixel = 0;
		b_pixel = 0;
	}
	Ellipse(float a_p, float b_p)
	{
		a = a_p;
		b = b_p;
		a_pixel = a * 37.795275590551;
		b_pixel = b * 37.795275590551;
	}
	virtual ~Ellipse() {};
	virtual float Area()
	{
		return 3.1415926535 * (a * b);
	}
	virtual string to_String()
	{
		str += "Ellipse info: ";
		str += "Side a: ";
		str += to_string(a);
		str += " Side b: ";
		str += to_string(b);
		str += " Area: ";
		str += to_string(Area());
		str += "\n";
		return str;
	}
	virtual void Draw()
	{
		RenderWindow window(VideoMode(500, 200), "SFML Works!");
		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			window.clear(Color(250, 220, 100, 0));
			CircleShape circle(1.f);
			circle.setScale(a_pixel, b_pixel);
			circle.setFillColor(Color(230, 0, 230));
			window.draw(circle);
			window.display();
		}
	}
};

class Circle : public Ellipse
{
public:
	Circle(float r_p) : Ellipse(r_p, r_p) {};
	virtual ~Circle() {};
	virtual string to_String()
	{
		str += "Circle info: ";
		str += "Radius: ";
		str += to_string(a);
		str += " Area: ";
		str += to_string(Area());
		str += "\n";
		return str;
	}
};

class Cylinder
{
protected:
	float h;
	string str;
	ShapeLC* shp;
public:
	Cylinder()
	{
		h = 0;
		shp = 0;
	}
	Cylinder(float h_p, ShapeLC* shp_p)
	{
		h = h_p;
		shp = shp_p;
	}
	~Cylinder() {};
	float Volume()
	{
		return h * shp->Area();
	}
	string to_String()
	{
		str += "Cylinder info: ";
		str += "Height h: ";
		str += to_string(h);
		str += " Base area: ";
		str += to_string(shp->Area());
		str += " Volume: ";
		str += to_string(Volume());
		str += "\n";
		return str;
	}
};

int main()
{
	ShapeLC* shp;
	Cylinder myCylinder;
	float temp;
	int key = 0;
	do
	{
		cout << "1) Triangle" << endl
			<< "2) Rectangle" << endl
			<< "3) Square" << endl
			<< "4) Ellipse" << endl
			<< "5) Circle" << endl
			<< "6) Cylinder" << endl
			<< "0) Exit" << endl;
		cout << endl << "Select an action: ";
		cin >> key;
		cout << endl;
		switch (key)
		{
		case 1:
			shp = new Triangle(3, 3, 3);
			cout << shp->to_String() << endl;
			shp->Move(4, 4);
			shp->Draw();
			break;
		case 2:
			shp = new Rectangle(3, 5);
			cout << shp->to_String() << endl;
			shp->Move(4, 4);
			shp->Draw();
			break;
		case 3:
			shp = new Square(4);
			cout << shp->to_String() << endl;
			shp->Move(4, 4);
			shp->Draw();
			break;
		case 4:
			shp = new Ellipse(2, 1);
			cout << shp->to_String() << endl;
			shp->Move(4, 4);
			shp->Draw();
			break;
		case 5:
			shp = new Circle(4);
			cout << shp->to_String() << endl;
			shp->Move(4, 4);
			shp->Draw();
			break;
		case 6:
			myCylinder = Cylinder(3, new Circle(4));
			cout << myCylinder.to_String() << endl;
			break;
		default:
			if (key != 0)
			{
				cout << "There is no such action !" << endl << endl;
			}
			break;
		}
	} while (key != 0);
}
#include <iostream>
#include <vector>
#include <cmath>

int gcd(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

class IntPoint
{
public:
	int x;
	int y;
	
	IntPoint(int x, int y) : x(x), y(y) {}
};

class Circle
{
	const double PI = 3.1415926535;
	IntPoint center;
	double
		diameter = radius * 2,
		radius = diameter / 2,
		circumference = PI * diameter;

public:

	Circle(IntPoint c_pt, double d) :
		center( (c_pt.x < -100) ? -100 : (c_pt.x > 100 ? 100 : c_pt.x),
			(c_pt.y < -100) ? -100 : (c_pt.y > 100 ? 100 : c_pt.y)),
		diameter((d < 1) ? 1 : (d > 100 ? 100 : d)) {}

	Circle(IntPoint c_pt, double r) :
		center((c_pt.x < -100) ? -100 : (c_pt.x > 100 ? 100 : c_pt.x),
		(c_pt.y < -100) ? -100 : (c_pt.y > 100 ? 100 : c_pt.y)),
		radius((r < 1) ? 1 : (r > 50 ? 50 : d)) {}

	Circle() :
		center(0, 0),
		diameter(1.0) {}

	double get_diameter()
	{
		diameter = radius * 2;
		return diameter;
	}

	double get_radius()
	{
		radius = diameter / 2;
		return radius;
	}

	double get_circumference()
	{
		return circumference;
	}

	double area()
	{
		return PI * pow(radius, 2);
	}

};

class Rectangle
{
	IntPoint corner; // Location of rectangle's lower-left corner
	int width;       // Rectangle's width
	int height;		 // Rectangle's height

public:

	Rectangle(IntPoint pt, int w, int h) :
		corner((pt.x < -100) ? -100 : (pt.x > 100 ? 100 : pt.x),
		(pt.y < -100) ? -100 : (pt.x > 100 ? 100 : pt.x)),
		width((w < 0) ? 0 : w), height((h < 0) ? 0 : h) {}

	int perimeter()
	{
		return 2 * width + 2 * height;
	}

	int area()
	{
		return width * height;
	}

	int get_width()
	{
		return width;
	}

	int get_height()
	{
		return height;
	}

	// Returns true if rectangle r overlaps this
	// rectangle object.
	bool intersect(Rectangle r)
	{
		IntPoint center_r = r.center();
		std::vector<IntPoint> rect_r;
		int
			r_width = r.get_width(),
			r_height = r.get_height(),
			r_x_corner = center_r.x - static_cast<int>(rint(r_width / 2)),
			r_y_corner = center_r.y - static_cast<int>(rint(r_height / 2)),
			r_x_top = r_x_corner + r_width,
			r_y_top = r_y_corner + r_height,
			r_range_x = r_x_top - r_x_corner,
			r_range_y = r_y_top - r_y_corner;
		// Populate vector with each point of rectangle r
		for (int x = r_x_corner; x < r_range_x ; x++)
		{
			// Each point along X, populate points on Y
			for (int y = r_y_corner; y < r_range_y; y++)
			{
				rect_r.push_back({ x,y });
			}
		}
		// Vector rect_r contains each point of rectangle r
		// so loop through that and check if any points are equal,
		// if they are, then it overlaps on at least a single point
		for (int x = corner.x; x < (corner.x + width); x++ )
			for (int y = corner.y; y < (corner.y + height); y++)
			{
				for (unsigned n = 0; n < rect_r.size(); n++)
				{
					if (x == rect_r[n].x && y == rect_r[n].y)
					{
						return true;
					}
				}
			}
		return false;
	}


	// Returns the length of a diagonal rounded to the
	// nearest integer.
	int diagonal()
	{
		// 2 diagonals in a rectangle, both are same size.
		// Since all corners in a rectangle are 90 degrees,
		// we can use pythagorean theorem: pow(a, 2) + pow(b, 2) = pow (c, 2)

		int result = static_cast<int>(pow(width, 2) + pow(height, 2));

		return static_cast<int>(rint(sqrt(result)));

	}


	// Returns the geometric center of the rectangle with
	// the (x,y) coordinates rounded to the nearest integer.
	IntPoint center()
	{
		IntPoint result(corner.x + static_cast<int>(rint(width / 2)), corner.y + static_cast<int>(rint(height / 2)));
		return result;
	}


	// Returns true if IntPoint pt is inside of the
	// rectangle object to whom this was called upon.
	bool is_inside(IntPoint pt)
	{
		std::vector<IntPoint> rect;

		// Populate vector with each point of rectangle r
		for (int x = corner.x; x < (corner.x + width); x++)
		{
			// Each point along X, populate points on Y
			for (int y = corner.y; y < (corner.y + height); y++)
			{
				rect.push_back({ x,y });
			}
		}
		// Vector rect_r contains each point of rectangle r
		// so loop through that and check if any points are equal,
		// if they are, then it overlaps on at least a single point
		for (unsigned n = 0; n < rect.size(); n++)
		{
			if (pt.x == rect[n].x && pt.y == rect[n].y)
			{
				return true;
			}
		}
		return false;
	}





};

IntPoint corner(Rectangle r)
{
	IntPoint r_center = r.center();

	int
		w = r.get_width,
		h = r.get_height;

	r_center.x = (r_center.x - rint(w / 2));
	r_center.y = (r_center.y - rint(h / 2));

	return r_center;
}

// Returns true if rectangle r is large enough
// to completely enclose circle c
bool encloses(Rectangle r, Circle c)
{

}

int main()
{
	IntPoint rec1(5, 5), rec2(-1, -1);

	Rectangle rect1(rec1, 3, 4), rect2(rec2, 6, 7);
	IntPoint r_center = rect2.center(), l_center = rect1.center();
	std::cout << "r1 Center X = " << l_center.x << " Y = " << l_center.y << '\n';
		
	std::cout << "r2 Center X = " << r_center.x << " Y = " << r_center.y << '\n';

	if (rect1.intersect(rect2))
		std::cout << "TRUE\n";
	else
		std::cout << "FALSE\n";

}

/*
class SimpleRational {

	int numerator;
	int denominator;

public:

	SimpleRational(int n, int d) : numerator(n), denominator(d)
	{
		if (d == 0)
		{
			std::cout << "Zero denominator error\n";
			exit(1);
		}
	}


	SimpleRational(): numerator(0), denominator(1) {}


	void set_numerator(int n)
	{
		numerator = n;
	}


	void set_denominator(int d)
	{
		if (d != 0)
			denominator = d;
		else
		{
			std::cout << "Zero denominator error\n";
			exit(1);
		}
	}


	int get_numerator() const
	{
		return numerator;
	}


	int get_denominator() const
	{
		return denominator;
	}

	void reduceit()
	{
		int gcdResult = gcd(denominator, numerator);

		if (gcdResult > denominator)
			return;
		else
		{
			denominator /= gcdResult;
			numerator /= gcdResult;
		}
	}


};

SimpleRational add(const SimpleRational& sr1, const SimpleRational& sr2)
{// Set numerator and denominator holder values
	SimpleRational ReturnVal;
	int sr1d = 1, sr2d = 1, sr1n = 0, sr2n = 0;

	sr1d = sr1.get_denominator(), sr2d = sr2.get_denominator();
	sr1n = sr1.get_numerator(), sr2n = sr2.get_numerator();

	int sr1NewD = 1, 
		sr2NewD = 1,
		New1N = 0,
		New2N = 0;

	if (sr2d % sr1d == 0)
	{
		sr1NewD = sr2d;
		New1N = (sr2d / sr1d) * sr1n;
		New2N = sr2n;
	}
	else if (sr1d % sr2d == 0)
	{
		sr2NewD = sr1d;
		New1N = sr1n;
		New2N = (sr1d / sr2d) * sr2n;
	}
	else if (sr2d % sr1d != 0 && sr1d % sr2d != 0)
	{
		sr1NewD = sr1d * sr2d;
		sr2NewD = sr1d * sr2d;
		New1N = sr1n * sr2d;
		New2N = sr2n * sr1d;
	}

	if (sr1NewD == New1N)
	{
		ReturnVal.set_denominator(1);
		ReturnVal.set_numerator(1);
		return ReturnVal;
	}
	else
	{
		ReturnVal.set_denominator(sr1NewD);
		ReturnVal.set_numerator(New1N + New2N);
		return ReturnVal;
	}
	


}

class Point 
{ 
	double x; 
	double y; 
public: 
	Point(double x, double y) : x(x), y(y) {} 
	double get_x() const { return x; } 
	double get_y() const { return y; } 
	void set_x(double x) { this->x = x; } 
	void set_y(double y) { this->y = y; } 

	double get_distance(const Point& p) const
	{
		double
			deltaX = pow(p.get_x(), x),
			deltaY = pow(p.get_y(), y),
			result = sqrt(deltaX + deltaY);
		
		return result;
	}
};
*/
/*
* (x1,y1) to (x2,y2) distance finder
* double p1x is x in p1
* double p1y is y in p1
* double p1x is x in p2
* double p2y is y in p2
* Source for math is from Wikipedia:
* http://en.wikipedia.org/wiki/Distance
*
* Created by: Christopher Stromski (cstromski@gmail.com)
* Last Edited: Jan 09, 2017
*
*      Formula:
*
*    Distance = sqrt(   pow ( (x2 - x1), 2) + pow ( (y2 - y1), 2)  )
*/
/*
double distance(const Point& p1, const Point& p2)
{
	double
		p1x = p1.get_x(),
		p2x = p2.get_x(),
		p1y = p1.get_y(),
		p2y = p2.get_y(),
		deltaX = pow(p2x - p1x, 2),
		deltaY = pow(p2y - p1y, 2),
		aDistance = sqrt(deltaX + deltaY);
	
	return aDistance;
}

SimpleRational reduce(const SimpleRational& frac)
{
	SimpleRational result;
	int gcdR = gcd(frac.get_denominator(), frac.get_numerator()),
		fracNum = frac.get_numerator(),
		fracDen = frac.get_denominator();

	if (gcdR > fracDen)
		return frac;
	else
	{
		result.set_denominator(fracDen / gcdR);
		result.set_numerator(fracNum / gcdR);
		return result;
	}
}

int main()
{
	SimpleRational new1, new2;
	int cIN1, cIN2;
	char quit = 'q';
	bool stopit = false;

	do
	{
		std::cout << "Enter numerator and denominator for first frac: ";
		std::cin >> cIN1 >> cIN2;

		new1.set_denominator(cIN2);
		new1.set_numerator(cIN1);

		std::cout << "Enter numerator and denominator for second frac: ";
		std::cin >> cIN1 >> cIN2;

		new2.set_denominator(cIN2);
		new2.set_numerator(cIN1);

		SimpleRational result = add(new1, new2);

		std::cout << "\nResult of adding fractions is: " << result.get_numerator() << '/'
			<< result.get_denominator() << '\n';

		result = reduce(result);

		std::cout << "\nReduced, that would be: " << result.get_numerator() << '/' << result.get_denominator() << '\n';
		std::cout << gcd(result.get_numerator(), result.get_denominator()) <<'\n';

		std::cout << "\nQuit? (Y)es or (N)o: ";
		std::cin >> quit;

		switch (quit)
		{
		case 'y':
		case 'Y':
			stopit = true;
			break;
		case 'n':
		case 'N':
			continue;
		}

	} while (!stopit);
}*/
/*
int main()
{
	Point p1(-22, 15), p2(16, 3);
	double cIN1, cIN2, result;
	char quit = 'q';
	bool stopit = false;

	do
	{
		std::cout << "Enter first point x then y: ";
		std::cin >> cIN1 >> cIN2;

		p1.set_x(cIN1);
		p1.set_y(cIN2);

		std::cout << "Enter second point x then y: ";
		std::cin >> cIN1 >> cIN2;

		p2.set_x(cIN1);
		p2.set_y(cIN2);

		result = distance(p1, p2);

		std::cout << "\nTotal distance is: " << result << '\n';

		std::cout << "Quit? (Y)es or (N)o: ";
		std::cin >> quit;

		switch (quit)
		{
		case 'y':
		case 'Y':
			stopit = true;
			break;
		case 'n':
		case 'N':
			continue;
		}

	} while (!stopit);
}
*/
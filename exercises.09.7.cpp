#include <iostream>
#include <cmath>
#include <algorithm>
/*
 * (x1,y1) to (x2,y2) distance finder
 * double x1 is x1 in (x1,y1)
 * double y1 is y1 in (x1,y1)
 * double x2 is x2 in (x2,y2)
 * double y2 is y2 in (x2,y2)
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

 double distance(double x1, double y1, double x2, double y2)
 {
     double aDistance, deltaX, deltaY;

     // pow( ( x2 - x1 ), 2)
     deltaX = pow(x2-x1,2);

     // pow( ( y2 - y1 ), 2)
     deltaY = pow(y2-y1,2);

     // Distance = sqrt ( deltaX + deltaY )
     aDistance = sqrt(deltaX+deltaY);

     return aDistance;
 }

 int main1()
 {
     double x1, x2, y1, y2;
     char LP = '(', RP = ')', COMMA = ',';

     // Get x1 and y1 from user, making sure they provide correct
     // input, otherwise stay in loop.
     std::cout << "Please provide a starting position (x1,y1): ";
     do
     {
         std::cin >> LP >> x1 >> COMMA >> y1 >> RP;
     }
     while ( LP != '(' || COMMA != ',' || RP != ')' );

     //...now get x2 and y2, only accepting proper input.
     std::cout << "\n...and ending position (x2,y2): ";
     do
     {
         std::cin >> LP >> x2 >> COMMA >> y2 >> RP;
     }
     while ( LP != '(' || COMMA != ',' || RP != ')' );

     std::cout << "The distance between (" << x1 << ',' << y1 << ") and ("
               << x2 << ',' << y2 << ") is: " << distance(x1,y1,x2,y2);
 }






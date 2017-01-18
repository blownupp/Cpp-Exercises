#include <iostream>
/*
int gcd (int a, int b)
{
    while ( a != b )
    {
        if ( a > b )
            a = a - b;
        else
            b = b - a;
    }
    return a;
}
int main1()
{
    int in1, in2;
    std::cout << "Input 2 integers; 0 exits: ";
    do
    {
        std::cout << "Number 1: ";
        std::cin >> in1;
        std::cout << "Number 2: ";
        std::cin >> in2;
        std::cout << "GCD: " << gcd(in1, in2) << '\n';
    }
    while (in1 != 0 || in2 != 0);

}
*/

void get_range(int min, int max, int& lower, int& upper)
{
    std::cout << "Please enter a data range within the bounds "
              << min << "..." << max << ": ";

    do {// loop until acceptable values are provided
        std::cin >> lower >> upper;
        if (lower < min)
            std::cout << lower << " is too low, please try again.\n";
        if (upper > max)
            std::cout << upper << " is too high, please try again.\n";
    }
    while (lower < min || upper > max);
}

int main()
{
    int lower, upper;
    get_range(20, 100, lower, upper);
    std::cout << lower << ' ' << upper;
}

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int sum = 0;

    for (int i = 0; i <= 20; i += 2)
	{
        sum += i;
    }
    
    ofstream output;

    output.open("output.txt");

        output << "The sum of the even number betweem 0 to 20: " << sum << endl;

    output.close();

    return 0;
}
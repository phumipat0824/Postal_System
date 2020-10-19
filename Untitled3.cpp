#include <iostream>
#include <fstream>
#include <fstream>
using namespace std;

int main()
{
	string j;
    ofstream myfile;
    myfile.open ("example.txt");
    
    cin>>j;
    myfile << "This is the first line.\n";
    myfile << "The second line.\n";
    myfile << j;
    myfile.close();
    return 0;
}

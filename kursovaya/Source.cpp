#include <iostream>
#include <fstream>
#include <string>
#include "FordFulkerson.h"

using namespace std;

int main()
{
	FordFulkerson a;
	ofstream out;
	out.open("graph.txt");
	if (out.is_open())
	{
		out << "S B 5";
		out << endl;
		out << "S D 7";
		out << endl;
		out << "D F 13";
		out << endl;
		out << "B G 4";
		out << endl;
		out << "G F 6";
		out << endl;
		out << "F T 15";
	}
	out.close();
	
	cout << a.alghoritm("graph.txt");
	
	return 0;
}
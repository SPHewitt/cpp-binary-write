#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int SIZE_OF_ARRAY = 100000;

int main(int argc, char **argv)
{
	float a_float = 124.0;
	long a_long = 54.0;
	int a_integer = 12;

	clock_t time_req;

	float array[SIZE_OF_ARRAY];

	cout << endl;
	cout << "------ Size of Floats ------" << endl;
	// check the size of data types
	cout << "Size of int(bytes): " << sizeof(a_integer) << endl;	
	cout << "Size of float(bytes): " << sizeof(a_float) << endl;	
	cout << "Size of long(bytes): " << sizeof(a_long) << endl;

	cout << "\nPopulating array of size: " << SIZE_OF_ARRAY << endl;
	// Populate array with values	
	for(int i=0; i<SIZE_OF_ARRAY;i++)
	{
		array[i]=i;
	}

	cout << "\nWriting Ascii Files" << endl;
	time_req = clock();
	// Write an ascii file	
	ofstream ascii_file("file.ascii",ios::out | ios::binary);
	for(int i=0; i<SIZE_OF_ARRAY;i++)
	{
	    ascii_file << array[i] << ",";
	}
	ascii_file.close();
	time_req = clock() - time_req;
	cout << "Time to write: " << (float)time_req/CLOCKS_PER_SEC <<
	       	" seconds" << endl;


	cout << "\nWriting Binary Files" << endl;
	time_req=clock();
	ofstream bin_file("file.bin",ios::out | ios::binary);
	for(int i=0; i<SIZE_OF_ARRAY;i++)
	{
	    bin_file.write((char*)(&array[i]),sizeof(a_float));
	}
	bin_file.close();
	time_req = clock() - time_req;
	cout << "Time to write: " << (float)time_req/CLOCKS_PER_SEC <<
	       	" seconds" << endl; 

	cout << endl;
}

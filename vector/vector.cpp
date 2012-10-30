// vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <time.h>

using namespace std;

vector<int> GenerateVectorOfSize(int sz)
{
	vector<int> v;

	for(int i = 0; i< sz; i++)
	{
		v.push_back(i);
	}

	return v;
}

void PrintVector(vector<int> &v)
{
	for (int i=0; i < v.size(); i++)
		cout<<" "<<v[i];
}

void WriteVectorToFile(vector<int> &v)
{
	ofstream diskFile;
	
	time_t rawtime;
	struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

	diskFile.open("vectorContents.txt", ios::out | ios::trunc);
	diskFile<<"Starting to write the contents of the vector - At Time:  " <<  asctime (timeinfo) << endl;
	diskFile<<"------------------------------------------------------  "<< endl;
	
	for (int i=0; i < v.size(); i++)
		diskFile<<" "<<v[i];
	
	diskFile<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> myVector = GenerateVectorOfSize(10);
	PrintVector (myVector);	// write to screen
	WriteVectorToFile(myVector); // write to text file

	return 0;
}


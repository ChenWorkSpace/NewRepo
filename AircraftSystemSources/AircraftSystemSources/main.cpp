#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "AircraftSystemMainSources.h"
using namespace std;

File file;
AirLine airline;

int main()
{
	/*FILE *f;
	int elem;
	fopen_s(&f, "FilghtA/Filghta-1/Filghta-1.txt","r");
	fscanf_s(f, "%d", &elem);
	cout << elem;
	cin >> elem;*/
	InitAircraftSystem(&file,&airline);
	//Main();
	return 0;
}



	
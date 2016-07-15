#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "AircraftSystemMainSources.h"
using namespace std;

File file;
AirLine airline;

int main()
{
	//char addr[60] = "user";
	InitAircraftSystem(&file,&airline);//初始化系统
	Main(&airline);//主界面
	return 0;
}



	
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
	InitAircraftSystem(&file,&airline);//��ʼ��ϵͳ
	Main(&airline);//������
	return 0;
}



	
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<string>
#include<string.h>
#include <iostream>
using namespace std;
#include "AircraftSystemMainSources.h"
/*
功能要求：
          浏览功能（Borwse）：浏览全部（All）和指定(Appoint)航班的信息
          查询功能（Search):按指定方式查询航线
          航班号（FlightNumber）起始站（StartingStation）,终点站（Terminus）
          修改功能（Modification）：修改航班信息
          订票功能(BookTheTicket)：订票操作
          保存功能（Save):保存航班信息及机票信息数据（文件）

航班信息：
          航班号（FlightNumber），起始站(StaringStation)，终点站(Terminus)
          飞行时间(FlightTime)，预售票总数(SurplusTicketSum)，已售票总数(SaleTicketSum)

机票信息：
          航班号，起始站，终点站，飞行时间，座位号（SeatNumber），票价(TicketPrice)，持票人(Owner)

文件系统；
         由Airline.txt文件存储总航线信息  由Filght+字母（A~Z）.txt 存储具体的航线信息 
		 由Filght+字母(A~Z)+‘-’number.txt 存储具体的航班信息
		 


*/
int UserMainFrom()
{
	getchar();
    char elem;
    while(1)
    {
		fflush(stdin);
		fflush(stdout);
        system("cls");//清屏操作
        printf("\n\n\n");
        printf("        --------------------------航班信息管理系统-------------------------\n\n");
        printf("        [F]航班列表   [S]查询航班  [M]修改航班信息    [B]订票    [D]注销机票 \n\n");
        printf("        \n\n\n");
        printf("        -------------------------------------------------------------------\n");
        printf("        R[返回]                                                     Q[退出]\n");
		scanf_s("%c", &elem);
		if (elem == 'B' || elem == 'b')
		{
			BookTheTicket();
		}
		else if (elem == 'S' || elem == 's')
		{
			SearchFilght();
		}
		else if (elem == 'Q' || elem == 'q')
		{
			exit(0);
		}
		else if (elem == 'F' || elem == 'f')
		{
			FilghtList();
		}
		else if (elem == 'D' || elem == 'd')
		{
			DestroyFilghtData();
		}
		else if (elem == 'M' || elem == 'm')
		{
			ModificationFilghtDataForUser();
		}
		else if (elem == 'R' || elem == 'r')
		{
			getchar();
			break;
		}
		else
			InputError();
    }
    return 0;
}

int ManageMainFrom()
{
	return 0;
}
int FilghtList()
{
    return 0;
}

int SearchFilght()
{
    return 0;
}

int ModificationFilghtDataForUser()						
{
    return 0;
}
//terminus终点站
//inception point 起点站

int GetTerminus()
{
	return 0;
}

int GetInceptionPoint()
{
	return 0;
}
int BookTheTicket()
{
	char elem;
	while (1)
	{
		printf("\n\n\n");
		printf("        --------------------------航班信息管理系统-------------------------\n\n");
		printf("        [I]选择起点站                                          [M]选择终点站\n\n");
		printf("        \n\n\n");
		printf("        -------------------------------------------------------------------\n");
		printf("        R[返回]                                                      Q[退出]\n");
		scanf_s("%c", &elem);
		if (elem == 'M' || elem == 'm')
		{
			GetTerminus();
		}
		else if (elem == 'S' || elem == 's')
		{
			GetInceptionPoint();
		}
		else if (elem == 'R' || elem == 'r')
			return 0;
		else if (elem == 'Q' || elem == 'q')
		{
			exit(0);
		}
		else
			InputError();
	}
	

    return 0;
}

int DestroyFilghtData()
{
    return 0;
}

int InputError()
{
	    getchar();
	    system("cls");
        char elem;
        printf("\n\n\n");
        printf("        --------------------------输入错误-------------------------\n\n");
        printf("        \n\n\n");
		printf("        输入任意字符返回...\n");
        printf("        -------------------------------------------------------------------\n");
		scanf_s("%c", &elem);
        return 0;
}
int Main()
{
	char elem;
	while (1)
	{
		system("cls");//清屏操作
		printf("\n\n\n");
		printf("        --------------------------航班信息管理系统-------------------------\n\n");
		printf("        [U]用户界面                                             [M]管理员界面 \n\n");
		printf("        \n\n\n");
		printf("        -------------------------------------------------------------------\n");
		printf("        Q[退出]\n");
		scanf_s("%c", &elem);
		if (elem == 'U' || elem == 'u')
		{
			UserMainFrom();
		}
		else if (elem == 'M' || elem == 'm')
		{
			ManageMainFrom();
		}
		else if (elem == 'Q' || elem == 'q')
		{
			exit(0);
		}
		else
			InputError();

	}
}

int InitAircraftSystem(File *file,AirLine *airline)
{
	int elem;
	GetAirLineData(file, airline);
	//GetFilghtNumberData();
	cin >> elem;
	return 0;

}

int GetAirLineData(File *file,AirLine *airline)
{
	AirLineNode *aln = airline->first = (AirLineNode*)malloc(sizeof(AirLineNode)), *alb;
	int FilghtLineNo = 1;
	int FilghtNumber = 1;
	file->membersum = 0;
	FILE *F, *FF;
	char str[20], str2[40], temp[20];
	fopen_s(&F, "Airline.txt", "a+");
	while (fgets(str, 1024, F))
	{
		str[strlen(str) - 1] = '\0';
		strcpy_s(str2, str);
		strcat_s(str2, "/");
		strcat_s(str2, str);
		strcat_s(str2, ".txt");
		fopen_s(&FF, str2, "a+");
		FilghtNumber = 1;
		while (fgets(str, 1024, FF))
		{
			str[strlen(str) - 1] = '\0';
			alb = airline->first->next = (AirLineNode*)malloc(sizeof(AirLineNode));
			alb->FilghtLineNo = FilghtLineNo;
			alb->FilghtNumber =FilghtNumber ;
			FilghtNumber++;
			memcpy(alb->StartingStation, str, sizeof(str));
			fgets(str, 1024, FF);
			str[strlen(str) - 1] = '\0';
			memcpy(alb->Terminus, str, sizeof(str));
			fgets(str, 1024, FF);
			str[strlen(str) - 1] = '\0';

			cout << "始发站:" << alb->StartingStation << "  终点站:" << alb->Terminus << "航线号：" << alb->FilghtLineNo << "航班数：" << alb->FilghtNumber << endl;
			aln->next = alb;
			alb->first;


		}
		FilghtLineNo++;


		//break;
		//fopen_s(&F, str2, "a+");
		//fscanf_s(F, "%s", str, 1024);

	}
}
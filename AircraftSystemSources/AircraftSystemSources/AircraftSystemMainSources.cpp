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
int UserMainFrom(AirLine *airline)
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
			FilghtList(airline);
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
int FilghtList(AirLine *airline)
{
	char elem;
	system("cls");
	AirLine *AL = airline;
	AirLineNode *ALN = AL->first;
	getchar();
	while (1)
	{
		printf("\n\n\n");
		printf("        --------------------------航班信息管理系统-------------------------\n\n");
		printf("        航线数：%d \n\n", AL->AirLineNumber);
		while (ALN)
		{
			printf("        航线: %d  %s - %s 航班数: %d \n\n", ALN->FilghtLineNo, ALN->StartingStation, ALN->Terminus, ALN->FilghtNumber, ALN->FilghtNumber);
			ALN = ALN->next;
		}
		printf("        \n\n\n");
		printf("        -------------------------------------------------------------------\n");
		printf("        R[返回]                                                     Q[退出]\n");
		scanf_s("%c", &elem);
		if (elem == 'Q' || elem == 'q')
		{
			exit(0);
		}
		else if (elem == 'R' || elem == 'r')
		{
			return 0;
		}
		else
			InputError();
	}
	
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
int Main(AirLine *airline)
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
			UserMainFrom(airline);
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
	return 0;

}

int GetAirLineData(File *file,AirLine *airline)
{
	AirLineNode *aln = airline->first = (AirLineNode*)malloc(sizeof(AirLineNode)), *alb;
	int FilghtLineNo = 1;//航线号
	int FilghtNumber = 1;//航班数
	file->membersum = 0;
	FILE *F, *FF;
	char str[20], str2[60], temp[20];
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
		alb = (AirLineNode*)malloc(sizeof(AirLineNode));
		while (fgets(str, 1024, FF))
		{
			str[strlen(str) - 1] = '\0';
			alb->FilghtLineNo = FilghtLineNo;
			alb->FilghtNumber =FilghtNumber ;
			memcpy(alb->StartingStation, str, sizeof(str));
			fgets(str, 1024, FF);
			str[strlen(str) - 1] = '\0';
			memcpy(alb->Terminus, str, sizeof(str));
			fgets(str, 1024, FF);
			if(str[strlen(str) - 1] == '\n')
			str[strlen(str) - 1] ='\0';
			GetFilghtNumberData(str,alb,str2);
			FilghtNumber++;
			//cout << "始发站:" << alb->StartingStation << "  终点站:" << alb->Terminus << "航线号：" << alb->FilghtLineNo << "航班数：" << alb->FilghtNumber << endl;
		}
		aln->next = alb;
		alb->Last = aln;
		aln = alb;
		airline->AirLineNumber++;

		FilghtLineNo++;;
	}
	fclose(F);
	fclose(FF);
	fflush(F);
	fflush(FF);
	aln->next = NULL;
	AirLineNode* p = airline->first;
	airline->first = airline->first->next;
	free(p);
}


int GetFilghtNumberData(char *str,AirLineNode *airlinenode,char *FileAddr)
{
	FilghtSeat *head,*last,*temp;
	last = (FilghtSeat*)malloc(sizeof(FilghtSeat));
	head = last;
	float content;
	FILE *F, *FF;
	char addr[80];
	int elem = 0,s,t,u;
	memcpy(addr, FileAddr, sizeof(addr));
	while (addr[elem])
	{
		if (addr[elem] == '/')
		{
			 s = 0;
			while (str[s])
			{
				addr[elem + 1 + s] = str[s];
				s++;
			}
			t = 0;
			addr[elem + 1 + s] = '/';
			u = elem + 1 + s+1;
			while (t<10)
			{
				addr[u+t] = str[t];

				t++;
			}
			break;
			//memcpy(addr + elem + 1+strlen(str), str, sizeof(addr));
		}
		elem++;
	}
	strcat_s(addr, ".txt");
	if (airlinenode->FilghtNumber == 1)
	{
		int test;
		elem = 0;
		airlinenode->first = (FilghtSeat*)malloc(sizeof(FilghtSeat));
		free(head);
		head = airlinenode->first;
		last = head;
		memcpy(head->FilghtNumber, str, sizeof(head->FilghtNumber));
		fopen_s(&F, addr, "r");
	    fscanf_s(F, "%d", &test);
		fscanf_s(F, "%d", &head->TicketSum);
		fscanf_s(F, "%d", &head->FirstCabinsSum);
		fscanf_s(F, "%d", &head->TouristClassSum);
		fscanf_s(F, "%lf", &head->FlightTime);
		head->SaleFirstCabins = 0;
		head->SaleTicketSum = 0;
		head->SaleTouristClass = 0;
		head->SurplusFirstCabins = head->FirstCabinsSum;
		head->SurplusTicketSum = head->TicketSum;
		head->SurplusTouristClass = head->TouristClassSum;
		GetFilghtMemberData(head,F,addr );
		
	}
	else
	{
		temp = (FilghtSeat*)malloc(sizeof(FilghtSeat));
		memcpy(temp->FilghtNumber, str, sizeof(temp->FilghtNumber));
		fopen_s(&F, addr, "a+");
		fscanf_s(F, "%d", &temp->TicketPrice);
		fscanf_s(F, "%d", &temp->TicketSum);
		fscanf_s(F, "%d", &temp->FirstCabinsSum);
		fscanf_s(F, "%d", &temp->TouristClassSum);
		fscanf_s(F, "%lf", &temp->FlightTime);
		temp->SaleFirstCabins = 0;
		temp->SaleTicketSum = 0;
		temp->SaleTouristClass = 0;
		temp->SurplusFirstCabins = temp->FirstCabinsSum;
		temp->SurplusTicketSum = temp->TicketSum;
		temp->SurplusTouristClass = temp->TouristClassSum;
		GetFilghtMemberData(temp, F, addr);
		last->next = temp;
		last = temp;

	}
	fclose(F);
	return 0;
}


int GetFilghtMemberData(FilghtSeat *filghtseat, FILE *F,char *addr)
{
	FILE *FF;
	int i = 0,m=0,n,d=0;
	char str[40], str2[20], name[20], ID[40];
	FilghtSeatNode *head, *last, *temp;
	fgets(str2, 1024, F);
	while (fgets(str2, 1024, F))
	{
		if (str2[0] == '\n')
			break;
		i = 0, m = 0;
		memcpy(str, addr, sizeof(str));
		while (addr[i])
		{
			if (addr[i] == '/')
			{
				m++;
			}
			if (addr[i] == '/'&&m == 2)
			{
				n = 0;
				while (str2[n])
				{
					str[i + 1] = str2[n];
					i++;
					n++;
				}
				str[i] = '\0';
				strcat_s(str, ".txt");
				break;
			}
			i++;
		}
		fopen_s(&FF, str, "a+");
		if (filghtseat->SaleTicketSum == 0)
		{
			head = (FilghtSeatNode*)malloc(sizeof(FilghtSeatNode));
			fscanf_s(FF, "%d", &head->type);
			fscanf_s(FF, "%d", &head->Number);
			fscanf_s(FF, "%s", name, sizeof(name));
			memcpy(head->Owner, name, sizeof(name));
			fscanf_s(FF, "%s", ID, sizeof(ID));
			memcpy(head->IDcharNumber, ID, sizeof(ID));
			filghtseat->head = head;
			filghtseat->Trail = head;
			filghtseat->SaleTicketSum++;
		}
		else
		{
			temp = (FilghtSeatNode*)malloc(sizeof(FilghtSeatNode));
			fscanf_s(FF, "%d", &temp->type);
			fscanf_s(FF, "%d", &temp->Number);
			fscanf_s(FF, "%s", name, sizeof(name));
			memcpy(temp->Owner, name, sizeof(name));
			fscanf_s(FF, "%s", ID, sizeof(ID));
			memcpy(temp->IDcharNumber, ID, sizeof(ID));
			filghtseat->Trail->next = temp;
			filghtseat->Trail = filghtseat->Trail->next;
			filghtseat->SaleTicketSum++;
		}
	}
	
	return 0;
}
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<string>
#include<string.h>
#include <iostream>
using namespace std;
#include "AircraftSystemMainSources.h"
/*
����Ҫ��
          ������ܣ�Borwse�������ȫ����All����ָ��(Appoint)�������Ϣ
          ��ѯ���ܣ�Search):��ָ����ʽ��ѯ����
          ����ţ�FlightNumber����ʼվ��StartingStation��,�յ�վ��Terminus��
          �޸Ĺ��ܣ�Modification�����޸ĺ�����Ϣ
          ��Ʊ����(BookTheTicket)����Ʊ����
          ���湦�ܣ�Save):���溽����Ϣ����Ʊ��Ϣ���ݣ��ļ���

������Ϣ��
          ����ţ�FlightNumber������ʼվ(StaringStation)���յ�վ(Terminus)
          ����ʱ��(FlightTime)��Ԥ��Ʊ����(SurplusTicketSum)������Ʊ����(SaleTicketSum)

��Ʊ��Ϣ��
          ����ţ���ʼվ���յ�վ������ʱ�䣬��λ�ţ�SeatNumber����Ʊ��(TicketPrice)����Ʊ��(Owner)

�ļ�ϵͳ��
         ��Airline.txt�ļ��洢�ܺ�����Ϣ  ��Filght+��ĸ��A~Z��.txt �洢����ĺ�����Ϣ 
		 ��Filght+��ĸ(A~Z)+��-��number.txt �洢����ĺ�����Ϣ
		 


*/
int UserMainFrom()
{
	getchar();
    char elem;
    while(1)
    {
		fflush(stdin);
		fflush(stdout);
        system("cls");//��������
        printf("\n\n\n");
        printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
        printf("        [F]�����б�   [S]��ѯ����  [M]�޸ĺ�����Ϣ    [B]��Ʊ    [D]ע����Ʊ \n\n");
        printf("        \n\n\n");
        printf("        -------------------------------------------------------------------\n");
        printf("        R[����]                                                     Q[�˳�]\n");
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
//terminus�յ�վ
//inception point ���վ

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
		printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
		printf("        [I]ѡ�����վ                                          [M]ѡ���յ�վ\n\n");
		printf("        \n\n\n");
		printf("        -------------------------------------------------------------------\n");
		printf("        R[����]                                                      Q[�˳�]\n");
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
        printf("        --------------------------�������-------------------------\n\n");
        printf("        \n\n\n");
		printf("        ���������ַ�����...\n");
        printf("        -------------------------------------------------------------------\n");
		scanf_s("%c", &elem);
        return 0;
}
int Main()
{
	char elem;
	while (1)
	{
		system("cls");//��������
		printf("\n\n\n");
		printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
		printf("        [U]�û�����                                             [M]����Ա���� \n\n");
		printf("        \n\n\n");
		printf("        -------------------------------------------------------------------\n");
		printf("        Q[�˳�]\n");
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

			cout << "ʼ��վ:" << alb->StartingStation << "  �յ�վ:" << alb->Terminus << "���ߺţ�" << alb->FilghtLineNo << "��������" << alb->FilghtNumber << endl;
			aln->next = alb;
			alb->first;


		}
		FilghtLineNo++;


		//break;
		//fopen_s(&F, str2, "a+");
		//fscanf_s(F, "%s", str, 1024);

	}
}
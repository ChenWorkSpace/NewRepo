#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<string>
#include<string.h>
#include <iostream>
#include<time.h>
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
int  FilghtEum = 1;
char user[20];
int UserMainFrom(AirLine *airline)
{
	//getchar();
    char elem;
    while(1)
    {
		getchar();
		fflush(stdin);
		fflush(stdout);
        system("cls");//��������
        printf("\n\n\n");
        printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
        printf("        [F]�����б�   [S]��ѯ����     [B]��Ʊ         [G]��Ʊ\n\n");
        printf("        \n\n\n");
        printf("        -------------------------------------------------------------------\n");
        printf("        R[����]                                                     Q[�˳�]\n");
		scanf_s("%c", &elem);
		if (elem == 'B' || elem == 'b')
		{
			BookTheTicket(airline);
		}
		else if (elem == 'S' || elem == 's')
		{
			SearchFilght(airline);
		}
		else if (elem == 'Q' || elem == 'q')
		{
			exit(0);
		}
		else if (elem == 'F' || elem == 'f')
		{
			FilghtList(airline);
		}
		else if (elem == 'R' || elem == 'r')
		{
			break;
		}
		else if (elem == 'G' || elem == 'g')
		{
			GetMyData(airline);
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
int ManageMainFrom()
{
	return 0;
}
int FilghtList(AirLine *airline)
{
	char elem;
	int i = 0;
	while (1)
	{
		getchar();
		AirLine *AL = airline;
		AirLineNode *ALN = AL->first;
		FilghtSeat *temp;
		system("cls");
		printf("\n\n\n");
		printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
		printf("        ��������%d \n\n", AL->AirLineNumber);
		while (ALN)
		{
			printf("        ����: %d  %s - %s ������: %d \n\n", ALN->FilghtLineNo, ALN->StartingStation, ALN->Terminus, ALN->FilghtNumber, ALN->FilghtNumber);
			temp = ALN->first;
			i = 0;
			while (temp)
			{
				if (i > 4)
				{
					printf("\n");
				}
				printf("        ����: %s", temp->FilghtNumber);
				i++;
				temp = temp->next;
			}
			printf("\n\n");
			ALN = ALN->next;
		}
		printf("        \n\n\n");
		printf("        -------------------------------------------------------------------\n");
		printf("        R[����]                                                     Q[�˳�]\n");
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

int SearchFilght(AirLine *airline)
{
	char elem;
	while (1)
	{
		getchar();
		system("cls");//��������
		printf("\n\n\n");
		printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
		printf("        ��ѯ��ʽ:\n");
		printf("        [F]�����                    [S]ʼ����                    [M]Ŀ�ĵ� \n\n");
		printf("        \n\n\n");
		printf("        -------------------------------------------------------------------\n");
		printf("        R[����]                                                     Q[�˳�]\n");
		scanf_s("%c", &elem);
		if (elem == 'F' || elem == 'f')
		{

			SearchforFilghtNumber(airline);
		}
		else if (elem == 'S' || elem == 's')
		{
			SearchforStaringStation(airline);
		}
		else if (elem == 'M' || elem == 'm')
		{
			SearchforTerminus(airline);
		}
		else if (elem == 'R' || elem == 'r')
		{
			return 0;
		}
		else if (elem == 'Q' || elem == 'q')
		{
			exit(0);
		}
		else
			InputError();
	}
	
	
    return 0;
}

int ModificationFilghtDataForUser()						
{
    return 0;
}
//terminus�յ�վ
//inception point ���վ

int GetTerminus(AirLine *airline)
{
	AirLine *al = airline;
	char StaringStation[20];
	char Terminus[20];
	AirLineNode *aln;
	FilghtSeat *fs;
	char elem;
	while (1)
	{
		aln = airline->first;
		fs = airline->first->first;
		getchar();
		system("cls");//��������
		printf("\n\n\n");
		printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
		printf("        ��������ʼվ��string����                                              \n        ");
		scanf_s("%s", StaringStation, sizeof(StaringStation));
		getchar();
		system("cls");//��������
		printf("\n\n\n");
		printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
		printf("        �������յ�վ��string����                                              \n        ");
		scanf_s("%s", Terminus, sizeof(Terminus));
		while (aln)
		{
			if(memcmp(StaringStation, aln->StartingStation, strlen(aln->StartingStation))==0&&memcmp(Terminus,aln->Terminus,strlen(Terminus))==0)
			{
				printf("\n        ��������: %s-%s      ���ߺ�: %d \n", aln->StartingStation, aln->Terminus, aln->FilghtLineNo);
				fs = aln->first;
				while (fs)
				{
					printf("        ������  : %s          �����: %d \n\n", fs->FilghtNumber, fs->FilghtEum);
					fs = fs->next;
				}
			}
			aln = aln->next;
		}

	}
	return 0;
}

int GetInceptionPoint(AirLine *airline)
{
	AirLine *al = airline;
	char StaringStation[20];
	char Terminus[20];
	AirLineNode *aln;
	FilghtSeat *fs;
	int elem,i=0;
	while (1)
	{
		aln = airline->first;
		fs = airline->first->first;
		getchar();
		system("cls");//��������
		printf("\n\n\n");
		printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
		printf("        ��������ʼվ��string����                                              \n        ");
		scanf_s("%s", StaringStation, sizeof(StaringStation));
		getchar();
		system("cls");//��������
		printf("\n\n\n");
		printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
		printf("        �������յ�վ��string����                                              \n        ");
		scanf_s("%s", Terminus, sizeof(Terminus));
		while (aln)
		{
			if (memcmp(StaringStation, aln->StartingStation, strlen(aln->StartingStation)) == 0 && memcmp(Terminus, aln->Terminus, strlen(Terminus)) == 0)
			{
				printf("\n        ��������: %s-%s      ���ߺ�: %d \n", aln->StartingStation, aln->Terminus, aln->FilghtLineNo);
				fs = aln->first;
				while (fs)
				{
					printf("        ������  : %s    �����: %d    Ʊ��:%d:\n\n", fs->FilghtNumber, fs->FilghtEum,fs->TicketPrice);
					fs = fs->next;
				}
				break;
			}
			aln = aln->next;
		}
		while (1)
		{
			if (i > 0)
			{
				system("cls");
			}
			i++;
			printf("        \n\n\n");
			printf("        -------------------------------------------------------------------\n");
			printf("        -1[����]                                                     -2[�˳�]\n");
			printf("        ѡ�񺽰ࣨ����ţ���                                              \n        ");
			getchar();
			scanf_s("%d", &elem);
			if (elem == -1)
			{
				return 0;
			}
			else if (elem == -2)
			{
				exit(0);
			}
			else if (elem)
			{
				if(AddMemberData(aln, elem))
				system("cls");//��������
				printf("\n\n\n");
				printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
				printf("        �����ɹ�                                               \n        ");
				printf("        \n\n\n");
				printf("        -------------------------------------------------------------------\n");
				printf("        R[����]                                                     Q[�˳�]\n");
				scanf_s("%c", &elem);
				if (elem == 'R' || elem == 'r')
				{
					return 0;
				}
				else if (elem == 'Q' || elem == 'q')
				{
					exit(0);
				}
				else
					InputError();

			}
			else
				InputError();
		}
		

	}
	return 0;
}
int BookTheTicket(AirLine *airline)
{
	char elem;
	while (1)
	{
		getchar();
		system("cls");
		printf("\n\n\n");
		printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
		printf("        [I]ѡ�����վ                                          \n\n");
		printf("        \n\n\n");
		printf("        -------------------------------------------------------------------\n");
		printf("        R[����]                                                      Q[�˳�]\n");
		scanf_s("%c", &elem);
		if (elem == 'I' || elem == 'i')
		{
			GetInceptionPoint(airline);
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
int Main(AirLine *airline)
{
	char elem;
	SelecetUserMain();
	while (1)
	{
		getchar();
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
	int FilghtLineNo = 1;//���ߺ�
	int FilghtNumber = 1;//������
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
			//cout << "ʼ��վ:" << alb->StartingStation << "  �յ�վ:" << alb->Terminus << "���ߺţ�" << alb->FilghtLineNo << "��������" << alb->FilghtNumber << endl;
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
		airlinenode->Trail = head;
		memcpy(head->FilghtNumber, str, sizeof(head->FilghtNumber));
		fopen_s(&F, addr, "r");
	    fscanf_s(F, "%d", &test);
		fscanf_s(F, "%d", &head->TicketSum);
		fscanf_s(F, "%d", &head->FirstCabinsSum);
		fscanf_s(F, "%d", &head->TouristClassSum);
		fscanf_s(F, "%lf", &head->FlightTime);
		head->FilghtEum = FilghtEum;
		head->SaleFirstCabins = 0;
		head->SaleTicketSum = 0;
		head->SaleTouristClass = 0;
		head->SurplusFirstCabins = head->FirstCabinsSum;
		head->SurplusTicketSum = head->TicketSum;
		head->SurplusTouristClass = head->TouristClassSum;
		GetFilghtMemberData(head,F,addr );
		FilghtEum++;
		
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
		temp->FilghtEum = FilghtEum;
		FilghtEum++;
		temp->SaleFirstCabins = 0;
		temp->SaleTicketSum = 0;
		temp->SaleTouristClass = 0;
		temp->SurplusFirstCabins = temp->FirstCabinsSum;
		temp->SurplusTicketSum = temp->TicketSum;
		temp->SurplusTouristClass = temp->TouristClassSum;
		GetFilghtMemberData(temp, F, addr);
		airlinenode->Trail->next = temp;
		airlinenode->Trail = airlinenode->Trail->next;

	}
	airlinenode->Trail->next = NULL;
	fclose(F);
	fflush(F);
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
		fclose(FF);
	}
	return 0;
}


int SearchforFilghtNumber(AirLine *airline)
{
	AirLineNode *aln;
	FilghtSeat *fs;
	char FilghtNumber[20];
	char elem;
	while (1)
	{
		aln = airline->first;
		fs = airline->first->first;
		getchar();
		system("cls");//��������
		printf("\n\n\n");
		printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
		printf("        �����뺽��ţ�string����                                              \n        ");
    	scanf_s("%s", FilghtNumber,sizeof(FilghtNumber));
		while (aln)
		{
			
			fs = aln->first;
			while (fs)
			{
				if (memcmp(fs->FilghtNumber, FilghtNumber,strlen(fs->FilghtNumber))==0)
				{
					printf("\n        ��������: %s-%s      ���ߺ�: %d \n",aln->StartingStation,aln->Terminus,aln->FilghtLineNo);
				    printf("        ������  : %s          �����: %d \n\n", fs->FilghtNumber, fs->FilghtEum);
					printf("\n");
					break;
				}
				fs = fs->next;
			}
			aln = aln->next;
		}
		printf("        \n\n\n");
		printf("        -------------------------------------------------------------------\n");
		printf("        R[����]                                                     Q[�˳�]\n");
		getchar();
		scanf_s("%c", &elem);
		if (elem == 'R' || elem == 'r')
		{
			return 0;
		}
		else if (elem == 'Q' || elem == 'q')
		{
			exit(0);
		}
		else
			InputError();
	}
//	while()


}

int SearchforStaringStation(AirLine *airline)
{
	AirLineNode *aln;
	FilghtSeat *fs;
	char StaringStation[20];
	char elem;
	while (1)
	{
		aln = airline->first;
		fs = airline->first->first;
		getchar();
		system("cls");//��������
		printf("\n\n\n");
		printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
		printf("        ��������ʼվ��string����                                              \n        ");
		scanf_s("%s", StaringStation, sizeof(StaringStation));
		while (aln)
		{
			fs = aln->first;
              	if (memcmp(aln->StartingStation, StaringStation, strlen(aln->StartingStation)) == 0)
				{
					printf("\n        ��������: %s-%s      ���ߺ�: %d \n", aln->StartingStation, aln->Terminus, aln->FilghtLineNo);
					while (fs)
					{
						printf("        ������  : %s          �����: %d \n\n", fs->FilghtNumber, fs->FilghtEum);
						fs = fs->next;
					}
					printf("\n");
				}
			aln = aln->next;
		}
		printf("        \n\n\n");
		printf("        -------------------------------------------------------------------\n");
		printf("        R[����]                                                     Q[�˳�]\n");
		getchar();
		scanf_s("%c", &elem);
		if (elem == 'R' || elem == 'r')
		{
			return 0;
		}
		else if (elem == 'Q' || elem == 'q')
		{
			exit(0);
		}
		else
			InputError();
	}
	//	while()
}


int SearchforTerminus(AirLine *airline) 
{
	AirLineNode *aln;
	FilghtSeat *fs;
	char Terminus[20];
	char elem;
	while (1)
	{
		aln = airline->first;
		fs = airline->first->first;
		getchar();
		system("cls");//��������
		printf("\n\n\n");
		printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
		printf("        �������յ�վ��string����                                              \n        ");
		scanf_s("%s", Terminus, sizeof(Terminus));
		while (aln)
		{
			fs = aln->first;
			if (memcmp(aln->Terminus,Terminus, strlen(aln->Terminus)) == 0)
			{
				printf("\n        ��������: %s-%s      ���ߺ�: %d \n", aln->StartingStation, aln->Terminus, aln->FilghtLineNo);
				while (fs)
				{
					printf("        ������  : %s          �����: %d \n\n", fs->FilghtNumber, fs->FilghtEum);
					fs = fs->next;
				}
				printf("\n");
			}
			aln = aln->next;
		}
		printf("        \n\n\n");
		printf("        -------------------------------------------------------------------\n");
		printf("        R[����]                                                     Q[�˳�]\n");
		getchar();
		scanf_s("%c", &elem);
		if (elem == 'R' || elem == 'r')
		{
			return 0;
		}
		else if (elem == 'Q' || elem == 'q')
		{
			exit(0);
		}
		else
			InputError();
	}
	//	while()
}



int SelecetUserMain()
{
	char selecet;

	while (1)
	{
		system("cls");//��������
		printf("\n\n\n");
		printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
		printf("        [A]�����˻�                                                 [L]��½\n\n");
		printf("        \n\n\n");
		printf("        -------------------------------------------------------------------\n");

		scanf_s("%c", &selecet);
		if (selecet == 'A' || selecet == 'a')
		{
			if (!RegisterUserMain())
				return 0;
		}
		else if (selecet == 'L' || selecet == 'l')
		{
			if (LoginUserMain())
				return 0;
		}
		else
		{
			InputError();
		}
	}

		
}
int RegisterUserMain()
{
	FILE *F, *FF;
	char username[20], password[20];
	int i = 0,m = 0;
	char addr[40];
	char elem;
	memcpy(addr, "UserMain/", sizeof("UserMain/"));
	system("cls");//��������
	printf("\n\n\n");
	printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
	printf("        �����˻�����                                              \n\n        ");
	scanf_s("%s", username, sizeof(username));
	while (addr[i])
	{
		if (addr[i] == '/')
		{
			while (username[m])
			{
				addr[i + 1] = username[m];
				i++;
				m++;
			}
			addr[i+1] = '\0';
		}
		i++;
	}
	strcat_s(addr, ".txt");
	fopen_s(&FF,addr, "w+");
	fwrite(username, strlen(username), 1, FF);
	fprintf(FF, "\n");
	system("cls");//��������
	printf("\n\n\n");
	printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
	printf("        �������룺                                              \n\n        ");
	scanf_s("%s", password, sizeof(password));
	fwrite(password, strlen(password), 1, FF);
	fprintf(FF, "\n");
	fclose(FF);
	while (1)
	{
		getchar();
		system("cls");//��������
		printf("\n\n\n");
		printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
		printf("        �����ɹ�                                              \n\n        ");
		printf("        -------------------------------------------------------------------\n");
		printf("        R[����]                                                     Q[�˳�]\n");
		scanf_s("%c", &elem);
		if (elem == 'R' || elem == 'r')
		{
			return 0;
		}
		else if (elem == 'Q' || elem == 'q')
		{
			exit(0);
		}
		else
			InputError();
	}
	

	return 0;


}




int LoginUserMain()
{
	char elem;
	int i = 1;
	while (i)
	{
		FILE *F, *FF;
		char username[20], password[20], usernamecmp[20], passwordcmp[20];
		int i = 0, m = 0;
		char addr[40];
		char elem;
		memcpy(addr, "UserMain/", sizeof("UserMain/"));
		system("cls");//��������
		printf("\n\n\n");
		printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
		printf("        �����˻�����                                              \n\n        ");
		scanf_s("%s", username, sizeof(username));
		while (addr[i])
		{
			if (addr[i] == '/')
			{
				while (username[m])
				{
					addr[i + 1] = username[m];
					i++;
					m++;
				}
				addr[i + 1] = '\0';
			}
			i++;
		}
		strcat_s(addr, ".txt");
		system("cls");
		if (!fopen_s(&FF, addr, "r"))
		{
			fgets(usernamecmp, 1024, FF);
			usernamecmp[strlen(usernamecmp) - 1] = '\0';
		    if (memcmp(username, usernamecmp, strlen(usernamecmp)) == 0)
			{
				getchar();
				system("cls");//��������
				printf("\n\n\n");
printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
printf("        �������룺                                            \n\n        ");
scanf_s("%s", password, sizeof(password));
fgets(passwordcmp, 1024, FF);
passwordcmp[strlen(passwordcmp) - 1] = '\0';
if (memcmp(password, passwordcmp, strlen(passwordcmp)) == 0)
{
	fclose(FF);
	fflush(FF);
	memcpy(user, usernamecmp, strlen(usernamecmp));
	return 1;
}
else
{
	fclose(FF);
	fflush(FF);
	return 0;
}


			}
			else
			{
				fclose(FF);
				fflush(FF);
				return 0;
			}

		}
		else
		{
			InputError();
		}

	}

	return 0;
}

int AddMemberData(AirLineNode *aln, int FilghtNumber)
{
	char name[20];
	char ID[30];
	int type;
	int number;
	AirLineNode *Aln = aln;
	FilghtSeat *fs = aln->first;
	FilghtSeatNode *fsn = aln->first->head;
	while (fs)
	{
		if (fs->FilghtEum == FilghtNumber)
		{
			printf("        ����������������string����                                              \n        ");
			scanf_s("%s", name, sizeof(name));
			getchar();
			printf("        �������������֤�ţ�string����                                              \n        ");
			scanf_s("%s", ID, sizeof(ID));
			while (1)
			{
				printf("        ѡ���λ�����ò�0/�����1����                                              \n        ");
				getchar();
				scanf_s("%d", &type);
				getchar();
				if (type == 1)
				{
					if(AddMemberDataforFile(fs, type,name,ID))
					return 1;
				}
				else if (type == 0)
				{
					if(AddMemberDataforFile(fs, type,name,ID))
					return 1;
				}
				else
					continue;

			}
		}
		fs = fs->next;
	}
}

int AddMemberDataforFile(FilghtSeat *fs, int type,char *name,char *ID)
{
	char id[30], Name[20];
	int i = 0,m=0;
	char member[20];
	char addr[60] = "UserMain/";
	char addr2[60]="Filght";
	char addr3[60] = "Filght";
	char addr4[60];
	while (addr[i])
	{
		if (addr[i] == '/')
		{
			while (user[m])
			{
				addr[i + 1] = user[m];
				m++;
				i++;
			}
			addr[i + 1] = '\0';
		}
		i++;
	}
	i = 0, m = 0;
	while (fs->FilghtNumber[i])
	{
		if (i == 6)
		{
			addr2[i] = fs->FilghtNumber[i];
			addr3[i] = fs->FilghtNumber[i];
			addr2[i + 1] = '/';
			addr3[i + 1] = '/';
			while (fs->FilghtNumber[m])
			{
				addr2[i + 2] = fs->FilghtNumber[m];
				addr3[i + 2] = fs->FilghtNumber[m];
				
				m++;
				i++;
			}
			addr2[i + 2] = '/';
			addr3[i + 2] = '/';
			m = 0;
			while (fs->FilghtNumber[m])
			{
				addr2[i + 3] = fs->FilghtNumber[m];
				i++;
				m++;
			}
			break;
		}
		i++;
	}
	int number, sum;
	FILE *F,*FF;
	FilghtSeatNode *fsn = fs->head;
	FilghtSeatNode *last;
	srand(int(time(0)));
	while (1)
	{
		if (type == 1)
		{
			sum = fs->FirstCabinsSum;
			number = rand() % (sum + 1) + 0;
		}
		else
		{
			sum = fs->TicketSum - fs->FirstCabinsSum;
			number = rand() % (sum + 1) + 0;
		}

		while (fsn)
		{
			if (fsn->Number == number)
			{
				break;
			}
			else if (fsn == fs->Trail && (fsn->Number != number))
			{
				last = (FilghtSeatNode*)malloc(sizeof(FilghtSeatNode));
				strcpy_s(last->IDcharNumber, ID);
				strcpy_s(last->Owner, name);
				last->Number = number;
				last->type = type;
				fs->Trail->next = last;
				last->Last = fs->Trail;
				fs->Trail = fs->Trail->next;
				fs->Trail->next = NULL;
				strcat_s(addr, ".txt");
				strcat_s(addr2, ".txt");
				fopen_s(&F, addr, "a+");
				if (type == 1)
				{
					fprintf(F, "H");
					fprintf(F,"%d",number);
					fprintf(F, "\n");
					fopen_s(&FF, addr2, "a+");
					fprintf(FF, "H");
					fprintf(FF, "%d", number);
					fprintf(FF, "\n");
				}
				else if (type == 0)	
				{
					fprintf(F, "E");
					fprintf(F, "%d", number);
					fprintf(F, "\n");
					fopen_s(&FF, addr2, "a+");
					fprintf(FF, "E");
					fprintf(FF, "%d", number);
					fprintf(FF, "\n");
				}
				fclose(FF);
				fflush(FF);
				fopen_s(&FF, addr2, "r");
				while (fgets(addr4, 1024, FF)){};
				fclose(FF);
				fflush(FF);
				addr4[strlen(addr4) - 1] = '\0';
				strcat_s(addr3, addr4);
				strcat_s(addr3, ".txt");
				fopen_s(&FF, addr3, "a+");
				fprintf(FF, "%d", type);
				fprintf(FF, "\n");
				fprintf(FF, "%d", fs->Trail->Number);
				fprintf(FF, "\n");
				fs->Trail->Owner[strlen(name) - 1] = '\0';
				fprintf_s(FF, "%s", name,strlen(name));
				fprintf(FF, "\n");
				fs->Trail->IDcharNumber[strlen(ID) - 1] = '\0';
				fprintf_s(FF, "%s",ID, strlen(ID));
				fprintf(FF, "\n");
				fclose(FF);
				fflush(FF);
				fclose(F);
				fflush(F);
				fopen_s(&FF, addr, "a+");
				fprintf_s(FF, "%s",addr3,strlen(addr3));
				fprintf_s(FF,"%s" ,"\n",strlen("\n"));
				fclose(FF);
				fflush(FF);
				return 1;
			}
			fsn = fsn->next;
		}
		return 0;
	}
	return 0;
}


int GetMyData(AirLine *airline)
{
	FILE *F,*FF;
	char elem;
	int i = 0, m = 0;
	while (1)
	{
		char addr[60] = "UserMain/", name[60];
		while (addr[i])
		{
			if (addr[i] == '/')
			{
				while (user[m])
				{
					addr[i + 1] = user[m];
					m++;
					i++;
				}
				addr[i + 1] = '\0';
			}
			i++;
		}
		strcat_s(addr, ".txt");
		fopen_s(&F, addr, "a+");
		while (fgets(name, 1024, F)) {};
		fclose(F);
		name[strlen(name) - 1] = '\0';
		fopen_s(&FF, name, "a+");
		fgets(name, 1024, FF);
		fgets(name, 1024, FF);
		fgets(name, 1024, FF);
		name[strlen(name) - 1] = '\0';
		fclose(FF);
		AirLineNode *aln = airline->first;
		FilghtSeat *fs = airline->first->first;
		FilghtSeatNode *fsn = airline->first->first->head;
		int i = 1;
		while (1)
		{
			fs = aln->first;
			while (fs)
			{
				fsn = fs->head;
				while (fsn)
				{
					if (memcmp(fsn->Owner, name, strlen(name)) == 0)
					{
						if (fsn->type == 1)
						{
						}
						system("cls");//��������
						printf("\n\n\n");
						printf("        --------------------------������Ϣ����ϵͳ-------------------------\n\n");
						if (fsn->type == 1)
						{
							printf("        ����: %s  ���֤��: %s  ��λ��: %d ��λ: %d \n", fsn->Owner, fsn->IDcharNumber, fsn->Number, "�����");
						}
						else
							printf("        ����: %s  ���֤��: %s  ��λ: %d \n", fsn->Owner, fsn->IDcharNumber, "���ò�");
						printf("        ��������: %d  ��������: %s(%d)  ��λ��: %d \n\n", aln->FilghtLineNo, fs->FilghtNumber,fs->FilghtEum, fsn->Number);
						printf("        \n\n\n");
						printf("        -------------------------------------------------------------------\n");
						printf("        R[����]                                                     Q[�˳�]\n");
						getchar();
						scanf_s("%c", &elem);
						if (elem == 'R' || elem == 'r')
							{
							//aln = NULL;
							return 0;
							//fsn = NULL;
							//fs = NULL;
							break;
							}
							else if (elem == 'Q' || elem == 'q')
							{
								exit(0);
							}
							else
								InputError();


					}
					fsn = fsn->next;
				}
				fs = fs->next;

			}
			aln = aln->next;
		}

	}
	


		cin >> i;

}
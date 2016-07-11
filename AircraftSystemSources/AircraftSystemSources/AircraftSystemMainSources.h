#ifndef AIRCRAFTSYSTEMMAINSOURCES_H_INCLUDED
#define AIRCRAFTSYSTEMMAINSOURCES_H_INCLUDED
//�ļ��ṹ��


typedef struct File
{
	FILE *oprint;//�ļ������
	FILE *iprint;//�ļ�������
	int membersum;//�ܳ˿���
	//AirLine  *airline;

}File;
//������λ�ڵ㣺 ��λ�����Ϣ

typedef struct FilghtSeatNode
{
    int Number;//��λ��
    char Owner[20];//�˿�����
    char IDcharNumber[20];//�˿����֤��
    struct FilghtSeatNode *next;//��һ��
    struct FilghtSeatNode *Last;//��һ��

}FilghtSeatNode;

//������λ��  ��Ÿú����ܵ���λ��Ϣ ��λ�����ͷβָ��
typedef struct FilghtSeat
{
    char FilghtNumber[20];//������
    float TicketPrice;//��Ʊ�۸�
    short SurplusTicketSum;//ʣ��Ʊ��
    short SaleTicketSum;//����Ʊ��
    short TicketSum;//��Ʊ��
    float FlightTime;//����ʱ��
    struct FilghtSeatNode *head;
    struct FilghtSeatNode *Trail;
    struct FilghtSeat *next;
    struct FilghtSeat *Last;

}FilghtSeat;

//���ߺ���ڵ� ���������Ϣ ���������� ʼ���� Ŀ�ĵ�
typedef struct AirLineNode
{
    char StartingStation[20];
    char Terminus[20];
    short FilghtNumebr;//������
    struct FilghtSeat *first;
    struct AirLineNode *Last;
    struct AirLineNode *next;
}AirLineNode;

//���� ������������
typedef struct AirLine
{
	int AirLineNumber;
	struct AirLineNode *first;

}AirLine;



//�����溯��  For User
int UserMainFrom();

//�޸ĺ�����Ϣ
int ModificationFilghtDataForUser();
//��Ʊ
int BookTheTicket();
//��Ʊ
int DestroyFilghtData();

//�����溯�� For Manage
int AddAirLine();
//ɾ��������Ϣ
int DestroyAirline();
//
int AddFilghtNumber();
int DestroyFilghtNumber();
int ManageMainFrom();
//ͨ�ú���
//��ʼ������
int InitAircraftSystem();
//�������
int InputError();
//�����б�
int FilghtList();
//��������
int SearchFilght();
//�޸ĺ�����Ϣ
int ModificationFilghtDataForManage();
//��ȡ���վ
//terminus�յ�վ
//inception point ���վ
int GetTerminus();
//��ȡ�յ�վ
int GetInceptionPoint();

//������
int Main();
#endif // AIRCRAFTSYSTEMMAINSOURCES_H_INCLUDED

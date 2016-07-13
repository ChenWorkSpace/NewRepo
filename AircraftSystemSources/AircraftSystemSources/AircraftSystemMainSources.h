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
	short type;//��λ����(ͷ��1/����0)�� 
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
	short FirstCabinsSum;//ͷ�Ȳ���Ʊ��
	short SaleFirstCabins;//����ͷ�Ȳ���
	short SurplusFirstCabins;//ʣ��ͷ�Ȳ�Ʊ��
	short TouristClassSum;//���ò���Ʊ��
	short SaleTouristClass;//���۾��ò�Ʊ��
	short SurplusTouristClass;//ʣ�ྭ�ò�Ʊ��
    float FlightTime;//����ʱ��
    struct FilghtSeatNode *head;
    struct FilghtSeatNode *Trail;
    struct FilghtSeat *next;
    struct FilghtSeat *Last;

}FilghtSeat;

//���ߺ���ڵ� ���������Ϣ ���������� ʼ���� Ŀ�ĵ�
typedef struct AirLineNode
{
    char StartingStation[20];//���վ
    char Terminus[20];//�յ�վ
    short FilghtNumber;//������
	short FilghtLineNo;//���ߺ�
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

//��ȡ������Ϣ
int GetAirLineData(File *file,AirLine *airline);

//��ȡ������Ϣ
int GetFilghtNumberData(char *str,AirLineNode *airlinenode,char *FileAddr);

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
//���Ӻ���
int AddFilghtNumber();
//ɾ������
int DestroyFilghtNumber();
//����Ա����
int ManageMainFrom();
//ͨ�ú���
//��ʼ������
int InitAircraftSystem(File *file,AirLine *airline);
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

//��ȡ������Ա��Ϣ
int GetFilghtMemberData(FilghtSeat *filghtseat,char *addr);
//������
int Main();
#endif // AIRCRAFTSYSTEMMAINSOURCES_H_INCLUDED

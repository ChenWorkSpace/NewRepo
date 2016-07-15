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
    char IDcharNumber[40];//�˿����֤��
    struct FilghtSeatNode *next;//��һ��
    struct FilghtSeatNode *Last;//��һ��

}FilghtSeatNode;

//������λ��  ��Ÿú����ܵ���λ��Ϣ ��λ�����ͷβָ��
typedef struct FilghtSeat
{
    char FilghtNumber[20];//������
	int  FilghtEum;//�����
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
    struct FilghtSeat *next;//��һ��
    struct FilghtSeat *Last;//��һ��

}FilghtSeat;

//���ߺ���ڵ� ���������Ϣ ���������� ʼ���� Ŀ�ĵ�
typedef struct AirLineNode
{
    char StartingStation[20];//���վ
    char Terminus[20];//�յ�վ
    short FilghtNumber;//������
	short FilghtLineNo;//���ߺ�
    struct FilghtSeat *first;
	struct FilghtSeat *Trail;
    struct AirLineNode *Last;
    struct AirLineNode *next;
}AirLineNode; 

//���� ������������
typedef struct AirLine
{
	int AirLineNumber;//������
	struct AirLineNode *first;

}AirLine;

//��ȡ������Ϣ
int GetAirLineData(File *file,AirLine *airline);

//��ȡ������Ϣ
int GetFilghtNumberData(char *str,AirLineNode *airlinenode,char *FileAddr);

//�����溯��  For User
int UserMainFrom(AirLine *airline);

//�޸ĺ�����Ϣ
int ModificationFilghtDataForUser();
//��Ʊ
int BookTheTicket(AirLine *airline);
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
int FilghtList(AirLine *airline);
//��������
int SearchFilght(AirLine *airline);
//�޸ĺ�����Ϣ
int ModificationFilghtDataForManage();
//��ȡ���վ
//terminus�յ�վ
//inception point ���վ
int GetTerminus(AirLine *airline);
//��ȡ�յ�վ
int GetInceptionPoint(AirLine *airline);

//��ȡ������Ա��Ϣ
int GetFilghtMemberData(FilghtSeat *filghtseat,FILE *F,char* addr);
//������
int Main(AirLine *airline);
//ͨ�������Ѱ�Һ���
int SearchforFilghtNumber(AirLine *airline);

//ͨ��ʼ���ز��Һ���
int SearchforStaringStation(AirLine *airline);

//ͨ���յ�վ���Һ���
int SearchforTerminus(AirLine *airline);
#endif // AIRCRAFTSYSTEMMAINSOURCES_H_INCLUDED
int SelecetUserMain();

//��½�˻�
int LoginUserMain();

//ע���˻�
int RegisterUserMain();

//ע����Ʊ
int DestroyFilghtData();

//������Ա��Ϣ
int AddMemberData(AirLineNode *aln,int FilghtNumber);

//������Ա��Ϣ�ļ�
int AddMemberDataforFile(FilghtSeat *fs,int type,char *name,char *ID);

//��ȡ�û��µĻ�Ʊ��Ϣ
int GetMyData(AirLine *airline);
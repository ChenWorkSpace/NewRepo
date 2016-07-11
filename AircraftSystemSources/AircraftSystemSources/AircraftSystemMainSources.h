#ifndef AIRCRAFTSYSTEMMAINSOURCES_H_INCLUDED
#define AIRCRAFTSYSTEMMAINSOURCES_H_INCLUDED
//文件结构体


typedef struct File
{
	FILE *oprint;//文件输出流
	FILE *iprint;//文件输入流
	int membersum;//总乘客数
	//AirLine  *airline;

}File;
//航班座位节点： 座位相关信息

typedef struct FilghtSeatNode
{
    int Number;//座位号
    char Owner[20];//乘客名称
    char IDcharNumber[20];//乘客身份证号
    struct FilghtSeatNode *next;//下一个
    struct FilghtSeatNode *Last;//上一个

}FilghtSeatNode;

//航班座位：  存放该航班总的座位信息 座位链表的头尾指针
typedef struct FilghtSeat
{
    char FilghtNumber[20];//航班名
    float TicketPrice;//机票价格
    short SurplusTicketSum;//剩余票数
    short SaleTicketSum;//已售票数
    short TicketSum;//总票数
    float FlightTime;//飞行时间
    struct FilghtSeatNode *head;
    struct FilghtSeatNode *Trail;
    struct FilghtSeat *next;
    struct FilghtSeat *Last;

}FilghtSeat;

//航线航班节点 航班相关信息 包括：航线 始发地 目的地
typedef struct AirLineNode
{
    char StartingStation[20];
    char Terminus[20];
    short FilghtNumebr;//航班数
    struct FilghtSeat *first;
    struct AirLineNode *Last;
    struct AirLineNode *next;
}AirLineNode;

//航线 包括：航线数
typedef struct AirLine
{
	int AirLineNumber;
	struct AirLineNode *first;

}AirLine;



//主界面函数  For User
int UserMainFrom();

//修改航班信息
int ModificationFilghtDataForUser();
//订票
int BookTheTicket();
//退票
int DestroyFilghtData();

//主界面函数 For Manage
int AddAirLine();
//删除航线信息
int DestroyAirline();
//
int AddFilghtNumber();
int DestroyFilghtNumber();
int ManageMainFrom();
//通用函数
//初始化函数
int InitAircraftSystem();
//输入错误
int InputError();
//航线列表
int FilghtList();
//搜索航班
int SearchFilght();
//修改航班信息
int ModificationFilghtDataForManage();
//获取起点站
//terminus终点站
//inception point 起点站
int GetTerminus();
//获取终点站
int GetInceptionPoint();

//主界面
int Main();
#endif // AIRCRAFTSYSTEMMAINSOURCES_H_INCLUDED

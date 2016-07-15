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
	short type;//舱位座次(头等1/经济0)舱 
    int Number;//座位号
    char Owner[20];//乘客名称
    char IDcharNumber[40];//乘客身份证号
    struct FilghtSeatNode *next;//下一个
    struct FilghtSeatNode *Last;//上一个

}FilghtSeatNode;

//航班座位：  存放该航班总的座位信息 座位链表的头尾指针
typedef struct FilghtSeat
{
    char FilghtNumber[20];//航班名
	int  FilghtEum;//航班号
    float TicketPrice;//机票价格
    short SurplusTicketSum;//剩余票数
    short SaleTicketSum;//已售票数
    short TicketSum;//总票数
	short FirstCabinsSum;//头等舱总票数
	short SaleFirstCabins;//已售头等舱数
	short SurplusFirstCabins;//剩余头等舱票数
	short TouristClassSum;//经济舱总票数
	short SaleTouristClass;//已售经济舱票数
	short SurplusTouristClass;//剩余经济舱票数
    float FlightTime;//飞行时间
    struct FilghtSeatNode *head;
    struct FilghtSeatNode *Trail;
    struct FilghtSeat *next;//下一个
    struct FilghtSeat *Last;//上一个

}FilghtSeat;

//航线航班节点 航班相关信息 包括：航线 始发地 目的地
typedef struct AirLineNode
{
    char StartingStation[20];//起点站
    char Terminus[20];//终点站
    short FilghtNumber;//航班数
	short FilghtLineNo;//航线号
    struct FilghtSeat *first;
	struct FilghtSeat *Trail;
    struct AirLineNode *Last;
    struct AirLineNode *next;
}AirLineNode; 

//航线 包括：航线数
typedef struct AirLine
{
	int AirLineNumber;//航线数
	struct AirLineNode *first;

}AirLine;

//获取航线信息
int GetAirLineData(File *file,AirLine *airline);

//获取航班信息
int GetFilghtNumberData(char *str,AirLineNode *airlinenode,char *FileAddr);

//主界面函数  For User
int UserMainFrom(AirLine *airline);

//修改航班信息
int ModificationFilghtDataForUser();
//订票
int BookTheTicket(AirLine *airline);
//主界面函数 For Manage
int AddAirLine();
//删除航线信息
int DestroyAirline();
//增加航班
int AddFilghtNumber();
//删除航班
int DestroyFilghtNumber();
//管理员界面
int ManageMainFrom();
//通用函数
//初始化函数
int InitAircraftSystem(File *file,AirLine *airline);
//输入错误
int InputError();
//航线列表
int FilghtList(AirLine *airline);
//搜索航班
int SearchFilght(AirLine *airline);
//修改航班信息
int ModificationFilghtDataForManage();
//获取起点站
//terminus终点站
//inception point 起点站
int GetTerminus(AirLine *airline);
//获取终点站
int GetInceptionPoint(AirLine *airline);

//获取航班人员信息
int GetFilghtMemberData(FilghtSeat *filghtseat,FILE *F,char* addr);
//主界面
int Main(AirLine *airline);
//通过航班号寻找航班
int SearchforFilghtNumber(AirLine *airline);

//通过始发地查找航班
int SearchforStaringStation(AirLine *airline);

//通过终点站查找航班
int SearchforTerminus(AirLine *airline);
#endif // AIRCRAFTSYSTEMMAINSOURCES_H_INCLUDED
int SelecetUserMain();

//登陆账户
int LoginUserMain();

//注册账户
int RegisterUserMain();

//注销机票
int DestroyFilghtData();

//创建成员信息
int AddMemberData(AirLineNode *aln,int FilghtNumber);

//创建成员信息文件
int AddMemberDataforFile(FilghtSeat *fs,int type,char *name,char *ID);

//获取用户下的机票信息
int GetMyData(AirLine *airline);
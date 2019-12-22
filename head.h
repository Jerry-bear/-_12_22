/***********************
//用单链表来实现简易的通讯录
//测试环境为 Windows VS2013
************************/

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

typedef struct DataType{
	string num;  //编号
	string name; //姓名
	string sex;  //性别
	string phone; //电话
	string addr; //住址
}DataType;

typedef struct InfoNode{
	DataType data;
	struct InfoNode* _next;
}InfoNode;

//菜单选择程序
void menu()
{
	printf("     通讯录管理系统\n");
	printf("=========================\n");
	printf("   1.通讯录链表的建立\n");
	printf("   2.通讯录信息的插入\n");
	printf("   3.通讯录信息的查询\n");
	printf("   4.通讯录信息的修改\n");
	printf("   5.通讯录信息的删除\n");
	printf("   6.通讯录链表的输出\n");
	printf("   0.退出管理系统\n");
	printf("=========================\n");
	printf("请选择 0-6: ");

}

//申请新的节点
InfoNode* buyNewNode()
{
	InfoNode* newNode = new InfoNode();
	return newNode;
}

//通讯录链表的建立(带头的单向链表)
void createPersonInfoList(InfoNode* pHead)
{
	pHead->_next = nullptr;
	cout << "通讯录链表创建完成!" << endl;
}

//通讯录信息的插入
void insertPersonInfoToList(InfoNode* pHead)
{
	char flag = 'y';
	while (flag == 'y')
	{
		//先申请新的节点
		InfoNode* newNode = buyNewNode();
		cout << "编号: ";
		cin >> newNode->data.num;
		cout << "姓名: ";
		cin >> newNode->data.name;
		cout << "性别: ";
		cin >> newNode->data.sex;
		cout << "电话: ";
		cin >> newNode->data.phone;
		cout << "地址: ";
		cin >> newNode->data.addr;

		//输入完成后，将该节点尾插到通讯录链表上
		//若只有一个信息节点,则直接尾插
		if (pHead->_next == nullptr)
		{
			pHead->_next = newNode;
			newNode->_next = nullptr;
		}
		//若已经有了若干个节点
		else
		{
			//遍历找到最后节点
			InfoNode* pCur = pHead->_next;
			while (pCur->_next != nullptr)
			{
				pCur = pCur->_next;
			}
			pCur->_next = newNode;
			newNode->_next = nullptr;
		}
		cout << "是否继续录入(y/n):";
		cin >> flag;
	}
}

//通讯录信息的查询
void searchPersonInfoList(InfoNode* pHead)
{
	if (pHead->_next == nullptr)
	{
		cout << "通讯录为空,查询失败!" << endl;
	}
	else
	{
		int select = 0;
		printf("===============\n");
		printf(" 1. 按编号查询\n");
		printf(" 2. 按姓名查询\n");
		printf("===============\n");
		cout << "请选择: ";
		cin >> select;
		if (select == 1)
		{
			int count = 0;
			string num;
			cout << "请输入编号: ";
			cin >> num;
			//遍历链表，查询与输入的编号相同的信息
			InfoNode* pCur = pHead->_next;
			printf("编号     姓名      性别   电话             地址\n");
			printf("-----------------------------------------------------\n");
			while (pCur != nullptr)
			{
				if (pCur->data.num != num)
				{
					pCur = pCur->_next;
				}
				else
				{
					++count;
					cout << pCur->data.num << "     ";
					cout << pCur->data.name << "     ";
					cout << pCur->data.sex << "    ";
					cout << pCur->data.phone << "      ";
					cout << pCur->data.addr << endl;
					pCur = pCur->_next;
				}
			}
			printf("------共有%d条记录------\n", count);
		}
		if (select == 2)
		{
			int count = 0;
			string name;
			cout << "请输入姓名: ";
			cin >> name;
			//遍历链表，查询与输入的编号相同的信息
			InfoNode* pCur = pHead->_next;
			printf("编号     姓名      性别   电话             地址\n");
			printf("-----------------------------------------------------\n");
			while (pCur != nullptr)
			{
				if (pCur->data.name != name)
				{
					pCur = pCur->_next;
				}
				else
				{
					++count;
					cout << pCur->data.num << "     ";
					cout << pCur->data.name << "     ";
					cout << pCur->data.sex << "    ";
					cout << pCur->data.phone << "      ";
					cout << pCur->data.addr << endl;
					pCur = pCur->_next;
				}
			}
			printf("------共有%d条记录------\n", count);
		}
	}
}

//通讯录信息的修改
void modifyPersonInfoList(InfoNode* pHead)
{
	if (pHead->_next == nullptr)
	{
		cout << "通讯录为空，修改失败!" << endl;
		return;
	}
	//根据正常的使用场景，一般不会修改联系人的姓名，可能修改的是【电话】或者【住址】
	string name;
	cout << "请输入将要修改的联系人姓名: ";
	cin >> name;
	//遍历链表，查询此节点
	InfoNode* pCur = pHead->_next;
	while (pCur != nullptr)
	{
		if (pCur->data.name != name)
		{
			pCur = pCur->_next;
		}
		else
		{
			int select = 0;
			printf("=================\n");
			printf(" 1. 修改电话号码\n");
			printf(" 2. 修改家庭住址\n");
			printf("=================\n");
			cout << "请输入: ";
			cin >> select;
			if (select == 1)
			{
				string newPhone;
				cout << "请输入新的电话号码:";
				cin >> newPhone;
				pCur->data.phone = newPhone;
			}
			if (select == 2)
			{
				string newAddr;
				cout << "请输入新的家庭住址:";
				cin >> newAddr;
				pCur->data.addr = newAddr;
			}
			cout << "-----修改成功-----\n";
			pCur = pCur->_next;
		}
	}
}

//通讯录联系人的删除
void delPersonInfo(InfoNode* pHead)
{
	if (pHead->_next == nullptr)
	{
		cout << "通讯录为空，删除失败!" << endl;
		return;
	}

	string delName;
	cout << "请输入将要删除的联系人姓名: ";
	cin >> delName;
	//遍历链表，查找这个节点
	InfoNode* pPrev = pHead;
	InfoNode* pCur = pHead->_next;
	while (pCur != nullptr)
	{
		if (pCur->data.name != delName)
		{
			pPrev = pCur;
			pCur = pCur->_next;
		}
		else
		{
			//找到了这个联系人
			InfoNode* delNode = pCur;
			pPrev->_next = pCur->_next;
			pCur = pCur->_next;
			delete delNode;
			delNode = nullptr;
			return;
		}
	}
	cout << "-----无本地搜索结果-----\n";
}
//通讯录链表的输出
void printPersonInfoList(InfoNode* pHead)
{
	if (pHead->_next == nullptr)
	{
		cout << "通讯录为空，输出失败!" << endl;
	}
	else
	{
		printf("编号     姓名      性别   电话             地址\n");
		printf("-----------------------------------------------------\n");
		InfoNode* pCur = pHead->_next;
		while (pCur != nullptr)
		{
			cout << pCur->data.num << "     ";
			cout << pCur->data.name << "     ";
			cout << pCur->data.sex << "    ";
			cout << pCur->data.phone << "      ";
			cout << pCur->data.addr <<endl;
			pCur = pCur->_next;
		}
	}
}



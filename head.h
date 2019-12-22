/***********************
//�õ�������ʵ�ּ��׵�ͨѶ¼
//���Ի���Ϊ Windows VS2013
************************/

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

typedef struct DataType{
	string num;  //���
	string name; //����
	string sex;  //�Ա�
	string phone; //�绰
	string addr; //סַ
}DataType;

typedef struct InfoNode{
	DataType data;
	struct InfoNode* _next;
}InfoNode;

//�˵�ѡ�����
void menu()
{
	printf("     ͨѶ¼����ϵͳ\n");
	printf("=========================\n");
	printf("   1.ͨѶ¼����Ľ���\n");
	printf("   2.ͨѶ¼��Ϣ�Ĳ���\n");
	printf("   3.ͨѶ¼��Ϣ�Ĳ�ѯ\n");
	printf("   4.ͨѶ¼��Ϣ���޸�\n");
	printf("   5.ͨѶ¼��Ϣ��ɾ��\n");
	printf("   6.ͨѶ¼��������\n");
	printf("   0.�˳�����ϵͳ\n");
	printf("=========================\n");
	printf("��ѡ�� 0-6: ");

}

//�����µĽڵ�
InfoNode* buyNewNode()
{
	InfoNode* newNode = new InfoNode();
	return newNode;
}

//ͨѶ¼����Ľ���(��ͷ�ĵ�������)
void createPersonInfoList(InfoNode* pHead)
{
	pHead->_next = nullptr;
	cout << "ͨѶ¼���������!" << endl;
}

//ͨѶ¼��Ϣ�Ĳ���
void insertPersonInfoToList(InfoNode* pHead)
{
	char flag = 'y';
	while (flag == 'y')
	{
		//�������µĽڵ�
		InfoNode* newNode = buyNewNode();
		cout << "���: ";
		cin >> newNode->data.num;
		cout << "����: ";
		cin >> newNode->data.name;
		cout << "�Ա�: ";
		cin >> newNode->data.sex;
		cout << "�绰: ";
		cin >> newNode->data.phone;
		cout << "��ַ: ";
		cin >> newNode->data.addr;

		//������ɺ󣬽��ýڵ�β�嵽ͨѶ¼������
		//��ֻ��һ����Ϣ�ڵ�,��ֱ��β��
		if (pHead->_next == nullptr)
		{
			pHead->_next = newNode;
			newNode->_next = nullptr;
		}
		//���Ѿ��������ɸ��ڵ�
		else
		{
			//�����ҵ����ڵ�
			InfoNode* pCur = pHead->_next;
			while (pCur->_next != nullptr)
			{
				pCur = pCur->_next;
			}
			pCur->_next = newNode;
			newNode->_next = nullptr;
		}
		cout << "�Ƿ����¼��(y/n):";
		cin >> flag;
	}
}

//ͨѶ¼��Ϣ�Ĳ�ѯ
void searchPersonInfoList(InfoNode* pHead)
{
	if (pHead->_next == nullptr)
	{
		cout << "ͨѶ¼Ϊ��,��ѯʧ��!" << endl;
	}
	else
	{
		int select = 0;
		printf("===============\n");
		printf(" 1. ����Ų�ѯ\n");
		printf(" 2. ��������ѯ\n");
		printf("===============\n");
		cout << "��ѡ��: ";
		cin >> select;
		if (select == 1)
		{
			int count = 0;
			string num;
			cout << "��������: ";
			cin >> num;
			//����������ѯ������ı����ͬ����Ϣ
			InfoNode* pCur = pHead->_next;
			printf("���     ����      �Ա�   �绰             ��ַ\n");
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
			printf("------����%d����¼------\n", count);
		}
		if (select == 2)
		{
			int count = 0;
			string name;
			cout << "����������: ";
			cin >> name;
			//����������ѯ������ı����ͬ����Ϣ
			InfoNode* pCur = pHead->_next;
			printf("���     ����      �Ա�   �绰             ��ַ\n");
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
			printf("------����%d����¼------\n", count);
		}
	}
}

//ͨѶ¼��Ϣ���޸�
void modifyPersonInfoList(InfoNode* pHead)
{
	if (pHead->_next == nullptr)
	{
		cout << "ͨѶ¼Ϊ�գ��޸�ʧ��!" << endl;
		return;
	}
	//����������ʹ�ó�����һ�㲻���޸���ϵ�˵������������޸ĵ��ǡ��绰�����ߡ�סַ��
	string name;
	cout << "�����뽫Ҫ�޸ĵ���ϵ������: ";
	cin >> name;
	//����������ѯ�˽ڵ�
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
			printf(" 1. �޸ĵ绰����\n");
			printf(" 2. �޸ļ�ͥסַ\n");
			printf("=================\n");
			cout << "������: ";
			cin >> select;
			if (select == 1)
			{
				string newPhone;
				cout << "�������µĵ绰����:";
				cin >> newPhone;
				pCur->data.phone = newPhone;
			}
			if (select == 2)
			{
				string newAddr;
				cout << "�������µļ�ͥסַ:";
				cin >> newAddr;
				pCur->data.addr = newAddr;
			}
			cout << "-----�޸ĳɹ�-----\n";
			pCur = pCur->_next;
		}
	}
}

//ͨѶ¼��ϵ�˵�ɾ��
void delPersonInfo(InfoNode* pHead)
{
	if (pHead->_next == nullptr)
	{
		cout << "ͨѶ¼Ϊ�գ�ɾ��ʧ��!" << endl;
		return;
	}

	string delName;
	cout << "�����뽫Ҫɾ������ϵ������: ";
	cin >> delName;
	//����������������ڵ�
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
			//�ҵ��������ϵ��
			InfoNode* delNode = pCur;
			pPrev->_next = pCur->_next;
			pCur = pCur->_next;
			delete delNode;
			delNode = nullptr;
			return;
		}
	}
	cout << "-----�ޱ����������-----\n";
}
//ͨѶ¼��������
void printPersonInfoList(InfoNode* pHead)
{
	if (pHead->_next == nullptr)
	{
		cout << "ͨѶ¼Ϊ�գ����ʧ��!" << endl;
	}
	else
	{
		printf("���     ����      �Ա�   �绰             ��ַ\n");
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



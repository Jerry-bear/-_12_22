#include "head.h"

int main()
{
	InfoNode personInfoList;
	int select = 0;
	while (1)
	{
		menu();
		while (1)
		{
			cin >> select;
			if (select <0 || select > 6)
			{
				cout << "输入有误，请重新选择: ";
			}
			else
				break;
		}
		switch (select)
		{
			case 1:
				createPersonInfoList(&personInfoList);
				break;
			case 2:
				insertPersonInfoToList(&personInfoList);
				break;
			case 3:
				searchPersonInfoList(&personInfoList);
				break;
			case 4:
				modifyPersonInfoList(&personInfoList);
				break;
			case 5:
				delPersonInfo(&personInfoList);
				break;
			case 6:
				printPersonInfoList(&personInfoList);
				break;
		}
	}
	system("pause");
	return 0;
}
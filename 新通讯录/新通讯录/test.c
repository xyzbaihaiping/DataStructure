#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"

void menu()
{
	
	printf("|！！！！！！！！！！！！！！！！！！！！！！！|\n");
	printf("|0.exit    ***********************  1.add      |\n");
	printf("|2.delet   ***********************  3.search   |\n");
	printf("|4.modify  ***********************  5.show     |\n");
	printf("|6.clr     ***********************  7.sort     |\n");
	printf("|！！！！！！！！！！！！！！！！！！！！！！！|\n");
}
void test()
{
	Contact my_con;
	init_contact(&my_con);
	int input = 1;
	while (input)
	{
		menu();
		printf("萩僉夲:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add_contact(&my_con);
			break;
		case DELET:
			delet_contact(&my_con);
			break;
		case SEARCH:
			search_contact(&my_con);
			break;
		case MODIFY:
			modify_contact(&my_con);
			break;
		case SHOW:
			show_contact(&my_con);
			break;
		case CLR:
			clr_contact(&my_con);
			break;
		case SORT:
			sort_contact(&my_con);
			break;
		case EXIT:
			exit(0);
			break;
		default:
			break;
		}
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"

static int find_entry(Contact *pcon, const char *find_name)
{
	int i = 0;
	for (i = 0; i < pcon->count; i++)
	{
		if (strcmp(pcon->con[i].name, find_name) == 0)
			return i;
	}
	return -1;
}
static void chack_capacity(Contact *pcon)
{
	assert(pcon);
	if (pcon->count == pcon->capacity)
	{
		if (pcon->capacity + INC_CAPACITY < MAX)
		{
			pcon->con = realloc(pcon->con, (pcon->capacity + INC_CAPACITY)*sizeof(PeoInfor));
			pcon->capacity += INC_CAPACITY;
		}
		else if (pcon->capacity < MAX && (pcon->capacity + INC_CAPACITY)>MAX)
		{
			pcon->con = realloc(pcon->con, MAX * sizeof(PeoInfor));
			pcon->capacity = MAX;
		}
	}
}
void add(Contact *pcon)
{
	PeoInfor Readfile = { 0 };
	FILE *pf = fopen(FILE_NAME, "r");
	if (pf == NULL)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	while (fread(&Readfile, sizeof(PeoInfor), 1, pf))
		{
		if (pcon->count >= MAX)
		{
			printf("电话本已满无法添加!\n");
			return;
		}
		  chack_capacity(pcon);
		  pcon->con[pcon->count] = Readfile;
		  pcon->count++;
		}
	fclose(pf);

}
void save(Contact *pcon)
{
	int i = 0;
	FILE *pf = fopen(FILE_NAME, "w");
	if (pf == NULL)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < pcon->count; i++)
	{
		fwrite(&pcon->con[i], sizeof(PeoInfor), 1, pf);
	}
	fclose(pf);
}
void init_contact(Contact *pcon)
{
	assert(pcon);
	pcon->con = (PeoInfor *)malloc(CAPACITY*sizeof(PeoInfor));
	pcon->count = 0;
	pcon->capacity = CAPACITY;
	add(pcon);

}

void add_contact(Contact *pcon)
{

	    if (pcon->count>=MAX)
	   {
		printf("电话本已满无法添加!\n");
	 	return;
	    }
		chack_capacity(pcon);
		printf("name:>");
		scanf("%s", pcon->con[pcon->count].name);
		printf("age:>");
		scanf("%d", &pcon->con[pcon->count].age);
		printf("sex:>");
		scanf("%s", pcon->con[pcon->count].sex);
		printf("tele:>");
		scanf("%s", pcon->con[pcon->count].tele);
		printf("addr:>");
		scanf("%s", pcon->con[pcon->count].addr);
		pcon->count++;

		printf("添加成功！\n");
	
	

}
void show_contact(Contact *pcon)
{
	int i = 0;
	printf("%10s  %4s  %4s  %12s %12s\n", "name", "age", "sex", "tele", "addr");
	for (i = 0; i < pcon->count; i++)
	{
		printf("%10s  %4d  %4s  %12s %12s\n",
			pcon->con[i].name,
			pcon->con[i].age,
			pcon->con[i].sex,
			pcon->con[i].tele,
			pcon->con[i].addr);
	}
}
void delet_contact(Contact *pcon)
{
	char del_name[MAX_NAME] = { 0 };
	int ret = 0;
	int i = 0;
	char ifdel[5] = { 0 };
	printf("请输入要删除人的姓名:>");
	scanf("%s", del_name);
	ret = find_entry(pcon, del_name);
	if (ret != -1)
	{
		printf("您确定要删除吗?\n");
		printf("yes or no:>");
		scanf("%s", ifdel);
		if (strcmp(ifdel, "yes") == 0)
		{
			for (i = ret; i < pcon->count - 1; i++)
			{
				pcon->con[i] = pcon->con[i + 1];
			}
			printf("删除完成!\n");
			pcon->count--;
		}
		else
			return;
	}
	else
	{
		printf("要删除的人不存在!\n");
		return;
	}


}
void search_contact(Contact *pcon)
{
	char sear_name[MAX_NAME] = { 0 };
	int ret = 0;

	printf("请输入要查找的人的姓名:>");
	scanf("%s", sear_name);
	ret = find_entry(pcon, sear_name);
	if (ret != -1)
	{
		printf("查找成功!\n");
		printf("%10s  %4s  %4s  %12s %12s\n", "name", "age", "sex", "tele", "addr");
		printf("%10s  %4d  %4s  %12s %12s\n",
			pcon->con[ret].name,
			pcon->con[ret].age,
			pcon->con[ret].sex,
			pcon->con[ret].tele,
			pcon->con[ret].addr);

	}
	else
	{
		printf("要查找的人不存在!\n");
		return;
	}
}
void modify_contact(Contact *pcon)
{
	char mod_name[MAX_NAME] = { 0 };
	int ret = 0;
	
	printf("请输入要修改的人的姓名:>");
	scanf("%s", mod_name);
	ret = find_entry(pcon, mod_name);
	if (ret != -1)
	{
		printf("name:>");
		scanf("%s", pcon->con[ret].name);
		printf("age:>");
		scanf("%d", &pcon->con[ret].age);
		printf("sex:>");
		scanf("%s", pcon->con[ret].sex);
		printf("tele:>");
		scanf("%s", pcon->con[ret].tele);
		printf("addr:>");
		scanf("%s", pcon->con[ret].addr);
	}
	else
	{
		printf("要修改的人不存在!\n");
		return;
	}
}
void clr_contact(Contact *pcon)
{
	pcon->count = 0;
	printf("已清空联系人!\n");
}
void sort_contact(Contact *pcon)
{
	int i = 0;
	int j = 0;
	PeoInfor tmp = { 0 };
	int flag = 0;

	for (i = 0; i < pcon->count - 1; i++)
	{
		flag = 0;
		for (j = 0; j < pcon->count - i - 1; j++)
		{
			if (strcmp(pcon->con[j].name, pcon->con[j + 1].name)>0)
			{
				tmp = pcon->con[j];
				pcon->con[j] = pcon->con[j + 1];
				pcon->con[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
	printf("排序完成!\n");

}
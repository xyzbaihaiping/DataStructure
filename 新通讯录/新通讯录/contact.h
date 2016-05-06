
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME 20
#define MAX_SEX 4
#define MAX_TELE 12
#define MAX_ADDR 20
#define MAX 1000

typedef struct PeoInfor
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfor;

typedef struct Contact
{
	PeoInfor con[MAX];
	int count;
}Contact;

enum OP
{
	EXIT,
	ADD,
	DELET,
	SEARCH,
	MODIFY,
	SHOW,
	CLR,
	SORT
};

void init_contact(Contact *pcon);
void add_contact(Contact *pcon);
void show_contact(Contact *pcon);
void delet_contact(Contact *pcon);
void search_contact(Contact *pcon);
void modify_contact(Contact *pcon);
void clr_contact(Contact *pcon);
void sort_contact(Contact *pcon);

#endif
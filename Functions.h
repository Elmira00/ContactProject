#pragma once
#include<iostream>
#include"Entities.h"
using namespace std;
#include<Windows.h>
void mysetcolor(int fg, int bg) {
 HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(h, fg | (bg << 4));
}

void ShowHuman(const Human& human) {
	mysetcolor(3, 0);
	cout << "Name : " << human.name << endl;
	mysetcolor(7, 0);
	cout << "Phone : " << human.phone << endl;
	cout << "Created Date : " << human.createdDate << endl;
}

void ShowAll(const Contact& contact) {
	for (size_t i = 0; i < contact.count; i++)
	{
		ShowHuman(*contact.humans[i]);
	}
}

Human* GetNewHuman() {
	cin.ignore();
	cin.clear();
	cout << "Enter Name : " << endl;
	char* name = new char[100]{};
	cin.getline(name, 100);
	cout << "Enter phone : " << endl;
	char* phone = new char[100]{};
	cin.getline(phone, 100);

	Human* human = new Human{ name,phone,__DATE__ };
	return human;
}


void AddNewHuman(Contact& contact, const Human& human) {
	int count = contact.count;
	auto newhumans = new Human*[count + 1]{};
	for (size_t i = 0; i < count; i++)
	{
		newhumans[i] = contact.humans[i];
	}
	newhumans[count] = new Human{ human };
	contact.humans = newhumans;
	newhumans = NULL;
	contact.count++;
	cout << "New contact added succesfully" << endl;

}

void SortAToZ(Contact& contact, bool reverse = false) {
	int data = 1;
	if (reverse) {
		data = -1;
	}

	for (size_t i = 0; i < contact.count-1; i++)
	{
		for (size_t k = 0; k < contact.count-i-1; k++)
		{
			if (strcmp(contact.humans[k]->name, contact.humans[k + 1]->name) == data) {
				auto temp = contact.humans[k];
				contact.humans[k] = contact.humans[k + 1];
				contact.humans[k + 1] = temp;
			}
		}
	}
}
int GetIndexByName( char*& name, Contact& contact) {
	for (size_t i = 0; i < contact.count; i++) {
		if (strcmp(contact.humans[i]->name, name) == 0) {
			return i;
		}
	}
	return -1;
}
void DeleteContact(Contact&contact,char*name) {
	int index = GetIndexByName(name, contact);
	if (index != -1) {
		int index_i = 0;
		Human** newHumans = new Human * [contact.count - 1];
		for (size_t i = 0; i < index; i++) {
			newHumans[index_i++] = contact.humans[i];
		}
		for (size_t i = index + 1; i < contact.count; i++) {
			newHumans[index_i++] = contact.humans[i];
		}
		if (contact.humans[index] != NULL) {
			delete[]contact.humans[index];
		}
		contact.humans = newHumans;
		newHumans = NULL;
		contact.count -= 1;
		mysetcolor(10, 0);
	cout << "The contact was deleted" << endl;
	mysetcolor(7, 0);
	}
	else {
		mysetcolor(4, 0);
		cout << "There is no contact with this name " << endl;
		mysetcolor(7, 0);
	}
	
}
int GetAsciiSum(char* text) {
	int sum = 0;
	for (size_t i = 0; i < strlen(text); i++) {
		sum += int(text[i]);
	}
	return sum;
}
Human* Search(Contact& contact,char*name) {
	int length_name= strlen(name);//1  A
	int name_ascii_sum = GetAsciiSum(name);//65
	for (size_t i = 0; i < contact.count; i++) {
		auto name_compare= contact.humans[i]->name;//elnur
		int all= GetAsciiSum(name_compare);
		int piece = GetAsciiSum(&name_compare[length_name]);		
		if (all - piece == name_ascii_sum) {
			return contact.humans[i];
		}
	}
	return NULL;
}
void SearchName(Contact& contact, char* name) {
	if (Search(contact, name) != NULL) {
		auto contact_main = Search(contact, name);
		ShowHuman(*contact_main);
	}
	else {
		mysetcolor(4, 0);
		cout << "There is no contact with this name " << endl;
		mysetcolor(7, 0);
	}
}
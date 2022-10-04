#pragma once


#include<iostream>
#include "Entities.h"
#include "Functions.h"

using namespace std;

void ShowMenu() {
	cout << "Show All Contacts [1]" << endl;
	cout << "Add New Contact [2]" << endl;
	cout << "Delete Contact [3]" << endl;
	cout << "Search Contact [4]" << endl;
	cout << "Show Contact A-Z [5]" << endl;
	cout << "Show Contact Z-A [6]" << endl;
}


void Start() {

	Human* h1 = new Human{
		new char[] {"Elnur"},
		new char[] {"+994558556595"},
		__DATE__
	};

	Human* h2 = new Human{
	new char[] {"Aydin"},
	new char[] {"+994558532595"},
	__DATE__
	};

	Human* h3 = new Human{
	new char[] {"Aysel"},
	new char[] {"+994558556595"},
	__DATE__
	};
	Human* h4 = new Human{
	new char[] {"Leyla"},
	new char[] {"+994558556595"},
	__DATE__
	};


	auto humans = new Human * [] {h1, h2, h3, h4};
	Contact* contact = new Contact{ humans,4 };


	while (true)
	{
		ShowMenu();
		int select = 0;
		cin >> select;
		system("cls");
		if (select == 1) {
			ShowAll(*contact);
		}
		else if (select == 2) {
			auto newhuman = GetNewHuman();
			AddNewHuman(*contact, *newhuman);
		}
		else if (select == 3) {
			cin.ignore();
			cin.clear();
			cout << "enter contact name to delete : ";
			char* name = new char[100] {};
			cin.getline(name, 100);
			DeleteContact(*contact, name);
		}
		else if (select == 4) {
			cin.ignore();
			cin.clear();
			cout << "enter contact name : ";
			char* name = new char[100] {};
			cin.getline(name, 100);
			SearchName(*contact, name);
		}
		else if (select == 5) {
			SortAToZ(*contact);
			ShowAll(*contact);
		}
		else if (select == 6) {
			SortAToZ(*contact, true);
			ShowAll(*contact);
		}
	}

}
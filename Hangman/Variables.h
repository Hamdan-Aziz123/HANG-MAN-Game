#pragma once
#include <fstream>
#include <iostream>
#include <conio.h>//getch
#include <cstdlib>//rand and srand
#include <ctime>//setting of srand
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include "msclr/marshal_cppstd.h"
	//ofstream write;
	//ifstream read;
using std::string;
using System::String;
using msclr::interop::marshal_as;
//using namespace std;
string Stos(String^ temp) {
	return marshal_as<string>(temp);
}

String^ stoS(string temp) {
	return marshal_as<String^>(temp);
}
	bool save;
	char wtype[50];
	char guess;
	int d;
	int check=0;
	int mistakes = 0;
	char entries[50];
	int j = 0;
	int choose_array = rand() % 3;
	int size = 0;
	int count = 0;
	//srand(time(0));
	int random = rand();
	string hangman[10] = { "H","HA","HAN" ,"HANG" ,"HANGM" ,"HANGMA" ,"HANGMAN" };
	char unknown[50], working[50];//put answer in unknown, put ------ ----- in working
	string alphabets[26] = {"A","B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T","U","V","W","X","Y","Z" };
	char month[12][20] = { "january","february","march","april","may","june","july","august","september","october","november","december" };
	char day[7][20] = { "monday","tuesday","wednesday","thursday","friday","saturday","sunday" };
	char fruit[10][20] = { "apple","banana","strawberry","mango","peach","orange","pineapple","tomato","grapes","pear" };
	//char truth[3][50] = { "I love PF","Hira Ilyas is best PF teacher","Hira Ilyas for Prime minister" };

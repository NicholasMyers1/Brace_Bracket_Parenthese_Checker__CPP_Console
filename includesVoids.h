#ifndef INCLUDESVOIDS_H
#define INCLUDESVOIDS_H
	#include <iostream>
	#include <fstream>
	#include <algorithm>
	#include <cstdlib>
	#include <stack>
	#include <vector>
	#include <deque>
	using namespace std;/*	-lAdvApi32	-lwinmm	*/
	//VOIDS: 
		//INIT.cpp:
			void INIT();
		//MAIN.cpp: 
			int main(int argc,char **argv);
		//READ_WRITE.cpp: 
			void CHECK_IF_FILE_EXISTS(string file);	void READ_FILE(string file); void CHECK_EXTENSION(string file);
		//KEYBOARD_INPUT.cpp: 
			string KEY_INPUT();
		//FILE_ERROR_CHECKER.cpp: 
			void FILE_ERROR_CHECKER(int n);
	//STRUCTURES:
		struct _KNOWN_EXTENSIONS{	string type,extensions;};	extern _KNOWN_EXTENSIONS Types[4];
		struct _FILES{	bool fileExists;	ifstream readFile_;	ofstream writeFile_;	string fileData,fileExtension;	int languageType;};extern _FILES FILES;
		struct _FILE_CHECKER{
			char brace[2];		int braceCountTotal[2],			braceCountCurrent[2];//open,close;
			char bracket[2];	int bracketCountTotal[2],		bracketCountCurrent[2];//open,close;
			char parenthese[2];	int parentheseCountTotal[2],	parentheseCountCurrent[2];//open,close;
		};extern _FILE_CHECKER FILECHECKER;
		struct _RETURN{string returnString, input, output;};extern _RETURN RETURN;
		struct _WINDOW{int mode;};extern _WINDOW WINDOW;//WINDOW STUFF;
#endif

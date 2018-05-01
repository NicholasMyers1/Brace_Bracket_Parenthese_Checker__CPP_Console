#include "includesVoids.h"
string KEY_INPUT(){		char* line=new char[255];	string afterInput="\0";//get the input from the user;

	//get user input: 
	cin.getline(line,255),afterInput=line;//get input until user hits the enter key;

	//switch the window mode: 
	switch(WINDOW.mode){//switch the window mode; mode 0: input file name; mode 1: choose the language if necessary;
		case 0:	for(int n=0;n<afterInput.length();n++){//input file name;
					if(afterInput[n]=='*'||afterInput[n]=='?'||afterInput[n]=='<'||afterInput[n]=='>'||afterInput[n]=='\"'||afterInput[n]=='|'){afterInput.erase(n,1),n-=1;}//erase?;
				}WINDOW.mode=1;break;//set the window mode to 1 and break;

		case 1: if(afterInput=="-1"){INIT();}//reset and enter another iteration of the code;
				else if(afterInput.length()==1){//find out if the input was a string equal to 0, 1, 2, or 3;
					for(int n=0;n</*extensionTypesArraySize*/4;n++){if(afterInput[0]==char(n+48)){FILES.languageType=n,WINDOW.mode=2;	break;}}//find if the language input is valid;
				}break;//break;
	}return(afterInput);//return the modified input;
}//end void;

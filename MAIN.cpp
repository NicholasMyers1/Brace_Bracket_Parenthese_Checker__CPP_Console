#include "includesVoids.h"
int main(int argc,char **argv){//main and set window properties;

	while(1){system("CLS");INIT();//reset the code each iteration; while(1) means the program won't exit;



stack<int>test;
cout<<"test:"<<test.size()<<"\n";






	
		//cout the text so the user knows what to do: 
		cout<<RETURN.output<<"Drag in a file, or enter a file's full file path, name and its extension.\n"<<RETURN.output<<"(ex: \"C:\\users\\%USERNAME%\\desktop\\test.cpp\")\n";
		cout<<RETURN.input<<"File:\t\t";RETURN.returnString=KEY_INPUT();//get file input from user;
		
		//check if the user input is valid and find the syntax errors: 
		CHECK_IF_FILE_EXISTS(RETURN.returnString);//check file;check if it exists and not empty, get extension, read file;
		if(FILES.languageType==-1&&WINDOW.mode==1){do{cout<<RETURN.input<<"Language:\t";RETURN.returnString=KEY_INPUT();}while(WINDOW.mode==1);}//enter lang if not known;
		if(FILES.languageType!=-1)FILE_ERROR_CHECKER(FILES.languageType);//check the file for syntax errors;
		
		//at the end of the loop, pause the system to allow the user to see everything displayed until a key is pressed:
		cout<<RETURN.output;system("PAUSE");	
	}return 0;
}//end void;

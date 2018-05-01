#include "includesVoids.h"
void CHECK_IF_FILE_EXISTS(string file){	string lineData="\0";

	//check if the file is null, exists, doesn't exist, etc: 
	FILES.readFile_.open(file);
	getline(FILES.readFile_,lineData);
		if(!FILES.readFile_){FILES.readFile_.close();cout<<RETURN.output<<"Exists?\t\tIf it does, the file is empty, null, a folder, or it's being edited currently.\n";INIT();}//file does not exist;
		else{FILES.readFile_.close(),FILES.fileExists=true,CHECK_EXTENSION(file);}//find out the extension, then read the file if it exists;
}//end void;
void CHECK_EXTENSION(string file){		cout<<RETURN.output<<"Exists?\t\tYes\n";

	//find the extension of the file: ex: .exe,.txt,.cpp,.java, etc: 
	for(int n=file.length()-1;n>-1;n--){//find extension: 
		if(file[n]>64&&file[n]<91)file[n]+=32;//convert to lowercase:
		if(file[(n)]=='.')break;
		else FILES.fileExtension+=file[n];
	}reverse(FILES.fileExtension.begin(),FILES.fileExtension.end());//reverse the string to a be read correctly;
	cout<<RETURN.output<<"Extension:\t"<<FILES.fileExtension<<"\n";
	
	//get the extension from the string and find if it is a known extension for this program specifically: 
	string getExtension="\0";
	for(int n=0;n</*extensionTypesArraySize*/4;n++){//check if known extension: 
		for(int m=0;m<Types[n].extensions.length();m++){
			if(Types[n].extensions[m]!=','&&Types[n].extensions[m]!='\n')getExtension+=Types[n].extensions[m];
			if(getExtension==FILES.fileExtension&&Types[n].extensions[m]==','||getExtension==FILES.fileExtension&&Types[n].extensions[m]=='\n'){
				if(FILES.languageType==-1){FILES.languageType=n,cout<<RETURN.output<<"Language:\t"<<Types[n].type;}
				else{cout<<", "<<Types[n].type;}break;
			}
			else if(Types[n].extensions[m]==',')getExtension="\0";
		}getExtension="\0";
	}
	
	//output whether if this extension is of a known type for this program or not": 
	if(FILES.languageType==-1){
		cout<<RETURN.output<<"This file type is not associated with an existing language.\n"<<RETURN.output<<"Available languages:\n"<<RETURN.output<<"\t(-1):Not listed\n";
		for(int n=0;n</*extensionTypesArraySize*/4;n++){cout<<RETURN.output<<"\t("<<char(n+48)<<"): "<<Types[n].type<<"\n";}
	}
	else{cout<<"\n";}
	
	//read the file" 
	READ_FILE(file);
}//end void;
void READ_FILE(string file){			string lineData="\0";

	//read the file and save each line of the file: 
	FILES.fileData="\0";
	FILES.readFile_.open(file);
		while(!FILES.readFile_.eof()){getline(FILES.readFile_,lineData),FILES.fileData+=lineData+"\n";}
	FILES.readFile_.close();
}//end void;

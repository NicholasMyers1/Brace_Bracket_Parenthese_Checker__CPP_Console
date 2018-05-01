#include "includesVoids.h"
void INIT(){					system("title SYNTAX ERROR CHECKER");//title;

		Types[0].type="C",		Types[0].extensions="c,h\n",	Types[1].type="CPlusPlus",	Types[1].extensions="cpp,h\n";//_KNOWN_EXTENSIONS:
		Types[2].type="CSharp",	Types[2].extensions="cs,\n",	Types[3].type="Java",		Types[3].extensions="class,java\n";//_KNOWN_EXTENSIONS:
	//_FILES: 
		FILES.fileExists=false,	FILES.fileData="\0",			FILES.fileExtension="\0",	FILES.languageType=-1;
	//_FILE_CHECKER: 
		for(int n=0;n<2;n++){
			FILECHECKER.braceCountTotal[n]=0,	FILECHECKER.bracketCountTotal[n]=0,		FILECHECKER.parentheseCountTotal[n]=0;
			FILECHECKER.braceCountCurrent[n]=0,	FILECHECKER.bracketCountCurrent[n]=0,	FILECHECKER.parentheseCountCurrent[n]=0;			
		}
		FILECHECKER.brace[0]='{',FILECHECKER.brace[1]='}',	FILECHECKER.bracket[0]='[',FILECHECKER.bracket[1]=']',	FILECHECKER.parenthese[0]='(',FILECHECKER.parenthese[1]=')';
	//_RETURN: 
		RETURN.returnString="\0",	RETURN.input=">",		RETURN.output="*\t\t";
	//WINDOW: 
		WINDOW.mode=0;
}//end void; 

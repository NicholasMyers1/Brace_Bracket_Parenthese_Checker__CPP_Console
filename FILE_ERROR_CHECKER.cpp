#include "includesVoids.h"
void FILE_ERROR_CHECKER(int n){int lineNumber=0;//n is the language;find the errors in the file: 

	//switch the language: 
	bool ignoreCommentLines=false,ignoreCommentLinesMultiple=false,ignoreQuote=false,ignoreQuoteMultiple=false;
	string includeLine="\0";
	switch(n){
		case 0:case 1:case 2:case 3: //case 0 or case 1: added in 2 and 3 for now because haven't coded other language syntax yet;
			//currently check: {,}, [,], (,);
				for(int m=0;m<FILES.fileData.length();m++){
					string x;x=FILES.fileData[m];
					if(includeLine!="#include")includeLine.insert(includeLine.length(),x);
					
					//ignore everything in a /* */: 
					if(ignoreQuote==false&&ignoreCommentLinesMultiple==false&&ignoreQuoteMultiple==false){
						if(ignoreCommentLinesMultiple==false){
							if(FILES.fileData[m]=='/'&&FILES.fileData[m+1]=='/'&&ignoreCommentLines==false){ignoreCommentLines=true;/*cout<<"start// "<<lineNumber+1<<" ";*/}
							else if(FILES.fileData[m]=='\n'&&ignoreCommentLines==true){ignoreCommentLines=false;/*cout<<"end\\n "<<lineNumber+1<<"\n";*/}
						}
					}
					
					//ignore everything in a //: 
					if(ignoreQuote==false&&ignoreCommentLines==false&&ignoreQuoteMultiple==false){
						if(FILES.fileData[m-1]=='/'&&FILES.fileData[m]=='*'&&ignoreCommentLinesMultiple==false){ignoreCommentLinesMultiple=true;/*cout<<"start/* "<<lineNumber+1<<" ";*/}
						else if(FILES.fileData[m-1]=='*'&&FILES.fileData[m]=='/'&&ignoreCommentLinesMultiple==true){ignoreCommentLinesMultiple=false;/*cout<<"end*//* "<<lineNumber+1<<"\n";*/}
					}
					
					//find all end points of a string and ignore anything inside it: 
					if(ignoreCommentLines==false&&ignoreCommentLinesMultiple==false&&ignoreQuoteMultiple==false){
						if(FILES.fileData[m]=='"'&&ignoreQuote==false){ignoreQuote=true;/*cout<<"start\" "<<lineNumber+1<<" ";*/}
						else if(FILES.fileData[m-1]!='\\'&&FILES.fileData[m]=='"'){ignoreQuote=false;includeLine="\0";/*cout<<"endquote"<<lineNumber+1<<"\n";*/}
					}
					
					//find all end points of a char and ignore anything inside it: 
					if(ignoreQuote==false&&ignoreCommentLines==false&&ignoreCommentLinesMultiple==false){
						if(FILES.fileData[m]=='\''&&ignoreQuoteMultiple==false){ignoreQuoteMultiple=true;/*cout<<"start\' "<<lineNumber+1<<" ";*/}
						else if(FILES.fileData[m-1]!='\\'&&FILES.fileData[m]=='\''||
								FILES.fileData[m-2]=='\\'&&FILES.fileData[m-1]=='\\'&&FILES.fileData[m]=='\''		
						){ignoreQuoteMultiple=false;/*cout<<"end\' "<<lineNumber+1<<" ";*/}
					}
					
					
					//add to the count for {,}, [,], (,): 
					if(ignoreCommentLines==false&&ignoreQuote==false&&ignoreCommentLinesMultiple==false&&ignoreQuoteMultiple==false){
						if(FILES.fileData[m]==FILECHECKER.brace[0]){				FILECHECKER.braceCountTotal[0]+=1;}//FILECHECKER.braceCountCurrent[0]+=1;
							else if(FILES.fileData[m]==FILECHECKER.brace[1]){		FILECHECKER.braceCountTotal[1]+=1;}//FILECHECKER.braceCountCurrent[1]+=1;
						if(FILES.fileData[m]==FILECHECKER.bracket[0]){				FILECHECKER.bracketCountTotal[0]+=1;}//FILECHECKER.bracketCountCurrent[0]+=1;
							else if(FILES.fileData[m]==FILECHECKER.bracket[1]){		FILECHECKER.bracketCountTotal[1]+=1;}//FILECHECKER.bracketCountCurrent[1]+=1;
						if(FILES.fileData[m]==FILECHECKER.parenthese[0]){			FILECHECKER.parentheseCountTotal[0]+=1;}//FILECHECKER.parentheseCountCurrent[0]+=1;
							else if(FILES.fileData[m]==FILECHECKER.parenthese[1]){	FILECHECKER.parentheseCountTotal[1]+=1;}//FILECHECKER.parentheseCountCurrent[0]+=1;
					}
					if(FILES.fileData[m]=='\n'){lineNumber+=1;}
				}
			//if errors don't exist: else if errors do exist: 
			if(FILECHECKER.braceCountTotal[0]==FILECHECKER.braceCountTotal[1]&&FILECHECKER.bracketCountTotal[0]==FILECHECKER.bracketCountTotal[1]&&FILECHECKER.parentheseCountTotal[0]==FILECHECKER.parentheseCountTotal[1])cout<<RETURN.output<<"There are no {}, [], () errors in your programming file!\n";
			else{cout<<RETURN.output<<"{}, [], () errors exist in your programming file!\n";
				//if the number of {}[]() is not equal to the number of{}[]()
				if(FILECHECKER.braceCountTotal[0]>FILECHECKER.braceCountTotal[1])						cout<<RETURN.output<<"\t"<<FILECHECKER.braceCountTotal[0]-FILECHECKER.braceCountTotal[1]<<" (end braces) '}' are missing.\n";//cout<<RETURN.output<<"\tA '}' is missing.\n";
					else if(FILECHECKER.braceCountTotal[0]<FILECHECKER.braceCountTotal[1])				cout<<RETURN.output<<"\t"<<FILECHECKER.braceCountTotal[1]-FILECHECKER.braceCountTotal[0]<<" (open braces) '{' are missing.\n";//cout<<RETURN.output<<"\tA '{' is missing.\n";
				if(FILECHECKER.bracketCountTotal[0]>FILECHECKER.bracketCountTotal[1])					cout<<RETURN.output<<"\t"<<FILECHECKER.bracketCountTotal[0]-FILECHECKER.bracketCountTotal[1]<<" (end brackets) ']' are missing.\n";//cout<<RETURN.output<<"\tA ']' is missing.\n";
					else if(FILECHECKER.bracketCountTotal[0]<FILECHECKER.bracketCountTotal[1])			cout<<RETURN.output<<"\t"<<FILECHECKER.bracketCountTotal[1]-FILECHECKER.bracketCountTotal[0]<<" (open brackets) '[' are missing.\n";//cout<<RETURN.output<<"\tA '[' is missing.\n";
				if(FILECHECKER.parentheseCountTotal[0]>FILECHECKER.parentheseCountTotal[1])				cout<<RETURN.output<<"\t"<<FILECHECKER.parentheseCountTotal[0]-FILECHECKER.parentheseCountTotal[1]<<" (end parenthese) ')' are missing.\n";//cout<<RETURN.output<<"\tA ')' is missing.\n";
					else if(FILECHECKER.parentheseCountTotal[0]<FILECHECKER.parentheseCountTotal[1])	cout<<RETURN.output<<"\t"<<FILECHECKER.parentheseCountTotal[1]-FILECHECKER.parentheseCountTotal[0]<<" (open parenthese) '(' are missing.\n";//cout<<RETURN.output<<"\tA '(' is missing.\n";
			}break;
	}
}//end void;

#include <iostream>

#ifndef H_IFDPARSER
#define H_IFDPARSER
  #include "IFDParser.h"
#endif // H_IFDPARSER



IFDParser::IFDParser()
{
    pos = 0;
    cout<<"Enter your gamefile name (i.e. filename.txt)"<<endl;
    getline(cin,gameFile);
}

void IFDParser::tokenIt()
{
    string token="";
    string nextLine;
    char c;

    ifstream inFile;
    inFile.open(gameFile.c_str());


    while(!inFile.eof()){
        getline(inFile, nextLine);
        trim(nextLine);
        c=nextLine[0];

        //dump any comment or blank line (all comments exist alone on their lines)
        if(c=='%' || nextLine == ""){
            //do nothing
        }
        else{
            //tokenize the entire line
            //cout<<nextLine<<endl;
            for(int i=0; i<nextLine.length(); i++){
                if(nextLine[i] == '>'){
                    token = token + nextLine[i];
                    if(token !="\n" && token !="" && token !=" " && token !="\t"){
                        tokenVec.push_back(token);
                    }
                    token = "";
                }
                else if(nextLine[i]=='<'){
                    if(token !="\n" && token !="" && token !=" " && token !="\t"){
                        tokenVec.push_back(token);
                    }
                    token = "";
                    token = token + nextLine[i];
                }
                else{
                    token = token + nextLine[i];
                }
            }
        }
    }//while !eof
    inFile.close();
    return;
}// end of tokenIt()

void IFDParser::eatToken()
{
    pos++;
}

string IFDParser::getNext(){
    return tokenVec[pos];
}

//helper function for trimming a string's white space
void IFDParser::trim(string& s)
{
    size_t p = s.find_first_not_of(" \t");
    s.erase(0, p);
    p = s.find_last_not_of(" \t");
    if (string::npos != p)
    {
        s.erase(p+1);
    }
}

void IFDParser::printTokens()
{
    cout<<":::Printing the Tokens in Order:::"<<endl;
    for(int i=0; i<tokenVec.size(); i++){
        cout<<i<<": "<<tokenVec[i]<<endl;
    }
}

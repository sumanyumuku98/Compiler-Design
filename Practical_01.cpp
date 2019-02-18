#include<iostream>
#include<fstream>
#include<string>
#include<regex>
using namespace std;

void detect_comments(string file){
    
    ifstream infile;
    infile.open(file);
    string line;
    string s;
    //Regex for single line comment
    regex a("//(.*)");
    //Regex for multi line comment
    regex b("/\\*.*?\\*/");
     smatch m,ml;
    while(getline(infile,line)){
        
        s+=" ";
        s+=line;
        
        if(regex_search(line,m,a)==true){
            cout<<"Single Line Comment: ";
            cout<<m.str(1)<<endl;
        }
      
      }
    if(regex_search(s,ml,b)==true){
        for(auto x: ml){
        cout<<"Multi Line Comment: ";
        cout<<x<<endl;
        }}
    
    infile.close();
    
}

int main(){
    string path = ""; //File PATH
    detect_comments(path);
    return 0;
}


#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
//#include <fstream>
#include "nfa.h"


using namespace std;

int main(int argc, char *argv[])
{
    char usage[]=
    "Compilador version 0.001ALPHA1\t    Copyright (c) 2009 Andre Luis da Cunha\n\nUsage:     compilador <command>\n<Commands>\n-f <file>\t     Open <file>\n";
    bool flag=false;
    char *file_name;
	//simulating parameters
	file_name="teste.txt";/*
	//parsing parameters
    
	if (argc>1){
        bool is_ok=true;
        while(is_ok){
            int j=1;
            char *aux =argv[j];
            char param;
            if (aux[0]=='-')
                param=aux[1];
            else {is_ok=false;}
            switch(param){
                case 'f':			if((!strcmp(aux,"-f"))&&argc>(j+1)){
										flag=1;
										file_name=argv[++j];
										break;
									}

                case 'h':			cout<< "-h\n"<<usage;
									break;
				
                default:			char msg[]=": wrong parameter\n";
									char tmp[strlen(msg)+strlen(usage)+2];
									strcat(tmp,aux);
									strcat(tmp,msg);
									cout << tmp;

            }
            if (j<(argc-1))
                j++;
            else{is_ok=false;}
        }
    }
    if (!flag){
        cout << usage << endl;
        return 0;
    }//*/
	//Put your code here
    //cout << "\nExecutando programa!\n"<<endl;
    //cout<<"Abrindo "<<file_name<<"!"<<endl;
	
	Cnfa my_nfa;
	my_nfa.set_file(file_name);
	my_nfa.~Cnfa();/**/
	return 0;
}

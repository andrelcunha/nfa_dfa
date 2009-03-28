#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
    char usage[]=
    "Compilador version 0.001ALPHA1\t    Copyright (c) 2009 Andre Luis da Cunha\n\nUsage:     compilador <command>\n<Commands>\n-f <file>\t     Open <file>";
    bool flag=false;
    char *file_name;
	//simulating parameters
	//argc=2;
	
	
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
                case 'f':          if((!strcmp(aux,"-f"))&&argc>(j+1)){
                                   flag=1;
                                   file_name=argv[++j];
                                   cout<<file_name<<endl;
                                   break;
                                   }

                case 'h':          cout<< "-h\n"<<usage;
                default:           char msg[]=": wrong parameter\n";
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
    }
	//Put your code here 
    cout << "\nExecutando programa!\n"<<endl;
    return 0;
}

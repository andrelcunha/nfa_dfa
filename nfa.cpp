/*
 *  nfa.cpp
 *  nfa_dfa
 *
 *  Created by Andre Luis da Cunha on 28/03/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "nfa.h"

using namespace std;
Cnfa::~Cnfa(){
	delete [] alphabet;
	alphabet = NULL;
}
//--------------------------------------------------------------------------------------
int Cnfa::get_stateN(){
	return stateN;
}
//--------------------------------------------------------------------------------------
void Cnfa::set_stateN(int value){
	stateN=value;
}
//--------------------------------------------------------------------------------------
int Cnfa::get_alphabetN(){
	return alphabetN;
}
//--------------------------------------------------------------------------------------
void Cnfa::set_alphabetN(int value){
	alphabetN=value;
}
//--------------------------------------------------------------------------------------
int Cnfa::set_file(char *filename){
	set_buffer(filename);
	parse_file();
	return 0;
}
//--------------------------------------------------------------------------------------
void Cnfa::set_buffer(char *filename){
	ifstream infile;
	infile.open(filename, ios::in);
	string line;
	while ( getline( infile , line) ) {
		buffer.push_back(line);
		
	}
}
//--------------------------------------------------------------------------------------
void Cnfa::parse_file(){
	int lines=buffer.size();
	int i,j,cnt;
	cout << "number of lines: "<<lines<<endl;
	string temp;
	//getting number of states
	temp=buffer[0];
	set_stateN(atoi( temp.c_str()));
	cout <<"number of states: "<< get_stateN()<<endl;
	temp.clear();
	temp=buffer[1];
	int ab_aux=temp.size(); 
	int ab_counter=0;
	for (i=0; i<ab_aux; i++) {
		if(temp[i]!=' '){
			ab_counter++;
		}
	}
	set_alphabetN(ab_counter);
	cout <<"number of elements in alphabet: "<< get_alphabetN()<<endl;
	alphabet = new char [ab_counter];
	j=0;
	for (i=0; i<ab_aux; i++) {
		if(temp[i]!=' '){
			alphabet[j++]=temp[i];
		}
	}
	cout <<"Alphabet: ";
	for  (i=0; i<ab_counter; i++){
		if (i != 0)
			cout <<", ";
		cout <<"{" <<alphabet[i]<<"}";
	}
	cout<<"\n";
	//extracting initial state
	temp.clear();
	temp=buffer[2];
	strcpy(initial_S,temp.c_str());
	cout<<"Initial state: "<<initial_S<<endl;
	//extracting final state(s)
	temp.clear();
	temp=buffer[3];
	int fi_s_aux=temp.size(); 
	int fi_s_counter=0;
	for (i=0; i<fi_s_aux; i++) {
		if(temp[i]=='S'){
			fi_s_counter++;
		}
	}
	cout <<"number of final states: "<<fi_s_counter <<endl;
	cnt=0; //counts state character, like s0, s1, s3223423 and so on. 
	string aux;
	for (i=0; i<fi_s_aux; i++){
		
		if(temp[i]!=' '){
			aux[cnt]=temp[i];
			cnt++;
		}
		if((temp[i]==' ')||(temp[i]=='\n')){
			if(i!=0){
				final_S.push_back(aux);
				aux.clear();
			}
			cnt=0;
		}
	}
	for(i=0; i<fi_s_counter; i++){
		if (i != 0)
			cout <<", ";
		cout<<"Final state(s): "<<final_S[i]<<endl;
	}/*
	//creating 3d vector of strings to keep node links
	vector <vector<vector<string> > > node; //line(alphabetN) x colluns() x deep
	cnt=0;
	for(i=0;i<alphabetN;i++){ //alphabet elements level
		node.push_back(vector<vector<string> > ());//new line
		string aux;
		int x=0; //"while" control
		temp.clear();
		temp=buffer[(i+4)]; //the vector start is 0 but the data in the file starts in the 5th line.
		for(j=0;j<stateN;j++){ //input state level
			node[i].push_back(vector<string> ()); //new collun
			while(x<temp.size()){
				if((temp[x]!=' ')&&(temp[x]!=',')){
					aux[cnt]=temp[x];
					cnt++;
					//if 
				}
				if(temp[x]!=','){
					cnt=0;
				}
				if(temp[x]!=' '){
					node[i][j].push_back(aux);
					aux.clear();
					cnt=0;
					break;
				}
				x++;
			}
		}
	}
	for( i=0;i<node.size();i++)
		for(j=0;j<node[i].size();j++)
			for(unsigned int k=0;k<node[i][j].size();k++)
				std::cout<<"Node "<<i<<" "<<j<<" "<<k<<" == "<<node[i][j][k]<<std::endl;
	 */
}
//--------------------------------------------------------------------------------------

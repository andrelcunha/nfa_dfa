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
	for (int i=0; i<ab_aux; i++) {
		if(temp[i]!=' '){
			ab_counter++;
		}
	}
	set_alphabetN(ab_counter);
	cout <<"number of elements in alphabet: "<< get_alphabetN()<<endl;
	alphabet = new char [ab_counter];
	int j=0;
	for (int i=0; i<ab_aux; i++) {
		if(temp[i]!=' '){
			alphabet[j++]=temp[i];
		}
	}
	cout <<"Alphabet: ";
	for  (int i=0; i<ab_counter; i++){
		if (i != 0)
			cout <<", ";
		cout <<"{" <<alphabet[i]<<"}";
	}
	cout<<"\n";
}
//--------------------------------------------------------------------------------------

/*
 *  nfa.h
 *  nfa_dfa
 *
 *  Created by Andre Luis da Cunha on 28/03/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Cnfa{
	public:
	Cnfa(){};
	~Cnfa();
	int get_stateN();
	void set_stateN(int);
	int get_alphabetN();
	void set_alphabetN(int);
	int set_file(char *);
	
	
	private:
	int stateN;
	int alphabetN;
	char *alphabet; 
	char initial_S[2];
	vector<string> final_S;
	vector<string> buffer;
	void set_buffer(char *);
	void parse_file();
	
};

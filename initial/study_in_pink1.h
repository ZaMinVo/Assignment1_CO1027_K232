/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2023
* Author: Vu Van Tien
* Date: 02.02.2023
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef _H_STUDY_IN_PINK_1_H_
#define _H_STUDY_IN_PINK_1_H_

#include "main.h"

bool readFile( const string & filename, int & HP1, int & HP2, int & EXP1, int & EXP2, int & M1, int & M2, int & E1, int & E2, int & E3);

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

void checkLimit(int & HP1, int & HP2, int & EXP1, int & EXP2, int & M1, int & M2);

bool checkLimitE(int & E1, int & E2, int & E3);


// Task 1
int firstMeet(int & exp1, int & exp2, int e1);

// Task 2
int POW_2(int A);

int findSquare(int EXP1);

double road_1(int EXP1);

double road_2(int & HP1, int & EXP1, int & M1, int E2, int V);

int solveE2(int E2);

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2);

// Task 3
const int Max_Col = 10, Max_Row = 10;

int solveE3(int cnt);

pair <int, int> Fill(int array[][Max_Col], int e3);

int Scores(int array[][Max_Col], int row, int col);

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3);

// Task 4
bool checkKey(char s);

bool checkCase2(char s);

int checkPassword(const char * s, const char * email);

// Task 5
bool cmp(string A, const char *B);

int findCorrectPassword(const char * arr_pwds[], int num_pwds);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */

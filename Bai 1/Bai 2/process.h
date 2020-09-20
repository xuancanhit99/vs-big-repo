#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
using namespace std;

//2.1
void InputArr(int* a, int& n);
int random(int minN, int maxN);
void RanArr(int* a, int n);
//2.2
void OutPutArr(int* a, int n);
//2.3
void InsertArr(int* a, int* b, int n, int ins, int num_ins);
//2.4
void LinearS(int* a, int n, int skey);
//2.5
void FindI(int* a, int n, int sfirst);
//2.6
void NumOfOcc(int* a, int n, int stimes);
//2.7
int DeArr(int* a, int* c, int n, int de);
//2.8
int DeAllArr(int* a, int* c, int n, int num_de);
//2.9 
int BeforeFNum(int* a, int* b, int n, int farr);
int AfterFNum(int* a, int m, int* b, int n, int farr);
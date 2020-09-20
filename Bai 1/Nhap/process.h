#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>

#define MAX 100
using namespace std;

//1.1
void InputArr(int a[], int& n);
int random(int minN, int maxN);
void RanArr(int a[], int n);
//1.2
void OutPutArr(int a[], int n);
//1.3
void InsertArr(int a[], int b[], int n, int ins, int num_ins);
//1.4
void LinearS(int a[], int n, int skey);
//1.5
void FindI(int a[], int n, int sfirst);
//1.6
void NumOfOcc(int a[], int n, int stimes);
//1.7
int DeArr(int a[], int c[], int n, int de);
//1.8
int DeAllArr(int a[], int c[], int n, int num_de);
//1.9 
int BeforeFNum(int a[], int b[], int n, int farr);
int AfterFNum(int a[], int m, int b[], int n, int farr);

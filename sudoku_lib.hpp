#include <iostream>
#include <fstream>
#include <string>
#define N 9


int main();

void read_file(int arr[9][9]);
void print(int arr[9][9]);
bool check(int arr[9][9], int i, int j);
bool solved(int arr[9][9]);

//Backtracking algorithm
bool backtrack (int arr[9][9]);

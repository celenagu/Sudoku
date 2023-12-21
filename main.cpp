#include <iostream>
#include <fstream>
#include <string>
#include "functions.hpp"

void read_file(int arr[9][9]){
    std::ifstream input("read.txt");
    char data{};
    for (int i{}; i<9; i++){
        for (int j{}; j<9; j++){
            input >> data;
            arr[i][j] = data -'0';
        }
    }
    input.close();
}

void print(int arr[9][9]){
    for (int i{}; i<9; i++){
        if (i!= 0 && (i)%3 == 0){
            std::cout << "------+-------+-------" << std::endl;
        }

        for (int j{}; j<9; j++){

            if (arr[i][j] == 0){
                std::cout << ". ";
            }
            else{
                std::cout << arr[i][j] << " ";
            }

            if ((j+1)%3 == 0 && j!=8){
                std::cout << "| ";
            }
        }
        std::cout << std::endl;
    }
}

int main(){
    int board[9][9]{}; //standard 9x9 2d array
    read_file(board);

    print(board);

}


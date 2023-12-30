#include "sudoku_lib.hpp"

//Backtracking system
//Stochastic
//Constraint Satisfication

void read_file(int arr[N][N]){
    //using fstream
    //indicates which file to read from
    std::ifstream input("read.txt");

    //variable to store character data
    char data{};

    //Adds character data into int 2d array
    for (int i{}; i<N; i++){
        for (int j{}; j<N; j++){
            input >> data;
            arr[i][j] = data -'0'; //converts char to int
        }
    }
    
    input.close();
}

void print(int arr[N][N]){
    for (int i{}; i<N; i++){
        if (i!= 0 && (i)%3 == 0){
            std::cout << "------+-------+-------" << std::endl;
        }

        for (int j{}; j<N; j++){

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

//Checks whether it is safe or not to assign a particular number to a location
bool check(int arr[N][N], int row, int col, int n){
    //Check row 
    for (int k{}; k<N; k++){
        if (k == col){
            continue;
        }
        else{
            if (arr[row][k] == n)
                return false;
        }
    }

    //Check column
    for (int k{}; k<N; k++){
        if (k == row){
            continue;
        }
        else{
            if (arr[k][col] == n)
                return false;
        }
    }

    int row_box{};
    int col_box{};

    //Check box
    //Identify which box ( (0,0) to (2,2))
    row_box = row/3;
    col_box = col/3;

    //Check all entries within that box except current entry
    //iterates through 3 rows of box
    for (int l{}; l<3; l++){

        //iterates through 3 columns of box
        for (int m{}; m<3; m++){
            if ( (l + row_box*3 == row) && (m + col_box*3 == col)){
                continue;
            } 
            else{
                if (arr[ l + row_box*3][m + col_box*3] == n){
                    return false;
                }
            }

        }

    }

    return true;
}

bool solved(int arr[N][N]){
    for (int i{}; i<N; i++){
        for (int j{}; j<N; j++){
            if (arr[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}

//Solves sudoku with backtracking
//Returns false if no valid solution exists

bool backtrack (int arr[N][N], int row, int col){
    //two base cases
    // if end is reached without failure
    if (row == N -1 && col == N){
        return true;
    }
    //if end of row is reached
    if (col == N){
        col = 0;
        row++;
    }

    //current element is already assigned, recurse
    if (arr[row][col] != 0){
        return backtrack(arr, row, col+1);
    }
    //current element unassigned
    else{
        for (int i{1}; i<=9; i++){

            //if it is valid to assign to that location, assign
            if (check(arr, row, col, i)){
                arr[row][col] = i;

                if (backtrack(arr, row, col+1)){
                    return true;
                }
            }
            // if this point is reached, solution was invalid, remove guess values
            arr[row][col] = 0;

        }
        
    }

    return false;
}

void game(int board[9][9]){
    read_file(board);

    std::cout << "Unsolved:" << std::endl;
    print(board);

    std::cout << std::endl;

    if (backtrack(board, 0, 0)){
        std::cout << "Solved: " << std::endl;
        print(board);
    }
    else{
        std::cout << "No solution" << std::endl;
    }

}

int main(){
    int board[N][N]{}; //standard 9x9 2d array
    game(board);

    return 0;
}

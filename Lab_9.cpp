#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//Question 1
vector<vector<int>> read_matrix(ifstream &File, int size) {
    vector<vector<int>> matrix(size, vector<int>(size));

    for (int i = 0; i<size; i++){ //store matrix
        for (int j = 0; j<size; j++){
            File >> matrix[i][j];
        }
    }
    return matrix;
}

void print_matrix(const vector<vector<int>> &matrix) {
    for (const auto &row : matrix) {
        for (int val : row)
            cout << val << "\t";
        cout << endl;
    }
}

//Question 2
vector<vector<int>> add_matrix(const vector<vector<int>> &matrix1, const vector<vector<int>> &matrix2)  {
    int size = matrix1.size();
    vector<vector<int>> result(size, vector<int>(size)); //create empty result matrix

    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j]; //add each element together
        }
    }
    return result;
}

//Question 3
vector<vector<int>> multiply_matrix(const vector<vector<int>> &matrix1, const vector<vector<int>> &matrix2) {
    int size = matrix1.size();
    vector<vector<int>> result(size, vector<int>(size)); //create empty result matrix

    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            for (int k=0;k<size;k++){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }    
        }
    }
    return result;
}

//Question 4
int diagonal_sum(const vector<vector<int>> &matrix) {
    int size = matrix.size();
    
    int main_sum = 0;
    int secondary_sum = 0;

    for (int i = 0; i < size; i++) {
        main_sum += matrix[i][i]; // main diagonal
        secondary_sum += matrix[i][size - 1 - i]; // secondary diagonal
    }

    int total_sum = main_sum + secondary_sum;

    return total_sum;
}

//Question 5
vector<vector<int>> swap_rows(vector<vector<int>> matrix, int row1, int row2) {
    vector<int> temp = matrix[row1]; //store first row in temp
    matrix[row1] = matrix[row2]; //swap values
    matrix[row2] = temp;

    return matrix;
}

//Question 6
vector<vector<int>> swap_columns(vector<vector<int>> matrix, int col1, int col2) {
    int num_rows = matrix.size();

    for (int i = 0; i < num_rows; i++) { //loop through rows
        int temp = matrix[i][col1]; //store col1 element in temp
        matrix[i][col1] = matrix[i][col2]; //swap col1 element with col2 element
        matrix[i][col2] = temp;
    }

    return matrix;
}

//Question 7
vector<vector<int>> insert_value(vector<vector<int>> matrix, int row, int col, int value) {
    int size = matrix.size();

    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            if (matrix[i][j] == matrix[row][col]) {
                matrix[i][j] = value; //once the loop arrives on the target position, switch in the value
            }
        }
    }

    return matrix;
}



int main() {

    string filename;
    cout << "Enter a file name: " <<endl;
    cin >> filename; 

    ifstream File(filename);

    if (!File) { // always check that the file opened successfully
        cerr << "Error: could not open file.\n";
        return 1;
    }

    int size;
    File >> size;  // read the first number (the size)

    // Read first and second matrix
    vector<vector<int>> matrixA = read_matrix(File, size);
    vector<vector<int>> matrixB = read_matrix(File, size);

    cout << "Matrix A:\n";
    print_matrix(matrixA);
    cout << "\nMatrix B:\n";
    print_matrix(matrixB);

    vector<vector<int>> sum = add_matrix(matrixA,matrixB);
    cout << "\nA + B:\n";
    print_matrix(sum);

    vector<vector<int>> product = multiply_matrix(matrixA,matrixB);
    cout << "\nA * B:\n";
    print_matrix(product);

    int diag_sum = diagonal_sum(matrixA);
    cout <<"\nSum of main and secondary diagonals of A:\n";
    cout << diag_sum << endl;

    vector<vector<int>> swaprows = swap_rows(matrixA, 0, 3);
    cout << "\n Matrix A with the first and last rows swapped:\n";
    print_matrix(swaprows);

    vector<vector<int>> swapcols = swap_columns(matrixA, 0, 3);
    cout << "\n Matrix A with the first and last columns swapped:\n";
    print_matrix(swapcols);

    vector<vector<int>> insertval = insert_value(matrixA, 2, 2, 67);
    cout << "\n Matrix A with 67 inserted at row 2 column 2:\n";
    print_matrix(insertval);


    File.close();
    return 0;
}
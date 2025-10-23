#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

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
            cout << val << " ";
        cout << endl;
    }
}

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

int main() {

    ifstream File("input.txt");

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

    File.close();
    return 0;
}
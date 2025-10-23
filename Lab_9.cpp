#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string text;

    ifstream File("input.txt");

    while (getline (File, text)) {
        cout << text << endl;
    }

    File.close();
    return 0;
}
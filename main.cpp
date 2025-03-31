#include <iostream>    // For cout
#include <fstream>     // For file operations

using namespace std;

int main()
{
    const int SIZE = 10;
    int numbers[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Open file for binary output
    fstream file("numbers.dat", ios::out | ios::binary);

    if (!file)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    cout << "Writing the data to the file.\n";
    file.write(reinterpret_cast<char*>(numbers), sizeof(numbers));
    file.close();

    // Open file for binary input
    file.open("numbers.dat", ios::in | ios::binary);

    if (!file)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    cout << "Now reading the data back into memory.\n";
    file.read(reinterpret_cast<char*>(numbers), sizeof(numbers));

    // Display the contents of the array
    for (int count = 0; count < SIZE; count++)
    {
        cout << numbers[count] << " ";
    }
    cout << endl;

    file.close();
    return 0;
}

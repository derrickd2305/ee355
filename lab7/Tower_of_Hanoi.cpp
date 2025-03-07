#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

ofstream outFile("output_ToH.txt");
int moveCounter = 0; // Counter for the number of moves

void moveDisk(int n, char from_rod, char to_rod) {
    outFile << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    moveCounter++; // Increment the counter
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    // base case: one disk
    if(n <= 1){
        moveDisk(1, from_rod, to_rod);
        return;
    }

    // move all disks except bottom one to the aux rod, so the og to_rod becomes the aux_rod
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    // move the bottom disk
    moveDisk(n, from_rod, to_rod);
    // then clear the aux_rod so we can move the bottom one into place, then repeat
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
    
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <number_of_disks>" << endl;
        return 1;
    }

    int n = atoi(argv[1]); // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    outFile << "Total number of moves: " << moveCounter << endl; // Output the total number of moves
    outFile.close();
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

bool checkRange(double ratx, double raty, double len) {
    double dist = pow((ratx - len / 2), 2) + pow((raty - len / 2), 2);
    cout << "Distance from food: " << dist << endl;
    return dist < 1;
}

int moveRat(double ratx, double raty, double len, int dir, int moves) {
    if (checkRange(ratx, raty, len)) {
        return moves;
    }

    double step = len * 0.9; // Fixed step size for moving towards the center

    // Move the rat based on direction
    if (dir == 0) {
        raty += step;   // Move up
    } else if (dir == 1) {
        ratx += step;   // Move right
    } else if (dir == 2) {
        raty -= step;   // Move down
    } else {
        ratx -= step;   // Move left
    }

    cout << "Rat x: " << ratx << ", Rat y: " << raty << endl;

    // Change direction and increment move count
    dir = (dir + 1) % 4;
    return moveRat(ratx, raty, len, dir, moves + 1);
}

void findFood(double len) {
    int moves = moveRat(0, 0, len, 0, 0);
    cout << "The Rat gets the food in " << moves << " moves." << endl;
}

int main() {
    double l;
    cout << "Enter Length of Square: ";
    cin >> l;

    if (l <= 0) {
        cout << "Invalid Input. Length must be positive." << endl;
    } else {
        findFood(l);
    }
    return 0;
}

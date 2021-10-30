#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) {
    std::cout << "You are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room... \nYou need to enter the correct codes to continue...\n\n";
}

bool PlayGame(int Difficulty) {
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "There are 3 numbers in the code\n";
    std::cout << "The codes add-up to: " << CodeSum << "\n";
    std::cout << "The codes multiply to give: " << CodeProduct << "\n\n";

    int GuessA, GuessB, GuessC;

    std::cout << "Enter your guess: ";
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "\n*** Well done agent! You managed to extract a file! Keep going... ***\n\n";
        return true;
    }
    else {
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again... ***\n\n";
        return false;
    }
}

int main() {
    srand(time(NULL)); // Create new  random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete) {
            ++LevelDifficulty;
        }
        
    }

    std::cout << "\n*** Greate work agent! You got all the files! Now get out of there! ***\n";
    return 0;
}
#include <iostream>
#include <ctime>

void Introduction(int Difficulty)
{
    //Print welcome message
    std::cout << "Level: " << Difficulty << std::endl;
    std::cout << "Write 3 numbers with following rulles:\n\n";
}

bool PlayGame(int Difficulty)
{

    Introduction(Difficulty);

    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    //Print CodeSum and CodeProduct to the terminal
    std::cout << "->   X + X + X = " << CodeSum << std::endl;
    std::cout << "->   X * X * X = " << CodeProduct << std::endl;

    //Get imput
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if input mached

    //Win
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n----- XXX match!! -----\n";
        return true;
    }
    
    //lose
    else
    {
        std::cout << "\n----- XXX dont match :( -----\n";
        return false;
    }
}

int main()
{
    srand(time(NULL)); //create new random sequence based on time 

    int LevelDifficulty = 1;
    const int MaxDifficulty = 10;

    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete == true)
        {
            ++LevelDifficulty;
        }
    }

    //End of the game
    std::cout << "You won the game!";

    return 0;
}
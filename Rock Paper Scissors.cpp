#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

enum enWinner { Player = 1, Computar = 2, Draw = 3 };
enum enGameChoice { Rock = 1, Paper = 2, Scissors = 3 };

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice PlayerChoice;
    enGameChoice ComputarChoice;
    enWinner Winner;
    string WinnterName;
};

struct stGameResult
{
    short GameTotalRounds;
    short PlayerWinTimes;
    short ComputarWinTimes;
    short DrawTimes;
    enWinner Winner;
    string FinalWinner;
};

short ReadHowManyRounds()
{
    short Rounds;
    do
    {
        cout << "How many rounds 1 to 10 ? \n";
        cin >> Rounds;

    } while (Rounds < 1 || Rounds>10);

    return Rounds;
}

int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

enGameChoice ReadPlayerChoice()
{
    short Choice = 0;
    do
    {

        cout << "Your Choice: [1]:Rock , [2]:Paper , [3]:Scissors ? \n";
        cin >> Choice;


    } while (Choice < 1 || Choice>3);

    return (enGameChoice)Choice;
}

enGameChoice ReadComputarChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.PlayerChoice == RoundInfo.ComputarChoice)
    {
        return enWinner::Draw;
    }
    switch (RoundInfo.PlayerChoice)
    {
    case enGameChoice::Paper:
        if (RoundInfo.ComputarChoice == enGameChoice::Scissors)
            return enWinner::Computar;
        break;

    case enGameChoice::Rock:
        if (RoundInfo.ComputarChoice == enGameChoice::Paper)
            return enWinner::Computar;
        break;

    case enGameChoice::Scissors:
        if (RoundInfo.ComputarChoice == enGameChoice::Rock)
            return enWinner::Computar;
        break;
    }
    //if you reach here this means that Player is the winner.
    return enWinner::Player;
    
   

}

enWinner WhoWonTheGame(short PlayerWinTImes, short ComputarWinTimes)
{
    if (PlayerWinTImes > ComputarWinTimes)
        return enWinner::Player;

    else if (ComputarWinTimes > PlayerWinTImes)
        return enWinner::Computar;
    else
        return enWinner::Draw;

}

void SetWinnerScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player:
        system("color 2F"); //turn screen to Green
        break;
    case enWinner::Computar:
        system("color 4F"); //turn screen to Red
        cout << "\a";
        break;
    default:
        system("color 6F"); //turn screen to Yellow
        break;
    }
}

string WriteFinalWinner(enWinner Winner)
{
    string ArrWinners[3] = { "Player","Computar","Draw" };

    return ArrWinners[Winner - 1];
}

string WriteRoundChoice(enGameChoice ChoiceName)
{
    string ArrWinners[3] = { "Rock","Paper","Scissors" };

    return ArrWinners[ChoiceName - 1];

}

stGameResult FillGameResult(short Rounds,short PlayerWinTImes,short ComputarWinTimes,short DrawTimes)
{
    stGameResult GameResult;
    GameResult.GameTotalRounds = Rounds;
    GameResult.PlayerWinTimes = PlayerWinTImes;
    GameResult.ComputarWinTimes = ComputarWinTimes;
    GameResult.DrawTimes = DrawTimes;
    GameResult.Winner = WhoWonTheGame(PlayerWinTImes, ComputarWinTimes);
    GameResult.FinalWinner = WriteFinalWinner(GameResult.Winner);
}

stGameResult PlayGame(short HowManyRounds)
{
    stRoundInfo RoundInfo;

    short PlayerWinTimes = 0, ComputarWinTimes = 0, DrawTimes = 0;

    for (short GameRounds = 1; GameRounds <= HowManyRounds; GameRounds++)
    {
        cout << "\n\n__________________Round[" << GameRounds << "]____________________\n";
        RoundInfo.PlayerChoice = ReadPlayerChoice();
        RoundInfo.ComputarChoice = ReadComputarChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
    }
    if (RoundInfo.Winner == enWinner::Player)
    {
        PlayerWinTimes++;
    }
    else if (RoundInfo.Winner == enWinner::Computar)
    {
        ComputarWinTimes++;
    }
    else
        DrawTimes++;

    return FillGameResult(ReadHowManyRounds(), PlayerWinTimes, ComputarWinTimes, DrawTimes);

}

void PrintRoundResults(stRoundInfo RoundInfo)
{
    cout << "\n____________Round [" << RoundInfo.RoundNumber << "]   ____________\n\n";
    cout << "Player1 Choice: " << WriteRoundChoice(RoundInfo.PlayerChoice) << endl;
    cout << "Computer Choice: " << WriteRoundChoice(RoundInfo.ComputarChoice) << endl;
    cout << "Round Winner : [" << RoundInfo.WinnterName << "]\n";
    cout << "__________________________________\n" << endl;

    SetWinnerScreenColor(RoundInfo.Winner);
}
  
void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void StartGame()
{
    char PlayAgain = 'Y';
    do {

        ResetScreen();
        stGameResult GameResult = PlayGame(ReadHowManyRounds());


    } while (PlayAgain == 'y' || PlayAgain == 'Y');

}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    StartGame();
}



//cout << "\a"; For the losing sounds
// 
//system("color 1F"); Blue Color
//system("color 4F"); Red Color
//system("color 2F"); Green Color
#include <iostream>
#include <stdlib.h>
#include <string>

#define TABLESIZE 14

void initBoard();
void colorOutput(int);
void displayBoard();
int userInput();
void updateBoard(int);

int board[TABLESIZE][TABLESIZE];

int main()
{
    srand(time(NULL));

    initBoard();
    displayBoard();

    int fills = 0;
    int chosenNumber;
    // Core game loop
    while (fills <= 25)
    {
        chosenNumber = userInput();
        updateBoard(chosenNumber);
    }
}

void initBoard()
{
    for (int i = 0; i < TABLESIZE; i++)
    {
        for (int j = 0; j < TABLESIZE; j++)
        {
            int number = rand() % 6 + 1;
            board[i][j] = number;
        }
    }
}

void displayBoard()
{
    for (int i = 0; i < TABLESIZE; i++)
    {
        for (int j = 0; j < TABLESIZE; j++)
            colorOutput(board[i][j]);

        std::cout << std::endl;
    }
}

int userInput()
{
    int input = 99;
    std::cout << "Wybierz kolor:" << std::endl;
    printf("1 - \x1b[34;44m  \x1b[0m \n");
    printf("2 - \x1b[31;41m  \x1b[0m \n");
    printf("3 - \x1b[32;42m  \x1b[0m \n");
    printf("4 - \x1b[33;43m  \x1b[0m \n");
    printf("5 - \x1b[35;45m  \x1b[0m \n");
    printf("6 - \x1b[36;46m  \x1b[0m \n");

    std::cout << "Your choice: ";
    std::cin >> input;

    return input;
}

void colorOutput(int number)
{
    switch (number)
    {
    case 1:
        printf("\x1b[34;44m  \x1b[0m");

        break;
    case 2:
        printf("\x1b[31;41m  \x1b[0m");

        break;
    case 3:
        printf("\x1b[32;42m  \x1b[0m");

        break;
    case 4:
        printf("\x1b[33;43m  \x1b[0m");

        break;
    case 5:
        printf("\x1b[35;45m  \x1b[0m");

        break;
    case 6:
        printf("\x1b[36;46m  \x1b[0m");

        break;
    default:
        printf("\x1b[0m");

        break;
    }
}
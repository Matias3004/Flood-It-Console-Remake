#include <iostream>
#include <stdlib.h>
#include <string>

#define N 14

void initBoard();
void colorOutput(int);
void displayBoard();
int userInput();
void updateBoard(int, int, int, int);
bool isBoardFilled();

int board[N][N];

int main()
{
    system("clear");

    srand(time(NULL));
    initBoard();

    int fills = 0;
    int chosenNumber;
    // Core game loop
    while (fills < 25)
    {
        // Checks if the chosen color is the same as the top-left color
        while (true)
        {
            std::cout << "Fills: " << fills << "/25\n";
            displayBoard();
            chosenNumber = userInput();

            system("clear");
            
            if (chosenNumber != board[0][0])
                break;
        }
        
        updateBoard(board[0][0], chosenNumber, 0, 0);

        if (isBoardFilled())
        {
            std::cout << "Fills: " << fills << "/25\n";
            displayBoard();
            std::cout << "You won!" << std::endl;
            std::cout << "1 - New Game\n2 - Exit" << std::endl;
            std::cout << "Choice: ";
            std::cin >> chosenNumber;

            switch (chosenNumber)
            {
            case 1:
                main();

                break;
            case 2:
                return 0;
            default:
                return 0;
            }
        }

        system("clear");
        fills++;
    }

    std::cout << "Fills: " << fills << "/25\n";
    displayBoard();
    std::cout << "You lost!" << std::endl;
    std::cout << "1 - New Game\n2 - Exit" << std::endl;
    std::cout << "Choice: ";
    std::cin >> chosenNumber;

    switch (chosenNumber)
    {
        case 1:
            main();

            break;
        case 2:
            return 0;
        default:
            return 0;
    }
}

void initBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int number = rand() % 6 + 1;
            board[i][j] = number;
        }
    }
}

void updateBoard(int oldColor, int newColor, int row, int col)
{
    // Check if the oldColor is same as the newColor
    if (oldColor == newColor)
        return;

    // Check if the row and column are within bounds of the board
    if (row < 0 || row >= N || col < 0 || col >= N)
        return;

    // Check if the current cell has the oldColor
    if (board[row][col] != oldColor)
        return;

    // Update the current cell with the newColor
    board[row][col] = newColor;

    // Update the adjacent cells with the newColor
    updateBoard(oldColor, newColor, row - 1, col);
    updateBoard(oldColor, newColor, row + 1, col);
    updateBoard(oldColor, newColor, row, col - 1);
    updateBoard(oldColor, newColor, row, col + 1);
}

bool isBoardFilled()
{
    int color = board[0][0];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] != color)
                return false;
        }
    }

    return true;
}

void displayBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
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
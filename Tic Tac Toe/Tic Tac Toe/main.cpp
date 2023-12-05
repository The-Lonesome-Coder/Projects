import <iostream>;

char board[3][3] = {
                        {'1', '2', '3'},
                        {'4', '5', '6'},
                        {'7', '8', '9'}
                   };

bool draw = false;
char turn = 'X';


void displayBoard()
{
    std::cout << "PLAYER - 1 [X]t PLAYER - 2 [O]\n\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
    std::cout << "     |     |     \n";
}


void playerTurn()
{
    int choice;
    int row, column;

    if (turn == 'X')
    {
        std::cout << "Player 1 [X]'s turn: ";
    }
    else if (turn == 'O')
    {
        std::cout << "Player 2 [O]'s turn: ";
    }

    std::cin >> choice;

    switch (choice)
    {
        case 1:
            row = 0;
            column = 0;
            break;

        case 2:
            row = 0;
            column = 1;
            break;

        case 3:
            row = 0;
            column = 2;
            break;

        case 4:
            row = 1;
            column = 0;
            break;

        case 5:
            row = 1;
            column = 1;
            break;

        case 6:
            row = 1;
            column = 2;
            break;

        case 7:
            row = 2;
            column = 0;
            break;

        case 8:
            row = 2;
            column = 1;
            break;

        case 9:
            row = 2;
            column = 2;
            break;

        default:
            std::cout << "Invalid Move";
    }

    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        std::cout << "Box already filled!n Please choose another!!\n\n";
        playerTurn();
    }
}


bool gameover()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return false;
        }
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return false;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return true;
            }
        }
    }

    draw = true;

    return false;
}


int main()
{
    std::cout << "T I C K -- T A C -- T O E -- G A M E";
    std::cout << "FOR 2 PLAYERS";

    while (gameover())
    {
        displayBoard();
        playerTurn();
        gameover();
    }

    if (turn == 'X' && draw == false)
    {
        std::cout << "Congratulations!Player with 'X' has won the game";
    }
    else if (turn == 'O' && draw == false)
    {
        std::cout << "Congratulations!Player with 'O' has won the game";
    }
    else
    {
        std::cout << "GAME DRAW!!!";
    }
}
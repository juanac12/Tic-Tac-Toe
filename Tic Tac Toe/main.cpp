    #include <iostream> 
    using namespace std; 

    char space[10] = {'0','1','2','3','4','5','6','7','8','9'};

    int checkWin()
    {

        // Check wins Horizontally.
        if (space[1] == space[2] && space[2] == space[3])
        {
            return 1; 
        }

        else if (space[4] == space[5] && space[5]==space[6])
        {
            return 1;
        }

        else if (space [7] == space[8] && space[8] == space[9])
        {
            return 1;
        }

        // Checks wins Vertically.
        else if (space[1] == space[4] && space[4] == space[7])
        {
            return 1;
        }

        else if (space[2] == space[5] && space[5] == space[8])
        {
            return 1; 
        }

        else if (space[3] == space[6] && space[6] == space[9])
        {
            return 1;
        }


        //Checks wins Diaganolly.
        else if (space[1] == space[5] && space[5] == space[9])
        {
            return 1;
        }

        else if (space[3]== space [5] && space[5] == space[7])
        {
            return 1;
        }

        // Draw
        else if (space[1] != '1' && space[2] != '2' && space[3] != '3'
            && space[4] != '4' && space[5] != '5' && space[6] != '6' 
            && space[7] != '7' && space[8] != '8' && space[9] != '9')
            {
                return 0;
            }

        else 
        {
            return -1;
        }

    }

    void drawBoard() // Draws the Tic Tac Toe Board 
    {

        cout << "      |     |      " << endl;
        cout << "    " << space[1] << " |   " << space[2] << " |   " << space[3] << endl;
        cout << "______|_____|________" << endl;

        cout << "      |     |      " << endl;
        cout << "    " << space[4] << " |   " << space[5] << " |   " << space[6] << endl;
        cout << "______|_____|_________" << endl;

        cout << "      |     |      " << endl;
        cout << "    " << space[7] << " |   " << space[8] << " |   " << space[9] << endl;
        cout << "      |     |      " << endl;


    }


    int main()
    {
        
        int player = 1, choice; 
        char mark; 
        int result;

        cout << "Player 1(X) - Player 2(0) \n" << endl << endl;

        do 
        {
            drawBoard();
            player = (player % 2) ? 1 : 2; 
            cout << endl; 
            cout << "Player " << player << " , make your move: ";
            cin >> choice; 
            cout << endl << endl; 

            mark = (player ==1)? 'X' : 'O';

            if (choice >= 1 && choice <= 9 && space[choice] == ('0' + choice))
            {
                space[choice] = mark;
                result = checkWin();

                player = (player % 2) ? 2 : 1;
            }

            else 
            {
                cout << "This is an invalid move. Please try again." << endl;
                player --;
                cin.ignore();
                cin.get();
            }

        } while (result == -1);


        drawBoard();
            if ( result == 1)
                {
                    cout << " You have won, Player  " << -- player; 
                }
            else 
                {
                    cout << "It is a Tie!";
                }

    cin.ignore();
    cin.get();
    return 0; 
    }
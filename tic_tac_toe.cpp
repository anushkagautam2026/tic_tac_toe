#include <iostream>
using namespace std;
void green()
{ /*colour functions*/
    printf("\033[1;32m");
}
void blue()
{
    printf("\033[1;36m");
}
void red()
{
    printf("\033[1;31m");
}
void pink()
{
    printf("\033[1;35m");
}
void reset()
{ /*reset function to reset colour to white*/
    printf("\033[0m");
}
class tictactoe
{
    char board[10];

public:

    bool played[10];
    tictactoe()
    {
        int k = '1';
        for (int i = 1; i < 10; i++)
        {
            board[i] = k;
            k++;
        }
        for (int i = 1; i < 10; i++)
        {
            played[i] = false;
        }
    }
    void printboard()
    {

        int i = 1;
        cout<<"----------"<<endl;
        while (i < 10)
        {
            
            if (i == 4 || i == 7)
            {
                cout << endl;
            }
            if(board[i]=='O'){
                pink();
                cout <<"|"<< board[i] << "|";
                reset();
            }
            else if(board[i]=='X'){
                blue();
                cout <<"|"<< board[i] << "|";
                reset();
            }
            else{
            cout <<"|"<< board[i] << "|";
            }
            i++;
        }
        cout<<endl<<"----------"<<endl;
        
    }
    void play2(int ch, int player)
    {
        if (player == 0)
        {
            board[ch] = 'O';
            played[ch] = true;
        }
        else
        {
            
            board[ch] = 'X';
            played[ch] = true;
        }
    }
    char checkwin()
    {
        if (board[1] == board[2] && board[2] == board[3])
        {
            return board[1];
        }
        if (board[1] == board[4] && board[4] == board[7])
        {
            return board[1];
        }
        if (board[1] == board[5] && board[5] == board[9])
        {
            return board[1];
        }
        if ((board[4] == board[5] && board[5] == board[6]) || (board[2] == board[5] && board[5] == board[8]) || (board[3] == board[5] && board[5] == board[7]))
        {
            return board[5];
        }
        if ((board[7] == board[8] && board[8] == board[9]) || (board[3] == board[6] && board[6] == board[9]))
        {
            return board[9];
        }
        return 'q';
    }
    bool checkend()
    {
        for (int i = 1; i < 10; i++)
        {
            if (board[i] != 'O' && board[i] != 'X')
            {
                return false;
            }
        }
        return true;
    }
    void play1(int ch){
        board[ch]='X';
        played[ch]=true;
    }
    void play(){
        srand(time(0));
        int a=rand()%10;
        while(a<1||a>9||played[a]){
            a=rand()%10;
        }
        board[a]='O';
        played[a]=true;
        
    }
};

int main()
{
    tictactoe game;
    int ch,choice;
    int player = 1;
    cout<<"-------MENU-------"<<endl;
    cout<<"1. single player"<<endl;
    cout<<"2. two player"<<endl;
    cin>>choice;
    if(choice==3){
        cout<<"!!!!!!!THANKS!!!!!!!"<<endl;
    }
    else if(choice==2){
    while(1)
    {
        game.printboard();
        if(player==1){
            cout<<"PLAYER1: ";
        }
        else{
            cout<<"PLAYER2: ";
        }
        cin >> ch;
        while (ch < 1 || ch > 9 || game.played[ch])
        {
            red();
            cout << "Invalid move. Try again: " << endl;
            reset();
            cout << "player" << player << ":";
            cin >> ch;
        }
        game.play2(ch, player);
        game.printboard();
        green();
        if (game.checkwin() == 'O')
        {
            cout << "PLAYER 2 WINS";
            break;
        }
        if (game.checkwin() == 'X')
        {
            cout << "PLAYER 1 WINS";
            break;
        }
        if (game.checkend())
        {
            cout << "ITS'S A DRAW";
            break;
        }
        reset();
        player = 1 - player;
    }
    }
    else if(choice==1){
        while(1){
        game.printboard();
        cin>>ch;
        while (ch < 1 || ch > 9 || game.played[ch])
        {
            red();
            cout << "Invalid move. Try again: " << endl;
            reset();
            cout << "player" << player << ":";
            cin >> ch;
        }
        game.play1(ch);
        game.printboard();
        green();
        if (game.checkwin() == 'O')
        {
            cout << "PLAYER 2 WINS";
            break;
        }
        if (game.checkwin() == 'X')
        {
            cout << "PLAYER 1 WINS";
            break;
        }
        if (game.checkend())
        {
            cout << "ITS'S A DRAW";
            break;
        }
        reset();
        game.play();
        game.printboard();
        green();
        if (game.checkwin() == 'O')
        {
            cout << "YOU LOSE";
            break;
        }
        if (game.checkwin() == 'X')
        {
            cout << "YOU WIN";
            break;
        }
        if (game.checkend())
        {
            cout << "ITS'S A DRAW!!";
            break;
        }
        reset();
        }

    }
}
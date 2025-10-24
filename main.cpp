#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void print_screen(char* Ar);//Выводит игровое поле
bool MoveCheck(char* Ar, int N);
void CheckVictory(char *Ar, char T);
void Restart(char* Ar);

short Drawmeter = 0;
unsigned short score[]{0, 0};
bool game = true;
string msg = "Enter command: ";

int main() {
    char Field[9] = {// Хранит текущую информацию об игровом поле
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9' };
    char inp, Turn = 'X';

    while (true) {
        print_screen(Field);
        cout << Turn << "'s turn\n" << msg;
        cin >> inp;
        system("cls");
        switch (inp) {
        case '1':
            if (MoveCheck(Field, 0)) {
                Field[0] = Turn;
                Turn = (Turn == 'X') ? 'O' : 'X';
            }
            break;
        case '2':
            if (MoveCheck(Field, 1)) {
                Field[1] = Turn;
                Turn = (Turn == 'X') ? 'O' : 'X';
            }
            break;
        case '3':
            if (MoveCheck(Field, 2)) {
                Field[2] = Turn;
                Turn = (Turn == 'X') ? 'O' : 'X';
            }
            break;
        case '4':
            if (MoveCheck(Field, 3)) {
                Field[3] = Turn;
                Turn = (Turn == 'X') ? 'O' : 'X';
            }
            break;
        case '5':
            if (MoveCheck(Field, 4)) {
                Field[4] = Turn;
                Turn = (Turn == 'X') ? 'O' : 'X';
            }
            break;
        case '6':
            if (MoveCheck(Field, 5)) {
                Field[5] = Turn;
                Turn = (Turn == 'X') ? 'O' : 'X';
            }
            break;
        case '7':
            if (MoveCheck(Field, 6)) {
                Field[6] = Turn;
                Turn = (Turn == 'X') ? 'O' : 'X';
            }
            break;
        case '8':
            if (MoveCheck(Field, 7)) {
                Field[7] = Turn;
                Turn = (Turn == 'X') ? 'O' : 'X';
            }
            break;
        case '9':
            if (MoveCheck(Field, 8)) {
                Field[8] = Turn;
                Turn = (Turn == 'X') ? 'O' : 'X';
            }
            break;
        case 'H':
            msg = "Play against your friend by typing commands one by one\nPut your sign by typing square's nuber\nMake 3 signs in a row to win\nYou may not choose taken square\nEnter command: ";
            break;
        case 'R':
            Restart(Field);
            break;
        default:
            msg = "Invalid command. Please try again: ";
            break;
        }
        if (game) CheckVictory(Field, Turn);
        if (Drawmeter > 8 && game) {
            msg = "Draw! Restart to play again: ";
            game = false;
        }
    }
    return 0;
}

void print_screen(char *Ar) {
    cout << "   |   |     Tic-tac-toe\n";
    cout << " " << *(Ar) << " | " << *(Ar + 1) << " | " << *(Ar + 2) << "   Score "<< score[0] << " : " << score[1] << "\n";
    cout << "___|___|___  Type number from 1 to 9 to take a space\n";
    cout << "   |   |     Type \"H\" to see rules\n";
    cout << " " << *(Ar + 3) << " | " << *(Ar + 4) << " | " << *(Ar + 5) << "   Type \"R\" to restart the game\n";
    cout << "___|___|___\n";
    cout << "   |   |    \n";
    cout << " " << *(Ar + 6) << " | " << *(Ar + 7) << " | " << *(Ar + 8) << "\n";
    cout << "   |   |    \n";
}

bool MoveCheck(char* Ar, int N){
    if (!game){
        msg = "Please restart the game: ";
        return false;
    }
    else if (Ar[N] != 'X' && Ar[N] != 'O') {
        Drawmeter++;
        msg = "Enter command: ";
        return true;
    }else msg = "Please choose free space: ";
    return false;
}

void Restart(char* Ar){
    char Template[9] = {
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9' };
    for (int i = 0; i < 9; i++) *(Ar + i) = Template[i];
    msg = "Enter command: ";
    game = true;
}

int WinCombos[8][3]{ 
    {0,1,2},{3,4,5},{6,7,8},{ 0,3,6 },{1,4,7},{2,5,8},{0,4,8},{6,4,2} 
    };
void CheckVictory(char *Ar, char T) {
    for (int i = 0; i < 8; ++i) {
        if (*(Ar + WinCombos[i][0]) == *(Ar + WinCombos[i][1]) && *(Ar + WinCombos[i][1]) == *(Ar + WinCombos[i][2])) {
            game = false;
            if (T == 'O') { 
                msg = "X won! Type \"R\" to play again: "; 
                score[0]++;
            }else { 
                msg = "O won! Type \"R\" to play again: ";
                score[1]++; 
            }
        }
    }
}
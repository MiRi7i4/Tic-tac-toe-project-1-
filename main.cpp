#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
void print_screen(char* Ar);//Выводит игровое поле

unsigned short score[]{0, 0};

int main() {
    char Field[9] = {// Хранит текущую информацию об игровом поле
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9' };
    char inp, Turn = 'X';
    string msg = "Enter command: ";

    while (true) {
        print_screen(Field);
        cout << Turn << "'s turn\n" << msg;
        cin >> inp;
        system("cls");
        switch (inp) {
        case '1':
                Field[0] = Turn;
                Turn = (Turn == 'X')? 'O' : 'X';
                break;
        case '2':
            Field[1] = Turn;
            Turn = (Turn == 'X') ? 'O' : 'X';
            break;
        case '3':
            Field[2] = Turn;
            Turn = (Turn == 'X') ? 'O' : 'X';
            break;
        case '4':
            Field[3] = Turn;
            Turn = (Turn == 'X') ? 'O' : 'X';
            break;
        case '5':
            Field[4] = Turn;
            Turn = (Turn == 'X') ? 'O' : 'X';
            break;
        case '6':
            Field[5] = Turn;
            Turn = (Turn == 'X') ? 'O' : 'X';
            break;
        case '7':
            Field[6] = Turn;
            Turn = (Turn == 'X') ? 'O' : 'X';
            break;
        case '8':
            Field[7] = Turn;
            Turn = (Turn == 'X') ? 'O' : 'X';
            break;
        case '9':
            Field[8] = Turn;
            Turn = (Turn == 'X') ? 'O' : 'X';
            break;
        }
    }
    return 0;
}

void print_screen(char *Ar) {
    cout << "   |   |     Tic-tac-toe\n";
    cout << " " << *(Ar) << " | " << *(Ar + 1) << " | " << *(Ar + 2) << "\n";
    cout << "___|___|___  Type number from 1 to 9 to take a space\n";
    cout << "   |   |     \n";
    cout << " " << *(Ar + 3) << " | " << *(Ar + 4) << " | " << *(Ar + 5) << " \n";
    cout << "___|___|___\n";
    cout << "   |   |    \n";
    cout << " " << *(Ar + 6) << " | " << *(Ar + 7) << " | " << *(Ar + 8) << "\n";
    cout << "   |   |    \n";
}

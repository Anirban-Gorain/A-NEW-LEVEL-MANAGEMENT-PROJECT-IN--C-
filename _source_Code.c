// Coding started date is 18/5/2020 during the lock-down period, Ending date is ....

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

// Function prototype.
void gotoxy(int ,int );
char _registration_Menu(void);
void _border(int, int);
void _red(void);
void _green(void);
void _reset(void);
int _sign_Up(void);

int main (void){
    // Border
    // _border(28, 121);

    // Password
    // int _return_Value;
    // _return_Value = _registration_Menu();
    _sign_Up();
    // printf("DONE");
    // getch();
    return 0;
}

// Function declaration.

// ------------------------------------- EVERYWHERE USEABLE FUNCTIONS --------------------------------------

// gotoxy function for move on the output screen.

void gotoxy(int x,int y)
{
    // Variable.

    COORD _coordinate;

    // Putting coordinate X and Y.

    _coordinate.X=x;
    _coordinate.Y=y;

    // Setting the position.

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _coordinate);
}
void _border(int _height, int _width){

    for(int _finish = 2; _height > _finish; _finish++){

        gotoxy(2, _finish);
        printf("|");

        gotoxy(119, _finish);
        printf("|");

    }

    for(int _finish = 1; _width > _finish; _finish++){

        gotoxy(_finish, 0);
        printf("_");

        gotoxy(_finish, 28);
        printf("_");

    }

}
// Color functions
void _red(void){

    printf("\033[0;31m");

}
void _green(void){

    printf("[0;32m");

}
void reset(void){

    printf("[0m");

}
// ------------------------------------------ REGISTRATION SECTION ---------------------------------------------
// Registration menu.
char _registration_Menu(void){

    // This variable value will be return from here.

    char _selected_Result;
    static int _maximum_Chance = 1;

    // Heading.

    gotoxy(45, 2);
    printf("--WELCOME TO THE REGISTRATION--");
    gotoxy(32, 3);
    printf("-----------------------------------------------------------");

    // Menu.

    gotoxy(32, 8);
    printf("LOG-IN, [PRESS \'L\']. \n");

    gotoxy(32, 11);
    printf("UPDATE SIGNED-UP-INFORMATION, [PRESS \'U\']. \n");

    gotoxy(32, 14);
    printf("SIGN-UP, [PRESS \'S\']. \n");

    gotoxy(32, 17);
    printf("ENTER YOUR NEEDFUL CHOICE: ");
    fflush(stdin);
    scanf("%c", &_selected_Result);

    // Eroor handling, Because if user entered any wrong value.
    if((_selected_Result == 'L' || _selected_Result == 'l') || (_selected_Result == 'U' || _selected_Result == 'u') || (_selected_Result == 'S' || _selected_Result == 's')){

        return _selected_Result;

    }
    else{

        // If the user want to enter again option.

        gotoxy(32, 19);
        printf("WRONG CHOICE, TRY AGAIN! CLICK A KEY FOR GET A ANOTHE CHANCE.");
        getch();
        system("cls");
        _border(28, 121);

        // When user will exceed maximum number of chance program will be close.

        if(_maximum_Chance > 4){

            _red();
            Beep(800, 1000);
            gotoxy(30, 15);
            printf("WRONG CHOICE, YOU EXCEED MAXIMUM NUMBER OF CHANCE, TRY AGAIN LATER.");
            getch();
            exit(1);

        }

        _maximum_Chance++;
        _registration_Menu();

    }

}
// Sign-up time.
int _sign_Up(void){

    system("cls");
    _border(28, 121);
    gotoxy(45, 2);
    printf("--WELCOME TO THE SIGN-UP--");
    gotoxy(32, 3);
    printf("-----------------------------------------------------------");
    // First check may stored any previous Signed-up data and this section of code for this

    // ------------- --------  ----------- ---------------- -------------


    // If don't having any Signed-up data the this section of code for this.

    // Taking the user name.

    char _user_Name[20];
    int _user_Name_Lenght;
    int _exceed_Time = 0;
    int _update_Y_Axis = 8;

    while(4){

        _exceed_Time++;
        _update_Y_Axis++;

        // If the maximum number of attempt are exceed the program will be close.

        if (_exceed_Time == 4 ){

            _red();
            gotoxy(18, 26);
            printf("YOU EXCEED THE MAXIMUM NUMBER OF TIME ATTEMPT, TRY AGAIN LATER :)");
            getch();
            exit(1);

        }

        gotoxy(18, _update_Y_Axis);
        printf("ENTER YOUR USER-NAME, USER-NAME LENGHT MUST BE GRATER 5 CHRACTER AND LESS 20 CHRACTER: ");

        _update_Y_Axis++;
        gotoxy(18, _update_Y_Axis);
        fflush(stdin);
        gets(_user_Name);

        _user_Name_Lenght = strlen(_user_Name);

        // If the user name satisfied all the criteria then  this loop will be break.

        if( _user_Name_Lenght > 5 && _user_Name_Lenght < 20 ){

            break;

        }

        if (_update_Y_Axis == 10)
        {

            _update_Y_Axis--;

        }

    }

}

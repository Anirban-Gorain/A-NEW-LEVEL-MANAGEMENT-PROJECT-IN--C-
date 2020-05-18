// Coding started date is 18/5/2020 during the lock-down period, Ending date is ....

#include<stdio.h>
#include<conio.h>
#include<windows.h>

// Function prototype.
void gotoxy(int ,int );
int _registration_Menu(void);
void _border(int, int);

int main (void){
    // Border
    _border(30, 121);

    // Password
    _registration_Menu();

    getch();
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

        gotoxy(_finish, 29);
        printf("_");

    }

}

// ------------------------------------------ REGISTRATION SECTION ---------------------------------------------
int _registration_Menu(void){

    // This variable value will be return from here.

    int _selected_Result;

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
    scanf("%d", &_selected_Result);

    return _selected_Result;
}
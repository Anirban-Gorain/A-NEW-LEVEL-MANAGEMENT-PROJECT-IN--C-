// Coding started date is 18/5/2020 during the lock-down period, Ending date is ....

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<stdbool.h>

// Function prototype.
void gotoxy(int ,int );
char _registration_Menu(void);
void _border(int, int);
void _red(void);
void _green(void);
void _reset(void);
bool _sign_Up(void);
void _encryption_And_Decryption(char *);

int main (void){

    // Registration

    char _return_Value;
    _return_Value = _registration_Menu();

    // Comparing user choice in registration section.

    if(_return_Value == 'L' || _return_Value == 'l'){

        // This section for LOG-IN.

    }else if(_return_Value == 'U' || _return_Value == 'u'){

        // This section for SIGNED_UP-DATA-UPDATE.

    }else{

        // This section for SIGN-UP

        _sign_Up();

    }



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

    printf("\033[0;32m");

}

void _reset(void){

    printf("\033[0m");

}

// Encryption decryption function

void _encryption_And_Decryption(char *_data_pointer){

    // The below array is the encryption decryption key.

    char _key[] = {'p', '3','2', '7','O', '9','c', 'X','s', 'q','w', '~','*', '2', 'I'};

    for (int _data_Index = 0; *(_data_pointer + _data_Index) != 0; _data_Index++)
    {
        for (int _key_Index = 0; *(_key + _key_Index) != 0; _key_Index++)
        {
            *(_data_pointer + _data_Index) ^= *(_key + _key_Index);
        }

    }


}
// ------------------------------------------ REGISTRATION SECTION ---------------------------------------------
// Registration menu.
char _registration_Menu(void){

    // Border

    _border(28, 121);

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
bool _sign_Up(void){

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

    while(1){

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

        // User name wrong message

        gotoxy(18, 18);
        _red();
        printf("WRONG USER NAME FOLLOW THE GUIDELINE.");
        _reset();

        if (_update_Y_Axis == 10)
        {

            _update_Y_Axis--;

        }

    }

    system("cls");
    _border(28, 121);
    gotoxy(45, 2);
    printf("--WELCOME TO THE SIGN-UP--");
    gotoxy(32, 3);
    printf("-----------------------------------------------------------");

    // Taking the password.

    char _password[20];
    int _password_Lenght;
    _exceed_Time = 0;
    _update_Y_Axis = 8;

    // Use of this below boolen array is the compare the password's pattern. INDEX 0, 1, 2 will denote the upper-case, lowercase, spcial-charter recpectivly.

    bool _password_Pattern[3] = {[0 ... 2] = false};

    while(1){

        _exceed_Time++;
        _update_Y_Axis++;

        // If the maximum number of attempt are exceed the program will be close.

        if (_exceed_Time == 4 ){

            _red();
            gotoxy(32, 22);
            printf("YOU EXCEED THE MAXIMUM NUMBER OF TIME ATTEMPT, TRY AGAIN LATER :)");
            getch();
            exit(1);

        }

        // Instruction message bottom left corner.

        gotoxy(32, 26);
        printf("INCLUDE MINIMUM ONE SPCIAL, ONE LOWER, ONE UPPER, CHARACTERS ALSO INCLUDE NUMBERS.");
        gotoxy(32, 27);
        printf("PASSWORD LENGHT SHOULD BE GRATER THEN 8 AND LESS THEN 20.");

        gotoxy(32, _update_Y_Axis);
        printf("ENTER YOUR PASSWORD: ");
        fflush(stdin);
        gets(_password);

        _password_Lenght = strlen(_password);

        // If the PASSWORD satisfied all the criteria then this loop will be break.

        if( _password_Lenght > 5 && _password_Lenght < 20 ){

                // INDEX 0, 1, 2 will denote the upper-case, lowercase, special-charter respectively.

                for (int _index_Of_Password = 0; _index_Of_Password < _password_Lenght; _index_Of_Password++)
                {
                    if((_password_Pattern[1] != true) && (_password[_index_Of_Password] >= 97 && _password[_index_Of_Password] <= 122)){

                        _password_Pattern[1] = true;
                    }
                    if((_password_Pattern[0] != true) && (_password[_index_Of_Password] >= 65 && _password[_index_Of_Password] <= 90)){

                        _password_Pattern[0] = true;

                    }
                    if((_password_Pattern[2] != true) && ((_password[_index_Of_Password] >= 33 && _password[_index_Of_Password] <= 47) || (_password[_index_Of_Password] >= 58 && _password[_index_Of_Password] <= 64) || (_password[_index_Of_Password] >= 91 && _password[_index_Of_Password] <= 96) || (_password[_index_Of_Password] >= 123 && _password[_index_Of_Password] <= 126))){

                        _password_Pattern[2] = true;

                    }

                }

        }

        // If the both the blocks are true then the loop will be break.

        if (_password_Pattern[0] == true && _password_Pattern[1] == true && _password_Pattern[2] == true)
        {

            _encryption_And_Decryption(_user_Name);
            _encryption_And_Decryption(_password);
            return true;

        }


        // Password wrong message.

        gotoxy(32, 18);
        _red();
        printf("WRONG PASSWORD FOLLOW THE GUIDELINE.");
        _reset();

    }

    return false;

}

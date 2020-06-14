// Coding started date is 18/5/2020 during the lock-down period, Ending date is ....

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>

// Function prototype.

void gotoxy(int, int);
bool _registration_Menu(void);
void _border(int, int);
void _red(void);
void _green(void);
void _reset(void);
bool _sign_Up(void);
void _encryption_And_Decryption(char *);
void _security_Questions(bool);
bool _log_In(void);
bool _verify_User(void);
bool _update_Signed_Up_Information(void);
void _single_Quote_Fixer(char *);
int _menu(void);
void _add_More_Option();
int _space_Remover(char *);
int _delete_Menu(void);
void _column_Maker(void);
void _memory_Allocater(char *);
void _record_Inserter(int , int *, char *, char *, char *);
char _printer(char *);
void _yellow(void);
int _add_New_Column(char *, int);
int _delete_Column_With_All_The_Values(char *, char *, int);
int _search(char *);

int main(void)
{

    char _user_Choice;

    //if (_registration_Menu() == true)
    //{

        _menu();

    //}

    // getch();
    return 0;
}

// -------------------------------------------- DEFINE DAYATYPE -----------------------------------------------

struct REGISTRATION
{

    char _user_Name[20];
    char _password[20];
    char _answer_City[20];
    char _answer_Pet[20];
    char _answer_Vehicle[20];
};
typedef struct REGISTRATION _REGISTRATION;

// -------------------------------------------- GLOBAL VARIABLES ----------------------------------------------

_REGISTRATION _sign_up;

// Function declaration.

// ------------------------------------- EVERYWHERE USEABLE FUNCTIONS --------------------------------------

// gotoxy function for move on the output screen.

void gotoxy(int x, int y)
{
    // Variable.

    COORD _coordinate;

    // Putting coordinate X and Y.

    _coordinate.X = x;
    _coordinate.Y = y;

    // Setting the position.

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _coordinate);
}
void _border(int _height, int _width)
{

    for (int _finish = 2; _height > _finish; _finish++)
    {

        gotoxy(2, _finish);
        printf("|");

        gotoxy(119, _finish);
        printf("|");
    }

    for (int _finish = 1; _width > _finish; _finish++)
    {

        gotoxy(_finish, 0);
        printf("_");

        gotoxy(_finish, 28);
        printf("_");
    }
}
// Color functions

void _red(void)
{

    printf("\033[0;31m");
}

void _green(void)
{

    printf("\033[0;32m");
}

void _yellow(void)
{

    printf("\033[0;33m");

}

void _reset(void)
{

    printf("\033[0m");
}

// Encryption decryption function

void _encryption_And_Decryption(char *_data_pointer)
{



    // The below array is the encryption decryption key.

    char _key[] = {'+', '-', '*', '/'};

    for (int _data_Index = 0; *(_data_pointer + _data_Index) != 0; _data_Index++)
    {
        for (int _key_Index = 0; *(_key + _key_Index) != 0; _key_Index++)
        {
            *(_data_pointer + _data_Index) ^= *(_key + _key_Index);
        }
    }
}

bool _verify_User(void)
{

    system("cls");
    _border(28, 121);
    gotoxy(45, 2);
    printf("--WELCOME TO THE VERIFY YOURSELF--");
    gotoxy(32, 3);
    printf("-----------------------------------------------------------");

    // First fetch all the Singed-up data from data-base or file.

    _REGISTRATION _store_Fetched_Signed_Up_Data;

    FILE *_file_Pointer = fopen("PASSWORD/DATA.txt", "r");

    fscanf(_file_Pointer, "%s", &_store_Fetched_Signed_Up_Data._user_Name);
    _encryption_And_Decryption(&_store_Fetched_Signed_Up_Data._user_Name);

    fscanf(_file_Pointer, "%s", &_store_Fetched_Signed_Up_Data._password);
    _encryption_And_Decryption(&_store_Fetched_Signed_Up_Data._password);

    fscanf(_file_Pointer, "%s", &_store_Fetched_Signed_Up_Data._answer_City);
    _encryption_And_Decryption(&_store_Fetched_Signed_Up_Data._answer_City);

    fscanf(_file_Pointer, "%s", &_store_Fetched_Signed_Up_Data._answer_Pet);
    _encryption_And_Decryption(&_store_Fetched_Signed_Up_Data._answer_Pet);

    fscanf(_file_Pointer, "%s", &_store_Fetched_Signed_Up_Data._answer_Vehicle);
    _encryption_And_Decryption(&_store_Fetched_Signed_Up_Data._answer_Vehicle);

    fclose(_file_Pointer);

    gotoxy(32, 4);
    printf("ENTER YOUR USER-NAME, WHICH ONE YOU USED TO PREVIOUS SIGNED UP TIME :");
    fflush(stdin);
    gets(_sign_up._user_Name);
    _single_Quote_Fixer(&_sign_up._user_Name);

    gotoxy(32, 6);
    printf("ENTER YOUR PASSWORD, WHICH ONE YOU USED TO PREVIOUS SIGNED UP TIME :");
    gets(_sign_up._password);
    _single_Quote_Fixer(&_sign_up._password);

    _security_Questions(false);

    // Strcmp return 0 if both the strings ar equal.

    if (

        (((!strcmp(_store_Fetched_Signed_Up_Data._user_Name, _sign_up._user_Name) && !strcmp(_store_Fetched_Signed_Up_Data._password, _sign_up._password)) && !strcmp(_store_Fetched_Signed_Up_Data._answer_City, _sign_up._answer_City)) && !strcmp(_store_Fetched_Signed_Up_Data._answer_Pet, _sign_up._answer_Pet)) && !strcmp(_store_Fetched_Signed_Up_Data._answer_Vehicle, _sign_up._answer_Vehicle)

    )
    {
        // If all the data are matched.

        return true;
    }
    else
    {

        return false;
    }
}

void _single_Quote_Fixer(char *_address_Of_The_User_Entered_Information){

    for(int _index = 0; *(_address_Of_The_User_Entered_Information + _index) != 0; _index++){

        // If any index contain ' this single quote then it will replace by normal spare " ".

        if(*(_address_Of_The_User_Entered_Information + _index) == 39){

            *(_address_Of_The_User_Entered_Information + _index) = ' ';

        }

    }

}

int _space_Remover(char *_address)
{

    for(int _index = 0; _address[_index] != 0; _index++)
    {

        if(_address[_index] == 32)
        {

            _address[_index] = '-';

        }

    }

}

// ------------------------------------------ REGISTRATION SECTION ---------------------------------------------

// Registration menu.

bool _registration_Menu(void)
{

    system("cls");

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

    // Error handling, Because if user entered any wrong value.
    if ((_selected_Result == 'L' || _selected_Result == 'l') || (_selected_Result == 'U' || _selected_Result == 'u') || (_selected_Result == 'S' || _selected_Result == 's'))
    {

        // Registration

        // Comparing user choice in registration section.

        if (_selected_Result == 'L' || _selected_Result == 'l')
        {

            // This section for LOG-IN.

            // Heading.

            system("cls");
            _border(28, 121);
            gotoxy(45, 2);
            printf("--WELCOME TO THE LOG-IN--");
            gotoxy(32, 3);
            printf("-----------------------------------------------------------");

            if (_log_In() == true)
            {

                // If login successfully.

                return true;
            }
        }
        else if (_selected_Result == 'U' || _selected_Result == 'u')
        {

            if (_update_Signed_Up_Information() == true)
            {

                return true;
            }

            // This section for SIGNED_UP-DATA-UPDATE.
        }
        else
        {

            // This section for SIGN-UP.

            if (_sign_Up() == true)
            {

                // If login successfully.

                return true;
            }
        }
    }
    else
    {

        // If the user want to enter again option.

        gotoxy(32, 19);
        printf("WRONG CHOICE, TRY AGAIN! CLICK A KEY FOR GET A ANOTHER CHANCE.");
        getch();
        system("cls");
        _border(28, 121);

        // When user will exceed maximum number of chance program will be close.

        if (_maximum_Chance > 4)
        {

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

bool _sign_Up(void)
{

    // First check may stored any previous Signed-up data and this section of code for this.

    FILE *_file_Pointer = fopen("PASSWORD/DATA.txt", "a+");

    // Checking file empty or not.

    fseek(_file_Pointer, 0, SEEK_END);

    int _is_Empty = ftell(_file_Pointer);

    fclose(_file_Pointer);

    if (_is_Empty != 0)
    {

        system("cls");
        _border(28, 121);
        gotoxy(45, 2);
        printf("--WELCOME TO THE VERIFY YOURSELF--");
        gotoxy(32, 3);
        printf("-----------------------------------------------------------");

        _red();
        gotoxy(3, 4);
        printf("ALREADY SIGNED-UP, IF YOU WANT REALLY TO DELETE YOUR EXISTING ACCOUNT WITH ALL THE RECORDS WHICH ARE PRESENT AT THE");
        gotoxy(3, 5);
        printf("CURRENT TIME IN THE DATABASE TO DELETE PRESS \'Y\', GO TO THE BACK MENU PRESS \'N\':");
        _reset();

        char _user_Choice = getch();

        if (_user_Choice == 'Y' || _user_Choice == 'y')
        {

            if (_verify_User() == true)
            {

                // Control came here mean the taken data and Signed-up time data both are equal and user give permission to delete all the data.

                remove("PASSWORD/DATA.txt");

                system("cls");
                _border(28, 121);
                gotoxy(45, 2);
                printf("--ALL THE RECORD ARE DELETED--");
                gotoxy(32, 3);
                printf("-----------------------------------------------------------");

                gotoxy(32, 12);
                _green();
                printf("ALL THE RECORD AND YOUR ACCOUNT SUCCESSFULLY DELETED.");
                gotoxy(32, 13);
                _reset();
                printf("PRESS \'E\' FOR THE \'EXIT\' OR \'S\' FOR SIGN UP.");

                char _user_Choice = getch();

                if (_user_Choice == 'e' || _user_Choice == 'E')
                {

                    exit(1);
                }
                else
                {

                    _registration_Menu();
                }
            }
            else
            {

                // When the control came here which mean anywhere the Signed-up data and at the current time taken data these are not equal.

                _red();
                gotoxy(32, 22);
                printf("YOUR ENTERED DATA ARE NOTE MATCHED WITH THE PREVIOUS TIME SIGNED UP DATA.");

                gotoxy(32, 23);
                printf("PRESS E FOR EXIT AND P FOR THE PREVIOUS MENU.");

                char _user_Choice = getch();

                if (_user_Choice == 'e' || _user_Choice == 'E')
                {

                    exit(1);
                }
                else
                {

                    _reset();
                    _registration_Menu();
                }
            }
        }
        else
        {

            // If user selected that user don't need to delete his/her accont the will be redirect to the registration menu.

            _reset();
            _registration_Menu();
        }
    }
    else
    {
        // If don't having any Signed-up data the this below section of code for this.

        system("cls");
        _border(28, 121);
        gotoxy(45, 2);
        printf("--WELCOME TO THE SIGN-UP--");
        gotoxy(32, 3);
        printf("-----------------------------------------------------------");

        // Taking the user name.

        int _user_Name_Length;
        int _exceed_Time = 0;
        int _update_Y_Axis = 8;

        while (1)
        {

            _exceed_Time++;
            _update_Y_Axis++;

            // If the maximum number of attempt are exceed the program will be close.

            if (_exceed_Time == 4)
            {

                _red();
                gotoxy(18, 26);
                printf("YOU EXCEED THE MAXIMUM NUMBER OF TIME ATTEMPT, TRY AGAIN LATER :)");
                getch();
                exit(1);
            }

            gotoxy(18, _update_Y_Axis);
            printf("ENTER YOUR USER-NAME, USER-NAME LENGTH MUST BE GRATER 5 CHARACTER AND LESS 20 CHARACTER: ");

            _update_Y_Axis++;
            gotoxy(18, _update_Y_Axis);
            fflush(stdin);
            gets(_sign_up._user_Name);
            _single_Quote_Fixer(&_sign_up._user_Name);

            _user_Name_Length = strlen(_sign_up._user_Name);

            // If the user name satisfied all the criteria then  this loop will be break.

            if (_user_Name_Length > 5 && _user_Name_Length < 20)
            {

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

        _sign_up._password[20];
        int _password_Length;
        _exceed_Time = 0;
        _update_Y_Axis = 8;

        // Use of this below boolen array is the compare the password's pattern. INDEX 0, 1, 2 will denote the upper-case, lowercase, spacial-charter respectively.

        bool _password_Pattern[3] = {[0 ... 2] = false};

        while (1)
        {

            _exceed_Time++;
            _update_Y_Axis++;

            // If the maximum number of attempt are exceed the program will be close.

            if (_exceed_Time == 4)
            {

                _red();
                gotoxy(32, 22);
                printf("YOU EXCEED THE MAXIMUM NUMBER OF TIME ATTEMPT, TRY AGAIN LATER :)");
                getch();
                exit(1);
            }

            // Instruction message bottom left corner.

            _green();

            gotoxy(32, 26);
            printf("INCLUDE MINIMUM ONE SPECIAL, ONE LOWER, ONE UPPER, CHARACTERS ALSO INCLUDE NUMBERS.");
            gotoxy(32, 27);
            printf("PASSWORD LENGTH SHOULD BE GRATER THEN 8 AND LESS THEN 20.");

            _reset();

            gotoxy(32, _update_Y_Axis);
            printf("ENTER YOUR PASSWORD: ");
            fflush(stdin);
            gets(_sign_up._password);
            _single_Quote_Fixer(&_sign_up._password);

            _password_Length = strlen(_sign_up._password);

            // If the PASSWORD satisfied all the criteria then this loop will be break.

            if (_password_Length > 5 && _password_Length < 20)
            {

                // INDEX 0, 1, 2 will denote the upper-case, lowercase, special-charter respectively.

                for (int _index_Of_Password = 0; _index_Of_Password < _password_Length; _index_Of_Password++)
                {
                    if ((_password_Pattern[1] != true) && (_sign_up._password[_index_Of_Password] >= 97 && _sign_up._password[_index_Of_Password] <= 122))
                    {

                        _password_Pattern[1] = true;
                    }
                    if ((_password_Pattern[0] != true) && (_sign_up._password[_index_Of_Password] >= 65 && _sign_up._password[_index_Of_Password] <= 90))
                    {

                        _password_Pattern[0] = true;
                    }
                    if ((_password_Pattern[2] != true) && ((_sign_up._password[_index_Of_Password] >= 33 && _sign_up._password[_index_Of_Password] <= 47) || (_sign_up._password[_index_Of_Password] >= 58 && _sign_up._password[_index_Of_Password] <= 64) || (_sign_up._password[_index_Of_Password] >= 91 && _sign_up._password[_index_Of_Password] <= 96) || (_sign_up._password[_index_Of_Password] >= 123 && _sign_up._password[_index_Of_Password] <= 126)))
                    {

                        _password_Pattern[2] = true;
                    }
                }
            }

            // If the both the blocks are true then the loop will be break.

            if (_password_Pattern[0] == true && _password_Pattern[1] == true && _password_Pattern[2] == true)
            {

                _encryption_And_Decryption(_sign_up._user_Name);
                _encryption_And_Decryption(_sign_up._password);

                // The control came here mean user-name, password done also security questions asking will be start.

                system("cls");
                _border(28, 121);

                gotoxy(45, 2);
                printf("--WELCOME TO THE SIGN-UP--");
                gotoxy(32, 3);
                printf("-----------------------------------------------------------");

                _security_Questions(true);

                _encryption_And_Decryption(_sign_up._answer_City);
                _encryption_And_Decryption(_sign_up._answer_Pet);
                _encryption_And_Decryption(_sign_up._answer_Vehicle);

                // After successfully done to take User-name, Password And three questions's answer store these data on the file.

                _putting_Sign_Up_Data_On_The_Data_Base(false);

                gotoxy(32, 14);
                printf("SIGN-UP DONE, YOU WILL REDIRECT TO THE MENU, PRESS ANY KEY TO CONTINUE.");
                getch();

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
}

// Security questions

void _security_Questions(bool _permission)
{

    // Recommendation

    if (_permission == true)
    {

        _green();
        gotoxy(32, 26);
        printf("YOU SHOULD TO GIVE TRICKY ANSWERS FOR BETTER SECURITY OF YOUR DATA.");
    }

    // resting text color.

    _reset();

    // First question.

    gotoxy(32, 8);
    printf("WHAT IS YOUR CITY NAME, [LENGTH MUST BE LESS THAN 20 CHRAACTER] :");
    gets(_sign_up._answer_City);
    _single_Quote_Fixer(&_sign_up._answer_City);

    // Second question.

    gotoxy(32, 10);
    printf("MAY YOU HAVE ANY PET, [LENGTH MUST BE LESS THAN 20 CHARACTER] :");
    gets(_sign_up._answer_Pet);
    _single_Quote_Fixer(&_sign_up._answer_Pet);

    // Third question

    gotoxy(32, 12);
    fflush(stdin);
    printf("MAY YOU HAVE ANY VEHICLE, [LENGTH MUST BE LESS THAN 20 CHRAACTER] :");
    gets(_sign_up._answer_Vehicle);
    _single_Quote_Fixer(&_sign_up._answer_Vehicle);

}

// Putting Sign-up data.

void _putting_Sign_Up_Data_On_The_Data_Base(bool _permission_To_Clean_File)
{

    // If need to clean the content the file

    if (_permission_To_Clean_File == true)
    {

        remove("PASSWORD/DATA.txt");
    }

    FILE *_file_Pointer = fopen("PASSWORD/DATA.txt", "a+");

    // Putting User-name.

    fprintf(_file_Pointer, "%s\n", _sign_up._user_Name);

    // Putting Password.

    fprintf(_file_Pointer, "%s\n", _sign_up._password);

    // Putting First question answer.

    fprintf(_file_Pointer, "%s\n", _sign_up._answer_City);

    // Putting Second question answer.

    fprintf(_file_Pointer, "%s\n", _sign_up._answer_Pet);

    // Putting Third question answer.

    fprintf(_file_Pointer, "%s", _sign_up._answer_Vehicle);
}

// Login-in or Sign-up time.

bool _log_In(void)
{

    FILE *_file_Pointer = fopen("PASSWORD/DATA.txt", "r");

    char _fetch_User_Name[20];
    char _fetch_Password[20];
    char _from_User_Username[20];
    char _from_User_Password[20];

    if (_file_Pointer == NULL)
    {

        _red();
        gotoxy(32, 8);
        printf("NO SIGN-UP FOUND.");

        char _user_Choice;

        gotoxy(32, 11);
        _red();
        printf("PRESS R FOR REGISTRATION MENU, E FOR EXIT.");
        _reset();
        fflush(stdin);
        _user_Choice = getch();

        if (_user_Choice == 'R' || _user_Choice == 'r')
        {

            _registration_Menu();
        }
        else
        {

            exit(1);
        }
    }
    else
    {

        // First fetching User-name and Password from file.

        fscanf(_file_Pointer, "%s", &_fetch_User_Name);
        _encryption_And_Decryption(&_fetch_User_Name);

        fscanf(_file_Pointer, "%s", &_fetch_Password);
        _encryption_And_Decryption(&_fetch_Password);

        // Second taking User-name and Password from user.

        gotoxy(32, 8);
        printf("ENTER YOUR USER-NAME, WHICH ONE YOU USED TO PREVIOUS SIGNED UP TIME :");
        fflush(stdin);
        gets(_from_User_Username);
        _single_Quote_Fixer(&_from_User_Username);

        gotoxy(32, 10);
        printf("ENTER YOUR PASSWORD, WHICH ONE YOU USED TO PREVIOUS SIGNED UP TIME :");
        gets(_from_User_Password);
        _single_Quote_Fixer(&_from_User_Password);

        if ((!strcmp(_fetch_User_Name, _from_User_Username) && !strcmp(_fetch_Password, _from_User_Password)))
        {
            // Control came here mean fetched user name and password are matched with taken from user, user name and password.

            return true;
        }
        else
        {

            char _user_Choice;

            gotoxy(4, 27);
            _red();
            printf("YOUR GIVEN USER-NAME AND PASSWORD ARE NOT MATCHED, PRESS T FOR TRAY AGAIN, R FOR REGISTRATION MENU, E FOR EXIT.");
            _reset();
            fflush(stdin);
            _user_Choice = getch();

            if (_user_Choice == 'T' || _user_Choice == 't')
            {

                system("cls");
                _border(28, 121);
                gotoxy(45, 2);
                printf("--WELCOME TO THE LOG-IN--");
                gotoxy(32, 3);
                printf("-----------------------------------------------------------");
                _log_In();
            }
            else if (_user_Choice == 'R' || _user_Choice == 'r')
            {

                _registration_Menu();
            }
            else
            {

                exit(1);
            }
        }
    }
}

// Update Sign-up information

bool _update_Signed_Up_Information(void)
{

    // Checking file empty or not.

    FILE *_file_Pointer = fopen("PASSWORD/DATA.txt", "a+");

    fseek(_file_Pointer, 0, SEEK_END);

    int _is_Empty = ftell(_file_Pointer);

    fclose(_file_Pointer);

    char _user_Choice;

    if (_is_Empty != 0)
    {

        // If Signed-up data found the this section of code for this.

        // First verify the origian user.

        if (_verify_User() == true)
        {

            // Control came here mean user entered correct User-name, password, and security question's answer, So all the information able to update.

            // Heading.

            system("cls");
            _border(28, 121);
            gotoxy(45, 2);
            printf("--WELCOME TO UPDATE SIGNED-UP INFORMATION--");
            gotoxy(32, 3);
            printf("-----------------------------------------------------------");

            FILE *_source_File_Pointer = fopen("PASSWORD/DATA.txt", "r");
            FILE *_destination_File_pointer = fopen("PASSWORD/TEMPORARY.txt", "w");

            char _store_Data[20];

            for (int _loop = 1; _loop <= 5; _loop++)
            {

                fscanf(_source_File_Pointer, "%s", &_store_Data);
                _encryption_And_Decryption(_store_Data);

                if (_loop == 1)
                {

                    gotoxy(3, 6);
                    printf("YOUR USER-NAME IS \"%s\", DO YOU WANT TO UPDATE YOUR USER NAME, PRESS \'Y\' FOR YES, \'N\' FOR NO:", _store_Data);

                    _user_Choice = getch();

                    if (_user_Choice == 'y' || _user_Choice == 'Y')
                    {

                        fflush(stdin);

                        gotoxy(3, 7);
                        printf("ENTER YOUR-USER NAME:");
                        gets(_store_Data);
                        _single_Quote_Fixer(&_store_Data);

                        _encryption_And_Decryption(_store_Data);
                        fprintf(_destination_File_pointer, "%s\n", _store_Data);
                    }
                    else
                    {

                        _encryption_And_Decryption(_store_Data);
                        fprintf(_destination_File_pointer, "%s\n", _store_Data);

                        continue;
                    }
                }
                else if (_loop == 2)
                {

                    gotoxy(3, 9);
                    printf("YOUR PASSWORD IS \"%s\", DO YOU WANT TO UPDATE PASSOWORD, PRESS \'Y\' FOR YES, \'N\' FOR NO:", _store_Data);

                    _user_Choice = getch();

                    if (_user_Choice == 'y' || _user_Choice == 'Y')
                    {

                        fflush(stdin);

                        gotoxy(3, 10);
                        printf("ENTER YOUR PASSWORD:");
                        gets(_store_Data);
                        _single_Quote_Fixer(&_store_Data);

                        _encryption_And_Decryption(_store_Data);
                        fprintf(_destination_File_pointer, "%s\n", _store_Data);
                    }
                    else
                    {

                        _encryption_And_Decryption(_store_Data);
                        fprintf(_destination_File_pointer, "%s\n", _store_Data);

                        continue;
                    }
                }
                else if (_loop == 3)
                {

                    gotoxy(3, 12);
                    printf("YOUR QUESTION'S ONE ANSWER IS \"%s\", TO UPDATE YOUR ANSWER, PRESS \'Y\' FOR YES, \'N\' FOR NO:", _store_Data);

                    _user_Choice = getch();

                    if (_user_Choice == 'y' || _user_Choice == 'Y')
                    {

                        fflush(stdin);

                        gotoxy(3, 13);
                        printf("ENTER YOUR QUESTION'S ONE ANSWER:");
                        gets(_store_Data);
                        _single_Quote_Fixer(&_store_Data);

                        _encryption_And_Decryption(_store_Data);
                        fprintf(_destination_File_pointer, "%s\n", _store_Data);
                    }
                    else
                    {
                        _encryption_And_Decryption(_store_Data);
                        fprintf(_destination_File_pointer, "%s\n", _store_Data);

                        continue;
                    }
                }
                else if (_loop == 4)
                {

                    gotoxy(3, 15);
                    printf("YOUR QUESTION'S TWO ANSWER IS \"%s\", TO UPDATE YOUR QUESTION'S TWO ANSWER, PRESS \'Y\' FOR YES, \'N\' FOR NO:", _store_Data);

                    _user_Choice = getch();

                    if (_user_Choice == 'y' || _user_Choice == 'Y')
                    {

                        fflush(stdin);

                        gotoxy(3, 16);
                        printf("ENTER QUESTION'S TWO ANSWER:");
                        gets(_store_Data);
                        _single_Quote_Fixer(&_store_Data);

                        _encryption_And_Decryption(_store_Data);
                        fprintf(_destination_File_pointer, "%s\n", _store_Data);
                    }
                    else
                    {

                        _encryption_And_Decryption(_store_Data);
                        fprintf(_destination_File_pointer, "%s\n", _store_Data);

                        continue;
                    }
                }
                else
                {

                    gotoxy(3, 18);
                    printf("YOUR QUESTION'S THREE ANSWER IS \"%s\",TO UPDATE YOUR QUESTION'S THREE ANSWER, PRESS \'Y\' FOR YES, \'N\' FOR NO:", _store_Data);

                    _user_Choice = getch();

                    if (_user_Choice == 'y' || _user_Choice == 'Y')
                    {

                        fflush(stdin);

                        gotoxy(3, 19);
                        printf("ENTER QUESTION'S THREE ANSWER:");
                        gets(_store_Data);
                        _single_Quote_Fixer(&_store_Data);

                        _encryption_And_Decryption(_store_Data);
                        fprintf(_destination_File_pointer, "%s", _store_Data);
                    }
                    else
                    {

                        _encryption_And_Decryption(_store_Data);
                        fprintf(_destination_File_pointer, "%s", _store_Data);

                        continue;
                    }
                }
            }

            // All the data are taken, Now taking a conformation to the user may he/she sure to update the informations.

            _green();
            gotoxy(3, 24);

            printf("DO YOU PROCEED ALL THE UPDATE PRESS \'Y\' FOR \'N\' FOR NO.");

            _user_Choice = getch();

            if (_user_Choice == 'Y' || _user_Choice == 'y')
            {

                fclose(_source_File_Pointer);
                fclose(_destination_File_pointer);

                remove("PASSWORD/DATA.txt");
                rename("PASSWORD/TEMPORARY.txt", "PASSWORD/DATA.txt");

                gotoxy(3, 25);
                printf("UPDATE COMPLETE YOU MUST REMEMBER THE NEW INFORMATIONS, YOU WILL REDIRECT TO THE MENU, PRESS ANY KEY TO CONTINUE.");
                getch();
                _reset();

                return true;
            }
            else
            {

                fclose(_source_File_Pointer);
                fclose(_destination_File_pointer);

                remove("PASSWORD/TEMPORARY.txt");

                _reset();
                gotoxy(3, 25);
                printf("UPDATE WAS STOPEED PRESS ANY KEY FOR GO TO THE REGISTRATION MENU.");
                getch();
                _registration_Menu();
            }
        }
        else
        {

            // Control came here mean may be the user entered wrong information or may be the user is dummy.

            _red();
            gotoxy(32, 15);
            printf("YOUR ENTERED INFORMATIONS ARE NOT MATCHED, PLEASE TRY AGAIN LATER.");

            gotoxy(32, 16);
            printf("PRESS \'R\' FOR GO TO THE REGISTRATION MENU, \'E\' FOR EXIT.");
            _reset();

            _user_Choice = getch();

            if (_user_Choice == 'R' || _user_Choice == 'r')
            {

                _registration_Menu();
            }
            else
            {

                exit(1);
            }
        }
    }
    else
    {

        // If didn't found any Singed-up data the this section of code for this.

        system("cls");
        _border(28, 121);
        gotoxy(42, 2);
        printf("--WELCOME TO THE UPDATE SIGNED-UP INFORMATION--");
        gotoxy(32, 3);
        printf("-----------------------------------------------------------");

        _red();
        gotoxy(32, 15);
        printf("SIGNED-UP DATA NO FOUND, DO YOU WANT TO GO BACK THE THE PREVIOUS MENU, PRESS ANY KEY CONFORMATION.");

    }
}

// Menu.

int _menu(void){

    // Heading

    system("cls");
    _border(28, 121);
    gotoxy(50, 2);
    printf("--WELCOME TO THE MENU--");
    gotoxy(32, 3);
    printf("-----------------------------------------------------------");

    FILE *_address_Of_The_Menu_Dot_Txt = fopen("MENU/MENU.txt", "a+");

    char _store_Option[101];
    char _choice_Of_The_User[5];
    char _user_Choice;
    int _serial_Number;
    int _return_Values;

    for(int _update_Y_Axis = 1 ; !feof(_address_Of_The_Menu_Dot_Txt); _update_Y_Axis += 1){

        fscanf(_address_Of_The_Menu_Dot_Txt, "%s", &_store_Option);

        gotoxy(32, 3 + _update_Y_Axis);
        printf("%s", _store_Option);

    }
    fclose(_address_Of_The_Menu_Dot_Txt);

    int _find_Bracket_File;

    for (_find_Bracket_File = 1; *(_store_Option + _find_Bracket_File) != ')'; _find_Bracket_File++);

    char *_Address_of_The_Allocated_Block_1 = (char *) malloc(sizeof(char) * (_find_Bracket_File + 1));

    for (int _index = 0; _index <= (_find_Bracket_File - 1); _index++)
    {

        *(_Address_of_The_Allocated_Block_1 + _index) = *(_store_Option + _index);

    }

    // Assign null at the last of allocated memory.

    *(_Address_of_The_Allocated_Block_1 + _find_Bracket_File) = '\0';

    // Now convert the two (1st is from the File, 2'st is form the User-new-option) fetched serial number from character to integer value.

    int _highest_Serial_Number_Of_The_Menu = atoi(_Address_of_The_Allocated_Block_1);
    free(_Address_of_The_Allocated_Block_1);

    gotoxy(32, 26);
    printf("PRESS \'D\' FOR DELETE OPTION WITH ALL THE RECORDS OF THE PARTICULAR OPTION, AND \'A\' FOR");
    gotoxy(32,27);
    printf("ADD A NEW OPTION.");

    gotoxy(32, 24);
    printf("ENTER THE SERIAL NUMBER OR (D/A) OF YOUR NEEDFULL CHOICE:");
    fflush(stdin);
    gets(_choice_Of_The_User);

    if(*_choice_Of_The_User >= 48 && *_choice_Of_The_User <= 57)
    {

        _serial_Number = atoi(_choice_Of_The_User);

    }

    if ((_serial_Number  <= _highest_Serial_Number_Of_The_Menu && _serial_Number > 0) || (*_choice_Of_The_User == 68 || *_choice_Of_The_User == 100) || (*_choice_Of_The_User == 65 || *_choice_Of_The_User == 97))
    {

        // Let the highest menu is 8, Menu must be lie between the range of less then equal to _highest_Serial_Number_Of_The_Menu and grater then 0.

        // 68 == D and 100 == d through of ASCII.

        if(*_choice_Of_The_User == 68 || *_choice_Of_The_User == 100){

            // If user selected to delete option then control will come here.

            _return_Values = _delete_Menu();
            gotoxy(32, 26);
            if(_return_Values != -1 && _return_Values != 0)
                printf("DELETE SUCCESSFULL, PRESS P FOR GO TO THE PREVIOUS MENU, E FOR THR EXIT:");
            else
                printf("DELETE UNSUCCESSFULL, PRESS P FOR GO TO THE PREVIOUS MENU, E FOR THR EXIT:");

            fflush(stdin);

            scanf("%c", &_user_Choice);

            if(_user_Choice == 'P' || _user_Choice == 'p')
            {

                _menu();

            }
            else
            {

                exit(1);

            }


        }
        // 65 == A and 97 == a through of ASCII.
        else if(*_choice_Of_The_User == 65 || *_choice_Of_The_User == 97)
        {

            // If user selected to Add-More+ option then control will come here.

            _add_More_Option();

            // To add columns in the new option.

            // Heading

            system("cls");
            gotoxy(43, 2);
            printf("--WELCOME TO THE ADD NEW RECORD--");
            gotoxy(32, 3);
            printf("-----------------------------------------------------------");
            _column_Maker();

        }
        else{

            // If user selected any menu then the control will come here.

            // NOW, Finding the path which record user want to open.

            char _store_Path[20];
            FILE *_address_Of_The_Path_Dot_Txt = fopen("MENU/PATH/PATH.txt", "r");

            for (int _where_Pick_Up_The_path = 1; !feof(_address_Of_The_Path_Dot_Txt); _where_Pick_Up_The_path++)
            {


                if(_where_Pick_Up_The_path == _serial_Number)
                {

                    fscanf(_address_Of_The_Path_Dot_Txt, "%s", _store_Path);

                    // NOW, Got the reqired path, Just want to remove the serial number from the path.

                    int _which_Item_Will_Be_Delete_In_Decreasing_Order;
                    int _assign_Assigner;
                    int _total_Length_Of_Each_Menu;

                    for (_which_Item_Will_Be_Delete_In_Decreasing_Order = 1; *(_store_Path + _which_Item_Will_Be_Delete_In_Decreasing_Order) != ')'; _which_Item_Will_Be_Delete_In_Decreasing_Order++);

                    for (; _which_Item_Will_Be_Delete_In_Decreasing_Order != -1; _which_Item_Will_Be_Delete_In_Decreasing_Order--)
                    {

                        _assign_Assigner = _which_Item_Will_Be_Delete_In_Decreasing_Order;
                        _total_Length_Of_Each_Menu = strlen(_store_Path);
                        _total_Length_Of_Each_Menu--;

                        for(; _assign_Assigner <= (_total_Length_Of_Each_Menu - 1); _assign_Assigner++)
                        {

                            _store_Path[_assign_Assigner] = _store_Path[_assign_Assigner + 1];

                        }

                        _store_Path[_assign_Assigner] = '\0';

                    }
                    fclose(_address_Of_The_Path_Dot_Txt);
                    break;

                }

                fscanf(_address_Of_The_Path_Dot_Txt, "%s", _store_Path);

            }

            // NOW, have complete usable path.

            _printer(_store_Path);

        }



    }
    else
    {

        gotoxy(32, 25);
        _red();
        printf("YOU ENTERED A WRONG CHOICE, TO TRY AGAIN PRESS T, TO EXIT PRESS E.");
        scanf("%c", _choice_Of_The_User);


        if(*_choice_Of_The_User == 84 || *_choice_Of_The_User == 116)
        {

            _reset();
            _menu();

        }else
        {

            exit(1);

        }


    }






}

// Add more option

void _add_More_Option(){

    char _which_Menu_Will_Creat_By_The_User[101];
    char _extension[] = ".txt";
    char
    _path[] = "MENU/";
    int _serial_Number_Of_The_New_Menu;
    char _last_Line_Of_Menu_Dot_Txt[101];
    FILE *_address_Of_The_Menu_Dot_Txt = fopen("MENU/MENU.txt", "a+");


    // User giving the name of the new menu.

    system("cls");
    _border(28, 121);
    gotoxy(46, 2);
    printf("--WELCOME TO THE NEW MENU--");
    gotoxy(32, 3);
    printf("-----------------------------------------------------------");

    // Fetch the last line of the MENU.txt

    while(!feof(_address_Of_The_Menu_Dot_Txt)){

        fscanf(_address_Of_The_Menu_Dot_Txt, "%s", &_last_Line_Of_Menu_Dot_Txt);

    }

    // This below section of code to find the next serial number like on the menu file if the last line is 1 then recomendate will be 2

    // Find how many character have (Of the last of the file) from the one index to till before the ')'. Why starting the index from the 1? Answer? >> The lowest number will be 1) like this, It confrom that block 0 never will contain any time ')'. And I want to find where have the ')';

    int _find_Bracket_File;

    for (_find_Bracket_File = 1; *(_last_Line_Of_Menu_Dot_Txt + _find_Bracket_File) != ')'; _find_Bracket_File++);

    char *_Address_of_The_Allocated_Block_1 = (char *) malloc(sizeof(char) * (_find_Bracket_File + 1));

    for (int _index = 0; _index <= (_find_Bracket_File - 1); _index++)
    {

        *(_Address_of_The_Allocated_Block_1 + _index) = *(_last_Line_Of_Menu_Dot_Txt + _index);

    }

    // Assign null at the last of allocated memory.

    *(_Address_of_The_Allocated_Block_1 + _find_Bracket_File) = '\0';

    // Now convert the two (1st is from the File, 2'st is form the User-new-option) fetched serial number from character to integer value.

    int _recomendate_Serial_Number = atoi(_Address_of_The_Allocated_Block_1);
    free(_Address_of_The_Allocated_Block_1);
    _recomendate_Serial_Number++;


    gotoxy(32, 5);
    printf("ENTER THE NAME OF YOUR NEW MENU: [MENU'S NAME MUST BE BETWEEN 100 CHARACTER]");
    fflush(stdin);
    gotoxy(32, 6);
    gets(_which_Menu_Will_Creat_By_The_User);
    _space_Remover(&_which_Menu_Will_Creat_By_The_User);

    // Add the new menu to the MENU.txt file

    fprintf(_address_Of_The_Menu_Dot_Txt, "\n%d)%s.", _recomendate_Serial_Number, _which_Menu_Will_Creat_By_The_User);
    fclose(_address_Of_The_Menu_Dot_Txt);

    // Add the path of the new menu create by the user on the PATH.txt file.

    FILE *_address_Of_The_Path_Dot_Txt = fopen("MENU/PATH/PATH.txt", "a+");
    fprintf(_address_Of_The_Path_Dot_Txt, "\n%d)MENU/%s.txt", _recomendate_Serial_Number, _which_Menu_Will_Creat_By_The_User);

    fclose(_address_Of_The_Path_Dot_Txt);
}

// Delete menu function.

int _delete_Menu(void){

    // When will not have any data on the MENU.txt file ind if this function will call then it is a error the below of code to fix these error.

    FILE *_address_Of_The_Menu_Dot_Txt = fopen("MENU/MENU.txt", "a+");
    fseek(_address_Of_The_Menu_Dot_Txt, 0, 2);
    int _is_Empty = ftell(_address_Of_The_Menu_Dot_Txt);


    if(_is_Empty == 0)
        return -1;

    // When checked file empty or not help of fseek moved the cursor but now it will be fixing.

    fseek(_address_Of_The_Menu_Dot_Txt, 2, 0);

    // When file MENU.txt will contain records then don't will not have any error menu containing related so user may delete records.

    system("cls");
    _border(28, 121);
    gotoxy(45, 2);
    printf("--WELCOME TO THE DELETE A MENU--");
    gotoxy(32, 3);
    printf("-----------------------------------------------------------");


    int _update_Y_Axis = 1;
    int _user_Selected_Result;
    char _to_Store_Menu_Diffrent_Operation[101];
    char _to_Store_Path_Deletion_Time[101];

    for(; !feof(_address_Of_The_Menu_Dot_Txt); _update_Y_Axis++)
    {

        fscanf(_address_Of_The_Menu_Dot_Txt, "%s", &_to_Store_Menu_Diffrent_Operation);
        gotoxy(32, 3 + _update_Y_Axis);
        printf("%s", _to_Store_Menu_Diffrent_Operation);

    }

    gotoxy(32, 4 + _update_Y_Axis);
    printf("ENTER THE SERIAL NUMBER OF THE MENU WHICH MENU YOU WANT TO DELETE, OR PRESS \'P\' TO GO");
    gotoxy(32, 5 + _update_Y_Axis);
    printf("TO THE PREVIOUS MENU:");
    fflush(stdin);
    scanf("%d", &_user_Selected_Result);

    // P == 80 and p == 112

    if(_user_Selected_Result != 'P' || _user_Selected_Result != 'p'){

        // Finding how many menu have on the MENU.txt file.

        int _find_Bracket_File;

        for (_find_Bracket_File = 1; *(_to_Store_Menu_Diffrent_Operation + _find_Bracket_File) != ')'; _find_Bracket_File++);

        char *_Address_of_The_Allocated_Block_1 = (char *) malloc(sizeof(char) * (_find_Bracket_File + 1));

        for (int _index = 0; _index <= (_find_Bracket_File - 1); _index++)
        {

            *(_Address_of_The_Allocated_Block_1 + _index) = *(_to_Store_Menu_Diffrent_Operation + _index);

        }

        // Assign null at the last of allocated memory.

        *(_Address_of_The_Allocated_Block_1 + _find_Bracket_File) = '\0';

        // Now convert the two (1st is from the File, 2st is form the User-new-option) fetched serial number from character to integer value.

        int _quantity_Of_The_Menu = atoi(_Address_of_The_Allocated_Block_1);
        free(_Address_of_The_Allocated_Block_1);

        // Removing the user instructed menu.

        _address_Of_The_Menu_Dot_Txt = fopen("MENU/MENU.txt", "r");
        FILE *_address_Of_The_Path_Dot_Txt = fopen("MENU/PATH/PATH.txt", "r");
        FILE *_address_Of_The_Temporary_MENU_File = fopen("MENU/TEMPORARY_MENU.txt", "w");
        FILE *_address_Of_The_Temporary_PATH_File = fopen("MENU/PATH/TEMPORARY_PATH.txt", "w");

        for(int _where_Will_Skip = 1; _where_Will_Skip <= _quantity_Of_The_Menu; _where_Will_Skip++)
        {

            fscanf(_address_Of_The_Menu_Dot_Txt, "%s", _to_Store_Menu_Diffrent_Operation);
            fscanf(_address_Of_The_Path_Dot_Txt, "%s", _to_Store_Path_Deletion_Time);

            if (_where_Will_Skip != _user_Selected_Result)
            {

                fprintf(_address_Of_The_Temporary_MENU_File, "\n%s", _to_Store_Menu_Diffrent_Operation);
                fprintf(_address_Of_The_Temporary_PATH_File, "\n%s", _to_Store_Path_Deletion_Time);

            }else
            {

                // When the control will be come here, Which mean this path will not be write on the file, That mean help of this path I want to delete this file.

                int _which_Item_Will_Be_Delete_In_Decreasing_Order;
                int _assign_Assigner;
                int _total_Length_Of_Each_Menu;

                for (_which_Item_Will_Be_Delete_In_Decreasing_Order = 1; *(_to_Store_Path_Deletion_Time + _which_Item_Will_Be_Delete_In_Decreasing_Order) != ')'; _which_Item_Will_Be_Delete_In_Decreasing_Order++);

                for (; _which_Item_Will_Be_Delete_In_Decreasing_Order != -1; _which_Item_Will_Be_Delete_In_Decreasing_Order--)
                {

                    _assign_Assigner = _which_Item_Will_Be_Delete_In_Decreasing_Order;
                    _total_Length_Of_Each_Menu = strlen(_to_Store_Path_Deletion_Time);
                    _total_Length_Of_Each_Menu--;

                    for(; _assign_Assigner <= (_total_Length_Of_Each_Menu - 1); _assign_Assigner++)
                    {

                        _to_Store_Path_Deletion_Time[_assign_Assigner] = _to_Store_Path_Deletion_Time[_assign_Assigner + 1];

                    }

                    _to_Store_Path_Deletion_Time[_assign_Assigner] = '\0';

                }

                // Deleting the file which contain this particular option data.
                remove(_to_Store_Path_Deletion_Time);

            }


        }

        fclose(_address_Of_The_Menu_Dot_Txt);
        fclose(_address_Of_The_Path_Dot_Txt);
        fclose(_address_Of_The_Temporary_MENU_File);
        fclose(_address_Of_The_Temporary_PATH_File);

        remove("MENU/MENU.txt");
        remove("MENU/PATH/PATH.txt");
        rename("MENU/TEMPORARY_MENU.txt", "MENU/MENU.txt");
        rename("MENU/PATH/TEMPORARY_PATH.txt", "MENU/PATH/PATH.txt");

        _serial_Number_Fixer();

        return 89;

    }
    else
    {

        // If user don't want to delete menu by mistake may the user came to the delete menu then user may go to the previous menu.

        _menu();
        return 0;

    }


}

// Serial number fixer.

void _serial_Number_Fixer(void){

    FILE *_address_Of_The_Menu_Dot_Txt = fopen("MENU/MENU.txt", "r");
    FILE *_address_Of_Temporary_File_One = fopen("MENU/TEMPORARY_MENU.txt", "w");
    FILE *_address_Of_The_Menu_Path_Txt = fopen("MENU/PATH/PATH.txt", "r");
    FILE *_address_Of_Temporary_File_Two = fopen("MENU/PATH/TEMPORARY_PATH.txt", "w");
    char _store_Menu_And_Path_For_Operations[101];
    int _which_Item_Will_Be_Delete_In_Decreasing_Order;
    int _assign_Assigner;
    int _total_Length_Of_Each_Menu;
    int _serial_Number = 1;

    // This below codes for fix serial number of the MENU.txt.

    while (!feof(_address_Of_The_Menu_Dot_Txt))
    {

        // Storing each menu one by one.

        fscanf(_address_Of_The_Menu_Dot_Txt, "%s", _store_Menu_And_Path_For_Operations);

        for (_which_Item_Will_Be_Delete_In_Decreasing_Order = 1; *(_store_Menu_And_Path_For_Operations + _which_Item_Will_Be_Delete_In_Decreasing_Order) != ')'; _which_Item_Will_Be_Delete_In_Decreasing_Order++);
        _which_Item_Will_Be_Delete_In_Decreasing_Order--;

        for (; _which_Item_Will_Be_Delete_In_Decreasing_Order != -1; _which_Item_Will_Be_Delete_In_Decreasing_Order--)
        {

            _assign_Assigner = _which_Item_Will_Be_Delete_In_Decreasing_Order;
            _total_Length_Of_Each_Menu = strlen(_store_Menu_And_Path_For_Operations);
            _total_Length_Of_Each_Menu--;

            for(; _assign_Assigner <= (_total_Length_Of_Each_Menu - 1); _assign_Assigner++)
            {

                _store_Menu_And_Path_For_Operations[_assign_Assigner] = _store_Menu_And_Path_For_Operations[_assign_Assigner + 1];

            }

            _store_Menu_And_Path_For_Operations[_assign_Assigner] = '\0';

        }

        fprintf(_address_Of_Temporary_File_One, "\n%d%s", _serial_Number, _store_Menu_And_Path_For_Operations);

        _serial_Number++;

    }
    fclose(_address_Of_The_Menu_Dot_Txt);
    fclose(_address_Of_Temporary_File_One);
    remove("MENU/MENU.txt");
    rename("MENU/TEMPORARY_MENU.txt", "MENU/MENU.txt");

    // This below codes for fix serial number of the PATH.txt.

    _which_Item_Will_Be_Delete_In_Decreasing_Order = 0;
    _assign_Assigner = 0;
    _total_Length_Of_Each_Menu = 0;
    _serial_Number = 1;

    while (!feof(_address_Of_The_Menu_Path_Txt))
    {

        // Storing each menu one by one.

        fscanf(_address_Of_The_Menu_Path_Txt, "%s", _store_Menu_And_Path_For_Operations);

        for (_which_Item_Will_Be_Delete_In_Decreasing_Order = 1; *(_store_Menu_And_Path_For_Operations + _which_Item_Will_Be_Delete_In_Decreasing_Order) != ')'; _which_Item_Will_Be_Delete_In_Decreasing_Order++);
        _which_Item_Will_Be_Delete_In_Decreasing_Order--;

        for (; _which_Item_Will_Be_Delete_In_Decreasing_Order != -1; _which_Item_Will_Be_Delete_In_Decreasing_Order--)
        {

            _assign_Assigner = _which_Item_Will_Be_Delete_In_Decreasing_Order;
            _total_Length_Of_Each_Menu = strlen(_store_Menu_And_Path_For_Operations);
            _total_Length_Of_Each_Menu--;

            for(; _assign_Assigner <= (_total_Length_Of_Each_Menu - 1); _assign_Assigner++)
            {

                _store_Menu_And_Path_For_Operations[_assign_Assigner] = _store_Menu_And_Path_For_Operations[_assign_Assigner + 1];

            }

            _store_Menu_And_Path_For_Operations[_assign_Assigner] = '\0';

        }

        fprintf(_address_Of_Temporary_File_Two, "\n%d%s", _serial_Number, _store_Menu_And_Path_For_Operations);

        _serial_Number++;

    }
    fclose(_address_Of_The_Menu_Path_Txt);
    fclose(_address_Of_Temporary_File_Two);
    remove("MENU/PATH/PATH.txt");
    rename("MENU/PATH/TEMPORARY_PATH.txt", "MENU/PATH/PATH.txt");

}

// Column maker

void _column_Maker(void){

    char _store_Menu_And_Path_For_Operations[30];
    int _which_Item_Will_Be_Delete_In_Decreasing_Order;
    int _assign_Assigner;
    int _total_Length_Of_Each_Menu;

    FILE *_address_of_The_Path_Dot_Txt = fopen("MENU/PATH/PATH.txt", "a+");

    while(!feof(_address_of_The_Path_Dot_Txt))
        fscanf(_address_of_The_Path_Dot_Txt, "%s", _store_Menu_And_Path_For_Operations);

    // Deletion the serial of the path.

    for (_which_Item_Will_Be_Delete_In_Decreasing_Order = 1; *(_store_Menu_And_Path_For_Operations + _which_Item_Will_Be_Delete_In_Decreasing_Order) != ')'; _which_Item_Will_Be_Delete_In_Decreasing_Order++);


    for (; _which_Item_Will_Be_Delete_In_Decreasing_Order != -1; _which_Item_Will_Be_Delete_In_Decreasing_Order--)
    {

        _assign_Assigner = _which_Item_Will_Be_Delete_In_Decreasing_Order;
        _total_Length_Of_Each_Menu = strlen(_store_Menu_And_Path_For_Operations);
        _total_Length_Of_Each_Menu--;

        for(; _assign_Assigner <= (_total_Length_Of_Each_Menu - 1); _assign_Assigner++)
        {

            _store_Menu_And_Path_For_Operations[_assign_Assigner] = _store_Menu_And_Path_For_Operations[_assign_Assigner + 1];

        }

        _store_Menu_And_Path_For_Operations[_assign_Assigner] = '\0';

    }

    // Now have the actual file path.

    FILE *_new_Menu = fopen(_store_Menu_And_Path_For_Operations, "a+");

    int _how_Many_Column;
    int _update_Y_Axis = 2;
    char _column_Name[15];
    int _which_Column_Indicator = 1;
    int _maximum_Size_Of_The_Each_Column = 0;

    gotoxy(32, 5);
    printf("ENTER HOW MANY COLUMN YOU WANT TO ADD TO THE NEW OPTION:");
    fflush(stdin);
    scanf("%d", &_how_Many_Column);

    // Allocating interger type memory to store the maximum size of character each of the column.

    while(_how_Many_Column != 0)
    {

        // Taking the column name.

        gotoxy(32, 5 + _update_Y_Axis);
        printf("ENTER YOUR %dST COLUMN NAME [MAXIMUM SIZE 15]:", _which_Column_Indicator);
        fflush(stdin);
        gets(_column_Name);

        // Taking the column size.

        _update_Y_Axis ++;
        gotoxy(32, 5 + _update_Y_Axis);
        printf("ENTER YOUR %dST COLUMN'S SIZE [MAXIMUM SIZE 15]:", _which_Column_Indicator);
        fflush(stdin);
        scanf("%d", &_maximum_Size_Of_The_Each_Column);
        if(_maximum_Size_Of_The_Each_Column > 15)
            _maximum_Size_Of_The_Each_Column = 15;

        _space_Remover(_column_Name);
        fprintf(_new_Menu, "%s(%d),", _column_Name, _maximum_Size_Of_The_Each_Column);

        _how_Many_Column--;
        _update_Y_Axis += 2;
        _which_Column_Indicator++;

    }

    gotoxy(32, 7 + _update_Y_Axis);
    printf("ALL THE COLUMNS ADDED SUCCESSFULLY, PRESS ANY KEY YOU WILL REDIRECT TO THE MAIN MENU");
    getch();

}

// Memory allocater for store record.

void _memory_Allocater(char *_path_Of_The_Selected_Option){

    FILE *_address_Of_The_User_Required_File = fopen(_path_Of_The_Selected_Option, "a+");

    char _store_the_First_Line_Of_User_Reqired_File[200];

    // Taking the first line which line contain all the information like  How many COLUMN, Maximum size of the each column also name of the each column, Of a particualar option.

    fscanf(_address_Of_The_User_Required_File, "%s", _store_the_First_Line_Of_User_Reqired_File);

    // Now, having the raw data which contain all the data which are topward commented mentioned item.

    // Finding how many column have, Simple approach each column seprated by the ',' just counting how many ',' contain the total raw data.

    int _how_Many_Column = 0;
    char _seprate_The_Store_Limition[2];
    int *_limition_Of_Each_Column = (int*) malloc(0);
    int _how_Many_Integer_Data_In_The_First_line = 0;

    for(int _index = 0, _index_For_Allocated_Memory = 0; _store_the_First_Line_Of_User_Reqired_File[_index] != '\0'; _index++){

        if (_store_the_First_Line_Of_User_Reqired_File[_index] == '(')
        {
            // _seprate_The_Store_Limition MEAN limitation character of each column.

            _seprate_The_Store_Limition[0] = _store_the_First_Line_Of_User_Reqired_File[_index + 1];
            _seprate_The_Store_Limition[1] = _store_the_First_Line_Of_User_Reqired_File[_index + 2];

            if(_store_the_First_Line_Of_User_Reqired_File[_index + 1] >= 48 && _store_the_First_Line_Of_User_Reqired_File[_index + 1] <= 57)
            {

                _how_Many_Integer_Data_In_The_First_line++;

            }

            if(_store_the_First_Line_Of_User_Reqired_File[_index + 2] >= 48 && _store_the_First_Line_Of_User_Reqired_File[_index + 2] <= 57)
            {

                _how_Many_Integer_Data_In_The_First_line++;

            }

        }


        if(_store_the_First_Line_Of_User_Reqired_File[_index] == ',')
        {

            _how_Many_Column++;
            realloc(_limition_Of_Each_Column, sizeof(int) * _how_Many_Column);
            *(_limition_Of_Each_Column + _index_For_Allocated_Memory) = atoi(_seprate_The_Store_Limition);
            _index_For_Allocated_Memory++;

        }


    }

    // Now calculating how many blocks required to store All the column name sparated by any NULL character.

    /*

        (_how_Many_Column * 2) = Total brackets.
        _how_Many_Integer_Data_In_The_First_line = All the limition characters.
        _how_Many_Column = All the comma.
        (_how_Many_Column - 1) = Required spacess to seprate the columns name.

    */

    int _Calculating_Size_To_Store_Column = (strlen(_store_the_First_Line_Of_User_Reqired_File) - (_how_Many_Column * 2) - _how_Many_Integer_Data_In_The_First_line - _how_Many_Column) + (_how_Many_Column - 1);

    char *_store_Each_Column_Name = (char*) malloc(sizeof(char) * (_Calculating_Size_To_Store_Column));

    // Seprating the column name from the first line which mean the raw data.

    int _index_For_Assign = 0;

    for(int _index_For_Traves_The_Raw_Data = 0, _index_Jumper = 0; _store_the_First_Line_Of_User_Reqired_File[_index_For_Traves_The_Raw_Data] != '\0'; _index_For_Traves_The_Raw_Data++, _index_For_Assign++)
    {

        if(_store_the_First_Line_Of_User_Reqired_File[_index_For_Traves_The_Raw_Data] == '(')
        {

            if(*(_limition_Of_Each_Column + _index_Jumper) / 2 > 4)
            {

                *(_store_Each_Column_Name + _index_For_Assign) = '\0';
                _index_Jumper++;
                _index_For_Traves_The_Raw_Data += 4;
                if(_store_the_First_Line_Of_User_Reqired_File[_index_For_Traves_The_Raw_Data + 1] == '\0')
                {

                    break;

                }
                continue;

            }else
            {

                *(_store_Each_Column_Name + _index_For_Assign) = '\0';
                _index_Jumper++;
                _index_For_Traves_The_Raw_Data += 3;
                if(_store_the_First_Line_Of_User_Reqired_File[_index_For_Traves_The_Raw_Data + 1] == '\0')
                {

                    break;

                }
                continue;

            }


        }

        *(_store_Each_Column_Name + _index_For_Assign) = _store_the_First_Line_Of_User_Reqired_File[_index_For_Traves_The_Raw_Data];


    }

    *(_store_Each_Column_Name + _index_For_Assign) = '\0';

    /*

    NOW,Finding the highest number from the limitation, When will take record from the user will store the record here
    temporary, EX: If the highest limition 8 under 8 limition will come all the column's value.

    */

    // Finding the highest number.

    int _store_The_Highest_Number = *_limition_Of_Each_Column;

    for(int _index = 1; _index < _how_Many_Column; _index++)
    {

        if (*(_limition_Of_Each_Column + _index) > _store_The_Highest_Number)
        {

            _store_The_Highest_Number = *(_limition_Of_Each_Column + _index);

        }


    }

    char *_here_Will_Store_All_The_Record_Temporary = (char*) malloc(sizeof(char) * _store_The_Highest_Number);

    _record_Inserter(_how_Many_Column, _limition_Of_Each_Column, _store_Each_Column_Name, _here_Will_Store_All_The_Record_Temporary, _path_Of_The_Selected_Option);

    fclose(_address_Of_The_User_Required_File);
    free(_limition_Of_Each_Column);
    free(_store_Each_Column_Name);
    free(_here_Will_Store_All_The_Record_Temporary);
}

// Record insert function.

void _record_Inserter(int _how_Many_Column, int *_limition_Of_Each_Column, char *_store_Each_Column_Name, char *_here_Will_Store_All_The_Record_Temporary, char *_path_Of_The_Selected_Option)
{

    system("cls");
    gotoxy(43, 2);
    printf("--WELCOME TO THE ADD NEW RECORD--");
    gotoxy(32, 3);
    printf("-----------------------------------------------------------");

    int _index_Healper = 0;

    // Opening file where will be store data.
    FILE *_address_Of_Where_Will_Store_Data = fopen(_path_Of_The_Selected_Option, "a+");
    fprintf(_address_Of_Where_Will_Store_Data, "\n");
    for(int _index = 0; _how_Many_Column > _index; _index++)
    {

        gotoxy(32, 5 + _index);
        printf("ENTER THE %s [MAXIMUM %d CHARACTERS IS ALLOWED]", _store_Each_Column_Name + _index_Healper, *(_limition_Of_Each_Column + _index));
        fflush(stdin);
        gets(_here_Will_Store_All_The_Record_Temporary);
        fprintf(_address_Of_Where_Will_Store_Data, "%s~", _here_Will_Store_All_The_Record_Temporary);

        _index_Healper += (strlen(_index_Healper + _store_Each_Column_Name) + 1);
    }

    fclose(_address_Of_Where_Will_Store_Data);

}

// Printer

char _printer(char *_path_Of_The_Selected_Option)
{

    char _user_Choice;

    system("cls");

    FILE *_delete_Item_Have_To_Print = fopen(_path_Of_The_Selected_Option, "r");

    char _store_File_To_Print[122] = {[0 ... 121] = '\0'};
    char _a_Copy_Of_First_Line[200];
    int _length_Of_The_First_Line;

    // Checking file empty or not.

    fseek(_delete_Item_Have_To_Print, 0, 2);
    int _is_Empty = ftell(_delete_Item_Have_To_Print);

    // Reopen the same file.

    fclose(_delete_Item_Have_To_Print);
    _delete_Item_Have_To_Print = fopen(_path_Of_The_Selected_Option, "r");

    if(_is_Empty != 0)
    {

        // Commands.

        printf("1)A FOR ADD A RECORD.\n2)D FOR DELETE A RECORD.\n3)C FOR ADD MORE COLUMN.\n4)R FOR REMOVE A COLUMN.\n5)S FOR SEARCH.\n6)U FOR UPDATE.\n7)B FOR BACK.\n8)M FOR THE MAIN MENU.\n");

        // This downward code will be print a line on the x axis.

        _yellow();

        for (int _line = 1; _line <= 122; _line++)
        {

            printf("-");

        }

        _reset();

        int _how_Many_Column = 0;
        char _store_The_Fetched_Line_From_User_Reqired_File[200] = {[0 ... 119] = '\0'};

        // Taking the first line which line contain all the information like  How many COLUMN, Maximum size of the each column also name of the each column, Of a particualar option.

        fscanf(_delete_Item_Have_To_Print, "%s", _store_The_Fetched_Line_From_User_Reqired_File);

        // Finding the how many column existing.

        for(int _index = 0; _store_The_Fetched_Line_From_User_Reqired_File[_index] != '\0'; _index++)
        {

            if(_store_The_Fetched_Line_From_User_Reqired_File[_index] == ',')
            {

                _how_Many_Column++;

            }


        }

        /*

            Allocating memory crossepondig size to the _how_Many_Column, Let having 3 column allocate will be 3 integer blocks.

            Purpose to allocate theese memory blocks?

            Answer => To store the highest size of each column.

            EXAMPLE:
            => Let, Having 2 columns F.name(15), F.price(5) respectively.

                    F.name  F.price
            row 1   Mango   12
            row 2   Apple   122
            row 3   Banana  50

            Now imagine these are teh allocated 2 memory blocks => |String length of the 'Banana'|Price length of the 'Apple'|


        */

        int *_address_Of_The_Allocated_Memory = (int*) malloc(sizeof(int) * _how_Many_Column);

        // In the first line of required file deleting all the Numeric character and bracket also replace

        strcpy(_a_Copy_Of_First_Line, _store_The_Fetched_Line_From_User_Reqired_File);

        _length_Of_The_First_Line  = strlen(_a_Copy_Of_First_Line);

        // The downward code will delete all the numeric character and brackets.

        for (int _traves_The_Total_Array = 0; _a_Copy_Of_First_Line[_traves_The_Total_Array] != '\0'; _traves_The_Total_Array++)
        {



            if ((_a_Copy_Of_First_Line[_traves_The_Total_Array] >= 48 && _a_Copy_Of_First_Line[_traves_The_Total_Array] <= 57) || (_a_Copy_Of_First_Line[_traves_The_Total_Array] == '(') || (_a_Copy_Of_First_Line[_traves_The_Total_Array] == ')'))
            {
                _length_Of_The_First_Line--;
                int _which_Element_Will_Be_Delete = _traves_The_Total_Array;

                for(;_a_Copy_Of_First_Line[_which_Element_Will_Be_Delete + 1] != '\0'; _which_Element_Will_Be_Delete++)
                {

                    _a_Copy_Of_First_Line[_which_Element_Will_Be_Delete] = _a_Copy_Of_First_Line[_which_Element_Will_Be_Delete + 1];

                }

                _a_Copy_Of_First_Line[_which_Element_Will_Be_Delete] = '\0';
                _traves_The_Total_Array--;

            }

            if(_a_Copy_Of_First_Line[_traves_The_Total_Array] == ','){

                _a_Copy_Of_First_Line[_traves_The_Total_Array] = '\0';

            }

        }

        // On the allocated memory assigning the length of each column name's.

        for(int _index_Jumper = 0, _index_For_Assign = 0; _index_Jumper < _length_Of_The_First_Line - 1; _index_For_Assign++)
        {

            *(_address_Of_The_Allocated_Memory + _index_For_Assign) = strlen(_a_Copy_Of_First_Line + _index_Jumper);
            _index_Jumper += (strlen(_a_Copy_Of_First_Line  + _index_Jumper) + 1);

        }

        // Comparing.

        // The down-ward exta 2 line of code because of want to open the record from the second line.

        fseek(_delete_Item_Have_To_Print, 2, 0);
        fscanf(_delete_Item_Have_To_Print, "%s", _store_The_Fetched_Line_From_User_Reqired_File);

        int _second_line_Length = strlen(_store_The_Fetched_Line_From_User_Reqired_File);

        while(!feof(_delete_Item_Have_To_Print))
        {
            fscanf(_delete_Item_Have_To_Print, "%s", _store_The_Fetched_Line_From_User_Reqired_File);

            _second_line_Length = strlen(_store_The_Fetched_Line_From_User_Reqired_File);

            // Replace the Conjugate-Character(~) by NULL, The conjugate seprated the each column vale in a row.

            for(int _index = 0; _store_The_Fetched_Line_From_User_Reqired_File[_index] != '\0'; _index++)
            {

                if(_store_The_Fetched_Line_From_User_Reqired_File[_index] == '~')
                {

                    _store_The_Fetched_Line_From_User_Reqired_File[_index] = '\0';

                }

            }

            for(int _index_Jumper = 0, _store_Value_To_Comapre, _index_To_Compare = 0; _index_Jumper < _second_line_Length - 1; _index_To_Compare++)
            {

                _store_Value_To_Comapre = strlen(_store_The_Fetched_Line_From_User_Reqired_File + _index_Jumper);

                _index_Jumper += strlen(_store_The_Fetched_Line_From_User_Reqired_File + _index_Jumper) + 1;

                if(_store_Value_To_Comapre > *(_address_Of_The_Allocated_Memory + _index_To_Compare))
                {

                   *(_address_Of_The_Allocated_Memory + _index_To_Compare) = _store_Value_To_Comapre;

                }

            }

        }

        // Printing the column name.

        _green();

        int _accsee_Allocated_Blocks = 0;
        int _index_Jumper = 0;
        int _string_Length;
        int _middle_Balancer;
        int _sum_All_The_Values_Of_Allocated_Blocks = 0;

        for(; _index_Jumper < _length_Of_The_First_Line - 1; _accsee_Allocated_Blocks++)
        {

            _string_Length = strlen(_a_Copy_Of_First_Line + _index_Jumper);

            _middle_Balancer = (*(_address_Of_The_Allocated_Memory + _accsee_Allocated_Blocks) - _string_Length) / 2;

            if(_middle_Balancer)
            {

                gotoxy(_middle_Balancer + _sum_All_The_Values_Of_Allocated_Blocks, 9);

                printf("%s", _a_Copy_Of_First_Line + _index_Jumper);

                _sum_All_The_Values_Of_Allocated_Blocks += *(_address_Of_The_Allocated_Memory + _accsee_Allocated_Blocks) + 1;

                gotoxy(_sum_All_The_Values_Of_Allocated_Blocks, 9);

            }else
            {
                printf("%s", _a_Copy_Of_First_Line + _index_Jumper);

                _sum_All_The_Values_Of_Allocated_Blocks += *(_address_Of_The_Allocated_Memory + _accsee_Allocated_Blocks) + 1;

                gotoxy(_sum_All_The_Values_Of_Allocated_Blocks, 9);

            }

            _index_Jumper += ((_string_Length) + 1);

        }

        _reset();

        // Making table for print the table.

        int _update_Y_Axis;
        int _update_X_Axis = 0;

        int _record_Length;

        for(int _index = 0; _index < (_how_Many_Column); _index++)
        {

            fseek(_delete_Item_Have_To_Print, 2, 0);
            fscanf(_delete_Item_Have_To_Print, "%s", _store_The_Fetched_Line_From_User_Reqired_File);

            _update_X_Axis += *(_address_Of_The_Allocated_Memory + _index) + 1;
            _update_Y_Axis = 9;

            while(!feof(_delete_Item_Have_To_Print))
            {

                _yellow();

                fscanf(_delete_Item_Have_To_Print, "%s", _store_The_Fetched_Line_From_User_Reqired_File);
                gotoxy(_update_X_Axis - 1, _update_Y_Axis);
                printf("|");
                _update_Y_Axis++;

                // Print a straight line on the x axis.

                gotoxy(0, _update_Y_Axis);

                for (int _line = 1; _line <= 122; _line++)
                {


                    printf("-");

                }

                _record_Length = strlen(_store_The_Fetched_Line_From_User_Reqired_File);

                // Replace the Conjugate-Character(~) by NULL, The conjugate seprated the each column vale in a row.

                for(int _index = 0; _store_The_Fetched_Line_From_User_Reqired_File[_index] != '\0'; _index++)
                {

                    if(_store_The_Fetched_Line_From_User_Reqired_File[_index] == '~')
                    {

                        _store_The_Fetched_Line_From_User_Reqired_File[_index] = '\0';

                    }

                }

                _reset();

                for(int _index_Jumper = 0, _index_For_Assign = 0, _sum_Of_The_Allocated_Memory_Value = 0, _store_Length_Temporary; _index_Jumper < _record_Length - 1; _index_For_Assign++)
                {

                    printf("%s", _store_The_Fetched_Line_From_User_Reqired_File + _index_Jumper);

                    _store_Length_Temporary = strlen(_store_The_Fetched_Line_From_User_Reqired_File + _index_Jumper);

                    _index_Jumper += (strlen(_store_The_Fetched_Line_From_User_Reqired_File  + _index_Jumper) + 1);

                    _sum_Of_The_Allocated_Memory_Value += *(_address_Of_The_Allocated_Memory + _index_For_Assign) + 1;

                    gotoxy(_sum_Of_The_Allocated_Memory_Value, _update_Y_Axis + 1);

                }

                _update_Y_Axis++;

            }


        }


        // Printing the last line.

        _update_X_Axis = 0;

        _yellow();

        for(int _index = 0; _index < (_how_Many_Column); _index++)
        {

            _update_X_Axis += *(_address_Of_The_Allocated_Memory + _index) + 1;
            gotoxy(_update_X_Axis - 1, _update_Y_Axis);
            printf("|");

        }

        printf("\n");

        for (int _line = 1; _line <= 122; _line++)
        {

            printf("-");

        }

        _reset();

        gotoxy(0, 4 + _update_Y_Axis);
        printf("ENTER YOUR CHOICE:");
        fflush(stdin);
        scanf("%c", &_user_Choice);

        fclose(_delete_Item_Have_To_Print);
        free(_address_Of_The_Allocated_Memory);

    }
    else
    {

        // Control came here mean don't have any data on the file.

        system("cls");
        gotoxy(48, 2);
        printf("--DON'T FOUND ANY RECORD--");
        gotoxy(32, 3);
        printf("-----------------------------------------------------------");

        _red();
        gotoxy(32, 8);
        printf("DON'T FOUND ANY RECORD, HIT ANY KEY FOR GO TO THE MENU.");

        _reset();

        // Commands.

        gotoxy(32, 11);
        printf("1)A FOR ADD A RECORD.");

        gotoxy(32, 13);
        printf("2)D FOR DELETE A RECORD.");

        gotoxy(32, 15);
        printf("3)C FOR ADD MORE COLUMN.");

        gotoxy(32, 17);
        printf("4)R FOR REMOVE A COLUMN.");

        gotoxy(32, 19);
        printf("5)S FOR SEARCH.");

        gotoxy(32, 21);
        printf("6)U FOR UPDATE.");

        gotoxy(32, 23);
        printf("7)B FOR BACK.");

        gotoxy(32, 25);
        printf("8)M FOR THE MAIN MENU.");

        _reset();

        char _user_Choice;

        gotoxy(32, 28);
        printf("ENTER YOUR CHOICE:");
        fflush(stdin);
        scanf("%c", &_user_Choice);

    }

    if(_user_Choice == 'A' || _user_Choice == 'a')
    {

        /*

            In the _memory_Allocater function sending the path which option user will open. Then the memory allocater will fetch all the the first a line
            (METADATA OF COLUMNS) and after process memory allocater will produce COLUMN-NAME, COLUMN-LIMITION and store all
            these data then this function will call _recoed_Inserter function where will send all the data which produce by this
            function and the one by one _recoed_Inserter will show all the COLUMN-NAME, COLUMN-LIMITION and will take data from
            the user then taken data will be store on the file.

        */

        _memory_Allocater(_path_Of_The_Selected_Option);

        _printer(_path_Of_The_Selected_Option);

    }
    else if(_user_Choice == 'D' || _user_Choice == 'd')
    {

        int _serial_Number_Of_delete_Item_Will_Be_Delete;

        printf("ENTER THE SERIAL NUMBER WHICH ROW YOU WANT TO DELETE:");
        scanf("%d", &_serial_Number_Of_delete_Item_Will_Be_Delete);

        _delete_Record(_path_Of_The_Selected_Option, _serial_Number_Of_delete_Item_Will_Be_Delete);

    }
    else if(_user_Choice == 'C' || _user_Choice == 'c')
    {

        int _How_Many_Column_User_Want_To_Enter;

        printf("ENTER HOW MANY COLUMN YOU WANT ADD:");
        scanf("%d", &_How_Many_Column_User_Want_To_Enter);

        _add_New_Column(_path_Of_The_Selected_Option, _How_Many_Column_User_Want_To_Enter);

    }
    else if(_user_Choice == 'R' || _user_Choice == 'r')
    {

        _delete_Column_With_All_The_Values(_path_Of_The_Selected_Option, _a_Copy_Of_First_Line, _length_Of_The_First_Line);

    }
    else if(_user_Choice == 'S' || _user_Choice == 's')
    {

        _search(_path_Of_The_Selected_Option);

    }
    else if(_user_Choice == 'U' || _user_Choice == 'u')
    {

        // Code here...

    }
    else if(_user_Choice == 'B' || _user_Choice == 'b')
    {

        // Code here...

    }
    else if(_user_Choice == 'M' || _user_Choice == 'm')
    {

        // Code here...

    }else
    {

        // Code here...

    }

}

// Delete record.

int _delete_Record(char *_path_Of_The_Selected_Option, int _serial_Number_Of_delete_Item_Will_Be_Delete)
{

    system("cls");

    FILE *_actual_File = fopen(_path_Of_The_Selected_Option, "r");
    FILE *_temporary_File = fopen("MENU/TEMPORARY_RECORD.txt", "w");
    char _swap_Container[150] = {[0 ... 149] = '\0'};

    if(_actual_File == NULL)
    {

        _red();
        gotoxy(32, 8);
        printf("SOMETHING WRONG, PRESS ANY KEY TO CONTINUE.");
        return 0;

    }
    else
    {

        int _delete_Item = 1;
        int _which_Line = 1;
        int _how_Many_Record = 0;
        bool _engine_Can_Start = false;
        int _serial_Number;
        char _store_Serial[10];
        int _index;
        int _total_Length_Of_Each_Record;


        // Finding end of the file.

        while (!feof(_actual_File))
        {

            fscanf(_actual_File, "%s", _swap_Container);
            _how_Many_Record++;

        }

        _how_Many_Record--;

        // Reset file.
        fclose(_actual_File);
        _actual_File = fopen(_path_Of_The_Selected_Option, "r");

        // In this function will be delete will be only the record not any COLUMN name related data, For this first placeing the column name.
        fscanf(_actual_File, "%s", _swap_Container);
        fprintf(_temporary_File, "%s", _swap_Container);

        if(_how_Many_Record > 1)
        {

            fprintf(_temporary_File, "\n");

        }

        while(!feof(_actual_File))
        {

            fscanf(_actual_File, "%s", _swap_Container);

            if(_serial_Number_Of_delete_Item_Will_Be_Delete == _delete_Item)
            {

                _delete_Item++;
                _engine_Can_Start = true;

                for(_index = 0; _swap_Container[_index] != ')'; _index++)
                {

                    _store_Serial[_index] = _swap_Container[_index];

                }

                _serial_Number = atoi(_store_Serial);

                continue;

            }

            /*

                Each record have a serial number like,
                1)A
                2)B
                3)C
                4)D
                .....
                So, Problem is when will delete any record, Let now 2)B.
                Serial number will not be change automatically, EX

                1)A
                3)C
                4)D

                But serial number must be,

                1)A
                2)C
                3)D

                till before fprint() code will be for this problem.

            */

            // Finding bracket.

            for(_index = 0; _swap_Container[_index] != ')'; _index++);
            _index--;

            if(_engine_Can_Start == true)
            {

                for (int _assign_Assigner; _index != -1; _index--)
                {

                    _assign_Assigner = _index;
                    _total_Length_Of_Each_Record = strlen(_swap_Container);
                    _total_Length_Of_Each_Record--;

                    for(; _assign_Assigner <= (_total_Length_Of_Each_Record - 1); _assign_Assigner++)
                    {

                        _swap_Container[_assign_Assigner] = _swap_Container[_assign_Assigner + 1];

                    }

                    _swap_Container[_assign_Assigner] = '\0';

                }
                fprintf(_temporary_File, "%d%s", _serial_Number, _swap_Container);

                _serial_Number++;

            }
            else
            {

                fprintf(_temporary_File, "%s", _swap_Container);

            }

            _delete_Item++;
            _which_Line++;

            if(_how_Many_Record != _which_Line)
            fprintf(_temporary_File, "\n");

        }

        fclose(_actual_File);
        fclose(_temporary_File);


        if(!remove(_path_Of_The_Selected_Option))
        {

            rename("MENU/TEMPORARY_RECORD.txt", _path_Of_The_Selected_Option);
            _green();
            gotoxy(32, 8);
            printf("RECORD DELETED SUCCESSFULLY, PRESS ANY KEY TO CONTINUE.");
            getch();
            _reset();

        }
        else
        {

            _red();
            gotoxy(32, 8);
            printf("RECORD NOT DELETED SUCCESSFULLY, PRESS ANY KEY TO CONTINUE.");
            getch();
            _reset();
            remove("MENU/TEMPORARY_RECORD.txt");

        }

    }

    _printer(_path_Of_The_Selected_Option);


}

// Add new column function

int _add_New_Column(char *_path_Of_The_Selected_Option, int _How_Many_Column_User_Want_To_Enter)
{

    system("cls");

    FILE *_actual_File = fopen(_path_Of_The_Selected_Option, "r");
    FILE *_temporary_File = fopen("MENU/TEMPORARY_RECORD.txt", "w");
    char _swap_Container[500] = {[0 ... 499] = '\0'};
    int _limitation_Size;
    int _update_Y_Axis = 8;
    int _how_Many_Record = 0;
    int _which_Line = 1;

    if(_actual_File == NULL)
    {

        _red();
        gotoxy(32, 8);
        printf("SOMETHING WRONG, PRESS ANY KEY TO CONTINUE.");
        _printer(_path_Of_The_Selected_Option);
        return 0;

    }

    // Finding end of the file.

    while (!feof(_actual_File))
    {

        fscanf(_actual_File, "%s", _swap_Container);
        _how_Many_Record++;

    }

   // Reset file.

    fclose(_actual_File);
    _actual_File = fopen(_path_Of_The_Selected_Option, "r");

    // Printing the already stored column.

    fscanf(_actual_File, "%s", _swap_Container);
    fprintf(_temporary_File, "%s", _swap_Container);

    // Adding new column.

    for(int _stop = 1; _How_Many_Column_User_Want_To_Enter >= _stop; _stop++)
    {

        gotoxy(32 ,_update_Y_Axis);
        printf("ENTER THE %dST COLUMN NAME:", _stop);
        fflush(stdin);
        gets(_swap_Container);

        _update_Y_Axis++;
        gotoxy(32 ,_update_Y_Axis);
        printf("ENTER THE LIMITION SIZE OF %dST COLUMN [SIZE MUST BE LESS THEN 15]:", _stop);
        fflush(stdin);
        scanf("%d", &_limitation_Size);

        if(_limitation_Size > 15)
            _limitation_Size = 15;

        fprintf(_temporary_File, "%s(%d),", _swap_Container, _limitation_Size);

        _update_Y_Axis += 2;


    }

    fprintf(_temporary_File, "\n");

    // Printing already stored data.

    while (!feof(_actual_File))
    {

        fscanf(_actual_File, "%s", _swap_Container);
        fprintf(_temporary_File, "%s", _swap_Container);

        _which_Line++;

        if(_how_Many_Record != _which_Line)
        fprintf(_temporary_File, "\n");

    }

    fclose(_actual_File);
    fclose(_temporary_File);

    remove(_path_Of_The_Selected_Option);
    rename("MENU/TEMPORARY_RECORD.txt", _path_Of_The_Selected_Option);
    _green();
    gotoxy(32, 2 + _update_Y_Axis);
    printf("COLUMN ADDED SUCCESSFULLY, PRESS ANY KEY TO CONTINUE.");
    getch();
    _reset();
    _printer(_path_Of_The_Selected_Option);

}

// Delete column with all the record of the particular column.

int _delete_Column_With_All_The_Values(char *_path_Of_The_Selected_Option, char *_The_Columns_Names, int _length_Of_The_First_Line_Receiver)
{

    system("cls");

    // Printing the existing column name.

    _red();
    printf("\n\n  IF YOU DELETE ANY COLUMN NAME, THEN ALL THE RECORD OF THE PARTICULAR COLUMN WILL BE DELETE.\n\n");
    _reset();

    int _serial_Number = 1;
    for(int _index_Jumper = 0; _index_Jumper < _length_Of_The_First_Line_Receiver - 1; _serial_Number++)
    {

        _yellow();
        printf("  %d)", _serial_Number);
        _reset();

        printf(" %s\n", _The_Columns_Names + _index_Jumper);
        _index_Jumper += (strlen(_The_Columns_Names  + _index_Jumper) + 1);

    }

    // Taking from the user which column user want to delete.

    int _serial_Number_Of_delete_Item;


    printf("\n  ENTER THE SERIAL NUMBER WHICH COLUMN NAME YO WANT TO DELETE:");
    fflush(stdin);
    scanf("%d", &_serial_Number_Of_delete_Item);

    if(!(_serial_Number_Of_delete_Item >= 1 && _serial_Number_Of_delete_Item <= (_serial_Number - 1)))
    {

        _red();
        printf("\n  YOU ENTERED A WRONG SERIAL NUMBER, TRY AGAIN LATER, PRESS ANY KEY TO CONTINUE");
        getch();
        _reset();
        _printer(_path_Of_The_Selected_Option);
        return 0;

    }

    // Delete section.

    FILE *_actual_File = fopen(_path_Of_The_Selected_Option, "r");
    FILE *_temporary_File = fopen("MENU/TEMPORARY_RECORD.txt", "w");
    char _swap_Container[500] = {[0 ... 499] = '\0'};

    // Operation for column.
    // Taking the column line or column metadata.

    fscanf(_actual_File, "%s", _swap_Container);
    int _row_Length = strlen(_swap_Container);

    // Now having the column metadata, Replacing all the ',' character by NULL.

    for (int _index = 0; _swap_Container[_index] != '\0'; _index++)
    {

        if (_swap_Container[_index] == ',')
        {

            _swap_Container[_index] = '\0';

        }


    }

    // Printing the columns and column's metedata.

    for(int _index_Jumper = 0, _delete_Item = 1; _index_Jumper < _row_Length - 1; _delete_Item++)
    {

        if (_serial_Number_Of_delete_Item == _delete_Item)
        {

            _index_Jumper += (strlen(_swap_Container  + _index_Jumper) + 1);
            continue;

        }

        fprintf(_temporary_File, "%s,", _swap_Container + _index_Jumper);
        _index_Jumper += (strlen(_swap_Container  + _index_Jumper) + 1);


    }

    // Column matter done, Now deleteing the crossponding record.

    int _serial_Number_For_Choice_1 = 1;

    while(!feof(_actual_File))
    {

        fscanf(_actual_File, "%s", _swap_Container);
        _row_Length = strlen(_swap_Container);

        for (int _index = 0; _swap_Container[_index] != '\0'; _index++)
        {

            if (_swap_Container[_index] == '~')
            {

                _swap_Container[_index] = '\0';

            }


        }

        int _delete_Item = 1;

        fprintf(_temporary_File, "\n");
        if(_serial_Number_Of_delete_Item == 1)
        {

            fprintf(_temporary_File, "%d)", _serial_Number_For_Choice_1);
            _serial_Number_For_Choice_1++;

        }

        for(int _index_Jumper = 0; _index_Jumper < _row_Length - 1; _delete_Item++)
        {

            if (_serial_Number_Of_delete_Item == _delete_Item)
            {

                _index_Jumper += (strlen(_swap_Container  + _index_Jumper) + 1);
                continue;

            }

            fprintf(_temporary_File, "%s~", _swap_Container + _index_Jumper);
            _index_Jumper += (strlen(_swap_Container  + _index_Jumper) + 1);

        }

    }

    fclose(_actual_File);
    fclose(_temporary_File);

    remove(_path_Of_The_Selected_Option);
    rename("MENU/TEMPORARY_RECORD.txt", _path_Of_The_Selected_Option);
    _green();
    printf("\n\n  COLUMN DELETED SUCCESSFULLY, PRESS ANY KEY TO CONTINUE.");

    _reset();
    _printer(_path_Of_The_Selected_Option);
    return 0;

}

// Search.

int _search(char *_path_Of_The_Selected_Option)
{

    char _keyword[100] = {[0 ... 99] = '\0'};
    int _keyword_Length;
    char _store_Record_For_Operation[500] = {[0 ... 499] = '\0'};
    bool _is_Matched_Any_Record = false;
    int _starting_Point;
    int _starting_Metadata;
    int _ending_Metadata;

    system("cls");

    // Taking the keyword which user want to search.

    printf("\n\n ENTER THE KEYWORD WHICH YOU WANT TO SEARCH:");
    fflush(stdin);
    gets(_keyword);

    _keyword_Length = strlen(_keyword);
    char*_store_Sub_String = (char*) malloc(sizeof(char) * _keyword_Length);
    *(_store_Sub_String + _keyword_Length) = '\0';


    // Opening the file which user open.

    FILE *required_File = fopen(_path_Of_The_Selected_Option, "r");
    int _row_Length;

    // Ignoring the first line.
    fscanf(required_File, "%s", _store_Record_For_Operation);

    printf("\n\n");

    while(!feof(required_File))
    {

        fscanf(required_File, "%s", _store_Record_For_Operation);

        // Replacing the conjugate (~) character by null

        _row_Length = strlen(_store_Record_For_Operation);

        for (int _index = 0; _store_Record_For_Operation[_index] != '\0'; _index++)
        {

            if (_store_Record_For_Operation[_index] == '~')
            {

                _store_Record_For_Operation[_index] = '\0';

            }

        }



        for(int _index_Jumper = 0; _index_Jumper < _row_Length - 1; )
        {

            // The is statement to determine can user key word is grater-than from the record.

            if(!(strlen(_store_Record_For_Operation  + _index_Jumper) >= _keyword_Length))
            {

                _index_Jumper += (strlen(_store_Record_For_Operation  + _index_Jumper) + 1);
                continue;

            }

            _starting_Point = _index_Jumper;


            for(int _execution_Time = 1; (_execution_Time + (_keyword_Length - 1)) <= strlen(_store_Record_For_Operation + _index_Jumper); _execution_Time++)
            {

                _starting_Metadata = _starting_Point;
                for(int _inner_Execution = 1, _assigner = 0; _inner_Execution <= _keyword_Length; _starting_Point++, _assigner++, _inner_Execution++)
                {
                    _store_Sub_String[_assigner] = _store_Record_For_Operation[_starting_Point];

                }

                if (!(strcmp(_store_Sub_String, _keyword)))
                {

                     _ending_Metadata = _starting_Point;
                    _ending_Metadata--;
                    _is_Matched_Any_Record = true;
                    break;

                }

                _starting_Point -= (_keyword_Length - 1);
            }

            if (!(strcmp(_store_Sub_String, _keyword)))
            {

                printf(" ");
                for (int _index = 0; _index < _row_Length; _index++)
                {

                    if(_index >= _starting_Metadata && _index <= _ending_Metadata)
                    _yellow();
                    else
                    _reset();

                    printf("%c", *(_store_Record_For_Operation + _index));

                }
                printf("\n\n");
                break;

            }

            _index_Jumper += (strlen(_store_Record_For_Operation  + _index_Jumper) + 1);

        }

    }

    // Message.

    if(_is_Matched_Any_Record == true)
    {

        _green();
        printf("\n THESE ARE ALL THE MATCHED RECORD, PRESS ANY KEY TO CONTINUE");

    }
    else
    {

        _red();
        printf("\n ANY RECORD DOSE NOT MATCHED, PRESS ANY KEY TO CONTINUE");

    }
    _reset();

    fclose(required_File);
    getch();
    _printer(_path_Of_The_Selected_Option);

}

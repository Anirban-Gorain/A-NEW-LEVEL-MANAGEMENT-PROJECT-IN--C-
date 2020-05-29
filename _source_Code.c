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

int main(void)
{

    _delete_Menu();

    // if (_registration_Menu() == true)
    // {

    //     printf("DONE");
    // }

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
    int _choice_Of_The_User;

    for(int _update_Y_Axis = 1 ;!feof(_address_Of_The_Menu_Dot_Txt); _update_Y_Axis += 1){

        fscanf(_address_Of_The_Menu_Dot_Txt, "%s", &_store_Option);

        gotoxy(32, 3 + _update_Y_Axis);
        printf("%s", _store_Option);

    }
    gotoxy(32, 27);
    printf("PRESS \'D\' FOR DELETE OPTION WITH ALL THE RECORDS OF THE PARTICULAR OPTION, AND \'A\' FOR ADD A NEW OPTION.");

    getch();
    _add_More_Option();

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
    gotoxy(50, 2);
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

    // Assing null at the last of allocated memory.

    *(_Address_of_The_Allocated_Block_1 + _find_Bracket_File) = '\0';

    // Now convert the two (1st is from the File, 2st is form the User-new-option) fetched serial number from character to integer value.

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

    fprintf(_address_Of_The_Menu_Dot_Txt, "\n\n%d)%s.", _recomendate_Serial_Number, _which_Menu_Will_Creat_By_The_User);

    // Add the path of the new menu create by the user on the PATH.txt file.

    FILE *_address_Of_The_Path_Dot_Txt = fopen("MENU/PATH/PATH.txt", "a+");
    fprintf(_address_Of_The_Path_Dot_Txt, "\n%d)MENU/%s.txt", _recomendate_Serial_Number, _which_Menu_Will_Creat_By_The_User);


}

// Delete menu function.

int _delete_Menu(void){

    system("cls");
    _border(28, 121);
    gotoxy(45, 2);
    printf("--WELCOME TO THE DELETE A MENU--");
    gotoxy(32, 3);
    printf("-----------------------------------------------------------");
    int _update_Y_Axis = 1;

    FILE *_address_Of_The_Menu_Dot_Txt = fopen("MENU/MENU.txt", "a+");
    int _user_Selected_Result;
    char _to_Store_Menu_Diffrent_Operation[101];
    char _to_Store_Path_Deletion_Time[101];

    for(; !feof(_address_Of_The_Menu_Dot_Txt); _update_Y_Axis++)
    {

        fscanf(_address_Of_The_Menu_Dot_Txt, "%s", &_to_Store_Menu_Diffrent_Operation);
        gotoxy(32, 3 + _update_Y_Axis);
        printf("%s", _to_Store_Menu_Diffrent_Operation);

    }
    fclose(_address_Of_The_Menu_Dot_Txt);

    gotoxy(32, 4 + _update_Y_Axis);
    printf("ENTER THE SERIAL NUMBER OF THE MENU WHICH MENU YOU WANT TO DELETE:");
    fflush(stdin);
    scanf("%d", &_user_Selected_Result);

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

}

// Serial number fixer.

void _serial_Number_Fixer(void){

    FILE *_address_Of_The_Menu_Dot_Txt = fopen("MENU/MENU.txt", "r");
    FILE *_address_Of_Temporary_File_One = fopen("MENU/TEMPORARY_MENU.txt", "a+");
    FILE *_address_Of_The_Menu_Path_Txt = fopen("MENU/PATH/PATH.txt", "r");
    FILE *_address_Of_Temporary_File_Two = fopen("MENU/PATH/TEMPORARY_PATH.txt", "a+");
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

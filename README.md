# 'A NEW LAEAL MANAGEMENT SYSTEM' IN 'C'.
Develop by **'Anirban Gorain'**  In 2020, During the lockdown period.

------------
# DESCRIPTION: 

------------


The entire project related basic type of dynamic management system, **Dynamic** means the user can add, delete, and modify all the Columns, Rows, All the specific items, Option names, etc. As well as all the stored data will be print in **tabular** format.

------------
# DEVELOPMENT ENVIRONMENT SETUP

Only need c/c++ IDE EX(Code-blocks, dev-c++). And change your console font-size into **24** and font into **consolas** to get a great viwe.

# INTRODUCING  ALL THE FUNCTIONS WHICH ARE USED:

------------
》<b>`void gotoxy(int, int):`</b>  This function used because to move text and symbols from the one place to another place.

》<b>`bool _registration_Menu(void):`</b>  Generally, this function uses to show all the registration-related information like Sign-up, Login, Update-sign-up-information, etc. After taking user choice according to the printed information it will call another function. If the user puts any wrong information then it will handle the errors.

》<b>`void _border(int, int):`</b> directly when this function will call it will print border according to the specified parameter's value, The first parameter representing the Y-axis or height of the border and similarly the second one representing the X-axis means the width of the border. 28, 121 natural value respectively.

》<b>`void _red(void):`</b> When this function will be calling the entire items of the console will be red;

》<b>`void _green(void):`</b> When this function will be calling the entire items of the console will be green.

》<b>`void _yellow(void):`</b> When this function will be calling the entire items of the console will be yellow;

》<b>`void _reset(void):`</b> When this function will be calling the entire item color of the console will be reset (Default color).

》<b>`bool _sign_Up(void):`</b>  First, the function will check that **DATA.txt** file empty or not if empty then it will give functionality to **Sign-up**. As well as if file **DATA.txt** is not empty then it will give functionality to the user can delete his/her account with all the records.

》<b>`void _encryption_And_Decryption(char *):`</b> As an argument, this function will take the address of a char type array or variable. The work of this function is the help of a defined key EX:(A2101_@) it will do **Encrypt**the data which taken by the help of the **POINTER**  as well as **Encrypt ** the **Decrypted** data by the help of the same key.

》<b>`void _security_Questions(bool):`</b> As an argument, this function will take permission to print a message, or not. Then one by one it will ask three **Security-Questions** and current time all the answers will store on a globally defined variable.

》<b>`bool _log_In(void):`</b> When the user will select the login on the startup interface then this function will be called. This function will check can DATA.txt is empty or not. If empty then it will show ERROR and how the user can solve the error. If DATA.txt is not empty then it will give functionality to users can LOG-IN.

》<b>`bool _verify_User(void)`</b> Directly this function will fetch **Signed-up** data from the **DATA.txt** and will be **Decrypt** all the data then It will take from the user all the information **EX:**(Username, Password, etc) Then will be compare fetched data and taken data is all information are same or equal this function will return **TRUE** otherwise if not matched the will return **FALSE**.

》<b>`bool _update_Signed_Up_Information(void)`</b> The first function will check the file empty or not empty. If **EMPTY** then it will show error and how the user can solve the error. If the file is **NOT EMPTY** then the function will **VERIFY** to the user if the **VERIFICATION** successful then the user can update his/her information. If **VERIFICATION** is unsuccessful the function will show **ERROR** and the user will redirect to the **REGISTRATION** menu.

》<b>`void _single_Quote_Fixer(char *_address_Of_The_User_Entered_Information)`</b> Generally, as an argument this function will take the base address of char array if the array will contain any **SINGLE-QUOTE** then this function will replace the **SINGLE-QUOTE** by **SPACE**.

》<b>`int _menu(void)`</b> First will check file file empty or not. If **EMPTY** then it will show error message then will provide the functionality of the user can add a new option. If the file is **NOT-EMPTY** then the user can add new options as well as user can be open existing options.

》<b>`void _add_More_Option(int _highest_Serial_Number_Of_The_Menu)`</b> This function will help to add new option.

》<b>`int _space_Remover(char *_address)`</b> This function will take as an argument base address of char array if the array contains any **SPACE**, Then space will replace by the **-**.

》<b>`int _delete_Menu(void)`</b> If **MENU.txt** file does not contain any menu then this function will be show error, And if the file in the menu file contains any menu then the function will take a serial number which menu user want to delete currently the menu will be deleted from the **MENU.txt** as well as will be deleted path of the menu from the **PATH.txt** and will delete the actual file which contains all the data of the particular option.

》<b>`void _column_Maker(void)`</b> Generally as an argument this function will take an integer number this integer number will denote how many column users want to add, Then one by one it will take the name of new column and limitation of each column this information will be store on required file.

》<b>`void _memory_Allocator(char *)`</b> The work of this function is to find how-many-column, limitation-of-each-column, store name of each column, generate memory to store temporary record (at one time one record), the path of the selected option by the user, recommended serial number (last serial number of options).

》<b>`void _record_Inserter(int , int *, char *, char *, char *, int)`</b> This function take 5 arguments, The arguments are how-many-column, limitation-of-each-column, store name of each column, generate memory to store temporary record (at one time one record), the path of the selected option by the user, recommended serial number (last serial number of options) respectively after taking this data this function able to append a new record on the specific function.

》<b>`char _printer(char *)`</b> As a argument this function take path of open option or menu. According to the sent path, This function first will check can file contain any data or not contain, If don't contain any data mean particular option doesn't have any column name this function will show error related this matter and if the user wants to add column names then this function will give functionality to the user can add columns name. If the file containing data then 1st will find the maximum length of each column 2nd printing the column names, 3rd print the table and stored record, 4th will make a choice from the user according to the user choice will call another function EX(can be called like delete record, add a new column, etc).

》<b>`int _add_New_Column(char *, int)`</b> This function takes the path of open option or menu and an integer value the integer value will denote how many column user want to add. This function will help to add a new column name.

》<b>`int _delete_Column_With_All_The_Values(char *, char *, int)`</b> This function will take the path of the open option or menu, Column name which one will be deleted, Length of the first line. The help of this function user will able to delete a specific column in a specific option with all the record of the column which column user want to delete.

》<b>`int _search(char *)`</b> This function take path of open option or menu. The search function 1st will take a character or string from the use which one user want to search in the total record of a specific option or menu, 2st from the specific option one by one will take each of the rows **(EACH ROW == one record)** then will be generate substring (Equal length of the taken string from the user) current time will be generate substring of record the two substring generated will be compared. If anyone matched then the entire record will be print.

》<b>`int _update(char *, int)`</b> This function will take two arguments 1st path of open option or menu and 2nd is a serial number which record or row user want to update. Then will be fetched one by one each column name and theirs values or records and the column name and value will demonstrate to the user if the user wants to update the specific column's value then the user will press **Y** and he/he can update the information otherwise **S** to skip and so on till the end of the column.

 # SCREENSHOTS OF THIS PROJECT
 
------------
### Authentication or startup view
![Authentication](https://github.com/Anirban-Gorain/A-NEW-LEVEL-MANAGEMENT-PROJECT-IN--C-/blob/master/_screenshots/_authentication_Image.png)

 ### Authentication failed view
![Authentication faild viwe](https://github.com/Anirban-Gorain/A-NEW-LEVEL-MANAGEMENT-PROJECT-IN--C-/blob/master/_screenshots/_third_Error_Handling_Image.png)

### Options or menu viwe
![Options or menu](https://github.com/Anirban-Gorain/A-NEW-LEVEL-MANAGEMENT-PROJECT-IN--C-/blob/master/_screenshots/_menu_Image.png)

### Options or menu related error view
![Options or menu related error](https://github.com/Anirban-Gorain/A-NEW-LEVEL-MANAGEMENT-PROJECT-IN--C-/blob/master/_screenshots/_second_Error_Handling_Image.png)

### Record related error view
![Record related error viwe](https://github.com/Anirban-Gorain/A-NEW-LEVEL-MANAGEMENT-PROJECT-IN--C-/blob/master/_screenshots/_one_Eroor_Handling_Image.png)

### Options to operate the software view
![Options to operate the software](https://github.com/Anirban-Gorain/A-NEW-LEVEL-MANAGEMENT-PROJECT-IN--C-/blob/master/_screenshots/_inner_Menu_Image.png)

### Printed record view
![Printed record](https://github.com/Anirban-Gorain/A-NEW-LEVEL-MANAGEMENT-PROJECT-IN--C-/blob/master/_screenshots/_tabular_Image.png)

##### SOCIAL LINKS

[<img src="https://img.icons8.com/material/24/000000/linkedin--v1.png"/>](https://www.linkedin.com/in/anirban-gorain-2bb20419b/ "LINKEDIN")
[<img src="https://img.icons8.com/material-outlined/24/000000/facebook-f.png"/>](https://www.facebook.com/anirban.gorain.73 "FACEBOOK")
[<img src="https://img.icons8.com/material/24/000000/instagram-new--v1.png"/>](https://www.instagram.com/_anirban_gorain_/ "FACEBOOK")

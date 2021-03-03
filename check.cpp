/**
 * Copyright © 2020-2021
 * Master: Masoud Pour Zahmatkesh
 * Author: Ehsan Sarzendeh
 * Email: ehsansarzendeh@gmail.com
 * 
 * @file check.cpp
 * @file check.hpp
 * @file data_file.dat
 * 
 * *This program is made to record user checks
 */ 

#include <iostream>
#include <string>
#include "check.hpp"

using namespace std;

int main()
{
    system ("cls");
    char menu;

    while (true)
    {
        menu = showMenu();

        if (menu == '1')
        {
            system("cls");
            newCheck();
            system("pause");
        }
        else if (menu == '2')
        {
            system("cls");
            editCheck();
            system("pause");
        }
        else if (menu == '3')
        {
            system("cls");
            deleteCheck();
            system("pause");
        }
        else if (menu == '4')
        {
            system("cls");
            searchCheckByNumber();
            system("pause");
        }
        else if (menu == '5')
        {
            system("cls");
            searchCheckByName();
            system("pause");
        }
        else if (menu == '6')
        {
            system("cls");
            searchCheckByDate();
            system("pause");
        }
        else if (menu == '7')
        {
            system("cls");
            listAllChecks();
            system("pause");
        }
        else if (menu == '8')
        {
            break;
        }

        system("cls");
    }
    
    return 0;
}
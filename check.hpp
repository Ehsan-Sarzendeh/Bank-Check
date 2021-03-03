#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

fstream dataFile;

struct Check
{
    int number;
    int date;
    int amount;
    string personName;
};

Check check;

vector<Check> checks;

/**
 * This function displays the program menu
 * @return {char} result: User-selected menu
 */
char showMenu()
{
    char result;
    cout << "***** Program Menu *****" << endl << endl;
    cout << "1. New check" << endl;
    cout << "2. Edit check" << endl;
    cout << "3. Delete check" << endl;
    cout << "4. Search check by number" << endl;
    cout << "5. Search check by name" << endl;
    cout << "6. Search check by date" << endl;
    cout << "7. List All checks" << endl;
    cout << "8. Exit" << endl;
    cout << endl;
    cout << "Please select an option: ";
    result = cin.get();
    return result;
}

/**
 * This function get the data related to the check from the user
 * !menu : 1
 */
void newCheck()
{
    cout << "   *** Add a new check ***  " << endl;
    cout << endl;
    cout <<"Enter the check number: "; 
    cin >> check.number;
    cout << "Enter the date (year-month-day): ";
    cin >> check.date;
    cout << "Enter the amount: ";
    cin >> check.amount;
    cout << "Enter the person name: ";
    cin.ignore();
    getline(cin, check.personName);
    cout << endl;

    dataFile.open("data_file.dat", ios::out | ios::app | ios::binary);
    dataFile.write((char *) &check, sizeof(check));
    dataFile.close();
}

/**
 * This function changes the data related to the requested check
 * !menu : 2
 */
void editCheck()
{
    int number;
    cout << "Enter the check number that you want to edit: ";
    cin >> number;
    system ("cls");

    dataFile.open("data_file.dat", ios::in | ios::binary);
    while (dataFile.read((char *) &check, sizeof(check)))
    {
        checks.push_back(check);
    }
    dataFile.close();

    for (int index = 0; index < checks.size(); index++)
    {
        if (number == checks[index].number)
        {
            cout << "   *** The Current data ***  " << endl;
            cout << endl;
            cout << "check number      --> " << checks[index].number << endl;
            cout << "check date        --> " << checks[index].date << endl;
            cout << "check amount      --> " << checks[index].amount << endl;
            cout << "check person name --> " << checks[index].personName << endl;
            cout << endl;
            system ("pause");
            system ("cls");

            cout << "   *** Enter the new data ***  " << endl;
            cout << endl;
            cout << "Enter the check number: ";
            cin >> checks[index].number;
            cout << "Enter the date(year-month-day): ";
            cin >> checks[index].date;
            cout << "Enter the amount: ";
            cin >> checks[index].amount;
            cout << "Enter the person name: ";
            cin.ignore();
            getline(cin, checks[index].personName);
            cout << endl;

            dataFile.open("data_file.dat", ios::out | ios::binary | ios::trunc);
            for (int index = 0; index < checks.size(); index++)
            {
                check = checks[index];
                dataFile.write((char *) &check, sizeof(check));
            }
            dataFile.close();

            break;
        }
        else if (checks[index].number == checks.back().number)
        {
            cerr << "This check number is not registered." << endl << endl;
            break;
        }
    }
    checks.clear();
}

/**
 * This function delete requested check
 * !menu : 3
 */
void deleteCheck()
{
    int number;
    cout << "Enter the check number that you want to delete: ";
    cin >> number;
    system ("cls");

    dataFile.open("data_file.dat", ios::in | ios::binary);
    while (dataFile.read((char *) &check, sizeof(check)))
    {
        checks.push_back(check);
    }
    dataFile.close();

    for (int index = 0; index < checks.size(); index++)
    {
        if (number == checks[index].number)
        {
            cout << "Are you sure that you want to delete check number " << number <<" ?" << endl;
            cout << "1. Yes" << "\t\t" << "2. No" << endl << endl;
            cout << "Enter your selection: ";
            char selection;
            cin.ignore();
            selection = cin.get();

            if (selection == '1')
            {
                system ("cls");
                checks.erase(checks.begin() + index);
                cout << "Check number " << number << " deleted." << endl << endl;

                dataFile.open("data_file.dat", ios::out | ios::binary | ios::trunc);
                for (int index = 0; index < checks.size(); index++)
                {
                    check = checks[index];
                    dataFile.write((char *) &check, sizeof(check));
                }
                dataFile.close();

                break;
            }
            else if (selection == '2')
            {
                break;
            }
        }
        else if (checks[index].number == checks.back().number)
        {
            cerr << "This check number is not registered." << endl << endl;
            break;
        }
    }
    checks.clear();
}

/**
 * This function displays the data for the requested check by number Check
 * !menu : 4
 */
void searchCheckByNumber()
{
    int number;
    cout << "Enter the check number that you want to displays: ";
    cin >> number;
    system ("cls");

    dataFile.open("data_file.dat", ios::in | ios::binary);
    while (dataFile.read((char *) &check, sizeof(check)))
    {
        checks.push_back(check);
    }
    dataFile.close();

    for (int index = 0; index < checks.size(); index++)
    {
        if (number == checks[index].number)
        {
            cout << "   *** Displays the data *** " << endl;
            cout << endl;
            cout << "check number      --> " << checks[index].number << endl;
            cout << "check date        --> " << checks[index].date << endl;
            cout << "check amount      --> " << checks[index].amount << endl;
            cout << "check person name --> " << checks[index].personName << endl;
            cout << endl;
            break;
        }
        else if (checks[index].number == checks.back().number)
        {
            cerr << "This check number is not registered." << endl << endl;
            break;
        }
    }
    checks.clear();
}

/**
 * This function displays the data for the requested check by person name
 * !menu : 5
 */
void searchCheckByName()
{
    string name;
    cout << "Enter the check person name that you want to displays: ";
    cin.ignore();
    getline(cin, name);
    system("cls");

    dataFile.open("data_file.dat", ios::in | ios::binary);
    while (dataFile.read((char *) &check, sizeof(check)))
    {
        checks.push_back(check);
    }
    dataFile.close();

    for (int index = 0; index < checks.size(); index++)
    {
        if (checks[index].personName.find(name) != -1)
        {
            cout << endl;
            cout << "check number      --> " << checks[index].number << endl;
            cout << "check date        --> " << checks[index].date << endl;
            cout << "check amount      --> " << checks[index].amount << endl;
            cout << "check person name --> " << checks[index].personName << endl;
            cout << endl;
            if (checks[index].personName == checks.back().personName)
                break;
            else
                continue;
        }
        else if (checks[index].number == checks.back().number)
        {
            for (int i = index; i >= 0; i--)
            {
                if (checks[i].personName.find(name) != -1)
                    goto jump;
            }
            cerr << "This person name is not registered." << endl << endl;
            jump:
            break;

        }
    }
    checks.clear();
}

/**
 * This function displays the data for the requested check by date
 * !menu : 6
 */
void searchCheckByDate()
{
    int fromDate;
    int toDate;
    cout << "Enter the period of date that you want" << endl;
    cout << "From: ";
    cin >> fromDate;
    cout << "To  : ";
    cin >> toDate;

    dataFile.open("data_file.dat", ios::in | ios::binary);
    while (dataFile.read((char *) &check, sizeof(check)))
    {
        checks.push_back(check);
    }
    dataFile.close();

    for (int i = 0; i < checks.size()-1; i++)
    {
        for (int j = i+1; j < checks.size(); j++)
        {
            if (checks[i].date > checks[j].date)
            {
                Check temp;
                temp = checks[i];
                checks[i] = checks[j];
                checks[j] = temp;
            }
        }
    }

    for (int index = 0; index < checks.size(); index++)
    {
        if (fromDate <= checks[index].date && checks[index].date <= toDate)
        {
            cout << endl;
            cout << "check number      --> " << checks[index].number << endl;
            cout << "check date        --> " << checks[index].date << endl;
            cout << "check person name --> " << checks[index].personName << endl;
            cout << "check amount      --> " << checks[index].amount << endl;
            cout << endl;
            if (checks[index].number == checks.back().number)
                break;
            else
                continue;
        }
        else if (checks[index].date == checks.back().date)
        {
            for (int i = index; i >= 0; i--)
            {
                if (fromDate <= checks[i].date && checks[i].date <= toDate)
                    goto jump;
            }
            cout << endl;
            cerr << "In this period of date no checks have been registered." << endl << endl;
            jump:
            break;
        }
    }
    checks.clear();
}

/**
 * This function displays the all checks sorted by date
 * !menu : 7
 */
void listAllChecks()
{
    dataFile.open("data_file.dat", ios::in | ios::binary);
    while (dataFile.read((char *) &check, sizeof(check)))
    {
        checks.push_back(check);
    }
    dataFile.close();

    if (checks.size() == 0)
    {
        cout << "No checks have been registered." << endl << endl;
        return;
    }

    cout << " **** Displays the all checks sorted by date **** " << endl;
    cout << endl;

    for (int i = 0; i < checks.size()-1; i++)
    {
        for (int j = i+1; j < checks.size(); j++)
        {
            if (checks[i].date > checks[j].date)
            {
                Check temp;
                temp = checks[i];
                checks[i] = checks[j];
                checks[j] = temp;
            }
        }
    }

    for (int index = 0; index < checks.size() ; index++)
    {
        cout << "      *** Check " << index+1 << " ***" << endl;
        cout << "check number      --> " << checks[index].number << endl;
        cout << "check date        --> " << checks[index].date << endl;
        cout << "check amount      --> " << checks[index].amount << endl;
        cout << "check person name --> " << checks[index].personName << endl;
        cout << "----------------------------------------" << endl;
    }

    checks.clear();
}
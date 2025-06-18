#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <map>
using namespace std;

void savefeature(map<string, string> &tabl, string &opfile)
{
    map<string, string>::iterator it = tabl.begin();
    ofstream out(opfile, ios::app);
    while (it != tabl.end())
    {
        out << it->first << " --> " << it->second << endl;
        it++;
    }
}
int main()
{
    system("title Arpan's password vault");

    system("cls");
    while (true)
    {
        cout << "------INPUT MODE-------" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "---TYPE use TO USE A FILE " << endl;
        cout<<endl;
        cout << "---PRESS ENTER TO GO TO FILE CREATION WINDOW" << endl;
        cout<<endl;
        cout << "---TYPE delete TO GO TO FILE DELETION WINDOW" << endl;
        cout<<endl;
        cout << "---TYPE open TO GO TO SEE CONTENTS OF A FILE" << endl;
        cout<<endl;
        cout << "---TYPE tree TO VIEW ALL THE DOCUMENTS" << endl;
        cout<<endl;
        cout << "---TYPE exit TO EXIT THE APP" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "                                                      " << endl;
        cout << "Input Operation: ";

        string basic;
        getline(cin, basic);
        if (basic == "use")
        {
            system("cls");
            cout << "Type the file name to be used , enter back to go to main menu" << endl;
            cout << "----------------------------------------------------------------" << endl;
            string filename;
            getline(cin, filename);
            map<string, string> table;
            if (filename == "back")
            {
                system("cls");
            }
            else
            {

                while (true)
                {
                    system("cls");
                    cout << "opened and using " << filename << endl;
                    cout << "-----------------------------------------------------" << endl;
                    cout << "Enter back to go to main menu" << endl;
                    string appp;
                    string passwor;
                    cout << "App name->";
                    getline(cin, appp);
                    if (appp == "back")
                    {
                        savefeature(table, filename);
                        system("cls");
                        break;
                    };
                    if (appp == "show")
                    {
                        string buff;
                        system("cls");
                        cout << "-------------------------" << endl;
                        map<string, string>::iterator it = table.begin();

                        while (it != table.end())
                        {
                            cout << it->first << " --> " << it->second << endl;
                            it++;
                        }
                        getline(cin, buff);
                        system("cls");
                    }
                    else
                    {
                        cout << "Enter Password->";
                        getline(cin, passwor);
                        table.insert(make_pair(appp, passwor));
                        system("cls");
                    }
                }
            }
        }
        else if (basic == "tree")
        {
            system("cls");
            system("tree /f /a");
        }
        else if (basic == "exit")
        {
            system("cls");
            break;
        }else if(basic=="open"){
            system("cls");
            cout<<"Type name of the file to view its contents,enter back to go back to the main menu"<<endl;
             cout<<"--------------------------------------------------------------------------------"<<endl;
            string filetobeopened;
            getline(cin,filetobeopened);
            ifstream in(filetobeopened);
            string output;
            output="0";
            if(filetobeopened=="back"){
                system("cls");
                
            }else{
            system("cls");
            while(output.size()!=0){

                getline(in,output);
                cout<<output<<endl;
            }
        }
        }
        else if (basic == "delete")
        {
            system("cls");
            string deletefile;
            cout << "Type file name to be deleted,type back to go to main menu" << endl;
            cout << "------------------------------" << endl;
            getline(cin, deletefile);
            if (deletefile == "back")
            {
                system("cls");
            }
            else
            {
                system(("del " + deletefile).c_str());
                system("cls");
            }
        }
        else
        {
            system("cls");
            string createfile;
            cout << "FILE CREATION MODE" << endl;
            cout << "------------------------------------------------- " << endl;
            cout << "ENter the name of the file to be created, type back to get out of file creation mode " << endl;
            getline(cin, createfile);
            if (createfile == "back")
            {
                system("cls");
            }
            else
            {

                string newstr = "type nul > " + createfile;

                system(newstr.c_str());
                system("cls");
            };
        }
    }
}

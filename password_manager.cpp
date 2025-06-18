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
        cout << "------Main Menu-------" << endl;
        cout << "----------------------------------------------------enter mmm for user manual--" << endl;
        cout << "-> use file :              u" << endl;
        cout<<endl;
        cout << "-> creating a file / previous page : enter " << endl;
        cout<<endl;
        cout << "-> delete a file :         d" << endl;
        cout<<endl;
        cout << "-> open file :             o" << endl;
        cout<<endl;
        cout << "-> view all created files: t" << endl;
        cout<<endl;
        cout << "-> exit :                  e" << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "                                                      " << endl;
        cout << "Input Operation: ";

        string basic;
        getline(cin, basic);
        if (basic == "u")
        {
            system("cls");
            cout << "Type the file name to be used , press enter to go to main menu" << endl;
            cout << "------------------------------------------------------------------------------" << endl;
            string filename;
            getline(cin, filename);
            map<string, string> table;
            if (filename == "")
            {
                system("cls");
            }
            else
            {

                while (true)
                {
                    system("cls");
                    cout << "opened and using " << filename << endl;
                    cout << "------------------------------------------------------------------------------" << endl;
                    cout << "press enter to go to main menu , type s to show the currently saved key and values " << endl;
                    string appp;
                    string passwor;
                    cout << "App name->";
                    getline(cin, appp);
                    if (appp == "")
                    {
                        filename=filename; 
                        savefeature(table, filename);
                        system("cls");
                        break;
                    };
                    if (appp == "s")
                    {
                        string buff;
                        system("cls");
                        cout << "------------------------------------------------------------------------------" << endl;
                        map<string, string>::iterator it = table.begin();

                        while (it != table.end())
                        {
                            cout << it->first << " --> " << it->second << endl;
                            it++;
                        }
                         cout << "------------------------------------------------------------------------------" << endl;
                          cout << "press enter to get back at insert mode" << endl;
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
        else if (basic == "t")
        {
            system("cls");
            system("tree /f /a");
             cout << "------------------------------------------------------------------------------" << endl;
        cout<<"Files that contain password are of the format {filename}.txt"<<endl;
            string entering;
           getline(cin,entering);
       
           if (entering==""){
            system("cls");
           }else{

           }
        }else if(basic=="mmm"){
            system("cls");
           
            cout<<"This is the user manual of the password manager app.If your are  "<<endl;
            cout<<"new to the app, please create a .txt file first for initial use (press enter).  "<<endl;
            cout<<"Then use the file by typing u and enter, thus the selected file    "<<endl;
            cout<<"will be chosen and you can work on that. If you want to create another file "<<endl;
            cout<<"you can repeat the same steps.You can the . . .  "<<endl;
          
        cout << "------------------------------------------------------------------------------" << endl;
            cout << "-> type u to select a file and write over it " << endl;
        cout<<endl;
        cout << "-> press enter on main menu to create a file" << endl;
        cout<<endl;
        cout << "-> enter d do go to file deletion window " << endl;
        cout<<endl;
        cout << "-> enter o to see saved passwords in a file  " << endl;
        cout<<endl;
        cout << "-> enter t to see all the files" << endl;
        cout<<endl;
        cout << "-> enter e to exit the app" << endl;
        cout<<endl;
        cout << "-> press enter to get back to the previous page" << endl;
        cout << "------------------------------------------------------------------------------" << endl;
         string entering;
           getline(cin,entering);
           if (entering==""){
            system("cls");
           }else{

           }


        }
        else if (basic == "e")
        {
            system("cls");
            break;
        }else if(basic=="o"){
            system("cls");
            cout<<"Type name of the file to view its contents, press enter to go b to the main menu"<<endl;
            cout << "------------------------------------------------------------------------------" << endl;
            string filetobeopened;
            getline(cin,filetobeopened);
            
            ifstream in(filetobeopened);
            string output;
            output="0";
            if(filetobeopened==""){
                system("cls");
                
            }else if(filetobeopened==""){

            }
            else{
            system("cls");
            while(output.size()!=0){

                getline(in,output);
                cout<<output<<endl;
            }
        }
        }
        else if (basic == "d")
        {
            system("cls");
            string deletefile;
            cout << "Type file name to be deleted, press enter to go to main menu" << endl;
            cout << "------------------------------------------------------------------------------" << endl;
            getline(cin, deletefile);
            if (deletefile == "")
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
           cout << "------------------------------------------------------------------------------" << endl;
            cout << "Enter the name of the file to be created, press enter to get out of file creation mode " << endl;
            getline(cin, createfile);
            if (createfile == "")
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


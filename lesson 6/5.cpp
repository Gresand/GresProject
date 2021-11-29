#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

/** Написать программу, которая проверяет присутствует
ли указанное пользователем при запуске программы слово
в указанном пользователем файле (для простоты
работаем только с латиницей). Используем функцию find
которая есть в строках std::string.*/

string findif = "";
string namefile;
string s = "tank aircraft car me";
void file()
{
    string file = "file";
    ofstream fout(file + ".txt");
    fout << s;
    fout.close();
}

void openfile()
{
    ifstream fin(namefile + ".txt");
    if (fin.is_open())
    {
        string buf;
        while (!fin.eof())
        {
            getline(fin, buf);
            if (buf.find(findif) != string::npos)
            {
                cout << buf;
                cout << "Find.";
            }
            else
            {
                cout << "Can't find.";
            }
        }
        fin.close();
    }
    else
    {
        cout << "File don't find.";
    }
}


int main()
{
    system("chcp 1251>nul");
    file();
    cout << "Введите название файла: ";
    cin >> namefile;
    cout << "Введите искомое слово: ";
    cin >> findif;
    openfile();
    system("pause>nul");
    return 0;
}


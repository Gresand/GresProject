#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <random>
#include <vector>

using namespace std;
/*Написать функцию, «склеивающую» эти файлы в
третий текстовый файл (имя файлов спросить у
пользователя).*/

string namefile1 = "";
string namefile2 = "";

void file1(string name)
{
    cout << "Введите название первого файла: ";
    cin >> namefile1;
    ofstream fout;
    fout.open(namefile1 +".txt");
    fout << "Здравствуйте, " + name;
    fout.close();
}

void file2(string position)
{
    cout << "Введите название первого файла: ";
    cin >> namefile2;
    ofstream fout;
    fout.open(namefile2+".txt");
    fout << "Ваша позиция в очереди: " + position;
    fout.close();
}

void file3(string namefile)
{
    string s1 = "",s2 = "";
    ofstream fout;
    fout.open(namefile + ".txt");
    ifstream fin1;
    fin1.open(namefile1 + ".txt");
    if (fin1.is_open())
    {
        string buf1;
        while (!fin1.eof())
        {
            getline(fin1, buf1);
            s1 = buf1;
        }
    }
    fin1.close();
    ifstream fin2;
    fin2.open(namefile2 + ".txt");
    if (fin2.is_open())
    {
        string buf2;
        while (!fin2.eof())
        {
            getline(fin2, buf2);
            s2 = buf2;
        }
    } 
    fin2.close();
    fout << s1 << endl << s2;
    fout.close();
}

int main()
{
    system("chcp 1251>nul");
    string name, position = "100";
    vector <string> a;
    string temp;
    cout << "Введите Ваше имя: ";
    cin >> name;
    file1(name);
    file2(position);
    string namefile3 = "";
    cout << "Введите название третьего файла: ";
    cin >> namefile3;
    file3(namefile3);
    system("pause>nul");
    return 0;
}


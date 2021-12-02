#include <iostream>

/*2. Описать макрокоманду (через директиву define),
проверяющую, входит ли переданное ей число (введенное с
клавиатуры) в диапазон от нуля (включительно) до переданного
ей второго аргумента (исключительно) и возвращает true или
false, вывести на экран «true» или «false».*/

#define FOO(x,y) ((x>=0) && (x<y)) ? true : false

using namespace std;

int main()
{
    int a = 0, b = 0;
    cout << "First argument: " << endl;
    cin >> a;
    cout << "Second argument: " << endl;
    cin >> b;
    FOO(a,b);
    if (FOO(a, b) == true)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    return 0;
}



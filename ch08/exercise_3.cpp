#include <iostream>
#include <string>
#include <cctype>
using namespace std;
void upper_string(string & str);

int main()
{
    cout << "Enter a string (q to quit): ";
    string str;
    getline(cin, str);
    while(str != "q")
    {
        upper_string(str);
        cout << str << endl;
        cout << "Next string (q to quit): ";
        getline(cin, str);
    }
    cout << "Bye.\n";
    return 0;
}

void upper_string(string & str)
{
    for(int i = 0; i < str.size(); i++)
        str[i] = toupper(str[i]);
}
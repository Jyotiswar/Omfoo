#include <iostream>
#include <string>

using namespace std;

string reverseWord(string str)
{
    int i = 0, j = str.size() - 1;
    while (i < j)
    {
        swap(str[i], str[j]);
        ++i;
        --j;
    }

    return str;
}

int main()
{
    string input;
    cout << "Enter a word: ";
    cin >> input;

    string reversed = reverseWord(input);
    cout << "Reversed word: " << reversed << endl;

    return 0;
}

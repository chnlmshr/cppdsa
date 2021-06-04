#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    string str;
    cin >> str;
    cout << str;
    string str1(5, 'n');
    cout << str1;
    getline(cin, str);
    getline(cin, str);
    cout << str;
    string s1 = "fam", s2 = "ily";
    s1.append(s2);
    cout << endl
         << s1 << endl
         << s1 + s2;

    str1.clear();
    cout << endl
         << str1;

    s1 = "hello";
    s2 = "hello";
    if (!s1.compare(s2))
        cout << "Strings are equal.";
    else
        cout << "Strings are unequal.";

    if (str1.empty())
        cout << endl
             << "String is Empty";

    string s3 = "nincompoop";
    s3.erase(3, 3);
    cout << endl
         << s3;

    cout << endl
         << s3.find("in");

    s3.insert(3, "com");
    cout << endl
         << s3;
    cout << endl
         << s1.length();
    cout << endl
         << s3.substr(6, 4);
    string i = "654";
    int x = stoi(i);
    cout << x + 1 << endl;
    cout << to_string(x) + "c" << endl;

    sort(s3.begin(), s3.end());
    cout << s3 << endl;

    string s = "fhfuehfjeuf";
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << s;
    return 0;
}
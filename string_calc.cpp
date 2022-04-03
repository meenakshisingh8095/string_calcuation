// simplemath.h
#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string &str, char commaDelimiter, char newlineDelimeter)
{
    vector<string> splitted_data;
    string temp = "";
    for (auto character : str)
    {
        if (character == commaDelimiter || character == newlineDelimeter)
        {
            splitted_data.push_back(temp);
            temp = "";
        }
        else
        {
            temp += character;
        }
    }
    if (temp.size() != 0)
        splitted_data.push_back(temp);
    return splitted_data;
}

int convertToNumber(string str)
{
    int int_value = 0;
    for (auto character : str)
    {
        int new_digit = character - '0';
        int_value = int_value * 10 + new_digit;
    }
    return int_value;
}

int string_add(string str)
{
    if (str == "")
        return 0;
    if (str.size() == 1)
        return convertToNumber(str);
    if (str[0] == '-')
        throw invalid_argument("negatives not allowed");
    char commaDelimiter = ',', newlineDelimeter = '\n';
    vector<string> a = split_string(str, commaDelimiter, newlineDelimeter);
    int sum = 0;
    for (auto i : a)
    {
        int int_val = convertToNumber(i);
        sum += int_val;
    }
    return sum;
}

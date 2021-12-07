/*
    Incorrect code.
    Contributions will be appreciated.
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

map<int, string> words{
    {0, "zero"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}};

map<int, string> multiplicatives{
    {2, "double"}, {3, "triple"}, {4, "quadruple"}, {5, "quintuple"}, {6, "sextuple"}, {7, "septuple"}, {8, "octuple"}, {9, "nonuple"}, {10, "decuple"}};

vector<int> getPhoneNumberPattern(string F, char delimiter)
{
    F.erase(remove(F.begin(), F.end(), delimiter), F.end());
    vector<int> number_pattern;
    for (auto i : F)
        number_pattern.push_back(i - '0');
    return number_pattern;
}

int main()
{
    freopen("ts1_input.txt", "r", stdin);
    int T, offset = 0, count;
    string N, F, str;
    vector<string> word_format;
    vector<int> number_pattern;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> F;
        number_pattern = getPhoneNumberPattern(F, '-');

        for (int j = 0; j < number_pattern.size(); j++)
        {
            int previous = -1;
            count = 1;
            for (int k = offset; k < offset + number_pattern[j] + 1; k++)
            {
                if (previous == N[k] - '0' && k != offset + number_pattern[j])
                {
                    count += 1;
                }
                else
                {
                    auto multiplicative = multiplicatives.find(count), word = words.find(previous);
                    if ((multiplicative->second).compare("") != 0 && multiplicative != multiplicatives.end())
                        str += multiplicative->second + " ";
                    if ((word->second).compare("") != 0 && word != words.end())
                        str += word->second;
                    word_format.push_back(str);
                    count = 1;
                    str = "";
                }
                previous = N[k] - '0';
            }
            offset += number_pattern[j];
        }
        for (const auto token : word_format)
        {
            str += token.compare("") ? token + " " : "";
            cout << "Case #" << i + 1 << ": " << str << endl;
            offset = 0;
            count = 0;
            str = "";
            word_format.clear();
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
bool checkPhone(char *phone_num)
{
    if (strlen(phone_num) != 10)
        return false;
    for (int i = 0; i < strlen(phone_num); i++)
    {
        if (!(phone_num[i] >= '0' && phone_num[i] <= '9'))
            return false;
    }
    return true;
}
int main()
{
    int count = 0;
    int incorrectphone = 0;
    int ctime;
    string type;
    map<string, int> numberCalls, timeCall;
    char sdt1[15], sdt2[15], first_word[10];
    int y1, mm1, d1, h1, m1, s1, h2, m2, s2;
    do
    {
        scanf("%s", first_word);
        if (strcmp(first_word, "#") == 0)
            break;
        scanf("%s %s %d-%d-%d %d:%d:%d %d:%d:%d", sdt1, sdt2, &y1, &mm1, &d1, &h1, &m1, &s1, &h2, &m2, &s2);
        if (!checkPhone(sdt1) || !checkPhone(sdt2))
            ++incorrectphone;
        ctime = 3600 * h2 + 60 * m2 + s2 - 3600 * h1 - 60 * m1 - s1;
        numberCalls[sdt1] += 1;
        timeCall[sdt1] += ctime;
        count++;
    } while (1);
    do
    {
        cin >> type;
        if (type == "#")
            continue;
        if (type == "?check_phone_number")
        {
            if (incorrectphone == 0)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (type == "?number_calls_from")
        {
            string phone;
            cin >> phone;
            cout << numberCalls[phone] << '\n';
        }
        else if (type == "?number_total_calls")
        {
            cout << count << '\n';
        }
        else if (type == "?count_time_calls_from")
        {
            string phone;
            cin >> phone;
            cout << timeCall[phone] << '\n';
        }
    } while (type != "#");
}
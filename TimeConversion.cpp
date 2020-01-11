/*
Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.

Note: Midnight is 12:00:00AM on a 12-hour clock, and 00:00:00 on a 24-hour clock. Noon is 12:00:00PM on a 12-hour clock, and 12:00:00 on a 24-hour clock.

Function Description

Complete the timeConversion function in the editor below. It should return a new string representing the input time in 24 hour format.

timeConversion has the following parameter(s):

s: a string representing time in 12 hour format

Input Format

A single string s containing a time in 12-hour clock format

Output Format

Convert and print the given time in 24-hour format, where 00 <= hh <= 23.
*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
     
    int hours = stoi(s.substr(0,2));

    // morning times are the same except for midnight
    if (s[8] == 'A') {
        if (hours == 12) { // midnight
            return "00" + s.substr(2, 6);
        }
        else {
            return s.substr(0, 8);
        }
    }
    // afternoon/night
    else {
        if (hours == 12) { // noon
            return s.substr(0,8);
        }
        else {
            return to_string(hours + 12) + s.substr(2,6);
        }
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

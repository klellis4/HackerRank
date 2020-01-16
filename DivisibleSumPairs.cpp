/*
You are given an array of n integers, ar = [ar[0], ar[1], ..., ar[n-1]], and a positive integer, k.
Find and print the number of (i,j) pairs where i < j and ar[i] + ar[j] is divisible by k.

For example, ar = [1,2,3,4,5,6] and k = 5. Our three pairs meeting the criteria are [1,4], [2,3] and [4,6].

Function Description

Complete the divisibleSumPairs function in the editor below. It should return the integer count of pairs meeting the criteria.

divisibleSumPairs has the following parameter(s):

n: the integer length of array ar
ar: an array of integers
k: the integer to divide the pair sum by
Input Format

The first line contains 2 space-separated integers, n and k.
The second line contains n space-separated integers describing the values of ar[ar[0], ar[1], ..., ar[n-1]].

Output Format

Print the number of (i,j) pairs where i < j and a[i] + a[j] is evenly divisible by k.

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the divisibleSumPairs function below.
int divisibleSumPairs(int n, int k, vector<int> ar) {

    int count {0};

    for (int i {0}; i < ar.size(); i++) {
        for (int j = i+1; j < ar.size(); j++) {
            if ((ar.at(i) + ar.at(j)) % k == 0) {
                count++;
            }
        }
    }

    return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = divisibleSumPairs(n, k, ar);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

/*
Problem(1): Pattern searching using Knuth-Morris-Pratt string algorithm.
Input 
Text = "ababcabcabababd", Pattern = "ababd"
Output
Found pattern at index 10
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void computeLPS(string pat, int M, vector<int>& lps){
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while(i < M){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0){
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string pat, string txt){
    int M = pat.length();
    int N = txt.length();
    vector<int> lps(M);
    computeLPS(pat, M, lps);
    int i = 0;
    int j = 0;
    while(i < N){
        if(pat[j] == txt[i]){
            j++;
            i++;
        }
        if(j == M){
            cout << "Found pattern at index " << i - j << endl;
            j = lps[j - 1];
        } else if(i < N && pat[j] != txt[i]){
            if(j != 0) j = lps[j - 1];
            else i++;
        }
    }
}

int main(){
    string txt = "ababcabcabababd";
    string pat = "ababd";
    KMPSearch(pat, txt);
}
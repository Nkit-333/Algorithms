#include <bits/stdc++.h> 
using namespace std;
void LPS(string pattern, int len1, int* lps) 
{ 
   
    int len = 0; 
  
    lps[0] = 0; 
    int i = 1; 
     do  { 
        if (pattern[i] == pattern[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else 
        { 
           
            if (len != 0) { 
                len = lps[len - 1]; 
  
               
            } 
            else 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    }while(i < len1);
} 
  
void solve(string pattern, string text) 
{ 
    int len1 = strlen(pattern.c_str()); 
    int len2 = strlen(text.c_str());  
    int lps[len1]; 
    LPS(pattern, len1, lps); 
  
    int i = 0; 
    int j = 0; 
    while (i < len2) { 
        if (pattern[j] == text[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == len1) { 
            cout<<i-j<<" "; 
            j = lps[j - 1]; 
        } 
        else if (i < len2 && pattern[j] != text[i]) { 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
} 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
    string text,pattern;
    cin>>text>>pattern; 
    solve(pattern, text);
    cout<<endl;
    } 
    return 0; 
} 

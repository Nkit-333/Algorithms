#include <vector>
#include<iostream>
#include <string.h> 
using namespace std;
void lps(string pattern,int len,int arr[])
{
    
    for(int i=0;i<len;i++)
        arr[i]=0;
    static int count=0;
    int i,j;
    i=0;
    j=i+1;
    while(1)
    {
            if(j>len-1)
                break;
            if(pattern[i]==pattern[j])
            {   
               
                count++;
                arr[j]=count;
                i++;
            }
            else
            {
                i=0;
                count=0;
            }
        j++;
    }
  
}
void kmp(string text,string pattern)
{
  int len=strlen(pattern.c_str());
  int text_len=strlen(text.c_str());
  int arr[len];
  lps(pattern,len,arr);
  int i = 0; 
    int j = 0; 
    while (i < text_len) { 
        if (pattern[j] == text[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == len) { 
            cout<<i-j<<" "; 
            j = arr[j - 1]; 
        } 
        else if (i < text_len && pattern[j] != text[i]) { 
            if (j != 0) 
                j = arr[j - 1]; 
            else
                i = i + 1; 
        } 
    }

}
int main()
{
    cin>>t;
    while(t--)
    {
    string text,pattern;
    cin>>text>>pattern;
    kmp(text,pattern);
    cout<<endl;
    }

}
//
//  main.cpp
//  project 4
//
//  Created by Time Thief on 7/20/22.
//

#include <iostream>
#include <string>
using namespace std;
//all functions take at least two parameters
   //an array of strings, and the number of items the function will consider in the array(size)
int locateMaximum(const string array[], int n);
bool matchingValuesTogether(const string array[], int n);
bool hasDuplicates(const string array[], int n);
string majorityElement(const string array[], int n);
bool hasReverse(const string array[], int n);
int findLastOccurrence(const string array[], int n, string target);
int countFloatingPointValues(const string array[], int n);
    bool noLetters(string arrayString);
    bool onlyOneDecimal(string arrayString);
    bool decimalInMiddle(string arrayString);
int replaceAll(string array[], int n, char letterToReplace, char letterToFill);

int main()
{
    string folks[10] = {"+12.", "", "tyrion", "12tyrion", "1tyrion","Tyrion+", "tyrion+", "tyrionn", ".", "5"};
    cerr<<"maximum value is at index: "<<locateMaximum(folks, 10)<<endl;
    cerr.setf(ios::boolalpha);
    cerr<<"There are matching values together: "<<matchingValuesTogether(folks, 10)<<endl;
    cerr<<"there are duplicates: "<<hasDuplicates(folks, 10)<<endl;
    cerr<<"the majority element is: "<<majorityElement(folks, 10)<<endl;
    cerr<<"there is a reverse in the array: "<<hasReverse(folks, 10)<<endl;
    cerr<<"the last occurrence of the target word is at index: "<<findLastOccurrence(folks, 10, "")<<endl;
    cerr<<"the float point number: "<< countFloatingPointValues(folks, 10)<<endl;
    cerr<<"the number of letter changed is: "<<replaceAll(folks, 0, '.', 'B')<<endl;
    cerr<<"the array after change is: ";
    for (int i=0; i<10; i++)
    {
        cerr<<folks[i]<<" ";
    }
    return 0;
}

int locateMaximum(const string array[], int n)
{
    if (n > 0)
    {
        int maxIndex = 0;
        string maxString = "";
        //return the index of the largest item found in the array
        for(int i=0; i<n; i++)
        {
            string words = array[i];
            if (words > maxString)
            {
                maxIndex = i;
                maxString = words;
            }
        }
        return maxIndex;
    }
    else
    {
        return -1;
    }
    
    //return -1 if n<=0
}

bool matchingValuesTogether(const string array[], int n)
{
    //if all the duplicated values found in the array are located one right after teh other, return true, otherwise false.
    //if don't find any duplicated values at all, return true.
    //if n<= 0 return false
    if (n>0)
    {
        //for each string in the array, check if there is a duplicated value
        //then check if the index are next to each other
        int valueIndex = -1;
        string sameValue = "";
        for (int i =0; i < n; i++)
        {
            valueIndex = i;
            sameValue = array[i];
            for (int j = i+1; j<n; j++)
            {
                string sec = array[j];
                if(sec == sameValue && sec != array[j-1] &&j!=i+1)
                {
                    return false;
                }
            }
        }
        return true;
        }
    else
    {
        return false;
    }
}

bool hasDuplicates(const string array[], int n)
{
    //if there is a value that is repeatedly found inthe array, return true otherwise false
    //if n<= 0 return false.
    if (n>0)
    {
        int valueIndex = 0;
        string sameValue = "";
        for (int i = 0; i < n; i++)
        {
            valueIndex = i;
            sameValue = array[i];
            for(int j=i+1; j<n; j++)
            {
                string sec = array[j];
                if(sec == sameValue)
                {
                    return true;
                }
            }
        }
        return false;
    }
    else
        return false;
}

string majorityElement(const string array[], int n)
{
    //find the element that occurs more than n/2 times or return the empty string ""
    string majorElement = "";
    int count = 1;
    for(int i=0; i<n; i++)
    {
        majorElement = array[i];
        for(int j=i+1; j<n; j++)
        {
            string sec = array[j];
            if (sec == majorElement)
            {
                count++;
            }
        }
        
        if (count <= n/2)
        {
            count = 1;
            majorElement = "";
        }
        else
        {
            return majorElement;
        }
    }
    return majorElement;
}

bool hasReverse(const string array[], int n)
{
    bool reverse = false;
    int count = 0;
    if(n>0)
    {
        for (int i=0; i<n; i++)
        {
            string checkWord = array[i];
            //check if the two words have the same length
            for (int j = i+1; j<n; j++)
            {
                count = 0;
                string secondWord = array[j];
                if(secondWord.length() == checkWord.length())
                {
                    size_t begin = 0;
                    size_t end = checkWord.length()-1;
                    for(int k =0; k<checkWord.length();k++)
                    {
                        if(secondWord.at(end) == checkWord.at(begin))
                        {
                            count++;
                            
                        }
                        begin++;
                        end--;
                    }
                    reverse = (count == secondWord.length());
                    if(reverse)
                        return reverse;
                }
            }
        }
        return reverse;
    }
    else
    {
        return (reverse = false);
    }
}

int findLastOccurrence(const string array[], int n, string target)
{
    //largest index that holds the target value in the array or -1 if it is not found at all or n<=0
    if (n>0)
    {
        int lastOccurrence = -1;
        for (int i=0; i<n ; i++)
        {
            string word = array[i];
            if(word == target)
            {
                lastOccurrence = i;
            }
        }
        return lastOccurrence;
    }
    else
        return -1;
}

int countFloatingPointValues(const string array[], int n)
{
    //total number of lfoating-point values found
    //interger is valid
    //should not have letters.
    //should have only one decimal point
    //the decimal point need to be at the middle and occur only once
    if (n>0)
    {
        int count=0;
        for(int i=0; i<n; i++)
        {
            string word = array[i];
            if(noLetters(word)&&onlyOneDecimal(word)&&decimalInMiddle(word))
            {
                count++;
            }
        }
    return count;
    }
    else
        return -1;
}

bool noLetters(const string arrayString)
{
    bool noLetters = false;
    const char ZERO = '0';
    const char ONE = '1';
    const char TWO = '2';
    const char THREE = '3';
    const char FOUR = '4';
    const char FIVE = '5';
    const char SIX = '6';
    const char SEVEN = '7';
    const char EIGHT = '8';
    const char NINE = '9';
    const char PLUS = '+';
    const char MINUS = '-';
    const char DECI = '.';
    for(size_t i=0; i<arrayString.length(); i++)
    {
        char number = arrayString.at(i);
        switch (number)
        {
            case ZERO:
            case ONE:
            case TWO:
            case THREE:
            case FOUR:
            case FIVE:
            case SIX:
            case SEVEN:
            case EIGHT:
            case NINE:
            case PLUS:
            case MINUS:
            case DECI:
                noLetters = true;
                break;
            default:
                return false;
        }
        
    }
    return noLetters;
}
bool onlyOneDecimal(const string arrayString)
{
    int count = 0, count2 = 0;
    for(size_t i =0; i< arrayString.length(); i++)
    {
        char letter=arrayString.at(i);
        if(letter == '.' )
        {
            count++;
        }
        else if(letter == '+' || letter == '-')
            count2++;
    }
    if (count >1||count2>1)
        return false;
    else
        return true;
}

bool decimalInMiddle(const string arrayString)
{
    int index2 = -1;
    for(int i=0; i<arrayString.length(); i++)
    {
        char letter=arrayString.at(i);
        if(letter == '+' || letter == '-')
            index2 = i;
    }
    if(index2 != 0 && index2 != -1)
        return false;
    else
        return true;
}
int replaceAll(string array[], int n, char letterToReplace, char letterToFill)
{
    //replace all occurrences in each element of the choosen character with the chosen letter.
    if(n>0)
    {
        int count=0;
        for (int i=0; i<n; i++)
        {
            string word = array[i];
            for (size_t j=0; j<word.length(); j++)
            {
                char letterCheck = word.at(j);
                if(letterCheck == letterToReplace)
                {
                    count++;
                    word.at(j) = letterToFill;
                    array[i] = word;
                }
            }
        }
        return count;
    }
    else
        return -1;
}

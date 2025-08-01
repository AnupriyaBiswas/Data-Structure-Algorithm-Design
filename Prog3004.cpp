/*4. Write a program to check if the given sentence is word-wise palindromic or character-wise palindromic or none of them. (Assume 
single space between two words).
Sample input 1: king are you glad you are king: word-wise palindromic
Sample input 2: was it a cat or a cat i saw: character-wise palindromic
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int charPallindrome(string str)
{
	string rs = "", ts = "";
	for(char c : str)
	{
		if(c != ' ')
		{
			rs = c + rs;
			ts = ts + c;
		}
	}
	return rs == ts;
}

int wordPallindrome(string str)
{
	vector<string> words;
	string word = "";
	for(char c : str)
	{
		if(c == ' ')
		{
			if (!word.empty()) 
			{
                words.push_back(word);  // Push current word to vector
                word = "";
            }
		}
		else
		{
			word += c;
		}
	}
	
	if (!word.empty()) 
	{
        words.push_back(word);
    }

	int n = words.size();
	for (int i = 0; i < n / 2; i++)
	{
		if(words[i] != words[n - i - 1])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	string s;
	cout << "Enter String : ";
	getline(cin, s);
	
	if (charPallindrome(s) && wordPallindrome(s))
	{
		cout << "Both Character and Word Wise Pallindromic.\n";
	}
	else if(charPallindrome(s))
	{
		cout << "NOT Word-Wise but Character-Wise Pallindromic.\n";
	}
	else if(wordPallindrome(s))
	{
		cout << "NOT Character-Wise but Word-Wise Pallindromic.\n";
	}
	else
	{
		cout << "NOT Pallindromic.\n";
	}
	return 0;
}

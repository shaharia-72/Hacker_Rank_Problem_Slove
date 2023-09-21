#include <bits/stdc++.h> // Includes a set of standard C++ library headers in a single line.
using namespace std;

int main()
{             // The entry point of the program.
    int t;    // Declare an integer variable 't' to store the number of test cases.
    cin >> t; // Read the number of test cases from the user.

    cin.ignore(); // Ignore the newline character left in the input buffer after reading 't'.

    while (t--)
    {                           // Loop runs 't' times, once for each test case.
        string sentence;        // Declare a string variable 'sentence' to store the input sentence.
        getline(cin, sentence); // Read a line of text (sentence) from the user and store it in 'sentence'.

        string word;               // Declare a string variable 'word' to store individual words from the sentence.
        stringstream ss(sentence); // Create a stringstream object 'ss' initialized with the 'sentence' string.

        map<string, int> word_count; // Declare a map named 'word_count' to store each word and its corresponding frequency.

        while (ss >> word)
        {                       // Loop runs until all words in the sentence have been extracted.
            word_count[word]++; // Increment the count of the current word in the 'word_count' map.
            // If the word is encountered for the first time, it will be inserted into the map with a count of 1.
        }

        // The following code block is commented out and not used in the actual implementation.

        // for (auto it = word_count.begin(); it != word_count.end(); it++) {
        //     // This loop is used to iterate through the 'word_count' map and print the word-frequency pairs.
        //     cout << it->first << " " << it->second << endl;
        // }

        string most_word; // Declare a string variable to store the word that occurs the most number of times.
        int count = 0;    // Initialize a variable to store the maximum frequency encountered.
        bool x = true;    // Initialize a boolean variable to handle the case of multiple words with the same maximum frequency.

        // The following code block is used to find the most frequently occurring word and its frequency.

        for (auto it = word_count.begin(); it != word_count.end(); it++)
        {
            // Loop through the 'word_count' map to find the word with the highest frequency.

            if (it->second > count)
            {
                // If the current word's frequency is greater than the current maximum count,
                // update 'most_word' and 'count' to the current word's values.
                most_word = it->first;
                count = it->second;
                x = false; // Set 'x' to false since we found a new highest frequency.
            }
            else if (it->second == count && !x)
            {
                // If we encounter a word with the same frequency as the current maximum frequency (count),
                // update 'most_word' to the current word's value, but keep 'x' as false to avoid overriding the 'most_word'.
                most_word = it->first;
            }
        }

        cout << most_word << " " << count << endl; // Print the word with the highest frequency and its frequency.
    }

    return 0; // Exit the program.
}
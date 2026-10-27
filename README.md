# UMBC-Anagrammer
A command-line C++ anagram game developed for CMSC 202 at UMBC in UMBC Linux Server

Project Structure
├── proj1.cpp
├── proj1_data.txt
├── proj1_sample.txt

Background:
An anagram is a word or phrase formed by rearranging the letters of another word or phrase, typically using all the original letters exactly once. A partial anagram is when you don't use all the original letters exactly once. Anagramming words is a linguistic puzzle that involves rearranging the letters of a word or phrase to create entirely new combinations of characters, while still using all the original letters. This wordplay not only tests one's vocabulary and cognitive agility but also tests patience within the jumble of letters. For this project, we are going to be creating a game where the computer will choose a word with more than 8 letters. The computer will build a list of all words that can be built from the chosen word (considered a partial anagram). The players will then guess a word. The program will check three things: 1. If the guess is a word from the list, 2. If the guess can be made from the chosen word, and 3. If the guess has not already been guessed. If all three are true, it increments the number of correct anagrams. If any of the three tests fails, it tells the user why and asks for another word. The game ends when all of the partial anagrams have been guessed.

Assignment Description:
Your assignment is to develop the code to read in a list of words into an array of strings. The program will randomly choose a word that is greater than or equal to 8 characters. The program will then build a list of all words that can be made from the chosen word. The user will guess words which will either be valid partial anagrams or not. Words can only be guessed once otherwise the player will be notified that the word has already been guessed. The game ends when all possible partial anagrams have been guessed.

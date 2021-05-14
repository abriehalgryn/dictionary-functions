This was a assigment for object oriented programming for C++ for my second year at uni.

It has the following functions:


Basic Tasks
1. Prompt the user to enter a word. If that exact word is in the dictionary, print the word’s name, the word type using the following scheme: Noun (n.), Verb (v.), Adverb (adv.), Adjective(adj.), Preposition(prep) MiscWords(misc.),ProperNouns (pn.), NounAndVerb (n. v.), and the word’s definition. If the word is not in the dictionary print ‘word not found.’
a. For words with multiple definitions, these should be separated with a line-break.
b. Proper nouns should have their word name capitalised.

2. Find the word(s) with more than three ‘z’’s 

3. List the words that have a 'q' without a following 'u' eg 'Iraqi'

4. List all words that are a noun and a verb e.g. “Phone” 

5. List all words that are palindromes. e.g .”civic”

6. Prompt the user for a word, and report all words that are anagrams of the word (e.g. “admirer” and “married”) 

7. Guessing game – present the definition of a random noun and the length of that noun and ask the user to guess that noun, giving three tries. After the first incorrect guess, reveal the first letter of the word, after the second incorrect guess reveal the second letter.

8. . Fun with Tri-Grams
Using a new class, implemented in a separate file, create a class that encapsulates 
the following functionality: From any given text document (you can use the 
dictionary), calculate the probability of any character occurring after any 
combination of two characters (including where the first character is a space, i.e. the 
start of a word) and store these probabilities. Based on an input of two characters, 
return the three most likely characters to occur after the two characters. Use the 
class to generate 10 random words which sound like English words, but do not exist 
in the dictionary;





Format of the dictionary file:
Notes about dictionary.txt 
• 106,184 word definitions 
• Text format (ascii) 
• 3 lines per definition 
  o Line 1: The word, followed by type in []
  o The definition (on one line) - multiple definitions of the same word separated by semicolon.
  o Blank line
• Word 
  o Only uses characters A-Z a-z and the hyphen ‘-‘ 
  o No punctuation or similar 
  o Abbreviations are given without the ‘.’ For example, “e.g.” would be “eg” 
  o No words are presented with spaces, the words are joined OR a hyphen is used. e.g. “bumble bee” is “bumblebee” 
  o The language conversions are made eg: é=e æ=ae ö=o 
  o No word has more than 45 characters 
  o ALL words are in lower case, even proper nouns. 
• Type, a single word (see table 1) enclosed in square brackets, appearing on the same line as the word, separated by a space from it; 
• Definition 
  o Multiple definitions are separated by a semicolon; 
  o No Definition has more than 6014 characters 
  o The language conversions are made eg: é=e æ=ae ö=o 
• The definitions were not written by your lecturer or ECU. We take no responsibility for any inaccuracies or the content. 
  o The definitions are from the GCIDE project, made available under the terms of the GNU general Public License, GCIDE_XML is necessarily also published under those terms. See the file gpl.txt or <http://www.gnu.org/copyleft/gpl.txt>.

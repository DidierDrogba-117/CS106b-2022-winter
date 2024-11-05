/******************************************************************************
 * File: OnlyConnect.h
 * Author: Keith Schwarz (htiek@cs.stanford.edu)
 *
 * Header file for the Only Connect portion of the assignment. You should not
 * modify this file.
 */

#ifndef OnlyConnect_Included
#define OnlyConnect_Included

#include <string>
#include <vector>   // Include the vector header

/**
 * Given a string, converts that string into an Only Connect puzzle by deleting all
 * non-consonants and making all characters upper-case.
 *
 * @param phrase The phrase to transform.
 * @return That string, rendered as an Only Connect puzzle.
 */
std::string onlyConnectize(std::string phrase);
void helper(const char *ptr, std::string &res, const std::vector<char>& consonants);
bool isConsonant(char curr_ch, const std::vector<char>& consonants);

#endif

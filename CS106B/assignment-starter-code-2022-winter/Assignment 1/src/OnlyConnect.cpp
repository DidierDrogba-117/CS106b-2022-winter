/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 */
#include "OnlyConnect.h"
#include "GUI/SimpleTest.h"
using namespace std;

string onlyConnectize(string phrase)
{
    /* TODO: The next few lines just exist to make sure you don't get compiler warning messages
     * when this function isn't implemented. Delete these lines, then implement this function.
     */
    /* 1. use recursion 2. remove all consonants 3. make all characters upper-case */

    // TODO:corner case

    // TODO: change it to vector later
    vector<char> consonants = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Z'};

    /* for recursion
        h(abc) -> h(bc) -> h(c) -> h() -> corner case
        need to add new char in front of result, like h(c) return res:c
        then b need to be added before c -> res: bc
    */

    const char *ptr = phrase.c_str(); // cannot use &phrase 
    string res = "";
    helper(ptr, res, consonants);
    cout << res << endl;
    return res;
}

void helper(const char *ptr, string &res, const vector<char>& consonants)
{
    // base case for recursion
    if (*ptr == '\0')
    {
        return;
    }

    // if the char is non-consonant, then add it to the result
    helper(ptr + 1, res, consonants);
    // add the char in front of res, like res = c -> bc, add b in the front
    if (!isConsonant(*ptr, consonants) || !isalpha(*ptr)) {return;}
    res = string(1, toupper(*ptr)) + res;


    // if (!isConsonant(*ptr, consonants) && isalpha(*ptr))
    // {
    //     res = string(1, toupper(*ptr)) + res;
    // }
}

bool isConsonant(char curr_ch, const vector<char>& consonants)
{
    curr_ch = toupper(curr_ch);
    if (find(consonants.begin(), consonants.end(), curr_ch) != consonants.end())
    {
        return true;
    }
    return false;
}

/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Converts lower-case to upper-case.")
{
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Handles non-letter characters properly.")
{
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

PROVIDED_TEST("Handles single-character inputs.")
{
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

PROVIDED_TEST("Empty input.")
{
    EXPECT_EQUAL(onlyConnectize(""), "");
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */

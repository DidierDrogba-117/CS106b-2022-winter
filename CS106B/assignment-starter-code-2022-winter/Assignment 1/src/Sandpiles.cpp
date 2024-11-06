/* File: Sandpiles.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 */
#include "Sandpiles.h"
#include "GUI/SimpleTest.h"
using namespace std;

// Define the neighbor directions
std::pair<int, int> directions[] = {
    {-1, 0}, // Up
    {1, 0},  // Down
    {0, -1}, // Left
    {0, 1}   // Right
};

void dropSandOn(Grid<int> &world, int row, int col)
{
    // /* TODO: Delete this line and the three after it, then implement this function. */
    // (void) world;
    // (void) row;
    // (void) col;

    // corner case
    // not in range
    if (!world.inBounds(row, col))
    {
        return;
    }
    // drop sand
    world[row][col]++;

    // check if the cell is toppled
    if (world[row][col] >= 4)
    {
        world[row][col] -= 4;
        // recursively drop sand on neighbors
        for (const auto& dir : directions)
        {
            dropSandOn(world, row + dir.first, col + dir.second);
        }
    }
}

/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Dropping into an empty cell only changes that cell.")
{
    /* Create a simple source grid. */
    Grid<int> before = {
        {3, 3, 3},
        {3, 0, 3},
        {3, 3, 3}};
    Grid<int> after = {
        {3, 3, 3},
        {3, 1, 3},
        {3, 3, 3}};

    dropSandOn(before, 1, 1);
    EXPECT_EQUAL(before, after); // The above call changes 'before.'
}

PROVIDED_TEST("Non-chaining topples work.")
{
    /* Create a simple source grid. */
    Grid<int> before = {
        {0, 0, 0},
        {1, 3, 1},
        {0, 2, 0}};
    Grid<int> after = {
        {0, 1, 0},
        {2, 0, 2},
        {0, 3, 0}};

    dropSandOn(before, 1, 1);
    EXPECT_EQUAL(before, after); // The above call changes 'before.'
}

PROVIDED_TEST("Two topples chain.")
{
    /* Create a simple source grid. */
    Grid<int> before = {
        {0, 0, 0, 0},
        {0, 3, 3, 0},
        {0, 0, 0, 0}};
    Grid<int> after = {
        {0, 1, 1, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 0}};

    dropSandOn(before, 1, 1);
    EXPECT_EQUAL(before, after); // The above call changes 'before.'
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

STUDENT_TEST("Test toppling at the corner of the grid.") {
    Grid<int> world(3, 3, 0); // Create a 3x3 grid initialized with zeros.

    // Manually set up the grid so that the corner cell will topple.
    world[0][0] = 3;

    // Drop a grain on the top-left corner.
    dropSandOn(world, 0, 0);

    // Expected results:
    // The cell at (0,0) should have 0 grains.
    // Cells at (0,1) and (1,0) should each have 1 grain.
    EXPECT_EQUAL(world[0][0], 0);
    EXPECT_EQUAL(world[0][1], 1);
    EXPECT_EQUAL(world[1][0], 1);
    EXPECT_EQUAL(world[1][1], 0); // Ensure no unintended grains are added elsewhere.
}


#include "Plotter.h"
#include "strlib.h"

using namespace std;

/*
Implement the runPlotterScript function. It should do the following:

Initialize the plotter. The pen begins at position (0, 0) with in the “up” position, using the color black and having width one.

Read each line of the input file. Based on the line, determine which of the PenUp, PenDown, MoveAbs, MoveRel, PenWidth, and PenColor commands to execute. Based on the command, make appropriate calls to drawLine, passing in the appropriate arguments.

*/

void runPlotterScript(istream &input)
{

    // init vars
    double curr_x = 0;
    double curr_y = 0;
    PenStyle curr_style = {1, "black"};
    bool is_writing = false;

    double next_x, next_y;

    for (string line; getline(input, line);)
    {
        /* ... do something with line ... */

        Vector<string> tokens = stringSplit(line, " ");

            /*
            MoveAbs -0.8 0.8
            PenDown
            MoveRel 0 -1.2
            PenColor color
            PenWidth width
            */
            // Commands are case-insensitive.  all transfer to lower case
            string command = toLowerCase(tokens[0]);

        // penup/down
        if (command == "penup")
        {
            is_writing = false;
        }
        else if (command == "pendown")
        {
            is_writing = true;
        }
        // MoveAbs/MoveRel
        else if (command == "moveabs")
        {
            next_x = stringToReal(tokens[1]);
            next_y = stringToReal(tokens[2]);

            if (is_writing)
            {
                drawLine(curr_x, curr_y, next_x, next_y, curr_style);
            }

            curr_x = next_x;
            curr_y = next_y;
        }
        else if (command == "moverel")
        {
            double next_x = curr_x + stringToReal(tokens[1]);
            next_y = curr_y + stringToReal(tokens[2]);

            if (is_writing)
            {
                drawLine(curr_x, curr_y, next_x, next_y, curr_style);
            }

            curr_x = next_x;
            curr_y = next_y;
        }
        // PenWidth
        else if (command == "penwidth")
        {
            curr_style.width = stringToReal(tokens[1]);
        }
        // PenColor
        else if (command == "pencolor")
        {
            curr_style.color = tokens[1];
        }
    }
}

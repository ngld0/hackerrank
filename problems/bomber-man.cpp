// Ref: https://programmingvidya.wordpress.com/2020/12/28/solution-for-hackerrank-the-bomberman-game/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */

vector<string> bomberMan(int n, vector<string> grid) {
// * After 1 second, bomberman does nothing
    if(n==1) {
        return grid;
    }
 
    /*
    *   Creating a grid to store position of bombs
    *   and initializing all the values
    *   in that grid to 0
    */
    int posGrid[200][200];
    for(int i=0; i<200; i++) {
        for(int j=0; j<200; j++) {
            posGrid[i][j] = 0;
        }
    }
 
    // * Initializing variables
    int numberOfRows = grid.size(), numberOfColumns = grid[0].length();
 
    /*
    *   Setting up the position grid with 1 at positions
    *   where bombs are placed initially and setting up
    *   the grid with bombs at all the positions
    */
    for(int i=0; i<numberOfRows; i++) {
        for(int j=0; j<numberOfColumns; j++) {
            if(grid[i][j]==79) {
                posGrid[i][j] = 1;
            }
            grid[i][j] = 79;
        }
    }
 
    /*
    *   After 2 seconds or if the number of seconds
    *   are even, the grid will be full.
    *   Returning the grid with bombs
    *   at all the positions
    */
    if(n%2==0) {
        return grid;
    }
 
    /*
    *   After 3 seconds, the bombs placed initially
    *   will detonate, updating the grid
    */
    for(int i=0; i<numberOfRows; i++) {
        for(int j=0; j<numberOfColumns; j++) {
            if(posGrid[i][j]==1) {
                grid[i][j] = '.';
                if(j-1>=0) {
                    grid[i][j-1] = '.';
                }
                if(i-1>=0) {
                    grid[i-1][j] = '.';
                }
                if(j+1<numberOfColumns) {
                    grid[i][j+1] = '.';
                }
                if(i+1<numberOfRows) {
                    grid[i+1][j] = '.';
                }
            }
        }
    }
 
    /*
    *   The grid now obtained will be repeated at second
    *   7, 11, 15, 19, 23....
    *   Therefore, returning this grid if the number of seconds
    *   when divided by 4 gives the remainder 3
    */
    if(n%4==3) {
        return grid;
    }
 
    /*
    *   Again forming the position grid
    *   by having a look at the positions
    *   where bombs are placed now. Also, updating
    *   the grid as it will look like after 4 seconds
    *   i.e. with bombs at all positions
    */
    for(int i=0; i<numberOfRows; i++) {
        for(int j=0; j<numberOfColumns; j++) {
            posGrid[i][j] = 0;
            if(grid[i][j]==79) {
                posGrid[i][j] = 1;
            }
            grid[i][j] = 79;
        }
    }
 
    /*
    *   After 5 seconds, the bombs placed after 2 seconds
    *   will detonate, updating the grid
    */
    for(int i=0; i<numberOfRows; i++) {
        for(int j=0; j<numberOfColumns; j++) {
            if(posGrid[i][j]==1) {
                grid[i][j] = '.';
                if(j-1>=0) {
                    grid[i][j-1] = '.';
                }
                if(i-1>=0) {
                    grid[i-1][j] = '.';
                }
                if(j+1<numberOfColumns) {
                    grid[i][j+1] = '.';
                }
                if(i+1<numberOfRows) {
                    grid[i+1][j] = '.';
                }
            }
        }
    }
 
    /*
    *   The grid now obtained will be repeated at second
    *   9, 13, 17, 21, 25....
    *   Therefore, returning this grid as the other possibilities
    *   are already considered above
    */
    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

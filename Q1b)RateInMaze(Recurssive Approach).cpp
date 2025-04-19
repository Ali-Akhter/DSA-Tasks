
#include <iostream>
#include<stack>
using namespace std;

void checkAndSaveCheckPoint(int maze[][10], stack<int> & x_index, stack<int> & y_index, int current_x, int current_y, int size_x, int size_y)
{
    int count_ways = 0;

    if ((current_x + 1 < size_x) && (maze[current_x + 1][current_y] != 0) && (maze[current_x + 1][current_y] != -1))
        count_ways++;

    if ((current_x - 1 >= 0) && (maze[current_x - 1][current_y] != 0) && (maze[current_x - 1][current_y] != -1))
        count_ways++;

    if ((current_y + 1 < size_y) && (maze[current_x][current_y + 1] != 0) && (maze[current_x][current_y + 1] != -1))
        count_ways++;

    if ((current_y - 1 >= 0) && (maze[current_x][current_y - 1] != 0) && (maze[current_x][current_y - 1] != -1))
        count_ways++;

    if (count_ways > 1)
    {

        x_index.push(current_x);
        y_index.push(current_y);
    }

}

bool findPath(int maze[][10],stack<int> & x_index, stack <int>& y_index, int size_x, int size_y, int current_x, int current_y)
{
    maze[current_x][current_y] = -1;

    if ((current_x == size_x - 1) && (current_y == size_y - 1))
        return 1;

    else if (((current_y + 1 < size_y) && (maze[current_x][current_y + 1] != 0) && (maze[current_x][current_y + 1] != -1)))
    {

        checkAndSaveCheckPoint(maze, x_index, y_index, current_x, current_y, size_x, size_y);
        current_y++;
        findPath(maze, x_index, y_index, size_x, size_y, current_x, current_y);
    }

    else if ((current_y - 1 >= 0) && (maze[current_x][current_y - 1] != 0) && (maze[current_x][current_y - 1] != -1))
    {

        checkAndSaveCheckPoint(maze, x_index, y_index, current_x, current_y, size_x, size_y);
        current_y--;
        findPath(maze, x_index, y_index, size_x, size_y, current_x, current_y);



    }

    else if ((current_x + 1 < size_x) && (maze[current_x + 1][current_y] != 0) && (maze[current_x + 1][current_y] != -1))
    {


        checkAndSaveCheckPoint(maze, x_index, y_index, current_x, current_y, size_x, size_y);
        current_x++;
        findPath(maze, x_index, y_index, size_x, size_y, current_x, current_y);

    }
    else if ((current_x - 1 >= 0) && (maze[current_x - 1][current_y] != 0) && (maze[current_x - 1][current_y] != -1))
    {

        checkAndSaveCheckPoint(maze, x_index, y_index, current_x, current_y, size_x, size_y);
        current_x--;
        findPath(maze, x_index, y_index, size_x, size_y, current_x, current_y);
     

    }
    else 
    {
        if (!x_index.empty())
        {
            current_x = x_index.top();
            current_y = y_index.top();
            x_index.pop();
            y_index.pop();
            findPath(maze, x_index, y_index, size_x, size_y, current_x, current_y);
        }
        else
        {
            
            return 0;
        }
    }

}
int main()
{
    int maze[10][10] = {
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
    };


    stack <int> x_index;
    stack <int> y_index;

    if (findPath(maze, x_index, y_index, 10, 10, 0, 0))
        cout << "Path is possible" << endl;
    else
        cout << "Path not possible " << endl;

    for (int i = 0;i < 10;i++)
    {
        for (int j = 0;j < 10;j++)
            cout << maze[i][j] << " ";
        cout << endl;
    }



    return 0;
}


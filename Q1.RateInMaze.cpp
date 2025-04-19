


#include <iostream>
#include<fstream>
#include <stack>
using namespace std;

class Stack {
private:
    int arr[1000];
    int size;
    int top;

public:
    Stack(int size1 = 100) :size(size1), top(-1) {}


    void push(int value) {
        if (top >= size - 1) {
            cout << "Stack is full " << value << endl;
        }
        else {
            arr[++top] = value;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        }
        else {
            arr[top--];
        }
    }

    int Top() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return '\0';
        }
        else {
            return arr[top];
        }
    }

    bool empty() {
        return top == -1;
    }
};
void checkAndSaveCheckPoint(int** maze, Stack& x_index, Stack& y_index, int current_x, int current_y, int size_x, int size_y);


int main()
{
    Stack  x_index;
    Stack  y_index;


    int size_x;
    int size_y;

    ifstream read("input.txt");

    read >> size_x;
    read >> size_y;

    int** maze = new int* [size_x];


    for (int i = 0; i < size_x; i++) {
        maze[i] = new int[size_y];
    }



    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            read >> maze[i][j];
        }
    }




    int current_x = 0;
    int current_y = 0;
    bool flag = 0;

    while (1)
    {

        flag = 1;
        if (current_x == size_x - 1 && current_y == size_y - 1)
        {
            cout << "Path has been found and marked. Output file also has been updated " << endl;
            break;
        }

        else if ((current_y + 1 < size_y) && (maze[current_x][current_y + 1] != 0) && (maze[current_x][current_y + 1] != -1))
        {


            checkAndSaveCheckPoint(maze, x_index, y_index, current_x, current_y, size_x, size_y);
            maze[current_x][current_y + 1] = -1;
            current_y++;
            flag = 0;

        }
        else if ((current_y - 1 >= 0) && (maze[current_x][current_y - 1] != 0) && (maze[current_x][current_y - 1] != -1))
        {

            checkAndSaveCheckPoint(maze, x_index, y_index, current_x, current_y, size_x, size_y);
            maze[current_x][current_y - 1] = -1;
            current_y--;
            flag = 0;


        }

        else if ((current_x + 1 < size_x) && (maze[current_x + 1][current_y] != 0) && (maze[current_x + 1][current_y] != -1))
        {


            checkAndSaveCheckPoint(maze, x_index, y_index, current_x, current_y, size_x, size_y);
            maze[current_x + 1][current_y] = -1;
            current_x++;

        }
        else if ((current_x - 1 >= 0) && (maze[current_x - 1][current_y] != 0) && (maze[current_x - 1][current_y] != -1))
        {

            checkAndSaveCheckPoint(maze, x_index, y_index, current_x, current_y, size_x, size_y);
            maze[current_x - 1][current_y] = -1;
            current_x--;
            flag = 0;

        }



        else if (flag)
        {
            if (!x_index.empty())
            {
                current_x = x_index.Top();
                current_y = y_index.Top();
                x_index.pop();
                y_index.pop();
            }
            else
            {
                cout << "No possible path found.Output file also has been updated " << endl;
                break;
            }
        }


    }

    ofstream write("output.txt");
    for (int i = 0;i < size_x;i++)
    {
        for (int j = 0;j < size_y;j++)
        {
            cout << maze[i][j] << " ";
            write << maze[i][j] << " ";

        }
        cout << endl;
        write << endl;
    }



    for (int i = 0; i < size_x; i++) {
        delete[] maze[i];
    }
    delete[] maze;


    return 0;
}

void checkAndSaveCheckPoint(int** maze, Stack& x_index, Stack& y_index, int current_x, int current_y, int size_x, int size_y)
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


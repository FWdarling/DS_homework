#include"../../Lab/vector.h"

using std::cin;
using std::cout;
using std::endl;
using std::pair;

typedef pair<int32_t, int32_t> Point;

void input(Vector<Vector<char> >& maze, Vector<Vector<Point> >& next, 
        const int32_t row_size, const int32_t col_size,Point& start, Point& end){
    char static_maze[10][11] = 
    {
        "##########",
        "#XX XX XX#",
        "#XX     X#",
        "#   XXXXX#",
        "#XX    XX#",
        "#  X XXXX#",
        "#XXX   XX#",
        "#XXXX    #", 
        "#XXX XXXX#",
        "##########"
    };
    start = {1, 3};
    end = {7, 8};
    for(int32_t i = 0; i < row_size; i++){
        for(int32_t j = 0; j < col_size; j++){
            maze[i].push_back(static_maze[i][j]);
            Point p = {i, j};
            next[i].push_back(p);
        }
    }
}

void produce(Vector<Vector<char> >& maze, Vector<Vector<Point> >& next, Point& start, Point& end){
    const int32_t row_size = 10;
    const int32_t col_size = 10;
    
    for(int32_t i = 0; i < row_size; i++){
        Vector<char> row(col_size);
        maze.push_back(row);
        Vector<Point> next_row(col_size);
        next.push_back(next_row);
    }
    input(maze, next, row_size, col_size, start, end);
}

void display(Vector<Vector<char> >& maze){
    int32_t row_size = maze.get_len();
    int32_t col_size = maze[0].get_len();
    for(int32_t i = 0; i < row_size; i++){
        for(int32_t j = 0; j < col_size; j++){
            cout << maze[i][j];
        }
        cout << endl;
    }
}

bool dfs(Vector<Vector<char> >& maze, Vector<Vector<Point> >& next,Point current_point, Point end){
    if(current_point == end) return true;
    const int32_t dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    for(int32_t i = 0; i < 4; i++){
        int32_t x = current_point.first + dir[i][0];
        int32_t y = current_point.second + dir[i][1];
        if(maze[x][y] == ' ' && next[x][y] == (Point){x, y}) {
            next[current_point.first][current_point.second] = (Point){x, y};
            if(dfs(maze, next, (Point){x, y}, end)) return true;
        }
    }
    return false;
}

void print_point(Point point){
    cout << "(" << point.first << ", " << point.second << ") ";
}
void print(Vector<Vector<Point> >& next, Point& start, Point& end){
    Point current_point = start;
    while(current_point != end){
        int32_t x = current_point.first, y = current_point.second;
        print_point(current_point);
        cout << "-> ";
        current_point = next[x][y];
    }
    print_point(current_point);
    cout << endl;
}  

int main(){
    Vector<Vector<char> > maze;
    Vector<Vector<Point> > next;
    Point start, end;
    produce(maze, next, start, end);
    display(maze);
    if(dfs(maze, next, start, end)){
        print(next, start, end);
    }else{
        cout << "The maze is unsolvable!" << endl;
    }
}
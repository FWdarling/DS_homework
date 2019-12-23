#include"../head/q8.h"

using std::string;
int main(){
    cout << "Welcome to the grid generating system" << endl;
    MST grid;
    int32_t count_vercite, count_edge;
    Vector<char> vercite_index_map;
    char operation = 0;
    while(operation != 'Q'){
        instructions();
        cin >> operation;
        if(operation != 'Q'){
            char start_vertice;
            switch (operation)
            {
                case 'A':
                    cout << "Please enter the number of vertices: ";
                    cin >> count_vercite;
                    grid.resize(count_vercite);
                    cout << "Please enter each point name in turn: ";
                    for(int32_t i = 0; i < count_vercite; i++){
                        char vertice;
                        cin >> vertice;
                        vercite_index_map.push_back(vertice);
                    }
                    break;
                case 'B':
                    cout << "Please enter the total number of edges: ";
                    cin >> count_edge;
                    if(count_edge > (count_vercite - 1) * count_vercite / 2) {
                        cout << "error: illegal number of edge input!" << endl;
                        break;
                    }
                    add_edge(grid, count_edge, vercite_index_map);
                    break;
                case 'C':
                    cout << "Please enter the starting vertex: ";
                    cin >> start_vertice;
                    generate(grid, start_vertice, vercite_index_map);
                    cout << "Generate grid successfully!" << endl;;
                    break;
                case 'D':
                    cout << "The edges and vertices of the grid are: " << endl;
                    display(grid, vercite_index_map);
                    break;
                default:
                    cout << "Incorrect input. Please re-enter your operation." << endl;
                    break;
            }
        }
        cout << endl;
    }
    return 0;
}
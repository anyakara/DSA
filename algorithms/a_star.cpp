#include<iostream>
#include<cmath>
#include<vector>
#include<unordered_map>
#include<queue>

#define GRID_SIZE 10
#define INF 1e9

struct Node {
    int x; int y;
    int g_cost;
    int f_cost;
    Node *parent;
    Node(int x_, int y_, int g_ = INF, int f_ = INF, Node *parent_ = nullptr) : x(x_), y(y_), g_cost(g_), f_cost(f_), parent(parent_) {}
    bool operator<(const Node &other) const { return f_cost > other.f_cost; }
};

#define MANHATTAN_HEURISTIC(x_current, y_current, x_goal, y_goal) (abs(x_goal-x_current) + abs(y_goal-y_current))
//#define EUCLIDEAN_HEURISTIC(x_current, y_current, x_goal, y_goal) (((x_goal - x_current)**2) + ((y_goal-y_current)**2))

std::vector<Node> get_neighbors(Node&current, int grid[GRID_SIZE][GRID_SIZE]) {
    std::vector<Node> neighbors;
    int directions[4][2] = {{0, 1}, {1,0}, {0, -1}, {-1,0}};
    for (auto &dir:directions) {
        int new_x = current.x + dir[0];
        int new_y = current.y + dir[1];
        if (new_x >= 0 && new_x < GRID_SIZE && new_y >= 0 && new_y < GRID_SIZE && grid[new_x][new_y] == 0) { 
            neighbors.emplace_back(new_x, new_y);
        }
    };
    return neighbors;
}

void reconstruct_path(Node *current) {
    while (current != nullptr) {
        std::cout << "(" << current->x << ", " << current->y << ") ";
        current = current->parent;
    } std::cout << "\n";
}

void a_star(int grid[GRID_SIZE][GRID_SIZE], Node &start, Node &goal) {
    std::priority_queue<Node> open_set;
    std::unordered_map<int, Node> all_nodes;

    auto hash_pos = [](int x, int y) { return x * GRID_SIZE + y; };

    start.g_cost = 0;
    start.f_cost = MANHATTAN_HEURISTIC(start.x, start.y, goal.x, goal.y);

    open_set.push(start);
    all_nodes[hash_pos(start.x, start.y)] = start;

    while (!open_set.empty()) {
        
        Node current = open_set.top();
        open_set.pop();

        if (current.x == goal.x && current.y == goal.y) {
            reconstruct_path(&all_nodes[hash_pos(current.x, current.y)]);
            return;
        }
        for (auto & neighbor : get_neighbors(current, grid)) {
            int tentative_g_cost = current.g_cost + 1;
            if (tentative_g_cost < neighbor.g_cost) {
                neighbor.g_cost = tentative_g_cost;
                neighbor.f_cost = tentative_g_cost + MANHATTAN_HEURISTIC(neighbor.x, neighbor.y, goal.x, goal.y);
                neighbor.parent = &all_nodes[hash_pos(current.x, current.y)];
                if (all_nodes.find(hash_pos(neighbor.x, neighbor.y)) == all_nodes.end() || tentative_g_cost < all_nodes[hash_pos(neighbor.x, neighbor.y)].g_cost) { 
                    open_set.push(neighbor);
                    all_nodes[hash_pos(neighbor.x, neighbor.y)] = neighbor;
                }
            }
        }
    }
    std::cout << "No path found" << std::endl;
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE] =
    {
        {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 1, 1, 1, 0}
    };

    Node start(0, 0);
    Node goal(0, 0);
    a_star(grid, start, goal);
    return 0;
}

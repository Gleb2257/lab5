#include <iostream>
#include <locale>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция для генерации случайного неориентированного графа
vector<pair<int, int>> generate_edges(int size) {
    vector<pair<int, int>> edges;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (rand() % 2) { 
                edges.push_back({ i, j });
            }
        }
    }
    return edges;
}

vector<vector<int>> generate_incidence_matrix(int vertices, const vector<pair<int, int>>& edges) {
    vector<vector<int>> incidence_matrix(vertices, vector<int>(edges.size(), 0));

    for (int e = 0; e < edges.size(); ++e) {
        int u = edges[e].first;
        int v = edges[e].second;
        incidence_matrix[u][e] = 1;
        incidence_matrix[v][e] = 1;
    }

    return incidence_matrix;
}

void analyze_vertices(const vector<vector<int>>& incidence_matrix) {
    int vertices = incidence_matrix.size();
    int edges = incidence_matrix[0].size();
    vector<int> isolated, terminal, dominant;

    for (int i = 0; i < vertices; ++i) {
        int degree = 0;  // Степень вершины
        for (int j = 0; j < edges; ++j) {
            if (incidence_matrix[i][j] == 1) {
                degree++;
            }
        }

        if (degree == 0) {
            isolated.push_back(i);
        }
   
        else if (degree == 1) {
            terminal.push_back(i);
        }
       
        else if (degree == edges) {
            dominant.push_back(i);
        }
    }

    // Вывод результатов
    cout << "Изолированные вершины: ";
    for (int v : isolated) cout << v << " ";
    cout << endl;

    cout << "Концевые вершины: ";
    for (int v : terminal) cout << v << " ";
    cout << endl;

    cout << "Доминирующие вершины: ";
    for (int v : dominant) cout << v << " ";
    cout << endl;
}

void print_matrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0)));

    int vertices;
    cout << "Введите количество вершин графа: ";
    cin >> vertices;

    vector<pair<int, int>> edges = generate_edges(vertices);

    vector<vector<int>> incidence_matrix = generate_incidence_matrix(vertices, edges);

    cout << "Матрица инцидентности графа:" << endl;
    print_matrix(incidence_matrix);

    cout << "Размер графа (количество вершин): " << vertices << endl;
    cout << "Количество рёбер: " << edges.size() << endl;

    analyze_vertices(incidence_matrix);

    return 0;
}

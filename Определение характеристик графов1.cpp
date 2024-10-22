#include <iostream>
#include <locale>
#include <vector>
#include <ctime>  
#include <cstdlib>

using namespace std;

// Функция для генерации случайной матрицы смежности
vector<vector<int>> generate_adjacency_matrix(int size) {
    vector<vector<int>> matrix(size, vector<int>(size, 0));

    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            int edge = rand() % 2; 
            matrix[i][j] = edge;
            matrix[j][i] = edge; 
        }
    }

    return matrix;
}

// Функция для анализа вершин (изолированные, концевые, доминирующие)
void analyze_vertices(const vector<vector<int>>& matrix) {
    int size = matrix.size();
    vector<int> isolated, terminal, dominant;

    for (int i = 0; i < size; ++i) {
        int degree = 0;  
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] == 1) {
                degree++;
            }
        }

        if (degree == 0) {
            isolated.push_back(i);
        }
        else if (degree == 1) {
            terminal.push_back(i);
        }
        else if (degree == size - 1) {
            dominant.push_back(i);
        }
    }

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

// Функция для вывода матрицы смежности
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

    int size;
    cout << "Введите количество вершин графа: ";
    cin >> size;

    // Генерация матрицы смежности
    vector<vector<int>> adjacency_matrix = generate_adjacency_matrix(size);

    // Вывод матрицы смежности
    cout << "Матрица смежности графа:" << endl;
    print_matrix(adjacency_matrix);

    // Вывод размера графа
    cout << "Размер графа (количество вершин): " << size << endl;

    analyze_vertices(adjacency_matrix);

    return 0;
}

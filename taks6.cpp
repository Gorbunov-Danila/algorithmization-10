#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printSortedSums(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<int> result(n * n);

    // Сначала создаем кучу из первых элементов сумм A[i]+B[0]
    vector<pair<int, pair<int, int>>> heap;
    for (int i = 0; i < n; i++) {
        heap.push_back({ A[i] + B[0], {i, 0} });
    }
    make_heap(heap.begin(), heap.end());

    for (int i = 0; i < n * n; i++) {
        // Извлекаем минимальный элемент из кучи
        pair<int, pair<int, int>> minElement = heap.front();
        pop_heap(heap.begin(), heap.end());
        heap.pop_back();

        result[i] = minElement.first;

        int aIndex = minElement.second.first;
        int bIndex = minElement.second.second;

        // Добавляем следующий элемент из B в кучу
        if (bIndex < n - 1) {
            int nextSum = A[aIndex] + B[bIndex + 1];
            heap.push_back({ nextSum, {aIndex, bIndex + 1} });
            push_heap(heap.begin(), heap.end());
        }
    }

    // Выводим отсортированные суммы
    for (int i = 0; i < n * n; i++) {
        cout << result[i] << " ";
    }
}

int main() {
    vector<int> A = { 1, 3, 5 };
    vector<int> B = { 2, 4, 6 };
    printSortedSums(A, B);

    return 0;
}

//Этот алгоритм использует структуру данных "куча" для хранения и извлечения минимальных сумм A[i]+B[j], что позволяет достичь времени работы O(n^2 log n) и использовать линейную память.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printSortedSums(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<int> result(n * n);

    // ������� ������� ���� �� ������ ��������� ���� A[i]+B[0]
    vector<pair<int, pair<int, int>>> heap;
    for (int i = 0; i < n; i++) {
        heap.push_back({ A[i] + B[0], {i, 0} });
    }
    make_heap(heap.begin(), heap.end());

    for (int i = 0; i < n * n; i++) {
        // ��������� ����������� ������� �� ����
        pair<int, pair<int, int>> minElement = heap.front();
        pop_heap(heap.begin(), heap.end());
        heap.pop_back();

        result[i] = minElement.first;

        int aIndex = minElement.second.first;
        int bIndex = minElement.second.second;

        // ��������� ��������� ������� �� B � ����
        if (bIndex < n - 1) {
            int nextSum = A[aIndex] + B[bIndex + 1];
            heap.push_back({ nextSum, {aIndex, bIndex + 1} });
            push_heap(heap.begin(), heap.end());
        }
    }

    // ������� ��������������� �����
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

//���� �������� ���������� ��������� ������ "����" ��� �������� � ���������� ����������� ���� A[i]+B[j], ��� ��������� ������� ������� ������ O(n^2 log n) � ������������ �������� ������.
#include <iostream>

namespace MatrixNS
{
    int** readMatrix (size_t& n, size_t& m)
    {
        std::cout << "Enter n and m: ";
        std::cin >> n >> m;

        int** matrix = new int*[n];
        for (size_t i = 0; i < n; i++)
        {
            matrix[i] = new int[m];
            for (size_t j = 0; j < m; j++)
            {
                std::cin >> matrix[i][j];
            }
        }

        return matrix;
    }

    int** transposeMatrix(int** matrix, size_t n, size_t m)
{
    int** transposedMatrix = new int*[m];
    for (size_t i = 0; i < m; i++)
    {
        transposedMatrix[i] = new int[n];
        for (size_t j = 0; j < n; j++)
        {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }

    return transposedMatrix;
}

    void deleteMatrix (int** matrix, size_t n)
    {
        for (size_t i = 0; i < n; i++)
        {        
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void swap (int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void swapRows (int** matrix, size_t row1, size_t row2, size_t n, size_t m)
    {
        if (row1 >= n || row2 >= n) return;

        for (size_t i = 0; i < m; i++)
        {
            swap(matrix[row1][i], matrix[row2][i]);
        }
    }

    void printMatrix (int** matrix, size_t n, size_t m)
    {
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}

int main()
{
    size_t n, m;
    
    int** matrix = MatrixNS::readMatrix(n, m);

    int** transposed = MatrixNS::transposeMatrix(matrix, n, m);
    MatrixNS::printMatrix(transposed, m, n);
    std::cout << std::endl;

    size_t row1, row2;
    std::cin >> row1 >> row2;
    std::cout << std::endl;

    if (row1 < n && row2 < n) {
        MatrixNS::swapRows(matrix, row1, row2, n, m);
        MatrixNS::printMatrix(matrix, n, m);
    }

    MatrixNS::deleteMatrix(matrix, n);
    MatrixNS::deleteMatrix(transposed, m);
}
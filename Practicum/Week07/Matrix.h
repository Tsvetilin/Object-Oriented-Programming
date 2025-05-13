#ifndef _MATRIX_H
#define _MATRIX_H

#include<iostream>

class Matrix {
public:
	Matrix(size_t rowns, size_t columns);
	Matrix() = default;
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	~Matrix();

	void setRowsCount(size_t rows);
	void setColumnsCount(size_t columns);
	size_t getRowsCount() const;
	size_t getColumnsCount() const;
	int** getMatrix() const;

	Matrix& operator+=(const Matrix& other);
	friend Matrix operator+(const Matrix& m1, const Matrix& m2);
	Matrix& operator-=(const Matrix& other);
	friend Matrix operator-(const Matrix& m1, const Matrix& m2);
	Matrix& operator*=(const Matrix& other);
	friend Matrix operator*(const Matrix& m1, const Matrix& m2);
	Matrix& operator*=(int coeff);
	Matrix operator*(int coeff);
	bool operator==(const Matrix& other) const;
	bool operator!=(const Matrix& other) const;
	int* operator[](size_t index) const;
	operator bool() const;

	void initialiseElementsInMatrix(size_t rows, size_t columns);
	void printMatrix() const;

private:
	size_t rows = 2;
	size_t columns = 2;
	int** matrix = nullptr;

	void copyFrom(const Matrix& other);
	void free();

	int** createMatrix(size_t rows, size_t colums);
	void deleteMatrix();
};

#endif // !_MATRIX_H

#include "Matrix.h"
#include<iostream>

void Matrix::copyFrom(const Matrix& other) {
	if (other.rows < 0 || other.columns < 0) {
		std::cerr << "Invalid sizes!" << std::endl;
		return;
	}

	this->rows = other.rows;
	this->columns = other.columns;

	createMatrix(other.rows, other.columns);

	for (size_t i = 0; i < other.rows; ++i) {
		for (size_t j = 0; j < other.columns; ++j) {
			this->matrix[i][j] = other.matrix[i][j];
		}
	}
}

void Matrix::free() {
	this->deleteMatrix();
}

int** Matrix::createMatrix(size_t rows, size_t columns) {
	this->matrix = new int*[rows];

	for (size_t i = 0; i < rows; ++i) {
		this->matrix[i] = new int[columns];
	}

	return matrix;
}

void Matrix::initialiseElementsInMatrix(size_t rows, size_t columns) {
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			std::cout << "Enter element [" << i << "][" << j << "]: ";
			std::cin >> this->matrix[i][j];
		}
	}
}

void Matrix::printMatrix() const {
	std::cout << "Matrix:" << std::endl;

	for (size_t i = 0; i < this->rows; ++i) {
		for (size_t j = 0; j < this->columns; ++j) {
			std::cout << this->matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Matrix::deleteMatrix() {
	for (size_t i = 0; i < this->rows; ++i) {
		delete[] this->matrix[i];
	}

	delete[] this->matrix;
}

Matrix::Matrix(size_t rows, size_t columns) {
	setRowsCount(rows);
	setColumnsCount(columns);

	this->createMatrix(rows, columns);

	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			this->matrix[i][j] = matrix[i][j];
		}
	}
}

Matrix::Matrix(const Matrix& other) {
	this->copyFrom(other);
}

Matrix& Matrix::operator=(const Matrix& other) {
	if (this != &other) {
		this->free();
		this->copyFrom(other);
	}

	return *this;
}

Matrix::~Matrix() {
	this->free();
}

void Matrix::setRowsCount(size_t rows) {
	if (rows < 1) {
		std::cerr << "Invalid number of rows!" << std::endl;
		return;
	}
	
	this->rows = rows;
}

void Matrix::setColumnsCount(size_t columns) {
	if (columns < 1) {
		std::cerr << "Invalid number of columns!" << std::endl;
		return;
	}

	this->columns = columns;
}

size_t Matrix::getRowsCount() const {
	return this->rows;
}

size_t Matrix::getColumnsCount() const {
	return this->columns;
}

int** Matrix::getMatrix() const {
	return this->matrix;
}

Matrix& Matrix::operator+=(const Matrix& other) {
	for (size_t i = 0; i < this->rows; ++i) {
		for (size_t j = 0; j < this->columns; ++j) {
			this->matrix[i][j] += other.matrix[i][j];
		}
	}

	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
	for (size_t i = 0; i < this->rows; ++i) {
		for (size_t j = 0; j < this->columns; ++j) {
			this->matrix[i][j] -= other.matrix[i][j];
		}
	}

	return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
	if (this->columns != other.rows) {
		std::cerr << "Matrices have incompatible sizes for multiplication!" << std::endl;
		return *this;
	}

	Matrix result(this->rows, other.columns);
	for (size_t i = 0; i < this->rows; ++i) {
		for (size_t j = 0; j < other.columns; ++j) {
			result.matrix[i][j] = 0;
			for (size_t k = 0; k < this->columns; ++k) {
				result.matrix[i][j] += this->matrix[i][k] * other.matrix[k][j];
			}
		}
	}

	return *this;
}

Matrix& Matrix::operator*=(int coeff) {
	if (coeff == 0) {
		std::cerr << "Invalid coefficient!" << std::endl;
		return *this;
	}

	for (size_t i = 0; i < this->rows; ++i) {
		for (size_t j = 0; j < this->columns; ++j) {
			this->matrix[i][j] *= coeff;
		}
	}

	return *this;
}

Matrix Matrix::operator*(int coeff) {
	if (coeff == 0) {
		std::cerr << "Invalid coefficient!" << std::endl;
		return Matrix();
	}

	Matrix result(this->rows, this->columns);
	for (size_t i = 0; i < this->rows; ++i) {
		for (size_t j = 0; j < this->columns; ++j) {
			result.matrix[i][j] = this->matrix[i][j] * coeff;
		}
	}

	return result;
}

bool Matrix::operator==(const Matrix& other) const {
	if (this->rows != other.rows || this->columns != other.columns) {
		return false;
	}

	for (size_t i = 0; i < this->rows; ++i) {
		for (size_t j = 0; j < this->columns; ++j) {
			if (this->matrix[i][j] != other.matrix[i][j]) {
				return false;
			}
		}
	}

	return true;
}

bool Matrix::operator!=(const Matrix& other) const {
	return !(*this == other);
}

int* Matrix::operator[](size_t index) const {
	if (index >= this->rows) {
		std::cerr << "Invalid row index!" << std::endl;
		return nullptr;
	}

	return this->matrix[index];
}

Matrix::operator bool() const {
	for (size_t i = 0; i < this->rows; ++i) {
		for (size_t j = 0; j < this->columns; ++j) {
			if (this->matrix[i][j] == 0) {
				return false;
			}
		}
	}

	return true;
}

Matrix operator+(const Matrix& m1, const Matrix& m2) {
	if (m1.rows != m2.rows || m1.columns != m2.columns) {
		std::cerr << "Matrices have different sizes!" << std::endl;
		return Matrix();
	}

	Matrix result(m1.rows, m1.columns);

	for (size_t i = 0; i < m1.rows; ++i) {
		for (size_t j = 0; j < m1.columns; ++j) {
			result.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
		}
	}

	return result;
}

Matrix operator-(const Matrix& m1, const Matrix& m2) {
	Matrix result(m1.rows, m1.columns);

	for (size_t i = 0; i < m1.rows; ++i) {
		for (size_t j = 0; j < m1.columns; ++j) {
			result.matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j];
		}
	}

	return result;
}

Matrix operator*(const Matrix& m1, const Matrix& m2) {
	if (m1.columns != m2.rows) {
		std::cerr << "Matrices have incompatible sizes for multiplication!" << std::endl;
		return Matrix();
	}

	Matrix result(m1.rows, m2.columns);
	for (size_t i = 0; i < m1.rows; ++i) {
		for (size_t j = 0; j < m2.columns; ++j) {
			result.matrix[i][j] = 0;
			for (size_t k = 0; k < m1.columns; ++k) {
				result.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
			}
		}
	}

	return result;
}

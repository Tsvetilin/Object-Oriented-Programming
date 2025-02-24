#include <iostream>

// Ex. 1
namespace MatrixNS
{
	double** writeMatrix(const size_t n, const size_t m)
	{
		double** matrix = new double* [n];
		for (size_t i = 0; i < n; i++)
		{
			matrix[i] = new double[m];
		}

		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				std::cin >> matrix[i][j];
			}
		}

		return matrix;
	}

	double** transpose(const double* const* const matrix, const size_t n, const size_t m)
	{
		if (!matrix) return nullptr;

		double** transposed = new double* [m];
		for (size_t i = 0; i < n; i++)
		{
			transposed[i] = new double[n];
		}

		for (size_t i = 0; i < m; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				transposed[i][j] = matrix[j][i];
			}
		}

		return transposed;
	}

	void swapRows(double** matrix, const size_t n, const size_t row1, const size_t row2)
	{
		if (!matrix) return;

		if (row1 < 0 || row1 >= n || row2 < 0 || row2 >= n) return;

		std::swap(matrix[row1], matrix[row2]);
	}

	void printMatrix(const double* const* const matrix, const size_t n, const size_t m)
	{
		if (!matrix) return;

		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				std::cout << matrix[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
}


// Ex. 2
namespace ComplexNumber
{
	struct Complex
	{
		double real = 0;
		double imaginary = 0;
	};

	Complex addition(Complex& a, Complex& b)
	{
		return Complex{ a.real + b.real, a.imaginary + b.imaginary };
	}

	Complex muliply(Complex& a, Complex& b)
	{
		return Complex{ a.real * b.real - a.imaginary * b.imaginary,
			a.real * b.imaginary + a.imaginary * b.real };
	}

	void printComplex(Complex& a)
	{
		std::cout << a.real << " " << (a.imaginary > 0 ? '+' : '-') 
			<< " " << abs(a.imaginary) << "i\n";
	}
}


// Ex. 3
namespace Triangle
{
	struct Point
	{
		double x = 0;
		double y = 0;
	};

	struct Triangle
	{
		char* name = nullptr;
		Point firstPoint;
		Point secondPoint;
		Point thirdPoint;
		double area;
	};

	double calculateSide(const Point& a, const Point& b)
	{
		double base = abs(a.x - b.x);
		double height = abs(a.y - b.y);

		return sqrt(pow(base, 2) + pow(height, 2));
	}

	double calculateArea(const Triangle& triangle)
	{
		double firstSide = calculateSide(triangle.firstPoint, triangle.secondPoint);
		double secondSide = calculateSide(triangle.secondPoint, triangle.thirdPoint);
		double thirdSide = calculateSide(triangle.thirdPoint, triangle.firstPoint);

		double semiArea = (firstSide + secondSide + thirdSide) / 2;

		return sqrt(semiArea 
			* (semiArea - firstSide) 
			* (semiArea - secondSide) 
			* (semiArea - thirdSide));
	}

	void sortByArea(Triangle* triangles, const size_t n)
	{
		for (size_t i = 0; i < n - 1; i++)
		{
			size_t minIndex = i;
			for (size_t j = i + 1; j < n; j++)
			{
				if (triangles[minIndex].area > triangles[j].area)
				{
					minIndex = j;
				}
			}

			if (minIndex != i)
			{
				std::swap(triangles[i], triangles[minIndex]);
			}
		}
	}
}

int main()
{
	const size_t STR_SIZE = 1024;
	
	// Ex. 1
	/*size_t n, m;
	std::cin >> n >> m;

	double** matrix = MatrixNS::writeMatrix(n, m);
	MatrixNS::printMatrix(matrix, n, m);
	double** transposedMatrix = MatrixNS::transpose(matrix, n, m);
	MatrixNS::printMatrix(transposedMatrix, m, n);
	MatrixNS::swapRows(matrix, n, n - 1, 0);
	MatrixNS::printMatrix(matrix, n, m);

	for (size_t i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

	for (size_t i = 0; i < m; i++)
	{
		delete[] transposedMatrix[i];
	}
	delete[] transposedMatrix;*/

	// Ex. 3
	/*size_t n;
	std::cin >> n;
	std::cin.ignore();

	Triangle::Triangle* triangles = new Triangle::Triangle[n];
	for (size_t i = 0; i < n; i++)
	{
		char tempName[STR_SIZE + 1];
		std::cin.getline(tempName, STR_SIZE);
		triangles[i].name = new char[strlen(tempName) + 1];
		strcpy_s(triangles[i].name, strlen(tempName) + 1, tempName);
		
		std::cin >> triangles[i].firstPoint.x;
		std::cin >> triangles[i].firstPoint.y;
		std::cin >> triangles[i].secondPoint.x;
		std::cin >> triangles[i].secondPoint.y;
		std::cin >> triangles[i].thirdPoint.x;
		std::cin >> triangles[i].thirdPoint.y;
		std::cin.ignore();

		triangles[i].area = Triangle::calculateArea(triangles[i]);
	}

	Triangle::sortByArea(triangles, n);

	for (size_t i = 0; i < n; i++)
	{
		std::cout << triangles[i].name << " with area: " << triangles[i].area << "\n";
	}*/
}

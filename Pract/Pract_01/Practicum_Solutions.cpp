#include <iostream>

const size_t STR_SIZE = 1024;
const double EPSILON = 1e-5;

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
		for (size_t i = 0; i < m; i++)
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


// Ex. 4
namespace University
{
	enum class Major
	{
		SoftwareEngineering,
		InformationSystems,
		ComputerScience,
		AppliedMathematics,
		Maths,
		Informatics,
	};

	struct Student
	{
		float grade;
		char* facultyNumber;
		char* name;
		Major major;
	};

	struct Group
	{
		Student* students;
		size_t studentsCount;
		float averageGrade;
	};

	float calculateAverageGrade(const Group& group)
	{
		float sum = 0;
		for (size_t i = 0; i < group.studentsCount; i++)
		{
			sum += group.students[i].grade;
		}
		return sum / group.studentsCount;
	}

	void sortGroupByFacultyNumber(const Group& group)
	{
		for (size_t i = 0; i < group.studentsCount - 1; i++)
		{
			size_t minIndex = i;
			for (size_t j = i + 1; j < group.studentsCount; j++)
			{
				if (strcmp(group.students[minIndex].facultyNumber,
					group.students[j].facultyNumber) > 0)
					minIndex = j;
			}

			if (minIndex != i)
			{
				std::swap(group.students[minIndex], group.students[i]);
			}
		}
	}

	Group createGroup(const size_t n)
	{
		Group group;
		group.students = new Student[n];
		group.studentsCount = n;
		group.averageGrade = 0;
		for (size_t i = 0; i < n; i++)
		{
			std::cout << "\nStudent Grade: ";
			std::cin >> group.students[i].grade;
			std::cin.ignore();

			char tempFacNum[STR_SIZE + 1];
			std::cout << "Student Faculty Number: ";
			std::cin.getline(tempFacNum, STR_SIZE);
			group.students[i].facultyNumber = new char[strlen(tempFacNum) + 1];
			strcpy_s(group.students[i].facultyNumber, strlen(tempFacNum) + 1, tempFacNum);

			char tempName[STR_SIZE + 1];
			std::cout << "Student Name: ";
			std::cin.getline(tempName, STR_SIZE);
			group.students[i].name = new char[strlen(tempName) + 1];
			strcpy_s(group.students[i].name, strlen(tempName) + 1, tempName);

			int major;
			std::cout << "Student Major Number: ";
			std::cin >> major;
			group.students[i].major = Major(major);
			std::cin.ignore();
		}
		group.averageGrade = calculateAverageGrade(group);
		sortGroupByFacultyNumber(group);
		return group;
	}

	size_t scholarsCount(const Group& group, const float minGrade)
	{
		size_t count = 0;
		for (size_t i = 0; i < group.studentsCount; i++)
		{
			if (group.students[i].grade > minGrade
				|| abs(group.students[i].grade - minGrade) < EPSILON)
				count++;
		}
		return count;
	}

	void sortStudentsByGrade(Student* students, const size_t count)
	{
		for (size_t i = 0; i < count - 1; i++)
		{
			size_t minIndex = i;
			for (size_t j = i + 1; j < count; j++)
			{
				if (students[minIndex].grade > students[j].grade)
				{
					minIndex = j;
				}
			}

			if (minIndex != i)
			{
				std::swap(students[i], students[minIndex]);
			}
		}
	}

	Student* scholars(const Group& group, const float minGrade, size_t& scholarsCount)
	{
		Student* scholars = new Student[group.studentsCount];
		scholarsCount = 0;
		for (size_t i = 0; i < group.studentsCount; i++)
		{
			if (group.students[i].grade > minGrade
				|| abs(group.students[i].grade - minGrade) < EPSILON)
				scholars[scholarsCount++] = group.students[i];
		}

		Student* fixedScholars = new Student[scholarsCount];
		for (size_t i = 0; i < scholarsCount; i++)
		{
			fixedScholars[i].grade = scholars[i].grade;
			fixedScholars[i].facultyNumber = new char[strlen(scholars[i].facultyNumber) + 1];
			strcpy_s(fixedScholars[i].facultyNumber, strlen(scholars[i].facultyNumber) + 1, scholars[i].facultyNumber);
			fixedScholars[i].name = new char[strlen(scholars[i].name) + 1];
			strcpy_s(fixedScholars[i].name, strlen(scholars[i].name) + 1, scholars[i].name);
			fixedScholars[i].major = scholars[i].major;
		}
		delete[] scholars;

		sortStudentsByGrade(fixedScholars, scholarsCount);
		return fixedScholars;
	}

	bool isStudentInGroup(const Group& group, const char* facultyNumber)
	{
		for (size_t i = 0; i < group.studentsCount; i++)
		{
			if (strcmp(group.students[i].facultyNumber, facultyNumber) == 0)
			{
				return true;
			}
		}
		return false;
	}
}


// Ex. 5
namespace CoordinateSystem
{
	enum class Quadrants
	{
		Origin,
		First,
		Second,
		Third,
		Fourth
	};

	struct Point
	{
		double x = 0;
		double y = 0;
	};

	Point writePoint()
	{
		Point point;

		std::cout << "X value: ";
		std::cin >> point.x;
		std::cout << "Y value: ";
		std::cin >> point.y;

		return point;
	}

	void printPoint(const Point& point)
	{
		std::cout << "Point(" << point.x << ", " << point.y << ")\n";
	}

	double distanceToCenter(Point point)
	{
		return sqrt(point.x * point.x + point.y * point.y);
	}

	double distanceBetween(Point a, Point b)
	{
		double x = abs(a.x - b.x);
		double y = abs(a.y - b.y);

		return sqrt(x * x + y * y);
	}

	Quadrants getPointQuadrant(Point point)
	{
		if (point.x > 0)
		{
			if (point.y > 0)
				return Quadrants::First;
			return Quadrants::Fourth;
		}
		else
		{
			if (point.y > 0)
				return Quadrants::Second;
			return Quadrants::Third;
		}
		return Quadrants::Origin;
	}

	short isPointInCircle(Point point, double radius)
	{
		double distanceToPoint = distanceToCenter(point);

		if (abs(distanceToPoint - radius) < EPSILON)
			return 0;
		if (distanceToPoint < radius)
			return -1;
		if (distanceToPoint > radius)
			return 1;
	}
}


// Ex. 6
namespace ITFirm
{
	const size_t NAME_SIZE = 100;
	const size_t EMPLOYEES_COUNT = 100;
	const int POSITIONS_COUNT = 4;
	const int GRADE_MIN = 1;
	const int GRADE_MAX = 100;

	enum class Positions
	{
		SoftwareEngineer = 1, 
		SeniorSoftwareEngineer, 
		EngineerManager, 
		LeadSoftwareEngineer
	};

	struct Employee
	{
		char name[NAME_SIZE + 1];
		Positions position;
		double salary;
		int grade;
	};

	struct Firm
	{
		Employee employees[EMPLOYEES_COUNT];
		size_t employeesCount;
		double averageSalary;
	};

	Employee createEmployee()
	{
		Employee employee;
		
		std::cout << "\nName: ";
		std::cin.getline(employee.name, NAME_SIZE + 1);

		std::cout << "Available Positions:\n";
		std::cout << "\t1. Software Engineer\n";
		std::cout << "\t2. Senior Software Engineer\n";
		std::cout << "\t3. Engineer Manager\n";
		std::cout << "\t4. Lead Software Engineer\n";

		int position;
		std::cout << "Position: ";
		std::cin >> position;
		employee.position = Positions(position);
		std::cout << "Salary: ";
		std::cin >> employee.salary;
		std::cout << "Grade: ";
		std::cin >> employee.grade;
		std::cin.ignore();

		return employee;
	}

    void printEmployee(const Employee& employee)
    {
		std::cout << "Name: " << employee.name << "\n";
		std::cout << "Position: ";
		switch (employee.position)
		{
		case Positions::SoftwareEngineer:
			std::cout << "Software Engineer";
			break;
        case Positions::SeniorSoftwareEngineer:
			std::cout << "Senior Software Engineer";
			break;
		case Positions::EngineerManager:
			std::cout << "Engineer Manager";
			break;
		case Positions::LeadSoftwareEngineer:
			std::cout << "Lead Software Engineer";
			break;
		default:
			std::cout << "Invalid";
		}
		std::cout << "\n";
		std::cout << "Salary: " << employee.salary << "\n";
		std::cout << "Grade: " << employee.grade << "\n\n";
    }

	double calculateAverageSalary(const Firm& firm)
	{
		double sum = 0;
		for (size_t i = 0; i < firm.employeesCount; i++)
		{
			sum += firm.employees[i].salary;
		}
		return sum / firm.employeesCount;
	}

	Firm createFirm(const size_t employeesCount)
	{
		Firm firm;

		firm.employeesCount = employeesCount;
		for (size_t i = 0; i < employeesCount; i++)
		{
			firm.employees[i] = createEmployee();
		}

		firm.averageSalary = calculateAverageSalary(firm);
		return firm;
	}

	Employee* getEmployees(const Firm& firm, const double minSalary, size_t& employeesCount)
	{
		Employee employees[EMPLOYEES_COUNT];
		employeesCount = 0;
		for (size_t i = 0; i < firm.employeesCount; i++)
		{
			if (firm.employees[i].salary > minSalary
				|| abs(firm.employees[i].salary - minSalary) < EPSILON)
				employees[employeesCount++] = firm.employees[i];
		}

		Employee* fixedEmployees = new Employee[employeesCount];
		for (size_t i = 0; i < employeesCount; i++)
		{
			strcpy_s(fixedEmployees[i].name, strlen(employees[i].name) + 1, employees[i].name);
			fixedEmployees[i].position = employees[i].position;
			fixedEmployees[i].salary = employees[i].salary;
			fixedEmployees[i].grade = employees[i].grade;
		}
		return fixedEmployees;
	}

	void sortEmployeesByName(Employee* employees, const size_t employeesCount)
	{
		for (size_t i = 0; i < employeesCount; i++)
		{
			size_t minIndex = i;
			for (size_t j = i + 1; j < employeesCount; j++)
			{
				if (strcmp(employees[minIndex].name, employees[j].name) > 0)
					minIndex = j;
			}

			if (minIndex != i)
			{
				std::swap(employees[i], employees[minIndex]);
			}
		}
	}

	void printEmployees(const Firm& firm, const double minSalary)
	{
		size_t employeesCount;
		Employee* employees = getEmployees(firm, minSalary, employeesCount);
		sortEmployeesByName(employees, employeesCount);

		for (size_t i = 0; i < employeesCount; i++)
		{
			printEmployee(employees[i]);
		}
	}


    void printMinMaxGrades(const Firm& firm)
    {
		int minGrades[POSITIONS_COUNT] = { GRADE_MAX, GRADE_MAX, GRADE_MAX, GRADE_MAX };
		int maxGrades[POSITIONS_COUNT] = { GRADE_MIN, GRADE_MIN, GRADE_MIN, GRADE_MIN };

		for (size_t i = 0; i < firm.employeesCount; i++)
		{
			int positionIndex = (int)firm.employees[i].position - 1;
			if (minGrades[positionIndex] > firm.employees[i].grade)
				minGrades[positionIndex] = firm.employees[i].grade;
			if (maxGrades[positionIndex] < firm.employees[i].grade)
				maxGrades[positionIndex] = firm.employees[i].grade;
		}

		const char* positions[POSITIONS_COUNT] = {"Software Engineer",
			"Senior Software Engineer", 
			"Engineer Manager", 
			"Lead Software Engineer" };

		std::cout << "Min and Max Grades\n";
		for (size_t i = 0; i < POSITIONS_COUNT; i++)
		{
			std::cout << positions[i] << ":\n";
			std::cout << "\tMin Grade: " << minGrades[i] << "\n";
			std::cout << "\tMax Grade: " << maxGrades[i] << "\n\n";
		}
    }
}

int main()
{
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


	// Ex. 2
	/*ComplexNumber::Complex a{ 1, 2 };
	ComplexNumber::Complex b{ 3, 4 };

	ComplexNumber::Complex add = ComplexNumber::addition(a, b);
	ComplexNumber::Complex mul = ComplexNumber::muliply(a, b);

	ComplexNumber::printComplex(add);
	ComplexNumber::printComplex(mul);*/


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


	// Ex. 4
	/*std::cout << "Number of students in group: ";
	size_t n;
	std::cin >> n;
	std::cin.ignore();

	std::cout << "\nMajors:\n";
	std::cout << "\t1. Software Engineering\n";
	std::cout << "\t2. Information Systems\n";
	std::cout << "\t3. Computer Science\n";
	std::cout << "\t4. Applied Mathematics\n";
	std::cout << "\t5. Maths\n";
	std::cout << "\t6. Informatics\n";
	University::Group group = University::createGroup(n);

	std::cout << "\nAverage grade: " << group.averageGrade << "\n";

	float minGrade;
	std::cout << "\nMinimum grade: ";
	std::cin >> minGrade;
	std::cin.ignore();
	std::cout << "\nScholars count: ";
	std::cout << University::scholarsCount(group, minGrade) << "\n\n";

	size_t scholarsCount;
	std::cout << "Scholars: \n";
	University::Student* scholars = University::scholars(group, minGrade, scholarsCount);
	for (size_t i = 0; i < scholarsCount; i++)
	{
		std::cout << "\t" << scholars[i].name << " " << scholars[i].grade << "\n";
	}

	char facultyNumber[STR_SIZE + 1];
	std::cout << "\nSearch by Faculty number: ";
	std::cin.getline(facultyNumber, STR_SIZE);
	std::cout << (University::isStudentInGroup(group, facultyNumber)
		? "\tIn group" : "\tNOT in group") << "\n";*/


	// Ex. 5
	/*std::cout << "Point A\n";
	CoordinateSystem::Point a = CoordinateSystem::writePoint();
	std::cout << "\nPoint B\n";
	CoordinateSystem::Point b = CoordinateSystem::writePoint();
	std::cout << "\n";

	CoordinateSystem::printPoint(a);
	CoordinateSystem::printPoint(b);
	std::cout << "\nDistance to center(a): " << CoordinateSystem::distanceToCenter(a) << "\n";
	std::cout << "Distance to center(b): " << CoordinateSystem::distanceToCenter(b) << "\n\n";

	std::cout << "Distance between (a) and (b): "
		<< CoordinateSystem::distanceBetween(a, b) << "\n\n";

	std::cout << "(a) quadrant: " << (int)CoordinateSystem::getPointQuadrant(a) << "\n";
	std::cout << "(b) quadrant: " << (int)CoordinateSystem::getPointQuadrant(b) << "\n\n";

	double radius;
	std::cout << "Circle radius: ";
	std::cin >> radius;
	std::cout << "Is (a) in circle? ";
	short locationA = CoordinateSystem::isPointInCircle(a, radius);
	if (locationA < 0)
		std::cout << "Inside\n";
	else if (locationA > 0)
		std::cout << "Outside\n";
	else
		std::cout << "On contour\n";
	std::cout << "Is (b) in circle? ";
	short locationB = CoordinateSystem::isPointInCircle(b, radius);
	if (locationB < 0)
		std::cout << "Inside\n";
	else if (locationB > 0)
		std::cout << "Outside\n";
	else
		std::cout << "On contour\n";*/


	// Ex. 6
	/*size_t n;
	std::cin >> n;
	std::cin.ignore();

	ITFirm::Firm firm = ITFirm::createFirm(n);
	std::cout << "\nAverage salary: " << firm.averageSalary << "\n\n";

	double minSalary;
	std::cout << "Minimum salary: ";
	std::cin >> minSalary;
	std::cout << "\nEmployees with salary >= " << minSalary << "\n";
	ITFirm::printEmployees(firm, minSalary);
	std::cout << "\n";

	ITFirm::printMinMaxGrades(firm);*/
}

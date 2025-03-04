#include <iostream>
#include <fstream>
#include <sstream>

namespace Constants
{
	constexpr char SEPARATOR = ';';
	constexpr char WHITESPACE_SYMBOL = ' ';
	constexpr char NEWLINE_SYMBOL = '\n';
	constexpr char TERMINATE_ZERO = '\0';
	constexpr size_t MAX_FIELD_SIZE = 64;
	constexpr size_t MAX_ROW_LENGTH = 5;
	constexpr size_t MAX_ROWS = 300;
	constexpr size_t MAX_STRING_LENGTH = 1024;
}

namespace Structs
{
	using namespace Constants;

	typedef char Field[MAX_FIELD_SIZE + 1];

	struct Row
	{
		Field fields[MAX_ROW_LENGTH];
		size_t columns = 0;
	};

	struct CSV
	{
		Row rows[MAX_ROWS];
		size_t size = 0;
	};
}

namespace FieldsNS
{
	using namespace Structs;

	void parseField(const char* line, Row& toReturn)
	{
		if (!line) return;

		std::stringstream ss(line);

		while (!ss.eof())
		{
			if (toReturn.columns >= MAX_ROW_LENGTH) break;
			ss.getline(toReturn.fields[toReturn.columns++], MAX_FIELD_SIZE + 1, SEPARATOR);
		}
	}

	void saveField(std::ofstream& ofs, const Field& field, char separator)
	{
		ofs << field << separator;
	}

	void printField(const Field& field, char separator)
	{
		std::cout << field << separator;
	}
}

namespace RowsNS
{
	using namespace FieldsNS;

	Row parseRow(std::ifstream& ifs)
	{
		Row toReturn;

		char buffer[MAX_STRING_LENGTH + 1]{ '\0' };
		ifs.getline(buffer, MAX_STRING_LENGTH + 1, NEWLINE_SYMBOL);

		parseField(buffer, toReturn);

		return toReturn;
	}

	void saveRow(std::ofstream& ofs, const Row& row)
	{
		for (size_t i = 0; i < row.columns; i++)
		{
			saveField(ofs, row.fields[i], (i != row.columns - 1) ? SEPARATOR : NEWLINE_SYMBOL);
		}
	}

	void printRow(const Row& row)
	{
		for (size_t i = 0; i < row.columns; i++)
		{
			printField(row.fields[i], (i != row.columns - 1) ? WHITESPACE_SYMBOL : NEWLINE_SYMBOL);
		}
	}
}

namespace CSVParser
{
	using namespace RowsNS;

	CSV fromCSV(std::ifstream& ifs)
	{
		CSV toReturn;

		while (!ifs.eof())
		{
			if (toReturn.size >= MAX_ROWS) break;
			toReturn.rows[toReturn.size++] = parseRow(ifs);
		}

		return toReturn;
	}

	CSV fromCSV(const char* fileName)
	{
		if (!fileName) return {};

		std::ifstream ifs(fileName, std::ios::in);

		if (!ifs.is_open()) return {};

		return fromCSV(ifs);
	}

	void toCSV(std::ofstream& ofs, const CSV& csv)
	{
		for (size_t i = 0; i < csv.size; i++)
		{
			saveRow(ofs, csv.rows[i]);
		}
	}

	void toCSV(const char* fileName, const CSV& csv)
	{
		if (!fileName) return;

		std::ofstream ofs(fileName, std::ios::out);

		if (!ofs.is_open()) return;

		return toCSV(ofs, csv);
	}

	void printCSV(const CSV& csv)
	{
		for (size_t i = 0; i < csv.size; i++)
		{
			printRow(csv.rows[i]);
		}
	}
}

int main()
{
	using namespace CSVParser;

	CSV csv = fromCSV("students.csv");

	toCSV("students.csv", csv);

	printCSV(csv);

	return 0;
}

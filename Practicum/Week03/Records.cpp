#include <iostream>
#include <fstream>

namespace Constants
{
	constexpr size_t BLOCK_SIZE = 504;
}

size_t getFileSize(std::ifstream& ifs)
{
	size_t currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t size = ifs.tellg();
	ifs.seekg(currPos);

	return size;
}

struct Record {
	uint64_t next;
	char data[Constants::BLOCK_SIZE];
};

void printRecord(int index, const Record& record, std::ostream& os) {
	os << index << " " << "next: " << record.next << " " << record.data << std::endl;
}

void print(std::ostream& os, const char* fileName) {

	std::ifstream ifs(fileName, std::ios::in | std::ios::binary);

	if (!ifs.is_open()) return;

	int currentIndex = 0;

	while (true) {
		Record currentRecord;

		ifs.seekg(currentIndex * sizeof(Record), std::ios::beg);
		ifs.read((char*)&currentRecord, sizeof(Record));

		printRecord(currentIndex, currentRecord, os);

		if (currentRecord.next == 0) {
			break;
		}

		currentIndex = currentRecord.next;
	}

	ifs.close();
}

int main() {

	const char* file = "maintasks.db";
	print(std::cout, file);

	return 0;
}

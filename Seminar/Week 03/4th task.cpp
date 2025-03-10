#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <cstdint>
#include <cstring>

const int RECORD_SIZE = 512;
const int NEXT_OFFSET = 0;
const int USER_DATA_OFFSET = 8;
const int USER_DATA_SIZE = 504;

struct Record {
    uint64_t next;
    char user_data[USER_DATA_SIZE];
};

std::vector<Record> readRecords(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    std::vector<Record> records;
    Record record;

    while (file.read(reinterpret_cast<char*>(&record), sizeof(Record))) {
        records.push_back(record);
    }

    return records;
}

void writeRecords(const std::string& filename, const std::vector<Record>& records) {
    std::ofstream file(filename, std::ios::binary);

    for (const auto& record : records) {
        file.write(reinterpret_cast<const char*>(&record), sizeof(Record));
    }
}

std::unordered_set<size_t> findUsedRecords(const std::vector<Record>& records) {
    std::unordered_set<size_t> used;
    size_t index = 0;

    while (index != 0 && index < records.size()) {
        used.insert(index);
        index = records[index].next;
    }

    return used;
}

void censorUnusedRecords(std::vector<Record>& records, const std::unordered_set<size_t>& used) {
    for (size_t i = 0; i < records.size(); ++i) {
        if (used.find(i) == used.end()) {
            std::memset(records[i].user_data, 0, USER_DATA_SIZE);
        }
    }
}

int main() {
    std::string filename = "records.dat";
    std::vector<Record> records = readRecords(filename);
    std::unordered_set<size_t> used = findUsedRecords(records);
    censorUnusedRecords(records, used);
    writeRecords(filename, records);

    return 0;
}

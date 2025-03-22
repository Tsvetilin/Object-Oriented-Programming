#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstring>

struct Record {
    uint64_t next;
    char user_data[504];
};

void create_sample_file(const char* filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error creating file!" << std::endl;
        return;
    }

    Record records[4];

    // Record 0
    records[0].next = 1;
    std::strcpy(records[0].user_data, "Record 0 data");

    // Record 1
    records[1].next = 3;
    std::strcpy(records[1].user_data, "Record 1 data");

    // Record 2 (unused)
    records[2].next = 0;
    std::strcpy(records[2].user_data, "Unused Record 2 data");

    // Record 3
    records[3].next = 0;
    std::strcpy(records[3].user_data, "Record 3 data");

    for (int i = 0; i < 4; ++i) {
        file.write((char*)&records[i], sizeof(Record));
    }

    file.close();
}

int main() {
    create_sample_file("maintasks.dat");
    return 0;
}
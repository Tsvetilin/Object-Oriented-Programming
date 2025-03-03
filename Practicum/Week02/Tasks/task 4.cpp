#include <iostream>
#include <fstream>
#include <cstring>

namespace Constants {
    const size_t MAX_ROW_SIZE = 100;
    const size_t MAX_LINES_SIZE = 10;
    const size_t MAX_WORD_LENGTH = 50;
}

namespace TemplateNS {
    using namespace Constants;

    char** readTemplate(std::ifstream& ifs) {
        char** text = new char* [MAX_LINES_SIZE];
        for (size_t i = 0; i < MAX_LINES_SIZE; i++) {
            text[i] = new char[MAX_ROW_SIZE]();
        }

        size_t i = 0;
        while (i < MAX_LINES_SIZE && ifs.getline(text[i], MAX_ROW_SIZE)) {
            i++;
        }
        return text;
    }

    char** readTemplate(const char* templatename) {
        if (!templatename) return nullptr;
        std::ifstream ifs(templatename);
        if (!ifs.is_open()) return nullptr;
        return readTemplate(ifs);
    }

    int len(const char* c) {
        int counter = 0;
        while (*c) {
            c++;
            counter++;
        }
        return counter;
    }

    char* clearTemplateTxt(const char* templatetext) {
        char* extracted = new char[MAX_WORD_LENGTH];
        const char* ptr = templatetext;
        char* dest = extracted;
        bool insideBraces = false;

        while (*ptr) {
            if (*ptr == '{') {
                insideBraces = true;
                ptr++;
                continue;
            }
            if (*ptr == '}') {
                break;
            }
            if (insideBraces) {
                *dest = *ptr;
                dest++;
            }
            ptr++;
        }
        *dest = '\0'; 
        return extracted;
    }

    bool compare(const char* a, const char* b) {
        while (*a)
        {
            if (*a++ != *b++) return false;
        }
        return true;
    }

    void putWordInSentence(char* sentence, const char* word) {
        int newSize = strlen(sentence) + strlen(word) + 2;
        char* newSentence = new char[newSize];

        char* ptr = newSentence;
        const char* src = sentence;

        while (*src && *src != '{') {
            *ptr++ = *src++;
        }

        while (*word) {
            *ptr++ = *word++;
        }

        while (*src && *src != '}') {
            src++;
        }
        if (*src == '}') src++;

        while (*src) {
            *ptr++ = *src++;
        }
        *ptr = '\0';

        strcpy_s(sentence, newSize, newSentence);

        delete[] newSentence;
    }


    void putAccordingTxt(const char* key, std::ifstream& ifs, char* sentence) {
        char* buffer=new char [MAX_ROW_SIZE];

        ifs.clear();
        ifs.seekg(0, std::ios::beg);

        while (ifs.getline(buffer, MAX_ROW_SIZE)) {
            if (compare(key, buffer)) {
                putWordInSentence(sentence, buffer+ (int)len(key)+1);
                break;
            }
        }
        delete[] buffer;
    }

    void fillInTemplate(char** templateText, std::ifstream& ifs) {
        std::ofstream ofs("template_filled.txt");
        if (!ofs.is_open()) return;

        for (size_t i = 0; i < MAX_LINES_SIZE; i++) {
            for (size_t j = 0; j < MAX_ROW_SIZE; j++)
            {
                if (templateText[i][j] == '{') {
                    char* key = clearTemplateTxt(templateText[i]);
                    putAccordingTxt(key, ifs, templateText[i]);
                    delete[] key;
                }
            }
            ofs << templateText[i] << std::endl;
        }

        ofs.close();
    }

    void fillInTemplate(char** templateText, const char* filename) {
        if (!filename) return;
        std::ifstream ifs(filename);
        if (!ifs.is_open()) return;
        fillInTemplate(templateText, ifs);
    }

    void printTemplate(char** templateText) {
        for (size_t i = 0; i < MAX_LINES_SIZE; i++) {
            if (templateText[i][0] != '\0') 
            {  
                std::cout << templateText[i] << std::endl;
            }
        }
    }

    void freeTemplate(char** templateText) {
        for (size_t i = 0; i < MAX_LINES_SIZE; i++) {
            delete[] templateText[i];
        }
        delete[] templateText;
    }
}

int main() {
    using namespace TemplateNS;

    char** templateText = readTemplate("template.txt");
    fillInTemplate(templateText, "data.txt");
    printTemplate(templateText);
    //freeTemplate(templateText);

    return 0;
}

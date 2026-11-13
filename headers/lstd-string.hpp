#include "lstd-def.hpp"
#include <string.h>
#include <cstdio>

//#define LSTD_IMPLEMENT_STRING

namespace lstd {
    class string {
        private:
        char* data;
        size_t size;

        public:
        string()  {
            size = 1;
            data = new char[size];
            *data = 0;
        }
        string(const char* s) {
            size = strlen(s) + 1;
            data = new char[size];
            strcpy(data, s);
        }
        string(const string& s) {
            size = s.size;
            data = new char[size];
            strcpy(data, s.data);
        }
        ~string() {
            delete[] data;
        }

        void append(const string& s);
        void append(const char* s);
        void append(const char& c);
        void print() {
            printf("%s", data);
        }
    };
}

#ifdef LSTD_IMPLEMENT_STRING
#undef LSTD_IMPLEMENT_STRING

void lstd::string::append(const char* s) {
    size += strlen(s);
    char* n_data = new char[size];
    strcpy(n_data, data);
    delete[] data;
    strcat(n_data, s);
    data = n_data;
}
void lstd::string::append(const lstd::string& s) {
    size += s.size - 1;
    char* n_data = new char[size];
    strcpy(n_data, data);
    delete[] data;
    strcat(n_data, s.data);
    data = n_data;
}
void lstd::string::append(const char& c) {
    size += 1;
    char* n_data = new char[size];
    strcpy(n_data, data);
    delete[] data;
    n_data[size - 2] = c;
    n_data[size - 1] = 0;
    data = n_data;
}

//

#endif

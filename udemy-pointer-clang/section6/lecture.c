# include <stdio.h>
# include <string.h>


typedef struct human {
    short age;
    short weight;
    short height;
} HUMAN;

HUMAN student[2];

int main() {
    HUMAN human;
    char* ptr = (char*)&human;
    ptr++;
}

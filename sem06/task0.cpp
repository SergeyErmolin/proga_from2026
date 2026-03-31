#include<iostream>
#include <string>

struct Student
{
    std::string name;
    int mark;
};

int main()
{
    Student* spisok = new Student[1];
    spisok->name = "Mark";
    spisok->mark = 10;
    spisok[0] = {"eqr", 2};

    std::cout << spisok->name << ' ' << spisok[0].mark;
    delete[] spisok;
    return 0;
}
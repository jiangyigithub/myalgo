#include <string>

class person
{
    std::string name;
    int age;

public:

    person(const std::string& name, int age) : name(name), age(age)
    {
    }
};

int main()
{
    person a("Bjarne Stroustrup", 60);
    person b(a);   // What happens here?
    b = a;         // And here?
}
// https://stackoverflow.com/questions/4172722/what-is-the-rule-of-three
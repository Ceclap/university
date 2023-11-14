#include <iostream>
#include <string>

class Student {
protected:
    std::string nume;
    int varsta;

public:
    Student(std::string nume, int varsta) : nume(nume), varsta(varsta) {}

    void afiseazaInformatii() {
        std::cout << "Nume: " << nume << ", Varsta: " << varsta << std::endl;
    }
};

class StudentBursier : public Student {
private:
    float sumaBursa;

public:
    StudentBursier(std::string nume, int varsta, float sumaBursa) : Student(nume, varsta), sumaBursa(sumaBursa) {}

    void afiseazaInformatiiBursier() {
        afiseazaInformatii();
        std::cout << "Suma Bursa: " << sumaBursa << std::endl;
    }
};

int main() {
    // Exemplu de utilizare
    Student student1("Ana", 20);
    StudentBursier student2("Mihai", 22, 1500);

    student1.afiseazaInformatii();
    std::cout << std::endl;
    student2.afiseazaInformatiiBursier();

    return 0;
}

#include <string>
#include <optional>
#include <iostream>
using namespace std;

class Aluno {
public:
    double note1;
    double note2;
    double moyenne;

    Aluno() : name("Inconnu"), note1(0), note2(0), moyenne(0) {}
    Aluno(string _name, double _note1, double _note2) 
        : name(_name), note1(_note1), note2(_note2) { 
        Moyenne(); 
    }

    void printInfo() const {
        cout << "Name: " << name << endl;
        cout << "Note 1: " << note1 << endl;
        cout << "Note 2: " << note2 << endl;
        cout << "Moyenne: " << moyenne << endl;
        cout << "---------------------------" << endl;
    }

    double Moyenne() {
        return moyenne = (note1 + note2) / 2.0;
    }

    void ModifInfo(string _name, double _note1, double _note2) {
        name = _name;
        note1 = _note1;
        note2 = _note2;
        Moyenne();
    }

    string getName() { return name; }

private:
    string name;
};

class Valunos {
public:
    // Le tableau contient maintenant des optionnels
    optional<Aluno> valunos[20];

    Valunos(const Aluno _valunos[20]) {
        for (int i = 0; i < 20; i++) {
            valunos[i] = _valunos[i];
        }
    }

    void printMoyClass() const {
        double totalMoy = 0;
        int count = 0;

        for (int i = 0; i < 20; i++) {
            if (valunos[i].has_value()) {
                totalMoy += valunos[i]->moyenne;
                count++;
            }
        }

        if (count > 0) {
            cout << "Average of the class: " << totalMoy / count << endl;
        } else {
            cout << "No students in class." << endl;
        }
    }

    void suppAluno(const string& nameADel) {
        for (int i = 0; i < 20; i++) {
            if (valunos[i].has_value() && valunos[i]->getName() == nameADel) {
                valunos[i] = nullopt; // Désormais valide
                cout << nameADel << " a ete supprime." << endl;
            }
        }
    }
};

int main() {
    Aluno classInformatique[20];

    for (int i = 0; i < 20; i++) {
        classInformatique[i] = Aluno("Student_" + to_string(i), 10, 10);
    }
    
    Valunos ClassInformatique(classInformatique);
    ClassInformatique.suppAluno("Student_5");
    ClassInformatique.printMoyClass();

    return 0;
}
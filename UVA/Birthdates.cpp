#include<bits/stdc++.h>

//Juan ANgel Lopez Delgadillo
//Uva 12541 Birthdates


using namespace std;

// Definición de la estructura Person que representa a una persona
struct Person {
    string name; // Nombre de la persona
    int day, month, year;  // Día, mes y año de nacimiento de la persona

//Aqui lo que hacemos es hacer una sobrecarga del operador < para poder ordenar las personas según su edad
    bool operator<(const Person& other) const {
        if (year != other.year) {
            return year > other.year;
        } else if (month != other.month) {
            return month > other.month;
        } else {
            return day > other.day;
        }
    }
};

int main() {
    int n;
    cin >> n;

     // Crea un vector de personas con tamaño n
    vector<Person> people(n);
    for (int i = 0; i < n; i++) {
        // Lee los datos de cada persona y los almacena en el vector
        cin >> people[i].name >> people[i].day >> people[i].month >> people[i].year;
    }

            // Ordena el vector de personas utilizando el operador '<' definido anteriormente
    sort(people.begin(), people.end());

    cout << people[0].name << endl;
    cout << people[n - 1].name << endl;

    return 0;
}

#include <iostream>
#include <random>

int main() {
    // Initialise le générateur de nombres aléatoires avec une graine basée sur l'horloge système
    std::random_device rd;
    std::mt19937 gen(rd());

    // Définit la plage des nombres aléatoires (0-100)
    std::uniform_int_distribution<> dis(0, 100);

    // Génère et affiche un nombre aléatoire
    int randomNumber = dis(gen);
    std::cout << "Nombre aleatoire: " << randomNumber << std::endl;

    return 0;
}

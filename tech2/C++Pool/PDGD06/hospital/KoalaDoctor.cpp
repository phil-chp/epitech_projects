/*
** EPITECH PROJECT, 2022
** PDG-D6 (Workspace)
** File description:
** KoalaDoctor
*/

#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(const std::string name)
{
    KoalaDoctor::_name = name;
    std::cout
        << "Dr."
        << _name
        << ": I'm Dr."
        << _name
        << "! How do you kreog?"
        << std::endl;
}

KoalaDoctor::~KoalaDoctor(void)
{
}

void KoalaDoctor::diagnose(SickKoala *patient)
{
    std::string patient_name(patient->getName());
    std::string foods[] = \
        { "Mars", "Kinder", "Crunch", "Maroilles", "Eucalyptus leaf" };
    int r = random() % 5;
    std::fstream fs;

    std::cout
        << "Dr." << _name
        << ": So what's goerking you Mr." << patient_name << "?"
        << std::endl;
    patient->poke();
    fs.open(patient_name + ".report", std::ios::out);
    if (fs.is_open()) fs << foods[r];
    fs.close();
}

void KoalaDoctor::timeCheck(void)
{
    std::string status;

    _working = !_working;
    status = (_working
        ? ": Time to get to work!"
        : ": Time to go home to my eucalyptus forest!");
    std::cout << "Dr. " << _name << status << std::endl;
}

std::string KoalaDoctor::getName(void)
{
    return (_name);
}

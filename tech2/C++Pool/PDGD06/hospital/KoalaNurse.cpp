/*
** EPITECH PROJECT, 2022
** PDG-D6 (Workspace)
** File description:
** KoalaNurse
*/

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(const int id)
{
    KoalaNurse::_id = id;
    KoalaNurse::_working = false;
}

KoalaNurse::~KoalaNurse(void)
{
    std::cout << "Nurse " << _id << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
    patient->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string filename)
{
    std::string drug;
    std::fstream file;
    std::regex pattern("(.*).report$");
    std::smatch match;

    if (std::regex_match(filename, match, pattern)) {
        file.open(filename, std::ios::in);
        if (file.is_open()) std::getline(file, drug);
        file.close();
    }
    if (drug.length() > 0) {
        std::cout
            << "Nurse " << _id
            << ": Kreog! Mr." << match[1] << " needs a " << drug << "!"
            << std::endl;
        return (drug);
    }
    return ("");
}

void KoalaNurse::timeCheck(void)
{
    std::string status;

    _working = !_working;
    status = (_working
        ? ": Time to get to work!"
        : ": Time to go home to my eucalyptus forest!");
    std::cout << "Nurse " << _id << status << std::endl;
}

int getID(void)
{
    return (_id);
}

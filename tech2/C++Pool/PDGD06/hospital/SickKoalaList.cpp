/*
** EPITECH PROJECT, 2022
** PDG-D6 (Workspace)
** File description:
** SickKoalaList
*/

#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(const SickKoala *patient)
{
    if (!patient) return;
    SickKoalaList::_patients.push_front(*patient);
}

SickKoalaList::~SickKoalaList(void)
{
}

bool SickKoalaList::isEnd(void)
{
    return (SickKoalaList::_patients.empty());
}

void SickKoalaList::append(SickKoalaList *list)
{
    if (!list) return;
    std::list<SickKoala>::iterator it(list->_patients.begin());

    for (; it != list->_patients.end(); it++) {
        SickKoalaList::_patients.push_back(*it);
    }
}

SickKoala *SickKoalaList::getFromName(const std::string name)
{
    std::list<SickKoala>::iterator it(SickKoalaList::_patients.begin());

    for (; it != SickKoalaList::_patients.end(); it++) {
        if (it->getName() == name) return (&(*it));
    }
    return (nullptr);
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *list)
{
    if (!list) return (nullptr);
    std::list<SickKoala>::iterator it(SickKoalaList::_patients.begin());

    for (; it != SickKoalaList::_patients.end(); it++) {
        if (&(*it) == list) {
            SickKoalaList::_patients.erase(it);
            return (this);
        }
    }
    return (nullptr);
}

SickKoalaList *SickKoalaList::removeFromName(const std::string name)
{
    std::list<SickKoala>::iterator it(SickKoalaList::_patients.begin());

    for (; it != SickKoalaList::_patients.end(); it++) {
        if (it->getName() == name) {
            SickKoalaList::_patients.erase(it);
            return (this);
        }
    }
    return (nullptr);
}

SickKoala *SickKoalaList::getContent(void)
{
    return (&SickKoalaList::_patients.front());
}

// has a getNext member function which takes no parameter and returns a pointer
// to the next node of the list.
// If there is no next node, the function returns a nullptr
SickKoalaList *SickKoalaList::getNext(void)
{
    std::list<SickKoala>::iterator it(SickKoalaList::_patients.begin());

    for (; it != SickKoalaList::_patients.end(); it++) {
        if (it != SickKoalaList::_patients.end()) {
            it++;
            return (&(*it));
        }
    }
    return (nullptr);
}

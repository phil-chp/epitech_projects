/*
** EPITECH PROJECT, 2022
** PDG-D10-AM (Workspace)
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

// ------------------------------ Subroutines ------------------------------- //

FruitBox::FruitBox(int size) : _size(size), _head(nullptr)
{
}

FruitBox::~FruitBox()
{
}

// -------------------------------- Methods --------------------------------- //

int FruitBox::nbFruits()
{
    FruitNode *temp = _head;
    size_t fruitCount = 0;

    for (; temp != nullptr; temp = temp->next, fruitCount++);
    return fruitCount;
}


bool FruitBox::putFruit(Fruit *f)
{
    FruitNode *newFruit;

    if (_size == 0) return (false);
    newFruit = new FruitNode;
    newFruit->fruit = f;
    newFruit->next = nullptr;

    if (_head == nullptr) {
        _head = newFruit;
    } else {
        FruitNode *temp = _head;
        for (; temp->next != nullptr; temp = temp->next) {
            if (temp->fruit == f) return (false);
        }
        if (temp->fruit == f) return (false);
        temp->next = newFruit;
    }
    _size--;
    return (true);
}

Fruit *FruitBox::pickFruit()
{
    FruitNode *temp = _head;
    Fruit *pickedFruit;

    if (_head == nullptr) return (nullptr);
    _head = (_head->next != nullptr ? _head->next : nullptr);
    pickedFruit = temp->fruit;
    delete temp;
    _size++;
    return pickedFruit;
}

FruitNode *FruitBox::head()
{
    return _head;
}

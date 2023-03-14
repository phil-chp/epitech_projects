/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Cursor
*/

#include "Lib/Raylib/rl-cpp/Windows/Cursor/Cursor.hpp"

bool rl::Cursor::isAccessible() const
{
    return (!this->_isHidden && this->_isActive && this->isOnScreen());
}

void rl::Cursor::show()
{
    this->_isHidden = false;
    ::ShowCursor();
}

void rl::Cursor::hide()
{
    this->_isHidden = true;
    ::HideCursor();
}

bool rl::Cursor::isHidden() const
{
    return (this->_isHidden);
}

void rl::Cursor::enable()
{
    this->_isActive = true;
    ::EnableCursor();
}

void rl::Cursor::disable()
{
    this->_isActive = false;
    ::DisableCursor();
}

bool rl::Cursor::isActive() const
{
    return (this->_isActive);
}

bool rl::Cursor::isOnScreen() const
{
    return (::IsCursorOnScreen());
}

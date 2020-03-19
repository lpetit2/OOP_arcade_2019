/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MyWindow
*/

#include "MyWindow.hpp"

void initObject()
{
    initscr();
    start_color();
    keypad(stdscr, TRUE);
    refresh();
    curs_set(0);
}

MyWindow::MyWindow(int lines, int colones, int x , int y)
{
    noecho();
    initObject();
    window = newwin(lines, colones, x, y);
}

MyWindow::~MyWindow()
{
    endwin();
}

void MyWindow::clear()
{
    delwin(this->window);
    erase();
}

int MyWindow::MyGetch()
{
    int key;

    timeout(5);
    key = getch();
    return key;
}
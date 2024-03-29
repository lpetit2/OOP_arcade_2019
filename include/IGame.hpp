/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGame
*/

#pragma once
#include <string>
#include <vector>

class IGame {
    public:
        virtual ~IGame() {}
        virtual std::string getName() const = 0;
        virtual std::vector<std::string> getScore() const = 0;
        virtual void InitMap() = 0;
        virtual std::vector<std::string> getMap() = 0;
        virtual int ReceiveEvent(int, int) = 0;
        virtual void saveGame(std::string) = 0;
        virtual bool Loose() = 0;
};
/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** nibbler.hpp
*/

#pragma once
#include "../../../include/IGame.hpp"
#include <vector>
#include <stdlib.h>
#include <time.h>

class nibbler : public IGame
{
    private:
      std::vector<std::string> _map;
      std::vector<std::string> _score;
      std::vector<std::pair<int,int>> _snake;
      int SaveLastKey;
      int _food;
      int _init;
      int press;
      bool loose = false;

      void initSnake();
      void deadSnake();
      void countFood();
       // std::vector<std::pair<int,int>> _NibblerBody;
       // int ymax;
       // int xmax;
    public:
        nibbler();
        void InitMap() final;
        bool Loose() final;
     //   int GetNibblerSize();
   //     std::vector<std::pair<int,int>> GetNibblerBody();
        std::string getName() const final;
        std::vector<std::string> getMap() final;
        int ReceiveEvent(int, int) final;
        void saveGame(std::string) final;
        std::vector<std::string> getScore() const final;
        void MovePlayer(int);
        void KeepMoving(int SaveLastKey);
        void MoveSnakeBody();
        void addFood();
        int GetY();
        int GetX();
};
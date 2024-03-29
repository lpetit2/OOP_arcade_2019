/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib_ncurses
*/

#include "lib_sfml.hpp"
#include <string.h>

std::string LibSfml::gameOver()
{
    this->window.clear();
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Sprite logo;
    sf::Texture T_logo;
    sf::Text Game1;
    sf::Text Game2;
    sf::Font font;
    int i = 0;

    if (!font.loadFromFile("./asset/Test-Font.ttf"))
        throw(Error("Can't find the Font file"));
    if (!texture.loadFromFile("./asset/arcade-backgrounds.jpg", sf::IntRect(0,0,1920, 1080)))
        throw(Error("Can't find the Asset file"));
    if (!T_logo.loadFromFile("./asset/test-logo.png", sf::IntRect(0, 0, 600, 400)))
        throw(Error("Can't find the Asset file"));
    sprite.setTexture(texture);
    logo.setTexture(T_logo);
    logo.setPosition(sf::Vector2f(660,0));

    Game1.setString("Restart");
    Game1.setFillColor(sf::Color::Green);
    Game1.setPosition(sf::Vector2f(200, 400));
    Game1.setFont(font);
    Game1.setCharacterSize(150);
    Game1.setStyle(sf::Text::Bold);

    Game2.setString("Menu");
    Game2.setFillColor(sf::Color::Green);
    Game2.setPosition(sf::Vector2f(1200, 400));
    Game2.setFont(font);
    Game2.setCharacterSize(150);
    Game2.setStyle(sf::Text::Bold);

    sf::Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    this->window.clear();
                    return "kill";
                }
                if (event.key.code == sf::Keyboard::Right)
                {
                    Game2.setFillColor(sf::Color::Blue);
                    Game1.setFillColor(sf::Color::Green);
                    i = 0;
                }
                if (event.key.code == sf::Keyboard::Left)
                {
                    Game1.setFillColor(sf::Color::Blue);
                    Game2.setFillColor(sf::Color::Green);
                    i = 1;
                }
                if (event.key.code == sf::Keyboard::Enter && i == 0)
                {
                    this->window.clear();
                    return "Menu";
                }
                else if ( event.key.code == sf::Keyboard::Enter && i == 1)
                {
                    this->window.clear();
                    return "Restart";
                }
            }
        }
        this->window.clear();
        this->window.draw(sprite);
        this->window.draw(logo);
        this->window.draw(Game1);
        this->window.draw(Game2);
        this->window.display();
    }
    return "success";
}

void LibSfml::initWindow()
{
    if (!this->Background.loadFromFile("./asset/arcade-backgrounds.jpg", sf::IntRect(0,0,1920, 1080)))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Background);
        ListSprite["Background"] = sprite;
        this->window.draw(ListSprite["Background"]);
    }
    if (!this->Wall_N.loadFromFile("./asset/assets-game/bric.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Wall_N);
        this->Wall_N.setSmooth(true);
        sprite.setScale(0.20, 0.20);
        ListSprite["WallNibbler"] = sprite;
    }
    if (!this->Nibbler_Head.loadFromFile("./asset/assets-game/head.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Nibbler_Head);
        this->Nibbler_Head.setSmooth(true);
        sprite.setScale(0.14, 0.14);
        ListSprite["Nibbler_Head"] = sprite;
    }
    if (!this->Nibbler_Tail.loadFromFile("./asset/assets-game/tail.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Nibbler_Tail);
        this->Nibbler_Tail.setSmooth(true);
        sprite.setScale(0.13, 0.13);
        ListSprite["Nibbler_Tail"] = sprite;
    }
    if (!this->Apple.loadFromFile("./asset/assets-game/apple.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Apple);
        this->Apple.setSmooth(true);
        sprite.setScale(0.08, 0.08);
        ListSprite["Apple"] = sprite;
    }
    if (!this->Wall_P.loadFromFile("./asset/assets-game/Block.png")) {
        throw(Error("Can't find the Asset file"));
    }
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Wall_P);
        this->Wall_P.setSmooth(true);
        sprite.setScale(0.20, 0.20);
        ListSprite["WallPacman"] = sprite;
    }
    if (!this->Ghost1.loadFromFile("./asset/assets-game/Bleu.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Ghost1);
        this->Ghost1.setSmooth(true);
        sprite.setScale(0.12, 0.12);
        ListSprite["Ghost1"] = sprite;
    }
    if (!this->Ghost2.loadFromFile("./asset/assets-game/Jaune.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Ghost2);
        this->Ghost2.setSmooth(true);
        sprite.setScale(0.12, 0.12);
        ListSprite["Ghost2"] = sprite;
    }
    if (!this->Ghost3.loadFromFile("./asset/assets-game/Rose.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Ghost3);
        this->Ghost3.setSmooth(true);
        sprite.setScale(0.12, 0.12);
        ListSprite["Ghost3"] = sprite;
    }
    if (!this->Ghost4.loadFromFile("./asset/assets-game/Rouge.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Ghost4);
        this->Ghost4.setSmooth(true);
        sprite.setScale(0.12, 0.12);
        ListSprite["Ghost4"] = sprite;
    }
    if (!this->Candy.loadFromFile("./asset/assets-game/Pastille.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Candy);
        this->Candy.setSmooth(true);
        sprite.setScale(0.08, 0.08);
        ListSprite["Candy"] = sprite;
    }
    if (!this->Pacman_Right.loadFromFile("./asset/assets-game/pac-man4.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Pacman_Right);
        this->Pacman_Right.setSmooth(true);
        sprite.setScale(0.14, 0.14);
        ListSprite["Pacman_Right"] = sprite;
    }
    if (!this->Pacman_Right_Open.loadFromFile("./asset/assets-game/open_right.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Pacman_Right_Open);
        this->Pacman_Right_Open.setSmooth(true);
        sprite.setScale(0.15, 0.15);
        ListSprite["Pacman_Right_Open"] = sprite;
    }
    if (!this->Pacman_Up.loadFromFile("./asset/assets-game/pac-man3.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Pacman_Up);
        this->Pacman_Right.setSmooth(true);
        sprite.setScale(0.12, 0.12);
        ListSprite["Pacman_Up"] = sprite;
    }
    if (!this->Pacman_Up_Open.loadFromFile("./asset/assets-game/open_up.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Pacman_Up_Open);
        this->Pacman_Up_Open.setSmooth(true);
        sprite.setScale(0.13, 0.13);
        ListSprite["Pacman_Up_Open"] = sprite;
    }
    if (!this->Pacman_Left.loadFromFile("./asset/assets-game/pac-man2.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Pacman_Left);
        this->Pacman_Left.setSmooth(true);
        sprite.setScale(0.12, 0.12);
        ListSprite["Pacman_Left"] = sprite;
    }
    if (!this->Pacman_Left_Open.loadFromFile("./asset/assets-game/open_left.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Pacman_Left_Open);
        this->Pacman_Left_Open.setSmooth(true);
        sprite.setScale(0.13, 0.13);
        ListSprite["Pacman_Left_Open"] = sprite;
    }
    if (!this->Pacman_Down.loadFromFile("./asset/assets-game/pac-man1.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Pacman_Down);
        this->Pacman_Down.setSmooth(true);
        sprite.setScale(0.12, 0.12);
        ListSprite["Pacman_Down"] = sprite;
    }
    if (!this->Pacman_Down_Open.loadFromFile("./asset/assets-game/open_down.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Pacman_Down_Open);
        this->Pacman_Down_Open.setSmooth(true);
        sprite.setScale(0.13, 0.13);
        ListSprite["Pacman_Down_Open"] = sprite;
    }
    if (!this->MagicCandy.loadFromFile("./asset/assets-game/shroom.png"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->MagicCandy);
        this->MagicCandy.setSmooth(true);
        sprite.setScale(0.12, 0.12);
        ListSprite["Magic_Candy"] = sprite;
    if (!this->GhostEat.loadFromFile("./asset/assets-game/Run.bmp"))
        throw(Error("Can't find the Asset file"));
    else
    {
        sf::Sprite sprite;
        sprite.setTexture(this->GhostEat);
        this->GhostEat.setSmooth(true);
        sprite.setScale(0.09, 0.09);
        ListSprite["Ghost_Eat"] = sprite;
    }
    }
}

LibSfml::LibSfml() : window(sf::VideoMode(VideoMode.width, VideoMode.height, VideoMode.bitsPerPixel), "Arcade", sf::Style::Fullscreen)
{

}

sf::Text InitText(std::vector<std::pair<int,std::string>> Vector, int i, sf::Font font, sf::Vector2f vector2f)
{
    sf::Text tmp;

    tmp.setString(Vector[i].second);
    tmp.setFillColor(sf::Color::Green);
    tmp.setPosition(vector2f);
    tmp.setFont(font);
    tmp.setCharacterSize(150);
    tmp.setStyle(sf::Text::Bold);
    return tmp;
}

void LibSfml::SetSpritePos(std::string Name, int LenLine, int pos1, int pos2)
{
    if (Name == "Candy" || Name == "Magic_Candy")
        this->ListSprite[Name].setPosition(this->window.getSize().x / 2 - (LenLine * 9.8) + pos2 * 25, this->window.getSize().y / 7.5 + pos1 * 25);
    else
        this->ListSprite[Name].setPosition(this->window.getSize().x / 2 - (LenLine * 10) + pos2 * 25, this->window.getSize().y / 8 + pos1 * 25);
    this->window.draw(this->ListSprite[Name]);
}


void LibSfml::DrawMap(std::vector<std::string> map)
{
    int pos1 = 0;
    int pos2 = 0;
    int lenLine = map[0].length();

    for (std::string str : map) {
        pos2 = 0;
        for (char c : str) {
            switch (c)
            {
                case 'F':
                    SetSpritePos("Magic_Candy", lenLine, pos1, pos2);
                    break;
                case 'W':
                    SetSpritePos("WallNibbler", lenLine, pos1, pos2);
                    break;
                case 'x':
                    SetSpritePos("Apple", lenLine, pos1,pos2);
                    break;
                case 'o':
                    SetSpritePos("Nibbler_Tail", lenLine, pos1, pos2);
                    break;
                case '0':
                    SetSpritePos("Nibbler_Head", lenLine, pos1, pos2);
                    break;
                case 'M':
                    SetSpritePos("WallPacman", lenLine, pos1, pos2);
                    break;
                case '.':
                    SetSpritePos("Candy", lenLine, pos1, pos2);
                    break;
                case 'I':
                    SetSpritePos("Candy", lenLine, pos1, pos2);
                    break;
                case 'D':
                    if (this->check % 2 == 0)
                        SetSpritePos("Pacman_Down", lenLine, pos1, pos2);
                    else
                        SetSpritePos("Pacman_Down_Open", lenLine, pos1, pos2);
                    this->check++;
                     if (check == 11)
                         check = 1;
                    break;
                case 'C':
                    if (this->check % 2 == 0)
                        SetSpritePos("Pacman_Right", lenLine, pos1, pos2);
                    else
                        SetSpritePos("Pacman_Right_Open", lenLine, pos1, pos2);
                    this->check++;
                     if (check == 11)
                         check = 1;
                    break;
                case 'B':
                    if (this->check % 2 == 0)
                        SetSpritePos("Pacman_Up", lenLine, pos1, pos2);
                    else
                        SetSpritePos("Pacman_Up_Open", lenLine, pos1, pos2);
                    this->check++;
                     if (check == 11)
                         check = 1;
                    break;
                case 'A':
                    if (this->check % 2 == 0)
                        SetSpritePos("Pacman_Left", lenLine, pos1, pos2);
                    else
                        SetSpritePos("Pacman_Left_Open", lenLine, pos1, pos2);
                    this->check++;
                     if (check == 11)
                         check = 1;
                    break;
                case 'G':
                    SetSpritePos("Ghost1", lenLine, pos1, pos2);
                    break;
                case 'T':
                    SetSpritePos("Ghost2", lenLine, pos1, pos2);
                    break;
                case 'H':
                    SetSpritePos("Ghost3", lenLine, pos1, pos2);
                    break;
                case 'U':
                    SetSpritePos("Ghost4", lenLine, pos1, pos2);
                    break;
                case 'i':
                    SetSpritePos("Magic_Candy", lenLine, pos1, pos2);
                    break;
                case 'h':
                    SetSpritePos("Magic_Candy", lenLine, pos1, pos2);
                    break;
                case 't':
                    SetSpritePos("Magic_Candy", lenLine, pos1, pos2);
                    break;
                case 'u':
                    SetSpritePos("Magic_Candy", lenLine, pos1, pos2);
                    break;

            }
            pos2++;
        }
        pos1++;
    }
}

void LibSfml::DrawScore(std::vector<std::string> score)
{
    sf::Text Score;
    sf::Text Name;
    sf::Text HighScore;
    //sf::Text UserName;
    sf::Font font;

    if (this->_map[0].front() == 'W')
        Name.setString("Nibbler");
    else
        Name.setString("Pacman");
    if (!font.loadFromFile("./asset/Test-Font.ttf"))
        throw(Error("Can't find the Font file"));
    Score.setString("score: " + score[0]);
    HighScore.setString("HighScore: " + score[1]);
    //UserName.setString("Name: " + score[2]);
    Score.setFillColor(sf::Color::Yellow);
    HighScore.setFillColor(sf::Color::Red);
    //UserName.setFillColor(sf::Color::Blue);
    Name.setFillColor(sf::Color::Green);
    Name.setFont(font);
    Score.setFont(font);
    //UserName.setFont(font);
    HighScore.setFont(font);
    Name.setCharacterSize(150);
    Score.setCharacterSize(40);
    HighScore.setCharacterSize(40);
    //UserName.setCharacterSize(40);
    Name.setStyle(sf::Text::Bold);
    Score.setStyle(sf::Text::Bold);
    HighScore.setStyle(sf::Text::Bold);
    //UserName.setStyle(sf::Text::Bold);
    Name.setPosition(sf::Vector2f(780, -20));
    Score.setPosition(sf::Vector2f(30, 200));
    HighScore.setPosition(sf::Vector2f(30, 300));
    //UserName.setPosition(sf::Vector2f(30, 100));

    this->window.draw(Name);
    this->window.draw(Score);
    this->window.draw(HighScore);
    //this->window.draw(UserName);
}

void LibSfml::InitProg(std::vector<std::string> map, std::vector<std::string> score)
{
    this->window.clear();
    this->_map = map;
    this->_score = score;
    if (this->window.isOpen()) {
        DrawMap(map);
        DrawScore(score);
        usleep(100600);
        this->window.display();
    }
}

int LibSfml::getEvent()
{
    return this->bind();
}

std::string LibSfml::Game()
{
    return "toto";
}

void LibSfml::closeWindow()
{
    window.close();
}

int LibSfml::Pause()
{
    this->window.clear();
    sf::Texture PauseTexture;
    sf::Sprite SpritePause;

    if (!PauseTexture.loadFromFile("./asset/assets-game/pause.png"))
        throw(Error("Fail to open assset File"));
    SpritePause.setTexture(PauseTexture);
    SpritePause.setPosition(sf::Vector2f(700,250));

    this->window.draw(SpritePause);
    this->window.display();
    if (this->window.isOpen())
    {
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                    return 1;
                if (event.key.code == sf::Keyboard::Escape)
                    return LEAVE;
                if (event.key.code == sf::Keyboard::M)
                    return MENU;
            }
        }
    }
    return 0;
}

void LibSfml::setName(std::string name)
{
    name = "toto";
    return;
}


//// For the dlsym Symbol /////
extern "C" LibSfml *createDisplay()
{
    return new LibSfml;
}
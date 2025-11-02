#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"

class Ball {

public:
Ball(int x, int y);
void update(float dt, Player& p);
sf::RectangleShape getShape();

bool m_Pong = false;

private:
sf::RectangleShape m_Shape;
sf::Vector2f m_Pos;
sf::Vector2f m_Speed = sf::Vector2f(300, 300);
float m_FlipTimer = 0;

};

#endif
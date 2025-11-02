#include "Ball.h"
#include <SFML/Audio.hpp>
#include <iostream>


Ball::Ball(int x, int y):m_Pos(x, y)
{
    m_Shape.setSize(sf::Vector2f(5, 5));
    m_Shape.setOutlineThickness(1);
    m_Shape.setOutlineColor(sf::Color::White);
    m_Shape.setFillColor(sf::Color::Red);
    m_Shape.setPosition(m_Pos);
}

void Ball::update(float dt, Player& p)
{   m_Pong = false;
    m_FlipTimer += dt;
    m_Speed.x = ((m_Pos.x > 1280 -7 || m_Pos.x < 0) && m_FlipTimer > 0.010)?((m_FlipTimer = 0) - 1)*m_Speed.x:m_Speed.x;
    m_Speed.y = ((m_Pos.y > 720 - 7 || m_Pos.y < 0) && m_FlipTimer > 0.010)?((m_FlipTimer = 0) - 1)*m_Speed.y :m_Speed.y;

    if(p.getShape().getGlobalBounds().findIntersection(m_Shape.getGlobalBounds()) && m_FlipTimer > 0.010){
        m_Speed.y *= -1;
        m_Pos.y -= 32;
        m_FlipTimer = 0;
        p.addScore();
        m_Pong = true;
    }


    m_Pos.x += m_Speed.x * dt;
    m_Pos.y += m_Speed.y * dt;

    m_Shape.setPosition(m_Pos);

}

sf::RectangleShape Ball::getShape()
{
    return m_Shape;
}

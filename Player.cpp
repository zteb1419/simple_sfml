#include "Player.h"
#include <iostream>

Player::Player(int x, int y):m_Pos(x, y)
{   //m_Pos.x = x;
    //m_Pos.y = y;
    m_Shape.setSize(sf::Vector2f(64, 32));
    m_Shape.setFillColor(sf::Color::Green);
    m_Shape.setPosition(m_Pos);
    m_Shape.setOrigin(sf::Vector2f(32, 16));

}

sf::RectangleShape Player::getShape()
{
    return m_Shape;
}

void Player::Update(float dt)
{

    m_MoveLeft =sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)?true:false;
    m_MoveRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)?true:false;


    if(m_MoveLeft && m_Pos.x > 32) m_Pos.x -= m_MoveSpeed * dt;
    if(m_MoveRight && m_Pos.x < 1280 - 32) m_Pos.x += m_MoveSpeed * dt;

    m_Shape.setPosition(m_Pos);

}

int Player::getScore()
{
    return m_Score;
}

void Player::addScore()
{
    m_Score++;
}

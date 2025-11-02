#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

class Player {
    public:
    Player(int x, int y);
    sf::RectangleShape getShape();
    void Update(float dt);
    int getScore();
    void addScore();

    private:
    sf::RectangleShape m_Shape;
    sf::Vector2f m_Pos;
    float m_MoveSpeed = 400;
    int m_Score = 0;

    bool m_MoveLeft = false;
    bool m_MoveRight = false;

};



#endif
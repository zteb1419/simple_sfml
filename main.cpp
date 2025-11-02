#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Ball.h"
#include <iostream>
#include <sstream>

int main() {
    const float        gameWidth  = 1280;
    const float        gameHeight = 720;

    sf::RenderWindow window(sf::VideoMode({static_cast<unsigned int>(gameWidth), static_cast<unsigned int>(gameHeight)}, 32),
                            "SFML Pong",
                            sf::Style::Titlebar | sf::Style::Close);
    
    window.setFramerateLimit(120);

    const sf::SoundBuffer ballSoundBuffer("pong.wav");
    sf::Sound             ballSound(ballSoundBuffer);


    
    sf::Font font;
    if(!font.openFromFile("SupremeSpike-KVO8D.otf")){
        std::cout << "Error Loading Font." << std::endl;
    }
    sf::Text text(font);
    text.setPosition(sf::Vector2f(0, 5));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Green);
    text.setString("Score: ");
    Player p(1280/2, 720-16);
    Ball b(1280/2, 0);
    sf::Time gameTime;
    sf::Clock gameClock;
    std::stringstream ss;
    float dt;

    sf::Music music("gamemusic.mp3");
    music.setLooping(true);
    music.setVolume(10);
    music.play();

   

    while(window.isOpen()){
        ss.str("");
        ss << "Score: " << p.getScore();
        text.setString(ss.str());
        gameTime = gameClock.restart();
        dt = gameTime.asSeconds();

        while (const std::optional event = window.pollEvent()){
                // Window closed or escape key pressed: exit
                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                    break;
                }
            
        }
        b.update(dt, p);
        p.Update(dt);

        if(b.m_Pong == true){
            ballSound.play();
        }
        window.clear();
        window.draw(text);
        window.draw(p.getShape());
        window.draw(b.getShape());
        window.display();
    }
    
}
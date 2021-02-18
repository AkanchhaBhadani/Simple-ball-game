#include "SFML/Graphics.hpp"
#include<vector>
#include <iostream>
#include <cmath>
#include <random>
int main()
{
    sf::RenderWindow wind(sf::VideoMode(640,480), "bounce");
    sf::Event event;
    sf::CircleShape ball(20);
    ball.setFillColor(sf::Color{247,33,33});
    ball.setOutlineThickness(2);
    ball.setOutlineColor(sf::Color::Black);
    sf::RectangleShape brick(sf::Vector2f(700,40));
    brick.setFillColor(sf::Color{255,38,33});
    brick.setOutlineColor(sf::Color::Black);
    brick.setOutlineThickness(2);
    brick.setPosition(-50,438);
    ball.setPosition(20,396);
    sf::RectangleShape brick2(sf::Vector2f(700,40));
    brick2.setFillColor(sf::Color{255,38,33});
    brick2.setOutlineColor(sf::Color::Black);
    brick2.setOutlineThickness(2);
    brick2.setPosition(654,438);
    sf::RectangleShape barrier(sf::Vector2f(10,50));
    barrier.setFillColor(sf::Color{253,219,73});
    barrier.setOutlineThickness(2);
    barrier.setOutlineColor(sf::Color::Black);
    barrier.setPosition(400, 386);
    sf::RectangleShape barrier2(sf::Vector2f(10,50));
    barrier2.setFillColor(sf::Color{253,219,73});
    barrier2.setOutlineThickness(2);
    barrier2.setOutlineColor(sf::Color::Black);
    barrier2.setPosition(brick2.getPosition().x+300, 386);
    sf::RectangleShape barrier3 (sf::Vector2f(10,50));
    barrier3.setFillColor(sf::Color{253,219,73});
    barrier3.setOutlineThickness(2);
    barrier3.setOutlineColor(sf::Color::Black);
    barrier3.setPosition(800, 386);
    sf::RectangleShape barrier4(sf::Vector2f(10,50));
    barrier4.setFillColor(sf::Color{253,219,73});
    barrier4.setOutlineThickness(2);
    barrier4.setOutlineColor(sf::Color::Black);
    barrier4.setPosition(brick2.getPosition().x+500, 386);
    bool up = false;
    bool going_up = false;
    sf::Clock clock;
    std::vector <sf::RectangleShape> bricks;
    sf::View view(sf::Vector2f(320.0f, 240.0f), sf::Vector2f(640.f, 480.f));
    sf::Clock clock2;
    std::uniform_int_distribution <int> range(100,350);
    std::random_device rd;
    std::mt19937 ran_no(rd());
    wind.setKeyRepeatEnabled(true);
    while (wind.isOpen())
    {


        while (wind.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up )
                {

                    ball.setPosition(ball.getPosition().x, ball.getPosition().y - 0.5*10*pow(clock.getElapsedTime().asSeconds(),2));
                    going_up = true;
                    if (ball.getPosition().y == 250)
                    {
                        up = true;
                    }


                }


                if (event.key.code == sf::Keyboard::Right)
                {
                    if (going_up == true || up == true)
                    {
                        ball.move(2.0f,0);
                    }

                        ball.move(5.0f,0.0f);
                        ball.setOrigin(ball.getLocalBounds().width/2, ball.getLocalBounds().height/2);
                        ball.rotate(360);
                        ball.setOrigin(0,0);
                        brick.move(-5.0f,0);
                        brick2.move(-5.0f,0);
                        barrier.move(-5.0f,0);
                        barrier2.move(-5.0f,0);
                        barrier3.move(-5.0f,0);
                        barrier4.move(-5.0f,0);


                }
                /*if (event.key.code == sf::Keyboard::Left)
                {

                        ball.move(-5.0f,0.0f);
                        brick.move(10.0f,0);
                        brick2.move(10.0f,0);
                }*/
            }

            if(event.type == sf::Event::EventType::Closed)
            {
                wind.close();
            }

        }
         if(ball.getPosition().x > 640)
         {

            brick.setPosition(-50,438);
            brick2.setPosition(654,438);
            barrier.setPosition(range(ran_no),386);
            barrier2.setPosition(brick2.getPosition().x+range(ran_no),386);
            barrier3.setPosition(barrier.getPosition().x+350,386);
            barrier4.setPosition(barrier2.getPosition().x+range(ran_no),386);
            view.setCenter(brick.getGlobalBounds().width/2,240);
            ball.setPosition(brick.getPosition().x+70,396);

         }
        if (ball.getPosition().x+40 >= barrier.getPosition().x && ball.getPosition().x <= barrier.getPosition().x+10 && ball.getPosition().y >= barrier.getPosition().y)
        {
            brick.setPosition(-50,438);
            brick2.setPosition(654,438);
            barrier.setPosition(range(ran_no),386);
            barrier2.setPosition(brick2.getPosition().x+range(ran_no),386);
            barrier3.setPosition(barrier.getPosition().x+350,386);
            barrier4.setPosition(barrier2.getPosition().x+range(ran_no),386);
            view.setCenter(brick.getGlobalBounds().width/2,240);
            ball.setPosition(brick.getPosition().x+70,396);
        }
        if (ball.getPosition().x+40 >= barrier2.getPosition().x && ball.getPosition().x <= barrier2.getPosition().x+10 && ball.getPosition().y >= barrier2.getPosition().y)
        {
            brick.setPosition(-50,438);
            brick2.setPosition(654,438);
            barrier.setPosition(range(ran_no),386);
            barrier2.setPosition(brick2.getPosition().x+range(ran_no),386);
            barrier3.setPosition(barrier.getPosition().x+350,386);
            barrier4.setPosition(barrier2.getPosition().x+range(ran_no),386);
            view.setCenter(brick.getGlobalBounds().width/2,240);
            ball.setPosition(brick.getPosition().x+70,396);
        }
        if (ball.getPosition().x+40 >= barrier3.getPosition().x && ball.getPosition().x <= barrier3.getPosition().x+10 && ball.getPosition().y >= barrier3.getPosition().y)
        {
            brick.setPosition(-50,438);
            brick2.setPosition(654,438);
            barrier.setPosition(range(ran_no),386);
            barrier2.setPosition(brick2.getPosition().x+range(ran_no),386);
            barrier3.setPosition(barrier.getPosition().x+350,386);
            barrier4.setPosition(barrier2.getPosition().x+range(ran_no),386);
            view.setCenter(brick.getGlobalBounds().width/2,240);
            ball.setPosition(brick.getPosition().x+70,396);
        }
        if (ball.getPosition().x+40 >= barrier4.getPosition().x && ball.getPosition().x <= barrier4.getPosition().x+10 && ball.getPosition().y >= barrier4.getPosition().y)
        {
            brick.setPosition(-50,438);
            brick2.setPosition(654,438);
            barrier.setPosition(range(ran_no),386);
            barrier2.setPosition(brick2.getPosition().x+range(ran_no),386);
            barrier3.setPosition(barrier.getPosition().x+350,386);
            barrier4.setPosition(barrier2.getPosition().x+range(ran_no),386);
            view.setCenter(brick.getGlobalBounds().width/2,240);
            ball.setPosition(brick.getPosition().x+70,396);
        }
        while (barrier2.getPosition().x-barrier3.getPosition().x < 200)
        {
            barrier2.setPosition(brick2.getPosition().x+range(ran_no),386);
        }
        while (barrier4.getPosition().x - barrier2.getPosition().x < 150)
        {
            barrier4.setPosition(barrier2.getPosition().x+range(ran_no),386);
        }

        if (going_up == true)
        {
            if (ball.getPosition().y - (0.5*10*pow(clock.getElapsedTime().asSeconds(),2)) > 250 && clock2.getElapsedTime().asSeconds()>0.005f)
            {
                ball.move(0,-(0.5*10*pow(clock.getElapsedTime().asSeconds(),2)));
                clock2.restart();
            }
            if (ball.getPosition().y - (0.5*10*pow(clock.getElapsedTime().asSeconds(),2)) < 250)
            {
                ball.setPosition(ball.getPosition().x, 250);

            }
            if (ball.getPosition().y == 250)
            {
                going_up = false;
                up = true;
                clock.restart();
            }
        }
        if(up == true)
        {
            if (ball.getPosition().y + (0.5*10*pow(clock.getElapsedTime().asSeconds(),2))< 396 && clock2.getElapsedTime().asSeconds()>0.005f)
            {
                ball.move(0,(0.5*10*pow(clock.getElapsedTime().asSeconds(),2)));
                clock2.restart();

            }
            if (ball.getPosition().y + (0.5*10*pow(clock.getElapsedTime().asSeconds(),2))> 396 )
            {
                ball.setPosition(ball.getPosition().x, 396);
            }
            if (ball.getPosition().y == 396)
            {

                up = false;
                clock.restart();
            }
                    }


        wind.clear(sf::Color{169,213,253});
        wind.setView(view);
        wind.draw(ball);
        wind.draw(brick);
        wind.draw(brick2);
        wind.draw(barrier);
        wind.draw(barrier2);
        wind.draw(barrier3);
        wind.draw(barrier4);
        wind.display();
    }


}

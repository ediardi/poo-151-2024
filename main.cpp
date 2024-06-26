#include <iostream>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

#include <Helper.h>

//////////////////////////////////////////////////////////////////////
/// NOTE: this include is needed for environment-specific fixes     //
/// You can remove this include and the call from main              //
/// if you have tested on all environments, and it works without it //
#include "env_fixes.h"                                              //
//////////////////////////////////////////////////////////////////////

#include "Drawables.h"
#include "GameStateManager.h"
#include "GameStateError.h"
#include "MapGenerator.h"


// static variables
sf::VertexArray Drawables::points;
sf::VertexArray Drawables::lines(sf::Lines,0);
std::unordered_map<int,sf::CircleShape> Drawables::circles;
std::unordered_map<int,sf::CircleShape> Drawables::pawns;


int main() {

    //// Challenge: make a triangle of largest area possible that is within the circumscribed circle of another triangle and does not intersect the original triangle

    ////////////////////////////////////////////////////////////////////////
    /// NOTE: this function call is needed for environment-specific fixes //
    init_threads();                                                       //
    ////////////////////////////////////////////////////////////////////////

    Helper helper;
    helper.help();
    ///////////////////////////////////////////////////////////////////////////

    sf::RenderWindow window;
    ///////////////////////////////////////////////////////////////////////////
    /// NOTE: sync with env variable APP_WINDOW from .github/workflows/cmake.yml:31
    window.create(sf::VideoMode({800, 700}), "My Window", sf::Style::Default);
    ///////////////////////////////////////////////////////////////////////////
    //
    ///////////////////////////////////////////////////////////////////////////
    /// NOTE: mandatory use one of vsync or FPS limit (not both)            ///
    /// This is needed so we do not burn the GPU                            ///
    window.setVerticalSyncEnabled(true);                            ///
    /// window.setFramerateLimit(60);                                       ///
    ///////////////////////////////////////////////////////////////////////////

    // for executable debug purposes
    if(window.isOpen()) {
        std::cout << "Game window opened" << std::endl;
        //auto graph=mapgenerator::;
    }
    auto map=MapGenerator(window.getSize().x,window.getSize().y);
    GameStateManager game(map);

    while(window.isOpen()) {
        bool shouldExit = false;
        sf::Event e{};
        while(window.pollEvent(e)) {
            switch(e.type) {
            case sf::Event::Closed: {
                window.close();
                break;
            }
            case sf::Event::Resized: {
                std::cout << "New width: " << window.getSize().x << '\n'
                          << "New height: " << window.getSize().y << '\n';
                break;
            }
            case sf::Event::KeyPressed: {
                std::cout << "Received key " << (e.key.code == sf::Keyboard::X ? "X" : "(other)") << "\n";
                if (e.key.code == sf::Keyboard::Escape)
                    shouldExit = true;
                break;
            }
            case sf::Event::MouseButtonPressed: {
                sf::Vector2 mouse_position = sf::Mouse::getPosition(window);
                sf::Vector2f coordinates(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y));
                std::cout << "Got click " << mouse_position.x << ' ' << mouse_position.y << "\n";
                try {
                    game.handle_click(coordinates.x, coordinates.y);
                }
                catch (CannotProcessClick& err){
                    std::cout << err.what() << std::endl;
                }
                catch (DoubleClick& err){
                    std::cout << err.what() << std::endl;
                }
                break;
            }
            default:

                break;
            }
        }
        // instead of if statement
        shouldExit |= game.has_ended();


        if(shouldExit) {
            window.close();
            break;
        }

        window.clear();
        Drawables drawables;
        window.draw(drawables);

        window.display();


        using namespace std::chrono_literals;
        std::this_thread::sleep_for(30ms);
    }

    return 0;
}

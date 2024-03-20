#include <iostream>
#include <array>
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

class Point {
    float x;
    float y;
    Point(int x,int y)
    {
        this->x= static_cast<float>(x);
        this->y= static_cast<float>(y);
    }
public:
    void setx(float new_x){this->x=new_x;}
    void sety(float new_y){this->y=new_y;}
    float getx(){return x;}
    float gety(){return y;}
    sf::Vertex tovertex()
    {
        sf::Vector2f temp1(x,y);
        sf::Vertex temp(temp1);
        return temp;
    }
};

class Line {
    Point a,b;
public:
    Point startpoint(){ return a;}
    Point endpoint(){ return b;}
};

class Intersecting_Lines {

    std::array<Line,0> lines;
    int count=0;
    sf::VertexArray todraw(){
        sf::VertexArray temp(sf::Lines,0);
        for(auto line:lines)
        {
            temp.append(line.startpoint().tovertex());
            temp.append(line.endpoint().tovertex());
        }
        return temp;
    }
};

//////////////////////////////////////////////////////////////////////
/// This class is used to test that the memory leak checks work as expected even when using a GUI
class SomeClass {
public:
    explicit SomeClass(int) {}
};

SomeClass *getC() {
    return new SomeClass{2};
}
//////////////////////////////////////////////////////////////////////


int main() {
    ////////////////////////////////////////////////////////////////////////
    /// NOTE: this function call is needed for environment-specific fixes //
    init_threads();                                                       //
    ////////////////////////////////////////////////////////////////////////
    ///
    std::cout << "Hello, world!\n";
    /////////////////////////////////////////////////////////////////////////
    /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
    /// dați exemple de date de intrare folosind fișierul tastatura.txt
    /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
    /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
    /// De asemenea, trebuie să adăugați în acest fișier date de intrare
    /// pentru cât mai multe ramuri de execuție.
    /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
    /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
    ///
    /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
    /// pentru a simula date introduse de la tastatură.
    /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
    ///
    /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
    /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
    /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
    /// program care merg (și să le evitați pe cele care nu merg).
    ///
    /////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
    /// alt fișier propriu cu ce alt nume doriți.
    /// Exemplu:
    /// std::ifstream fis("date.txt");
    /// for(int i = 0; i < nr2; ++i)
    ///     fis >> v2[i];
    ///
    ///////////////////////////////////////////////////////////////////////////
    ///                Exemplu de utilizare cod generat                     ///
    ///////////////////////////////////////////////////////////////////////////
    Helper helper;
    helper.help();
    ///////////////////////////////////////////////////////////////////////////

    SomeClass *c = getC();
    std::cout << c << "\n";
    delete c;

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

    sf::VertexArray lines(sf::Lines, 0);

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
                sf::Vector2 mousepos = sf::Mouse::getPosition(window);
                sf::Vector2f first_try(static_cast<float>(mousepos.x),static_cast<float>(mousepos.y));
                std::cout << "Got click " << mousepos.x << ' ' << mousepos.y << "\n";
                lines.append(first_try);
                break;
            }
            default:
                break;
            }
        }
        if(shouldExit) {
            window.close();
            break;
        }
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(300ms);

        window.clear();
        window.draw(lines);
        window.display();
    }
    return 0;
}

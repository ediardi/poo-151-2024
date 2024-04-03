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

#include "Triangle.h"
#include "Point.h"
#include "Drawables.h"



class Line {
    Point a,b;
    int intersections=0;
    sf::Color color[7]={sf::Color::White,sf::Color::Yellow,sf::Color::Red
    ,sf::Color::Green, sf::Color::Magenta, sf::Color::Cyan
    , sf::Color::Blue};
public:
    Point startpoint(){ return a;};
    Point endpoint(){ return b;};
    Line(Point a1,Point b1) : a(a1),b(b1) {}
    sf::Color get_color()
    {
        return color[intersections];
    }
    void inc_interesction()
    {
        intersections++;
        a.inc_color();
        b.inc_color();
    }
    bool intersects(Line line)
    {
        // credit goes to https://stackoverflow.com/questions/563198/how-do-you-detect-where-two-line-segments-intersect
        // Returns 1 if the lines intersect, otherwise 0. In addition, if the lines
        // p0= a
        // p1 =b
        // p2 =line.a
        // p3 =line.b
        {
            float s1_x, s1_y, s2_x, s2_y;
            s1_x = b.getx() - a.getx();                 s1_y = b.gety() - a.gety();
            s2_x = line.b.getx() - line.a.getx();        s2_y = line.b.gety() - line.a.gety();

            float s, t;
            s = (-s1_y * (a.getx() - line.a.getx()) + s1_x * (a.gety() - line.a.gety())) / (-s2_x * s1_y + s1_x * s2_y);
            t = ( s2_x * (a.gety() - line.a.gety()) - s2_y * (a.getx() - line.a.getx())) / (-s2_x * s1_y + s1_x * s2_y);

            if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
            {
                // Collision detected
                return true;
            }

            return false; // No collision
        }
    }
};

class Intersecting_Lines {

    std::vector<Line> lines;
    bool clickstate=0;
    Point temppoint=Point(0,0);
public:
    void addline(Line line){
        for (auto& lin:lines)
        {
            if(line.intersects(lin))
            {
                line.inc_interesction();
                lin.inc_interesction();
            }
        }
        lines.push_back(line);
    }
    void add_point(Point new_p){
        if(clickstate==0)
        {
            clickstate=1;
            temppoint=new_p;
        }
        else
        {
            clickstate=0;
            addline(Line(temppoint,new_p));
        }
    }
    void tempdisplay(){
        if(clickstate==1)
        {

        }
    }
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




sf::VertexArray Drawables::points;
std::vector<sf::CircleShape> Drawables::circles;
std::vector<Triangle> Drawables::triangles;

class Geometry{

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

    //sf::VertexArray lines(sf::Lines, 0);
    Intersecting_Lines lines;

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
                //lines.add_point(Point(mousepos.x,mousepos.y));
                sf::Vector2f first_try(static_cast<float>(mousepos.x),static_cast<float>(mousepos.y));
                Drawables::add_triangle_vertex(sf::Vertex(first_try));
                //std::cout << "Got click " << mousepos.x << ' ' << mousepos.y << "\n";
                //lines.append(first_try);
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
        std::this_thread::sleep_for(30ms);

        window.clear();
        window.draw(lines.todraw());
        Drawables drawables;
        window.draw(drawables);

        /*
        sf::CircleShape cirtext(100,60);
        cirtext.setOrigin(0,0);
        cirtext.setOutlineColor(sf::Color::White);
        cirtext.setFillColor(sf::Color::Transparent);
        cirtext.setOutlineThickness(2);
        window.draw(cirtext);
         */


        window.display();
    }
    return 0;
}

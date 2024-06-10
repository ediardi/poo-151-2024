//
// Created by eciuc on 4/15/2024.
//

#include <iostream>
#include "Stopwatch.h"
#include "GameStateManager.h"
#include "Drawables.h"
#include "Point.h"

GameStateManager::GameStateManager():fin("levels.txt") {
    fin>>n;
    index=0;
    next_level();
    std::cout << "This game has " << n << " levels in which you have to make a triangle of largest area possible that is within the circumscribed circle of the given triangle and does not intersect it" << std::endl;
    std::cout << "To pass each level you have to have an area of at least 75% of the theoretical maximum area" << std::endl;
}

void GameStateManager::handle_click(float x, float y) {
    Stopwatch::discard_double_action();
    switch (state) {
        case awaiting_point:
        {
            points++;
            switch (points) {
                case 1:
                {
                    candidate_triangle = PlayerTriangle();
                    candidate_triangle.set_a(Point(x, y));
                    Drawables::add(sf::Vertex(sf::Vector2f (x,y)));
                    break;
                }
                case 2:
                {
                    candidate_triangle.set_b(Point(x, y));
                    Drawables::add(sf::Vertex(sf::Vector2f (x,y)));
                    break;
                }
                case 3:
                {
                    points = 0;
                    candidate_triangle.set_c(Point(x, y));
                    Drawables::add(sf::Vertex(sf::Vector2f (x,y)));
                    evaluate();
                    break;
                }
            }
            break;
        }
        case click_to_continue:
        {
            next_level();
            break;
        }
        case showing_result:
        {
            throw CannotProcessClick("The game is currently processing results, click ignored");
            break;
        }
        case game_end:
        {
            break;
        }
    }
}

GameStateManager::~GameStateManager() {
    fin.close();
    Drawables::clear_all();
}

void GameStateManager::next_level() {
    Drawables::clear_all();
    draw_circle_index = -1;
    draw_challenge_triangle_index = -1;
    draw_candidate_triangle_index = -1;
    if(replay_level)
    {
        //for the sake of using constructors:
        TriangleWithCenter old=challenge_triangle;
        challenge_triangle = TriangleWithCenter(old);
        //
        draw_challenge_triangle_index = challenge_triangle.add_on_screen();
        state = awaiting_point;
    }
    else {
        if (index < n) {
            float x, y;
            fin >> x >> y;
            Point a(x, y);
            fin >> x >> y;
            Point b(x, y);
            fin >> x >> y;
            Point c(x, y);
            challenge_triangle =  TriangleWithCenter(a, b, c);
            draw_challenge_triangle_index = challenge_triangle.add_on_screen();
            index++;
            state = awaiting_point;
        } else {
            state = game_end;
        }
    }
}

bool GameStateManager::has_ended() {
    if(index==n && state==game_end)
        return true;
    return false;
}

bool inline GameStateManager::is_in_circle() const{
    return candidate_triangle.is_inside_circle(challenge_triangle.get_center(), challenge_triangle.get_radius());
}

bool inline GameStateManager::triangles_do_not_intersect() const{
    return candidate_triangle.does_not_intersect_triangle(challenge_triangle);
}

void GameStateManager::evaluate() {
    state=showing_result;
    frames_to_show_results=0;

    draw_candidate_triangle_index = candidate_triangle.add_on_screen();
    draw_circle_index= challenge_triangle.add_circumscribed_circle_on_screen();

    // check for intersections
    if(is_in_circle() && triangles_do_not_intersect())
    {
        float score=0;
        try {
            score= 100 * candidate_triangle.get_area() / challenge_triangle.best_area();
            std::cout<<"The 3 points you submitted created a valid triangle"<<std::endl;
            std::cout << candidate_triangle;
            std::cout<<"The triangle has an area equal to "<<candidate_triangle.get_area()<<std::endl<<std::endl;
        }
        catch (GeometricError& err){
            std::cout << "The triangle you entered is degenerate and has no area"<< std::endl;
            std::cout << err.what() << std::endl;
        }

        std::cout<<"The challenge has the following characteristics:" << std::endl;
        std::cout << challenge_triangle;
        std::cout << "The maximum possible area is " << challenge_triangle.best_area() << std::endl <<std::endl;
        std::cout<<"On level "<<index<<" you achieved a score of "<<score<<" %"<<std::endl;
        if(score>90)
        {
            std::cout<<"Excellent result"<<std::endl;
            replay_level=false;
        }
        else
        {
            if(score>75)
            {
                std::cout<<"You passed the level but you can do better"<<std::endl;
                replay_level=false;
            }
            else
            {
                std::cout<<"That score looks pretty low, try and get a better one"<<std::endl;
                replay_level=true;
            }
        }
        std::cout<<"Actions disabled until animation finishes to prevent accidental skip"<<std::endl;
        highlight_color=sf::Color::Green;
    }
    else
    {
        std::cout<<"The 3 points you submitted formed a triangle that intersected some geometry"<<std::endl;
        std::cout<<"Actions disabled until animation finishes to prevent accidental skip"<<std::endl;
        replay_level=true;
        highlight_color=sf::Color::Red;
    }
}

void GameStateManager::frame_update() {
    if(state==showing_result)
    {
        if(frames_to_show_results%10==0)
        {
            sf::Color new_color= opposite( Drawables::get_triangle_color(draw_candidate_triangle_index));

            Drawables::change_triangle_color(draw_candidate_triangle_index,new_color);
            if(replay_level)
            {
                if(!is_in_circle()) {
                    Drawables::change_circle_color(draw_circle_index,new_color);
                }
                if(!triangles_do_not_intersect()) {
                    Drawables::change_triangle_color(draw_challenge_triangle_index,new_color);
                }
            }
        }
        frames_to_show_results++;
        if (frames_to_show_results > results_max_frames) {
            state = click_to_continue;
            std::cout << "Animation finished!" << std::endl;
            if (!replay_level) {
                if(index!=n)
                    std::cout << "Click anywhere on the game screen to continue to next level" << std::endl;
                else {
                    std::cout << "CONGRATULATIONS! YOU FINISHED THE PUZZLE!" << std::endl;
                    std::cout << "Click anywhere in the interface to close the application" << std::endl;
                }
            }
            else
                std::cout<<"Click anywhere on the game screen to restart level"<<std::endl;
        }
    }
}

sf::Color GameStateManager::opposite(const sf::Color color) const{
    if(color==sf::Color::White)
        return highlight_color;
    return sf::Color::White;
}



//
// Created by eciuc on 4/15/2024.
//

#include <iostream>
#include "GameStateManager.h"
#include "Drawables.h"
#include "Point.h"

GameStateManager::GameStateManager():fin("nivele.txt") {
    fin>>n;
    index=0;
    next_level();
}

void GameStateManager::handle_click(float x, float y) {
    switch (state) {
        case awaiting_point:
        {
            points++;
            switch (points) {
                case 1:
                {
                    candidate_triangle = new Triangle();
                    candidate_triangle->seta(Point(x,y));
                    Drawables::add(sf::Vertex(sf::Vector2f (x,y)));
                    break;
                }
                case 2:
                {
                    candidate_triangle->setb(Point(x,y));
                    Drawables::add(sf::Vertex(sf::Vector2f (x,y)));
                    break;
                }
                case 3:
                {
                    points = 0;
                    candidate_triangle->setc(Point(x,y));
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
        case game_end:
        {
            break;
        }
    }
}

GameStateManager::~GameStateManager() {
    fin.close();
}

void GameStateManager::next_level() {
    Drawables::clear_all();
    delete candidate_triangle;
    if(replaylevel)
    {
        draw_challenge_triangle_reference = challange_triangle->add_on_screen();
        state = awaiting_point;
    }
    else {
        delete challange_triangle;
        if (index < n) {
            float x, y;
            fin >> x >> y;
            Point a(x, y);
            fin >> x >> y;
            Point b(x, y);
            fin >> x >> y;
            Point c(x, y);
            challange_triangle = new Triangle(a, b, c);
            draw_challenge_triangle_reference = challange_triangle->add_on_screen();
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

bool inline GameStateManager::is_in_circle(){
    return candidate_triangle->is_inside_circle(challange_triangle->getcenter(),challange_triangle->getradius());
}

bool inline GameStateManager::triangles_do_not_intersect(){
    return candidate_triangle->does_not_intersect_triangle(*challange_triangle);
}

void GameStateManager::evaluate() {
    state=showing_result;
    frames_to_show_results=0;

    draw_candidate_triangle_reference = candidate_triangle->add_on_screen();
    draw_circle_reference= challange_triangle->add_circumcircle_on_screen();

    // check for intersections
    if(is_in_circle() && triangles_do_not_intersect())
    {
        float score=100*candidate_triangle->get_area()/challange_triangle->best_area();
        std::cout<<"The 3 points you submitted created a valid triangle"<<std::endl;
        std::cout<<"The triangle has an are equal to "<<candidate_triangle->get_area()<<std::endl;
        std::cout<<"The maximum possible area is "<<challange_triangle->best_area()<<std::endl;
        std::cout<<"On level "<<index<<" you achieved a score of "<<score<<" %"<<std::endl;
        if(score>90)
        {
            std::cout<<"Excellent result"<<std::endl;
            replaylevel=false;
        }
        else
        {
            if(score>75)
            {
                std::cout<<"You passed the level but you can do better"<<std::endl;
                replaylevel=false;
            }
            else
            {
                std::cout<<"That score looks pretty low, try and get a better one"<<std::endl;
                replaylevel=true;
            }
        }
        std::cout<<"Actions disabled until animation finishes to prevent accidental skip"<<std::endl;
        highligh_color=sf::Color::Green;
    }
    else
    {
        std::cout<<"The 3 points you submitted formed a triangle that intersected some geometry"<<std::endl;
        std::cout<<"Actions disabled until animation finishes to prevent accidental skip"<<std::endl;
        replaylevel=true;
        highligh_color=sf::Color::Red;
    }
}

void GameStateManager::frame_update() {
    if(state==showing_result)
    {
        if(frames_to_show_results%10==0)
        {
            draw_candidate_triangle_reference->color= opposite(draw_candidate_triangle_reference->color);
            if(replaylevel)
            {
                if(!is_in_circle())
                    draw_circle_reference->setOutlineColor(opposite(draw_circle_reference->getOutlineColor()));
                if(!triangles_do_not_intersect())
                    draw_challenge_triangle_reference->color=opposite(draw_challenge_triangle_reference->color);
            }
        }
        frames_to_show_results++;
        if (frames_to_show_results > results_max_frames)
        {
            state=click_to_continue;
            if(!replaylevel)
                std::cout<<"Click anywhere on the game screen to continue to next level"<<std::endl;
            else
                std::cout<<"Click anywhere on the game screen to restart level"<<std::endl;
        }
    }
}

sf::Color GameStateManager::opposite(sf::Color color) {
    if(color==sf::Color::White)
        return highligh_color;
    return sf::Color::White;
}



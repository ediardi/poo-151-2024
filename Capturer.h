//
// Created by eciuc on 6/18/2024.
//

#ifndef OOP_CAPTURER_H
#define OOP_CAPTURER_H


#include <vector>
#include <SFML/Graphics.hpp>
#include "Drawables.h"

class Node;

class Capturer {
    static inline int id_c = 0;
    int id;
public:
    [[nodiscard]] int getId() const;

private:
    int current_pos;
    sf::Color captured_col,occupied_col;
public:
    [[nodiscard]] const sf::Color &getCapturedCol() const;

    [[nodiscard]] const sf::Color &getOccupiedCol() const;

public:
    [[nodiscard]] int getCurrentPos() const;

public:
    explicit Capturer(sf::Color cap_col,sf::Color occ_col):id(id_c),current_pos(-1),captured_col(cap_col),occupied_col(occ_col){
        id_c++;
        Drawables::add(sf::Vertex(),occupied_col);
    }
    bool move(Node& node, std::vector<Node *> &graph);
};


#endif //OOP_CAPTURER_H

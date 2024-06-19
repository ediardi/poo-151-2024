//
// Created by eciuc on 6/18/2024.
//

#ifndef OOP_CAPTURER_H
#define OOP_CAPTURER_H


#include <vector>
#include <SFML/Graphics.hpp>

class Node;

class Capturer {
    int current_pos;
    sf::Color captured_col,occupied_col;
public:
    const sf::Color &getCapturedCol() const;

    const sf::Color &getOccupiedCol() const;

public:
    [[nodiscard]] int getCurrentPos() const;

public:
    explicit Capturer(sf::Color cap_col,sf::Color occ_col):current_pos(-1),captured_col(cap_col),occupied_col(occ_col){}
    bool move(Node& node, std::vector<Node *> &graph);
};


#endif //OOP_CAPTURER_H

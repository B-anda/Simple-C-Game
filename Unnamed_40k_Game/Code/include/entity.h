#pragma once
#include "game_object.h"

#include <SFML/Graphics.hpp>
#include <memory>


class Enemy;

class Entity : public Game_Object
{
    public:
    Entity(sf::Vector2f coordinates,
            sf::Texture& texture, 
            sf::RenderWindow& window,
            int health_points = 3,
            int damage = 1,
            int speed = 1);

    virtual ~Entity() = 0;

    void draw(sf::RenderWindow& window) override;
    // virtual void update(double delta_time, sf::RenderWindow& window, size_t window_width, size_t window_height) = 0;
    virtual void attack() const = 0;
    virtual void move(double delta_time, size_t window_width, size_t window_height) = 0;
    virtual void update(double delta_time) = 0;
    virtual void death() = 0;
    void rotate(sf::Vector2f& direction);
    sf::Vector2f check_boundury_collision(sf::Vector2f direction, double distance_to_move, size_t window_width, size_t window_height);
    virtual bool is_dead() = 0;
    void set_speed(int new_speed);
    void set_texture(sf::Texture& new_texture);
    void set_attack_speed(double new_speed);
    bool can_attack() const;
    void take_damage(int damage_to_take);
    // void set_enemies(std::vector<std::shared_ptr<Grunt>>& enemies);

    protected:
    int health_points;
    int damage;
    int speed;
    double rotation;
    float texture_scale;
    
    float attack_distance;
    double attack_cooldown;
    double time_since_last_attack;
    // std::vector<std::shared_ptr<Grunt>>* loaded_enemies;
}; 
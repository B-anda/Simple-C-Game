#include "game_over_state.h"
#include "standard.h"
#include <cmath>

Game_Over_State::Game_Over_State(int level_count)
: level_count{level_count}
{
    if (!font.loadFromFile("../Static/Textures/arial.ttf") )
    {
        std::cerr << "failed to fuck font" ;
    }
    
    text[0] = sf::Text{"You\'ve won!", font};
    text[1] = sf::Text{"You\'ve cleared the level!", font};
    text[2] = sf::Text{"You Lose!", font};
    text[3] = sf::Text{instructions, font};
    for ( int i = 0 ; i < 3 ; i++ )
    {
        // auto center = text[i].getGlobalBounds()
        text[i].setCharacterSize(60);
    }

    current_level_index = 1;
    cout << "gae" << endl;

}

Game_Over_State::~Game_Over_State()
{}

void Game_Over_State::update(double delta_time, sf::RenderWindow& window)
{
    window.clear();

    decision_handling();
}

void Game_Over_State::render(sf::RenderWindow& window)
{
    window.draw( text[decision-1] );
    // cout << text[decision-1].getPosition().y << text[decision-1].getPosition().x << endl;
    window.draw( text[3] );
    // cout << text[3].getPosition().y << text[3].getPosition().x << endl;
    // cout << text[3].getString().toAnsiString() << endl;
}



void Game_Over_State::set_status( bool win )
{
    if ( win && level_count == current_level_index )
    {
        decision = 1;
        instructions = "Press Q to exit.";
    }
    else if( win )
    {
        decision = 2;
        instructions = "Press SPACE to continue or Q to exit.";
        current_level_index++;
    }
    else if( !win )
    {
        decision = 3;
        instructions = "Press SPACE to restart or Q to exit.";
    }
}

void Game_Over_State::decision_handling()
{
    upper_text_size = sf::Vector2f{512 - text[decision-1].getGlobalBounds().width / 2, 512 - text[decision-1].getGlobalBounds().height / 2};
    upper_text_size.y -= 30;
    text[decision-1].setPosition(upper_text_size);
    text[3].setString(instructions);
    lower_text_size = sf::Vector2f{512 - text[3].getGlobalBounds().width / 2, 512 - text[3].getGlobalBounds().height / 2};
    lower_text_size.y += 30;
    text[3].setPosition(lower_text_size);
}

int Game_Over_State::get_change()
{
    return decision;
}
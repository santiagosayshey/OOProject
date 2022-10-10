#include "Sprite.h"
#include <iostream>

Sprite::Sprite(std::string texture, int x, int y, int width, int height, float scale)

{
    // set init values as parameters using this keyword. Needed for getx,y()
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

    // set the sf::texture to be the parameter 'texture'
    this->texture = new sf::Texture;
    this->texture->loadFromFile(texture);

    // use this texture for the displayed sprite
    sprite = new sf::Sprite;
    sprite->setTexture(*(this->texture));

    // set the current texture rect for dynamic sprites
    sprite->setTextureRect(sf::IntRect(0, 0, width, height));

    // change the size of the sprite to be drawn correctly in the render window
    sprite->setScale(scale, scale);

    // set the position of the sprite
    // position always called after scale to make sure everything is in correct pos
    sprite->setPosition(x, y);

    // set the animation values to play the idle animation on init
    currentFrame = 0;
    numFrames = 7;
    row = 0;
}


Sprite::~Sprite()
{
    delete texture;
    delete sprite;
}

void Sprite::update(sf::RenderWindow *window)
{
}

void Sprite::updateAnimation(int numFrames, int row)
{
    // change the animation values such that the new values 
    // represent a new animation within the sprite sheet
    currentFrame = 0;
    this->numFrames = numFrames;
    this->row = row;
}

bool Sprite::checkCollision(sf::RenderWindow *window)
{
    // find the bounds of the mouse
    sf::Vector2f mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window));

    // find the bounds of the current sprite
    sf::FloatRect bounds = sprite->getGlobalBounds();

    // return a boolean that defines whether the bounds of the sprite contains the bounds of the mouse
    return bounds.contains(mouse);
}

bool Sprite::animation(bool repeat)
{
    // check whether the current time since the last update is greater than 0.1 seconds
    if (clock.getElapsedTime().asSeconds() > 0.1f)
    
    {
        // if true, restart the clock and update the current frame of the texture rectangle
        clock.restart();

        /* if the current animation is not finished, such that its current frame does not equal the
        number of frames in the animation, update the texture rectangle and iterate the frame+1 */
        if (currentFrame != numFrames)
        {
            /* while the current frame is less than 8, its currently within its first row of animation. 
            update the texture rectangle such that it moves to the right 1 'size' sprite. Keep
            repeating this until it has moved 8 times. */ 
            if (currentFrame < 8)
            {
                sprite->setTextureRect(sf::IntRect(width * currentFrame, height * row, width, height));
                currentFrame++;

            }

            // do the same thing as the previous if statement but increase the row value + 1 size sprite
            else if (currentFrame < 16)
            {
                sprite->setTextureRect(sf::IntRect(width * currentFrame, height * row + height, width, height));
                currentFrame++;
            }

            // do the same thing as the previous if statement but increase the row value + 1 size sprite
            else if (currentFrame < 24)
            {
                sprite->setTextureRect(sf::IntRect(width * currentFrame, height * row + 2*height, width, height));
                currentFrame++;
            }
        }
        /* if the current animation is finished, use the parameter 'repeat' to either repeat the current animation
        or set update the animation values such that the idle animation is played instead */
        else
        {
            if (repeat == true)
            {
                // set current frame to 0 IF the animation needs to be repeated
                currentFrame=0;
            }
            else
                // if not repeated, play idle animation
                updateAnimation(7, 0);
                return true;
        }
        
    }
    return false;
}

void Sprite::draw(sf::RenderWindow *window)
{
    window->draw(*sprite);
}

int Sprite::getX()
{
    return x;
}

int Sprite::getY()
{
    return y;
}


void Sprite::setPos(int x, int y)
{
    sprite->setPosition(x, y);
}

void Sprite::move(int d)
{
    sprite->setPosition(sprite->getPosition().x+d,sprite->getPosition().y);
}

void Sprite::flip()
{
    // set x to be negative values of itself, y stays the same
    sprite->scale(-1.f, 1.f);
}

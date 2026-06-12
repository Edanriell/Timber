// Include important libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

// Make code easier to type with "using namespace"
using namespace sf;

// This is where our game starts from
int main() {
    // Create a video mode object - SFML 3.0 uses Vector2u
    VideoMode vm(Vector2u(1920, 1080));

    // Create and open a window for the game
    RenderWindow window(vm, "Timber!!!", State::Windowed);

    // Create a texture to hold a graphic on the GPU
    Texture textureBackground;

    // Load a graphic into the texture with error checking
    if (!textureBackground.loadFromFile("../graphics/background.png")) {
        // Handle error - texture failed to load
        return -1;
    }

    // Create a sprite and attach the texture to the sprite
    Sprite spriteBackground(textureBackground);

    // Set the spriteBackground to cover the screen
    spriteBackground.setPosition(Vector2f(0.0f, 0.0f));

    // Make a tree sprite
    Texture textureTree;
    if (!textureTree.loadFromFile("../graphics/tree.png")) {
        return -1;
    }
    Sprite spriteTree(textureTree);
    spriteTree.setPosition(Vector2f(810.0f, 0.0f));

    // Prepare the bee
    Texture textureBee;
    if (!textureBee.loadFromFile("../graphics/bee.png")) {
        return -1;
    }
    Sprite spriteBee(textureBee);
    spriteBee.setPosition(Vector2f(0.0f, 800.0f));

    // Is the bee currently moving ?
    bool beeActive = false;

    // How fast can the bee fly
    float beeSpeed = 0.0f;

    // Make 3 cloud sprites from 1 texture
    Texture textureCloud;
    // Load texture
    if (!textureCloud.loadFromFile("../graphics/cloud.png")) {
        return -1;
    }
    // 3 New sprites with the same texture
    Sprite spriteCloud1(textureCloud);
    Sprite spriteCloud2(textureCloud);
    Sprite spriteCloud3(textureCloud);
    // Position the clouds on the left of the screen at different heights
    spriteCloud1.setPosition(Vector2f(0.0f, 0.0f));
    spriteCloud2.setPosition(Vector2f(0.0f, 250.0f));
    spriteCloud3.setPosition(Vector2f(0.0f, 500.0f));
    // Are the clouds currently on screen?
    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;
    // How fast is each cloud ?
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

    // Variables to control time itself
    Clock clock;

    while (window.isOpen()) {
        /*
        **************************************** Handle the players input
        ****************************************
        */
        // Process events - SFML 3.0 approach
        while (const std::optional<Event> event = window.pollEvent()) {
            // Check for specific event types using getIf
            if (const auto *closeEvent = event->getIf<Event::Closed>()) {
                window.close();
            }
        }

        // Handle keyboard input
        if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
            window.close();
        }

        /*
        **************************************** Update the scene
        ****************************************
        */

        // Measure time
        // delta time, is time between two updates
        Time dt = clock.restart();

        // Setup the bee
        if (!beeActive) {
            // How fast is the bee
            srand((int) time(0));
            beeSpeed = (rand() % 200) + 200;

            // How high is the bee
            srand((int) time(0) * 10);
            float height = (rand() % 1350) + 500;
            spriteBee.setPosition(Vector2f(2000.0f, height));
            beeActive = true;
        } else {
            // Move the bee
            spriteBee.setPosition(Vector2f(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()),
                                           spriteBee.getPosition().y));
            // Has the bee reached the left-hand edge of the screen ?
            if (spriteBee.getPosition().x < -100) {
                // Set it up ready to be a whole new bee next frame
                beeActive = false;
            }
        }

        // Manage the clouds
        // Cloud 1
        if (!cloud1Active) {
            // How fast is the cloud
            srand((int) time(0) * 10);
            cloud1Speed = (rand() % 200);

            // How high is the cloud
            srand((int) time(0) * 10);
            float height = (rand() % 150);
            spriteCloud1.setPosition(Vector2f(-200.0f, height));
            cloud1Active = true;
        } else {
            spriteCloud1.setPosition(Vector2f(spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()),
                                              spriteCloud1.getPosition().y));

            // Has the cloud reached the right hand edge of the screen ?
            if (spriteCloud1.getPosition().x > 1920) {
                // Set it up ready to be a whole new cloud next frame
                cloud1Active = false;
            }
        }

        // Cloud2
        if (!cloud2Active) {
            // How fast is the cloud
            srand((int) time(0) * 20);
            cloud2Speed = (rand() % 200);

            // How hight is the cloud
            srand((int) time(0) * 20);
            float height = (rand() % 300) - 150;
            spriteCloud2.setPosition(Vector2f(-200.0f, height));
            cloud2Active = true;
        } else {
            spriteCloud2.setPosition(Vector2f(spriteCloud2.getPosition().x + (cloud2Speed * dt.asSeconds()),
                                              spriteCloud2.getPosition().y));

            // Has the cloud reached the right hand of the screen ?
            if (spriteCloud2.getPosition().x > 1920) {
                // Set it up ready to be a whole new cloud next frame
                cloud2Active = false;
            }
        }

        if (!cloud3Active) {
            // How fast is the cloud
            srand((int) time(0) * 30);
            cloud3Speed = (rand() % 200);

            // How high is the cloud
            srand((int) time(0) * 30);
            float height = (rand() % 450) - 150;
            spriteCloud3.setPosition(Vector2f(-200.0f, height));
            cloud3Active = true;
        } else {
            spriteCloud3.setPosition(Vector2f(spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()),
                                              spriteCloud3.getPosition().y));

            // Has the cloud reached the right hand ednge of the screen ?
            if (spriteCloud3.getPosition().x > 1920) {
                // Set it cloud to be a whole new cloud next frame
                cloud3Active = false;
            }
        }

        /*
        **************************************** Draw the scene
        ****************************************
        */

        // Clear everything from the last frame
        window.clear();

        // Draw our game scene here
        window.draw(spriteBackground);

        // Draw the clouds
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);

        // Draw the tree
        window.draw(spriteTree);

        // Draw the insect
        window.draw(spriteBee);

        // Show everything we just drew
        window.display();
    }

    return 0;
}

// 110

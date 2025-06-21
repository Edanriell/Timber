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

        /*
        **************************************** Draw the scene
        ****************************************
        */

        // Clear everything from the last frame
        window.clear();

        // Draw our game scene here
        window.draw(spriteBackground);

        // Show everything we just drew
        window.display();
    }

    return 0;
}

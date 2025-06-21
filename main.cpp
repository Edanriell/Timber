// Include important libraries here
#include <SFML/Graphics.hpp>

// Make code easier to type with "using namespace"
using namespace sf;

// This is where our game starts from
int main() {
    // Create a video mode object VideoMode vm(1920, 1080);
    VideoMode vm(Vector2u(1920, 1080));

    // Create and open a window for the game
    RenderWindow window(vm, "Timber!!!", State::Windowed);

    while (window.isOpen()) {
        /*
        **************************************** Handle the players input
        ****************************************
        */
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
        // Show everything we just drew
        window.display();
    }

    return 0;
}

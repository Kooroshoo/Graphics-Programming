#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>


int main()
{
    // create the window
    sf::Window window(sf::VideoMode(800, 800), "OpenGL", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);

    // activate the window
    window.setActive(true);

    // load resources, initialize the OpenGL states, ... =======================================================================




    // -------------------------------------------------------------------------------------------------------------------------
    
    // Animation variables
    float time = 0.0f;
    const float animationSpeed = 5.0f; // Speed of color change

    // run the main loop
    bool running = true;
    while (running)
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
            {
                // end the program
                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {
                // adjust the viewport when the window is resized
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

        // Increase time for smooth color change
        time += 0.01f; 

        // clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // draw... ==============================================================================================================

        glClearColor(std::sin(time * animationSpeed), 0.0, 0, 0);






        // ----------------------------------------------------------------------------------------------------------------------

        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }

    // release resources... =====================================================================================================





    // --------------------------------------------------------------------------------------------------------------------------

    return 0;
}
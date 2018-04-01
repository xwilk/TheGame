#include "Game.hpp"
#include "Logging.hpp"


int main()
try
{
    Game game{};
    game.run();

    return 0;
}
catch (const std::runtime_error& e)
{
    logSDLError(std::cout, e.what());
}

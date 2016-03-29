#include "Tutorials/AdvancedTexturing.h"
#include "Tutorials/RenderingGeometry.h"
#include "Tutorials/ComputerGraphics.h"

#include <GLFW/glfw3.h>

int main() {

    BaseApplication* app = new ComputerGraphics();
    if (app->startup())
        app->run();
    app->shutdown();

	return 0;
}

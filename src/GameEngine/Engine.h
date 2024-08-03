#include "GameEngine.h"

namespace Game236   {

class Engine : public GameEngine {
    public:
        Engine();
        Engine(int width, int height);

        virtual void run();

        private:

        const int WIDTH = 90;
        const int HEIGHT = 70;
        bool _running;
        std::shared_ptr<RenderEngine> renderer;
        std::shared_ptr<EventManager> eventManager;
};
}
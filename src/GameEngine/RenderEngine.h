

#ifndef RENDER_ENGINE_H
#define RENDER_ENGINE_H

#include <string>
#include <queue>
#include <memory>

namespace Game236 {

class RenderEngine {
  public:
    RenderEngine();
    RenderEngine(int width, int height);
    ~RenderEngine();

    /**
     * pops everything from render queue and creates a framebuffer 
     * and pushes buffer to screen. if no renderables in renderQueue,
     * the frame should not change
     */
    void render();//pops everything from render queue and creates a framebuffer

    /**
     * push rendrables to the render buffer for the next frame.
     */
    //TODO: this needs to be split from render() somehow so we can control who can push to buffer and who can render
    void pushRenderable(std::string* renderable);
  
  private:
    void init();
    void generateFrame();

    //keeps a frame Buffer to push to screen
    //keeps a render queue
    const int WIDTH = 90;
    const int HEIGHT = 70;
    int _width;
    int _height;
    std::shared_ptr<std::queue<std::string*>> renderQueue;
    std::shared_ptr<std::string> frame;
    std::shared_ptr<std::string> emptyFrame;
};
}
#endif
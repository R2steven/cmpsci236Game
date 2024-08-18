#ifndef GAME236_CONSOLE_RENDERER_H
#define GAME236_CONSOLE_RENDERER_H

#include <memory>
#include <queue>
#include <vector>
#include <unordered_map>

#include "RenderEngine.h"

namespace Game236 {

struct box {
  int x;
  int y;
  int x_end;
  int y_end;
  int x_size;
  int y_size;
};

class ConsoleRenderer : public RenderEngine {
  public:
    ConsoleRenderer();
    ConsoleRenderer(int width, int height);
    ~ConsoleRenderer();

    virtual void render();
    //virtual void registerScene(Scene<std::string> nScene);
    virtual void registerRenderable(Renderable<std::string>* nObj);
    //virtual void unregisterScene(std::string sKey);
    virtual void unregisterRenderable(std::string rKey);
    //TODO: create an event which can add render objects to the world.
    virtual void updateWorld(std::string rKey, char command);

  private:
    /**
     * returns a 1d index in underlaying render frame from 2d coords.
     * 
     * underlaying arrays are row-major
     */
    inline int index(int x, int y);

    /**
     * returns a 1d index based on a row-major matrix with rowSize
     */
    inline int rMajIndex(int x, int y, int rowSize);

    /**
     * initialize the renderEngine backend
     */
    void init();

    /**
     * takes all objects from world queue and draw them to the backFrame,
     * then pushes the new frame to frontFrame.
     */
    void generateNextFrame();

    /**
     * draws a given object to the backFrame
     */
    void drawToFrame(Renderable<std::string>* object);

    /**
     * helper to clear the frame. leaves the border
     */
    void clearFrame(char* frame);

    /**
     * clamps an object's renderbox to the window
     */
    box fitToWindow(Renderable<std::string>* object);


    static const int WIDTH = 115; //this just fit in my console pretty well
    static const int HEIGHT = 28; //this just fit in my console pretty well
    static const int B_WIDTH = 1; //window border width
    static const int NLINE_WIDTH = 1; //newline for formatting (TODO: should be replaced with std::cout.setw())

    // window details
    int _width;
    int _height;
    // total frame size with boarder
    int _frameWidth;
    int _frameHeight;

    // size of a pixelBuffer
    int _size;

    bool _redraw;

    // RenderQueue should maybe be event queue and handle update events?
    std::unique_ptr<std::queue<std::string>> renderQueue; //obj id(s) to put to screen
    // world models the current frame/scene //TODO: enable removal of single element?
    std::unique_ptr<std::vector<Renderable<std::string>*>> world;
    // this map controls the lifespan of loaded renderables
    std::unique_ptr<std::unordered_map
      <std::string,std::unique_ptr<Renderable<std::string>>>> renderableObjs;

    // these are the renderBuffers
    char* frontFrame;
    char* backFrame;
};
}
#endif
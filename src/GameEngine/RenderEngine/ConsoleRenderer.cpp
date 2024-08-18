
#include <iostream>
#include <vector>
#include <string>

#include "ConsoleRenderer.h"
#include "base.h"

namespace Game236 {

  ConsoleRenderer::ConsoleRenderer()  
  :ConsoleRenderer::ConsoleRenderer(WIDTH, HEIGHT)
  {}

  ConsoleRenderer::ConsoleRenderer(int width, int height) 
  : renderQueue(std::make_unique<std::queue<std::string>>()),
    world(std::make_unique<std::vector<Renderable<std::string>*>>()),
    renderableObjs(std::make_unique<std::unordered_map
      <std::string,std::unique_ptr<Renderable<std::string>>>>())
  {
    _width = width;
    _height = height;
    _frameWidth = _width + 2*B_WIDTH + NLINE_WIDTH;
    _frameHeight = _height + 2*B_WIDTH;
    _size = _frameWidth * _frameHeight;
    init();
  }

  ConsoleRenderer::~ConsoleRenderer() {
    delete frontFrame;
    delete backFrame;
  }

  /**void ConsoleRenderer::registerScene(Scene<std::string> nScene)  {
    for(int i = 0; i < nScene.objData->size(); i++)  {
      renderableObjs->insert(nScene.objData->at(i));//should transfer mem management duties here
    }
    renderableObjs->insert(nScene); //polymorphism to fix (remove templates)
  }*/

  void ConsoleRenderer::registerRenderable(Renderable<std::string>* nObj)  {
    renderableObjs->insert(
      {nObj->id, std::unique_ptr<Renderable<std::string>>(nObj)}
      );
  }

  /**void ConsoleRenderer::unregisterScene(std::string sKey) {

  }*/

  void ConsoleRenderer::unregisterRenderable(std::string rKey)  {
    renderableObjs->erase(rKey);
  }

  void ConsoleRenderer::updateWorld(std::string rKey, char command) {
    switch(command)  {
      case 'a': world->push_back(renderableObjs->find(rKey)->second.get());
        break;
      case 'r': 
        break;
    }
    _redraw = true;
  }

  void ConsoleRenderer::render(){
    if(_redraw)  {
      generateNextFrame();
      system("cls"); //we would like to eliminate this -- its slow and dangerous
      std::cout.write(frontFrame, _size);
      std::cout.flush();
      _redraw = false;
    }
  }

  inline int ConsoleRenderer::index(int x, int y) {
    return y * _frameWidth + x;
  }

  inline int ConsoleRenderer::rMajIndex(int x, int y, int rowSize) {
    return y * rowSize + x;
  }

  void ConsoleRenderer::init() {
    frontFrame = new char[_size];
    int i;
    for(auto y = 0; y < _frameHeight; y++) {
      for(auto x = 0; x < _frameWidth; x++) {
        i = index(x,y);
        if(y == 0 || y == _frameHeight - B_WIDTH) {
          frontFrame[index(x,y)] = '+';
        }
        else if(x == 0 || x == _frameWidth - B_WIDTH - NLINE_WIDTH) {
          frontFrame[index(x,y)] = '+';
        }
        else{
          frontFrame[index(x,y)] = ' ';
        }

        if(x == _frameWidth-NLINE_WIDTH) {
          frontFrame[index(x,y)] = '\n';
        }
      }
    }

    backFrame = new char[_size];
    std::copy(frontFrame, frontFrame+_size, backFrame);
  }

  void ConsoleRenderer::generateNextFrame()  {
    clearFrame(backFrame);

    for(auto obj = world->begin(); obj < world->end(); obj++) {
      drawToFrame(*obj); 
    }

    std::swap(frontFrame,backFrame);
  }

  void ConsoleRenderer::drawToFrame(Renderable<std::string>* object) {

    box win = fitToWindow(object);
    std::string* data = object->objData;
    int datai;

    for(auto y = 0; y < win.y_size ; y++) {
      for(auto x = 0; x < win.x_size; x++) {

        datai =  rMajIndex(x,y,win.x_size);

        if(datai < data->size()) {

          if('\n' == data->at(datai))  {
            break;
          }

          backFrame[index(x + win.x + B_WIDTH, y + win.y + B_WIDTH)] = 
            data->at(datai);
        }

        else {
          return;
          }
      }
    }
  }

  void ConsoleRenderer::clearFrame(char* frame)  {
    for(auto y = 1; y < _height; y++) {
      for(auto x = 1; x < _width; x++) {
        frame[index(x,y)] = ' ';
      }
    }
  }

  box ConsoleRenderer::fitToWindow(Renderable<std::string>* object) {
    box ret = {
      clamp(1, _width+B_WIDTH, object->x_pos),
      clamp(1, _height+B_WIDTH, object->y_pos),
      clamp(1, _width+B_WIDTH, object->x_pos + object->x_size),
      clamp(1, _height+B_WIDTH, object->y_pos + object->y_size),
    };
    ret.x_size = std::abs(ret.x_end-ret.x) + 1;
    ret.y_size = std::abs(ret.y_end-ret.y) + 1;
    return ret;
  }
}
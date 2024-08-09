
#include <iostream>

#include "RenderEngine.h"

namespace Game236 {

  RenderEngine::RenderEngine()  
  :RenderEngine::RenderEngine(WIDTH, HEIGHT)
  {}

  RenderEngine::RenderEngine(int width, int height) {
    _width = width;
    _height = height;
    renderQueue = std::make_shared<std::queue<std::string*>>();//TODO: smart pointer this
    init();
  }

  RenderEngine::~RenderEngine() {
  }

  void RenderEngine::init() {
    emptyFrame = std::make_shared<std::string>((size_t)(_width*_height)+1,' ');

    (*emptyFrame)[0] = '\n';

    for(int i = 1; i < _height; i++)  {
      //(*emptyFrame)[(i-1)*_width] = '+';
      (*emptyFrame)[(i*_width)-1] = '+';
      (*emptyFrame)[i*_width] = '\n';
    }

    frame = std::make_shared<std::string>(*emptyFrame);
  }

  void RenderEngine::pushRenderable(std::string* renderable)  {
    renderQueue->push(renderable);
  }

  void RenderEngine::render(){
    if(!renderQueue->empty())  {
      generateFrame();
      system("cls");
      std::cout << *frame;
    }
  }

  void RenderEngine::generateFrame()  {
    int pointer = 1;
    std::string* temp;
    while(!renderQueue->empty())  {
      temp = renderQueue->front();
      frame->replace(pointer, temp->size(), *temp);
      renderQueue->pop();
      pointer+=temp->size();
    }
  }

}
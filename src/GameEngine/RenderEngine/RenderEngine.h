

#ifndef GAME236_RENDER_ENGINE_H
#define GAME236_RENDER_ENGINE_H

#include <string> //I want to figure out how to get this out of the interface

#include "Renderable.h"

namespace Game236 {

/**
 * rendereEngine should handle all things related to rendering views, frames,
 * and objects.
 */

class RenderEngine {
  public:

    virtual void render() = 0;

    /**
     * figure out how to remove the string template thing here... probably move 
     * away from templates entirely?
     */
    //virtual void registerScene(Scene<std::string> nScene) = 0;
    virtual void registerRenderable(Renderable<std::string>* nObj) = 0;
    //virtual void unregisterScene(std::string sKey) = 0;
    virtual void unregisterRenderable(std::string rKey) = 0;
    virtual void updateWorld(std::string rKey, char command) = 0;
};
}
#endif
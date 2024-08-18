
#include <vector>
#include <string>

#include "Renderable.h"


using namespace Game236;

/**
 * this could probably be done through a scene builder in render engine
 * or related component
 */
Scene<std::string>* makeCellScene() {
  std::vector<Renderable<std::string>*> components = {};

  Renderable<std::string>* storyPrompt  = new Renderable<std::string>(
    "Cell Story Point",
    0,0,90,1,
    std::string("You begin your journey in a super cell on the prison asteroid 23")
  );
  components.push_back(storyPrompt);

  Renderable<std::string>* storyActions  = new Renderable<std::string>(
    "Cell action options",
    0,60,90,2,
    std::string("1) charm the guard\n2) overpower the guard")
  );
  components.push_back(storyActions);

  Scene<std::string>* cellScene = new Scene<std::string>(
    "Cell Scene",
    components
  );

  return cellScene;
}

Renderable<std::string>* makeCellRenderable() {
  Renderable<std::string>* storyPrompt  = new Renderable<std::string>(
    "Cell Story Point",
    3,10,90,1,
    std::string("You begin your journey in a super cell on the prison asteroid 23. Hello World!")
    );
    return storyPrompt;
}
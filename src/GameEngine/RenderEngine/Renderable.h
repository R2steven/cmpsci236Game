#ifndef GAME236_RENDERABLE_H
#define GAME236_RENDERABLE_H

#include <string>
#include <vector>


namespace Game236 {

/**
 * Renderable defines an object the RenderEngine is capable of 
 * rendering to screen.
 */
template <class T>
class Renderable  {
  public:
    std::string id;

    int x_pos;
    int y_pos;
    int x_size;
    int y_size;

    T* objData;

    Renderable(std::string id, T& data)
    : Renderable::Renderable(id,0,0,0,0,data)
    {}

    Renderable(std::string id, int x, int y, int width, int height, T& data)
    :id(id), x_pos(x), y_pos(y), x_size(width), y_size(height), objData(new T(data))
    {}

    ~Renderable() {
      delete objData;
    }

    bool operator==(const Renderable& other) const  {
      return (this->id==other.id);
    }
};

template<class T>
class Scene : public Renderable<std::vector<Renderable<T>*>> {
  public:
    Scene(std::string id, std::vector<Renderable<T>*>& objs) 
    : Renderable<std::vector<Renderable<T>*>>::Renderable(id,objs)
    {}
};


template<class T>
class RenderableHashFunc{
  
  size_t operator()(const std::string& key) const{
    return std::hash<std::string>()(key);
  }

  size_t operator()(const Renderable<T>& obj) const{
    return std::hash<std::string>()(obj.id);
  }
};


/**
 * factory pattern. NOT FINISHED
 * takes in a renderable obj file and builds a renderable struct.
 * 
 * we may implement/use something like a json parser to enable loading 
 * renderables.
 */
template<class T>
class RenderableFactory {
  public:
    static Renderable<T> getRenderable(char* input);
  private:
};

}
#endif
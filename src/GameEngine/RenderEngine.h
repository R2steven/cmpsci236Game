

#ifndef RENDER_ENGINE_H
#define RENDER_ENGINE_H


class RenderEngine {
    public:
        RenderEngine(int width, int height);

        /**
         * pops everything from render queue and creates a framebuffer 
         * and pushes buffer to screen. if no renderables in renderQueue,
         * the frame should not change
         */
        virtual void render() = 0;//pops everything from render queue and creates a framebuffer

        /**
         * push rendrables to the render buffer for the next frame.
         */
        //TODO: this needs to be split from render() somehow so we can control who can push to buffer and who can render
        void pushRenderables();
    
    private:
        //keeps a frame Buffer to push to screen
        //keeps a render queue
        int _width;
        int _height;
};

#endif
#pragma once

class Camera;
struct GLFWwindow;

class BaseApplication {
public:

    BaseApplication() : m_window(nullptr) {}
    virtual ~BaseApplication();

    void run();

	void Clear();
    
    virtual bool startup() = 0;
    virtual void shutdown() = 0;

    virtual bool update(float deltaTime) = 0;
    virtual void draw() = 0;
	virtual void drawGUI() {}

protected:

    virtual bool createWindow(const char* title, int width, int height);
    virtual void destroyWindow();

    GLFWwindow* m_window;
    Camera*     m_camera;
};
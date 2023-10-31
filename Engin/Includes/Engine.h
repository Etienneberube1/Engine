#pragma once
#include <string>
#include "IInput.h"
#include "ILogger.h"
#include "IGraphics.h"
#include "IWorld.h"
#include "IAudio.h"
#include "Color.h"
#include "IScene.h"
#include "BaseScene.h"
#include "MenuScene.h"
#include "WorldService.h"

namespace project {
	class Engine final {

    // https://stackoverflow.com/questions/1008019/how-do-you-implement-the-singleton-design-pattern
    public:
        static Engine& Get()
        {
            static Engine instance; // Guaranteed to be destroyed.
            // Instantiated on first use.
            return instance;
        }
    private:
        Engine() {}                    

    public:
        Engine(Engine const&) = delete;
        void operator=(Engine const&) = delete;

    

	public:

		bool Init(const char* name, int w, int h);
		void Start(void);

		IWorld* World() const { return m_World; }
		IAudio* Audio() const { return m_Audio; }
		IInput* Input() const { return m_Input; }
        IGraphics* Graphics() const { return m_Graphics; }
        IILogger* Logger() const { return m_Logger; }
	private:
		void ProcessInput(void);
		void Update(float dt);	
		void Render(void);
		void Shutdown(void);
		void LoadTexture(void);
		void LoadAudio(void);

		IGraphics* m_Graphics = nullptr;
		IInput* m_Input = nullptr;
		IILogger* m_Logger = nullptr;
		Entity* m_Square1 = nullptr;
		IWorld* m_World = nullptr;
		IAudio* m_Audio = nullptr;
		bool m_IsInit = false;

		BaseScene* m_baseScene = nullptr;
		MenuScene* m_menuScene = nullptr;
	};
}
#pragma once
#include "Atlas.h"
#include <map>
#include <string>
#include <IUpdatable.h>

#include <RectI.h>
#include <RectF.h>


namespace project
{

    class Entity;

    struct AnimationClip
    {
        int start;
        int count;
        float delay;
    };

    class Animation final : public Atlas, public IUpdatable
    {
    public:
        virtual ~Animation() = default;
        Animation();
        Animation(Entity* parent);

        void Update(float dt) override;

        void Init(int frameInRows, int frameWidth, int frameHeight);
        void AddClip(const std::string& name, int start, int count, float delay);
        void Stop();
        void Play(const std::string& name, bool loop);

    private:
        void UpdateFrame();

        std::map<std::string, AnimationClip> m_Clips;

        int m_FrameInRowCount = 0;
        int m_FrameWidth = 0;
        int m_FrameHeight = 0;
        int m_StartFrame = 0;
        int m_EndFrame = 0;
        int m_LastFrame = 0;
        float m_Delay = 0.0f;
        float m_Elapsed = 0.0f;
        bool m_Playing = false;
        bool m_Loop = false;
        int m_CurrentFrame = 0;
        std::string m_CurrentClip;
    };
}
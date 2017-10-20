#pragma
#ifndef SKY_PASS_H
#define SKY_PASS_H

#include <Engine/Source/RenderPhase.h>

#include <Engine/Source/Shader.h>

#include <memory>

namespace Flux {
    class SkyPass : public RenderPhase
    {
    public:
        SkyPass();

        void render(const Scene& scene) override;

    private:
        std::unique_ptr<Shader> skyboxShader;
        std::unique_ptr<Shader> skysphereShader;
    };
}

#endif /* SKY_PASS_H */
#pragma once

#include "RenderPhase.h"

#include "Shader.h"

#include <memory>

namespace Flux {
    class SkyPass : public RenderPhase
    {
    public:
        SkyPass();

        void Resize(const Size& windowSize) override;

        void render(RenderState& renderState, const Scene& scene) override;

    private:
        Shader skyboxShader;
        Shader skysphereShader;
        Shader skyShader;
        Shader texShader;
    };
}

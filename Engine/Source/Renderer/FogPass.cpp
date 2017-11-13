#include "Renderer/FogPass.h"

#include "Renderer/RenderState.h"

#include "TextureUnit.h"
#include "Texture.h"
#include "Framebuffer.h"

namespace Flux {
    FogPass::FogPass() : RenderPhase("Fog")
    {
        shader = std::unique_ptr<Shader>(Shader::fromFile("res/Shaders/Quad.vert", "res/Shaders/Fog.frag"));
    }

    void FogPass::SetSource(const Texture* source)
    {
        this->source = source;
    }

    void FogPass::SetDepthMap(const Texture* depthMap)
    {
        this->depthMap = depthMap;
    }

    void FogPass::SetTarget(const Framebuffer* target)
    {
        this->target = target;
    }

    void FogPass::render(const Scene& scene)
    {
        nvtxRangePushA(getPassName().c_str());

        shader->bind();

        source->bind(TextureUnit::TEXTURE0);
        shader->uniform1i("tex", TextureUnit::TEXTURE0);
        depthMap->bind(TextureUnit::TEXTURE1);
        shader->uniform1i("depthMap", TextureUnit::TEXTURE1);
//        shader->uniform3f("cameraPos", scene.getMainCamera()->getComponent<Transform>()->position);
        target->bind();
        RenderState::drawQuad();

        nvtxRangePop();
    }
}
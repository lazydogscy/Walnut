#pragma once

#include <glm/glm.hpp>

#include "Texture.h"

namespace Walnut
{
    class SubTexture2D
    {
    public:
        SubTexture2D(const Ref<Texture2D>& texture, const glm::vec2& min, const glm::vec2& max);

        const Ref<Texture2D> GetTexture() const { return mTexture; }
        const glm::vec2* GetTexCoords() const { return mTexCoords; }

        static Ref<SubTexture2D> CreateFromCoords(const Ref<Texture2D>& texture, const glm::vec2& coords, const glm::vec2& cellSize, const glm::vec2& spriteSize = { 1, 1 });
    private:
        Ref<Texture2D> mTexture;

        glm::vec2 mTexCoords[4];
    };
}
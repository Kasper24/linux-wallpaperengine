#pragma once

#include "WallpaperEngine/Core/Objects/Effects/CFBO.h"
#include "WallpaperEngine/Core/Objects/CImage.h"
#include "WallpaperEngine/Assets/ITexture.h"

using namespace WallpaperEngine::Assets;

namespace WallpaperEngine::Render
{
    class CFBO : public ITexture
    {
    public:
        CFBO (std::string name, ITexture::TextureFormat format, float scale, uint32_t realWidth, uint32_t realHeight, uint32_t textureWidth, uint32_t textureHeight);

        const std::string& getName () const;
        const float& getScale () const;
        const ITexture::TextureFormat getFormat () const override;
        GLuint getFramebuffer () const;
        GLuint getDepthbuffer () const;
        const GLuint getTextureID (int imageIndex) const override;
        const uint32_t getTextureWidth () const override;
        const uint32_t getTextureHeight () const override;
        const uint32_t getRealWidth () const override;
        const uint32_t getRealHeight () const override;
        const glm::vec4* getResolution () const override;
        const bool isAnimated () const override;

    private:

        GLuint m_framebuffer;
        GLuint m_depthbuffer;
        GLuint m_texture;
        glm::vec4 m_resolution;
        float m_scale;
        std::string m_name;
        ITexture::TextureFormat m_format;
    };
};

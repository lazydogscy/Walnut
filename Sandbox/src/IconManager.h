#pragma once 

#include "Walnut/Asset/PublicSingleton.h"
#include "Walnut/Renderer/Texture.h"

#include <unordered_map>

namespace Walnut
{
    class IconManager : public PublicSingleton<IconManager>
    {
    public:
        IconManager();

        Ref<Texture2D> LoadOrFindTexture(const std::string& path)
        {
            if (iconLibrary.find(path) != iconLibrary.end())
            {
                return iconLibrary[path];
            }
            iconLibrary[path] = Texture2D::Create(path);
            return iconLibrary[path];
        }

        void Add(const std::string& name, const Ref<Texture2D>& mem)
        {
            WN_CORE_ASSERT(iconLibrary.find(name) == iconLibrary.end() && "Already have this member in Library!");
            iconLibrary[name] = mem;
        }
        [[nodiscard]] Ref<Texture2D> Get(const std::string& name)
        {
            WN_CORE_ASSERT(iconLibrary.find(name) != iconLibrary.end() && "Can't find this member in Library!");
            return iconLibrary[name];
        }

        Ref<Texture2D> GetNullTexture() { return Get("NullTextrue"); }
        Ref<Texture2D> GetDirectoryIcon() { return Get("DirectoryIcon"); }
        Ref<Texture2D> GetFileIcon() { return Get("FileIcon"); }
        Ref<Texture2D> GetSettingIcon() { return Get("SettingIcon"); }
        Ref<Texture2D> GetPlayIcon() { return Get("PlayIcon"); }
        Ref<Texture2D> GetStopIcon() { return Get("StopIcon"); }
    private:
        std::unordered_map<std::string, Ref<Texture2D>> iconLibrary;
    };
}
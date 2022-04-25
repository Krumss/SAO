#include "contentBrowserPanel.h"
#include "imgui.h"
#include <filesystem>

static const std::filesystem::path s_TexturePath = "textures";

ContentBrowserPanel::ContentBrowserPanel()
    : m_CurrentDir(s_TexturePath) { }
ContentBrowserPanel::~ContentBrowserPanel() { }

void ContentBrowserPanel::OnImGuiRender()
{
    ImGui::Begin("Content Browser");

    if (m_CurrentDir != std::filesystem::path(s_TexturePath))
    {
        if (ImGui::Button("<-"))
        {
            m_CurrentDir = m_CurrentDir.parent_path();
        }
        
    }
    

    for (auto &p : std::filesystem::directory_iterator(m_CurrentDir))
    {
        const auto& path = p.path();
        auto relativePath = std::filesystem::relative(path, s_TexturePath);
        std::string filenameString = relativePath.filename().string();
        if (p.is_directory())
        {
            if (ImGui::Button(filenameString.c_str()))
            {
                m_CurrentDir /= path.filename();
            }
        }
        else
        {
            if (ImGui::Button(filenameString.c_str()))
            {
            }
            
        }
        
        
    }

    ImGui::End();
}
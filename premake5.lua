workspace "SAO"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release", 
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {
	["GLFW"] = "vendor/GLFW/include", 
	["Glad"] = "vendor/Glad/include",
	["ImGui"] = "vendor/imgui",
	["glm"] = "vendor/glm"
}

include "vendor/GLFW"
include "vendor/Glad"
include "vendor/imgui"


project "SAO"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h", 
		"src/**.cpp",
		"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl",
        "src/sprite.fs",
        "src/sprite.vs",
		"textures/**",
		"shaders/**",
	}

	includedirs
	{
		"src/**",
        "shaders",
		"textures",
		"%{IncludeDir.GLFW}", 
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	defines
	{
        "GLFW_INCLUDE_NONE"
	}

	postbuildcommands
	{
		
	}

	filter "system.windows"

		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines "SAO_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "SAO_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "SAO_DIST"
		buildoptions "/MD"
		optimize "On"

		postbuildcommands
		{
			
		}
--[[
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"SAO/vendor/spdlog/include",
		"SAO/src",
		"%{IncludeDir.glm}"
	}
	
	links
	{
		"SAO"
	}

	defines
	{
		"SAO_PLATFORM_WINDOWS"
	}

	filter "system.windows"

		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines "SAO_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "SAO_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "SAO_DIST"
		buildoptions "/MD"
		optimize "On"
--]]
workspace "Flint"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root
IncludeDir = {}
IncludeDir["GLFW"] = "FlintStoneEngine/vendor/GLFW/include"

include "FlintStoneEngine/vendor/GLFW"

project "FlintStoneEngine"
	location "FlintStoneEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ftpch.h"
	pchsource "FlintStoneEngine/src/ftpch.cpp"

	staticruntime "off"
	runtime "Release"
	buildoptions {"/MD"}

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FT_PLATFORM_WINDOWS",
			"FT_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "FT_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "FT_RELEASE"
		symbols "on"

	filter "configurations:Dist"
		defines "FT_DIST"
		symbols "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	staticruntime "off"
	runtime "Release"
	buildoptions {"/MD"}

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"FlintStoneEngine/vendor/spdlog/include",
		"FlintStoneEngine/src"
	}

	links
	{
		"FlintStoneEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "FT_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "FT_RELEASE"
		symbols "on"

	filter "configurations:Dist"
		defines "FT_DIST"
		symbols "on"
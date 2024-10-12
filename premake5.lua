-- premake5.lua
workspace "CryptoService"
   configurations { "Debug", "Release" }
   
   project "CryptoService"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   architecture "x64"
   targetdir "bin/%{cfg.buildcfg}"

   libdirs { "./external/oatpp/lib" }

   links { "ws2_32" }

   includedirs {
      "./external/oatpp/include",
      "./external/magic_enum/include",
      "./external/toml++/include",
      "./src",
    }

   files { "**.h", "**.hpp", "**.cpp", "**.cc", "**.cx", "**.c" }

   filter "configurations:Debug"
      links { "oatpp_d" }
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      links { "oatpp" }
      defines { "NDEBUG" }
      optimize "On"
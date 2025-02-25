
# NoMoreAPI

A simple DLC unlocker for Steamworks that **doesn't** replace steam_api/steam_api64.dll.

# Installation  

You can use any DLL injector, but for convenience, I recommend [ThirteenAG's Ultimate ASI Loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader) or any DLL/mod loader of your choice.  

### Steps:  
- Download and extract the [ASI Loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader/releases/latest) to the same folder as your target application's `.exe`.  
- Download and extract [NoMoreAPI](https://github.com/KaylinOwO/NoMoreAPI/releases/latest) into the same folder.  
- Boot the game. Simple as that! :D 

#### **Note:** Use the x64 version of both Ultimate ASI Loader and NoMoreAPI if your target application is x64, and the x86 versions if it's 32-bit.  

# Q&A

- #### Why?  
    - The primary reason this exists is that certain DRMs detect and block modified `steam_api` files. Since this does not modify those files, it works fine on applications with such DRMs.  

 - #### Does this work on multiplayer games?
    - Highly depends but in most cases, no. If the game has an anti-cheat this will very likely get you banned. 

 - #### Will this work on X/Y/Z Game?
    - No way to know for sure but I have tested on quite a number of games. If you found one that it doesn't work in then create a GitHub Issue and I'll look into it.

# Credits
- [IcePixelx's silver-bun](https://github.com/IcePixelx/silver-bun) 
- [cursey's safetyhook](https://github.com/cursey/safetyhook)

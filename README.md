# DXUP
## D3D9 and D3D10 -> D3D11 Translation Layer

### Get [latest build here](https://git.froggi.es/joshua/dxup/pipelines) or [tagged builds here](https://github.com/Joshua-Ashton/dxup/releases).

### What's the point?
- The main reason is for [DXVK](https://github.com/doitsujin/dxvk), translation layer D3D11-> Volcano. I'm sure where you can see where this is going ... (linux, wine stuff.)
  - You can use this if you are a lazy gamer and want to access some of the features of the D3D11 by querying the interfaces (and getting some extensions coming soon!)
  - You write a D3D9Ex game and don't want to deal with syncing and other VR issues.
  - You write a D3D9 game and don't want to deal with D3D9Ex pool changes, so you can't get shared resources.

Support for D3D10 is now obsolete on Linux platforms and will not be installed with a script or verb, as this is now done by DXVK.

### How do I use it?
To install DXUP, look for the release on the [public page](https://github.com/Joshua-Ashton/dxup/releases) (for versions with versions) or on the [build server](https://git.froggi.es/joshua/dxup/pipelines)
```
export WINEPREFIX = / path / to / .wine-prefix
winetricks --force setup_dxup_d3d9.verb
```

### How do I build it?
**Simple (Linux Only):**
Use ``./package-release.sh master /your/target/directory --no-package`` to automagically.

**Advanced (Windows in Linux):**

You can use meson to create DLLs:

Windows: ``meson --backend vs2017 --buildtype release build`` in a Visual Studio x86/x64 Command Prompt depending on the arc you wish to build.

Linux: ``meson --cross-file build-win64.txt --buildtype release --prefix /your/dxup/directory build.w64 `` and vice versa for each arc (change 64s to 32s.)

### Screenshots

#### D3D10 (before DXVK got support for D3D10)
![Crysis Warhead Menu](https://i.imgur.com/q1l2gLb.png)
![Crysis Warhead Game](https://i.imgur.com/7yY5bZy.jpg)
![Crysis Warhead Game](https://i.imgur.com/eJbUdxK.jpg)
![Just Cause 2](https://i.imgur.com/mu57Z2O.jpg)
![Just Cause 2](https://i.imgur.com/Q6FoDvj.jpg)
![Just Cause 2](https://i.imgur.com/jGgGrYt.jpg)

# Have fun!


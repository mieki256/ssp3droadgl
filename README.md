ssp3droadgl
===========

Screensaver for Windows that draws pseudo 3D roads, implemented in C++ and OpenGL.

Issue. Does not work on some PCs. Cause unknown.

Screenshots
-----------

![01summer_thumb.png](./screenshots/01summer_thumb.png)
[01summer.png](./screensots/01summer.png)

![02autumn_thumb.png](./screenshots/02autumn_thumb.png)
[02autumn.png](./screensots/02autumn.png)

![03winter_thumb.png](./screenshots/03winter_thumb.png)
[03winter.png](./screensots/03winter.png)

![04night_thumb.png](./screenshots/04night_thumb.png)
[04night.png](./screensots/04night.png)

Install
-------

Copy 1 files to Windows system folder.

* ssp3droadgl.scr

```
Windows 64bit : C:\Windows\SysWOW64\
Windows 32bit : C:\Windows\System32\
```

The screen saver name is "P3D Road GL".

The settings are saved in an ini file.

```
%APPDATA%\ssp3droadgl\ssp3droadgl.ini

Windows10 : C:\Users\(USERNAME)\AppData\Roaming\ssp3droadgl\ssp3droadgl.ini
```

### Extra

ssp3droadglfw.exe is a demonstration program that draws almost as well as this screen saver. Using GLFW.

* 1,2,3,4 key : Draw on/off. tree, slope, BG, beam
* F key : Change framerate. 60, 30, 20 FPS.

Uninstall
---------

Delete files.

```
C:\Windows\SysWOW64\ssp3droadgl.scr
(or C:\Windows\System32\ssp3droadgl.scr)

%APPDATA%\ssp3droadgl\ssp3droadgl.ini
%APPDATA%\ssp3droadgl
```

Build Requirement / Environment
-------------------------------

* Windows10 x64 22H2
* MinGW (gcc 6.3.0)
* windres 2.28 (in binutils package)
* ld 2.28 or objcopy 2.28 (in binutils package)

Build ssp3droadgl.scr

```
cd src
make
```

Build ssp3droadglfw.exe

```
cd src
make -f Makefile.glfw
```

Author
------

[mieki256](https://github.com/mieki256)

License
-------

mieki256が書いた部分は CC0 / Public Domain 扱いということで…。

Reference
---------

[How to Scr: Writing an OpenGL Screensaver for Windows](http://www.cityintherain.com/howtoscr.html)

### Use font

[ProFont for Windows, for Macintosh, for Linux](https://tobiasjung.name/profont/)

### Use library

[nothings/stb: stb single-file public domain libraries for C/C++](https://github.com/nothings/stb)


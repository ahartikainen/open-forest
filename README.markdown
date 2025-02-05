![](https://raw.githubusercontent.com/karamellpelle/open-forest/master/data/meta/screenshots/open-forest-june2018-macos.png "macOS High Sierra, using Ogre v1.11")

# Open Forest


This was originally a fork of an orienteering game I found on GitHub, ["Beat About The Bush]( 
https://github.com/jarvinet/orienteering-game), but it is now completely rewritten.
The old game is still runnable through Open Forest, but then the project will have more dependencies in order to build (i.e. `plib`).

My intention has been to build up a foundation for an open source orienteering game. Despite the sport of orienteering is small, there are multiple commercial orienteering games available (Catching Features, Suunnistussimulaattori, Oriantica). I don't see the point of having so many commercial games for something that probably will not generate enough money for a high-end product. And there are many good programmers/developers in the orienteering community.

Here are some [screenshots](readme/screenshots.markdown) of terrain.

This project builds (on macOS High Sierra as of June 2018) and the libraries are up and running, so collaborative development is absolutely possible. But I should have finished some more work first (I'm in lack of time). The program's structure is based on how I've been writing functional games in Haskell. The thing is to abandon the traditional "main loop" and consider a game as a _World_ (with subworlds) that is iterated by _Iteration_'s. See [computergames.pdf](https://github.com/karamellpelle/grid/blob/master/computergames.pdf). This makes the program flow a lot easier to implement and opens up possibilites that are complicated to do with a traditional main loop. It can be considered as a MVC pattern where _World_ is the model, and _Iteration_'s are control and view.

[Ogre3D](https://www.ogre3d.org/) is used for 3D rendering. It has very good forest rendering capabilities, for example see this [Ogre3D based](https://forums.ogre3d.org/viewtopic.php?f=11&t=35922) game: [clip A](https://youtu.be/4QIHzn1PrxY?t=12m20s), [clip B](https://youtu.be/PWSg4olxaYE?t=5m9s), [clip C](https://youtu.be/CXr82Gtbk1Y?t=1m57s).



## Programming


We shall do modern programming (OpenGL 3.3 Core, C++14, new open source libraries etc.)

### Libraries

Below are suggestions of open source libraries to use. Please add (better) alternatives.

  * graphics          : [**OpenGL**](https://www.opengl.org/wiki/), [**GLEW**](http://glew.sourceforge.net), [**GLFW**](http://www.glfw.org) (or [glad](https://github.com/Dav1dde/glad)?, see [Loading Library](https://www.khronos.org/opengl/wiki/OpenGL_Loading_Library))  
  * sound             : [**ALURE**](http://kcat.strangesoft.net/alure.html)  
  * input             : [**GLFW**](http://www.glfw.org)  
  * GUI               : [**turbobadger**](https://github.com/fruxo/turbobadger)  
  * config            : [**YAML**](http://yaml.org), [tinyxml2](http://www.grinninglizard.com/tinyxml2)  
  * UDP network       : [???](http://www.codeofhonor.com/blog/choosing-a-game-network-lib)  
  * 3D rendering      : [**OGRE**](http://www.ogre3d.org)  
  * 2D rendering      : [**nanovg**](https://github.com/memononen/nanovg)  
  * font rendering    : (using turbobadger or nanovg)  
  * packaging         : [gamedev.stackexhange.com](http://gamedev.stackexchange.com/questions/37648/how-can-you-put-all-images-from-a-game-to-1-file), [wikipedia.org](http://en.wikipedia.org/wiki/List_of_archive_formats)  
  * collision         : do we need collision?, [Bullet3D ?](https://github.com/bulletphysics/bullet3)  
  * linear            : [**GLM**](http://glm.g-truc.net)  
  * 3D animation      : [**OGRE**](http://www.ogre3d.org)  
  * video             : [OGRE ?](http://www.ogre3d.org), [libTheora ?](http://www.theora.org/)  
  * c++               : [**boost**](http://www.boost.org/) (filesystem, hash, integer, geometry, predef, system_library, program_options, asio, math ??)  


Currently, `GLFW`, `Ogre`, `nanovg`, `turbobadger`, `ALURE`, `YAML`, `tinyxml2`, `GLM`  are up and running. 


## Building


### macOS 

As of 28 May 2018, this project builds and runs on macOS High Sierra (using Ogre3D v1.11).
Use [homebrew](www.brew.sh) to install the dependencies:

    $ brew install cmake
    $ brew install glew
    $ brew install boost
    $ brew install mpg123
    $ brew install libzzip
    $ brew install freeimage
    $ brew install freetype

It also depends on git submodules. Run
    
    $ git submodule init
    $ git submodule update

the first time pull in these.

Building can then be done with

    $ ./build.sh

which creates a program you can run with `./open-forest.sh`. (Afterwards you can use `./build.sh make-openforest` to only build the program source).


## Contact


<karamellpelle@hotmail.com>

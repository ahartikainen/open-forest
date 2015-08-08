//    open-forest: an orientering game.
//    Copyright (C) 2014  carljsv@student.matnat.uio.no
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License along
//    with this program; if not, write to the Free Software Foundation, Inc.,
//    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
#include "batb.hpp"
#include "batb/run/iteration/IterationRun.hpp"
#include "batb/run/World.hpp"

namespace batb
{


namespace run
{

IterationRun::IterationRun(BATB& b) : batb( b )
{

}

IterationStack IterationRun::iterate(World& world)
{
    ////////////////////////////////////////    
    // begin new frame
    ////////////////////////////////////////
debug::gl::DebugGroup(DEBUG_FUNCTION_NAME);

    // set current world the Run-object is working on (used by GUI)
    batb.run.world = &world;

    // set current tick for world.
    world.tick = batb.env.tick();

    // tmp:
    if ( world.toggle_a )
        glClearColor( 0.4, 0.1, 0.5, 1.0 );
    else
        glClearColor( 0.0, 0.0, 0.0, 0.0 );

    // setup scene for this frame
    begin( world.scene );

    if (world.toggle_ogre)
    {
        // output OGRE. 
        // TODO: not here (every frame), instead let 'iterate_run' iteration use 
        // call Ogre::SceneManager->_renderScene( camera, viewport, false ); 
        batb.ogre.output( world.scene );
    }

    // step all Key's, before 'iterate_run' implementation
    batb.keys.step( world.tick );

    ////////////////////////////////////////
    // actual iteration, implemented by subclass
    ////////////////////////////////////////
debug::gl::msg("iterate_run()");
    auto ret = iterate_run( world );
 

    // output and step GUI (every frame!)
    batb.gui.output( world.scene );
    batb.gui.step( world.tick );

    ////////////////////////////////////////////////////////////////////////////////
    // free resources

    step( world.events );


    ++world.frames;

    return ret;
}


// set up our Scene object for a new frame.
// currently, our Scene is just the default FBO,
// from Env
void IterationRun::begin(Scene& scene)
{
debug::gl::DebugGroup( DEBUG_FUNCTION_NAME );

    // set fragment size of scene.
    batb.env.screenSize( scene.wth, scene.hth );

    // set shape
    scene.shape.size( scene.wth, scene.hth );

    // set 2D-projection: normalized size, x (left -> right), y (up -> down)
    scene.proj2D = glm::ortho( 0.0, scene.shape.wth, scene.shape.hth, 0.0 );

    // set 3D-projection: x ( ), y ( ), z ( ) . FIXME.
    scene.proj3D = glm::perspective( value::proj3DFOVY, scene.shape.wth / scene.shape.hth, value::proj3DNear, value::proj3DFar );


    ////////////////////////////////////////    
    // OpenGL
    ////////////////////////////////////////

    // define fragment region
    glViewport( 0, 0, scene.wth, scene.hth );

    // bind FBO 
    //glBindFramebuffer( gl_FRAMEBUFFER, scene.fbo );

    // clear screen
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );

}


} // namespace run

} // namespace batb


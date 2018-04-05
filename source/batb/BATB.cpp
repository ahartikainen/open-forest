//    open-forest: an orientering game.
//    Copyright (C) 2018  karamellpelle@hotmail.com
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
#include "batb/BATB.hpp"
#include <chrono>

namespace batb
{



BATB::BATB(env::Env& e) :  env( e ), log( *this ), value( *this ), keys( *this ), gl( *this ), gui( *this ), al( *this ), ogre( *this ), 
                           run( *this ), forest( *this ), demo( *this )
{

    
}


// initialize BATB and its core parts
void begin(BATB& batb)
{
    if ( batb.init_empty() )
    {
        // core:
        batb.value.config(     file::directory( batb.filepath ) + "/value/Value.yaml" );
        batb.gui.config(       file::directory( batb.filepath ) + "/gui/GUI.yaml" );
        batb.gl.config(        file::directory( batb.filepath ) + "/gl/GL.yaml" );

        // non-core:
        batb.ogre.config(      file::directory( batb.filepath ) + "/ogre/OGRE.yaml" );
        batb.al.config(        file::directory( batb.filepath ) + "/al/AL.yaml" );
        batb.run.config(       file::directory( batb.filepath ) + "/run/Run.yaml" );
        batb.forest.config(    file::directory( batb.filepath ) + "/forest/Forest.yaml" );
        batb.demo.config(      file::directory( batb.filepath ) + "/demo/Demo.yaml" );


        // logging
        log::begin( batb.log );

        // general values to use 
        value::begin( batb.value );


        // now configure module from 'yaml'
        // ...
        


        // keys
        keys::begin( batb.keys );

        // gl
        gl::begin( batb.gl );

        // gui
        gui::begin( batb.gui );
        
        // al
        al::begin( batb.al );

        // (now the non-core part of BATB is loaded by IterationRunWork)
    }

    batb.init( true );
    
}


// end BATB and its core parts
void end(BATB& batb)
{
    if ( batb.init_nonempty() )
    {
        // save the configuration to file
        batb.save();
        
        // (the non-core part of BATB is unloaded by IterationRunWork)
        al::end( batb.al );
        gui::end( batb.gui );
        gl::end( batb.gl );
        keys::end( batb.keys );
        value::end( batb.value );
        log::end( batb.log );
    }

    batb.init( false );

}



}

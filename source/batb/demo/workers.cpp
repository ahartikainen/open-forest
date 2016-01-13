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
#include "batb/demo/workers.hpp"
#include "batb/demo/World.hpp"



  
namespace batb
{

namespace demo
{



void LoadWorkerWorld::operator()(run::Work& work)
{
    // how many steps to be loaded
    work.definite( 2 ); 

    try
    {
        work.state( "forest::World" );
        forest::WorldLoader loader( batb );         // TODO: pass 'Work' down
        loader.load( demo->forest, YAML::Node() );  // TODO: YAML definition

    }
    catch (std::exception& e)
    {
        batb.log << "error loading demo::World: " << e.what() << std::endl; 
    }

    // must be done to signalize completion
    work.finish();
}


void UnloadWorkerWorld::operator()(run::Work& work)
{
    // (this is done in other GL context!)

    // unknown how many steps to be taken
    work.indefinite(); 

    try
    {
        work.state( "forest::World" );
        forest::WorldLoader loader( batb );           // TODO: pass 'Work' down
        loader.unload( demo->forest );  // TODO: YAML definition

    } 
    catch (std::exception& e)
    {
        batb.log << "error unloading : " << e.what() << std::endl; 
    }

    // free world
    delete demo;

    // must be done to signalize completion
    work.finish();
}


////////////////////////////////////////////////////////////////////////////////
//

} // namespace demo

} // namespace batb


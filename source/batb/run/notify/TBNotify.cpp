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
#include "batb/run.hpp"
#include "batb/run/World.hpp"
#include "batb/run/notify/Notify.hpp"
#include "batb/run/notify/TBNotify.hpp"
#include "batb/value/run.hpp"
#include "tb/animation/tb_widget_animation.h"



  
namespace batb
{

namespace run
{

TBNotify::TBNotify(BATB& b) : batb( b ), notify_( b.run.notify )
{
    // set layout parameters
    
    // size: preferred
    SetLayoutSize( tb::LAYOUT_SIZE_PREFERRED );
    // position: center
    SetLayoutPosition( tb::LAYOUT_POSITION_CENTER );
    // distribution: preferred
    SetLayoutDistribution( tb::LAYOUT_DISTRIBUTION_PREFERRED );
    // distribution position: top
    SetLayoutDistributionPosition( tb::LAYOUT_DISTRIBUTION_POSITION_LEFT_TOP );

    // clip
    SetLayoutOverflow( tb::LAYOUT_OVERFLOW_CLIP );
}

TBNotifyMessage::TBNotifyMessage(TBNotify* n, NotifyMessage* msg) : tb_notify( n ), message( msg )
{
    using namespace tb;

    BATB& batb = tb_notify->batb;

    // read file as node tree, letting us parse custom nodes for this widget.
    // see tb_widgets_reader.[hc]pp
    TBNode node;
    if ( node.ReadFile( "static://batb/run/notifymesssage.tb.txt" ) )
    {
        // let TB populate this TBWindow from file
        g_widgets_reader->LoadNodeTree( this, &node );

        SetSkinBg( node.GetValueString( "skin", "TBWindow" ) ); // TODO!

        if ( ( edit = GetWidgetByIDAndType<TBEditField>( TBIDC( "edit" ) ) ) )
        {
            // TODO: write msg to edit
        }
        else
        {
            batb.log << "TBNotifyMessage: 'edit' not defined\n";
        }

        // only input should receive focus
        //tb_output_->SetIsFocusable( false );
        
        // TODO: set preferred size!

    }
    else
    {
        batb.log << "TBNotify: could not read notifymessage.tb.txt\n" ;

    }

}


void TBNotify::step(World& run)
{
    auto wth = run.scene.wth;
    auto hth = run.scene.hth;

    // fasten widget at top center
    SetPosition( tb::TBPoint( wth / 2, 0 ) );


    for ( auto i : tb_notify_messages_ )
    {
        auto dur = i->message->duration;
        if ( dur != 0 )
        {
            tick_t tick = i->message->tick + i->message->duration;
            if ( batb.env.tick() <= tick ) 
            {
                // TODO: remove 'i'
                // message->finish() and remove elemnet from list
            }
        }
    }

}

void TBNotify::push(NotifyMessage* m)
{
    tb_notify_messages_.push_back( std::make_shared<TBNotifyMessage>( this, m ) );

}



//void TBNotify::OnFocusChanged(bool focus)
//{
//    if ( focus )
//    {
//        // hopefully, this does not mess up (see TBWidgets::SetFocus())
//        SetFocusRecursive( tb::WIDGET_FOCUS_REASON_UNKNOWN );
//    }
//}
//
//bool TBNotify::OnEvent(const tb::TBWidgetEvent& event)
//{
//
//}
//


} // namespace run

} // namespace batb


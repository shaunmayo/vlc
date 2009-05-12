/*****************************************************************************
 * cmd_resize.cpp
 *****************************************************************************
 * Copyright (C) 2003 the VideoLAN team
 * $Id: 5a768daf8b1a7da363c1d528304b21692964725b $
 *
 * Authors: Cyril Deguet     <asmax@via.ecp.fr>
 *          Olivier Teulière <ipkiss@via.ecp.fr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include "cmd_resize.hpp"
#include "../src/generic_layout.hpp"
#include "../src/window_manager.hpp"
#include "../src/vlcproc.hpp"
#include "../src/vout_window.hpp"
#include "../controls/ctrl_video.hpp"
#include <vlc_vout.h>


CmdResize::CmdResize( intf_thread_t *pIntf, const WindowManager &rWindowManager,
                      GenericLayout &rLayout, int width, int height ):
    CmdGeneric( pIntf ), m_rWindowManager( rWindowManager ),
    m_rLayout( rLayout ), m_width( width ), m_height( height )
{
}


void CmdResize::execute()
{
    // Resize the layout
    m_rWindowManager.resize( m_rLayout, m_width, m_height );
}


CmdResizeVout::CmdResizeVout( intf_thread_t *pIntf, void *pWindow, int width,
                              int height ):
    CmdGeneric( pIntf ), m_pWindow( pWindow ), m_width( width ),
    m_height( height )
{
}


void CmdResizeVout::execute()
{
    VarBox &rVoutSize = VlcProc::instance( getIntf() )->getVoutSizeVar();
    rVoutSize.setSize( m_width, m_height );
}


CmdResizeInnerVout::CmdResizeInnerVout( intf_thread_t *pIntf,
                    CtrlVideo* pCtrlVideo )
         : CmdGeneric( pIntf ), m_pCtrlVideo( pCtrlVideo )
{
}


void CmdResizeInnerVout::execute()
{
    m_pCtrlVideo->resizeInnerVout();
}


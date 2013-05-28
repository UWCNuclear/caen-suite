/////////////////////////////////////////////////////////////////////////////
// Name:        virtual_channel_def_dialog.cpp
// Purpose:     
// Author:      NDA
// Modified by: 
// Created:     10/01/2007 12:50:38
// RCS-ID:      
// Copyright:   CAEN S.p.A All rights reserved.
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 10/01/2007 12:50:38

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "virtual_channel_def_dialog.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include <wx/tokenzr.h>

////@begin includes
////@end includes

#include "virtual_channel_def_dialog.h"
#include "virtual_board_channel.h"
#include "generic_board.h"
#include "rpn_handler.h"

////@begin XPM images
////@end XPM images

/*!
 * VirtualChannelDefDialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS( VirtualChannelDefDialog, wxDialog )

/*!
 * VirtualChannelDefDialog event table definition
 */

BEGIN_EVENT_TABLE( VirtualChannelDefDialog, wxDialog )

////@begin VirtualChannelDefDialog event table entries
    EVT_BUTTON( ID_VCH_DEF_ADD_CHANNEL_BUTTON, VirtualChannelDefDialog::OnVchDefAddChannelButtonClick )

    EVT_BUTTON( ID_VCH_DEF_ADD_CONSTANT_BUTTON, VirtualChannelDefDialog::OnVchDefAddConstantButtonClick )

    EVT_BUTTON( ID_VCH_DEF_ADD_OPERATOR_BUTTON, VirtualChannelDefDialog::OnVchDefAddOperatorButtonClick )

    EVT_BUTTON( ID_VCH_DEF_REMOVE_BUTTON, VirtualChannelDefDialog::OnVchDefRemoveButtonClick )

    EVT_BUTTON( ID_VCH_MOVE_UP_BUTTON, VirtualChannelDefDialog::OnVchMoveUpButtonClick )

    EVT_BUTTON( ID_VCH_MOVE_DW_BUTTON, VirtualChannelDefDialog::OnVchMoveDwButtonClick )

    EVT_BUTTON( ID_VCH_DEF_OK_BUTTON, VirtualChannelDefDialog::OnVchDefOkButtonClick )

    EVT_BUTTON( ID_VCH_DEF_CANCEL_BUTTON, VirtualChannelDefDialog::OnVchDefCancelButtonClick )

    EVT_BUTTON( ID_VCH_DEF_TEST_BUTTON, VirtualChannelDefDialog::OnVchDefTestButtonClick )

////@end VirtualChannelDefDialog event table entries

END_EVENT_TABLE()

/*!
 * VirtualChannelDefDialog constructors
 */

VirtualChannelDefDialog::VirtualChannelDefDialog( )
{
	this->m_p_board_channel= NULL;
}

VirtualChannelDefDialog::VirtualChannelDefDialog( VirtualBoardChannel* board_channel, wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
	this->m_p_board_channel= board_channel;

    Create(parent, id, caption, pos, size, style);

	wxStringTokenizer tokenizer( (const wxChar*)this->m_p_board_channel->GetExpressionDef(), _(","));
	while ( tokenizer.HasMoreTokens() )
	{
		wxString token = tokenizer.GetNextToken();
		this->m_definition_ctrl->Append( token);
	}
}

/*!
 * VirtualChannelDefDialog creator
 */

bool VirtualChannelDefDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin VirtualChannelDefDialog member initialisation
    m_left_panel = NULL;
    m_left_sizer = NULL;
    m_channel_ctrl = NULL;
    m_constant_ctrl = NULL;
    m_operator_ctrl = NULL;
    m_definition_ctrl = NULL;
////@end VirtualChannelDefDialog member initialisation

////@begin VirtualChannelDefDialog creation
    SetExtraStyle(GetExtraStyle()|wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end VirtualChannelDefDialog creation

	// Fill channel combo list
	for( int i= 0; i< ( int)this->m_p_board_channel->GetParent()->m_channel_array.GetCount(); i++)
	{
		this->m_channel_ctrl->Append( wxString::Format( _T("CH%d"), i));
	}
	if( this->m_channel_ctrl->GetCount())
		this->m_channel_ctrl->SetSelection( 0);
	// Fill operator combo list
	this->m_operator_ctrl->Append( _( "ADD"));
	this->m_operator_ctrl->Append( _( "SUB"));
	this->m_operator_ctrl->Append( _( "MUL"));
	this->m_operator_ctrl->Append( _( "DIV"));

	this->m_operator_ctrl->SetSelection( 0);

    return true;
}

/*!
 * Control creation for VirtualChannelDefDialog
 */

void VirtualChannelDefDialog::CreateControls()
{    
////@begin VirtualChannelDefDialog content construction
    // Generated by DialogBlocks, 16/01/2007 17:41:36 (unregistered)

    VirtualChannelDefDialog* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    m_left_panel = new wxPanel( itemDialog1, ID_VCH_DEF_LEFT_PANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    m_left_panel->SetBackgroundColour(wxColour(255, 255, 255));
    itemBoxSizer2->Add(m_left_panel, 1, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    m_left_panel->SetSizer(itemBoxSizer4);

    m_left_sizer = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer4->Add(m_left_sizer, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer6Static = new wxStaticBox(m_left_panel, wxID_ANY, _("Channel operand selection"));
    wxStaticBoxSizer* itemStaticBoxSizer6 = new wxStaticBoxSizer(itemStaticBoxSizer6Static, wxHORIZONTAL);
    m_left_sizer->Add(itemStaticBoxSizer6, 0, wxGROW|wxALL, 5);

    wxString* m_channel_ctrlStrings = NULL;
    m_channel_ctrl = new wxChoice( m_left_panel, ID_VCH_DEF_CHANNEL_CHOICE, wxDefaultPosition, wxSize(100, -1), 0, m_channel_ctrlStrings, 0 );
    m_channel_ctrl->SetHelpText(_("Select a channel to add"));
    if (ShowToolTips())
        m_channel_ctrl->SetToolTip(_("Select a channel to add"));
    itemStaticBoxSizer6->Add(m_channel_ctrl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton8 = new wxButton( m_left_panel, ID_VCH_DEF_ADD_CHANNEL_BUTTON, _(">"), wxDefaultPosition, wxSize(40, 25), 0 );
    itemButton8->SetHelpText(_("Add the selected channel"));
    if (ShowToolTips())
        itemButton8->SetToolTip(_("Add the selected channel"));
    itemButton8->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemStaticBoxSizer6->Add(itemButton8, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer9Static = new wxStaticBox(m_left_panel, wxID_ANY, _("Constant operand"));
    wxStaticBoxSizer* itemStaticBoxSizer9 = new wxStaticBoxSizer(itemStaticBoxSizer9Static, wxHORIZONTAL);
    m_left_sizer->Add(itemStaticBoxSizer9, 0, wxGROW|wxALL, 5);

    m_constant_ctrl = new wxSpinCtrl( m_left_panel, ID_VCH_DEF_CONSTANT_SPINCTRL, _T("0"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, -9999999, 9999999, 0 );
    m_constant_ctrl->SetHelpText(_("Set a constant value (Bits)"));
    if (ShowToolTips())
        m_constant_ctrl->SetToolTip(_("Set a constant value (Bits)"));
    itemStaticBoxSizer9->Add(m_constant_ctrl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton11 = new wxButton( m_left_panel, ID_VCH_DEF_ADD_CONSTANT_BUTTON, _(">"), wxDefaultPosition, wxSize(40, 25), 0 );
    itemButton11->SetHelpText(_("Add constant value"));
    if (ShowToolTips())
        itemButton11->SetToolTip(_("Add constant value"));
    itemButton11->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemStaticBoxSizer9->Add(itemButton11, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer12Static = new wxStaticBox(m_left_panel, wxID_ANY, _("Operator selection"));
    wxStaticBoxSizer* itemStaticBoxSizer12 = new wxStaticBoxSizer(itemStaticBoxSizer12Static, wxHORIZONTAL);
    m_left_sizer->Add(itemStaticBoxSizer12, 0, wxGROW|wxALL, 5);

    wxString* m_operator_ctrlStrings = NULL;
    m_operator_ctrl = new wxChoice( m_left_panel, ID_VCH_DEF_OPERATOR_CHOICE, wxDefaultPosition, wxSize(100, -1), 0, m_operator_ctrlStrings, 0 );
    m_operator_ctrl->SetHelpText(_("Select a channel to add"));
    if (ShowToolTips())
        m_operator_ctrl->SetToolTip(_("Select a channel to add"));
    itemStaticBoxSizer12->Add(m_operator_ctrl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton14 = new wxButton( m_left_panel, ID_VCH_DEF_ADD_OPERATOR_BUTTON, _(">"), wxDefaultPosition, wxSize(40, 25), 0 );
    itemButton14->SetHelpText(_("Add the selected operator"));
    if (ShowToolTips())
        itemButton14->SetToolTip(_("Add the selected operator"));
    itemButton14->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemStaticBoxSizer12->Add(itemButton14, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer15Static = new wxStaticBox(m_left_panel, wxID_ANY, _("Virtual channel's definition (RPN syntax)"));
    wxStaticBoxSizer* itemStaticBoxSizer15 = new wxStaticBoxSizer(itemStaticBoxSizer15Static, wxHORIZONTAL);
    itemBoxSizer4->Add(itemStaticBoxSizer15, 1, wxGROW|wxALL, 5);

    wxButton* itemButton16 = new wxButton( m_left_panel, ID_VCH_DEF_REMOVE_BUTTON, _("<"), wxDefaultPosition, wxSize(40, 25), 0 );
    itemButton16->SetHelpText(_("Remove selected item"));
    if (ShowToolTips())
        itemButton16->SetToolTip(_("Remove selected item"));
    itemButton16->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemStaticBoxSizer15->Add(itemButton16, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxString* m_definition_ctrlStrings = NULL;
    m_definition_ctrl = new wxListBox( m_left_panel, ID_VCH_DEF_DEFINTION_LISTBOX, wxDefaultPosition, wxDefaultSize, 0, m_definition_ctrlStrings, wxLB_SINGLE );
    m_definition_ctrl->SetHelpText(_("The virtual channel's definition "));
    if (ShowToolTips())
        m_definition_ctrl->SetToolTip(_("The virtual channel's definition "));
    itemStaticBoxSizer15->Add(m_definition_ctrl, 1, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer18 = new wxBoxSizer(wxVERTICAL);
    itemStaticBoxSizer15->Add(itemBoxSizer18, 0, wxGROW|wxALL, 0);

    wxButton* itemButton19 = new wxButton( m_left_panel, ID_VCH_MOVE_UP_BUTTON, _("UP"), wxDefaultPosition, wxSize(30, 50), 0 );
    itemButton19->SetHelpText(_("Move selected item up"));
    if (ShowToolTips())
        itemButton19->SetToolTip(_("Move selected item up"));
    itemButton19->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemBoxSizer18->Add(itemButton19, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM, 5);

    itemBoxSizer18->Add(5, 5, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton21 = new wxButton( m_left_panel, ID_VCH_MOVE_DW_BUTTON, _("DW"), wxDefaultPosition, wxSize(30, 50), 0 );
    itemButton21->SetHelpText(_("Move selected item down"));
    if (ShowToolTips())
        itemButton21->SetToolTip(_("Move selected item down"));
    itemButton21->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemBoxSizer18->Add(itemButton21, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM, 5);

    wxPanel* itemPanel22 = new wxPanel( itemDialog1, ID_VCH_DEF_RIGHT_PANEL, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL );
    itemPanel22->SetBackgroundColour(wxColour(192, 192, 192));
    itemBoxSizer2->Add(itemPanel22, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer23 = new wxBoxSizer(wxVERTICAL);
    itemPanel22->SetSizer(itemBoxSizer23);

    wxButton* itemButton24 = new wxButton( itemPanel22, ID_VCH_DEF_OK_BUTTON, _("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton24->SetDefault();
    itemButton24->SetHelpText(_("Close this windows and save changes"));
    if (ShowToolTips())
        itemButton24->SetToolTip(_("Close this windows and save changes"));
    itemButton24->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemBoxSizer23->Add(itemButton24, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton25 = new wxButton( itemPanel22, ID_VCH_DEF_CANCEL_BUTTON, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton25->SetDefault();
    itemButton25->SetHelpText(_("Close this windows and discard changes"));
    if (ShowToolTips())
        itemButton25->SetToolTip(_("Close this windows and discard changes"));
    itemButton25->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemBoxSizer23->Add(itemButton25, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    itemBoxSizer23->Add(5, 5, 1, wxGROW|wxALL, 5);

    wxButton* itemButton27 = new wxButton( itemPanel22, ID_VCH_DEF_TEST_BUTTON, _("Test"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton27->SetDefault();
    itemButton27->SetHelpText(_("Test the channel definition"));
    if (ShowToolTips())
        itemButton27->SetToolTip(_("Test the channel definition"));
    itemButton27->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemBoxSizer23->Add(itemButton27, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

////@end VirtualChannelDefDialog content construction
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ADD_CONSTANT_BUTTON
 */

void VirtualChannelDefDialog::OnVchDefAddConstantButtonClick( wxCommandEvent& /*event */)
{
	wxString value= wxString::Format( _T("%d"), this->m_constant_ctrl->GetValue());
	int target_sel_item= this->m_definition_ctrl->GetSelection();
	if( target_sel_item== wxNOT_FOUND )
	{
		this->m_definition_ctrl->Append( value);
		this->m_definition_ctrl->SetSelection( this->m_definition_ctrl->GetCount()- 1);
	}
	else
	{
		this->m_definition_ctrl->Insert( value, target_sel_item+ 1);
		this->m_definition_ctrl->SetSelection( target_sel_item+ 1);
	}
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ADD_OPERATOR_BUTTON
 */

void VirtualChannelDefDialog::OnVchDefAddOperatorButtonClick( wxCommandEvent& /*event */)
{
	int sel_item= 0;
	if( ( sel_item= this->m_operator_ctrl->GetSelection())== wxNOT_FOUND )
		return;
	int target_sel_item= this->m_definition_ctrl->GetSelection();
	if( target_sel_item== wxNOT_FOUND )
	{
		this->m_definition_ctrl->Append( this->m_operator_ctrl->GetString( sel_item));
		this->m_definition_ctrl->SetSelection( this->m_definition_ctrl->GetCount()- 1);
	}
	else
	{
		this->m_definition_ctrl->Insert( this->m_operator_ctrl->GetString( sel_item), target_sel_item+ 1);
		this->m_definition_ctrl->SetSelection( target_sel_item+ 1);
	}
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_REMOVE_BUTTON
 */

void VirtualChannelDefDialog::OnVchDefRemoveButtonClick( wxCommandEvent& /*event*/ )
{
	int sel_item= 0;
	if( ( sel_item= this->m_definition_ctrl->GetSelection())== wxNOT_FOUND )
		return;
	this->m_definition_ctrl->Delete( sel_item);	
	if( this->m_definition_ctrl->GetCount())
	{
		this->m_definition_ctrl->SetSelection( sel_item >= (int)this->m_definition_ctrl->GetCount()? this->m_definition_ctrl->GetCount()- 1: sel_item);
	}
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_OK_BUTTON
 */

void VirtualChannelDefDialog::OnVchDefOkButtonClick( wxCommandEvent& /*event */)
{
	RpnHandler* rpn_handler= new RpnHandler( NULL, this->MakeExpressionDef().ToAscii());
	if( !rpn_handler->Test())
	{
		// Prompt User
		if( wxMessageBox( wxT("RPN syntax has some errors!\nDo you want to save anyway ?"), wxT("Expression test"), wxOK| wxCANCEL | wxCENTRE | wxICON_ERROR  )!= wxOK)
		{
			delete rpn_handler;
			return;
		}
	}

	this->m_p_board_channel->SetExpressionDef( rpn_handler->Format());
	delete rpn_handler;

	this->Close();
	this->SetReturnCode( wxOK);
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_CANCEL_BUTTON
 */

void VirtualChannelDefDialog::OnVchDefCancelButtonClick( wxCommandEvent& /*event */)
{
	this->Close();
	this->SetReturnCode( wxCANCEL);
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_TEST_BUTTON
 */

void VirtualChannelDefDialog::OnVchDefTestButtonClick( wxCommandEvent& /*event*/ )
{
	// TODO : do test configuration here
	RpnHandler* rpn_handler= new RpnHandler( NULL, this->MakeExpressionDef().ToAscii());
	if( !rpn_handler->Test())
	{
		wxMessageBox( wxT("RPN syntax has some errors!"), wxT("Expression test"), wxOK | wxCENTRE | wxICON_ERROR  );
	}
	else
	{
		wxMessageBox( wxT("RPN syntax is Ok."), wxT("Expression test"), wxOK | wxCENTRE | wxICON_INFORMATION  );
	}
	delete rpn_handler;
}

/*!
 * Should we show tooltips?
 */

bool VirtualChannelDefDialog::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap VirtualChannelDefDialog::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin VirtualChannelDefDialog bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end VirtualChannelDefDialog bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon VirtualChannelDefDialog::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin VirtualChannelDefDialog icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end VirtualChannelDefDialog icon retrieval
}
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_VCH_DEF_ADD_CHANNEL_BUTTON
 */

void VirtualChannelDefDialog::OnVchDefAddChannelButtonClick( wxCommandEvent& /*event */)
{
	int sel_item= 0;
	if( ( sel_item= this->m_channel_ctrl->GetSelection())== wxNOT_FOUND )
		return;
	int target_sel_item= this->m_definition_ctrl->GetSelection();
	if( target_sel_item== wxNOT_FOUND )
	{
		this->m_definition_ctrl->Append( this->m_channel_ctrl->GetString( sel_item));
		this->m_definition_ctrl->SetSelection( this->m_definition_ctrl->GetCount()- 1);
	}
	else
	{
		this->m_definition_ctrl->Insert( this->m_channel_ctrl->GetString( sel_item), target_sel_item+ 1);
		this->m_definition_ctrl->SetSelection( target_sel_item+ 1);
	}
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_VCH_MOVE_UP_BUTTON
 */

void VirtualChannelDefDialog::OnVchMoveUpButtonClick( wxCommandEvent& /*event */)
{
	int sel_item= 0;
	if( ( sel_item= this->m_definition_ctrl->GetSelection())== wxNOT_FOUND )
		return;
	if( sel_item== 0)
		return;
	wxString item= this->m_definition_ctrl->GetString( sel_item);
	this->m_definition_ctrl->Delete( sel_item);	
	this->m_definition_ctrl->Insert( item, sel_item- 1);
	this->m_definition_ctrl->SetSelection( sel_item- 1);
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_VCH_MOVE_DW_BUTTON
 */

void VirtualChannelDefDialog::OnVchMoveDwButtonClick( wxCommandEvent& /*event */)
{
	int sel_item= 0;
	if( ( sel_item= this->m_definition_ctrl->GetSelection())== wxNOT_FOUND )
		return;
	if( sel_item== (int)this->m_definition_ctrl->GetCount()- 1)
		return;
	wxString item= this->m_definition_ctrl->GetString( sel_item);
	this->m_definition_ctrl->Delete( sel_item);	
	this->m_definition_ctrl->Insert( item, sel_item+ 1);
	this->m_definition_ctrl->SetSelection( sel_item+ 1);
}

wxString VirtualChannelDefDialog::MakeExpressionDef( void)
{
	wxString expression_def;
	for( int i= 0; i< (int)this->m_definition_ctrl->GetCount(); i++)
	{
		expression_def.Append( this->m_definition_ctrl->GetString( i).c_str());
		if( i!= (int)this->m_definition_ctrl->GetCount()- 1)
			expression_def.Append( _T(","));
	}
	return expression_def;
}
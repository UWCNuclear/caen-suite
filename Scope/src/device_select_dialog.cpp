/////////////////////////////////////////////////////////////////////////////
// Name:        device_select_dialog.cpp
// Purpose:     
// Author:      NDA
// Modified by: 
// Created:     24/10/2010 16:29:18
// RCS-ID:      
// Copyright:   CAEN S.p.A All rights reserved.
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 24/10/2010 16:29:18

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "device_select_dialog.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "device_select_dialog.h"

////@begin XPM images
////@end XPM images

/*!
 * DeviceSelectDialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS( DeviceSelectDialog, wxDialog )

/*!
 * DeviceSelectDialog event table definition
 */

BEGIN_EVENT_TABLE( DeviceSelectDialog, wxDialog )

////@begin DeviceSelectDialog event table entries
    EVT_CHOICE( ID_DS_LINK_TYPE_CHOICE, DeviceSelectDialog::OnDsLinkTypeChoiceSelected )

    EVT_BUTTON( ID_DS_OK_BUTTON, DeviceSelectDialog::OnDsOkButtonClick )

    EVT_BUTTON( ID_DS_CANCEL_BUTTON, DeviceSelectDialog::OnDsCancelButtonClick )

////@end DeviceSelectDialog event table entries

END_EVENT_TABLE()

/*!
 * DeviceSelectDialog constructors
 */

DeviceSelectDialog::DeviceSelectDialog( )
{
}

DeviceSelectDialog::DeviceSelectDialog( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, caption, pos, size, style);
}

/*!
 * DeviceSelectDialog creator
 */

bool DeviceSelectDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin DeviceSelectDialog member initialisation
    m_left_panel = NULL;
    m_left_sizer = NULL;
    m_link_type_ctrl = NULL;
    m_link_number_ctrl = NULL;
    m_node_number_ctrl = NULL;
    m_base_address_ctrl = NULL;
////@end DeviceSelectDialog member initialisation

////@begin DeviceSelectDialog creation
    SetExtraStyle(GetExtraStyle()|wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end DeviceSelectDialog creation
    return true;
}

/*!
 * Control creation for DeviceSelectDialog
 */

void DeviceSelectDialog::CreateControls()
{    
////@begin DeviceSelectDialog content construction
    // Generated by DialogBlocks, 26/10/2010 16:39:20 (unregistered)

    DeviceSelectDialog* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    m_left_panel = new wxPanel( itemDialog1, ID_VCH_DEF_LEFT_PANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    m_left_panel->SetBackgroundColour(wxColour(255, 255, 255));
    itemBoxSizer2->Add(m_left_panel, 1, wxGROW|wxALL, 5);

    m_left_sizer = new wxBoxSizer(wxVERTICAL);
    m_left_panel->SetSizer(m_left_sizer);

    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxVERTICAL);
    m_left_sizer->Add(itemBoxSizer5, 0, wxALIGN_LEFT|wxALL, 5);

    wxStaticText* itemStaticText6 = new wxStaticText( m_left_panel, wxID_STATIC, _("Link type:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText6->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemBoxSizer5->Add(itemStaticText6, 0, wxALIGN_LEFT|wxALL|wxADJUST_MINSIZE, 5);

    wxString m_link_type_ctrlStrings[] = {
        _("USB"),
        _("OPTICAL"),
        _("VME V1718"),
        _("VME 2718")
    };
    m_link_type_ctrl = new wxChoice( m_left_panel, ID_DS_LINK_TYPE_CHOICE, wxDefaultPosition, wxSize(150, -1), 4, m_link_type_ctrlStrings, 0 );
    m_link_type_ctrl->SetStringSelection(_("USB"));
    m_link_type_ctrl->SetHelpText(_("Select the link type"));
    if (ShowToolTips())
        m_link_type_ctrl->SetToolTip(_("Select the link type"));
    itemBoxSizer5->Add(m_link_type_ctrl, 0, wxALIGN_LEFT|wxALL, 5);

    wxBoxSizer* itemBoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    m_left_sizer->Add(itemBoxSizer8, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer9 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer8->Add(itemBoxSizer9, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText10 = new wxStaticText( m_left_panel, wxID_STATIC, _("Link number:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText10->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemBoxSizer9->Add(itemStaticText10, 0, wxALIGN_LEFT|wxALL|wxADJUST_MINSIZE, 5);

    m_link_number_ctrl = new wxSpinCtrl( m_left_panel, ID_DS_LINK_NUMBER_SPINCTRL, _T("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 9999999, 0 );
    m_link_number_ctrl->SetHelpText(_("Set the link number"));
    if (ShowToolTips())
        m_link_number_ctrl->SetToolTip(_("Set the link number"));
    itemBoxSizer9->Add(m_link_number_ctrl, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer12 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer8->Add(itemBoxSizer12, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText13 = new wxStaticText( m_left_panel, wxID_STATIC, _("Node number:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText13->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemBoxSizer12->Add(itemStaticText13, 0, wxALIGN_LEFT|wxALL|wxADJUST_MINSIZE, 5);

    m_node_number_ctrl = new wxSpinCtrl( m_left_panel, ID_DS_NODE_NUMBER_SPINCTRL, _T("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 9999999, 0 );
    m_node_number_ctrl->SetHelpText(_("Set the node number"));
    if (ShowToolTips())
        m_node_number_ctrl->SetToolTip(_("Set the node number"));
    itemBoxSizer12->Add(m_node_number_ctrl, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer15 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer8->Add(itemBoxSizer15, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText16 = new wxStaticText( m_left_panel, wxID_STATIC, _("Base address:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText16->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemBoxSizer15->Add(itemStaticText16, 0, wxALIGN_LEFT|wxALL|wxADJUST_MINSIZE, 5);

    m_base_address_ctrl = new wxTextCtrl( m_left_panel, ID_DS_BASE_ADDRESS_TEXTCTRL, _("3210"), wxDefaultPosition, wxSize(80, -1), 0 );
    m_base_address_ctrl->SetMaxLength(4);
    m_base_address_ctrl->SetHelpText(_("Set the base address"));
    if (ShowToolTips())
        m_base_address_ctrl->SetToolTip(_("Set the base address"));
    itemBoxSizer15->Add(m_base_address_ctrl, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxPanel* itemPanel18 = new wxPanel( itemDialog1, ID_VCH_DEF_RIGHT_PANEL, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL );
    itemPanel18->SetBackgroundColour(wxColour(192, 192, 192));
    itemBoxSizer2->Add(itemPanel18, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer19 = new wxBoxSizer(wxVERTICAL);
    itemPanel18->SetSizer(itemBoxSizer19);

    wxButton* itemButton20 = new wxButton( itemPanel18, ID_DS_OK_BUTTON, _("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton20->SetDefault();
    itemButton20->SetHelpText(_("Close this windows and save changes"));
    if (ShowToolTips())
        itemButton20->SetToolTip(_("Close this windows and save changes"));
    itemButton20->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemBoxSizer19->Add(itemButton20, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton21 = new wxButton( itemPanel18, ID_DS_CANCEL_BUTTON, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton21->SetDefault();
    itemButton21->SetHelpText(_("Close this windows and discard changes"));
    if (ShowToolTips())
        itemButton21->SetToolTip(_("Close this windows and discard changes"));
    itemButton21->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemBoxSizer19->Add(itemButton21, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    itemBoxSizer19->Add(5, 5, 1, wxGROW|wxALL, 5);

////@end DeviceSelectDialog content construction
	UpdateLinkControls();
}

/*!
 * wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_DS_LINK_TYPE_CHOICE
 */

void DeviceSelectDialog::OnDsLinkTypeChoiceSelected( wxCommandEvent& /*event */)
{
	UpdateLinkControls();
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_DS_OK_BUTTON
 */

void DeviceSelectDialog::OnDsOkButtonClick( wxCommandEvent& /*event */)
{
	// Field validation

	// Board address
	if( GetBaseAddress()< 0)
	{
		wxMessageBox( wxT("Base address format error !\nPlease input an hex number in the range [0..FFFF]."), wxT("Device selection"), wxOK | wxCENTRE | wxICON_ERROR );
		m_base_address_ctrl->SetFocus();
		return;
	}

	this->Close();
	this->SetReturnCode( wxOK);
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_DS_CANCEL_BUTTON
 */

void DeviceSelectDialog::OnDsCancelButtonClick( wxCommandEvent& /*event */)
{
	this->Close();
	this->SetReturnCode( wxCANCEL);
}

/*!
 * Should we show tooltips?
 */

bool DeviceSelectDialog::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap DeviceSelectDialog::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin DeviceSelectDialog bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end DeviceSelectDialog bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon DeviceSelectDialog::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin DeviceSelectDialog icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end DeviceSelectDialog icon retrieval
}

void DeviceSelectDialog::UpdateLinkControls()
{
	m_link_number_ctrl->Enable(false);
	m_node_number_ctrl->Enable(false);
	m_base_address_ctrl->Enable(false);
	LINK_TYPES link_type= (LINK_TYPES )m_link_type_ctrl->GetSelection();
	if( (int)link_type< 0) 
	{
		return;
	}
	switch( link_type) 
	{
	case DLT_USB:
		m_link_number_ctrl->Enable(true);
		break;
	case DLT_OPTICAL:
		m_link_number_ctrl->Enable(true);
		m_node_number_ctrl->Enable(true);
		break;
	case DLT_V1718:
		m_link_number_ctrl->Enable(true);
		m_base_address_ctrl->Enable(true);
		break;
	case DLT_V2718:
		m_link_number_ctrl->Enable(true);
		m_node_number_ctrl->Enable(true);
		m_base_address_ctrl->Enable(true);
		break;
	}
}
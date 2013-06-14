/////////////////////////////////////////////////////////////////////////////
// Name:        view_ch_control.cpp
// Purpose:     
// Author:      NDA
// Modified by: 
// Created:     06/04/2006 10:37:55
// RCS-ID:      
// Copyright:   CAEN S.p.A All rights reserved.
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 06/04/2006 10:37:55

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "view_ch_control.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include <wx/cmndata.h>
#include <wx/colordlg.h>

////@begin includes
////@end includes

#include "view_ch_control.h"

////@begin XPM images
////@end XPM images

/*!
 * ViewChControl type definition
 */

IMPLEMENT_DYNAMIC_CLASS( ViewChControl, wxPanel )

/*!
 * ViewChControl event table definition
 */

BEGIN_EVENT_TABLE( ViewChControl, wxPanel )

////@begin ViewChControl event table entries
    EVT_TOGGLEBUTTON( ID_VIEW_ENABLE_TOGGLEBUTTON, ViewChControl::OnViewEnableTogglebuttonClick )

    EVT_TEXT( ID_VIEW_VOLT_PER_DIV_COMBOBOX, ViewChControl::OnViewVoltPerDivComboboxUpdated )

    EVT_BUTTON( ID_OFFSET_Y_RESET_BUTTON, ViewChControl::OnOffsetYResetButtonClick )

    EVT_SPIN( ID_SPINBUTTON1, ViewChControl::OnSpinbutton1Updated )

    EVT_BUTTON( ID_CHOOSE_COLOR_BUTTON, ViewChControl::OnChooseColorButtonClick )

    EVT_SPINCTRL( ID_LINE_WIDTH_SPINCTRL, ViewChControl::OnLineWidthSpinctrlUpdated )

////@end ViewChControl event table entries

    EVT_TEXT_ENTER( ID_LINE_WIDTH_SPINCTRL, ViewChControl::OnLineWidthSpinctrlTextUpdated )
END_EVENT_TABLE()

/*!
 * ViewChControl constructors
 */

ViewChControl::ViewChControl( )
{
}

ViewChControl::ViewChControl( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, pos, size, style);
}

/*!
 * ViewChControl creator
 */

bool ViewChControl::Create( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
////@begin ViewChControl member initialisation
    m_main_sizer_text = NULL;
    m_view_enable_control = NULL;
    m_ch_volt_per_div_comboBox = NULL;
    m_ch_offset_reset_control = NULL;
    m_ch_offset_control = NULL;
    m_color_control = NULL;
    m_line_width_control = NULL;
////@end ViewChControl member initialisation

////@begin ViewChControl creation
    wxPanel::Create( parent, id, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end ViewChControl creation
    return true;
}

/*!
 * Control creation for ViewChControl
 */

void ViewChControl::CreateControls()
{    
////@begin ViewChControl content construction
    // Generated by DialogBlocks, 23/10/2010 19:30:05 (unregistered)

    ViewChControl* itemPanel1 = this;

    m_main_sizer_text = new wxStaticBox(itemPanel1, wxID_ANY, _("???"));
    wxStaticBoxSizer* itemStaticBoxSizer2 = new wxStaticBoxSizer(m_main_sizer_text, wxHORIZONTAL);
    itemPanel1->SetSizer(itemStaticBoxSizer2);

    m_view_enable_control = new wxToggleButton( itemPanel1, ID_VIEW_ENABLE_TOGGLEBUTTON, _("???"), wxDefaultPosition, wxSize(65, -1), 0 );
    m_view_enable_control->SetValue(true);
    m_view_enable_control->SetHelpText(_("Enable/Disable channel view"));
    if (ShowToolTips())
        m_view_enable_control->SetToolTip(_("Enable/Disable channel view"));
    m_view_enable_control->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, _T("Verdana")));
    itemStaticBoxSizer2->Add(m_view_enable_control, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 3);

    wxStaticBox* itemStaticBoxSizer4Static = new wxStaticBox(itemPanel1, wxID_ANY, _("Scale (mV/Div)"));
    wxStaticBoxSizer* itemStaticBoxSizer4 = new wxStaticBoxSizer(itemStaticBoxSizer4Static, wxHORIZONTAL);
    itemStaticBoxSizer2->Add(itemStaticBoxSizer4, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 2);

    wxString m_ch_volt_per_div_comboBoxStrings[] = {
        _("1"),
        _("2"),
        _("5"),
        _("10"),
        _("20"),
        _("50"),
        _("100"),
        _("200"),
        _("500")
    };
    m_ch_volt_per_div_comboBox = new wxComboBox( itemPanel1, ID_VIEW_VOLT_PER_DIV_COMBOBOX, _T(""), wxDefaultPosition, wxSize(80, -1), 9, m_ch_volt_per_div_comboBoxStrings, wxCB_READONLY );
    m_ch_volt_per_div_comboBox->SetHelpText(_("Set channel vertical scale (mV/Div)"));
    if (ShowToolTips())
        m_ch_volt_per_div_comboBox->SetToolTip(_("Set channel vertical scale (mV/Div)"));
    itemStaticBoxSizer4->Add(m_ch_volt_per_div_comboBox, 0, wxALIGN_CENTER_VERTICAL|wxALL, 6);

    wxStaticBox* itemStaticBoxSizer6Static = new wxStaticBox(itemPanel1, wxID_ANY, _("Position"));
    wxStaticBoxSizer* itemStaticBoxSizer6 = new wxStaticBoxSizer(itemStaticBoxSizer6Static, wxHORIZONTAL);
    itemStaticBoxSizer2->Add(itemStaticBoxSizer6, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 2);

    m_ch_offset_reset_control = new wxButton( itemPanel1, ID_OFFSET_Y_RESET_BUTTON, _("0"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
    m_ch_offset_reset_control->SetHelpText(_("Reset channel vertical position"));
    if (ShowToolTips())
        m_ch_offset_reset_control->SetToolTip(_("Reset channel vertical position"));
    m_ch_offset_reset_control->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemStaticBoxSizer6->Add(m_ch_offset_reset_control, 0, wxALIGN_CENTER_VERTICAL, 5);

    m_ch_offset_control = new wxSpinButton( itemPanel1, ID_SPINBUTTON1, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
    m_ch_offset_control->SetHelpText(_("Set channel vertical position"));
    if (ShowToolTips())
        m_ch_offset_control->SetToolTip(_("Set channel vertical position"));
    itemStaticBoxSizer6->Add(m_ch_offset_control, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 3);

    wxStaticBox* itemStaticBoxSizer9Static = new wxStaticBox(itemPanel1, wxID_ANY, _("Line"));
    wxStaticBoxSizer* itemStaticBoxSizer9 = new wxStaticBoxSizer(itemStaticBoxSizer9Static, wxVERTICAL);
    itemStaticBoxSizer2->Add(itemStaticBoxSizer9, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 2);

    itemStaticBoxSizer9->Add(2, 2, 1, wxGROW|wxTOP|wxBOTTOM, 2);

    wxBoxSizer* itemBoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer9->Add(itemBoxSizer11, 0, wxALIGN_CENTER_HORIZONTAL, 0);

    m_color_control = new wxPanel( itemPanel1, ID_COLOR_PANEL, wxDefaultPosition, wxSize(30, 15), wxSIMPLE_BORDER|wxTAB_TRAVERSAL );
    itemBoxSizer11->Add(m_color_control, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    wxButton* itemButton13 = new wxButton( itemPanel1, ID_CHOOSE_COLOR_BUTTON, _("..."), wxDefaultPosition, wxSize(30, 20), 0 );
    itemButton13->SetHelpText(_("Choose channel color"));
    if (ShowToolTips())
        itemButton13->SetToolTip(_("Choose channel color"));
    itemButton13->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, _T("Verdana")));
    itemBoxSizer11->Add(itemButton13, 0, wxALIGN_CENTER_VERTICAL|wxALL, 1);

    m_line_width_control = new wxSpinCtrl( itemPanel1, ID_LINE_WIDTH_SPINCTRL, _T("1"), wxDefaultPosition, wxSize(45, -1), wxSP_ARROW_KEYS, 1, 20, 1 );
    m_line_width_control->SetHelpText(_("Set line width"));
    if (ShowToolTips())
        m_line_width_control->SetToolTip(_("Set line width"));
    itemBoxSizer11->Add(m_line_width_control, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 1);

    itemStaticBoxSizer9->Add(2, 2, 1, wxGROW|wxTOP|wxBOTTOM, 2);

////@end ViewChControl content construction

	this->m_ch_offset_control->SetRange( -200, 200);
}

/*!
 * Should we show tooltips?
 */

bool ViewChControl::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap ViewChControl::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin ViewChControl bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end ViewChControl bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon ViewChControl::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin ViewChControl icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end ViewChControl icon retrieval
}

bool ViewChControl::SetupBoard( GenericBoard* p_board, int ch_index, int ch_count, int scope_index, bool is_virtual)
{
	this->m_is_virtual= is_virtual;
	this->m_p_board= p_board;
	this->m_ch_index= ch_index;
	this->m_ch_count= ch_count;
	this->m_scope_index= scope_index;
	if( this->m_is_virtual)
	{
		if( ( size_t)this->m_ch_index>= this->m_p_board->m_virtual_channel_array.GetCount())
			return false;
		this->m_p_board_channel= (GenericBoardChannel*)this->m_p_board->m_virtual_channel_array[ this->m_ch_index];
	}
	else
	{
		if( ( size_t)this->m_ch_index>= this->m_p_board->m_channel_array.GetCount())
			return false;
		this->m_p_board_channel= (GenericBoardChannel*)this->m_p_board->m_channel_array[ this->m_ch_index];
	}
	
	if( !this->UpdateControls())
		return false;
	return true;
}
bool ViewChControl::UpdateControls( )
{
	if( this->m_is_virtual)
		this->m_main_sizer_text->SetLabel( wxString::Format( _T("VIRT %d"), this->m_ch_count));
	else
		this->m_main_sizer_text->SetLabel( wxString::Format( _T("%d"), this->m_ch_count));
	this->m_color_control->SetBackgroundColour( this->m_p_board_channel->m_line_color[ this->m_scope_index]);
	this->m_line_width_control->SetValue( this->m_p_board_channel->m_line_width[ this->m_scope_index]);

	this->m_ch_offset_control->SetValue( (int)(double)(this->m_p_board_channel->m_offset_y[ this->m_scope_index]* 10.0));
	if( this->m_p_board_channel->m_volt_2_div[ this->m_scope_index]== 0)
		this->m_p_board_channel->m_volt_2_div[ this->m_scope_index]= 0.01;
	wxString voltPerDiv= wxString::Format( _T("%d"), (int)(double)(1000.0/ this->m_p_board_channel->m_volt_2_div[ this->m_scope_index]) );
	// For previous version compatibility
	int idx= this->m_ch_volt_per_div_comboBox->FindString( voltPerDiv);
	if( idx>= 0) 
	{
		this->m_ch_volt_per_div_comboBox->Select( idx);
	}
	else
	{
		this->m_ch_volt_per_div_comboBox->Select(0);
		int value= wxAtoi( this->m_ch_volt_per_div_comboBox->GetLabelText( ) );
		this->UpdateVoltPerDiv( value);
	}
	this->UpdateLinePen();

	this->m_view_enable_control->SetValue( this->m_p_board_channel->m_scope_view_enabled[ this->m_scope_index]);
	this->m_view_enable_control->SetLabel( this->m_view_enable_control->GetValue( )? _("Disable"): _("Enable"));

	return true;
}
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_CHOOSE_COLOR_BUTTON
 */

void ViewChControl::OnChooseColorButtonClick( wxCommandEvent& /* event*/ )
{
	wxColourData colour_data;
	colour_data.SetColour( this->m_p_board_channel->m_line_color[ this->m_scope_index]);
	wxColourDialog *dlg= new wxColourDialog( this, &colour_data);
	dlg->Centre();
	if( dlg->ShowModal()== wxID_OK)
	{
		this->m_p_board_channel->m_line_color[ this->m_scope_index]= dlg->GetColourData().GetColour();
		this->m_color_control->SetBackgroundColour( this->m_p_board_channel->m_line_color[ this->m_scope_index]);
		this->m_color_control->Refresh();
		this->UpdateLinePen();
	}
	delete dlg;
}


/*!
 * wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_LINE_WIDTH_SPINCTRL
 */

void ViewChControl::OnLineWidthSpinctrlUpdated( wxSpinEvent& event )
{
	this->UpdateLineWidth( event.GetPosition());
}


void ViewChControl::UpdateLinePen( )
{
	int wx_pen_style= wxSOLID;

	wxPen line_pen= wxPen( this->m_p_board_channel->m_line_color[ this->m_scope_index], this->m_p_board_channel->m_line_width[ this->m_scope_index], wx_pen_style);
	wxPen trigger_pen= wxPen( this->m_p_board_channel->m_line_color[ this->m_scope_index], 1, wxSOLID);
	this->m_p_board_channel->SetLinePen( this->m_scope_index, &line_pen, &trigger_pen);
	(this->m_p_board_channel->ScopeRefresh)( this->m_scope_index, true);
}


/*!
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_LINE_WIDTH_SPINCTRL
 */

void ViewChControl::OnLineWidthSpinctrlTextUpdated( wxCommandEvent& /* event*/ )
{
	int value= wxAtoi( this->m_line_width_control->GetLabel() );
    this->UpdateLineWidth( value);
}


void ViewChControl::UpdateLineWidth( int value)
{
	this->m_p_board_channel->m_line_width[ this->m_scope_index]= value;
	this->UpdateLinePen();
}

void ViewChControl::UpdateOffset( void)
{
	this->m_p_board_channel->m_offset_y[ this->m_scope_index]= (double)this->m_ch_offset_control->GetValue( )* 0.1;
	(this->m_p_board_channel->ScopeRefresh)( this->m_scope_index, true);
}
void ViewChControl::UpdateVoltPerDiv( int value)
{
	if( value== 0)
		value= 1;
	this->m_p_board_channel->SetVolt2Div( this->m_scope_index, 1000.0/ (double)value);
	(this->m_p_board_channel->ScopeRefresh)( this->m_scope_index, true);
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_OFFSET_Y_RESET_BUTTON
 */

void ViewChControl::OnOffsetYResetButtonClick( wxCommandEvent& /* event*/)
{
	this->m_ch_offset_control->SetValue( 0);
	this->UpdateOffset();
}

/*!
 * wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_SPINBUTTON1
 */

void ViewChControl::OnSpinbutton1Updated( wxSpinEvent& /* event*/ )
{
	this->UpdateOffset();
}

/*!
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_VIEW_ENABLE_TOGGLEBUTTON
 */

void ViewChControl::OnViewEnableTogglebuttonClick( wxCommandEvent& /*event*/ )
{
	this->m_p_board_channel->m_scope_view_enabled[ this->m_scope_index]= this->m_view_enable_control->GetValue( )!= 0;
	this->m_view_enable_control->SetLabel( this->m_view_enable_control->GetValue( )? _("Disable"): _("Enable"));
	(this->m_p_board_channel->ScopeRefresh)( this->m_scope_index, true);
}


/*!
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_VIEW_VOLT_PER_DIV_COMBOBOX
 */

void ViewChControl::OnViewVoltPerDivComboboxUpdated( wxCommandEvent& /*event*/ )
{
	int value= wxAtoi( this->m_ch_volt_per_div_comboBox->GetLabelText( ));
	this->UpdateVoltPerDiv( value);
}



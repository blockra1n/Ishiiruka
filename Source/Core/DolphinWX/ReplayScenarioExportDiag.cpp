//Replay Scenario Exporter added by Jake Holtham
// blockra1n.github.io
#include <wx/wx.h>

#include "DolphinWX/ReplayScenarioExportDiag.h"

ReplayScenarioExportDiag::ReplayScenarioExportDiag(wxWindow* const parent)
    : wxDialog(parent, wxID_ANY, _("Replay Scenario Exporter"), wxDefaultPosition, wxDefaultSize,
               wxDEFAULT_DIALOG_STYLE | wxSTAY_ON_TOP)
{
	wxBoxSizer *layout = new wxBoxSizer(wxVERTICAL);
	text = new wxStaticText(this, wxID_ANY, "Upcoming frames to export: 1 (0.016 sec.)", wxDefaultPosition,
	                        wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
	layout->Add(text);
	layout->AddSpacer(5);
	slider = new wxSlider(this, wxID_ANY, 1, 1, 600, wxDefaultPosition, wxSize(600, 50),
	                      wxALIGN_CENTER_HORIZONTAL | wxTOP | wxSL_LABELS);
	layout->Add(slider);
	Bind(wxEVT_SLIDER, &ReplayScenarioExportDiag::OnSliderMove, this);

	wxBoxSizer *buttons = (wxBoxSizer *)CreateButtonSizer(wxOK | wxCLOSE | wxNO_DEFAULT);
	layout->Add(buttons);
	Bind(wxEVT_BUTTON, &ReplayScenarioExportDiag::OnOKButton, this, wxID_OK);
	Bind(wxEVT_BUTTON, &ReplayScenarioExportDiag::OnCloseButton, this, wxID_CLOSE);
	Bind(wxEVT_CLOSE_WINDOW, &ReplayScenarioExportDiag::OnClose, this);
	SetSizerAndFit(layout);
}

void ReplayScenarioExportDiag::OnSliderMove(wxCommandEvent& event) {
	selectedTime = ((wxSlider *)event.GetEventObject())->GetValue();
	text->SetLabel(wxString::Format(_("Upcoming frames to export: %d (~%0.3f sec.)"), selectedTime, (float)selectedTime/60.0f));
}

void ReplayScenarioExportDiag::OnOKButton(wxCommandEvent& event) {
	MessageBoxA(NULL, "lol", "lol", MB_OK);
}

void ReplayScenarioExportDiag::OnCloseButton(wxCommandEvent &event)
{
	Close();
}
void ReplayScenarioExportDiag::OnClose(wxCloseEvent& event) {
	EndModal(wxID_OK);
}

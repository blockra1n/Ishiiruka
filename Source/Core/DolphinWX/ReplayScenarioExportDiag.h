// Replay Scenario Exporter added by Jake Holtham
//  blockra1n.github.io
#pragma once
#include <wx/dialog.h>

class ReplayScenarioExportDiag final : public wxDialog
{
  public:
	ReplayScenarioExportDiag(wxWindow *const parent);

  private:
	wxSlider* slider;
	wxStaticText* text;
	int selectedTime;
	void OnSliderMove(wxCommandEvent &event);
	void OnOKButton(wxCommandEvent &event);
	void OnCloseButton(wxCommandEvent &event);
	void OnClose(wxCloseEvent &event);
};
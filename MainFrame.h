#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
    MainFrame();
private:
    void Compute(wxCommandEvent& evt);
protected:
    wxTextCtrl* investmentAmountEntry;
    wxTextCtrl* yearsEntry;
    wxTextCtrl* annualInterestRateEntry;
    wxStaticText* futureValueLabel;

};
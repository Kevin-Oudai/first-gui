#include "MainFrame.h"
#include "FutureValue.h"
#include <wx/wx.h>

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Investment Calculator",wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE)
{
        wxGridSizer* grid = new wxGridSizer(2);
        wxStaticText* investmentAmountText = new wxStaticText(this, wxID_ANY, "Investment Amount");
        this->investmentAmountEntry = new wxTextCtrl(this, wxID_ANY);
        wxStaticText* yearsText = new wxStaticText(this, wxID_ANY, "Number of Years");
        this->yearsEntry = new wxTextCtrl(this, wxID_ANY);
        wxStaticText* annualInterestRateText = new wxStaticText(this, wxID_ANY, "Annual Interest Rate");
        this->annualInterestRateEntry = new wxTextCtrl(this, wxID_ANY);
        wxStaticText* futureValueText = new wxStaticText(this, wxID_ANY, "Future Value");
        this->futureValueLabel = new wxStaticText(this, wxID_ANY, "$10, 000.00");
        wxButton* computeButton = new wxButton(this, wxID_ANY, "Compute");
        grid->Add(investmentAmountText, wxSizerFlags().Border(wxALL));
        grid->Add(investmentAmountEntry, wxSizerFlags().Border(wxALL));
        grid->Add(yearsText, wxSizerFlags().Border(wxALL));
        grid->Add(yearsEntry, wxSizerFlags().Border(wxALL));
        grid->Add(annualInterestRateText, wxSizerFlags().Border(wxALL));
        grid->Add(annualInterestRateEntry, wxSizerFlags().Border(wxALL));
        grid->Add(futureValueText, wxSizerFlags().Border(wxALL));
        grid->Add(futureValueLabel, wxSizerFlags().Border(wxALL));
        grid->Add(computeButton, wxSizerFlags().Border(wxALL));
        SetSizerAndFit(grid);
        Centre(wxBOTH);

        // Events
        computeButton->Bind(wxEVT_BUTTON, &MainFrame::Compute, this);
}

void MainFrame::Compute(wxCommandEvent& evt)
{
    double investmentAmount, years, annualInterestRate;
    (this->investmentAmountEntry->GetValue()).ToCDouble(&investmentAmount);
    (this->yearsEntry->GetValue()).ToCDouble(&years);
    (this->annualInterestRateEntry->GetValue()).ToCDouble(&annualInterestRate);
    FutureValue result(investmentAmount, annualInterestRate, years);

    wxString fv = wxString::Format("$ %.2f", result.getFutureValue());
    this->futureValueLabel->SetLabel(fv);
}

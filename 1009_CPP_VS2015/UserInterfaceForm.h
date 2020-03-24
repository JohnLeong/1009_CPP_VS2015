#pragma once
#include <string>
#include <iostream>
#include "InstagramScrapper.h"
#include "TwitterScraper.h"
#include "FileUtility.h"
#include "OCRUtility.h"
#include "DataAnalyser.h"
#define nullptr __nullptr
#include "json.hpp"
#undef nullptr

#include <msclr\marshal_cppstd.h>
#include <exception>

namespace My1009_CPP_VS2015 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for UserInterfaceForm
	/// </summary>
	public ref class UserInterfaceForm : public System::Windows::Forms::Form
	{
	public:
		UserInterfaceForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UserInterfaceForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::String^ twitterExportPath = "";
	private: System::Boolean twitterScrapeInProgress = false;
	private: System::Windows::Forms::Panel^  sidePanelBacking;
	private: System::Windows::Forms::PictureBox^  sitLogo;
	private: System::Windows::Forms::Label^  functionalitiesLabel;
	protected:

	protected:


	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  instagramTab;
	private: System::Windows::Forms::TabPage^  twitterTab;
	private: System::Windows::Forms::Button^  instagramButton;



	private: System::Windows::Forms::Label^  instagramHeaderLabel;
	private: System::Windows::Forms::Button^  twitterButton;


	private: System::Windows::Forms::Label^  twitterHeaderLabel;
	private: System::Windows::Forms::Button^  dataAnalysisButton;

	private: System::Windows::Forms::Button^  displayJsonButton;
	private: System::Windows::Forms::Button^  aboutButton;
	private: System::Windows::Forms::Label^  informationLabel;
	private: System::Windows::Forms::Button^  visualisationButton;
	private: System::Windows::Forms::TabPage^  displayJsonTab;
	private: System::Windows::Forms::Label^  displayJsonHeaderLabel;
	private: System::Windows::Forms::TabPage^  dataAnalysisTab;
	private: System::Windows::Forms::TabPage^  visualisationTab;
	private: System::Windows::Forms::TabPage^  aboutTab;
	private: System::Windows::Forms::Label^  dataAnalysisHeaderLabel;
	private: System::Windows::Forms::Label^  visualisationHeaderLabel;
	private: System::Windows::Forms::Label^  instagramUsernameLabel;


	private: System::Windows::Forms::TextBox^  instagramUsernamePasswordTextBox;

	private: System::Windows::Forms::TextBox^  instagramUsernameTextBox;


	private: System::Windows::Forms::Label^  instagramProfilesLabel;
	private: System::Windows::Forms::Label^  instagramHashTagsLabel;
	private: System::Windows::Forms::Label^  instagramProfileNumberOfPostLabel;
	private: System::Windows::Forms::Label^  instagramHashTagNumberOfPostLabel;
	private: System::Windows::Forms::Label^  instagramProfileModeLabel;
	private: System::Windows::Forms::Label^  instagramHashTagModeLabel;
	private: System::Windows::Forms::Label^  instagramPasswordLabel;
	private: System::Windows::Forms::TextBox^  instagramProfilesTextBox;

	private: System::Windows::Forms::TextBox^  instagramProfilePostCountTextBox;
	private: System::Windows::Forms::TextBox^  instagramHashTagsTextBox;


	private: System::Windows::Forms::TextBox^  instagramHashTagPostCountTextBox;
	private: System::Windows::Forms::Button^  instagramProfileExecuteButton;

	private: System::Windows::Forms::Button^  instagramHashTagExecuteButton;
	private: System::Windows::Forms::Button^  instagramBrowseExportFolderButton;
	private: System::Windows::Forms::Label^  instagramExportFolderPathLabel;
	private: System::Windows::Forms::Label^  instagramExportLabel;
	private: System::Windows::Forms::FolderBrowserDialog^  instagramFolderDialog;
	private: System::Windows::Forms::Label^  instagramExportFolderPathValueLabel;
	private: System::Windows::Forms::TextBox^  instagramConsole;
	private: System::Windows::Forms::Label^  displayJsonFilePathValueLabel;

	private: System::Windows::Forms::Button^  displayJsonSaveAsButton;
	private: System::Windows::Forms::Button^  displayJsonSelectJsonButton;
	private: System::Windows::Forms::Label^  displayJsonFilePathLabel;
	private: System::Windows::Forms::Label^  displayJsonFilePathHeaderLabel;
	private: System::Windows::Forms::OpenFileDialog^  displayJsonLoadFileDialog;
	private: System::Windows::Forms::RichTextBox^  displayJsonFileOutputRichTextBox;
	private: System::Windows::Forms::SaveFileDialog^  displayJsonSaveFileDialog;
	private: System::Windows::Forms::Button^  imageOcrButton;

	private: System::Windows::Forms::TabPage^  imageOcrTab;
	private: System::Windows::Forms::Label^  imageOcrHeaderLabel;
	private: System::Windows::Forms::Label^  imageOcrFilePathLabel;

	private: System::Windows::Forms::Label^  imageOcrDescriptionLabel;
	private: System::Windows::Forms::Label^  imageOcrFilePathHeaderLabel;
private: System::Windows::Forms::Label^  imageOcrFilePathValueLabel;
private: System::Windows::Forms::Button^  imageOcrExecuteButton;
private: System::Windows::Forms::TextBox^  imageOcrConsoleTextBox;
private: System::Windows::Forms::Button^  imageOcrBrowseJsonButton;
private: System::Windows::Forms::OpenFileDialog^  imageOcrLoadFileDialog;
private: System::Windows::Forms::TextBox^  twitterHashtagsTextBox;
private: System::Windows::Forms::Label^  twitterHashtagsLabel;
private: System::Windows::Forms::Label^  twitterHashtagModeLabel;
private: System::Windows::Forms::Button^  twitterSelectPathButton;
private: System::Windows::Forms::Label^  twitterExportPathLabel;
private: System::Windows::Forms::Label^  twitterExportLabel;
private: System::Windows::Forms::NumericUpDown^  twitterNumHashtagsSelector;



private: System::Windows::Forms::Label^  twitterNumPostsLabel;
private: System::Windows::Forms::Button^  twitterScrapeProfilesButton;

private: System::Windows::Forms::NumericUpDown^  twitterNumProfilesSelector;

private: System::Windows::Forms::Label^  twitterNumPostsProfileLabel;
private: System::Windows::Forms::TextBox^  twitterProfilesTextBox;
private: System::Windows::Forms::Label^  twitterProfilesLabel;
private: System::Windows::Forms::Label^  twitterProfileModeLabel;
private: System::Windows::Forms::Button^  twitterScrapeHashtagsButton;
private: System::Windows::Forms::Button^  analysisSelectFileButton;

private: System::Windows::Forms::Label^  analysisFilePathLabel;

private: System::Windows::Forms::Label^  analysisFileLocationLabel;
private: System::Windows::Forms::DataGridView^  analysisRelatedHashtagsTable;



private: System::Windows::Forms::DataGridViewTextBoxColumn^  HashtagColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  FreqColumn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  TotalColumn;
private: System::Windows::Forms::Label^  analysisAvgWordsLabel;

private: System::Windows::Forms::Label^  analysisAvgLikesLabel;

private: System::Windows::Forms::Label^  analysisNumPostsLabel;
private: System::Windows::Forms::Label^  analysisAvgPostLengthLabel;

private: System::Windows::Forms::Label^  analysisAvgHashtagsLabel;
private: System::Windows::Forms::Label^  analysisScrapeTargetLabel;



private: System::Windows::Forms::DataVisualization::Charting::Chart^  BarChart;

private: System::Windows::Forms::DataVisualization::Charting::Chart^  PieChart;
private: System::Windows::Forms::Button^  visualationBtn;

private: System::Windows::Forms::Label^  jsonVisualFilePath;
private: System::Windows::Forms::Label^  displayJsonVisualFilePathValue;
private: System::Windows::Forms::TextBox^  twitterConsole;







































	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UserInterfaceForm::typeid));
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series9 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series10 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series11 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series12 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series13 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->sidePanelBacking = (gcnew System::Windows::Forms::Panel());
			this->imageOcrButton = (gcnew System::Windows::Forms::Button());
			this->aboutButton = (gcnew System::Windows::Forms::Button());
			this->informationLabel = (gcnew System::Windows::Forms::Label());
			this->visualisationButton = (gcnew System::Windows::Forms::Button());
			this->dataAnalysisButton = (gcnew System::Windows::Forms::Button());
			this->displayJsonButton = (gcnew System::Windows::Forms::Button());
			this->twitterButton = (gcnew System::Windows::Forms::Button());
			this->instagramButton = (gcnew System::Windows::Forms::Button());
			this->functionalitiesLabel = (gcnew System::Windows::Forms::Label());
			this->sitLogo = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->instagramTab = (gcnew System::Windows::Forms::TabPage());
			this->instagramConsole = (gcnew System::Windows::Forms::TextBox());
			this->instagramExportFolderPathValueLabel = (gcnew System::Windows::Forms::Label());
			this->instagramBrowseExportFolderButton = (gcnew System::Windows::Forms::Button());
			this->instagramExportFolderPathLabel = (gcnew System::Windows::Forms::Label());
			this->instagramExportLabel = (gcnew System::Windows::Forms::Label());
			this->instagramProfileExecuteButton = (gcnew System::Windows::Forms::Button());
			this->instagramHashTagExecuteButton = (gcnew System::Windows::Forms::Button());
			this->instagramProfilesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->instagramProfilePostCountTextBox = (gcnew System::Windows::Forms::TextBox());
			this->instagramHashTagsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->instagramHashTagPostCountTextBox = (gcnew System::Windows::Forms::TextBox());
			this->instagramUsernamePasswordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->instagramUsernameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->instagramProfilesLabel = (gcnew System::Windows::Forms::Label());
			this->instagramHashTagsLabel = (gcnew System::Windows::Forms::Label());
			this->instagramProfileNumberOfPostLabel = (gcnew System::Windows::Forms::Label());
			this->instagramHashTagNumberOfPostLabel = (gcnew System::Windows::Forms::Label());
			this->instagramProfileModeLabel = (gcnew System::Windows::Forms::Label());
			this->instagramHashTagModeLabel = (gcnew System::Windows::Forms::Label());
			this->instagramPasswordLabel = (gcnew System::Windows::Forms::Label());
			this->instagramUsernameLabel = (gcnew System::Windows::Forms::Label());
			this->instagramHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->twitterTab = (gcnew System::Windows::Forms::TabPage());
			this->twitterConsole = (gcnew System::Windows::Forms::TextBox());
			this->twitterScrapeProfilesButton = (gcnew System::Windows::Forms::Button());
			this->twitterNumProfilesSelector = (gcnew System::Windows::Forms::NumericUpDown());
			this->twitterNumPostsProfileLabel = (gcnew System::Windows::Forms::Label());
			this->twitterProfilesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->twitterProfilesLabel = (gcnew System::Windows::Forms::Label());
			this->twitterProfileModeLabel = (gcnew System::Windows::Forms::Label());
			this->twitterScrapeHashtagsButton = (gcnew System::Windows::Forms::Button());
			this->twitterNumHashtagsSelector = (gcnew System::Windows::Forms::NumericUpDown());
			this->twitterNumPostsLabel = (gcnew System::Windows::Forms::Label());
			this->twitterHashtagsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->twitterHashtagsLabel = (gcnew System::Windows::Forms::Label());
			this->twitterHashtagModeLabel = (gcnew System::Windows::Forms::Label());
			this->twitterSelectPathButton = (gcnew System::Windows::Forms::Button());
			this->twitterExportPathLabel = (gcnew System::Windows::Forms::Label());
			this->twitterExportLabel = (gcnew System::Windows::Forms::Label());
			this->twitterHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->displayJsonTab = (gcnew System::Windows::Forms::TabPage());
			this->displayJsonFileOutputRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->displayJsonFilePathValueLabel = (gcnew System::Windows::Forms::Label());
			this->displayJsonSaveAsButton = (gcnew System::Windows::Forms::Button());
			this->displayJsonSelectJsonButton = (gcnew System::Windows::Forms::Button());
			this->displayJsonFilePathLabel = (gcnew System::Windows::Forms::Label());
			this->displayJsonFilePathHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->displayJsonHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->dataAnalysisTab = (gcnew System::Windows::Forms::TabPage());
			this->analysisAvgPostLengthLabel = (gcnew System::Windows::Forms::Label());
			this->analysisAvgHashtagsLabel = (gcnew System::Windows::Forms::Label());
			this->analysisScrapeTargetLabel = (gcnew System::Windows::Forms::Label());
			this->analysisAvgWordsLabel = (gcnew System::Windows::Forms::Label());
			this->analysisAvgLikesLabel = (gcnew System::Windows::Forms::Label());
			this->analysisNumPostsLabel = (gcnew System::Windows::Forms::Label());
			this->analysisRelatedHashtagsTable = (gcnew System::Windows::Forms::DataGridView());
			this->HashtagColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FreqColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TotalColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->analysisSelectFileButton = (gcnew System::Windows::Forms::Button());
			this->analysisFilePathLabel = (gcnew System::Windows::Forms::Label());
			this->analysisFileLocationLabel = (gcnew System::Windows::Forms::Label());
			this->dataAnalysisHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->visualisationTab = (gcnew System::Windows::Forms::TabPage());
			this->displayJsonVisualFilePathValue = (gcnew System::Windows::Forms::Label());
			this->jsonVisualFilePath = (gcnew System::Windows::Forms::Label());
			this->visualationBtn = (gcnew System::Windows::Forms::Button());
			this->PieChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->BarChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->visualisationHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->imageOcrTab = (gcnew System::Windows::Forms::TabPage());
			this->imageOcrExecuteButton = (gcnew System::Windows::Forms::Button());
			this->imageOcrConsoleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->imageOcrBrowseJsonButton = (gcnew System::Windows::Forms::Button());
			this->imageOcrFilePathHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->imageOcrFilePathValueLabel = (gcnew System::Windows::Forms::Label());
			this->imageOcrFilePathLabel = (gcnew System::Windows::Forms::Label());
			this->imageOcrDescriptionLabel = (gcnew System::Windows::Forms::Label());
			this->imageOcrHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->aboutTab = (gcnew System::Windows::Forms::TabPage());
			this->instagramFolderDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->displayJsonLoadFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->displayJsonSaveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->imageOcrLoadFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->sidePanelBacking->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sitLogo))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->instagramTab->SuspendLayout();
			this->twitterTab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->twitterNumProfilesSelector))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->twitterNumHashtagsSelector))->BeginInit();
			this->displayJsonTab->SuspendLayout();
			this->dataAnalysisTab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->analysisRelatedHashtagsTable))->BeginInit();
			this->visualisationTab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PieChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BarChart))->BeginInit();
			this->imageOcrTab->SuspendLayout();
			this->SuspendLayout();
			// 
			// sidePanelBacking
			// 
			this->sidePanelBacking->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->sidePanelBacking->Controls->Add(this->imageOcrButton);
			this->sidePanelBacking->Controls->Add(this->aboutButton);
			this->sidePanelBacking->Controls->Add(this->informationLabel);
			this->sidePanelBacking->Controls->Add(this->visualisationButton);
			this->sidePanelBacking->Controls->Add(this->dataAnalysisButton);
			this->sidePanelBacking->Controls->Add(this->displayJsonButton);
			this->sidePanelBacking->Controls->Add(this->twitterButton);
			this->sidePanelBacking->Controls->Add(this->instagramButton);
			this->sidePanelBacking->Controls->Add(this->functionalitiesLabel);
			this->sidePanelBacking->Controls->Add(this->sitLogo);
			this->sidePanelBacking->Location = System::Drawing::Point(0, -1);
			this->sidePanelBacking->Name = L"sidePanelBacking";
			this->sidePanelBacking->Size = System::Drawing::Size(237, 681);
			this->sidePanelBacking->TabIndex = 0;
			// 
			// imageOcrButton
			// 
			this->imageOcrButton->BackColor = System::Drawing::Color::DimGray;
			this->imageOcrButton->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->imageOcrButton->FlatAppearance->BorderSize = 0;
			this->imageOcrButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->imageOcrButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->imageOcrButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->imageOcrButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imageOcrButton.Image")));
			this->imageOcrButton->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->imageOcrButton->Location = System::Drawing::Point(-3, 473);
			this->imageOcrButton->Name = L"imageOcrButton";
			this->imageOcrButton->Padding = System::Windows::Forms::Padding(0, 0, 15, 0);
			this->imageOcrButton->Size = System::Drawing::Size(237, 61);
			this->imageOcrButton->TabIndex = 9;
			this->imageOcrButton->Text = L"Image OCR";
			this->imageOcrButton->UseVisualStyleBackColor = false;
			this->imageOcrButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::imageOcrButton_Click);
			// 
			// aboutButton
			// 
			this->aboutButton->BackColor = System::Drawing::Color::DimGray;
			this->aboutButton->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->aboutButton->FlatAppearance->BorderSize = 0;
			this->aboutButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->aboutButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->aboutButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->aboutButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"aboutButton.Image")));
			this->aboutButton->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->aboutButton->Location = System::Drawing::Point(-3, 570);
			this->aboutButton->Name = L"aboutButton";
			this->aboutButton->Padding = System::Windows::Forms::Padding(0, 0, 15, 0);
			this->aboutButton->Size = System::Drawing::Size(237, 61);
			this->aboutButton->TabIndex = 8;
			this->aboutButton->Text = L"About";
			this->aboutButton->UseVisualStyleBackColor = false;
			this->aboutButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::aboutButton_Click);
			// 
			// informationLabel
			// 
			this->informationLabel->AutoSize = true;
			this->informationLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20.14286F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->informationLabel->ForeColor = System::Drawing::SystemColors::AppWorkspace;
			this->informationLabel->Location = System::Drawing::Point(12, 537);
			this->informationLabel->Name = L"informationLabel";
			this->informationLabel->Size = System::Drawing::Size(127, 30);
			this->informationLabel->TabIndex = 7;
			this->informationLabel->Text = L"Information";
			// 
			// visualisationButton
			// 
			this->visualisationButton->BackColor = System::Drawing::Color::DimGray;
			this->visualisationButton->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->visualisationButton->FlatAppearance->BorderSize = 0;
			this->visualisationButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->visualisationButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->visualisationButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->visualisationButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"visualisationButton.Image")));
			this->visualisationButton->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->visualisationButton->Location = System::Drawing::Point(0, 417);
			this->visualisationButton->Name = L"visualisationButton";
			this->visualisationButton->Padding = System::Windows::Forms::Padding(0, 0, 15, 0);
			this->visualisationButton->Size = System::Drawing::Size(237, 61);
			this->visualisationButton->TabIndex = 6;
			this->visualisationButton->Text = L"Visualisation";
			this->visualisationButton->UseVisualStyleBackColor = false;
			this->visualisationButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::visualisationButton_Click);
			// 
			// dataAnalysisButton
			// 
			this->dataAnalysisButton->BackColor = System::Drawing::Color::DimGray;
			this->dataAnalysisButton->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->dataAnalysisButton->FlatAppearance->BorderSize = 0;
			this->dataAnalysisButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->dataAnalysisButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->dataAnalysisButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataAnalysisButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dataAnalysisButton.Image")));
			this->dataAnalysisButton->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->dataAnalysisButton->Location = System::Drawing::Point(0, 356);
			this->dataAnalysisButton->Name = L"dataAnalysisButton";
			this->dataAnalysisButton->Padding = System::Windows::Forms::Padding(0, 0, 15, 0);
			this->dataAnalysisButton->Size = System::Drawing::Size(237, 61);
			this->dataAnalysisButton->TabIndex = 5;
			this->dataAnalysisButton->Text = L"Data Analysis";
			this->dataAnalysisButton->UseVisualStyleBackColor = false;
			this->dataAnalysisButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::dataAnalysisButton_Click);
			// 
			// displayJsonButton
			// 
			this->displayJsonButton->BackColor = System::Drawing::Color::DimGray;
			this->displayJsonButton->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->displayJsonButton->FlatAppearance->BorderSize = 0;
			this->displayJsonButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->displayJsonButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->displayJsonButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->displayJsonButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"displayJsonButton.Image")));
			this->displayJsonButton->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->displayJsonButton->Location = System::Drawing::Point(0, 286);
			this->displayJsonButton->Name = L"displayJsonButton";
			this->displayJsonButton->Padding = System::Windows::Forms::Padding(0, 0, 15, 0);
			this->displayJsonButton->Size = System::Drawing::Size(237, 70);
			this->displayJsonButton->TabIndex = 4;
			this->displayJsonButton->Text = L"Display Json";
			this->displayJsonButton->UseVisualStyleBackColor = false;
			this->displayJsonButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::displayJsonButton_Click);
			// 
			// twitterButton
			// 
			this->twitterButton->BackColor = System::Drawing::Color::DimGray;
			this->twitterButton->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->twitterButton->FlatAppearance->BorderSize = 0;
			this->twitterButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->twitterButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->twitterButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->twitterButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"twitterButton.Image")));
			this->twitterButton->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->twitterButton->Location = System::Drawing::Point(0, 234);
			this->twitterButton->Name = L"twitterButton";
			this->twitterButton->Padding = System::Windows::Forms::Padding(0, 0, 15, 0);
			this->twitterButton->Size = System::Drawing::Size(237, 61);
			this->twitterButton->TabIndex = 3;
			this->twitterButton->Text = L"Twitter";
			this->twitterButton->UseVisualStyleBackColor = false;
			this->twitterButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::twitterButton_Click);
			// 
			// instagramButton
			// 
			this->instagramButton->BackColor = System::Drawing::Color::DimGray;
			this->instagramButton->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->instagramButton->FlatAppearance->BorderSize = 0;
			this->instagramButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->instagramButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->instagramButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->instagramButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"instagramButton.Image")));
			this->instagramButton->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->instagramButton->Location = System::Drawing::Point(0, 173);
			this->instagramButton->Name = L"instagramButton";
			this->instagramButton->Padding = System::Windows::Forms::Padding(0, 0, 15, 0);
			this->instagramButton->Size = System::Drawing::Size(237, 61);
			this->instagramButton->TabIndex = 2;
			this->instagramButton->Text = L"Instagram";
			this->instagramButton->UseVisualStyleBackColor = false;
			this->instagramButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::button1_Click);
			// 
			// functionalitiesLabel
			// 
			this->functionalitiesLabel->AutoSize = true;
			this->functionalitiesLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20.14286F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->functionalitiesLabel->ForeColor = System::Drawing::SystemColors::AppWorkspace;
			this->functionalitiesLabel->Location = System::Drawing::Point(12, 139);
			this->functionalitiesLabel->Name = L"functionalitiesLabel";
			this->functionalitiesLabel->Size = System::Drawing::Size(150, 30);
			this->functionalitiesLabel->TabIndex = 1;
			this->functionalitiesLabel->Text = L"Functionalities";
			// 
			// sitLogo
			// 
			this->sitLogo->BackColor = System::Drawing::Color::Gainsboro;
			this->sitLogo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sitLogo.Image")));
			this->sitLogo->Location = System::Drawing::Point(-11, 0);
			this->sitLogo->Name = L"sitLogo";
			this->sitLogo->Size = System::Drawing::Size(248, 127);
			this->sitLogo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->sitLogo->TabIndex = 0;
			this->sitLogo->TabStop = false;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->instagramTab);
			this->tabControl1->Controls->Add(this->twitterTab);
			this->tabControl1->Controls->Add(this->displayJsonTab);
			this->tabControl1->Controls->Add(this->dataAnalysisTab);
			this->tabControl1->Controls->Add(this->visualisationTab);
			this->tabControl1->Controls->Add(this->imageOcrTab);
			this->tabControl1->Controls->Add(this->aboutTab);
			this->tabControl1->Location = System::Drawing::Point(233, -36);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(860, 746);
			this->tabControl1->TabIndex = 1;
			// 
			// instagramTab
			// 
			this->instagramTab->Controls->Add(this->instagramConsole);
			this->instagramTab->Controls->Add(this->instagramExportFolderPathValueLabel);
			this->instagramTab->Controls->Add(this->instagramBrowseExportFolderButton);
			this->instagramTab->Controls->Add(this->instagramExportFolderPathLabel);
			this->instagramTab->Controls->Add(this->instagramExportLabel);
			this->instagramTab->Controls->Add(this->instagramProfileExecuteButton);
			this->instagramTab->Controls->Add(this->instagramHashTagExecuteButton);
			this->instagramTab->Controls->Add(this->instagramProfilesTextBox);
			this->instagramTab->Controls->Add(this->instagramProfilePostCountTextBox);
			this->instagramTab->Controls->Add(this->instagramHashTagsTextBox);
			this->instagramTab->Controls->Add(this->instagramHashTagPostCountTextBox);
			this->instagramTab->Controls->Add(this->instagramUsernamePasswordTextBox);
			this->instagramTab->Controls->Add(this->instagramUsernameTextBox);
			this->instagramTab->Controls->Add(this->instagramProfilesLabel);
			this->instagramTab->Controls->Add(this->instagramHashTagsLabel);
			this->instagramTab->Controls->Add(this->instagramProfileNumberOfPostLabel);
			this->instagramTab->Controls->Add(this->instagramHashTagNumberOfPostLabel);
			this->instagramTab->Controls->Add(this->instagramProfileModeLabel);
			this->instagramTab->Controls->Add(this->instagramHashTagModeLabel);
			this->instagramTab->Controls->Add(this->instagramPasswordLabel);
			this->instagramTab->Controls->Add(this->instagramUsernameLabel);
			this->instagramTab->Controls->Add(this->instagramHeaderLabel);
			this->instagramTab->Location = System::Drawing::Point(4, 33);
			this->instagramTab->Name = L"instagramTab";
			this->instagramTab->Padding = System::Windows::Forms::Padding(3);
			this->instagramTab->Size = System::Drawing::Size(852, 709);
			this->instagramTab->TabIndex = 0;
			this->instagramTab->Text = L"1";
			this->instagramTab->UseVisualStyleBackColor = true;
			// 
			// instagramConsole
			// 
			this->instagramConsole->Location = System::Drawing::Point(52, 514);
			this->instagramConsole->Multiline = true;
			this->instagramConsole->Name = L"instagramConsole";
			this->instagramConsole->ReadOnly = true;
			this->instagramConsole->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->instagramConsole->Size = System::Drawing::Size(686, 83);
			this->instagramConsole->TabIndex = 22;
			// 
			// instagramExportFolderPathValueLabel
			// 
			this->instagramExportFolderPathValueLabel->AutoSize = true;
			this->instagramExportFolderPathValueLabel->Location = System::Drawing::Point(275, 120);
			this->instagramExportFolderPathValueLabel->Name = L"instagramExportFolderPathValueLabel";
			this->instagramExportFolderPathValueLabel->Size = System::Drawing::Size(59, 25);
			this->instagramExportFolderPathValueLabel->TabIndex = 21;
			this->instagramExportFolderPathValueLabel->Text = L"None";
			// 
			// instagramBrowseExportFolderButton
			// 
			this->instagramBrowseExportFolderButton->Location = System::Drawing::Point(39, 170);
			this->instagramBrowseExportFolderButton->Name = L"instagramBrowseExportFolderButton";
			this->instagramBrowseExportFolderButton->Size = System::Drawing::Size(101, 28);
			this->instagramBrowseExportFolderButton->TabIndex = 20;
			this->instagramBrowseExportFolderButton->Text = L"Select folder path";
			this->instagramBrowseExportFolderButton->UseVisualStyleBackColor = true;
			this->instagramBrowseExportFolderButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::instagramBrowseExportFolderButton_Click);
			// 
			// instagramExportFolderPathLabel
			// 
			this->instagramExportFolderPathLabel->AutoSize = true;
			this->instagramExportFolderPathLabel->Location = System::Drawing::Point(25, 130);
			this->instagramExportFolderPathLabel->Name = L"instagramExportFolderPathLabel";
			this->instagramExportFolderPathLabel->Size = System::Drawing::Size(123, 25);
			this->instagramExportFolderPathLabel->TabIndex = 19;
			this->instagramExportFolderPathLabel->Text = L"Folder Path: ";
			// 
			// instagramExportLabel
			// 
			this->instagramExportLabel->AutoSize = true;
			this->instagramExportLabel->Location = System::Drawing::Point(25, 93);
			this->instagramExportLabel->Name = L"instagramExportLabel";
			this->instagramExportLabel->Size = System::Drawing::Size(134, 25);
			this->instagramExportLabel->TabIndex = 19;
			this->instagramExportLabel->Text = L"Export Folder:";
			// 
			// instagramProfileExecuteButton
			// 
			this->instagramProfileExecuteButton->Location = System::Drawing::Point(399, 458);
			this->instagramProfileExecuteButton->Name = L"instagramProfileExecuteButton";
			this->instagramProfileExecuteButton->Size = System::Drawing::Size(150, 35);
			this->instagramProfileExecuteButton->TabIndex = 18;
			this->instagramProfileExecuteButton->Text = L"Execute";
			this->instagramProfileExecuteButton->UseVisualStyleBackColor = true;
			this->instagramProfileExecuteButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::instagramProfileExecuteButton_Click);
			// 
			// instagramHashTagExecuteButton
			// 
			this->instagramHashTagExecuteButton->Location = System::Drawing::Point(39, 458);
			this->instagramHashTagExecuteButton->Name = L"instagramHashTagExecuteButton";
			this->instagramHashTagExecuteButton->Size = System::Drawing::Size(150, 35);
			this->instagramHashTagExecuteButton->TabIndex = 17;
			this->instagramHashTagExecuteButton->Text = L"Execute";
			this->instagramHashTagExecuteButton->UseVisualStyleBackColor = true;
			this->instagramHashTagExecuteButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::instagramHashTagExecuteButton_Click);
			// 
			// instagramProfilesTextBox
			// 
			this->instagramProfilesTextBox->Location = System::Drawing::Point(399, 382);
			this->instagramProfilesTextBox->Multiline = true;
			this->instagramProfilesTextBox->Name = L"instagramProfilesTextBox";
			this->instagramProfilesTextBox->Size = System::Drawing::Size(200, 70);
			this->instagramProfilesTextBox->TabIndex = 16;
			this->instagramProfilesTextBox->TextChanged += gcnew System::EventHandler(this, &UserInterfaceForm::textBox8_TextChanged);
			// 
			// instagramProfilePostCountTextBox
			// 
			this->instagramProfilePostCountTextBox->Location = System::Drawing::Point(399, 284);
			this->instagramProfilePostCountTextBox->Name = L"instagramProfilePostCountTextBox";
			this->instagramProfilePostCountTextBox->Size = System::Drawing::Size(126, 29);
			this->instagramProfilePostCountTextBox->TabIndex = 15;
			// 
			// instagramHashTagsTextBox
			// 
			this->instagramHashTagsTextBox->Location = System::Drawing::Point(32, 382);
			this->instagramHashTagsTextBox->Multiline = true;
			this->instagramHashTagsTextBox->Name = L"instagramHashTagsTextBox";
			this->instagramHashTagsTextBox->Size = System::Drawing::Size(200, 70);
			this->instagramHashTagsTextBox->TabIndex = 14;
			// 
			// instagramHashTagPostCountTextBox
			// 
			this->instagramHashTagPostCountTextBox->Location = System::Drawing::Point(32, 284);
			this->instagramHashTagPostCountTextBox->Name = L"instagramHashTagPostCountTextBox";
			this->instagramHashTagPostCountTextBox->Size = System::Drawing::Size(126, 29);
			this->instagramHashTagPostCountTextBox->TabIndex = 13;
			// 
			// instagramUsernamePasswordTextBox
			// 
			this->instagramUsernamePasswordTextBox->Location = System::Drawing::Point(556, 56);
			this->instagramUsernamePasswordTextBox->Name = L"instagramUsernamePasswordTextBox";
			this->instagramUsernamePasswordTextBox->PasswordChar = '*';
			this->instagramUsernamePasswordTextBox->Size = System::Drawing::Size(126, 29);
			this->instagramUsernamePasswordTextBox->TabIndex = 10;
			this->instagramUsernamePasswordTextBox->Text = L"Password12345";
			// 
			// instagramUsernameTextBox
			// 
			this->instagramUsernameTextBox->Location = System::Drawing::Point(204, 62);
			this->instagramUsernameTextBox->Name = L"instagramUsernameTextBox";
			this->instagramUsernameTextBox->Size = System::Drawing::Size(126, 29);
			this->instagramUsernameTextBox->TabIndex = 9;
			this->instagramUsernameTextBox->Text = L"hehebongesher";
			// 
			// instagramProfilesLabel
			// 
			this->instagramProfilesLabel->AutoSize = true;
			this->instagramProfilesLabel->Location = System::Drawing::Point(392, 333);
			this->instagramProfilesLabel->Name = L"instagramProfilesLabel";
			this->instagramProfilesLabel->Size = System::Drawing::Size(76, 25);
			this->instagramProfilesLabel->TabIndex = 8;
			this->instagramProfilesLabel->Text = L"Profiles";
			this->instagramProfilesLabel->Click += gcnew System::EventHandler(this, &UserInterfaceForm::instagramProfilesLabel_Click);
			// 
			// instagramHashTagsLabel
			// 
			this->instagramHashTagsLabel->AutoSize = true;
			this->instagramHashTagsLabel->Location = System::Drawing::Point(25, 333);
			this->instagramHashTagsLabel->Name = L"instagramHashTagsLabel";
			this->instagramHashTagsLabel->Size = System::Drawing::Size(103, 25);
			this->instagramHashTagsLabel->TabIndex = 7;
			this->instagramHashTagsLabel->Text = L"HashTags";
			// 
			// instagramProfileNumberOfPostLabel
			// 
			this->instagramProfileNumberOfPostLabel->AutoSize = true;
			this->instagramProfileNumberOfPostLabel->Location = System::Drawing::Point(392, 248);
			this->instagramProfileNumberOfPostLabel->Name = L"instagramProfileNumberOfPostLabel";
			this->instagramProfileNumberOfPostLabel->Size = System::Drawing::Size(156, 25);
			this->instagramProfileNumberOfPostLabel->TabIndex = 6;
			this->instagramProfileNumberOfPostLabel->Text = L"Number of Posts";
			// 
			// instagramHashTagNumberOfPostLabel
			// 
			this->instagramHashTagNumberOfPostLabel->AutoSize = true;
			this->instagramHashTagNumberOfPostLabel->Location = System::Drawing::Point(25, 248);
			this->instagramHashTagNumberOfPostLabel->Name = L"instagramHashTagNumberOfPostLabel";
			this->instagramHashTagNumberOfPostLabel->Size = System::Drawing::Size(156, 25);
			this->instagramHashTagNumberOfPostLabel->TabIndex = 5;
			this->instagramHashTagNumberOfPostLabel->Text = L"Number of Posts";
			// 
			// instagramProfileModeLabel
			// 
			this->instagramProfileModeLabel->AutoSize = true;
			this->instagramProfileModeLabel->Location = System::Drawing::Point(392, 201);
			this->instagramProfileModeLabel->Name = L"instagramProfileModeLabel";
			this->instagramProfileModeLabel->Size = System::Drawing::Size(121, 25);
			this->instagramProfileModeLabel->TabIndex = 4;
			this->instagramProfileModeLabel->Text = L"Profile Mode";
			// 
			// instagramHashTagModeLabel
			// 
			this->instagramHashTagModeLabel->AutoSize = true;
			this->instagramHashTagModeLabel->Location = System::Drawing::Point(25, 201);
			this->instagramHashTagModeLabel->Name = L"instagramHashTagModeLabel";
			this->instagramHashTagModeLabel->Size = System::Drawing::Size(148, 25);
			this->instagramHashTagModeLabel->TabIndex = 3;
			this->instagramHashTagModeLabel->Text = L"HashTag Mode";
			// 
			// instagramPasswordLabel
			// 
			this->instagramPasswordLabel->AutoSize = true;
			this->instagramPasswordLabel->Location = System::Drawing::Point(362, 56);
			this->instagramPasswordLabel->Name = L"instagramPasswordLabel";
			this->instagramPasswordLabel->Size = System::Drawing::Size(104, 25);
			this->instagramPasswordLabel->TabIndex = 2;
			this->instagramPasswordLabel->Text = L"Password:";
			// 
			// instagramUsernameLabel
			// 
			this->instagramUsernameLabel->AutoSize = true;
			this->instagramUsernameLabel->Location = System::Drawing::Point(25, 56);
			this->instagramUsernameLabel->Name = L"instagramUsernameLabel";
			this->instagramUsernameLabel->Size = System::Drawing::Size(108, 25);
			this->instagramUsernameLabel->TabIndex = 1;
			this->instagramUsernameLabel->Text = L"Username:";
			this->instagramUsernameLabel->Click += gcnew System::EventHandler(this, &UserInterfaceForm::instagramUsernameLabel_Click);
			// 
			// instagramHeaderLabel
			// 
			this->instagramHeaderLabel->AutoSize = true;
			this->instagramHeaderLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 25.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->instagramHeaderLabel->Location = System::Drawing::Point(6, 10);
			this->instagramHeaderLabel->Name = L"instagramHeaderLabel";
			this->instagramHeaderLabel->Size = System::Drawing::Size(259, 31);
			this->instagramHeaderLabel->TabIndex = 0;
			this->instagramHeaderLabel->Text = L"Instagram Scraper";
			// 
			// twitterTab
			// 
			this->twitterTab->Controls->Add(this->twitterConsole);
			this->twitterTab->Controls->Add(this->twitterScrapeProfilesButton);
			this->twitterTab->Controls->Add(this->twitterNumProfilesSelector);
			this->twitterTab->Controls->Add(this->twitterNumPostsProfileLabel);
			this->twitterTab->Controls->Add(this->twitterProfilesTextBox);
			this->twitterTab->Controls->Add(this->twitterProfilesLabel);
			this->twitterTab->Controls->Add(this->twitterProfileModeLabel);
			this->twitterTab->Controls->Add(this->twitterScrapeHashtagsButton);
			this->twitterTab->Controls->Add(this->twitterNumHashtagsSelector);
			this->twitterTab->Controls->Add(this->twitterNumPostsLabel);
			this->twitterTab->Controls->Add(this->twitterHashtagsTextBox);
			this->twitterTab->Controls->Add(this->twitterHashtagsLabel);
			this->twitterTab->Controls->Add(this->twitterHashtagModeLabel);
			this->twitterTab->Controls->Add(this->twitterSelectPathButton);
			this->twitterTab->Controls->Add(this->twitterExportPathLabel);
			this->twitterTab->Controls->Add(this->twitterExportLabel);
			this->twitterTab->Controls->Add(this->twitterHeaderLabel);
			this->twitterTab->Location = System::Drawing::Point(4, 33);
			this->twitterTab->Name = L"twitterTab";
			this->twitterTab->Padding = System::Windows::Forms::Padding(3);
			this->twitterTab->Size = System::Drawing::Size(852, 709);
			this->twitterTab->TabIndex = 2;
			this->twitterTab->Text = L"2";
			this->twitterTab->UseVisualStyleBackColor = true;
			// 
			// twitterConsole
			// 
			this->twitterConsole->Location = System::Drawing::Point(12, 559);
			this->twitterConsole->Multiline = true;
			this->twitterConsole->Name = L"twitterConsole";
			this->twitterConsole->ReadOnly = true;
			this->twitterConsole->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->twitterConsole->Size = System::Drawing::Size(819, 102);
			this->twitterConsole->TabIndex = 26;
			// 
			// twitterScrapeProfilesButton
			// 
			this->twitterScrapeProfilesButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->twitterScrapeProfilesButton->Location = System::Drawing::Point(529, 487);
			this->twitterScrapeProfilesButton->Name = L"twitterScrapeProfilesButton";
			this->twitterScrapeProfilesButton->Size = System::Drawing::Size(233, 39);
			this->twitterScrapeProfilesButton->TabIndex = 25;
			this->twitterScrapeProfilesButton->Text = L"Scrape by profiles";
			this->twitterScrapeProfilesButton->UseVisualStyleBackColor = true;
			this->twitterScrapeProfilesButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::twitterScrapeProfilesButton_Click);
			// 
			// twitterNumProfilesSelector
			// 
			this->twitterNumProfilesSelector->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->twitterNumProfilesSelector->Location = System::Drawing::Point(529, 405);
			this->twitterNumProfilesSelector->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->twitterNumProfilesSelector->Name = L"twitterNumProfilesSelector";
			this->twitterNumProfilesSelector->Size = System::Drawing::Size(90, 28);
			this->twitterNumProfilesSelector->TabIndex = 24;
			this->twitterNumProfilesSelector->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// twitterNumPostsProfileLabel
			// 
			this->twitterNumPostsProfileLabel->AutoSize = true;
			this->twitterNumPostsProfileLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->twitterNumPostsProfileLabel->Location = System::Drawing::Point(526, 380);
			this->twitterNumPostsProfileLabel->Name = L"twitterNumPostsProfileLabel";
			this->twitterNumPostsProfileLabel->Size = System::Drawing::Size(77, 17);
			this->twitterNumPostsProfileLabel->TabIndex = 23;
			this->twitterNumPostsProfileLabel->Text = L"No. posts";
			// 
			// twitterProfilesTextBox
			// 
			this->twitterProfilesTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->twitterProfilesTextBox->Location = System::Drawing::Point(12, 405);
			this->twitterProfilesTextBox->Multiline = true;
			this->twitterProfilesTextBox->Name = L"twitterProfilesTextBox";
			this->twitterProfilesTextBox->Size = System::Drawing::Size(482, 122);
			this->twitterProfilesTextBox->TabIndex = 22;
			// 
			// twitterProfilesLabel
			// 
			this->twitterProfilesLabel->AutoSize = true;
			this->twitterProfilesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->twitterProfilesLabel->Location = System::Drawing::Point(14, 380);
			this->twitterProfilesLabel->Name = L"twitterProfilesLabel";
			this->twitterProfilesLabel->Size = System::Drawing::Size(63, 17);
			this->twitterProfilesLabel->TabIndex = 21;
			this->twitterProfilesLabel->Text = L"Profiles";
			// 
			// twitterProfileModeLabel
			// 
			this->twitterProfileModeLabel->AutoSize = true;
			this->twitterProfileModeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->twitterProfileModeLabel->Location = System::Drawing::Point(12, 344);
			this->twitterProfileModeLabel->Name = L"twitterProfileModeLabel";
			this->twitterProfileModeLabel->Size = System::Drawing::Size(163, 29);
			this->twitterProfileModeLabel->TabIndex = 20;
			this->twitterProfileModeLabel->Text = L"Profile Mode";
			// 
			// twitterScrapeHashtagsButton
			// 
			this->twitterScrapeHashtagsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->twitterScrapeHashtagsButton->Location = System::Drawing::Point(529, 301);
			this->twitterScrapeHashtagsButton->Name = L"twitterScrapeHashtagsButton";
			this->twitterScrapeHashtagsButton->Size = System::Drawing::Size(233, 39);
			this->twitterScrapeHashtagsButton->TabIndex = 19;
			this->twitterScrapeHashtagsButton->Text = L"Scrape by hashtags";
			this->twitterScrapeHashtagsButton->UseVisualStyleBackColor = true;
			this->twitterScrapeHashtagsButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::twitterScrapeHashtagsButton_Click);
			// 
			// twitterNumHashtagsSelector
			// 
			this->twitterNumHashtagsSelector->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->twitterNumHashtagsSelector->Location = System::Drawing::Point(529, 219);
			this->twitterNumHashtagsSelector->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->twitterNumHashtagsSelector->Name = L"twitterNumHashtagsSelector";
			this->twitterNumHashtagsSelector->Size = System::Drawing::Size(90, 28);
			this->twitterNumHashtagsSelector->TabIndex = 18;
			this->twitterNumHashtagsSelector->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// twitterNumPostsLabel
			// 
			this->twitterNumPostsLabel->AutoSize = true;
			this->twitterNumPostsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->twitterNumPostsLabel->Location = System::Drawing::Point(526, 194);
			this->twitterNumPostsLabel->Name = L"twitterNumPostsLabel";
			this->twitterNumPostsLabel->Size = System::Drawing::Size(77, 17);
			this->twitterNumPostsLabel->TabIndex = 16;
			this->twitterNumPostsLabel->Text = L"No. posts";
			// 
			// twitterHashtagsTextBox
			// 
			this->twitterHashtagsTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->twitterHashtagsTextBox->Location = System::Drawing::Point(12, 219);
			this->twitterHashtagsTextBox->Multiline = true;
			this->twitterHashtagsTextBox->Name = L"twitterHashtagsTextBox";
			this->twitterHashtagsTextBox->Size = System::Drawing::Size(482, 122);
			this->twitterHashtagsTextBox->TabIndex = 15;
			// 
			// twitterHashtagsLabel
			// 
			this->twitterHashtagsLabel->AutoSize = true;
			this->twitterHashtagsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->twitterHashtagsLabel->Location = System::Drawing::Point(14, 194);
			this->twitterHashtagsLabel->Name = L"twitterHashtagsLabel";
			this->twitterHashtagsLabel->Size = System::Drawing::Size(76, 17);
			this->twitterHashtagsLabel->TabIndex = 5;
			this->twitterHashtagsLabel->Text = L"Hashtags";
			// 
			// twitterHashtagModeLabel
			// 
			this->twitterHashtagModeLabel->AutoSize = true;
			this->twitterHashtagModeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->twitterHashtagModeLabel->Location = System::Drawing::Point(12, 158);
			this->twitterHashtagModeLabel->Name = L"twitterHashtagModeLabel";
			this->twitterHashtagModeLabel->Size = System::Drawing::Size(181, 29);
			this->twitterHashtagModeLabel->TabIndex = 4;
			this->twitterHashtagModeLabel->Text = L"Hashtag Mode";
			// 
			// twitterSelectPathButton
			// 
			this->twitterSelectPathButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->twitterSelectPathButton->Location = System::Drawing::Point(12, 114);
			this->twitterSelectPathButton->Name = L"twitterSelectPathButton";
			this->twitterSelectPathButton->Size = System::Drawing::Size(122, 32);
			this->twitterSelectPathButton->TabIndex = 3;
			this->twitterSelectPathButton->Text = L"Select path";
			this->twitterSelectPathButton->UseVisualStyleBackColor = true;
			this->twitterSelectPathButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::twitterSelectPathButton_Click);
			// 
			// twitterExportPathLabel
			// 
			this->twitterExportPathLabel->AutoSize = true;
			this->twitterExportPathLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->twitterExportPathLabel->Location = System::Drawing::Point(8, 90);
			this->twitterExportPathLabel->Name = L"twitterExportPathLabel";
			this->twitterExportPathLabel->Size = System::Drawing::Size(170, 20);
			this->twitterExportPathLabel->TabIndex = 2;
			this->twitterExportPathLabel->Text = L"Path: No path selected";
			// 
			// twitterExportLabel
			// 
			this->twitterExportLabel->AutoSize = true;
			this->twitterExportLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->twitterExportLabel->Location = System::Drawing::Point(8, 62);
			this->twitterExportLabel->Name = L"twitterExportLabel";
			this->twitterExportLabel->Size = System::Drawing::Size(144, 22);
			this->twitterExportLabel->TabIndex = 1;
			this->twitterExportLabel->Text = L"Export location";
			// 
			// twitterHeaderLabel
			// 
			this->twitterHeaderLabel->AutoSize = true;
			this->twitterHeaderLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 25.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->twitterHeaderLabel->Location = System::Drawing::Point(6, 10);
			this->twitterHeaderLabel->Name = L"twitterHeaderLabel";
			this->twitterHeaderLabel->Size = System::Drawing::Size(216, 31);
			this->twitterHeaderLabel->TabIndex = 0;
			this->twitterHeaderLabel->Text = L"Twitter Scraper";
			// 
			// displayJsonTab
			// 
			this->displayJsonTab->Controls->Add(this->displayJsonFileOutputRichTextBox);
			this->displayJsonTab->Controls->Add(this->displayJsonFilePathValueLabel);
			this->displayJsonTab->Controls->Add(this->displayJsonSaveAsButton);
			this->displayJsonTab->Controls->Add(this->displayJsonSelectJsonButton);
			this->displayJsonTab->Controls->Add(this->displayJsonFilePathLabel);
			this->displayJsonTab->Controls->Add(this->displayJsonFilePathHeaderLabel);
			this->displayJsonTab->Controls->Add(this->displayJsonHeaderLabel);
			this->displayJsonTab->Location = System::Drawing::Point(4, 33);
			this->displayJsonTab->Name = L"displayJsonTab";
			this->displayJsonTab->Size = System::Drawing::Size(852, 709);
			this->displayJsonTab->TabIndex = 3;
			this->displayJsonTab->Text = L"3";
			this->displayJsonTab->UseVisualStyleBackColor = true;
			// 
			// displayJsonFileOutputRichTextBox
			// 
			this->displayJsonFileOutputRichTextBox->Location = System::Drawing::Point(54, 250);
			this->displayJsonFileOutputRichTextBox->Name = L"displayJsonFileOutputRichTextBox";
			this->displayJsonFileOutputRichTextBox->Size = System::Drawing::Size(744, 313);
			this->displayJsonFileOutputRichTextBox->TabIndex = 6;
			this->displayJsonFileOutputRichTextBox->Text = L"";
			// 
			// displayJsonFilePathValueLabel
			// 
			this->displayJsonFilePathValueLabel->AutoSize = true;
			this->displayJsonFilePathValueLabel->Location = System::Drawing::Point(100, 150);
			this->displayJsonFilePathValueLabel->Name = L"displayJsonFilePathValueLabel";
			this->displayJsonFilePathValueLabel->Size = System::Drawing::Size(59, 25);
			this->displayJsonFilePathValueLabel->TabIndex = 5;
			this->displayJsonFilePathValueLabel->Text = L"None";
			// 
			// displayJsonSaveAsButton
			// 
			this->displayJsonSaveAsButton->Location = System::Drawing::Point(250, 200);
			this->displayJsonSaveAsButton->Name = L"displayJsonSaveAsButton";
			this->displayJsonSaveAsButton->Size = System::Drawing::Size(108, 45);
			this->displayJsonSaveAsButton->TabIndex = 4;
			this->displayJsonSaveAsButton->Text = L"Save As";
			this->displayJsonSaveAsButton->UseVisualStyleBackColor = true;
			this->displayJsonSaveAsButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::displayJsonSaveAsButton_Click);
			// 
			// displayJsonSelectJsonButton
			// 
			this->displayJsonSelectJsonButton->Location = System::Drawing::Point(75, 200);
			this->displayJsonSelectJsonButton->Name = L"displayJsonSelectJsonButton";
			this->displayJsonSelectJsonButton->Size = System::Drawing::Size(108, 45);
			this->displayJsonSelectJsonButton->TabIndex = 3;
			this->displayJsonSelectJsonButton->Text = L"Select file";
			this->displayJsonSelectJsonButton->UseVisualStyleBackColor = true;
			this->displayJsonSelectJsonButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::displayJsonSelectJsonButton_Click);
			// 
			// displayJsonFilePathLabel
			// 
			this->displayJsonFilePathLabel->AutoSize = true;
			this->displayJsonFilePathLabel->Location = System::Drawing::Point(48, 150);
			this->displayJsonFilePathLabel->Name = L"displayJsonFilePathLabel";
			this->displayJsonFilePathLabel->Size = System::Drawing::Size(64, 25);
			this->displayJsonFilePathLabel->TabIndex = 2;
			this->displayJsonFilePathLabel->Text = L"label1";
			// 
			// displayJsonFilePathHeaderLabel
			// 
			this->displayJsonFilePathHeaderLabel->AutoSize = true;
			this->displayJsonFilePathHeaderLabel->Location = System::Drawing::Point(48, 100);
			this->displayJsonFilePathHeaderLabel->Name = L"displayJsonFilePathHeaderLabel";
			this->displayJsonFilePathHeaderLabel->Size = System::Drawing::Size(142, 25);
			this->displayJsonFilePathHeaderLabel->TabIndex = 1;
			this->displayJsonFilePathHeaderLabel->Text = L"Json File Path:";
			// 
			// displayJsonHeaderLabel
			// 
			this->displayJsonHeaderLabel->AutoSize = true;
			this->displayJsonHeaderLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 25.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->displayJsonHeaderLabel->Location = System::Drawing::Point(6, 10);
			this->displayJsonHeaderLabel->Name = L"displayJsonHeaderLabel";
			this->displayJsonHeaderLabel->Size = System::Drawing::Size(177, 31);
			this->displayJsonHeaderLabel->TabIndex = 0;
			this->displayJsonHeaderLabel->Text = L"Display Json";
			// 
			// dataAnalysisTab
			// 
			this->dataAnalysisTab->Controls->Add(this->analysisAvgPostLengthLabel);
			this->dataAnalysisTab->Controls->Add(this->analysisAvgHashtagsLabel);
			this->dataAnalysisTab->Controls->Add(this->analysisScrapeTargetLabel);
			this->dataAnalysisTab->Controls->Add(this->analysisAvgWordsLabel);
			this->dataAnalysisTab->Controls->Add(this->analysisAvgLikesLabel);
			this->dataAnalysisTab->Controls->Add(this->analysisNumPostsLabel);
			this->dataAnalysisTab->Controls->Add(this->analysisRelatedHashtagsTable);
			this->dataAnalysisTab->Controls->Add(this->analysisSelectFileButton);
			this->dataAnalysisTab->Controls->Add(this->analysisFilePathLabel);
			this->dataAnalysisTab->Controls->Add(this->analysisFileLocationLabel);
			this->dataAnalysisTab->Controls->Add(this->dataAnalysisHeaderLabel);
			this->dataAnalysisTab->Location = System::Drawing::Point(4, 33);
			this->dataAnalysisTab->Name = L"dataAnalysisTab";
			this->dataAnalysisTab->Size = System::Drawing::Size(852, 709);
			this->dataAnalysisTab->TabIndex = 4;
			this->dataAnalysisTab->Text = L"4";
			this->dataAnalysisTab->UseVisualStyleBackColor = true;
			// 
			// analysisAvgPostLengthLabel
			// 
			this->analysisAvgPostLengthLabel->AutoSize = true;
			this->analysisAvgPostLengthLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->analysisAvgPostLengthLabel->Location = System::Drawing::Point(378, 281);
			this->analysisAvgPostLengthLabel->Name = L"analysisAvgPostLengthLabel";
			this->analysisAvgPostLengthLabel->Size = System::Drawing::Size(150, 24);
			this->analysisAvgPostLengthLabel->TabIndex = 13;
			this->analysisAvgPostLengthLabel->Text = L"Avg post length: ";
			// 
			// analysisAvgHashtagsLabel
			// 
			this->analysisAvgHashtagsLabel->AutoSize = true;
			this->analysisAvgHashtagsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->analysisAvgHashtagsLabel->Location = System::Drawing::Point(378, 224);
			this->analysisAvgHashtagsLabel->Name = L"analysisAvgHashtagsLabel";
			this->analysisAvgHashtagsLabel->Size = System::Drawing::Size(206, 24);
			this->analysisAvgHashtagsLabel->TabIndex = 12;
			this->analysisAvgHashtagsLabel->Text = L"Avg hashtags per post: ";
			// 
			// analysisScrapeTargetLabel
			// 
			this->analysisScrapeTargetLabel->AutoSize = true;
			this->analysisScrapeTargetLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->analysisScrapeTargetLabel->Location = System::Drawing::Point(378, 171);
			this->analysisScrapeTargetLabel->Name = L"analysisScrapeTargetLabel";
			this->analysisScrapeTargetLabel->Size = System::Drawing::Size(154, 24);
			this->analysisScrapeTargetLabel->TabIndex = 11;
			this->analysisScrapeTargetLabel->Text = L"Target hashtags: ";
			// 
			// analysisAvgWordsLabel
			// 
			this->analysisAvgWordsLabel->AutoSize = true;
			this->analysisAvgWordsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->analysisAvgWordsLabel->Location = System::Drawing::Point(12, 281);
			this->analysisAvgWordsLabel->Name = L"analysisAvgWordsLabel";
			this->analysisAvgWordsLabel->Size = System::Drawing::Size(182, 24);
			this->analysisAvgWordsLabel->TabIndex = 10;
			this->analysisAvgWordsLabel->Text = L"Avg words per post: ";
			// 
			// analysisAvgLikesLabel
			// 
			this->analysisAvgLikesLabel->AutoSize = true;
			this->analysisAvgLikesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->analysisAvgLikesLabel->Location = System::Drawing::Point(12, 224);
			this->analysisAvgLikesLabel->Name = L"analysisAvgLikesLabel";
			this->analysisAvgLikesLabel->Size = System::Drawing::Size(95, 24);
			this->analysisAvgLikesLabel->TabIndex = 9;
			this->analysisAvgLikesLabel->Text = L"Avg likes: ";
			// 
			// analysisNumPostsLabel
			// 
			this->analysisNumPostsLabel->AutoSize = true;
			this->analysisNumPostsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->analysisNumPostsLabel->Location = System::Drawing::Point(12, 171);
			this->analysisNumPostsLabel->Name = L"analysisNumPostsLabel";
			this->analysisNumPostsLabel->Size = System::Drawing::Size(119, 24);
			this->analysisNumPostsLabel->TabIndex = 8;
			this->analysisNumPostsLabel->Text = L"No. of posts: ";
			// 
			// analysisRelatedHashtagsTable
			// 
			this->analysisRelatedHashtagsTable->AllowUserToAddRows = false;
			this->analysisRelatedHashtagsTable->AllowUserToDeleteRows = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->analysisRelatedHashtagsTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->analysisRelatedHashtagsTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->analysisRelatedHashtagsTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->HashtagColumn,
					this->FreqColumn, this->TotalColumn
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->analysisRelatedHashtagsTable->DefaultCellStyle = dataGridViewCellStyle2;
			this->analysisRelatedHashtagsTable->Location = System::Drawing::Point(12, 339);
			this->analysisRelatedHashtagsTable->Name = L"analysisRelatedHashtagsTable";
			this->analysisRelatedHashtagsTable->ReadOnly = true;
			this->analysisRelatedHashtagsTable->RowHeadersVisible = false;
			this->analysisRelatedHashtagsTable->RowTemplate->Height = 31;
			this->analysisRelatedHashtagsTable->Size = System::Drawing::Size(504, 320);
			this->analysisRelatedHashtagsTable->TabIndex = 7;
			// 
			// HashtagColumn
			// 
			this->HashtagColumn->HeaderText = L"Hashtags";
			this->HashtagColumn->Name = L"HashtagColumn";
			this->HashtagColumn->ReadOnly = true;
			this->HashtagColumn->Width = 300;
			// 
			// FreqColumn
			// 
			this->FreqColumn->HeaderText = L"Avg frequency";
			this->FreqColumn->Name = L"FreqColumn";
			this->FreqColumn->ReadOnly = true;
			// 
			// TotalColumn
			// 
			this->TotalColumn->HeaderText = L"Total frequency";
			this->TotalColumn->Name = L"TotalColumn";
			this->TotalColumn->ReadOnly = true;
			// 
			// analysisSelectFileButton
			// 
			this->analysisSelectFileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->analysisSelectFileButton->Location = System::Drawing::Point(12, 114);
			this->analysisSelectFileButton->Name = L"analysisSelectFileButton";
			this->analysisSelectFileButton->Size = System::Drawing::Size(122, 32);
			this->analysisSelectFileButton->TabIndex = 6;
			this->analysisSelectFileButton->Text = L"Select file";
			this->analysisSelectFileButton->UseVisualStyleBackColor = true;
			this->analysisSelectFileButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::analysisSelectFileButton_Click);
			// 
			// analysisFilePathLabel
			// 
			this->analysisFilePathLabel->AutoSize = true;
			this->analysisFilePathLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->analysisFilePathLabel->Location = System::Drawing::Point(8, 90);
			this->analysisFilePathLabel->Name = L"analysisFilePathLabel";
			this->analysisFilePathLabel->Size = System::Drawing::Size(202, 20);
			this->analysisFilePathLabel->TabIndex = 5;
			this->analysisFilePathLabel->Text = L"File loaded: No file selected";
			// 
			// analysisFileLocationLabel
			// 
			this->analysisFileLocationLabel->AutoSize = true;
			this->analysisFileLocationLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->analysisFileLocationLabel->Location = System::Drawing::Point(8, 62);
			this->analysisFileLocationLabel->Name = L"analysisFileLocationLabel";
			this->analysisFileLocationLabel->Size = System::Drawing::Size(119, 22);
			this->analysisFileLocationLabel->TabIndex = 4;
			this->analysisFileLocationLabel->Text = L"File location";
			// 
			// dataAnalysisHeaderLabel
			// 
			this->dataAnalysisHeaderLabel->AutoSize = true;
			this->dataAnalysisHeaderLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 25.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->dataAnalysisHeaderLabel->Location = System::Drawing::Point(6, 10);
			this->dataAnalysisHeaderLabel->Name = L"dataAnalysisHeaderLabel";
			this->dataAnalysisHeaderLabel->Size = System::Drawing::Size(193, 31);
			this->dataAnalysisHeaderLabel->TabIndex = 0;
			this->dataAnalysisHeaderLabel->Text = L"Data Analysis";
			// 
			// visualisationTab
			// 
			this->visualisationTab->Controls->Add(this->displayJsonVisualFilePathValue);
			this->visualisationTab->Controls->Add(this->jsonVisualFilePath);
			this->visualisationTab->Controls->Add(this->visualationBtn);
			this->visualisationTab->Controls->Add(this->PieChart);
			this->visualisationTab->Controls->Add(this->BarChart);
			this->visualisationTab->Controls->Add(this->visualisationHeaderLabel);
			this->visualisationTab->Location = System::Drawing::Point(4, 33);
			this->visualisationTab->Name = L"visualisationTab";
			this->visualisationTab->Size = System::Drawing::Size(852, 709);
			this->visualisationTab->TabIndex = 5;
			this->visualisationTab->Text = L"5";
			this->visualisationTab->UseVisualStyleBackColor = true;
			// 
			// displayJsonVisualFilePathValue
			// 
			this->displayJsonVisualFilePathValue->AutoSize = true;
			this->displayJsonVisualFilePathValue->Location = System::Drawing::Point(321, 74);
			this->displayJsonVisualFilePathValue->Name = L"displayJsonVisualFilePathValue";
			this->displayJsonVisualFilePathValue->Size = System::Drawing::Size(69, 25);
			this->displayJsonVisualFilePathValue->TabIndex = 9;
			this->displayJsonVisualFilePathValue->Text = L"NONE";
			// 
			// jsonVisualFilePath
			// 
			this->jsonVisualFilePath->AutoSize = true;
			this->jsonVisualFilePath->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.818182F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->jsonVisualFilePath->Location = System::Drawing::Point(225, 69);
			this->jsonVisualFilePath->Name = L"jsonVisualFilePath";
			this->jsonVisualFilePath->Size = System::Drawing::Size(128, 31);
			this->jsonVisualFilePath->TabIndex = 8;
			this->jsonVisualFilePath->Text = L"File Path: ";
			// 
			// visualationBtn
			// 
			this->visualationBtn->Font = (gcnew System::Drawing::Font(L"Arial", 7.854546F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->visualationBtn->Location = System::Drawing::Point(28, 59);
			this->visualationBtn->Name = L"visualationBtn";
			this->visualationBtn->Size = System::Drawing::Size(149, 32);
			this->visualationBtn->TabIndex = 7;
			this->visualationBtn->Text = L"Select File";
			this->visualationBtn->UseVisualStyleBackColor = true;
			this->visualationBtn->Click += gcnew System::EventHandler(this, &UserInterfaceForm::visualationBtn_Click_1);
			// 
			// PieChart
			// 
			chartArea1->Name = L"ChartArea1";
			this->PieChart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			legend1->Title = L"Visualation Number Of Location Base On Post";
			this->PieChart->Legends->Add(legend1);
			this->PieChart->Location = System::Drawing::Point(44, 381);
			this->PieChart->Name = L"PieChart";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
			series1->EmptyPointStyle->Name = L"Location";
			series1->Legend = L"Legend1";
			series1->Name = L"Location1";
			series1->YValuesPerPoint = 4;
			this->PieChart->Series->Add(series1);
			this->PieChart->Size = System::Drawing::Size(770, 300);
			this->PieChart->TabIndex = 6;
			this->PieChart->Text = L"PieChart";
			// 
			// BarChart
			// 
			chartArea2->Name = L"ChartArea1";
			this->BarChart->ChartAreas->Add(chartArea2);
			legend2->BackGradientStyle = System::Windows::Forms::DataVisualization::Charting::GradientStyle::LeftRight;
			legend2->IsEquallySpacedItems = true;
			legend2->LegendStyle = System::Windows::Forms::DataVisualization::Charting::LegendStyle::Column;
			legend2->Name = L"VisualationNumberOfPostPerMonth";
			legend2->Title = L"Visualation Number Of Post Per Month";
			this->BarChart->Legends->Add(legend2);
			this->BarChart->Location = System::Drawing::Point(6, 108);
			this->BarChart->Name = L"BarChart";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"VisualationNumberOfPostPerMonth";
			series2->Name = L"JAN";
			series3->ChartArea = L"ChartArea1";
			series3->Legend = L"VisualationNumberOfPostPerMonth";
			series3->Name = L"FEB";
			series4->ChartArea = L"ChartArea1";
			series4->Legend = L"VisualationNumberOfPostPerMonth";
			series4->Name = L"MARCH";
			series5->ChartArea = L"ChartArea1";
			series5->Legend = L"VisualationNumberOfPostPerMonth";
			series5->Name = L"APRIL";
			series6->ChartArea = L"ChartArea1";
			series6->Legend = L"VisualationNumberOfPostPerMonth";
			series6->Name = L"MAY";
			series7->ChartArea = L"ChartArea1";
			series7->Legend = L"VisualationNumberOfPostPerMonth";
			series7->Name = L"JUNE";
			series8->ChartArea = L"ChartArea1";
			series8->Legend = L"VisualationNumberOfPostPerMonth";
			series8->Name = L"JULY";
			series9->ChartArea = L"ChartArea1";
			series9->Legend = L"VisualationNumberOfPostPerMonth";
			series9->Name = L"AUG";
			series10->ChartArea = L"ChartArea1";
			series10->Legend = L"VisualationNumberOfPostPerMonth";
			series10->Name = L"SEPT";
			series11->ChartArea = L"ChartArea1";
			series11->Legend = L"VisualationNumberOfPostPerMonth";
			series11->Name = L"OCT";
			series12->ChartArea = L"ChartArea1";
			series12->Legend = L"VisualationNumberOfPostPerMonth";
			series12->Name = L"NOV";
			series13->ChartArea = L"ChartArea1";
			series13->Legend = L"VisualationNumberOfPostPerMonth";
			series13->Name = L"DEC";
			this->BarChart->Series->Add(series2);
			this->BarChart->Series->Add(series3);
			this->BarChart->Series->Add(series4);
			this->BarChart->Series->Add(series5);
			this->BarChart->Series->Add(series6);
			this->BarChart->Series->Add(series7);
			this->BarChart->Series->Add(series8);
			this->BarChart->Series->Add(series9);
			this->BarChart->Series->Add(series10);
			this->BarChart->Series->Add(series11);
			this->BarChart->Series->Add(series12);
			this->BarChart->Series->Add(series13);
			this->BarChart->Size = System::Drawing::Size(803, 283);
			this->BarChart->TabIndex = 1;
			this->BarChart->Text = L"BarChart";
			// 
			// visualisationHeaderLabel
			// 
			this->visualisationHeaderLabel->AutoSize = true;
			this->visualisationHeaderLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 25.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->visualisationHeaderLabel->Location = System::Drawing::Point(6, 10);
			this->visualisationHeaderLabel->Name = L"visualisationHeaderLabel";
			this->visualisationHeaderLabel->Size = System::Drawing::Size(183, 31);
			this->visualisationHeaderLabel->TabIndex = 0;
			this->visualisationHeaderLabel->Text = L"Visualisation";
			// 
			// imageOcrTab
			// 
			this->imageOcrTab->Controls->Add(this->imageOcrExecuteButton);
			this->imageOcrTab->Controls->Add(this->imageOcrConsoleTextBox);
			this->imageOcrTab->Controls->Add(this->imageOcrBrowseJsonButton);
			this->imageOcrTab->Controls->Add(this->imageOcrFilePathHeaderLabel);
			this->imageOcrTab->Controls->Add(this->imageOcrFilePathValueLabel);
			this->imageOcrTab->Controls->Add(this->imageOcrFilePathLabel);
			this->imageOcrTab->Controls->Add(this->imageOcrDescriptionLabel);
			this->imageOcrTab->Controls->Add(this->imageOcrHeaderLabel);
			this->imageOcrTab->Location = System::Drawing::Point(4, 33);
			this->imageOcrTab->Name = L"imageOcrTab";
			this->imageOcrTab->Size = System::Drawing::Size(852, 709);
			this->imageOcrTab->TabIndex = 6;
			this->imageOcrTab->Text = L"6";
			this->imageOcrTab->UseVisualStyleBackColor = true;
			// 
			// imageOcrExecuteButton
			// 
			this->imageOcrExecuteButton->Location = System::Drawing::Point(223, 277);
			this->imageOcrExecuteButton->Name = L"imageOcrExecuteButton";
			this->imageOcrExecuteButton->Size = System::Drawing::Size(75, 56);
			this->imageOcrExecuteButton->TabIndex = 7;
			this->imageOcrExecuteButton->Text = L"Execute";
			this->imageOcrExecuteButton->UseVisualStyleBackColor = true;
			this->imageOcrExecuteButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::imageOcrExecuteButton_Click);
			// 
			// imageOcrConsoleTextBox
			// 
			this->imageOcrConsoleTextBox->Location = System::Drawing::Point(56, 406);
			this->imageOcrConsoleTextBox->Multiline = true;
			this->imageOcrConsoleTextBox->Name = L"imageOcrConsoleTextBox";
			this->imageOcrConsoleTextBox->ReadOnly = true;
			this->imageOcrConsoleTextBox->Size = System::Drawing::Size(705, 225);
			this->imageOcrConsoleTextBox->TabIndex = 6;
			// 
			// imageOcrBrowseJsonButton
			// 
			this->imageOcrBrowseJsonButton->Location = System::Drawing::Point(53, 280);
			this->imageOcrBrowseJsonButton->Name = L"imageOcrBrowseJsonButton";
			this->imageOcrBrowseJsonButton->Size = System::Drawing::Size(75, 23);
			this->imageOcrBrowseJsonButton->TabIndex = 5;
			this->imageOcrBrowseJsonButton->Text = L"Browse";
			this->imageOcrBrowseJsonButton->UseVisualStyleBackColor = true;
			this->imageOcrBrowseJsonButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::imageOcrBrowseJsonButton_Click);
			// 
			// imageOcrFilePathHeaderLabel
			// 
			this->imageOcrFilePathHeaderLabel->AutoSize = true;
			this->imageOcrFilePathHeaderLabel->Location = System::Drawing::Point(50, 130);
			this->imageOcrFilePathHeaderLabel->Name = L"imageOcrFilePathHeaderLabel";
			this->imageOcrFilePathHeaderLabel->Size = System::Drawing::Size(128, 25);
			this->imageOcrFilePathHeaderLabel->TabIndex = 4;
			this->imageOcrFilePathHeaderLabel->Text = L"File Location:";
			// 
			// imageOcrFilePathValueLabel
			// 
			this->imageOcrFilePathValueLabel->AutoSize = true;
			this->imageOcrFilePathValueLabel->Location = System::Drawing::Point(150, 200);
			this->imageOcrFilePathValueLabel->Name = L"imageOcrFilePathValueLabel";
			this->imageOcrFilePathValueLabel->Size = System::Drawing::Size(59, 25);
			this->imageOcrFilePathValueLabel->TabIndex = 3;
			this->imageOcrFilePathValueLabel->Text = L"None";
			// 
			// imageOcrFilePathLabel
			// 
			this->imageOcrFilePathLabel->AutoSize = true;
			this->imageOcrFilePathLabel->Location = System::Drawing::Point(50, 200);
			this->imageOcrFilePathLabel->Name = L"imageOcrFilePathLabel";
			this->imageOcrFilePathLabel->Size = System::Drawing::Size(113, 25);
			this->imageOcrFilePathLabel->TabIndex = 2;
			this->imageOcrFilePathLabel->Text = L"File loaded:";
			// 
			// imageOcrDescriptionLabel
			// 
			this->imageOcrDescriptionLabel->AutoSize = true;
			this->imageOcrDescriptionLabel->Location = System::Drawing::Point(44, 73);
			this->imageOcrDescriptionLabel->Name = L"imageOcrDescriptionLabel";
			this->imageOcrDescriptionLabel->Size = System::Drawing::Size(1548, 25);
			this->imageOcrDescriptionLabel->TabIndex = 1;
			this->imageOcrDescriptionLabel->Text = L"*This function is currently only compatible with Instagram scraped Data. For ever"
				L"y post in the JSON file, an ocr_text field will be appended to it whenever text "
				L"extraction is possible. ";
			// 
			// imageOcrHeaderLabel
			// 
			this->imageOcrHeaderLabel->AutoSize = true;
			this->imageOcrHeaderLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 25.14286F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->imageOcrHeaderLabel->Location = System::Drawing::Point(6, 10);
			this->imageOcrHeaderLabel->Name = L"imageOcrHeaderLabel";
			this->imageOcrHeaderLabel->Size = System::Drawing::Size(163, 31);
			this->imageOcrHeaderLabel->TabIndex = 0;
			this->imageOcrHeaderLabel->Text = L"Image OCR";
			// 
			// aboutTab
			// 
			this->aboutTab->Location = System::Drawing::Point(4, 33);
			this->aboutTab->Name = L"aboutTab";
			this->aboutTab->Size = System::Drawing::Size(852, 709);
			this->aboutTab->TabIndex = 7;
			this->aboutTab->Text = L"7";
			this->aboutTab->UseVisualStyleBackColor = true;
			// 
			// imageOcrLoadFileDialog
			// 
			this->imageOcrLoadFileDialog->FileName = L"openFileDialog1";
			// 
			// UserInterfaceForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1080, 679);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->sidePanelBacking);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"UserInterfaceForm";
			this->Text = L"ICT1009 Scrapper";
			this->sidePanelBacking->ResumeLayout(false);
			this->sidePanelBacking->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sitLogo))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->instagramTab->ResumeLayout(false);
			this->instagramTab->PerformLayout();
			this->twitterTab->ResumeLayout(false);
			this->twitterTab->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->twitterNumProfilesSelector))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->twitterNumHashtagsSelector))->EndInit();
			this->displayJsonTab->ResumeLayout(false);
			this->displayJsonTab->PerformLayout();
			this->dataAnalysisTab->ResumeLayout(false);
			this->dataAnalysisTab->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->analysisRelatedHashtagsTable))->EndInit();
			this->visualisationTab->ResumeLayout(false);
			this->visualisationTab->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PieChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BarChart))->EndInit();
			this->imageOcrTab->ResumeLayout(false);
			this->imageOcrTab->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->tabControl1->SelectTab(0);
	}
	private: System::Void twitterButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->tabControl1->SelectTab(1);
	}
	private: System::Void displayJsonButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->tabControl1->SelectTab(2);
	}
	private: System::Void dataAnalysisButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->tabControl1->SelectTab(3);
	}
	private: System::Void visualisationButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->tabControl1->SelectTab(4);
	}
	private: System::Void imageOcrButton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->tabControl1->SelectTab(5);
	}
	private: System::Void aboutButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->tabControl1->SelectTab(6);
	}
	private: System::Void instagramUsernameLabel_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox8_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void instagramProfilesLabel_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
}
private: System::Void folderBrowserDialog1_HelpRequest(System::Object^  sender, System::EventArgs^  e) {
}
	private: System::Void instagramBrowseExportFolderButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (instagramFolderDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			instagramExportFolderPathValueLabel->Text = instagramFolderDialog->SelectedPath;

		}
	}
	private: System::Void instagramHashTagExecuteButton_Click(System::Object^  sender, System::EventArgs^  e) {
		//Check user name whether keyed in,
		//Check whether password keyed in
		//Check if numberof post in hashtag is correfct (empty and is number)
		//check if hashtags is correct
		//Check if export path has been chosen
		bool success = true;
		using std::cout;
		using std::endl;

	/*	instagramConsole->AppendText(instagramExportFolderPathValueLabel->Text+"\r\n");
		instagramConsole->AppendText(instagramUsernameTextBox->Text+"\r\n");
		instagramConsole->AppendText(instagramUsernamePasswordTextBox->Text+"\r\n");*/

		if (instagramExportFolderPathValueLabel->Text == "None") {
			instagramConsole->AppendText("*Please choose an export path\r\n");
			success = false;
		}

		//Check for valid fields
		if (instagramUsernameTextBox->Text == "") {

			instagramConsole->AppendText("*Please enter username\r\n");
			success = false;
		}
		if (instagramUsernamePasswordTextBox->Text == "") {
			instagramConsole->AppendText("*Please enter password\r\n");
			success = false;
		}
		if (instagramHashTagPostCountTextBox->Text == "") {
			instagramConsole->AppendText("*Please enter number of posts\r\n");
			success = false;
		}
		try {
			double nubmerOfPost = double::Parse(instagramHashTagPostCountTextBox->Text);
		} catch (...) {
			instagramConsole->AppendText("*Invalid number of posts\r\n");
			success = false;
		}

		if (instagramHashTagsTextBox->Text == "") {
			instagramConsole->AppendText("*Please enter hashtags\r\n");
			success = false;
		}

		if (success) {
			std::string username = msclr::interop::marshal_as<std::string>(instagramUsernameTextBox->Text);
			std::string password =  msclr::interop::marshal_as<std::string>(instagramUsernamePasswordTextBox->Text);
			std::string hashtags = msclr::interop::marshal_as<std::string>(instagramHashTagsTextBox->Text);
			double postCap = System::Convert::ToDouble(instagramHashTagPostCountTextBox->Text);
			std::string exportFolderPath = msclr::interop::marshal_as<std::string>(instagramExportFolderPathValueLabel->Text);
			using ICT1009::WebScrapping::InstagramScrapper;
			typedef std::shared_ptr<InstagramScrapper> InstagramScrapperPtr;
			InstagramScrapperPtr scrapper(new InstagramScrapper);
			instagramConsole->AppendText("*Executing hashtag scraping procedure...\r\n");
			try {
				if (scrapper->scrapeByHashTags(username, password, hashtags, postCap, exportFolderPath) == 1) 
					instagramConsole->AppendText("*Finished hashtag scrapping procedure. \r\n");
			} catch (...) {
				instagramConsole->AppendText("*Error occured during hashtag scraping procedure...\r\n");
			}
		}
	}

	private: System::Void instagramProfileExecuteButton_Click(System::Object^  sender, System::EventArgs^  e) {

		bool success = true;
		using std::cout; using std::endl;

		if (instagramExportFolderPathValueLabel->Text == "None") {
			instagramConsole->AppendText("*Please choose an export path\r\n");
			success = false;
		}

		//Check for valid fields
		if (instagramUsernameTextBox->Text == "") {

			instagramConsole->AppendText("*Please enter username\r\n");
			success = false;
		}
		if (instagramUsernamePasswordTextBox->Text == "") {
			instagramConsole->AppendText("*Please enter password\r\n");
			success = false;
		}
		if (instagramProfilePostCountTextBox->Text == "") {
			instagramConsole->AppendText("*Please enter number of posts\r\n");
			success = false;
		}
		try {
			double nubmerOfPost = double::Parse(instagramProfilePostCountTextBox->Text);
		} catch (...) {
			instagramConsole->AppendText("*Invalid number of posts\r\n");
			success = false;
		}

		if (instagramProfilesTextBox->Text == "") {
			instagramConsole->AppendText("*Please enter profiles\r\n");
			success = false;
		}

		if (success) {
			std::string username = msclr::interop::marshal_as<std::string>(instagramUsernameTextBox->Text);
			std::string password =  msclr::interop::marshal_as<std::string>(instagramUsernamePasswordTextBox->Text);
			std::string profiles = msclr::interop::marshal_as<std::string>(instagramProfilesTextBox->Text);
			double postCap = System::Convert::ToDouble(instagramProfilePostCountTextBox->Text);
			std::string exportFolderPath = msclr::interop::marshal_as<std::string>(instagramExportFolderPathValueLabel->Text);
			using ICT1009::WebScrapping::InstagramScrapper;
			typedef std::shared_ptr<InstagramScrapper> InstagramScrapperPtr;
			InstagramScrapperPtr scrapper(new InstagramScrapper);
			instagramConsole->AppendText("*Executing profile scraping procedure...\r\n");
			try {
				if (scrapper->scrapeByProfiles(username, password, profiles, static_cast<int>(postCap), exportFolderPath) == 1)
					instagramConsole->AppendText("*Finished profiles scrapping procedure. \r\n");
			} catch (...) {
				instagramConsole->AppendText("*Error occured during profiles scraping procedure...\r\n");
			}
		}
	}
	private: System::Void displayJsonSelectJsonButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (displayJsonLoadFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			displayJsonFilePathValueLabel->Text = displayJsonLoadFileDialog->FileName;
			using json = nlohmann::json;

			try {
				std::string fileName = msclr::interop::marshal_as<std::string>(displayJsonLoadFileDialog->FileName);
				std::ifstream i(fileName);
				json j; i >> j; i.close();
				std::stringstream displayOutput;
				displayOutput << std::setw(4) << j << std::endl;
				displayJsonFileOutputRichTextBox->Text = gcnew System::String(displayOutput.str().c_str());
			} catch (std::exception e) {
				std::cout << e.what() << std::endl;
			}
			

		}
	}
	private: System::Void displayJsonSaveAsButton_Click(System::Object^  sender, System::EventArgs^  e) {
		
		if (displayJsonFileOutputRichTextBox->Text != "") {
			if (displayJsonSaveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				std::string output = msclr::interop::marshal_as<std::string>(displayJsonFileOutputRichTextBox->Text);
				std::string savePath = msclr::interop::marshal_as<std::string>(displayJsonSaveFileDialog->FileName);
				if (FileUtility::saveStringToFile(output, savePath))
					MessageBox::Show(gcnew System::String(("Successfully saved to file"+savePath).c_str()));
			}
		} else {
			MessageBox::Show("There is no data in the textbox.");
		}
	}

	private: System::Void imageOcrBrowseJsonButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (imageOcrLoadFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			imageOcrFilePathValueLabel->Text = imageOcrLoadFileDialog->FileName;
		}
	}




	private: System::Void imageOcrExecuteButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (imageOcrFilePathValueLabel->Text == "None" or imageOcrFilePathValueLabel->Text == "") {
			imageOcrConsoleTextBox->AppendText("Please choose json file to conduct OCR on \r\n");
		} else {
			using nlohmann::json;
			std::string filePath = msclr::interop::marshal_as<std::string>(imageOcrFilePathValueLabel->Text);
			typedef std::shared_ptr<ICT1009::TextRecognition::OCRUtility> OCRPtr;
			OCRPtr extractor(new ICT1009::TextRecognition::OCRUtility);
			imageOcrConsoleTextBox->AppendText("Executing OCR procedure...\r\n");
			
			int returnCode = extractor->appendImagesTextToJson(filePath);
			switch (returnCode) {
				case -1:
					imageOcrConsoleTextBox->AppendText("Unable to read specified Json file\r\n");
					break;
				case -2:
					imageOcrConsoleTextBox->AppendText("Unable to append to Json file\r\n");
					break;
				default:
					if (returnCode > 1) {

						imageOcrConsoleTextBox->AppendText("Successfully appended image text to file\r\n");
					}
					//imageOcrConsoleTextBox->AppendText("Default Case\r\n");
			}
		}
	}


private: System::Void visualationBtn_Click_1(System::Object^  sender, System::EventArgs^  e)
{
	if (displayJsonLoadFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		displayJsonVisualFilePathValue->Text = displayJsonLoadFileDialog->FileName;
		using json = nlohmann::json;

		try {
			std::string fileName = msclr::interop::marshal_as<std::string>(displayJsonLoadFileDialog->FileName);
			std::ifstream i(fileName);
			json jsonObject;
			i >> jsonObject; i.close(); //Parse file into json object;
			string tempLoc;
			int counterLoc = 0;
			int location[15];
			location[0] = 0; location[1] = 0; location[2] = 0; location[3] = 0; location[4] = 0;
			location[5] = 0; location[6] = 0; location[7] = 0; location[8] = 0; location[9] = 0;
			location[10] = 0; location[11] = 0; location[12] = 0; location[13] = 0; location[14] = 0;
			string locationName[15];
			string tempDate;
			int totalCaptions = 0;
			int months[13];
			months[1] = 0; months[2] = 0; months[3] = 0; months[4] = 0; months[5] = 0; months[6] = 0;
			months[7] = 0; months[8] = 0; months[9] = 0; months[10] = 0; months[11] = 0; months[12] = 0; months[0] = 0;
			for (auto &detail : jsonObject["details"])
			{
				for (auto &post : detail["extracted_posts"])
				{

					tempLoc = post["location"].get<string>();
					//std::cout << tempLoc<<"\n";
					if (locationName[counterLoc] != tempLoc && tempLoc != "None" && counterLoc < 15) { locationName[counterLoc] = tempLoc; counterLoc++; }
					else { continue; }
				}

				for (auto &post : detail["extracted_posts"])
				{

					tempLoc = post["location"].get<string>();
					//std::cout << tempLoc<<"\n";
					for (int y = 0; y < 15; y++)
					{
						if (tempLoc == locationName[y])
						{
							location[y]++;
							break;
						}
						else
						{
							continue;
						}
					}
				}
			}
			for (auto &detail : jsonObject["details"]) {

				for (auto &post : detail["extracted_posts"]) {

					tempDate = post["date_time"].get<string>();
					totalCaptions += 1;
					if (tempDate[5] == '0')
					{
						if (tempDate[6] == '1')
						{
							months[1] += 1;
						}
						else if (tempDate[6] == '2')
						{
							months[2] += 1;
						}
						else if (tempDate[6] == '3')
						{
							months[3] += 1;
						}
						else if (tempDate[6] == '4')
						{
							months[4] += 1;
						}
						else if (tempDate[6] == '5')
						{
							months[5] += 1;
						}
						else if (tempDate[6] == '6')
						{
							months[6] += 1;
						}
						else if (tempDate[6] == '7')
						{
							months[7] += 1;
						}
						else if (tempDate[6] == '8')
						{
							months[8] += 1;
						}
						else if (tempDate[6] == '9')
						{
							months[9] += 1;
						}
					}
					else
					{
						if (tempDate[6] == '0')
						{
							months[10] += 1;
						}
						else if (tempDate[6] == '1')
						{
							months[11] += 1;
						}
						else if (tempDate[6] == '2')
						{
							months[12] += 1;
						}
					}

				}
			}
			this->PieChart->Series["Location1"]->Points->AddXY("Loc 1", location[0]);
			this->PieChart->Series["Location1"]->Points->AddXY("Loc 2", location[1]);
			this->PieChart->Series["Location1"]->Points->AddXY("Loc 3", location[2]);
			this->PieChart->Series["Location1"]->Points->AddXY("Loc 4", location[3]);
			this->PieChart->Series["Location1"]->Points->AddXY("Loc 5", location[4]);
			this->PieChart->Series["Location1"]->Points->AddXY("Loc 6", location[5]);
			this->PieChart->Series["Location1"]->Points->AddXY("Loc 7", location[6]);
			this->PieChart->Series["Location1"]->Points->AddXY("Loc 8", location[7]);
			this->PieChart->Series["Location1"]->Points->AddXY("Loc 9", location[8]);

			this->BarChart->Series["JAN"]->Points->Add(months[1]);
			this->BarChart->Series["FEB"]->Points->Add(months[2]);
			this->BarChart->Series["MARCH"]->Points->Add(months[3]);
			this->BarChart->Series["APRIL"]->Points->Add(months[4]);
			this->BarChart->Series["MAY"]->Points->Add(months[5]);
			this->BarChart->Series["JUNE"]->Points->Add(months[6]);
			this->BarChart->Series["JULY"]->Points->Add(months[7]);
			this->BarChart->Series["AUG"]->Points->Add(months[8]);
			this->BarChart->Series["SEPT"]->Points->Add(months[9]);
			this->BarChart->Series["OCT"]->Points->Add(months[10]);
			this->BarChart->Series["NOV"]->Points->Add(months[11]);
			this->BarChart->Series["DEC"]->Points->Add(months[12]);
		}
		catch (...) {
		}
	}
}

private: System::Void twitterSelectPathButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (instagramFolderDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		twitterExportPathLabel->Text = "Path: " + instagramFolderDialog->SelectedPath;
		this->twitterExportPath = instagramFolderDialog->SelectedPath;
	}
}
private: System::Void twitterScrapeHashtagsButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (twitterScrapeInProgress)
	{
		twitterConsole->AppendText("*Scraping already in progress, please wait\r\n");
		return;
	}

	bool success = true;

	//Check for valid fields
	if (twitterExportPath->Length < 1) 
	{
		twitterConsole->AppendText("*Please choose an export path\r\n");
		success = false;
	}

	if (twitterHashtagsTextBox->Text->Length < 1) 
	{
		twitterConsole->AppendText("*Please enter hashtags\r\n");
		success = false;
	}

	if (success)
	{
		twitterScrapeInProgress = true;
		twitterConsole->AppendText("*Scraping in progress\r\n");
		ICT1009::WebScrapping::TwitterScraper twitterScraper;
		twitterScraper.scrapeByHashTags("", "", msclr::interop::marshal_as<std::string>(twitterHashtagsTextBox->Text)
			, static_cast<int>(twitterNumHashtagsSelector->Value)
			, msclr::interop::marshal_as<std::string>(this->twitterExportPath->ToString()));

		twitterConsole->AppendText("*Scraping by hashtags complete\r\n");
		twitterScrapeInProgress = false;
	}
}
private: System::Void twitterScrapeProfilesButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (twitterScrapeInProgress)
	{
		twitterConsole->AppendText("*Scraping already in progress, please wait\r\n");
		return;
	}

	bool success = true;

	//Check for valid fields
	if (twitterExportPath->Length < 1)
	{
		twitterConsole->AppendText("*Please choose an export path\r\n");
		success = false;
	}

	if (twitterProfilesTextBox->Text->Length < 1)
	{
		twitterConsole->AppendText("*Please enter profiles\r\n");
		success = false;
	}

	if (success)
	{
		twitterScrapeInProgress = true;
		twitterConsole->AppendText("*Scraping in progress\r\n");
		ICT1009::WebScrapping::TwitterScraper twitterScraper;
		twitterScraper.scrapeByProfiles("", "", msclr::interop::marshal_as<std::string>(twitterProfilesTextBox->Text)
			, static_cast<int>(twitterNumProfilesSelector->Value)
			, msclr::interop::marshal_as<std::string>(this->twitterExportPath->ToString()));

		twitterConsole->AppendText("*Scraping by profiles complete\r\n");
		twitterScrapeInProgress = false;
	}
}
private: System::Void analysisSelectFileButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
	using ICT1009::Analysis::DataAnalyser;
	using ICT1009::Analysis::AnalysedData;
	using ICT1009::DataStorage::ScrapeStorage;

	if (displayJsonLoadFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) 
	{
		analysisFilePathLabel->Text = "File loaded: " + displayJsonLoadFileDialog->FileName;

		try 
		{
			std::string filePath = msclr::interop::marshal_as<std::string>(displayJsonLoadFileDialog->FileName);
			ScrapeStorage data(filePath);

			//std::cout << data.getScrapePlatform() << std::endl;

			//for (auto details : data.getScrapedDetails())
			//{
			//	std::cout << "DETAIL 2" << std::endl;
			//	for (auto post : details.get()->getPostList())
			//	{
			//		std::cout << "POST 2" << std::endl;
			//		std::cout << post.get()->getCaption() << std::endl;
			//	}
			//}

			AnalysedData analysedData = DataAnalyser::Analyse(&data);
			analysisAvgLikesLabel->Text = "Avg likes: " + analysedData.getAvgLikes().ToString();
			analysisAvgPostLengthLabel->Text = "Avg post lenth: " + analysedData.getAvgChars().ToString();
			analysisAvgWordsLabel->Text = "Avg words per post: " + analysedData.getAvgWords().ToString();
			analysisAvgHashtagsLabel->Text = "Avg hashtags per post: " + analysedData.getAvgHashtags().ToString();
			analysisNumPostsLabel->Text = "No. of posts: " + analysedData.getNumPosts().ToString();

			std::string scrapeTargets = "";
			for (auto target : *analysedData.getScrapeTargets())
				scrapeTargets += target + " ";

			analysisScrapeTargetLabel->Text = "Target " + (analysedData.getScrapeType() == "Hashtags" ? "hashtags: " : "profiles: ") + (gcnew String(scrapeTargets.c_str()));

			std::map<std::string, unsigned int> sorted_hashtags(analysedData.getRelatedHashtags()->begin(), analysedData.getRelatedHashtags()->end());
			for (auto item = sorted_hashtags.begin(); item != sorted_hashtags.end(); ++item)
			{
				analysisRelatedHashtagsTable->Rows->Add(gcnew String(item->first.c_str()), (static_cast<float>(item->second) / analysedData.getNumPosts()).ToString(),item->second.ToString());
			}
		}
		catch (std::exception e) 
		{
			std::cout << "Data analysis failed: ";
			std::cout << e.what() << std::endl;
		}
	}
}
}; //Endpoint
}

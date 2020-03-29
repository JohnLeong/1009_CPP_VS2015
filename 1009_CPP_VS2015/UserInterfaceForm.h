#pragma once
#include <string>
#include <iostream>
#include "InstagramScrapper.h"
#include "TwitterScraper.h"
#include "FileUtility.h"
#include "OCRUtility.h"
#include "DataAnalyser.h"
#include "SentimentAnalyser.h"
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
	private: System::Boolean wordmapGenerated = false;
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
private: System::Windows::Forms::DataVisualization::Charting::Chart^  visualisationMonthlyChart;




private: System::Windows::Forms::DataVisualization::Charting::Chart^  visualisationLocationChart;


private: System::Windows::Forms::Button^  visualationBtn;

private: System::Windows::Forms::Label^  jsonVisualFilePath;
private: System::Windows::Forms::Label^  visualisationFilePathLabel;

private: System::Windows::Forms::TextBox^  twitterConsole;
private: System::Windows::Forms::PictureBox^  analysisWordmap;
private: System::Windows::Forms::PictureBox^  aboutSeleniumPicture;







private: System::Windows::Forms::PictureBox^  aboutCppPicture;






private: System::Windows::Forms::Label^  aboutMember1Label;

private: System::Windows::Forms::PictureBox^  aboutMember4Picture;

private: System::Windows::Forms::PictureBox^  aboutMember3Picture;

private: System::Windows::Forms::PictureBox^  aboutMember2Picture;

private: System::Windows::Forms::PictureBox^  aboutMember1Picture;

private: System::Windows::Forms::Label^  aboutMemberLabel;

private: System::Windows::Forms::Label^  aboutGroup34Label;

private: System::Windows::Forms::Label^  aboutTechnologiesLabel;
private: System::Windows::Forms::Label^  aboutMember4Label;


private: System::Windows::Forms::Label^  aboutMember3Label;

private: System::Windows::Forms::Label^  aboutMember2Label;

private: System::Windows::Forms::PictureBox^  aboutInstagramPicture;

private: System::Windows::Forms::PictureBox^  aboutTwitterPicture;
private: System::Windows::Forms::Button^  visualisationLocationButton;

private: System::Windows::Forms::Button^  visualisationMonthlyButton;
private: System::Windows::Forms::Button^  visualisationSentimentButton;
private: System::Windows::Forms::OpenFileDialog^  visualisationLoadFileDialog;
private: System::Windows::Forms::DataVisualization::Charting::Chart^  visualisationSentimentChart;









































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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series15 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea5 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series16 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea6 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series17 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series18 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series19 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series20 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series21 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series22 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series23 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series24 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series25 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series26 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series27 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series28 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
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
			this->analysisWordmap = (gcnew System::Windows::Forms::PictureBox());
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
			this->visualisationSentimentChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->visualisationLocationButton = (gcnew System::Windows::Forms::Button());
			this->visualisationMonthlyButton = (gcnew System::Windows::Forms::Button());
			this->visualisationSentimentButton = (gcnew System::Windows::Forms::Button());
			this->visualisationFilePathLabel = (gcnew System::Windows::Forms::Label());
			this->jsonVisualFilePath = (gcnew System::Windows::Forms::Label());
			this->visualationBtn = (gcnew System::Windows::Forms::Button());
			this->visualisationLocationChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->visualisationMonthlyChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
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
			this->aboutInstagramPicture = (gcnew System::Windows::Forms::PictureBox());
			this->aboutTwitterPicture = (gcnew System::Windows::Forms::PictureBox());
			this->aboutMemberLabel = (gcnew System::Windows::Forms::Label());
			this->aboutGroup34Label = (gcnew System::Windows::Forms::Label());
			this->aboutTechnologiesLabel = (gcnew System::Windows::Forms::Label());
			this->aboutMember4Label = (gcnew System::Windows::Forms::Label());
			this->aboutMember3Label = (gcnew System::Windows::Forms::Label());
			this->aboutMember2Label = (gcnew System::Windows::Forms::Label());
			this->aboutSeleniumPicture = (gcnew System::Windows::Forms::PictureBox());
			this->aboutCppPicture = (gcnew System::Windows::Forms::PictureBox());
			this->aboutMember1Label = (gcnew System::Windows::Forms::Label());
			this->aboutMember4Picture = (gcnew System::Windows::Forms::PictureBox());
			this->aboutMember3Picture = (gcnew System::Windows::Forms::PictureBox());
			this->aboutMember2Picture = (gcnew System::Windows::Forms::PictureBox());
			this->aboutMember1Picture = (gcnew System::Windows::Forms::PictureBox());
			this->instagramFolderDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->displayJsonLoadFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->displayJsonSaveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->imageOcrLoadFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->visualisationLoadFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->sidePanelBacking->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sitLogo))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->instagramTab->SuspendLayout();
			this->twitterTab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->twitterNumProfilesSelector))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->twitterNumHashtagsSelector))->BeginInit();
			this->displayJsonTab->SuspendLayout();
			this->dataAnalysisTab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->analysisWordmap))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->analysisRelatedHashtagsTable))->BeginInit();
			this->visualisationTab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->visualisationSentimentChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->visualisationLocationChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->visualisationMonthlyChart))->BeginInit();
			this->imageOcrTab->SuspendLayout();
			this->aboutTab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aboutInstagramPicture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aboutTwitterPicture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aboutSeleniumPicture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aboutCppPicture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aboutMember4Picture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aboutMember3Picture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aboutMember2Picture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aboutMember1Picture))->BeginInit();
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
			this->instagramConsole->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->instagramConsole->Location = System::Drawing::Point(12, 559);
			this->instagramConsole->Multiline = true;
			this->instagramConsole->Name = L"instagramConsole";
			this->instagramConsole->ReadOnly = true;
			this->instagramConsole->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->instagramConsole->Size = System::Drawing::Size(819, 102);
			this->instagramConsole->TabIndex = 22;
			// 
			// instagramExportFolderPathValueLabel
			// 
			this->instagramExportFolderPathValueLabel->AutoSize = true;
			this->instagramExportFolderPathValueLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->instagramExportFolderPathValueLabel->Location = System::Drawing::Point(51, 90);
			this->instagramExportFolderPathValueLabel->Name = L"instagramExportFolderPathValueLabel";
			this->instagramExportFolderPathValueLabel->Size = System::Drawing::Size(47, 20);
			this->instagramExportFolderPathValueLabel->TabIndex = 21;
			this->instagramExportFolderPathValueLabel->Text = L"None";
			// 
			// instagramBrowseExportFolderButton
			// 
			this->instagramBrowseExportFolderButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->instagramBrowseExportFolderButton->Location = System::Drawing::Point(12, 114);
			this->instagramBrowseExportFolderButton->Name = L"instagramBrowseExportFolderButton";
			this->instagramBrowseExportFolderButton->Size = System::Drawing::Size(122, 32);
			this->instagramBrowseExportFolderButton->TabIndex = 20;
			this->instagramBrowseExportFolderButton->Text = L"Select folder path";
			this->instagramBrowseExportFolderButton->UseVisualStyleBackColor = true;
			this->instagramBrowseExportFolderButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::instagramBrowseExportFolderButton_Click);
			// 
			// instagramExportFolderPathLabel
			// 
			this->instagramExportFolderPathLabel->AutoSize = true;
			this->instagramExportFolderPathLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->instagramExportFolderPathLabel->Location = System::Drawing::Point(8, 90);
			this->instagramExportFolderPathLabel->Name = L"instagramExportFolderPathLabel";
			this->instagramExportFolderPathLabel->Size = System::Drawing::Size(50, 20);
			this->instagramExportFolderPathLabel->TabIndex = 19;
			this->instagramExportFolderPathLabel->Text = L"Path: ";
			// 
			// instagramExportLabel
			// 
			this->instagramExportLabel->AutoSize = true;
			this->instagramExportLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->instagramExportLabel->Location = System::Drawing::Point(8, 62);
			this->instagramExportLabel->Name = L"instagramExportLabel";
			this->instagramExportLabel->Size = System::Drawing::Size(137, 22);
			this->instagramExportLabel->TabIndex = 19;
			this->instagramExportLabel->Text = L"Export Folder:";
			// 
			// instagramProfileExecuteButton
			// 
			this->instagramProfileExecuteButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->instagramProfileExecuteButton->Location = System::Drawing::Point(431, 496);
			this->instagramProfileExecuteButton->Name = L"instagramProfileExecuteButton";
			this->instagramProfileExecuteButton->Size = System::Drawing::Size(350, 35);
			this->instagramProfileExecuteButton->TabIndex = 18;
			this->instagramProfileExecuteButton->Text = L"Execute";
			this->instagramProfileExecuteButton->UseVisualStyleBackColor = true;
			this->instagramProfileExecuteButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::instagramProfileExecuteButton_Click);
			// 
			// instagramHashTagExecuteButton
			// 
			this->instagramHashTagExecuteButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->instagramHashTagExecuteButton->Location = System::Drawing::Point(12, 496);
			this->instagramHashTagExecuteButton->Name = L"instagramHashTagExecuteButton";
			this->instagramHashTagExecuteButton->Size = System::Drawing::Size(350, 35);
			this->instagramHashTagExecuteButton->TabIndex = 17;
			this->instagramHashTagExecuteButton->Text = L"Execute";
			this->instagramHashTagExecuteButton->UseVisualStyleBackColor = true;
			this->instagramHashTagExecuteButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::instagramHashTagExecuteButton_Click);
			// 
			// instagramProfilesTextBox
			// 
			this->instagramProfilesTextBox->Location = System::Drawing::Point(431, 358);
			this->instagramProfilesTextBox->Multiline = true;
			this->instagramProfilesTextBox->Name = L"instagramProfilesTextBox";
			this->instagramProfilesTextBox->Size = System::Drawing::Size(350, 132);
			this->instagramProfilesTextBox->TabIndex = 16;
			this->instagramProfilesTextBox->TextChanged += gcnew System::EventHandler(this, &UserInterfaceForm::textBox8_TextChanged);
			// 
			// instagramProfilePostCountTextBox
			// 
			this->instagramProfilePostCountTextBox->Location = System::Drawing::Point(431, 303);
			this->instagramProfilePostCountTextBox->Name = L"instagramProfilePostCountTextBox";
			this->instagramProfilePostCountTextBox->Size = System::Drawing::Size(126, 29);
			this->instagramProfilePostCountTextBox->TabIndex = 15;
			// 
			// instagramHashTagsTextBox
			// 
			this->instagramHashTagsTextBox->Location = System::Drawing::Point(12, 358);
			this->instagramHashTagsTextBox->Multiline = true;
			this->instagramHashTagsTextBox->Name = L"instagramHashTagsTextBox";
			this->instagramHashTagsTextBox->Size = System::Drawing::Size(350, 132);
			this->instagramHashTagsTextBox->TabIndex = 14;
			// 
			// instagramHashTagPostCountTextBox
			// 
			this->instagramHashTagPostCountTextBox->Location = System::Drawing::Point(12, 303);
			this->instagramHashTagPostCountTextBox->Name = L"instagramHashTagPostCountTextBox";
			this->instagramHashTagPostCountTextBox->Size = System::Drawing::Size(126, 29);
			this->instagramHashTagPostCountTextBox->TabIndex = 13;
			// 
			// instagramUsernamePasswordTextBox
			// 
			this->instagramUsernamePasswordTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->instagramUsernamePasswordTextBox->Location = System::Drawing::Point(444, 184);
			this->instagramUsernamePasswordTextBox->Name = L"instagramUsernamePasswordTextBox";
			this->instagramUsernamePasswordTextBox->PasswordChar = '*';
			this->instagramUsernamePasswordTextBox->Size = System::Drawing::Size(126, 26);
			this->instagramUsernamePasswordTextBox->TabIndex = 10;
			this->instagramUsernamePasswordTextBox->Text = L"Password12345";
			// 
			// instagramUsernameTextBox
			// 
			this->instagramUsernameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->instagramUsernameTextBox->Location = System::Drawing::Point(104, 184);
			this->instagramUsernameTextBox->Name = L"instagramUsernameTextBox";
			this->instagramUsernameTextBox->Size = System::Drawing::Size(126, 26);
			this->instagramUsernameTextBox->TabIndex = 9;
			this->instagramUsernameTextBox->Text = L"hehebongesher";
			// 
			// instagramProfilesLabel
			// 
			this->instagramProfilesLabel->AutoSize = true;
			this->instagramProfilesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->instagramProfilesLabel->Location = System::Drawing::Point(427, 338);
			this->instagramProfilesLabel->Name = L"instagramProfilesLabel";
			this->instagramProfilesLabel->Size = System::Drawing::Size(69, 20);
			this->instagramProfilesLabel->TabIndex = 8;
			this->instagramProfilesLabel->Text = L"Profiles";
			this->instagramProfilesLabel->Click += gcnew System::EventHandler(this, &UserInterfaceForm::instagramProfilesLabel_Click);
			// 
			// instagramHashTagsLabel
			// 
			this->instagramHashTagsLabel->AutoSize = true;
			this->instagramHashTagsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->instagramHashTagsLabel->Location = System::Drawing::Point(8, 338);
			this->instagramHashTagsLabel->Name = L"instagramHashTagsLabel";
			this->instagramHashTagsLabel->Size = System::Drawing::Size(90, 20);
			this->instagramHashTagsLabel->TabIndex = 7;
			this->instagramHashTagsLabel->Text = L"HashTags";
			// 
			// instagramProfileNumberOfPostLabel
			// 
			this->instagramProfileNumberOfPostLabel->AutoSize = true;
			this->instagramProfileNumberOfPostLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->instagramProfileNumberOfPostLabel->Location = System::Drawing::Point(426, 277);
			this->instagramProfileNumberOfPostLabel->Name = L"instagramProfileNumberOfPostLabel";
			this->instagramProfileNumberOfPostLabel->Size = System::Drawing::Size(127, 20);
			this->instagramProfileNumberOfPostLabel->TabIndex = 6;
			this->instagramProfileNumberOfPostLabel->Text = L"Number of Posts";
			// 
			// instagramHashTagNumberOfPostLabel
			// 
			this->instagramHashTagNumberOfPostLabel->AutoSize = true;
			this->instagramHashTagNumberOfPostLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->instagramHashTagNumberOfPostLabel->Location = System::Drawing::Point(7, 277);
			this->instagramHashTagNumberOfPostLabel->Name = L"instagramHashTagNumberOfPostLabel";
			this->instagramHashTagNumberOfPostLabel->Size = System::Drawing::Size(127, 20);
			this->instagramHashTagNumberOfPostLabel->TabIndex = 5;
			this->instagramHashTagNumberOfPostLabel->Text = L"Number of Posts";
			// 
			// instagramProfileModeLabel
			// 
			this->instagramProfileModeLabel->AutoSize = true;
			this->instagramProfileModeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->instagramProfileModeLabel->Location = System::Drawing::Point(427, 245);
			this->instagramProfileModeLabel->Name = L"instagramProfileModeLabel";
			this->instagramProfileModeLabel->Size = System::Drawing::Size(122, 22);
			this->instagramProfileModeLabel->TabIndex = 4;
			this->instagramProfileModeLabel->Text = L"Profile Mode";
			// 
			// instagramHashTagModeLabel
			// 
			this->instagramHashTagModeLabel->AutoSize = true;
			this->instagramHashTagModeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->instagramHashTagModeLabel->Location = System::Drawing::Point(8, 245);
			this->instagramHashTagModeLabel->Name = L"instagramHashTagModeLabel";
			this->instagramHashTagModeLabel->Size = System::Drawing::Size(145, 22);
			this->instagramHashTagModeLabel->TabIndex = 3;
			this->instagramHashTagModeLabel->Text = L"HashTag Mode";
			// 
			// instagramPasswordLabel
			// 
			this->instagramPasswordLabel->AutoSize = true;
			this->instagramPasswordLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->instagramPasswordLabel->Location = System::Drawing::Point(344, 187);
			this->instagramPasswordLabel->Name = L"instagramPasswordLabel";
			this->instagramPasswordLabel->Size = System::Drawing::Size(88, 20);
			this->instagramPasswordLabel->TabIndex = 2;
			this->instagramPasswordLabel->Text = L"Password:";
			// 
			// instagramUsernameLabel
			// 
			this->instagramUsernameLabel->AutoSize = true;
			this->instagramUsernameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->instagramUsernameLabel->Location = System::Drawing::Point(7, 187);
			this->instagramUsernameLabel->Name = L"instagramUsernameLabel";
			this->instagramUsernameLabel->Size = System::Drawing::Size(91, 20);
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
			this->displayJsonFileOutputRichTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->displayJsonFileOutputRichTextBox->Location = System::Drawing::Point(12, 152);
			this->displayJsonFileOutputRichTextBox->Name = L"displayJsonFileOutputRichTextBox";
			this->displayJsonFileOutputRichTextBox->Size = System::Drawing::Size(819, 518);
			this->displayJsonFileOutputRichTextBox->TabIndex = 6;
			this->displayJsonFileOutputRichTextBox->Text = L"";
			// 
			// displayJsonFilePathValueLabel
			// 
			this->displayJsonFilePathValueLabel->AutoSize = true;
			this->displayJsonFilePathValueLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->displayJsonFilePathValueLabel->Location = System::Drawing::Point(97, 90);
			this->displayJsonFilePathValueLabel->Name = L"displayJsonFilePathValueLabel";
			this->displayJsonFilePathValueLabel->Size = System::Drawing::Size(47, 20);
			this->displayJsonFilePathValueLabel->TabIndex = 5;
			this->displayJsonFilePathValueLabel->Text = L"None";
			// 
			// displayJsonSaveAsButton
			// 
			this->displayJsonSaveAsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->displayJsonSaveAsButton->Location = System::Drawing::Point(144, 114);
			this->displayJsonSaveAsButton->Name = L"displayJsonSaveAsButton";
			this->displayJsonSaveAsButton->Size = System::Drawing::Size(122, 32);
			this->displayJsonSaveAsButton->TabIndex = 4;
			this->displayJsonSaveAsButton->Text = L"Save As";
			this->displayJsonSaveAsButton->UseVisualStyleBackColor = true;
			this->displayJsonSaveAsButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::displayJsonSaveAsButton_Click);
			// 
			// displayJsonSelectJsonButton
			// 
			this->displayJsonSelectJsonButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->displayJsonSelectJsonButton->Location = System::Drawing::Point(12, 114);
			this->displayJsonSelectJsonButton->Name = L"displayJsonSelectJsonButton";
			this->displayJsonSelectJsonButton->Size = System::Drawing::Size(122, 32);
			this->displayJsonSelectJsonButton->TabIndex = 3;
			this->displayJsonSelectJsonButton->Text = L"Select file";
			this->displayJsonSelectJsonButton->UseVisualStyleBackColor = true;
			this->displayJsonSelectJsonButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::displayJsonSelectJsonButton_Click);
			// 
			// displayJsonFilePathLabel
			// 
			this->displayJsonFilePathLabel->AutoSize = true;
			this->displayJsonFilePathLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->displayJsonFilePathLabel->Location = System::Drawing::Point(8, 90);
			this->displayJsonFilePathLabel->Name = L"displayJsonFilePathLabel";
			this->displayJsonFilePathLabel->Size = System::Drawing::Size(94, 20);
			this->displayJsonFilePathLabel->TabIndex = 2;
			this->displayJsonFilePathLabel->Text = L"File loaded: ";
			// 
			// displayJsonFilePathHeaderLabel
			// 
			this->displayJsonFilePathHeaderLabel->AutoSize = true;
			this->displayJsonFilePathHeaderLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->displayJsonFilePathHeaderLabel->Location = System::Drawing::Point(8, 62);
			this->displayJsonFilePathHeaderLabel->Name = L"displayJsonFilePathHeaderLabel";
			this->displayJsonFilePathHeaderLabel->Size = System::Drawing::Size(119, 22);
			this->displayJsonFilePathHeaderLabel->TabIndex = 1;
			this->displayJsonFilePathHeaderLabel->Text = L"File location";
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
			this->dataAnalysisTab->Controls->Add(this->analysisWordmap);
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
			// analysisWordmap
			// 
			this->analysisWordmap->BackColor = System::Drawing::Color::Gainsboro;
			this->analysisWordmap->Location = System::Drawing::Point(551, 358);
			this->analysisWordmap->Name = L"analysisWordmap";
			this->analysisWordmap->Size = System::Drawing::Size(256, 256);
			this->analysisWordmap->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->analysisWordmap->TabIndex = 14;
			this->analysisWordmap->TabStop = false;
			this->analysisWordmap->Click += gcnew System::EventHandler(this, &UserInterfaceForm::analysisWordmap_Click);
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
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->analysisRelatedHashtagsTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->analysisRelatedHashtagsTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->analysisRelatedHashtagsTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->HashtagColumn,
					this->FreqColumn, this->TotalColumn
			});
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->analysisRelatedHashtagsTable->DefaultCellStyle = dataGridViewCellStyle4;
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
			this->visualisationTab->Controls->Add(this->visualisationFilePathLabel);
			this->visualisationTab->Controls->Add(this->visualisationSentimentChart);
			this->visualisationTab->Controls->Add(this->visualisationLocationButton);
			this->visualisationTab->Controls->Add(this->visualisationMonthlyButton);
			this->visualisationTab->Controls->Add(this->visualisationSentimentButton);
			this->visualisationTab->Controls->Add(this->jsonVisualFilePath);
			this->visualisationTab->Controls->Add(this->visualationBtn);
			this->visualisationTab->Controls->Add(this->visualisationLocationChart);
			this->visualisationTab->Controls->Add(this->visualisationMonthlyChart);
			this->visualisationTab->Controls->Add(this->visualisationHeaderLabel);
			this->visualisationTab->Location = System::Drawing::Point(4, 33);
			this->visualisationTab->Name = L"visualisationTab";
			this->visualisationTab->Size = System::Drawing::Size(852, 709);
			this->visualisationTab->TabIndex = 5;
			this->visualisationTab->Text = L"5";
			this->visualisationTab->UseVisualStyleBackColor = true;
			// 
			// visualisationSentimentChart
			// 
			chartArea4->Name = L"ChartArea1";
			this->visualisationSentimentChart->ChartAreas->Add(chartArea4);
			legend4->Name = L"Legend1";
			this->visualisationSentimentChart->Legends->Add(legend4);
			this->visualisationSentimentChart->Location = System::Drawing::Point(269, 90);
			this->visualisationSentimentChart->Name = L"visualisationSentimentChart";
			series15->ChartArea = L"ChartArea1";
			series15->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
			series15->Legend = L"Legend1";
			series15->Name = L"Series1";
			this->visualisationSentimentChart->Series->Add(series15);
			this->visualisationSentimentChart->Size = System::Drawing::Size(550, 395);
			this->visualisationSentimentChart->TabIndex = 13;
			this->visualisationSentimentChart->Text = L"chart1";
			// 
			// visualisationLocationButton
			// 
			this->visualisationLocationButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->visualisationLocationButton->Location = System::Drawing::Point(12, 311);
			this->visualisationLocationButton->Name = L"visualisationLocationButton";
			this->visualisationLocationButton->Size = System::Drawing::Size(139, 51);
			this->visualisationLocationButton->TabIndex = 12;
			this->visualisationLocationButton->Text = L"View posts by location";
			this->visualisationLocationButton->UseVisualStyleBackColor = true;
			this->visualisationLocationButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::visualisationLocationButton_Click);
			// 
			// visualisationMonthlyButton
			// 
			this->visualisationMonthlyButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->visualisationMonthlyButton->Location = System::Drawing::Point(12, 246);
			this->visualisationMonthlyButton->Name = L"visualisationMonthlyButton";
			this->visualisationMonthlyButton->Size = System::Drawing::Size(139, 51);
			this->visualisationMonthlyButton->TabIndex = 11;
			this->visualisationMonthlyButton->Text = L"View monthly posts";
			this->visualisationMonthlyButton->UseVisualStyleBackColor = true;
			this->visualisationMonthlyButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::visualisationMonthlyButton_Click);
			// 
			// visualisationSentimentButton
			// 
			this->visualisationSentimentButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->visualisationSentimentButton->Location = System::Drawing::Point(12, 181);
			this->visualisationSentimentButton->Name = L"visualisationSentimentButton";
			this->visualisationSentimentButton->Size = System::Drawing::Size(139, 51);
			this->visualisationSentimentButton->TabIndex = 10;
			this->visualisationSentimentButton->Text = L"View sentiment analysis";
			this->visualisationSentimentButton->UseVisualStyleBackColor = true;
			this->visualisationSentimentButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::visualisationSentimentButton_Click);
			// 
			// visualisationFilePathLabel
			// 
			this->visualisationFilePathLabel->AutoSize = true;
			this->visualisationFilePathLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::World, static_cast<System::Byte>(0)));
			this->visualisationFilePathLabel->Location = System::Drawing::Point(8, 90);
			this->visualisationFilePathLabel->Name = L"visualisationFilePathLabel";
			this->visualisationFilePathLabel->Size = System::Drawing::Size(190, 20);
			this->visualisationFilePathLabel->TabIndex = 9;
			this->visualisationFilePathLabel->Text = L"File loaded: No file loaded";
			// 
			// jsonVisualFilePath
			// 
			this->jsonVisualFilePath->AutoSize = true;
			this->jsonVisualFilePath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->jsonVisualFilePath->Location = System::Drawing::Point(8, 62);
			this->jsonVisualFilePath->Name = L"jsonVisualFilePath";
			this->jsonVisualFilePath->Size = System::Drawing::Size(102, 22);
			this->jsonVisualFilePath->TabIndex = 8;
			this->jsonVisualFilePath->Text = L"File Path: ";
			// 
			// visualationBtn
			// 
			this->visualationBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->visualationBtn->Location = System::Drawing::Point(12, 112);
			this->visualationBtn->Name = L"visualationBtn";
			this->visualationBtn->Size = System::Drawing::Size(122, 32);
			this->visualationBtn->TabIndex = 7;
			this->visualationBtn->Text = L"Select File";
			this->visualationBtn->UseVisualStyleBackColor = true;
			this->visualationBtn->Click += gcnew System::EventHandler(this, &UserInterfaceForm::visualationBtn_Click_1);
			// 
			// visualisationLocationChart
			// 
			chartArea5->Name = L"ChartArea1";
			this->visualisationLocationChart->ChartAreas->Add(chartArea5);
			legend5->Name = L"Legend1";
			legend5->Title = L"Visualation Number Of Location Base On Post";
			this->visualisationLocationChart->Legends->Add(legend5);
			this->visualisationLocationChart->Location = System::Drawing::Point(269, 90);
			this->visualisationLocationChart->Name = L"visualisationLocationChart";
			series16->ChartArea = L"ChartArea1";
			series16->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
			series16->EmptyPointStyle->Name = L"Location";
			series16->Legend = L"Legend1";
			series16->Name = L"Location1";
			series16->YValuesPerPoint = 4;
			this->visualisationLocationChart->Series->Add(series16);
			this->visualisationLocationChart->Size = System::Drawing::Size(565, 451);
			this->visualisationLocationChart->TabIndex = 6;
			this->visualisationLocationChart->Text = L"PieChart";
			// 
			// visualisationMonthlyChart
			// 
			chartArea6->Name = L"ChartArea1";
			this->visualisationMonthlyChart->ChartAreas->Add(chartArea6);
			legend6->BackGradientStyle = System::Windows::Forms::DataVisualization::Charting::GradientStyle::LeftRight;
			legend6->IsEquallySpacedItems = true;
			legend6->LegendStyle = System::Windows::Forms::DataVisualization::Charting::LegendStyle::Column;
			legend6->Name = L"VisualationNumberOfPostPerMonth";
			legend6->Title = L"Visualation Number Of Post Per Month";
			this->visualisationMonthlyChart->Legends->Add(legend6);
			this->visualisationMonthlyChart->Location = System::Drawing::Point(257, 105);
			this->visualisationMonthlyChart->Name = L"visualisationMonthlyChart";
			series17->ChartArea = L"ChartArea1";
			series17->Legend = L"VisualationNumberOfPostPerMonth";
			series17->Name = L"JAN";
			series18->ChartArea = L"ChartArea1";
			series18->Legend = L"VisualationNumberOfPostPerMonth";
			series18->Name = L"FEB";
			series19->ChartArea = L"ChartArea1";
			series19->Legend = L"VisualationNumberOfPostPerMonth";
			series19->Name = L"MARCH";
			series20->ChartArea = L"ChartArea1";
			series20->Legend = L"VisualationNumberOfPostPerMonth";
			series20->Name = L"APRIL";
			series21->ChartArea = L"ChartArea1";
			series21->Legend = L"VisualationNumberOfPostPerMonth";
			series21->Name = L"MAY";
			series22->ChartArea = L"ChartArea1";
			series22->Legend = L"VisualationNumberOfPostPerMonth";
			series22->Name = L"JUNE";
			series23->ChartArea = L"ChartArea1";
			series23->Legend = L"VisualationNumberOfPostPerMonth";
			series23->Name = L"JULY";
			series24->ChartArea = L"ChartArea1";
			series24->Legend = L"VisualationNumberOfPostPerMonth";
			series24->Name = L"AUG";
			series25->ChartArea = L"ChartArea1";
			series25->Legend = L"VisualationNumberOfPostPerMonth";
			series25->Name = L"SEPT";
			series26->ChartArea = L"ChartArea1";
			series26->Legend = L"VisualationNumberOfPostPerMonth";
			series26->Name = L"OCT";
			series27->ChartArea = L"ChartArea1";
			series27->Legend = L"VisualationNumberOfPostPerMonth";
			series27->Name = L"NOV";
			series28->ChartArea = L"ChartArea1";
			series28->Legend = L"VisualationNumberOfPostPerMonth";
			series28->Name = L"DEC";
			this->visualisationMonthlyChart->Series->Add(series17);
			this->visualisationMonthlyChart->Series->Add(series18);
			this->visualisationMonthlyChart->Series->Add(series19);
			this->visualisationMonthlyChart->Series->Add(series20);
			this->visualisationMonthlyChart->Series->Add(series21);
			this->visualisationMonthlyChart->Series->Add(series22);
			this->visualisationMonthlyChart->Series->Add(series23);
			this->visualisationMonthlyChart->Series->Add(series24);
			this->visualisationMonthlyChart->Series->Add(series25);
			this->visualisationMonthlyChart->Series->Add(series26);
			this->visualisationMonthlyChart->Series->Add(series27);
			this->visualisationMonthlyChart->Series->Add(series28);
			this->visualisationMonthlyChart->Size = System::Drawing::Size(562, 380);
			this->visualisationMonthlyChart->TabIndex = 1;
			this->visualisationMonthlyChart->Text = L"BarChart";
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
			this->imageOcrExecuteButton->Location = System::Drawing::Point(223, 280);
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
			this->imageOcrBrowseJsonButton->Size = System::Drawing::Size(75, 56);
			this->imageOcrBrowseJsonButton->TabIndex = 5;
			this->imageOcrBrowseJsonButton->Text = L"Browse";
			this->imageOcrBrowseJsonButton->UseVisualStyleBackColor = true;
			this->imageOcrBrowseJsonButton->Click += gcnew System::EventHandler(this, &UserInterfaceForm::imageOcrBrowseJsonButton_Click);
			// 
			// imageOcrFilePathHeaderLabel
			// 
			this->imageOcrFilePathHeaderLabel->AutoSize = true;
			this->imageOcrFilePathHeaderLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->imageOcrFilePathHeaderLabel->Location = System::Drawing::Point(50, 174);
			this->imageOcrFilePathHeaderLabel->Name = L"imageOcrFilePathHeaderLabel";
			this->imageOcrFilePathHeaderLabel->Size = System::Drawing::Size(200, 32);
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
			this->imageOcrDescriptionLabel->Location = System::Drawing::Point(44, 73);
			this->imageOcrDescriptionLabel->Name = L"imageOcrDescriptionLabel";
			this->imageOcrDescriptionLabel->Size = System::Drawing::Size(779, 157);
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
			this->aboutTab->BackColor = System::Drawing::Color::Transparent;
			this->aboutTab->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->aboutTab->Controls->Add(this->aboutInstagramPicture);
			this->aboutTab->Controls->Add(this->aboutTwitterPicture);
			this->aboutTab->Controls->Add(this->aboutMemberLabel);
			this->aboutTab->Controls->Add(this->aboutGroup34Label);
			this->aboutTab->Controls->Add(this->aboutTechnologiesLabel);
			this->aboutTab->Controls->Add(this->aboutMember4Label);
			this->aboutTab->Controls->Add(this->aboutMember3Label);
			this->aboutTab->Controls->Add(this->aboutMember2Label);
			this->aboutTab->Controls->Add(this->aboutSeleniumPicture);
			this->aboutTab->Controls->Add(this->aboutCppPicture);
			this->aboutTab->Controls->Add(this->aboutMember1Label);
			this->aboutTab->Controls->Add(this->aboutMember4Picture);
			this->aboutTab->Controls->Add(this->aboutMember3Picture);
			this->aboutTab->Controls->Add(this->aboutMember2Picture);
			this->aboutTab->Controls->Add(this->aboutMember1Picture);
			this->aboutTab->Location = System::Drawing::Point(4, 33);
			this->aboutTab->Name = L"aboutTab";
			this->aboutTab->Size = System::Drawing::Size(852, 709);
			this->aboutTab->TabIndex = 7;
			this->aboutTab->Text = L"7";
			// 
			// aboutInstagramPicture
			// 
			this->aboutInstagramPicture->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"aboutInstagramPicture.Image")));
			this->aboutInstagramPicture->Location = System::Drawing::Point(629, 113);
			this->aboutInstagramPicture->Name = L"aboutInstagramPicture";
			this->aboutInstagramPicture->Size = System::Drawing::Size(179, 163);
			this->aboutInstagramPicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->aboutInstagramPicture->TabIndex = 24;
			this->aboutInstagramPicture->TabStop = false;
			// 
			// aboutTwitterPicture
			// 
			this->aboutTwitterPicture->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"aboutTwitterPicture.Image")));
			this->aboutTwitterPicture->Location = System::Drawing::Point(409, 107);
			this->aboutTwitterPicture->Name = L"aboutTwitterPicture";
			this->aboutTwitterPicture->Size = System::Drawing::Size(172, 169);
			this->aboutTwitterPicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->aboutTwitterPicture->TabIndex = 23;
			this->aboutTwitterPicture->TabStop = false;
			// 
			// aboutMemberLabel
			// 
			this->aboutMemberLabel->AutoSize = true;
			this->aboutMemberLabel->Font = (gcnew System::Drawing::Font(L"Microsoft PhagsPa", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->aboutMemberLabel->ForeColor = System::Drawing::SystemColors::ControlText;
			this->aboutMemberLabel->Location = System::Drawing::Point(352, 343);
			this->aboutMemberLabel->Name = L"aboutMemberLabel";
			this->aboutMemberLabel->Size = System::Drawing::Size(141, 41);
			this->aboutMemberLabel->TabIndex = 22;
			this->aboutMemberLabel->Text = L"Member";
			// 
			// aboutGroup34Label
			// 
			this->aboutGroup34Label->AutoSize = true;
			this->aboutGroup34Label->Font = (gcnew System::Drawing::Font(L"Microsoft PhagsPa", 35, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->aboutGroup34Label->ForeColor = System::Drawing::SystemColors::ControlText;
			this->aboutGroup34Label->Location = System::Drawing::Point(334, 296);
			this->aboutGroup34Label->Name = L"aboutGroup34Label";
			this->aboutGroup34Label->Size = System::Drawing::Size(178, 47);
			this->aboutGroup34Label->TabIndex = 21;
			this->aboutGroup34Label->Text = L"Group 34";
			// 
			// aboutTechnologiesLabel
			// 
			this->aboutTechnologiesLabel->AutoSize = true;
			this->aboutTechnologiesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->aboutTechnologiesLabel->ForeColor = System::Drawing::SystemColors::ControlText;
			this->aboutTechnologiesLabel->Location = System::Drawing::Point(1, 63);
			this->aboutTechnologiesLabel->Name = L"aboutTechnologiesLabel";
			this->aboutTechnologiesLabel->Size = System::Drawing::Size(292, 40);
			this->aboutTechnologiesLabel->TabIndex = 20;
			this->aboutTechnologiesLabel->Text = L"Technologies Used";
			// 
			// aboutMember4Label
			// 
			this->aboutMember4Label->AutoSize = true;
			this->aboutMember4Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->aboutMember4Label->ForeColor = System::Drawing::SystemColors::ControlText;
			this->aboutMember4Label->Location = System::Drawing::Point(637, 626);
			this->aboutMember4Label->Name = L"aboutMember4Label";
			this->aboutMember4Label->Size = System::Drawing::Size(189, 17);
			this->aboutMember4Label->TabIndex = 19;
			this->aboutMember4Label->Text = L"AARON CHUA (1902146)";
			// 
			// aboutMember3Label
			// 
			this->aboutMember3Label->AutoSize = true;
			this->aboutMember3Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->aboutMember3Label->ForeColor = System::Drawing::SystemColors::ControlText;
			this->aboutMember3Label->Location = System::Drawing::Point(430, 626);
			this->aboutMember3Label->Name = L"aboutMember3Label";
			this->aboutMember3Label->Size = System::Drawing::Size(182, 17);
			this->aboutMember3Label->TabIndex = 18;
			this->aboutMember3Label->Text = L"DAMON ANG (1902707)";
			// 
			// aboutMember2Label
			// 
			this->aboutMember2Label->AutoSize = true;
			this->aboutMember2Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->aboutMember2Label->ForeColor = System::Drawing::SystemColors::ControlText;
			this->aboutMember2Label->Location = System::Drawing::Point(225, 626);
			this->aboutMember2Label->Name = L"aboutMember2Label";
			this->aboutMember2Label->Size = System::Drawing::Size(189, 17);
			this->aboutMember2Label->TabIndex = 17;
			this->aboutMember2Label->Text = L"JOHN LEONG (1902605)";
			// 
			// aboutSeleniumPicture
			// 
			this->aboutSeleniumPicture->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"aboutSeleniumPicture.Image")));
			this->aboutSeleniumPicture->Location = System::Drawing::Point(228, 125);
			this->aboutSeleniumPicture->Name = L"aboutSeleniumPicture";
			this->aboutSeleniumPicture->Size = System::Drawing::Size(134, 131);
			this->aboutSeleniumPicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->aboutSeleniumPicture->TabIndex = 11;
			this->aboutSeleniumPicture->TabStop = false;
			// 
			// aboutCppPicture
			// 
			this->aboutCppPicture->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"aboutCppPicture.Image")));
			this->aboutCppPicture->Location = System::Drawing::Point(41, 125);
			this->aboutCppPicture->Name = L"aboutCppPicture";
			this->aboutCppPicture->Size = System::Drawing::Size(134, 131);
			this->aboutCppPicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->aboutCppPicture->TabIndex = 8;
			this->aboutCppPicture->TabStop = false;
			// 
			// aboutMember1Label
			// 
			this->aboutMember1Label->AutoSize = true;
			this->aboutMember1Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(0)));
			this->aboutMember1Label->ForeColor = System::Drawing::SystemColors::ControlText;
			this->aboutMember1Label->Location = System::Drawing::Point(10, 626);
			this->aboutMember1Label->Name = L"aboutMember1Label";
			this->aboutMember1Label->Size = System::Drawing::Size(201, 17);
			this->aboutMember1Label->TabIndex = 4;
			this->aboutMember1Label->Text = L"PATRICK KANG (1902132)";
			// 
			// aboutMember4Picture
			// 
			this->aboutMember4Picture->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"aboutMember4Picture.Image")));
			this->aboutMember4Picture->Location = System::Drawing::Point(640, 398);
			this->aboutMember4Picture->Name = L"aboutMember4Picture";
			this->aboutMember4Picture->Size = System::Drawing::Size(179, 211);
			this->aboutMember4Picture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->aboutMember4Picture->TabIndex = 3;
			this->aboutMember4Picture->TabStop = false;
			// 
			// aboutMember3Picture
			// 
			this->aboutMember3Picture->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"aboutMember3Picture.Image")));
			this->aboutMember3Picture->Location = System::Drawing::Point(433, 398);
			this->aboutMember3Picture->Name = L"aboutMember3Picture";
			this->aboutMember3Picture->Size = System::Drawing::Size(179, 211);
			this->aboutMember3Picture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->aboutMember3Picture->TabIndex = 2;
			this->aboutMember3Picture->TabStop = false;
			// 
			// aboutMember2Picture
			// 
			this->aboutMember2Picture->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"aboutMember2Picture.Image")));
			this->aboutMember2Picture->Location = System::Drawing::Point(228, 398);
			this->aboutMember2Picture->Name = L"aboutMember2Picture";
			this->aboutMember2Picture->Size = System::Drawing::Size(179, 211);
			this->aboutMember2Picture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->aboutMember2Picture->TabIndex = 1;
			this->aboutMember2Picture->TabStop = false;
			// 
			// aboutMember1Picture
			// 
			this->aboutMember1Picture->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"aboutMember1Picture.Image")));
			this->aboutMember1Picture->Location = System::Drawing::Point(18, 398);
			this->aboutMember1Picture->Name = L"aboutMember1Picture";
			this->aboutMember1Picture->Size = System::Drawing::Size(179, 211);
			this->aboutMember1Picture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->aboutMember1Picture->TabIndex = 0;
			this->aboutMember1Picture->TabStop = false;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->analysisWordmap))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->analysisRelatedHashtagsTable))->EndInit();
			this->visualisationTab->ResumeLayout(false);
			this->visualisationTab->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->visualisationSentimentChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->visualisationLocationChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->visualisationMonthlyChart))->EndInit();
			this->imageOcrTab->ResumeLayout(false);
			this->imageOcrTab->PerformLayout();
			this->aboutTab->ResumeLayout(false);
			this->aboutTab->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aboutInstagramPicture))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aboutTwitterPicture))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aboutSeleniumPicture))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aboutCppPicture))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aboutMember4Picture))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aboutMember3Picture))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aboutMember2Picture))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aboutMember1Picture))->EndInit();
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
					if (returnCode > 1) 
						imageOcrConsoleTextBox->AppendText("Successfully appended image text to file\r\n");
					else 
						imageOcrConsoleTextBox->AppendText("Successfully appended image text to file\r\n");
			}
		}
	}


private: System::Void visualationBtn_Click_1(System::Object^  sender, System::EventArgs^  e)
{
	if (visualisationLoadFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) 
	{
		visualisationFilePathLabel->Text = visualisationLoadFileDialog->FileName;
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

			//Display data analysis onto gui
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

			//Populate related hashtags table
			analysisRelatedHashtagsTable->Rows->Clear();
			std::map<std::string, unsigned int> sorted_hashtags(analysedData.getRelatedHashtags()->begin(), analysedData.getRelatedHashtags()->end());
			for (auto item = sorted_hashtags.begin(); item != sorted_hashtags.end(); ++item)
				analysisRelatedHashtagsTable->Rows->Add(gcnew String(item->first.c_str()), (static_cast<float>(item->second) / analysedData.getNumPosts()).ToString(),item->second.ToString());

			//Load wordmap
			auto img = Image::FromFile("wordmap.png");
			Bitmap^ bm = gcnew Bitmap(img);
			analysisWordmap->Image = bm;
			delete img;
			wordmapGenerated = true;
		}
		catch (std::exception e) 
		{
			std::cout << "Data analysis failed: ";
			std::cout << e.what() << std::endl;
		}
	}
}
private: System::Void analysisWordmap_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (!wordmapGenerated)
		return;
	System::Diagnostics::Process::Start("wordmap.png");
}
private: System::Void visualisationSentimentButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (visualisationLoadFileDialog->FileName->Length < 1)
	{
		MessageBox::Show("Please select a file");
		return;
	}

	visualisationSentimentChart->Visible = true;
	visualisationMonthlyChart->Visible = false;
	visualisationLocationChart->Visible = false;

	std::string fileName = msclr::interop::marshal_as<std::string>(visualisationLoadFileDialog->FileName);

	std::cout << "Starting sentiment analysis" << std::endl;
	ICT1009::DataStorage::ScrapeStorage data(fileName);
	auto results = ICT1009::Analysis::SentimentAnalyser::analyseSentiment(&data);
	
	visualisationSentimentChart->Series[0]->Points->Clear();
	for (auto it = results.cbegin(); it != results.cend(); ++it)
	{
		visualisationSentimentChart->Series[0]->Points->AddXY(gcnew String(it->first.c_str()), it->second);
		std::cout << it->first << " " << it->second << " " << "\n";
	}
	std::cout << "Sentiment analysis done" << std::endl;
}
private: System::Void visualisationMonthlyButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (visualisationLoadFileDialog->FileName->Length < 1)
	{
		MessageBox::Show("Please select a file");
		return;
	}

	visualisationSentimentChart->Visible = false;
	visualisationMonthlyChart->Visible = true;
	visualisationLocationChart->Visible = false;

	std::string fileName = msclr::interop::marshal_as<std::string>(visualisationLoadFileDialog->FileName);

	using json = nlohmann::json;

	try {
		std::ifstream i(fileName);
		json jsonObject;
		i >> jsonObject; i.close(); //Parse file into json object;
		int counterLoc = 0;
		string tempDate;
		int totalCaptions = 0;

		string monthNames[] = { "JAN", "FEB", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUG", "SEPT", "OCT", "NOV", "DEC" };
		int months[12];
		for (int i = 0; i < 12; ++i)
			months[i] = 0;

		for (auto &detail : jsonObject["details"]) {

			for (auto &post : detail["extracted_posts"]) {

				tempDate = post["date_time"].get<string>();
				int month = std::stoi(string() + tempDate[5] + tempDate[6]);
				totalCaptions += 1;
				months[month - 1] += 1;
			}
		}

		for (int i = 0; i < 12; ++i)
			this->visualisationMonthlyChart->Series[gcnew String(monthNames[i].c_str())]->Points->Clear();
		for (int i = 0; i < 12; ++i)
			this->visualisationMonthlyChart->Series[gcnew String(monthNames[i].c_str())]->Points->Add(months[i]);
	}
	catch (...) {
	}

}
private: System::Void visualisationLocationButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (visualisationLoadFileDialog->FileName->Length < 1)
	{
		MessageBox::Show("Please select a file");
		return;
	}

	visualisationSentimentChart->Visible = false;
	visualisationMonthlyChart->Visible = false;
	visualisationLocationChart->Visible = true;

	std::string fileName = msclr::interop::marshal_as<std::string>(visualisationLoadFileDialog->FileName);

	using json = nlohmann::json;

	try {
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
		if (jsonObject["platform"].get<string>() == "twitter")
		{
			MessageBox::Show("Location visualisation only works for Instagram data!");
			return;
		}
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
		this->visualisationLocationChart->Series["Location1"]->Points->AddXY("Loc 1", location[0]);
		this->visualisationLocationChart->Series["Location1"]->Points->AddXY("Loc 2", location[1]);
		this->visualisationLocationChart->Series["Location1"]->Points->AddXY("Loc 3", location[2]);
		this->visualisationLocationChart->Series["Location1"]->Points->AddXY("Loc 4", location[3]);
		this->visualisationLocationChart->Series["Location1"]->Points->AddXY("Loc 5", location[4]);
		this->visualisationLocationChart->Series["Location1"]->Points->AddXY("Loc 6", location[5]);
		this->visualisationLocationChart->Series["Location1"]->Points->AddXY("Loc 7", location[6]);
		this->visualisationLocationChart->Series["Location1"]->Points->AddXY("Loc 8", location[7]);
		this->visualisationLocationChart->Series["Location1"]->Points->AddXY("Loc 9", location[8]);
	}
	catch (...) {
	}

}
}; //Endpoint
}
